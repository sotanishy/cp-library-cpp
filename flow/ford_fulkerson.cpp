#pragma once
#include <algorithm>
#include <limits>
#include <set>
#include <stack>
#include <vector>

template <typename T>
class FordFulkerson {
public:
    FordFulkerson() = default;
    explicit FordFulkerson(int n) : G(n), used(n) {}

    void add_edge(int u, int v, T cap) {
        G[u].push_back({v, (int) G[v].size(), cap});
        G[v].push_back({u, (int) G[u].size() - 1, 0});
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while (true) {
            std::fill(used.begin(), used.end(), false);
            T f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
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

    const T INF = std::numeric_limits<T>::max() / 2;

    std::vector<std::vector<Edge>> G;
    std::vector<bool> used;

    T dfs(int v, int t, T f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
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