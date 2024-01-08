#pragma once
#include <limits>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

/*
 * Bellman-Ford Algorithm
 */
template <typename T>
std::vector<T> bellman_ford(const std::vector<std::tuple<int, int, T>>& G,
                            int V, int s) {
    constexpr T INF = std::numeric_limits<T>::max();
    std::vector<T> dist(V, INF);
    dist[s] = 0;
    for (int i = 0; i < V; ++i) {
        for (auto& [s, t, w] : G) {
            if (dist[s] != INF && dist[t] > dist[s] + w) {
                dist[t] = dist[s] + w;
                if (i == V - 1) return {};
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
    const int V = dist.size();
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
std::vector<T> dijkstra(const std::vector<std::vector<std::pair<int, T>>>& G,
                        int s) {
    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());
    dist[s] = 0;
    using P = std::pair<T, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist[v] < d) continue;
        for (auto& [u, w] : G[v]) {
            if (dist[u] > d + w) {
                dist[u] = d + w;
                pq.emplace(dist[u], u);
            }
        }
    }

    return dist;
}

template <typename T>
std::pair<std::vector<T>, std::vector<int>> shortest_path_tree(
    const std::vector<std::vector<std::pair<int, T>>>& G, int s) {
    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());
    std::vector<int> par(G.size(), -1);
    dist[s] = 0;
    using P = std::pair<T, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (dist[v] < d) continue;
        for (auto& [u, w] : G[v]) {
            if (dist[u] > d + w) {
                dist[u] = d + w;
                par[u] = v;
                pq.emplace(dist[u], u);
            }
        }
    }

    return {dist, par};
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
std::vector<int> dial(const std::vector<std::vector<std::pair<int, int>>>& G,
                      int s, int w) {
    std::vector<int> dist(G.size(), std::numeric_limits<int>::max());
    dist[s] = 0;
    std::vector<std::vector<int>> buckets(w * G.size(), std::vector<int>());
    buckets[0].push_back(s);

    for (int d = 0; d < (int)buckets.size(); ++d) {
        while (!buckets[d].empty()) {
            int v = buckets[d].back();
            buckets[d].pop_back();
            if (dist[v] < d) continue;
            for (auto& [u, w] : G[v]) {
                if (dist[u] > d + w) {
                    dist[u] = d + w;
                    buckets[dist[u]].push_back(u);
                }
            }
        }
    }
    return dist;
}