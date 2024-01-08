#pragma once
#include <algorithm>
#include <vector>

#include "lowlink.hpp"

std::vector<int> two_edge_connected_components(
    const std::vector<std::vector<int>>& G, const Lowlink& low) {
    int k = 0;
    std::vector<int> comp(G.size(), -1);

    auto dfs = [&](const auto& dfs, int u) -> void {
        comp[u] = k;
        for (int v : G[u]) {
            if (comp[v] == -1 && !low.is_bridge(u, v)) dfs(dfs, v);
        }
    };

    for (int v = 0; v < (int)G.size(); ++v) {
        if (comp[v] == -1) {
            dfs(dfs, v);
            ++k;
        }
    }
    return comp;
}

std::vector<std::vector<int>> contract(const std::vector<std::vector<int>>& G,
                                       const std::vector<int>& comp) {
    const int n = *std::ranges::max_element(comp) + 1;
    std::vector<std::vector<int>> G2(n);
    for (int i = 0; i < (int)G.size(); ++i) {
        for (int j : G[i]) {
            if (comp[i] != comp[j]) {
                G2[comp[i]].push_back(comp[j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        std::ranges::sort(G2[i]);
        G2[i].erase(std::ranges::unique(G2[i]).begin(), G2[i].end());
    }
    return G2;
}