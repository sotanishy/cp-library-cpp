#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Union Find
 * @docs docs/data-structure/union_find.md
 */
struct UnionFind {
    vector<int> par;

    UnionFind(size_t n) : par(n, -1) {}

    size_t find(size_t x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    void unite(size_t x, size_t y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }

    size_t size(size_t x) {
        return -par[find(x)];
    }
};