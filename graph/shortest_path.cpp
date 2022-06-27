#pragma once
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include "edge.cpp"

/*
 * Bellman-Ford Algorithm
 */
template <typename T>
std::vector<T> bellman_ford(const std::vector<Edge<T>>& G, int V, int s) {
    constexpr T INF = std::numeric_limits<T>::max();
    std::vector<T> dist(V, INF);
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
        T d;
        int v;
        std::tie(d, v) = pq.top();
        pq.pop();
        if (dist[v] < d) continue;
        for (auto& e : G[v]) {
            if (dist[e.to] > d + e.weight) {
                dist[e.to] = d + e.weight;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }

    return dist;
}

/*
 * Breadth-First Search
 */
std::vector<int> bfs(const std::vector<std::vector<int>>& G, int s) {
    std::vector<int> dist(G.size(), -1);
    dist[s] = 0;
    std::queue<int> que;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (int u : G[v]) {
            if (dist[u] == -1) {
                dist[u] = dist[v] + 1;
                que.push(u);
            }
        }
    }

    return dist;
}

/*
 * Dial's Algorithm
 */
std::vector<int> dial(const std::vector<std::vector<Edge<int>>>& G, int s, int w) {
    std::vector<int> dist(G.size(), std::numeric_limits<int>::max());
    dist[s] = 0;
    std::vector<std::vector<int>> buckets(w * G.size(), std::vector<int>());
    buckets[0].push_back(s);

    for (int d = 0; d < (int) buckets.size(); ++d) {
        while (!buckets[d].empty()) {
            int v = buckets[d].back();
            buckets[d].pop_back();
            if (dist[v] < d) continue;
            for (auto& e : G[v]) {
                if (dist[e.to] > d + e.weight) {
                    dist[e.to] = d + e.weight;
                    buckets[dist[e.to]].push_back(e.to);
                }
            }
        }
    }
    return dist;
}