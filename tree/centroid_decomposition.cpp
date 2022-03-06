#pragma once
#include <vector>

/*
 * @brief Centroid Decomposition
 */

int find_centroid(const std::vector<std::vector<int>>& G, int r,
                  const std::vector<bool>& dead) {
    static std::vector<int> sz(G.size());

    auto dfs_size = [&](auto& dfs_size, int v, int p) -> int {
        sz[v] = 1;
        for (int c : G[v]) {
            if (c != p && !dead[c]) sz[v] += dfs_size(dfs_size, c, v);
        }
        return sz[v];
    };

    int n = dfs_size(dfs_size, r, -1);

    auto dfs = [&](auto& dfs, int v, int p) -> int {
        for (int c : G[v]) {
            if (c != p && !dead[c] && sz[c] > n / 2) return dfs(dfs, c, v);
        }
        return v;
    };

    return dfs(dfs, r, -1);
}

void solve(const std::vector<std::vector<int>>& G) {
    int N = G.size();
    std::vector<bool> dead(N);

    // implement here
    auto calc = [&](int s) {};

    auto decompose = [&](auto& decompose, int v) -> void {
        int s = find_centroid(G, v, dead);
        dead[s] = true;
        calc(s);
        for (int c : G[s]) {
            if (!dead[c]) decompose(decompose, c);
        }
    };

    decompose(decompose, 0);
}