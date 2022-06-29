#pragma once
#include <algorithm>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include "../data-structure/unionfind/union_find.cpp"
#include "../flow/hopcroft_karp.hpp"
#include "../graph/eulerian_path.hpp"


std::vector<int> bipartite_edge_coloring(const std::vector<std::pair<int, int>>& G, int n, int m) {
    // find the maximum degree
    std::vector<int> deg0(n), deg1(m);
    for (auto [a, b] : G) {
        ++deg0[a];
        ++deg1[b];
    }
    const int D = std::max(*max_element(deg0.begin(), deg0.end()), *max_element(deg1.begin(), deg1.end()));

    // convert to D-regular bipartite graph
    // merge vertices with the sum of degrees <= D
    auto contract = [&](const auto& deg) {
        using P = std::pair<int, int>;
        const int n = deg.size();
        std::priority_queue<P, std::vector<P>, std::greater<>> pq;
        for (int i = 0; i < n; ++i) {
            pq.emplace(deg[i], i);
        }
        UnionFind uf(deg.size());
        while (pq.size() > 1) {
            auto [p, i] = pq.top();
            pq.pop();
            auto [q, j] = pq.top();
            pq.pop();
            if (p + q > D) break;
            uf.unite(i, j);
            pq.emplace(p + q, i);
        }
        // rename vertices
        int k = 0;
        std::vector<int> id(n);
        for (int i = 0; i < n; ++i) {
            if (uf.find(i) == i) id[i] = k++;
        }
        std::vector<int> ndeg(k);
        for (int i = 0; i < n; ++i) {
            id[i] = id[uf.find(i)];
            ndeg[id[i]] += deg[i];
        }
        return std::make_pair(id, ndeg);
    };

    auto [id0, ndeg0] = contract(deg0);
    auto [id1, ndeg1] = contract(deg1);

    // add dummy vertices
    const int n2 = std::max(ndeg0.size(), ndeg1.size());
    ndeg0.resize(n2);
    ndeg1.resize(n2);

    // rename edges and add dummy edges
    std::vector<std::pair<int, int>> G2;
    for (auto [a, b] : G) {
        a = id0[a];
        b = id1[b];
        G2.emplace_back(a, b);
    }
    int j = 0;
    for (int i = 0; i < n2; ++i) {
        while (ndeg0[i] < D) {
            while (ndeg1[j] == D) ++j;
            G2.emplace_back(i, j);
            ++ndeg0[i];
            ++ndeg1[j];
        }
    }

    // find the edge coloring
    std::map<std::pair<int, int>, std::vector<int>> color;
    int k = 0;

    auto rec = [&](auto& rec, const std::vector<std::pair<int, int>>& G, int D) -> void {
        if (D == 1) {
            for (auto& e : G) {
                color[e].push_back(k);
            }
            ++k;
            return;
        } else if (D % 2 == 0) {
            // find an eulerian trail for each connected component
            // partition the graph into two and recurse
            std::vector<std::vector<int>> H(n2 + n2);
            for (auto [a, b] : G) {
                H[a].push_back(n2 + b);
                H[n2 + b].push_back(a);
            }
            std::vector<int> idx(n2 + n2, -1), invidx(n2 + n2, -1), prevv(n2 + n2, -1);
            std::vector<std::vector<std::pair<int, int>>> G2(2);
            for (int i = 0; i < n2; ++i) {
                if (idx[i] != -1) continue;
                // find the connected component
                std::stack<int> st;
                st.push(i);
                int k = 0;
                idx[i] = k;
                invidx[k] = i;
                ++k;
                std::vector<std::pair<int, int>> edges2;
                while (!st.empty()) {
                    int u = st.top();
                    st.pop();
                    for (int v : H[u]) {
                        if (idx[v] == -1) {
                            idx[v] = k;
                            invidx[k] = v;
                            prevv[v] = u;
                            ++k;
                            edges2.emplace_back(idx[u], idx[v]);
                            st.push(v);
                        } else if (prevv[u] != v && idx[u] < idx[v]) {
                            edges2.emplace_back(idx[u], idx[v]);
                        }
                    }
                }
                // get an eulerian path and partition it into two
                auto path = eulerian_path(edges2, k);
                for (int i = 0; i < (int) path.size() - 1; ++i) {
                    int u = invidx[path[i]], v = invidx[path[i + 1]];
                    if (u > v) std::swap(u, v);
                    v -= n2;
                    G2[i % 2].emplace_back(u, v);
                }
            }
            rec(rec, G2[0], D / 2);
            rec(rec, G2[1], D / 2);
        } else {
            // paint the edges in a perfect matching with the same color
            HopcroftKarp flow(n2, n2);
            for (auto [a, b] : G) {
                flow.add_edge(a, b);
            }
            std::vector<int> match(n2, -1);
            for (auto [a, b] : flow.bipartite_matching()) {
                match[a] = b;
            }
            std::vector<std::pair<int, int>> G2;
            for (auto [a, b] : G) {
                if (match[a] == b) {
                    color[{a, b}].push_back(k);
                    match[a] = -1;
                } else {
                    G2.emplace_back(a, b);
                }
            }
            ++k;
            rec(rec, G2, D - 1);
        }
    };

    rec(rec, G2, D);

    // get colors for edges in the original graph
    std::vector<int> ans(G.size());
    for (int i = 0; i < (int) G.size(); ++i) {
        auto [a, b] = G[i];
        std::pair<int, int> e(id0[a], id1[b]);
        ans[i] = color[e].back();
        color[e].pop_back();
    }

    return ans;
}
