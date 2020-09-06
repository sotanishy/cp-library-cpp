#include <bits/stdc++.h>
using namespace std;

template <typename TF, typename TC>
struct MinCostFlow {
    struct Edge {
        int to;
        TF cap;
        TC cost;
        int rev;
        Edge(int to, TF cap, TC cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };

    const TC INF = numeric_limits<TC>::max();

    int V;
    vector<vector<Edge>> G;

    MinCostFlow(int V) : V(V), G(V) {}

    void add_edge(int u, int v, TF cap, TC cost) {
        G[u].emplace_back(v, cap, cost, G[v].size());
        G[v].emplace_back(u, 0, -cost, G[u].size() - 1);
    }

    TC min_cost_flow(int s, int t, TF f) {
        int ret = 0;
        vector<TC> dist(V), h(V);
        vector<int> prevv(V), preve(V);
        using P = pair<TC, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        while (f > 0) {
            // update h using dijkstra
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            pq.emplace(0, s);
            while (!pq.empty()) {
                TC d;
                int v;
                tie(d, v) = pq.top();
                pq.pop();
                if (dist[v] < d) continue;
                for (int i = 0; i < G[v].size(); i++) {
                    Edge& e = G[v][i];
                    TC ndist = dist[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 && dist[e.to] > ndist) {
                        dist[e.to] = ndist;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.emplace(dist[e.to], e.to);
                    }
                }
            }

            if (dist[t] == INF) return -1;
            for (int v = 0; v < V; v++) h[v] += dist[v];

            TF m = f;
            int v = t;
            for (int v = t; v != s; v = prevv[v]) {
                m = min(m, G[prevv[v]][preve[v]].cap);
            }
            f -= m;
            ret += m * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge& e = G[prevv[v]][preve[v]];
                e.cap -= m;
                G[v][e.rev].cap += m;
            }
        }
        return ret;
    }
};