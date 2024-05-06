#pragma once
#include <cassert>
#include <utility>
#include <vector>

#include "union_find.hpp"

class StaticRangeUnionFind {
   public:
    StaticRangeUnionFind() = default;
    explicit StaticRangeUnionFind(int n) : n(n), uf(n), lst(n) {}

    void unite(int x, int y, int len) {
        assert(x + len <= n && y + len <= n);
        if (x == y) return;
        lst[len].push_back({x, y});
    }

    std::vector<int> run() {
        for (int len = n - 1; len >= 1; --len) {
            for (auto [x, y] : lst[len]) {
                if (uf.same(x, y)) continue;
                uf.unite(x, y);
                if (len > 1) lst[len - 1].push_back({x + 1, y + 1});
            }
        }
        std::vector<int> res(n);
        for (int i = 0; i < n; ++i) res[i] = uf.find(i);
        return res;
    }

   private:
    int n;
    UnionFind uf;
    std::vector<std::vector<std::pair<int, int>>> lst;
};