#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;

    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}

    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {};
};


template <typename T>
T prim(vector<Edge<T>>& G) {
    vector<bool> used(G.size());
    using P = pair<T, int>
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0, 0});
    T ret = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (used[v]) continue;
        used[v] = true;
        ret += p.first;
        for (auto& e : G[v]) {
            pq.push({e.cost, e.to});
        }
    }
    return ret;
}