#pragma once
#include <vector>
#include "../graph/scc.cpp"

std::vector<bool> two_sat(int n, const std::vector<std::tuple<int, bool, int, bool>>& clauses) {
    std::vector<std::vector<int>> G(2 * n);
    std::vector<bool> val(n);

    for (auto& [i, f, j, g] : clauses) {
        G[n * f + i].push_back(n * (!g) + j);
        G[n * g + j].push_back(n * (!f) + i);
    }

    auto comp = scc(G);
    for (int i = 0; i < n; ++i) {
        if (comp[i] == comp[n + i]) {
            // not satisfiable
            return {};
        }
        val[i] = comp[i] > comp[n + i];
    }
    return val;
}