#include <bits/stdc++.h>
#include "edge.cpp"

/*
 * @brief Bellman-Ford Algorithm
 * @docs docs/graph/bellman_ford.md
 */
template <typename T>
std::vector<T> bellman_ford(const std::vector<Edge<T>>& G, int V, int s) {
    const auto INF = std::numeric_limits<T>::max();
    std::vector<int> dist(V, INF);
    dist[s] = 0;
    for (int i = 0; i < V; i++) {
        for (auto& e : G) {
            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == V - 1) return std::vector<T>();
            }
        }
    }
    return dist;
}