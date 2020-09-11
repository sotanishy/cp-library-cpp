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

    WeightedUnionFind(int n) : par(n, -1), ws(n) {}

    int find(int x) {
        if (par[x] < 0) return x;
        int r = find(par[x]);
        ws[x] += ws[par[x]];
        return par[x] = r;
    }

    T weight(int x) {
        find(x);
        return ws[x];
    }

    bool unite(int x, int y, T w) {
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

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }

    int size(int x) {
        return -par[find(x)];
    }
};