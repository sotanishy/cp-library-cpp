#pragma once
#include <algorithm>
#include <functional>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template <typename Cap, typename Cost>
class MinCostFlow {
public:
    MinCostFlow() = default;
    explicit MinCostFlow(int V) : V(V), G(V), add(0) {}

    void add_edge(int u, int v, Cap cap, Cost cost) {
        G[u].emplace_back(v, cap, cost, (int) G[v].size());
        G[v].emplace_back(u, 0, -cost, (int) G[u].size() - 1);
    }

    void add_edge(int u, int v, Cap lb, Cap ub, Cost cost) {
        add_edge(u, v, ub - lb, cost);
        add_edge(u, v, lb, cost - M);
        add += M * lb;
    }

    Cost min_cost_flow(int s, int t, Cap f, bool arbitrary = false) {
        Cost ret = add;
        std::vector<Cost> dist(V);
        std::vector<int> prevv(V), preve(V);
        using P = std::pair<Cost, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

        auto h = calculate_initial_potential(s);

        while (f > 0) {
            // update h using dijkstra
            std::fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            pq.emplace(0, s);
            while (!pq.empty()) {
                Cost d;
                int v;
                std::tie(d, v) = pq.top();
                pq.pop();
                if (dist[v] < d) continue;
                for (int i = 0; i < (int) G[v].size(); ++i) {
                    Edge& e = G[v][i];
                    Cost ndist = dist[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 && dist[e.to] > ndist) {
                        dist[e.to] = ndist;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.emplace(dist[e.to], e.to);
                    }
                }
            }

            if (!arbitrary && dist[t] == INF) return -1;
            for (int v = 0; v < V; ++v) h[v] += dist[v];

            if (arbitrary && h[t] >= 0) break;

            Cap d = f;
            for (int v = t; v != s; v = prevv[v]) {
                d = std::min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            ret += d * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge& e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return ret;
    }

private:
    struct Edge {
        int to;
        Cap cap;
        Cost cost;
        int rev;
        Edge(int to, Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };

    static constexpr Cost INF = std::numeric_limits<Cost>::max() / 2;
    static constexpr Cost M = INF / 1e9;  // large constant used for minimum flow requirement for edges

    int V;
    std::vector<std::vector<Edge>> G;
    Cost add;


    std::vector<Cost> calculate_initial_potential(int s) {
        std::vector<Cost> h(V);
        // if all costs are nonnegative, then do nothing
        return h;

        // if there is a negative edge,
        // use Bellman-Ford or topological sort and a DP (for DAG)
        // std::fill(h.begin(), h.end(), INF);
        // h[s] = 0;
        // for (int i = 0; i < V - 1; ++i) {
        //     for (int v = 0; v < V; ++v) {
        //         for (auto& e : G[v]) {
        //             if (e.cap > 0 && h[v] != INF && h[e.to] > h[v] + e.cost) {
        //                 h[e.to] = h[v] + e.cost;
        //             }
        //         }
        //     }
        // }

        // return h;
    }
};
