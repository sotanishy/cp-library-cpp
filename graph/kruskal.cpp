#include <bits/stdc++.h>
#include "../data-structures/union_find.cpp";
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;

    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}

    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {};
};

template <typename T>
T kruskal(vector<Edge<T>>& G, int V) {
    sort(G.begin(), G.end(), [](const auto& e1, const auto& e2) {
        return e1.cost < e2.cost;
    });
    UnionFind uf(V);
    T ret = 0;
    for (auto& e : G) {
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            ret += e.cost;
        }
    }
    return ret;
}