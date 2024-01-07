#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <utility>
#include <vector>

template <typename Flow, typename Cost>
class MinCostFlow {
   public:
    MinCostFlow() = default;
    explicit MinCostFlow(int V) : V(V), G(V), b(V), potential(V) {}

    void add_supply(int v, Flow amount) { b[v] += amount; }
    void add_demand(int v, Flow amount) { b[v] -= amount; }

    void add_edge(int u, int v, Flow lb, Flow ub, Cost cost) {
        assert(lb <= ub);
        int e = G[u].size(), re = u == v ? e + 1 : G[v].size();
        G[u].push_back({v, re, ub, 0, cost});
        G[v].push_back({u, e, -lb, 0, -cost});
        edge_idx.push_back({u, e});
    }

    std::pair<bool, Cost> min_cost_flow() {
        // handle min flow constraints
        for (int v = 0; v < V; ++v) {
            for (auto& e : G[v]) {
                Flow f = e.residual_cap();
                if (f < 0) {
                    b[v] -= f;
                    b[e.to] += f;
                    e.flow += f;
                    G[e.to][e.rev].flow -= f;
                }
            }
        }

        // get max delta
        Flow max_cap = 1;
        for (int v = 0; v < V; ++v) {
            for (auto& e : G[v]) max_cap = std::max(max_cap, e.residual_cap());
        }
        Flow delta = 1;
        while (delta <= max_cap) delta <<= 1;

        std::vector<Cost> dist(V);
        std::vector<int> prevv(V), preve(V);
        using P = std::pair<Cost, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;

        for (delta >>= 1; delta > 0; delta >>= 1) {
            // handle negative edges
            for (int v = 0; v < V; ++v) {
                for (auto& e : G[v]) {
                    Flow f = e.residual_cap();
                    if (f >= delta && residual_cost(v, e) < 0) {
                        b[v] -= f;
                        b[e.to] += f;
                        e.flow += f;
                        G[e.to][e.rev].flow -= f;
                    }
                }
            }

            while (true) {
                // dual
                dist.assign(V, INF);
                prevv.assign(V, -1);
                preve.assign(V, -1);
                for (int s = 0; s < V; ++s) {
                    if (b[s] >= delta) {
                        dist[s] = 0;
                        pq.emplace(0, s);
                    }
                }
                bool augment = false;
                Cost farthest = 0;
                while (!pq.empty()) {
                    auto [d, v] = pq.top();
                    pq.pop();
                    if (dist[v] < d) continue;
                    farthest = d;
                    if (b[v] <= -delta) augment = true;
                    for (int i = 0; i < (int)G[v].size(); ++i) {
                        Edge& e = G[v][i];
                        Cost ndist = dist[v] + residual_cost(v, e);
                        if (e.residual_cap() >= delta && dist[e.to] > ndist) {
                            dist[e.to] = ndist;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            pq.emplace(dist[e.to], e.to);
                        }
                    }
                }

                for (int v = 0; v < V; ++v)
                    potential[v] += std::min(dist[v], farthest);

                if (!augment) break;

                // primal
                for (int t = 0; t < V; ++t) {
                    if (b[t] >= 0 || dist[t] > farthest) continue;

                    Flow f = -b[t];
                    int v;
                    for (v = t; prevv[v] != -1 && f >= delta; v = prevv[v]) {
                        f = std::min(f, G[prevv[v]][preve[v]].residual_cap());
                    }
                    f = std::min(f, b[v]);

                    if (f < delta) continue;
                    for (v = t; prevv[v] != -1; v = prevv[v]) {
                        Edge& e = G[prevv[v]][preve[v]];
                        e.flow += f;
                        G[v][e.rev].flow -= f;
                    }

                    b[t] += f;
                    b[v] -= f;
                }
            }
        }

        Cost res = 0;
        for (int v = 0; v < V; ++v) {
            for (auto& e : G[v]) {
                res += e.flow * e.cost;
            }
        }
        res /= 2;

        bool feasible = true;
        for (int v = 0; v < V; ++v) {
            if (b[v] != 0) {
                feasible = false;
                break;
            }
        }

        return {feasible, res};
    }

    std::vector<Flow> get_flow() const {
        std::vector<Flow> ret(edge_idx.size());
        for (int j = 0; j < (int)edge_idx.size(); ++j) {
            auto [v, i] = edge_idx[j];
            ret[j] = G[v][i].flow;
        }
        return ret;
    }

    std::vector<Cost> get_potential() const { return potential; }

   private:
    struct Edge {
        int to, rev;
        Flow cap, flow;
        Cost cost;

        Flow residual_cap() const { return cap - flow; }
    };

    static constexpr Cost INF = std::numeric_limits<Cost>::max() / 2;

    int V;
    std::vector<std::vector<Edge>> G;
    std::vector<Flow> b;
    std::vector<Cost> potential;
    std::vector<std::pair<int, int>> edge_idx;

    Cost residual_cost(int v, const Edge& e) const {
        return e.cost + potential[v] - potential[e.to];
    }
};
