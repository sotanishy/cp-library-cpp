#pragma once
#include <numeric>
#include <queue>
#include <vector>

std::vector<int> complement_bfs(const std::vector<std::vector<int>>& Gcomp,
                                int s) {
    std::vector<int> dist(Gcomp.size(), -1);
    dist[s] = 0;

    std::vector<int> unvisited(Gcomp.size() - 1);
    std::iota(unvisited.begin(), unvisited.end(), 1);

    std::vector<bool> not_neighbor(Gcomp.size());

    std::queue<int> que;
    que.push(s);

    while (!que.empty()) {
        int v = que.front();
        que.pop();

        for (int u : Gcomp[v]) {
            not_neighbor[u] = true;
        }

        std::vector<int> nxt_unvisited;

        for (int u : unvisited) {
            if (not_neighbor[u]) {
                nxt_unvisited.push_back(u);
            } else {
                dist[u] = dist[v] + 1;
                que.push(u);
            }
        }

        unvisited.swap(nxt_unvisited);

        for (int u : Gcomp[v]) {
            not_neighbor[u] = false;
        }
    }

    return dist;
}
