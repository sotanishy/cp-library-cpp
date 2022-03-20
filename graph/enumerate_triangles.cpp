#pragma once
#include <vector>

std::vector<std::tuple<int, int, int>> enumerate_triangles(const std::vector<std::vector<int>>& G) {
    int n = G.size();
    std::vector<int> deg(n);
    for (int i = 0; i < n; ++i) deg[i] = G[i].size();
    std::vector<std::vector<int>> G2(n);
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j : G[i]) {
            if (std::make_pair(deg[i], i) < std::make_pair(deg[j], j)) {
                G2[i].push_back(j);
                edges.push_back({i, j});
            }
        }
    }
    std::vector<std::tuple<int, int, int>> ret;
    std::vector<bool> used(n);
    for (auto& [a, b] : edges) {
        for (int c : G2[a]) used[c] = true;
        for (int c : G2[b]) {
            if (used[c]) {
                ret.push_back({a, b, c});
            }
        }
        for (int c : G2[a]) used[c] = false;
    }
    return ret;
}
