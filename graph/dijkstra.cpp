#include <bits/stdc++.h>
#include "edge.cpp"
using namespace std;

template <typename T>
vector<T> dijkstra(vector<vector<Edge<T>>>& G, int V, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(V, INF);
    dist[s] = 0;
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        T cost;
        int v;
        tie(cost, v) = pq.top();
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