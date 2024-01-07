---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/fenwick_tree.hpp
    title: Fenwick Tree
  - icon: ':question:'
    path: tree/centroid_decomposition.hpp
    title: Centroid Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/range_contour_aggregation.hpp\"\n#include <map>\n#include\
    \ <queue>\n#include <utility>\n#include <vector>\n\n#line 2 \"data-structure/fenwick_tree.hpp\"\
    \n#include <functional>\n#line 4 \"data-structure/fenwick_tree.hpp\"\n\ntemplate\
    \ <typename M>\nclass FenwickTree {\n    using T = M::T;\n\n   public:\n    FenwickTree()\
    \ = default;\n    explicit FenwickTree(int n) : n(n), data(n + 1, M::id()) {}\n\
    \n    T prefix_fold(int i) const {\n        T ret = M::id();\n        for (; i\
    \ > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return ret;\n    }\n\n\
    \    void update(int i, const T& x) {\n        for (++i; i <= n; i += i & -i)\
    \ data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const T& x) const\
    \ { return lower_bound(x, std::less<>()); }\n\n    template <typename Compare>\n\
    \    int lower_bound(const T& x, Compare cmp) const {\n        if (!cmp(M::id(),\
    \ x)) return 0;\n        int k = 1;\n        while (k * 2 <= n) k <<= 1;\n   \
    \     int i = 0;\n        T v = M::id();\n        for (; k > 0; k >>= 1) {\n \
    \           if (i + k > n) continue;\n            T nv = M::op(v, data[i + k]);\n\
    \            if (cmp(nv, x)) {\n                v = nv;\n                i +=\
    \ k;\n            }\n        }\n        return i + 1;\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> data;\n};\n#line 2 \"tree/centroid_decomposition.hpp\"\
    \n#include <tuple>\n#line 4 \"tree/centroid_decomposition.hpp\"\n\nstd::tuple<std::vector<int>,\
    \ std::vector<int>, std::vector<int>>\ncentroid_decomposition(const std::vector<std::vector<int>>&\
    \ G) {\n    const int N = G.size();\n    std::vector<int> sz(N), level(N, -1),\
    \ sz_comp(N), par(N);\n\n    auto dfs_size = [&](auto& dfs_size, int v, int p)\
    \ -> int {\n        sz[v] = 1;\n        for (int c : G[v]) {\n            if (c\
    \ != p && level[c] == -1) sz[v] += dfs_size(dfs_size, c, v);\n        }\n    \
    \    return sz[v];\n    };\n\n    auto dfs_centroid = [&](auto& dfs_centroid,\
    \ int v, int p, int n) -> int {\n        for (int c : G[v]) {\n            if\
    \ (c != p && level[c] == -1 && sz[c] > n / 2)\n                return dfs_centroid(dfs_centroid,\
    \ c, v, n);\n        }\n        return v;\n    };\n\n    auto decompose = [&](auto&\
    \ decompose, int v, int k, int p) -> void {\n        int n = dfs_size(dfs_size,\
    \ v, -1);\n        int s = dfs_centroid(dfs_centroid, v, -1, n);\n        level[s]\
    \ = k;\n        sz_comp[s] = n;\n        par[s] = p;\n        for (int c : G[s])\
    \ {\n            if (level[c] == -1) decompose(decompose, c, k + 1, s);\n    \
    \    }\n    };\n\n    decompose(decompose, 0, 0, -1);\n    return {level, sz_comp,\
    \ par};\n}\n#line 9 \"tree/range_contour_aggregation.hpp\"\n\ntemplate <typename\
    \ Group>\nclass RangeContourAggregation {\n    using T = Group::T;\n\n   public:\n\
    \    RangeContourAggregation() = default;\n    explicit RangeContourAggregation(const\
    \ std::vector<std::vector<int>>& G)\n        : seg(G.size()),\n          seg_sub(G.size()),\n\
    \          dist(G.size()),\n          idx(G.size()),\n          sub(G.size()),\n\
    \          idx_sub(G.size()),\n          first(G.size()),\n          first_sub(G.size())\
    \ {\n        std::tie(level, sz_comp, par) = centroid_decomposition(G);\n\n  \
    \      for (int v = 0; v < (int)G.size(); ++v) {\n            // calculate for\
    \ each vertex u,\n            // dist: dist from v\n            // idx: index\
    \ in the BFS order\n            // sub: subtree of v that u belongs to\n     \
    \       // idx_sub: index in the subtree\n\n            // calculate for each\
    \ depth d,\n            // first: first index of depth d\n            // first_sub:\
    \ first index of depth d in the subtree i\n\n            dist[v][v] = 0;\n   \
    \         std::queue<std::pair<int, int>> que;\n            que.push({v, -1});\n\
    \            int k = 0, sub_idx = 0;\n            std::vector<int> ks;\n\n   \
    \         while (!que.empty()) {\n                auto [u, i] = que.front();\n\
    \                que.pop();\n\n                // update component info\n    \
    \            int d = dist[v][u];\n                if (d >= (int)first[v].size())\
    \ {\n                    first[v].push_back(k);\n                }\n         \
    \       idx[v][u] = k++;\n                // enter subtree\n                if\
    \ (d == 1) {\n                    i = sub_idx++;\n                    ks.push_back(0);\n\
    \                    first_sub[v].emplace_back();\n                }\n       \
    \         // update subtree info\n                if (i != -1) {\n           \
    \         sub[v][u] = i;\n                    if (d - 1 >= (int)first_sub[v][i].size())\
    \ {\n                        first_sub[v][i].push_back(ks[i]);\n             \
    \       }\n                    idx_sub[v][u] = ks[i]++;\n                }\n\n\
    \                for (int w : G[u]) {\n                    if (level[w] > level[v]\
    \ && !dist[v].contains(w)) {\n                        dist[v][w] = d + 1;\n  \
    \                      que.push({w, i});\n                    }\n            \
    \    }\n            }\n\n            first[v].push_back(k);\n            seg[v]\
    \ = FenwickTree<Group>(k);\n            for (int i = 0; i < sub_idx; ++i) {\n\
    \                first_sub[v][i].push_back(ks[i]);\n                seg_sub[v].emplace_back(ks[i]);\n\
    \            }\n        }\n    }\n\n    void update(int v, T x) {\n        seg[v].update(0,\
    \ x);\n        for (int p = par[v]; p != -1; p = par[p]) {\n            seg[p].update(idx[p][v],\
    \ x);\n            int i = sub[p][v];\n            seg_sub[p][i].update(idx_sub[p][v],\
    \ x);\n        }\n    }\n\n    T fold(int v, int d) const {\n        int dd =\
    \ std::min((int)first[v].size() - 1, d);\n        T res = seg[v].prefix_fold(first[v][dd]);\n\
    \        for (int p = par[v]; p != -1; p = par[p]) {\n            int dep = d\
    \ - dist[p].at(v);\n            if (dep >= 0) {\n                dd = std::min((int)first[p].size()\
    \ - 1, dep);\n                res = Group::op(res, seg[p].prefix_fold(first[p][dd]));\n\
    \                if (dd > 0) {\n                    int i = sub[p].at(v);\n  \
    \                  dd = std::min((int)first_sub[p][i].size() - 1, dep - 1);\n\
    \                    res = Group::op(res, Group::inv(seg_sub[p][i].prefix_fold(\n\
    \                                             first_sub[p][i][dd])));\n      \
    \          }\n            }\n        }\n        return res;\n    }\n\n   private:\n\
    \    std::vector<int> level, sz_comp, par;\n    std::vector<FenwickTree<Group>>\
    \ seg;\n    std::vector<std::vector<FenwickTree<Group>>> seg_sub;\n    std::vector<std::unordered_map<int,\
    \ int>> dist, idx, sub, idx_sub;\n    std::vector<std::vector<int>> first;\n \
    \   std::vector<std::vector<std::vector<int>>> first_sub;\n};\n"
  code: "#pragma once\n#include <map>\n#include <queue>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"../data-structure/fenwick_tree.hpp\"\n#include \"centroid_decomposition.hpp\"\
    \n\ntemplate <typename Group>\nclass RangeContourAggregation {\n    using T =\
    \ Group::T;\n\n   public:\n    RangeContourAggregation() = default;\n    explicit\
    \ RangeContourAggregation(const std::vector<std::vector<int>>& G)\n        : seg(G.size()),\n\
    \          seg_sub(G.size()),\n          dist(G.size()),\n          idx(G.size()),\n\
    \          sub(G.size()),\n          idx_sub(G.size()),\n          first(G.size()),\n\
    \          first_sub(G.size()) {\n        std::tie(level, sz_comp, par) = centroid_decomposition(G);\n\
    \n        for (int v = 0; v < (int)G.size(); ++v) {\n            // calculate\
    \ for each vertex u,\n            // dist: dist from v\n            // idx: index\
    \ in the BFS order\n            // sub: subtree of v that u belongs to\n     \
    \       // idx_sub: index in the subtree\n\n            // calculate for each\
    \ depth d,\n            // first: first index of depth d\n            // first_sub:\
    \ first index of depth d in the subtree i\n\n            dist[v][v] = 0;\n   \
    \         std::queue<std::pair<int, int>> que;\n            que.push({v, -1});\n\
    \            int k = 0, sub_idx = 0;\n            std::vector<int> ks;\n\n   \
    \         while (!que.empty()) {\n                auto [u, i] = que.front();\n\
    \                que.pop();\n\n                // update component info\n    \
    \            int d = dist[v][u];\n                if (d >= (int)first[v].size())\
    \ {\n                    first[v].push_back(k);\n                }\n         \
    \       idx[v][u] = k++;\n                // enter subtree\n                if\
    \ (d == 1) {\n                    i = sub_idx++;\n                    ks.push_back(0);\n\
    \                    first_sub[v].emplace_back();\n                }\n       \
    \         // update subtree info\n                if (i != -1) {\n           \
    \         sub[v][u] = i;\n                    if (d - 1 >= (int)first_sub[v][i].size())\
    \ {\n                        first_sub[v][i].push_back(ks[i]);\n             \
    \       }\n                    idx_sub[v][u] = ks[i]++;\n                }\n\n\
    \                for (int w : G[u]) {\n                    if (level[w] > level[v]\
    \ && !dist[v].contains(w)) {\n                        dist[v][w] = d + 1;\n  \
    \                      que.push({w, i});\n                    }\n            \
    \    }\n            }\n\n            first[v].push_back(k);\n            seg[v]\
    \ = FenwickTree<Group>(k);\n            for (int i = 0; i < sub_idx; ++i) {\n\
    \                first_sub[v][i].push_back(ks[i]);\n                seg_sub[v].emplace_back(ks[i]);\n\
    \            }\n        }\n    }\n\n    void update(int v, T x) {\n        seg[v].update(0,\
    \ x);\n        for (int p = par[v]; p != -1; p = par[p]) {\n            seg[p].update(idx[p][v],\
    \ x);\n            int i = sub[p][v];\n            seg_sub[p][i].update(idx_sub[p][v],\
    \ x);\n        }\n    }\n\n    T fold(int v, int d) const {\n        int dd =\
    \ std::min((int)first[v].size() - 1, d);\n        T res = seg[v].prefix_fold(first[v][dd]);\n\
    \        for (int p = par[v]; p != -1; p = par[p]) {\n            int dep = d\
    \ - dist[p].at(v);\n            if (dep >= 0) {\n                dd = std::min((int)first[p].size()\
    \ - 1, dep);\n                res = Group::op(res, seg[p].prefix_fold(first[p][dd]));\n\
    \                if (dd > 0) {\n                    int i = sub[p].at(v);\n  \
    \                  dd = std::min((int)first_sub[p][i].size() - 1, dep - 1);\n\
    \                    res = Group::op(res, Group::inv(seg_sub[p][i].prefix_fold(\n\
    \                                             first_sub[p][i][dd])));\n      \
    \          }\n            }\n        }\n        return res;\n    }\n\n   private:\n\
    \    std::vector<int> level, sz_comp, par;\n    std::vector<FenwickTree<Group>>\
    \ seg;\n    std::vector<std::vector<FenwickTree<Group>>> seg_sub;\n    std::vector<std::unordered_map<int,\
    \ int>> dist, idx, sub, idx_sub;\n    std::vector<std::vector<int>> first;\n \
    \   std::vector<std::vector<std::vector<int>>> first_sub;\n};"
  dependsOn:
  - data-structure/fenwick_tree.hpp
  - tree/centroid_decomposition.hpp
  isVerificationFile: false
  path: tree/range_contour_aggregation.hpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
documentation_of: tree/range_contour_aggregation.hpp
layout: document
title: Range Contour Aggregation
---

## Description

木上の等高線集約クエリ (の変種1) (参考文献を参照) を扱う．

空間計算量: $O(n\log n)$

## Operations

- `RangeContourAggregation(vector<vector<int>> G)`
    - 木 $G$ に対する前計算を行う
    - 時間計算量: $O(n\log n)$
- `void update(int v, T x)`
    - 頂点 $v$ の値を $x$ に更新する
    - 時間計算量: $O((\log n)^2)$
- `T fold(int v, int d)`
    - $v$ からの距離が $d$ 未満の頂点の値の総和を求める
    - 時間計算量: $O((\log n)^2)$

## Reference

- [木上の等高線集約クエリ - suisen のブログ](https://suisen-kyopro.hatenablog.com/entry/2022/03/21/220009)