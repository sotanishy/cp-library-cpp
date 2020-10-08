#include <bits/stdc++.h>

/*
 * @brief Weighted Union Find
 * @docs docs/data-structure/unionfind/weighted_union_find.md
 */
template <typename T>
class WeightedUnionFind {
public:
    WeightedUnionFind() = default;
    explicit WeightedUnionFind(int n) : data(n, -1), ws(n) {}

    int find(int x) {
        if (data[x] < 0) return x;
        int r = find(data[x]);
        ws[x] += ws[data[x]];
        return data[x] = r;
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
        if (data[x] > data[y]) {
            std::swap(x, y);
            w = -w;
        }
        data[x] += data[y];
        data[y] = x;
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
        return -data[find(x)];
    }

private:
    std::vector<int> data;
    std::vector<T> ws;
};