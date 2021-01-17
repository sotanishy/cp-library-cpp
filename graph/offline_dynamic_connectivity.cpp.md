---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/undoable_union_find.cpp
    title: Undoable Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/offline_dynamic_connectivity.cpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <map>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n#line 4 \"data-structure/unionfind/undoable_union_find.cpp\"\n#include\
    \ <stack>\n#line 7 \"data-structure/unionfind/undoable_union_find.cpp\"\n\ntemplate\
    \ <typename M>\nclass UndoableUnionFind {\n    using T = typename M::T;\n\npublic:\n\
    \    UndoableUnionFind() = default;\n    explicit UndoableUnionFind(int n) : UndoableUnionFind(std::vector<T>(n,\
    \ M::id)) {}\n    explicit UndoableUnionFind(const std::vector<T>& v)\n      \
    \  : data(v.size(), -1), val(v.begin(), v.end()) {}\n\n    int find(int x) const\
    \ {\n        if (data[x] < 0) return x;\n        return find(data[x]);\n    }\n\
    \n    void unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        history.emplace(-1, 0, M::id);\n        history.emplace(x, data[x], val[x]);\n\
    \        history.emplace(y, data[y], val[y]);\n        if (x == y) return;\n \
    \       if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n        val[x] = M::op(val[x], val[y]);\n    }\n\n    void\
    \ undo() {\n        assert(!history.empty());\n        while (true) {\n      \
    \      auto [x, dx, vx] = history.top();\n            history.pop();\n       \
    \     if (x == -1) break;\n            data[x] = dx;\n            val[x] = vx;\n\
    \        }\n    }\n\n    bool same(int x, int y) const {\n        return find(x)\
    \ == find(y);\n    }\n\n    int size(int x) const {\n        return -data[find(x)];\n\
    \    }\n\n    T component_fold(int x) const {\n        return val[find(x)];\n\
    \    }\n\n    void update(int x, const T& v) {\n        x = find(x);\n       \
    \ history.emplace(-1, 0, M::id);\n        history.emplace(x, data[x], val[x]);\n\
    \        val[x] = M::op(val[x], v);\n    }\n\nprivate:\n    std::vector<int> data;\n\
    \    std::vector<T> val;\n    std::stack<std::tuple<int, int, T>> history;\n};\n\
    #line 9 \"graph/offline_dynamic_connectivity.cpp\"\n\ntemplate <typename M>\n\
    class OfflineDynamicConnectivity {\n    using T = typename M::T;\n\npublic:\n\
    \    OfflineDynamicConnectivity() = default;\n    explicit OfflineDynamicConnectivity(int\
    \ n) : OfflineDynamicConnectivity(std::vector<T>(n, M::id)) {}\n    explicit OfflineDynamicConnectivity(const\
    \ std::vector<T>& v) : val(v) {}\n\n    void link(int u, int v) {\n        ++now;\n\
    \        auto edge = std::minmax(u, v);\n        assert(!open.count(edge));\n\
    \        open[edge] = now;\n    }\n\n    void cut(int u, int v) {\n        ++now;\n\
    \        auto edge = std::minmax(u, v);\n        assert(open.count(edge));\n \
    \       closed.emplace_back(edge.first, edge.second, open[edge], now);\n     \
    \   open.erase(edge);\n    }\n\n    void update(int v, const T& x) {\n       \
    \ ++now;\n        query_update.emplace_back(now, v, x);\n    }\n\n    void component_fold(int\
    \ v) {\n        ++now;\n        query_fold[now] = v;\n    }\n\n    std::vector<T>\
    \ run() {\n        ++now;\n\n        // cut edges\n        for (auto [edge, s]\
    \ : open) {\n            closed.emplace_back(edge.first, edge.second, s, now);\n\
    \        }\n\n        // build a segment tree\n        int size = 1;\n       \
    \ while (size < now) size <<= 1;\n        std::vector<std::vector<std::pair<int,\
    \ int>>> edges(2 * size);\n        std::vector<std::vector<std::pair<int, T>>>\
    \ updates(2 * size);\n\n        for (auto [u, v, s, t] : closed) {\n         \
    \   for (s += size, t += size; s < t; s >>= 1, t >>= 1) {\n                if\
    \ (s & 1) edges[s++].emplace_back(u, v);\n                if (t & 1) edges[--t].emplace_back(u,\
    \ v);\n            }\n        }\n\n        for (auto [s, v, x] : query_update)\
    \ {\n            int t = size;\n            for (s += size, t += size; s < t;\
    \ s >>= 1, t >>= 1) {\n                if (s & 1) updates[s++].emplace_back(v,\
    \ x);\n                if (t & 1) updates[--t].emplace_back(v, x);\n         \
    \   }\n        }\n\n        // handle queries\n        UndoableUnionFind<M> uf(val);\n\
    \        std::vector<T> ret;\n\n        auto dfs = [&](const auto& self, int k)\
    \ -> void {\n            for (auto [u, v] : edges[k]) {\n                uf.unite(u,\
    \ v);\n            }\n            for (auto [v, x] : updates[k]) {\n         \
    \       uf.update(v, x);\n            }\n            if (k < size) {\n       \
    \         self(self, 2 * k);\n                self(self, 2 * k + 1);\n       \
    \     } else if (k < size + now) {\n                if (query_fold.count(k - size))\
    \ {\n                    ret.emplace_back(uf.component_fold(query_fold[k - size]));\n\
    \                }\n            }\n            for (int i = 0; i < (int) (edges[k].size()\
    \ + updates[k].size()); ++i) {\n                uf.undo();\n            }\n  \
    \      };\n\n        dfs(dfs, 1);\n        return ret;\n    }\n\nprivate:\n  \
    \  int now = 0;\n    std::map<std::pair<int, int>, int> open;\n    std::vector<std::tuple<int,\
    \ int, int, int>> closed;\n    std::vector<std::tuple<int, int, T>> query_update;\n\
    \    std::map<int, int> query_fold;\n    std::vector<T> val;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <map>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n#include \"../data-structure/unionfind/undoable_union_find.cpp\"\
    \n\ntemplate <typename M>\nclass OfflineDynamicConnectivity {\n    using T = typename\
    \ M::T;\n\npublic:\n    OfflineDynamicConnectivity() = default;\n    explicit\
    \ OfflineDynamicConnectivity(int n) : OfflineDynamicConnectivity(std::vector<T>(n,\
    \ M::id)) {}\n    explicit OfflineDynamicConnectivity(const std::vector<T>& v)\
    \ : val(v) {}\n\n    void link(int u, int v) {\n        ++now;\n        auto edge\
    \ = std::minmax(u, v);\n        assert(!open.count(edge));\n        open[edge]\
    \ = now;\n    }\n\n    void cut(int u, int v) {\n        ++now;\n        auto\
    \ edge = std::minmax(u, v);\n        assert(open.count(edge));\n        closed.emplace_back(edge.first,\
    \ edge.second, open[edge], now);\n        open.erase(edge);\n    }\n\n    void\
    \ update(int v, const T& x) {\n        ++now;\n        query_update.emplace_back(now,\
    \ v, x);\n    }\n\n    void component_fold(int v) {\n        ++now;\n        query_fold[now]\
    \ = v;\n    }\n\n    std::vector<T> run() {\n        ++now;\n\n        // cut\
    \ edges\n        for (auto [edge, s] : open) {\n            closed.emplace_back(edge.first,\
    \ edge.second, s, now);\n        }\n\n        // build a segment tree\n      \
    \  int size = 1;\n        while (size < now) size <<= 1;\n        std::vector<std::vector<std::pair<int,\
    \ int>>> edges(2 * size);\n        std::vector<std::vector<std::pair<int, T>>>\
    \ updates(2 * size);\n\n        for (auto [u, v, s, t] : closed) {\n         \
    \   for (s += size, t += size; s < t; s >>= 1, t >>= 1) {\n                if\
    \ (s & 1) edges[s++].emplace_back(u, v);\n                if (t & 1) edges[--t].emplace_back(u,\
    \ v);\n            }\n        }\n\n        for (auto [s, v, x] : query_update)\
    \ {\n            int t = size;\n            for (s += size, t += size; s < t;\
    \ s >>= 1, t >>= 1) {\n                if (s & 1) updates[s++].emplace_back(v,\
    \ x);\n                if (t & 1) updates[--t].emplace_back(v, x);\n         \
    \   }\n        }\n\n        // handle queries\n        UndoableUnionFind<M> uf(val);\n\
    \        std::vector<T> ret;\n\n        auto dfs = [&](const auto& self, int k)\
    \ -> void {\n            for (auto [u, v] : edges[k]) {\n                uf.unite(u,\
    \ v);\n            }\n            for (auto [v, x] : updates[k]) {\n         \
    \       uf.update(v, x);\n            }\n            if (k < size) {\n       \
    \         self(self, 2 * k);\n                self(self, 2 * k + 1);\n       \
    \     } else if (k < size + now) {\n                if (query_fold.count(k - size))\
    \ {\n                    ret.emplace_back(uf.component_fold(query_fold[k - size]));\n\
    \                }\n            }\n            for (int i = 0; i < (int) (edges[k].size()\
    \ + updates[k].size()); ++i) {\n                uf.undo();\n            }\n  \
    \      };\n\n        dfs(dfs, 1);\n        return ret;\n    }\n\nprivate:\n  \
    \  int now = 0;\n    std::map<std::pair<int, int>, int> open;\n    std::vector<std::tuple<int,\
    \ int, int, int>> closed;\n    std::vector<std::tuple<int, int, T>> query_update;\n\
    \    std::map<int, int> query_fold;\n    std::vector<T> val;\n};"
  dependsOn:
  - data-structure/unionfind/undoable_union_find.cpp
  isVerificationFile: false
  path: graph/offline_dynamic_connectivity.cpp
  requiredBy: []
  timestamp: '2021-01-17 23:34:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: graph/offline_dynamic_connectivity.cpp
