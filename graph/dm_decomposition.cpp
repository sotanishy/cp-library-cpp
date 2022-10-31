#pragma once
#include <stack>
#include <utility>
#include <vector>
#include "bipartite_matching.hpp"

std::vector<int> dm_decomposition(int X, int Y, const std::vector<std::pair<int, int>>& edges) {
    int N = X + Y;
    std::vector<std::vector<int>> G(N);
    BipartiteMatching bm(X, Y);
    for (auto [u, v] : edges) {
        G[u].push_back(X+v);
        G[X+v].push_back(u);
        bm.add_edge(u, v);
    }
    std::vector<int> comp(N), matched(N, -1);
    for (auto [u, v] : bm.max_matching()) {
        comp[u] = comp[v] = -1;
        matched[u] = X+v;
        matched[X+v] = u;
    }
    std::stack<std::pair<int, bool>> st;  // whether or not the previous edge is used in the matching
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