#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Weighted Union Find
 * @docs docs/data-structure/weighted_union_find.md
 */
template <typename T>
struct WeightedUnionFind {
    vector<int> par;
    vector<T> ws;

    WeightedUnionFind(size_t n) : par(n, -1), ws(n) {}

    size_t find(size_t x) {
        if (par[x] < 0) return x;
        size_t r = find(par[x]);
        ws[x] += ws[par[x]];
        return par[x] = r;
    }

    T weight(size_t x) {
        find(x);
        return ws[x];
    }

    bool unite(size_t x, size_t y, T w) {
        w += weight(x);
        w -= weight(y);
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) {
            swap(x, y);
            w = -w;
        }
        par[x] += par[y];
        par[y] = x;
        ws[y] = w;
        return true;
    }

    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }

    T diff(size_t x, size_t y) {
        return weight(y) - weight(x);
    }

    size_t size(size_t x) {
        return -par[find(x)];
    }
};