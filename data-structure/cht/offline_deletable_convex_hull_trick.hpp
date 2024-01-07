#pragma once
#include <bit>
#include <cassert>
#include <map>
#include <utility>
#include <vector>

#include "undoable_li_chao_tree.hpp"

template <typename T>
class OfflineDeletableConvexHullTrick {
   public:
    void insert(T a, T b) { open.insert({{a, b}, now++}); }

    void erase(T a, T b) {
        auto it = open.find({a, b});
        assert(it != open.end());
        closed.emplace_back(a, b, it->second, now++);
        open.erase(it);
    }

    void get(T x) {
        query[now++] = x;
        xs.push_back(x);
    }

    std::vector<T> run() {
        if (xs.empty()) return {};

        // erase lines
        for (auto [line, s] : open) {
            closed.emplace_back(line.first, line.second, s, now);
        }

        // build a segment tree
        int size = std::bit_ceil((unsigned int)now);
        std::vector<std::vector<std::pair<T, T>>> lines(2 * size);

        for (auto [a, b, s, t] : closed) {
            for (s += size, t += size; s < t; s >>= 1, t >>= 1) {
                if (s & 1) lines[s++].emplace_back(a, b);
                if (t & 1) lines[--t].emplace_back(a, b);
            }
        }

        // handle queries
        UndoableLiChaoTree<T> lct(xs);
        std::vector<T> ret;

        auto dfs = [&](const auto& dfs, int k) -> void {
            for (auto [a, b] : lines[k]) {
                lct.add(a, b);
            }
            if (k < size) {
                dfs(dfs, 2 * k);
                dfs(dfs, 2 * k + 1);
            } else if (k < size + now) {
                if (query.contains(k - size)) {
                    ret.push_back(lct.get(query[k - size]));
                }
            }
            for (int i = 0; i < (int)lines[k].size(); ++i) {
                lct.undo();
            }
        };

        dfs(dfs, 1);
        return ret;
    }

   private:
    int now = 0;
    std::multimap<std::pair<T, T>, int> open;
    std::vector<std::tuple<T, T, int, int>> closed;
    std::map<int, T> query;
    std::vector<T> xs;
};