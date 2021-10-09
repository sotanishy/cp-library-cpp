#pragma once
#include <utility>
#include <vector>

template <typename M,
          typename Cost,
          typename M::T (*leaf)(),
          typename M::T (*apply)(typename M::T, int, int, Cost)>
class Rerooting {
    using T = typename M::T;

public:
    explicit Rerooting(int n) : G(n) {}

    void add_edge(int u, int v, Cost c) {
        G[u].emplace_back(v, c);
        G[v].emplace_back(u, c);
    }

    std::vector<T> run() {
        dp_sub.resize(G.size(), M::id);
        dp_all.resize(G.size());
        dfs_sub(0, -1);
        dfs_all(0, -1, M::id);
        return dp_all;
    }

private:
    std::vector<std::vector<std::pair<int, Cost>>> G;
    std::vector<T> dp_sub, dp_all;

    void dfs_sub(int v, int p) {
        bool is_leaf = true;
        for (auto [c, cost] : G[v]) {
            if (c == p) continue;
            is_leaf = false;
            dfs_sub(c, v);
            dp_sub[v] = M::op(dp_sub[v], apply(dp_sub[c], v, c, cost));
        }
        if (is_leaf) dp_sub[v] = leaf();
    }

    void dfs_all(int v, int p, const T& val) {
        std::vector<T> ds = {val};
        for (auto [c, cost] : G[v]) {
            if (c == p) continue;
            ds.push_back(apply(dp_sub[c], v, c, cost));
        }
        int n = ds.size();
        std::vector<T> head(n + 1, M::id), tail(n + 1, M::id);
        for (int i = 0; i < n; ++i) head[i+1] = M::op(head[i], ds[i]);
        for (int i = n - 1; i >= 0; --i) tail[i] = M::op(ds[i], tail[i+1]);
        dp_all[v] = head[n];
        int k = 1;
        for (auto [c, cost] : G[v]) {
            if (c == p) continue;
            dfs_all(c, v, apply(M::op(head[k], tail[k+1]), c, v, cost));
            ++k;
        }
    }
};