#pragma once
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>

#include "../data-structure/unionfind/union_find.hpp"

template <typename T>
using Edge = std::tuple<int, int, T>;

/*
 * Kruskal's Algorithm
 */
template <typename T>
std::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>> G, int V) {
    std::ranges::sort(G, {}, [](auto& e) { return std::get<2>(e); });
    UnionFind uf(V);
    T weight = 0;
    std::vector<Edge<T>> edges;
    for (auto& [u, v, w] : G) {
        if (!uf.same(u, v)) {
            uf.unite(u, v);
            weight += w;
            edges.push_back({u, v, w});
        }
    }
    return {weight, edges};
}

/*
 * Prim's Algorithm
 */
template <typename T>
std::pair<T, std::vector<Edge<T>>> prim(
    const std::vector<std::vector<std::pair<int, T>>>& G) {
    std::vector<bool> used(G.size());
    auto cmp = [](const auto& e1, const auto& e2) {
        return std::get<2>(e1) > std::get<2>(e2);
    };
    std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> pq(cmp);
    pq.emplace(0, 0, 0);
    T weight = 0;
    std::vector<Edge<T>> edges;
    while (!pq.empty()) {
        auto [p, v, w] = pq.top();
        pq.pop();
        if (used[v]) continue;
        used[v] = true;
        weight += w;
        if (v != 0) edges.push_back({p, v, w});
        for (auto& [u, w2] : G[v]) {
            pq.emplace(v, u, w2);
        }
    }
    return {weight, edges};
}

/*
 * Boruvka's Algorithm
 */
template <typename T>
std::pair<T, std::vector<Edge<T>>> boruvka(std::vector<Edge<T>> G, int V) {
    UnionFind uf(V);
    T weight = 0;
    std::vector<Edge<T>> edges;
    while (uf.size(0) < V) {
        std::vector<Edge<T>> cheapest(V,
                                      {-1, -1, std::numeric_limits<T>::max()});
        for (auto [u, v, w] : G) {
            if (!uf.same(u, v)) {
                u = uf.find(u);
                v = uf.find(v);
                if (w < std::get<2>(cheapest[u])) cheapest[u] = {u, v, w};
                if (w < std::get<2>(cheapest[v])) cheapest[v] = {u, v, w};
            }
        }
        for (auto [u, v, w] : cheapest) {
            if (u != -1 && !uf.same(u, v)) {
                uf.unite(u, v);
                weight += w;
                edges.push_back({u, v, w});
            }
        }
    }
    return {weight, edges};
}