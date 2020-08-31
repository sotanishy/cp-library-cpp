#include <bits/stdc++.h>
#include "edge.cpp"
using namespace std;

// returns an empty vector if there exists a negative cycle
template <typename T>
vector<T> bellman_ford(vector<Edge<T>>& G, int V, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<int> dist(V, INF);
    dist[s] = 0;
    for (int i = 0; i < V; i++) {
        for (auto& e : G) {
            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == V - 1) return vector<T>();
            }
        }
    }
    return dist;
}