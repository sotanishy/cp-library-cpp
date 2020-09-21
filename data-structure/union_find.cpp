#include <bits/stdc++.h>

/*
 * @brief Union Find
 * @docs docs/data-structure/union_find.md
 */
class UnionFind {
public:
    explicit UnionFind(int n) : data(n, -1) {}

    int find(int x) {
        if (data[x] < 0) return x;
        return data[x] = find(data[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (data[x] > data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -data[find(x)];
    }

private:
    std::vector<int> data;
};