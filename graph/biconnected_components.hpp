#pragma once
#include <set>
#include <stack>
#include <unordered_map>
#include <utility>
#include <vector>

#include "lowlink.hpp"

std::vector<std::vector<int>> biconnected_components(
    const std::vector<std::vector<int>>& G, const Lowlink& low) {
    std::vector<bool> used(G.size());
    std::stack<std::pair<int, int>> st;
    std::vector<std::vector<int>> blocks;

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
                    std::set<int> block;
                    while (true) {
                        auto e = st.top();
                        st.pop();
                        block.insert(e.first);
                        block.insert(e.second);
                        if (e.first == v) {
                            break;
                        }
                    }
                    blocks.emplace_back(block.begin(), block.end());
                }
            }
        }
    };

    for (int v = 0; v < (int)G.size(); ++v) {
        if (!used[v]) dfs(dfs, v, -1);
        if (G[v].empty()) {
            blocks.push_back({v});
        }
    }

    return blocks;
}

// B: number of blocks, C: number of cut vertices
// 0 through B - 1: block
// B through B + C - 1: cut
std::vector<std::vector<int>> block_cut_tree(
    const std::vector<std::vector<int>>& blocks, const std::vector<int>& cuts) {
    const int B = blocks.size();
    std::vector<std::vector<int>> bct(B + (int)cuts.size());
    std::unordered_map<int, int> cut_idx;
    for (int i = 0; i < (int)cuts.size(); ++i) cut_idx[cuts[i]] = i;

    for (int i = 0; i < (int)blocks.size(); ++i) {
        auto& block = blocks[i];
        for (int v : block) {
            if (cut_idx.contains(v)) {
                int j = B + cut_idx[v];
                bct[i].push_back(j);
                bct[j].push_back(i);
            }
        }
    }

    return bct;
}
