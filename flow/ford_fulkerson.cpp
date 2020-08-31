#include <bits/stdc++.h>
using namespace std;

struct FordFulkerson {
    struct Edge {
        int to, cap, rev;
    };

    const int INF = numeric_limits<int>::max();

    vector<vector<Edge>> G;
    vector<bool> used;

    FordFulkerson(int V) : G(V), used(V) {}

    void add_edge(int u, int v, int cap) {
        G[u].emplace_back((Edge) {v, cap, (int) G[v].size()});
        G[v].emplace_back((Edge) {u, 0, (int) G[u].size() - 1});
    }

    // find a path
    // v: current node, t: sink node, f: current flow
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    // find the max flow from s to t
    int max_flow(int s, int t) {
        int flow = 0;
        while (true) {
            fill(used.begin(), used.end(), false);
            int f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }
};