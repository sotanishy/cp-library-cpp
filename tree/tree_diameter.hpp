#pragma once
#include <algorithm>
#include <utility>
#include <vector>

std::pair<int, std::vector<int>> tree_diameter(
    const std::vector<std::vector<int>>& G) {
    std::vector<int> to(G.size());

    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<int, int> {
        std::pair<int, int> ret(0, v);
        for (int c : G[v]) {
            if (c == p) continue;
            auto weight = dfs(dfs, c, v);
            ++weight.first;
            if (ret < weight) {
                ret = weight;
                to[v] = c;
            }
        }
        return ret;
    };

    auto p = dfs(dfs, 0, -1);
    auto q = dfs(dfs, p.second, -1);
    std::vector<int> path;
    int v = p.second;
    while (v != q.second) {
        path.push_back(v);
        v = to[v];
    }
    path.push_back(v);
    return {q.first, path};
}

template <typename T>
std::pair<T, std::vector<int>> tree_diameter(
    const std::vector<std::vector<std::pair<int, T>>>& G) {
    std::vector<int> to(G.size());

    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T, int> {
        std::pair<T, int> ret(0, v);
        for (auto& [u, w] : G[v]) {
            if (u == p) continue;
            auto weight = dfs(dfs, u, v);
            weight.first += w;
            if (ret < weight) {
                ret = weight;
                to[v] = u;
            }
        }
        return ret;
    };

    auto p = dfs(dfs, 0, -1);
    auto q = dfs(dfs, p.second, -1);
    std::vector<int> path;
    int v = p.second;
    while (v != q.second) {
        path.push_back(v);
        v = to[v];
    }
    path.push_back(v);
    return {q.first, path};
}