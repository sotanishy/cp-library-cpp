#pragma once
#include <vector>
#include "lowlink.cpp"

std::vector<int> two_edge_connected_components(const std::vector<std::vector<int>>& G) {
    int k = 0;
    std::vector<int> comp(G.size(), -1);
    auto lowlink = Lowlink(G);

    auto dfs = [&](const auto& dfs, int u) -> void {
        comp[u] = k;
        for (int v : G[u]) {
            if (comp[v] == -1 && !lowlink.is_bridge(u, v)) dfs(dfs, v);
        }
    };

    for (int v = 0; v < (int) G.size(); ++v) {
        if (comp[v] == -1) {
            dfs(dfs, v);
            ++k;
        }
    }
    return comp;
}