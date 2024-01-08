#pragma once
#include <set>
#include <vector>

#include "../data-structure/partition_refinement.hpp"

std::vector<int> lex_bfs(const std::vector<std::vector<int>>& G) {
    const int n = G.size();
    PartitionRefinement pr(n);
    std::vector<int> prv(1, -1), nxt(1, -1);
    std::vector<int> ord;
    int k = 0;
    for (int i = 0; i < n; ++i) {
        while (pr.size(k) == 0) {
            k = nxt[k];
        }
        int x = pr.member(k);
        ord.push_back(x);
        pr.erase(x);
        std::vector<int> pivot;
        std::set<int> neighbor;
        for (int y : G[x]) {
            if (pr.contains(y)) {
                pivot.push_back(y);
                neighbor.insert(y);
            }
        }
        for (auto [s, t] : pr.refine(pivot)) {
            if ((int)prv.size() <= t) {
                prv.resize(t + 1, -1);
                nxt.resize(t + 1, -1);
            }
            if (neighbor.contains(pr.member(s))) {
                if (nxt[s] >= 0) prv[nxt[s]] = t;
                nxt[t] = nxt[s];
                prv[t] = s;
                nxt[s] = t;
            } else {
                if (prv[s] >= 0) nxt[prv[s]] = t;
                prv[t] = prv[s];
                prv[s] = t;
                nxt[t] = s;
            }
        }
        if (prv[k] != -1) k = prv[k];
    }
    return ord;
}
