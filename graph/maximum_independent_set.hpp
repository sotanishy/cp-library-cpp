#pragma once
#include <algorithm>
#include <vector>

std::vector<int> maximum_independent_set(
    const std::vector<std::vector<int>>& G) {
    const int n = G.size();
    std::vector<bool> used(n), ans(n);
    std::vector<int> deg(n), dead(n);
    std::ranges::transform(G, deg.begin(), [&](auto& g) { return g.size(); });
    int res = 0, cnt = 0, alive = n;

    auto dfs = [&](const auto& dfs) {
        if (cnt + alive <= res) return;

        int v = -1;
        for (int i = 0; i < n; ++i) {
            if (used[i] || dead[i]) continue;
            if (deg[i] <= 1) {
                v = i;
                break;
            }
            if (v < 0 || deg[v] < deg[i]) v = i;
        }
        if (v < 0) return;

        // not use
        if (deg[v] != 1) {
            dead[v] = true;
            --alive;
            for (int u : G[v]) --deg[u];

            dfs(dfs);

            dead[v] = false;
            ++alive;
            for (int u : G[v]) ++deg[u];
        }

        // use
        used[v] = true;
        --alive;
        for (int u : G[v]) {
            if (!dead[u]) --alive;
            ++dead[u];
        }
        ++cnt;
        if (res < cnt) {
            ans = used;
            res = cnt;
        }

        dfs(dfs);

        used[v] = false;
        ++alive;
        for (int u : G[v]) {
            --dead[u];
            if (!dead[u]) ++alive;
        }
        --cnt;
    };

    dfs(dfs);

    std::vector<int> ret;
    for (int i = 0; i < n; ++i) {
        if (ans[i]) ret.push_back(i);
    }
    return ret;
}