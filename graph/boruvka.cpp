#include <bits/stdc++.h>
#include "edge.cpp"
#include "../data-structure/unionfind/union_find.cpp"

/*
 * @brief Boruvka's Algorithm
 * @docs docs/graph/boruvka.md
 */
template <typename T>
std::pair<T, std::vector<Edge<T>>> boruvka(std::vector<Edge<T>> G, int V) {
    UnionFind uf(V);
    T weight = 0;
    std::vector<Edge<T>> edges;
    while (uf.size(0) < V) {
        std::vector<Edge<T>> cheapest(V, {-1, -1, std::numeric_limits<T>::max()});
        for (auto& e : G) {
            if (!uf.same(e.from, e.to)) {
                int u = uf.find(e.from);
                int v = uf.find(e.to);
                if (e.weight < cheapest[u].weight) cheapest[u] = e;
                if (e.weight < cheapest[v].weight) cheapest[v] = e;
            }
        }
        for (auto& e : cheapest) {
            if (e.from != -1 && !uf.same(e.from, e.to)) {
                uf.unite(e.from, e.to);
                weight += e.weight;
                edges.push_back(e);
            }
        }
    }
    return {weight, edges};
}