#pragma once
#include <algorithm>
#include <cassert>
#include <map>
#include <tuple>
#include <utility>
#include <vector>

#include "../data-structure/unionfind/undoable_union_find.hpp"

template <typename M>
class OfflineDynamicConnectivity {
    using T = typename M::T;

   public:
    OfflineDynamicConnectivity() = default;
    explicit OfflineDynamicConnectivity(int n)
        : OfflineDynamicConnectivity(std::vector<T>(n, M::id())) {}
    explicit OfflineDynamicConnectivity(const std::vector<T>& v) : val(v) {}

    void link(int u, int v) {
        ++now;
        auto edge = std::minmax(u, v);
        open.emplace(edge, now);
    }

    void cut(int u, int v) {
        ++now;
        auto edge = std::minmax(u, v);
        auto it = open.find(edge);
        assert(it != open.end());
        closed.emplace_back(edge.first, edge.second, it->second, now);
        open.erase(it);
    }

    void update(int v, const T& x) {
        ++now;
        query_update.emplace_back(now, v, x);
    }

    void same(int u, int v) {
        ++now;
        query_same[now] = {u, v};
    }

    void component_fold(int v) {
        ++now;
        query_fold[now] = v;
    }

    std::vector<std::pair<bool, T>> run() {
        ++now;

        // cut edges
        for (auto [edge, s] : open) {
            closed.emplace_back(edge.first, edge.second, s, now);
        }

        // build a segment tree
        int size = 1;
        while (size < now) size <<= 1;
        std::vector<std::vector<std::pair<int, int>>> edges(2 * size);
        std::vector<std::vector<std::pair<int, T>>> updates(2 * size);

        for (auto [u, v, s, t] : closed) {
            for (s += size, t += size; s < t; s >>= 1, t >>= 1) {
                if (s & 1) edges[s++].emplace_back(u, v);
                if (t & 1) edges[--t].emplace_back(u, v);
            }
        }

        for (auto [s, v, x] : query_update) {
            int t = size;
            for (s += size, t += size; s < t; s >>= 1, t >>= 1) {
                if (s & 1) updates[s++].emplace_back(v, x);
                if (t & 1) updates[--t].emplace_back(v, x);
            }
        }

        // handle queries
        UndoableUnionFind<M> uf(val);
        std::vector<std::pair<bool, T>> ret;

        auto dfs = [&](const auto& self, int k) -> void {
            for (auto [u, v] : edges[k]) {
                uf.unite(u, v);
            }
            for (auto [v, x] : updates[k]) {
                uf.update(v, x);
            }
            if (k < size) {
                self(self, 2 * k);
                self(self, 2 * k + 1);
            } else if (k < size + now) {
                if (query_same.count(k - size)) {
                    auto [u, v] = query_same[k - size];
                    ret.emplace_back(uf.same(u, v), M::id());
                }
                if (query_fold.count(k - size)) {
                    ret.emplace_back(false,
                                     uf.component_fold(query_fold[k - size]));
                }
            }
            for (int i = 0; i < (int)(edges[k].size() + updates[k].size());
                 ++i) {
                uf.undo();
            }
        };

        dfs(dfs, 1);
        return ret;
    }

   private:
    int now = 0;
    std::multimap<std::pair<int, int>, int> open;
    std::vector<std::tuple<int, int, int, int>> closed;
    std::vector<std::tuple<int, int, T>> query_update;
    std::map<int, std::pair<int, int>> query_same;
    std::map<int, int> query_fold;
    std::vector<T> val;
};