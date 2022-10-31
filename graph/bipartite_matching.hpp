#pragma once
#include <limits>
#include <queue>
#include <utility>
#include <vector>

class BipartiteMatching {
public:
    BipartiteMatching() = default;
    BipartiteMatching(int U, int V) : U(U), V(V), NIL(U + V), G(U), level(U + V + 1), match(U + V + 1, NIL) {}

    void add_edge(int u, int v) {
        G[u].emplace_back(U + v);
    }

    std::vector<std::pair<int, int>> max_matching() {
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


/*
 * Bipartite matching using Ford-Fulkerson algorithm
 * Time complexity: O(VE)
 */
class BipartiteMatchingFF {
public:
    BipartiteMatchingFF() = default;
    explicit BipartiteMatchingFF(int n) : G(n), used(n), match(n) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    std::vector<std::pair<int, int>> max_matching() {
        int res = 0;
        std::fill(match.begin(), match.end(), -1);
        for (int v = 0; v < (int) G.size(); ++v) {
            if (match[v] == -1) {
                std::fill(used.begin(), used.end(), false);
                if (dfs(v)) ++res;
            }
        }

        std::vector<std::pair<int, int>> ret;
        for (int i = 0; i < (int) G.size(); ++i) {
            if (i < match[i]) ret.emplace_back(i, match[i]);
        }
        return ret;
    }

private:
    std::vector<std::vector<int>> G;
    std::vector<bool> used;
    std::vector<int> match;

    bool dfs(int u) {
        used[u] = true;
        for (int v : G[u]) {
            int w = match[v];
            if (w == -1 || (!used[w] && dfs(w))) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }
};