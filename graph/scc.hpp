#pragma once
#include <algorithm>
#include <ranges>
#include <vector>

std::vector<int> scc(const std::vector<std::vector<int>>& G) {
    const int n = G.size();
    std::vector<std::vector<int>> G_rev(n);
    for (int u = 0; u < n; ++u) {
        for (int v : G[u]) G_rev[v].push_back(u);
    }
    std::vector<int> comp(n, -1), order(n);
    std::vector<bool> visited(n);

    auto dfs = [&](const auto& dfs, int u) -> void {
        if (visited[u]) return;
        visited[u] = true;
        for (int v : G[u]) dfs(dfs, v);
        order.push_back(u);
    };

    for (int v = 0; v < n; ++v) dfs(dfs, v);
    int c = 0;

    auto rdfs = [&](const auto& rdfs, int u, int c) -> void {
        if (comp[u] != -1) return;
        comp[u] = c;
        for (int v : G_rev[u]) rdfs(rdfs, v, c);
    };

    for (int v : order | std::views::reverse) {
        if (comp[v] == -1) rdfs(rdfs, v, c++);
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