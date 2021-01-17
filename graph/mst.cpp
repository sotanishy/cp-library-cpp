#pragma once
#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
#include "edge.cpp"
#include "../data-structure/unionfind/union_find.cpp"

/*
 * Kruskal's Algorithm
 */
template <typename T>
std::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>> G, int V) {
    std::sort(G.begin(), G.end(), [](const auto& e1, const auto& e2) {
        return e1.weight < e2.weight;
    });
    UnionFind uf(V);
    T weight = 0;
    std::vector<Edge<T>> edges;
    for (auto& e : G) {
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            weight += e.weight;
            edges.push_back(e);
        }
    }
    return {weight, edges};
}

/*
 * Prim's Algorithm
 */
template <typename T>
std::pair<T, std::vector<Edge<T>>> prim(const std::vector<std::vector<Edge<T>>>& G) {
    std::vector<bool> used(G.size());
    auto cmp = [](const auto& e1, const auto& e2) { return e1.weight > e2.weight; };
    std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)> pq(cmp);
    pq.emplace(0, 0, 0);
    T weight = 0;
    std::vector<Edge<T>> edges;
    while (!pq.empty()) {
        auto e = pq.top();
        pq.pop();
        if (used[e.to]) continue;
        used[e.to] = true;
        weight += e.weight;
        if (e.to != 0) edges.push_back(e);
        for (auto& f : G[e.to]) {
            pq.emplace(e.to, f.to, f.weight);
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
        std::vector<Edge<T>> cheapest(V, {-1, -1, std::numeric_limits<T>::max()});
        for (auto& e : G) {
            if (!uf.same(e.from, e.to)) {
                int u = uf.find(e.from);
                int v = uf.find(e.to);
                if (e.weight < cheapest[u].weight) cheapest[u] = e;
                if (e.weight < cheapest[v].weight) cheapest[v] = e;
            }
        }
        for (auto& e : cheapest) {
            if (e.from != -1 && !uf.same(e.from, e.to)) {
                uf.unite(e.from, e.to);
                weight += e.weight;
                edges.push_back(e);
            }
        }
    }
    return {weight, edges};
}