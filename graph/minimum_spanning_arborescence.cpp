#pragma once
#include <algorithm>
#include <limits>
#include <memory>
#include <numeric>
#include <utility>
#include <vector>
#include "edge.cpp"
#include "../data-structure/unionfind/union_find.cpp"
#include "../data-structure/leftist_heap.cpp"

/*
 * @brief Minimum Cost Arborescence
 */
template <typename T>
std::pair<T, std::vector<int>> minimum_spanning_arborescence(std::vector<Edge<T>> G, int V, int root) {
    std::vector<LeftistHeap<T>> incoming(V);
    for (int i = 0; i < (int) G.size(); ++i) {
        auto& e = G[i];
        incoming[e.to].push(i, e.weight);
    }
    T weight = 0;
    UnionFind uf(V);
    std::vector<int> from(V), stem(V, -1), prev_edge(G.size()), ord;
    std::vector<T> from_cost(V);
    std::vector<int> status(V); // 0: not checked, 1: cheking, 2: checked
    status[root] = 2;

    for (int s = 0; s < V; ++s) {
        if (status[s] != 0) continue;
        int cur = s, cyc = 0;
        std::vector<int> seen, processing;
        while (status[cur] != 2) {
            status[cur] = 1;
            processing.push_back(cur);
            if (incoming[cur].empty()) { // no msa
                return {std::numeric_limits<T>::max(), std::vector<int>()};
            }

            auto [i, c] = incoming[cur].top();
            int v = uf.find(G[i].from);
            incoming[cur].pop();
            if (cur == v) continue;
            from[cur] = v;
            from_cost[cur] = c;
            weight += c;
            ord.push_back(i);
            if (stem[cur] == -1) stem[cur] = i;
            while (cyc) {
                prev_edge[seen.back()] = i;
                seen.pop_back();
                --cyc;
            }
            seen.push_back(i);

            if (status[v] == 1) {
                int p = cur;
                do {
                    if (!incoming[p].empty()) incoming[p].add(-from_cost[p]);
                    if (p != cur) {
                        uf.unite(p, cur);
                        auto newheap = LeftistHeap<T>::meld(std::move(incoming[cur]), std::move(incoming[p]));
                        incoming[cur = uf.find(cur)] = std::move(newheap);
                    }
                    p = uf.find(from[p]);
                    ++cyc;
                } while (p != cur);
            } else {
                cur = v;
            }
        }
        for (int v : processing) status[v] = 2;
    }
    std::reverse(ord.begin(), ord.end());
    std::vector<bool> used_edge(G.size());
    std::vector<int> par(V);
    std::iota(par.begin(), par.end(), 0);
    for (int i : ord) {
        if (used_edge[i]) continue;
        auto& e = G[i];
        par[e.to] = e.from;
        int x = stem[e.to];
        while (x != i) {
            used_edge[x] = true;
            x = prev_edge[x];
        }
    }
    return {weight, par};
}
