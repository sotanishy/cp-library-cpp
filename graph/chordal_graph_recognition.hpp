#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <set>
#include <utility>
#include <vector>

#include "lex_bfs.hpp"

// if G is chordal, return a perfect elimination ordering
// otherwise return an induced cycle of length >= 4
std::pair<bool, std::vector<int>> recognize_chordal_graph(
    const std::vector<std::vector<int>>& G) {
    const int n = G.size();
    std::vector<std::set<int>> st(n);
    for (int x = 0; x < n; ++x) {
        for (int y : G[x]) st[x].insert(y);
    }

    auto ord = lex_bfs(G);
    std::reverse(ord.begin(), ord.end());
    std::vector<int> idx(n, -1);
    for (int x = 0; x < n; ++x) idx[ord[x]] = x;

    // check if ord is a perfect elimination ordering
    for (int i = n - 1; i >= 0; --i) {
        int x = ord[i];

        // find the first neighbor z of x that appears after x
        std::pair<int, int> neighbor(n, -1);
        for (int y : G[x]) {
            if (idx[y] > i) {
                neighbor = std::min(neighbor, {idx[y], y});
            }
        }
        auto [j, z] = neighbor;
        if (j == n) continue;

        // check if N(x) - z is a subset of N(z)
        for (int y : G[x]) {
            if (idx[y] > i && y != z && !st[y].count(z)) {
                // not chordal
                // bfs from y to z using vertices after x and not in N(x)

                std::queue<int> que;
                que.push(y);
                std::vector<int> prv(n, -1);
                prv[y] = y;
                prv[z] = -1;
                for (int v : G[x]) {
                    if (v != y && v != z) {
                        prv[v] = -2;
                    }
                }
                while (!que.empty()) {
                    int v = que.front();
                    que.pop();
                    for (int u : G[v]) {
                        if (idx[u] > i && prv[u] == -1) {
                            prv[u] = v;
                            que.push(u);
                        }
                    }
                }

                assert(prv[z] != -1);

                std::vector<int> cycle;
                int v = z;
                while (prv[v] != v) {
                    cycle.push_back(v);
                    v = prv[v];
                }
                cycle.push_back(y);
                cycle.push_back(x);

                return {false, cycle};
            }
        }
    }

    return {true, ord};
}