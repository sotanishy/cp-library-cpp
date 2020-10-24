#pragma once
#include <stack>
#include <vector>

/*
 * @brief Topological Sort
 * @docs docs/graph/topological_sort.md
 */
std::vector<int> topological_sort(const std::vector<std::vector<int>>& G) {
    int V = G.size();
    std::vector<int> par_count(V);
    for (int u = 0; u < V; ++u) {
        for (int v : G[u]) ++par_count[v];
    }
    std::stack<int> start;
    for (int v = 0; v < V; ++v) {
        if (par_count[v] == 0) start.push(v);
    }

    std::vector<int> ret;
    while (!start.empty()) {
        int u = start.top();
        start.pop();
        ret.push_back(u);
        for (int v : G[u]) {
            --par_count[v];
            if (par_count[v] == 0) start.push(v);
        }
    }

    for (int c : par_count) {
        if (c > 0) return std::vector<int>();
    }
    return ret;
}