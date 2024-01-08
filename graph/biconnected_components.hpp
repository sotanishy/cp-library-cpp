#pragma once
#include <stack>
#include <utility>
#include <vector>

#include "lowlink.hpp"

std::vector<std::vector<std::pair<int, int>>> biconnected_components(
    const std::vector<std::vector<int>>& G, const Lowlink& low) {
    std::vector<bool> used(G.size());
    std::stack<std::pair<int, int>> st;
    std::vector<std::vector<std::pair<int, int>>> bc;

    auto dfs = [&](auto& dfs, int v, int p) -> void {
        used[v] = true;
        for (int c : G[v]) {
            if (c == p) continue;
            if (!used[c] || low.ord[c] < low.ord[v]) {
                st.emplace(v, c);
            }
            if (!used[c]) {
                dfs(dfs, c, v);
                if (low.ord[v] <= low.low[c]) {  // v is an articulation point
                    bc.emplace_back();
                    while (true) {
                        auto e = st.top();
                        st.pop();
                        bc.back().push_back(e);
                        if (e.first == v) {
                            break;
                        }
                    }
                }
            }
        }
    };

    for (int v = 0; v < (int)G.size(); ++v) {
        if (!used[v]) dfs(dfs, v, -1);
    }

    return bc;
}