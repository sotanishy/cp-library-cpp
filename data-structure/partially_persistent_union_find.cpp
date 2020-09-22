#include <bits/stdc++.h>

/*
 * @brief Partially Persistent Union Find
 * @docs docs/data-structure/partially_persistent_union_find.md
 */
class PartiallyPersistentUnionFind {
public:
    PartiallyPersistentUnionFind() = default;
    explicit PartiallyPersistentUnionFind(int n) : data(n, -1), time(n, INF), sz(n, {{0, 1}}) {}

    int find(int t, int x) {
        if (t < time[x]) return x;
        return find(t, data[x]);
    }

    void unite(int x, int y) {
        ++now;
        x = find(now, x);
        y = find(now, y);
        if (x == y) return;
        if (data[x] > data[y]) std::swap(x, y);
        data[x] += data[y];
        sz[x].emplace_back(now, -data[x]);
        data[y] = x;
        time[y] = now;
    }

    bool same(int t, int x, int y) {
        return find(t, x) == find(t, y);
    }

    int size(int t, int x) {
        x = find(t, x);
        return (--std::lower_bound(sz[x].begin(), sz[x].end(), std::make_pair(t, INF)))->second;
    }

private:
    const int INF = std::numeric_limits<int>::max();

    std::vector<int> data;
    std::vector<int> time;
    std::vector<std::vector<std::pair<int, int>>> sz;
    int now = 0;
};