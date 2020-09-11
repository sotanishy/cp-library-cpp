#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Partially Persistent Union Find
 * @docs docs/data-structure/partially_persistent_union_find.md
 */
struct PartiallyPersistentUnionFind {
    vector<int> par, time;
    vector<vector<pair<int, int>>> sz;
    int now = 0;
    const int INF = 1e9;

    PartiallyPersistentUnionFind(int n) : par(n, -1), time(n, INF), sz(n, {{0, 1}}) {}

    int find(int t, int x) {
        if (t < time[x]) return x;
        return find(t, par[x]);
    }

    void unite(int x, int y) {
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

    bool same(int t, int x, int y) {
        return find(t, x) == find(t, y);
    }

    int size(int t, int x) {
        x = find(t, x);
        return (--lower_bound(sz[x].begin(), sz[x].end(), make_pair(t, INF)))->second;
    }
};