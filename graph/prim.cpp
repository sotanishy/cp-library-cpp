#include <bits/stdc++.h>
#include "edge.cpp"

/*
 * @brief Prim's Algorithm
 * @docs docs/graph/prim.md
 */
template <typename T>
T prim(const std::vector<std::vector<Edge<T>>>& G) {
    std::vector<bool> used(G.size());
    using P = std::pair<T, int>;
    std::priority_queue<P, std::vector<P>, std::greater<P>> pq;
    pq.emplace(0, 0);
    T ret = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (used[v]) continue;
        used[v] = true;
        ret += p.first;
        for (auto& e : G[v]) {
            pq.emplace(e.weight, e.to);
        }
    }
    return ret;
}