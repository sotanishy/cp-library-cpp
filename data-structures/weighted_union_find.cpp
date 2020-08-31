#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct WeightedUnionFind {
    vector<int> par;
    vector<T> weight;

    WeightedUnionFind(int n) : par(n, -1), weight(n) {}

    int find(int x) {
        if (par[x] < 0) return x;
        int r = find(par[x]);
        weight[x] += weight[par[x]];
        return par[x] = r;
    }

    bool unite(int x, int y, T w) {
        w += weight[x] - weight[y];
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) {
            swap(x, y);
            w = -w;
        }
        par[x] += par[y];
        par[y] = x;
        weight[y] = w;
        return true;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    T diff(int x, int y) {
        find(x);
        find(y);
        return weight[y] - weight[x];
    }

    int size(int x) {
        return -par[find(x)];
    }
};