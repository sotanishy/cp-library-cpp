#pragma once
#include <stack>
#include <utility>
#include <vector>
#include "../flow/bipartite_matching.cpp"

std::vector<int> dm_decomposition(const std::vector<std::vector<int>>& G) {
    int N = G.size();
    BipartiteMatching bm(N);
    for (int u = 0; u < N; ++u) {
        for (int v : G[u]) {
            if (u < v) {
                bm.add_edge(u, v);
            }
        }
    }
    bm.bipartite_matching();
    std::vector<int> comp(N), matched(N, -1);
    for (auto [u, v] : bm.get_edges()) {
        comp[u] = comp[v] = -1;
        matched[u] = v;
        matched[v] = u;
    }
    std::stack<std::pair<int, bool>> st;  // whether or not the previous edges is used in the matching
    for (int v = 0; v < N; ++v) {
        if (comp[v] == 0) {
            st.push({v, 0});
            st.push({v, 1});
        }
    }
    while (!st.empty()) {
        auto [u, b] = st.top();
        st.pop();
        for (int v : G[u]) {
            if (comp[v] == -1 && (b ^ (matched[u] == v))) {
                comp[v] = comp[u] ^ 1;
                st.push({v, !b});
            }
        }
    }
    return comp;
}