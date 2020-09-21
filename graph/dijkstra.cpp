#include <bits/stdc++.h>
#include "edge.cpp"

/*
 * @brief Dijkstra's Algorithm
 * @docs docs/graph/dijkstra.md
 */
template <typename T>
std::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>& G, int s) {
    const T INF = std::numeric_limits<T>::max();
    std::vector<T> dist(G.size(), INF);
    dist[s] = 0;
    using P = std::pair<T, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        T cost;
        int v;
        std::tie(cost, v) = pq.top();
        pq.pop();
        if (dist[v] < cost) continue;
        for (auto& e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }

    return dist;
}