#pragma once
#include <queue>
#include <utility>
#include <vector>
#include "edge.cpp"

/*
 * @brief Prim's Algorithm
 * @docs docs/graph/prim.md
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