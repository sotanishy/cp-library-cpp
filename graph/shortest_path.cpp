#pragma once
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include "edge.cpp"

/*
 * @brief Shortest Path Algorithms
 * @docs docs/graph/shortest_path.md
 */

/*
 * Bellman-Ford Algorithm
 */
template <typename T>
std::vector<T> bellman_ford(const std::vector<Edge<T>>& G, int V, int s) {
    constexpr T INF = std::numeric_limits<T>::max();
    std::vector<int> dist(V, INF);
    dist[s] = 0;
    for (int i = 0; i < V; ++i) {
        for (auto& e : G) {
            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.weight) {
                dist[e.to] = dist[e.from] + e.weight;
                if (i == V - 1) return std::vector<T>();
            }
        }
    }
    return dist;
}

/*
 * Floyd-Warshall Algorithm
 */
template <typename T>
void floyd_warshall(std::vector<std::vector<T>>& dist) {
    int V = dist.size();
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

/*
 * Dijkstra's Algorithm
 */
template <typename T>
std::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>& G, int s) {
    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());
    dist[s] = 0;
    using P = std::pair<T, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        T weight;
        int v;
        std::tie(weight, v) = pq.top();
        pq.pop();
        if (dist[v] < weight) continue;
        for (auto& e : G[v]) {
            if (dist[e.to] > dist[v] + e.weight) {
                dist[e.to] = dist[v] + e.weight;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }

    return dist;
}