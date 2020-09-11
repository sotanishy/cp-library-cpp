#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Floyd-Warshall Algorithm
 * @docs docs/graph/floyd_warshall.md
 */
template <typename T>
void floyd_warshall(vector<vector<T>>& dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}