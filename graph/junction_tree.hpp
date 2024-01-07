#pragma once
#include <set>
#include <stack>
#include <vector>

#include "../data-structure/unionfind/union_find.hpp"

class JunctionTreeWidth2 {
   public:
    struct Node {
        std::vector<int> bag;
        std::vector<int> ch;
    };

    explicit JunctionTreeWidth2(const std::vector<std::vector<int>>& G)
        : nodes(1) {
        const int n = G.size();

        UnionFind uf(n);
        std::vector<int> deg(n);
        std::vector<std::set<int>> G_st(n);
        for (int v = 0; v < n; ++v) {
            for (int u : G[v]) {
                uf.unite(u, v);
                G_st[v].insert(u);
            }
            deg[v] = G_st[v].size();
        }

        // add dummy edges to make G connected
        std::vector<int> leaders;
        for (int v = 0; v < n; ++v) {
            if (uf.find(v) == v) {
                leaders.push_back(v);
            }
        }
        for (int i = 0; i < (int)leaders.size() - 1; ++i) {
            int u = leaders[i];
            int v = leaders[i + 1];
            G_st[u].insert(v);
            G_st[v].insert(u);
            ++deg[u], ++deg[v];
        }

        // construct a tree decomposition of width 2

        // -2: removed and added to the tree
        // -1: not removed
        // >= 0: removed and not yet added to the tree
        std::vector<int> state(n, -1);
        std::stack<int> st;
        for (int v = 0; v < n; ++v) {
            if (deg[v] <= 2) {
                st.push(v);
            }
        }
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            if (state[v] != -1) continue;
            Node node;
            node.bag.push_back(v);
            int x = -1, y = -1;
            for (int u : G_st[v]) {
                if (state[u] == -1) {
                    (x == -1 ? x : y) = u;
                    node.bag.push_back(u);
                } else if (state[u] > 0) {
                    node.ch.push_back(state[u]);
                    state[u] = -2;
                }
            }

            if (x == -1) {
                // last vertex
            } else if (y == -1) {
                --deg[x];
            } else {
                // add new edge
                if (!G_st[x].count(y)) {
                    G_st[x].insert(y);
                    G_st[y].insert(x);
                } else {
                    --deg[x], --deg[y];
                }
            }
            for (int u : G_st[v]) {
                if (state[u] == -1 && deg[u] <= 2) {
                    st.push(u);
                }
            }

            deg[v] = 0;
            state[v] = nodes.size();
            nodes.push_back(node);
        }

        if (*std::max_element(deg.begin(), deg.end()) > 0) {
            treewidth_is_2 = false;
            return;
        }

        treewidth_is_2 = true;
        nodes[0].ch.push_back(nodes.size() - 1);
    }

    bool is_treewidth_2() const { return treewidth_is_2; }

    int size() const { return nodes.size(); }

    std::vector<Node> get_nodes() const { return nodes; }

   private:
    bool treewidth_is_2;
    std::vector<Node> nodes;
};
