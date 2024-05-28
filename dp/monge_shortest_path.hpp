#pragma once
#include <limits>
#include <vector>

template <typename T, typename F>
std::vector<T> monge_shortest_path(int n, const F& cost) {
    const T INF = std::numeric_limits<T>::max() / 2;
    std::vector<T> dist(n, INF);
    dist[0] = 0;
    std::vector<int> amin(n);

    auto update = [&](int i, int k) {
        if (i <= k) return;
        auto nd = dist[k] + cost(k, i);
        if (nd < dist[i]) {
            dist[i] = nd;
            amin[i] = k;
        }
    };

    auto dfs = [&](auto& dfs, int l, int r) -> void {
        if (r - l == 1) return;
        int m = (l + r) / 2;
        for (int k = amin[l]; k <= amin[r]; ++k) update(m, k);
        dfs(dfs, l, m);
        for (int k = l + 1; k <= m; ++k) update(r, k);
        dfs(dfs, m, r);
    };

    dfs(dfs, 0, n - 1);
    return dist;
}