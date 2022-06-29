#pragma once
#include <limits>
#include <queue>
#include <utility>
#include <vector>


class HopcroftKarp {
public:
    HopcroftKarp() = default;
    HopcroftKarp(int U, int V) : U(U), V(V), NIL(U + V), G(U), level(U + V + 1), match(U + V + 1, NIL) {}

    void add_edge(int u, int v) {
        G[u].emplace_back(U + v);
    }

    std::vector<std::pair<int, int>> bipartite_matching() {
        while (bfs()) {
            for (int u = 0; u < U; ++u) {
                if (match[u] == NIL) {
                    dfs(u);
                }
            }
        }
        std::vector<std::pair<int, int>> ret;
        for (int u = 0; u < U; ++u) {
            if (match[u] != NIL) ret.emplace_back(u, match[u] - U);
        }
        return ret;
    }

private:
    static constexpr int INF = std::numeric_limits<int>::max() / 2;

    const int U, V, NIL;
    std::vector<std::vector<int>> G;
    std::vector<int> level, match;

    bool bfs() {
        std::fill(level.begin(), level.end(), INF);
        std::queue<int> q;
        for (int u = 0; u < U; ++u) {
            if (match[u] == NIL) {
                level[u] = 0;
                q.push(u);
            }
        }
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            if (level[u] < level[NIL]) {
                for (int v : G[u]) {
                    if (level[match[v]] == INF) {
                        level[match[v]] = level[u] + 1;
                        q.push(match[v]);
                    }
                }
            }
        }
        return level[NIL] != INF;
    }

    bool dfs(int u) {
        if (u == NIL) return true;
        for (int v : G[u]) {
            if (level[match[v]] == level[u] + 1 && dfs(match[v])) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        level[u] = INF;
        return false;
    }
};