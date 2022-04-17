#pragma once
#include <vector>

std::pair<std::vector<int>, std::vector<int>> centroid_decomposition(const std::vector<std::vector<int>>& G) {
    int N = G.size();
    std::vector<int> sz(N), level(N, -1), sz_comp(N);

    auto dfs_size = [&](auto& dfs_size, int v, int p) -> int {
        sz[v] = 1;
        for (int c : G[v]) {
            if (c != p && level[c] == -1) sz[v] += dfs_size(dfs_size, c, v);
        }
        return sz[v];
    };

    auto dfs_centroid = [&](auto& dfs_centroid, int v, int p, int n) -> int {
        for (int c : G[v]) {
            if (c != p && level[c] == -1 && sz[c] > n / 2) return dfs_centroid(dfs_centroid, c, v, n);
        }
        return v;
    };

    auto decompose = [&](auto& decompose, int v, int k) -> void {
        int n = dfs_size(dfs_size, v, -1);
        int s = dfs_centroid(dfs_centroid, v, -1, n);
        level[s] = k;
        sz_comp[s] = n;
        for (int c : G[s]) {
            if (level[c] == -1) decompose(decompose, c, k + 1);
        }
    };

    decompose(decompose, 0, 0);
    return {level, sz_comp};
}