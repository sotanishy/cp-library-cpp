#include <bits/stdc++.h>

/*
 * @brief Range Edge Graph
 * @docs docs/graph/range_edge_graph.md
 */
template <typename T>
class RangeEdgeGraph {
public:
    RangeEdgeGraph() = default;
    explicit RangeEdgeGraph(int n) {
        size = 1;
        while (size < n) size <<= 1;
        G.resize(4 * size);
        for (int i = 1; i < size; ++i) {
            int l = 2 * i, r = 2 * i + 1;
            G[i].push_back({l, 0});
            G[i].push_back({r, 0});
            G[l + 2 * size].push_back({i + 2 * size, 0});
            G[r + 2 * size].push_back({i + 2 * size, 0});
        }
        for (int i = size; i < 2 * size; ++i) G[i].push_back({i + 2 * size, 0});
    }

    void add_edge(int l1, int r1, int l2, int r2, T w) {
        int idx = G.size();
        for (l1 += size, r1 += size; l1 < r1; l1 >>= 1, r1 >>= 1) {
            if (l1 & 1) G[l1 + 2 * size].push_back({idx, 0}), ++l1;
            if (r1 & 1) --r1, G[r1 + 2 * size].push_back({idx, 0});
        }
        std::vector<Edge> node;
        for (l2 += size, r2 += size; l2 < r2; l2 >>= 1, r2 >>= 1) {
            if (l2 & 1) node.push_back({l2++, w});
            if (r2 & 1) node.push_back({--r2, w});
        }
        G.push_back(node);
    }

    std::vector<T> dijkstra(int s) const {
        s += size;
        std::vector<T> dist(G.size(), std::numeric_limits<T>::max());
        dist[s] = 0;
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, s);

        while (!pq.empty()) {
            T weight;
            int v;
            std::tie(weight, v) = pq.top();
            pq.pop();
            if (dist[v] < weight) continue;
            for (auto& e : G[v]) {
                if (dist[e.to] > dist[v] + e.weight) {
                    dist[e.to] = dist[v] + e.weight;
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }
        return std::vector<T>(dist.begin() + size, dist.begin() + 2 * size);
    }

private:
    struct Edge { int to; T weight; };

    int size;
    std::vector<std::vector<Edge>> G;
};

/*
Implementation with a sparse table

template <typename T>
class RangeEdgeGraph {
public:
    RangeEdgeGraph() = default;
    explicit RangeEdgeGraph(int n) : n(n) {
        b = 0;
        while ((1 << b) <= n) ++b;
        G.resize(2 * n * b);
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                int k = n * i + j;
                int l = n * (i - 1) + j;
                int r = l + (1 << (i - 1));
                G[k].push_back({l, 0});
                G[k].push_back({r, 0});
                G[n * b + l].push_back({n * b + k, 0});
                G[n * b + r].push_back({n * b + k, 0});
            }
        }
        for (int j = 0; j < n; ++j) G[j].push_back({n * b + j, 0});
    }

    void add_edge(int l1, int r1, int l2, int r2, T w) {
        int idx = G.size();
        std::vector<Edge> node;
        int i = 31 - __builtin_clz(r1 - l1);
        G[n * b + n * i + l1].push_back({idx, 0});
        G[n * b + n * i + r1 - (1 << i)].push_back({idx, 0});

        i = 31 - __builtin_clz(r2 - l2);
        node.push_back({n * i + l2, w});
        node.push_back({n * i + r2 - (1 << i), w});
        G.push_back(node);
    }

    std::vector<T> dijkstra(int s) const {
        std::vector<T> dist(G.size(), std::numeric_limits<T>::max());
        dist[s] = 0;
        using P = std::pair<T, int>;
        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
        pq.emplace(0, s);

        while (!pq.empty()) {
            T weight;
            int v;
            std::tie(weight, v) = pq.top();
            pq.pop();
            if (dist[v] < weight) continue;
            for (auto& e : G[v]) {
                if (dist[e.to] > dist[v] + e.weight) {
                    dist[e.to] = dist[v] + e.weight;
                    pq.emplace(dist[e.to], e.to);
                }
            }
        }
        return std::vector<T>(dist.begin(), dist.begin() + n);
    }

private:
    struct Edge { int to; T weight; };

    int n, b;
    std::vector<std::vector<Edge>> G;
};

*/
