#include <bits/stdc++.h>
#include "edge.cpp"
using namespace std;

/*
 * @brief Prim's Algorithm
 * @docs docs/graph/prim.md
 */
template <typename T>
T prim(vector<vector<Edge<T>>>& G) {
    vector<bool> used(G.size());
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
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
            pq.emplace(e.cost, e.to);
        }
    }
    return ret;
}