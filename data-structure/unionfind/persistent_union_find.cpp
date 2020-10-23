#pragma once
#include <algorithm>
#include <vector>
#include "../persistent_array.cpp"

/*
 * @brief Persistent Union Find
 * @docs docs/data-structure/unionfind/persistent_union_find.md
 */
class PersistentUnionFind {
public:
    PersistentUnionFind() = default;
    explicit PersistentUnionFind(int n) : data(std::vector<int>(n, -1)) {}

    int find(int x) const {
        int p = data.get(x);
        if (p < 0) return x;
        return find(p);
    }

    PersistentUnionFind unite(int x, int y) const {
        x = find(x);
        y = find(y);
        if (x == y) return *this;
        int u = data.get(x);
        int v = data.get(y);
        if (u > v) std::swap(x, y);
        auto tmp = data.set(x, u + v);
        auto res = tmp.set(y, x);
        return PersistentUnionFind(res);
    }

    bool same(int x, int y) const {
        return find(x) == find(y);
    }

    int size(int x) const {
        return -data.get(x);
    }

private:
    PersistentArray<int, 8> data;

    explicit PersistentUnionFind(const PersistentArray<int, 8>& pa) : data(pa) {}
};