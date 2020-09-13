#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Partially Persistent Union Find
 * @docs docs/data-structure/partially_persistent_union_find.md
 */
struct PartiallyPersistentUnionFind {
    using time_type = unsigned int;

    vector<size_t> par;
    vector<time_type> time;
    vector<vector<pair<time_type, size_t>>> sz;
    time_type now = 0;
    const time_type INF = numeric_limits<time_type>::max();

    PartiallyPersistentUnionFind(size_t n) : par(n, -1), time(n, INF), sz(n, {{0, 1}}) {}

    size_t find(time_type t, size_t x) {
        if (t < time[x]) return x;
        return find(t, par[x]);
    }

    void unite(size_t x, size_t y) {
        now++;
        x = find(now, x);
        y = find(now, y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        sz[x].emplace_back(now, -par[x]);
        par[y] = x;
        time[y] = now;
    }

    bool same(time_type t, size_t x, size_t y) {
        return find(t, x) == find(t, y);
    }

    size_t size(time_type t, size_t x) {
        x = find(t, x);
        return (--lower_bound(sz[x].begin(), sz[x].end(), make_pair(t, INF)))->second;
    }
};