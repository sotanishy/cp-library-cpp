#include <bits/stdc++.h>
#include "edge.cpp"
#include "../data-structure/unionfind/union_find.cpp"

/*
 * @brief Kruskal's Algorithm
 * @docs docs/graph/kruskal.md
 */
template <typename T>
std::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>> G, int V) {
    std::sort(G.begin(), G.end(), [](const auto& e1, const auto& e2) {
        return e1.weight < e2.weight;
    });
    UnionFind uf(V);
    T weight = 0;
    std::vector<Edge<T>> edges;
    for (auto& e : G) {
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            weight += e.weight;
            edges.push_back(e);
        }
    }
    return {weight, edges};
}