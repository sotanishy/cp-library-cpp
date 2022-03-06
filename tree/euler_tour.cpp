#pragma once
#include <vector>

/*
 * @brief Euler Tour
 */
std::pair<std::vector<int>, std::vector<int>> euler_tour(const std::vector<std::vector<int>>& G, int root) {
    std::vector<int> in(G.size()), out(G.size());
    int k = 0;

    auto dfs = [&](auto& dfs, int v, int p) -> void {
        in[v] = k++;
        for (int c : G[v]) if (c != p) dfs(dfs, c, v);
        out[v] = k;
    };

    dfs(dfs, root, -1);
    return {in, out};
}
