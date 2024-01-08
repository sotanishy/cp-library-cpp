#pragma once
#include <algorithm>
#include <numeric>
#include <vector>

std::vector<int> dominator_tree(const std::vector<std::vector<int>>& G, int s) {
    const int n = G.size();

    // label nodes with the arrival times of a dfs
    std::vector<int> sdom(n, -1), par(n, -1), vs;
    vs.reserve(n);
    int k = 0;

    auto dfs = [&](auto& dfs, int v) -> void {
        sdom[v] = k++;
        vs.push_back(v);
        for (int c : G[v]) {
            if (sdom[c] == -1) {
                par[c] = v;
                dfs(dfs, c);
            }
        }
    };

    dfs(dfs, s);

    std::vector<std::vector<int>> G_rev(n);
    for (int u = 0; u < n; ++u) {
        if (sdom[u] == -1) continue;
        for (int v : G[u]) {
            G_rev[v].push_back(u);
        }
    }

    // union find with path compression
    std::vector<int> dsu(n), val(n);
    std::iota(dsu.begin(), dsu.end(), 0);
    std::iota(val.begin(), val.end(), 0);

    auto unite = [&](int u, int v) {  // make u the parent of v
        dsu[v] = u;
    };

    auto find = [&](auto& find, int v) -> int {
        if (v == dsu[v]) return v;
        int r = find(find, dsu[v]);
        if (sdom[val[v]] > sdom[val[dsu[v]]]) {
            val[v] = val[dsu[v]];
        }
        return dsu[v] = r;
    };

    auto eval = [&](int v) {  // return the ancestor of v with minimum sdom
        find(find, v);
        return val[v];
    };

    // calculate sdom
    std::vector<int> us(n);
    std::vector<std::vector<int>> bucket(n);
    for (int i = k - 1; i > 0; --i) {
        int w = vs[i];
        for (int v : G_rev[w]) {
            sdom[w] = std::min(sdom[w], sdom[eval(v)]);
        }
        bucket[vs[sdom[w]]].push_back(w);
        for (int v : bucket[par[w]]) {
            us[v] = eval(v);
        }
        bucket[par[w]].clear();
        unite(par[w], w);
    }

    // calculate idom
    std::vector<int> idom(n, -1);
    idom[s] = sdom[s];
    for (int i = 1; i < k; ++i) {
        int w = vs[i], u = us[w];
        idom[w] = (sdom[w] == sdom[u] ? sdom[w] : idom[u]);
    }
    for (int v : vs) {
        idom[v] = vs[idom[v]];
    }
    return idom;
}