layout: document
title: Offline Dynamic Connectivity
---

## Description

グラフに対する以下のクエリをオフラインで処理する:
- 辺の追加
- 辺の削除
- 連結成分の fold
- 頂点の値の更新

Undo 可能 union find を用いることでこれらの操作を実現する．

空間計算量: $O(n + q\lg q)$, $q$ はクエリ数

## Operations

- `OfflineDynamicConnectivity(int n)`
    - グラフを頂点数 `n`で初期化する．頂点の値は単位元 $e$ で初期化される．
    - 時間計算量: $O(n)$
- `OfflineDynamicConnectivity(vector<T> v)`
    - グラフを頂点数 `n = v.size()`で初期化する．頂点の値は `v` で初期化される．
    - 時間計算量: $O(n)$
- `void link(int u, int v)`
    - 辺 $uv$ を追加する
    - 時間計算量: $O(\lg q)$
- `void cut(int u, int v)`
    - 辺 $uv$ を削除する
    - 時間計算量: $O(\lg q)$
- `void update(int v, T x)`
    - $a_v$ を $a_v \cdot x$ に更新する
    - 時間計算量: $O(1)$
- `void component_fold(int v)`
    - 頂点 $v$ が属する連結成分の頂点の値を fold する
    - 時間計算量: $O(1)$
- `vector<T> run()`
    - クエリを実行し，`component_fold`の結果を返す
    - 時間計算量: $O(n + q\log nq)$