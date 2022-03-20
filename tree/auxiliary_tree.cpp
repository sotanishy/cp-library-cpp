#pragma once
#include <stack>
#include <utility>
#include <vector>
#include "lca.cpp"

class AuxiliaryTree {
public:
    AuxiliaryTree() = default;
    AuxiliaryTree(std::vector<std::vector<int>>& G, int root) : G(G), lca(G, root), ord(G.size()), depth(G.size()) {
        dfs(root, -1);
    }

    std::vector<std::pair<int, int>> query(std::vector<int> vs) {
        std::sort(vs.begin(), vs.end(), [&](int u, int v) {
            return ord[u] < ord[v];
        });
        std::vector<std::pair<int, int>> edges;
        std::stack<int> st;
        st.push(vs[0]);
        for (int i = 1; i < (int) vs.size(); ++i) {
            int l = lca.query(vs[i - 1], vs[i]);
            if (l != vs[i - 1]) {
                int u = st.top();
                st.pop();
                while (!st.empty() && depth[l] < depth[st.top()]) {
                    edges.push_back({u, st.top()});
                    u = st.top();
                    st.pop();
                }
                edges.push_back({u, l});
                if (st.empty() || st.top() != l) st.push(l);
            }
            st.push(vs[i]);
        }
        while (st.size() > 1) {
            int u = st.top();
            st.pop();
            edges.push_back({u, st.top()});
        }
        return edges;
    }

private:
    std::vector<std::vector<int>> G;
    LCA lca;
    std::vector<int> ord, depth;
    int k = 0;

    void dfs(int v, int p) {
        ord[v] = k++;
        for (int c : G[v]) {
            if (c != p) {
                depth[c] = depth[v] + 1;
                dfs(c, v);
            }
        }
    }
};