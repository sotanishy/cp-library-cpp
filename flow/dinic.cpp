#pragma once
#include <algorithm>
#include <limits>
#include <set>
#include <stack>
#include <queue>
#include <vector>

template <typename T>
class Dinic {
public:
    Dinic() = default;
    explicit Dinic(int V) : G(V), level(V), iter(V) {}

    void add_edge(int u, int v, T cap) {
        G[u].emplace_back(v, (int) G[v].size(), cap);
        G[v].emplace_back(u, (int) G[u].size() - 1, 0);
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while (bfs(s, t)) {
            std::fill(iter.begin(), iter.end(), 0);
            T f = 0;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }

    std::set<int> min_cut(int s) {
        std::stack<int> st;
        std::set<int> visited;
        st.push(s);
        visited.insert(s);
        while (!st.empty()) {
            int v = st.top();
            st.pop();
            for (auto& e : G[v]) {
                if (e.cap > 0 && !visited.count(e.to)) {
                    visited.insert(e.to);
                    st.push(e.to);
                }
            }
        }
        return visited;
    }

private:
    struct Edge {
        int to, rev;
        T cap;
    };

    static constexpr T INF = std::numeric_limits<T>::max() / 2;

    std::vector<std::vector<Edge>> G;
    std::vector<int> level, iter;

    bool bfs(int s, int t) {
        std::fill(level.begin(), level.end(), -1);
        level[s] = 0;
        std::queue<int> q;
        q.push(s);
        while (!q.empty() && level[t] == -1) {
            int v = q.front();
            q.pop();
            for (auto& e : G[v]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    T dfs(int v, int t, T f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < (int) G[v].size(); ++i) {
            Edge& e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, std::min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};