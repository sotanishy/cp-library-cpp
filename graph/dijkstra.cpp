#include <bits/stdc++.h>
#include "edge.cpp"

/*
 * @brief Dijkstra's Algorithm
 * @docs docs/graph/dijkstra.md
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