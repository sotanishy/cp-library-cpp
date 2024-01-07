---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segtree/segment_tree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: data-structure/unionfind/union_find.hpp
    title: Union Find
  - icon: ':question:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':question:'
    path: graph/mst.cpp
    title: Minimum Spanning Tree Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/manhattanmst.test.cpp
    title: test/yosupo/manhattanmst.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/manhattan_mst.hpp\"\n#include <algorithm>\n#include\
    \ <limits>\n#include <vector>\n\n#line 3 \"data-structure/segtree/segment_tree.hpp\"\
    \n#include <bit>\n#line 5 \"data-structure/segtree/segment_tree.hpp\"\n\ntemplate\
    \ <typename M>\nclass SegmentTree {\n    using T = M::T;\n\n   public:\n    SegmentTree()\
    \ = default;\n    explicit SegmentTree(int n) : SegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    explicit SegmentTree(const std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\
    \ node(2 * size, M::id()) {\n        std::ranges::copy(v, node.begin() + size);\n\
    \        for (int i = size - 1; i > 0; --i) {\n            node[i] = M::op(node[2\
    \ * i], node[2 * i + 1]);\n        }\n    }\n\n    T operator[](int k) const {\
    \ return node[k + size]; }\n\n    void update(int k, const T& x) {\n        k\
    \ += size;\n        node[k] = x;\n        while (k >>= 1) node[k] = M::op(node[2\
    \ * k], node[2 * k + 1]);\n    }\n\n    T fold(int l, int r) const {\n       \
    \ T vl = M::id(), vr = M::id();\n        for (l += size, r += size; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) vl = M::op(vl, node[l++]);\n         \
    \   if (r & 1) vr = M::op(node[--r], vr);\n        }\n        return M::op(vl,\
    \ vr);\n    }\n\n    template <typename F>\n    int find_first(int l, F cond)\
    \ const {\n        T v = M::id();\n        for (l += size; l > 0; l >>= 1) {\n\
    \            if (l & 1) {\n                T nv = M::op(v, node[l]);\n       \
    \         if (cond(nv)) {\n                    while (l < size) {\n          \
    \              nv = M::op(v, node[2 * l]);\n                        if (cond(nv))\
    \ {\n                            l = 2 * l;\n                        } else {\n\
    \                            v = nv, l = 2 * l + 1;\n                        }\n\
    \                    }\n                    return l + 1 - size;\n           \
    \     }\n                v = nv;\n                ++l;\n            }\n      \
    \  }\n        return -1;\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) const {\n        T v = M::id();\n        for (r += size; r > 0; r\
    \ >>= 1) {\n            if (r & 1) {\n                --r;\n                T\
    \ nv = M::op(node[r], v);\n                if (cond(nv)) {\n                 \
    \   while (r < size) {\n                        nv = M::op(node[2 * r + 1], v);\n\
    \                        if (cond(nv)) {\n                            r = 2 *\
    \ r + 1;\n                        } else {\n                            v = nv,\
    \ r = 2 * r;\n                        }\n                    }\n             \
    \       return r - size;\n                }\n                v = nv;\n       \
    \     }\n        }\n        return -1;\n    }\n\n   private:\n    int size;\n\
    \    std::vector<T> node;\n};\n#line 2 \"graph/edge.cpp\"\n\ntemplate <typename\
    \ T>\nstruct Edge {\n    int from, to;\n    T weight;\n    Edge() = default;\n\
    \    Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int\
    \ from, int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 3\
    \ \"graph/mst.cpp\"\n#include <queue>\n#include <utility>\n#line 4 \"data-structure/unionfind/union_find.hpp\"\
    \n\nclass UnionFind {\n   public:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) { return find(x) ==\
    \ find(y); }\n\n    int size(int x) { return -data[find(x)]; }\n\n   private:\n\
    \    std::vector<int> data;\n};\n#line 8 \"graph/mst.cpp\"\n\n/*\n * Kruskal's\
    \ Algorithm\n */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>>\
    \ G, int V) {\n    std::sort(G.begin(), G.end(), [](const auto& e1, const auto&\
    \ e2) {\n        return e1.weight < e2.weight;\n    });\n    UnionFind uf(V);\n\
    \    T weight = 0;\n    std::vector<Edge<T>> edges;\n    for (auto& e : G) {\n\
    \        if (!uf.same(e.from, e.to)) {\n            uf.unite(e.from, e.to);\n\
    \            weight += e.weight;\n            edges.push_back(e);\n        }\n\
    \    }\n    return {weight, edges};\n}\n\n/*\n * Prim's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(const std::vector<std::vector<Edge<T>>>&\
    \ G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto& e1,\
    \ const auto& e2) { return e1.weight > e2.weight; };\n    std::priority_queue<Edge<T>,\
    \ std::vector<Edge<T>>, decltype(cmp)> pq(cmp);\n    pq.emplace(0, 0, 0);\n  \
    \  T weight = 0;\n    std::vector<Edge<T>> edges;\n    while (!pq.empty()) {\n\
    \        auto e = pq.top();\n        pq.pop();\n        if (used[e.to]) continue;\n\
    \        used[e.to] = true;\n        weight += e.weight;\n        if (e.to !=\
    \ 0) edges.push_back(e);\n        for (auto& f : G[e.to]) {\n            pq.emplace(e.to,\
    \ f.to, f.weight);\n        }\n    }\n    return {weight, edges};\n}\n\n/*\n *\
    \ Boruvka's Algorithm\n */\ntemplate <typename T>\nstd::pair<T, std::vector<Edge<T>>>\
    \ boruvka(std::vector<Edge<T>> G, int V) {\n    UnionFind uf(V);\n    T weight\
    \ = 0;\n    std::vector<Edge<T>> edges;\n    while (uf.size(0) < V) {\n      \
    \  std::vector<Edge<T>> cheapest(V, {-1, -1, std::numeric_limits<T>::max()});\n\
    \        for (auto& e : G) {\n            if (!uf.same(e.from, e.to)) {\n    \
    \            int u = uf.find(e.from);\n                int v = uf.find(e.to);\n\
    \                if (e.weight < cheapest[u].weight) cheapest[u] = e;\n       \
    \         if (e.weight < cheapest[v].weight) cheapest[v] = e;\n            }\n\
    \        }\n        for (auto& e : cheapest) {\n            if (e.from != -1 &&\
    \ !uf.same(e.from, e.to)) {\n                uf.unite(e.from, e.to);\n       \
    \         weight += e.weight;\n                edges.push_back(e);\n         \
    \   }\n        }\n    }\n    return {weight, edges};\n}\n#line 9 \"graph/manhattan_mst.hpp\"\
    \n\ntemplate <typename U>\nstruct MinMonoid {\n    using T = std::pair<U, int>;\n\
    \    static T id() { return {std::numeric_limits<U>::max(), -1}; }\n    static\
    \ T op(T a, T b) { return std::min(a, b); }\n};\n\ntemplate <typename T>\nstd::pair<T,\
    \ std::vector<Edge<T>>> manhattan_mst(\n    std::vector<std::pair<T, T>> pts)\
    \ {\n    std::vector<int> idx(pts.size());\n    std::iota(idx.begin(), idx.end(),\
    \ 0);\n\n    std::vector<Edge<T>> edges;\n\n    for (int i = 0; i < 2; ++i) {\n\
    \        for (int j = 0; j < 2; ++j) {\n            for (int k = 0; k < 2; ++k)\
    \ {\n                // sort by y-x asc then by y desc\n                std::sort(idx.begin(),\
    \ idx.end(), [&](auto& i, auto& j) {\n                    auto [xi, yi] = pts[i];\n\
    \                    auto [xj, yj] = pts[j];\n                    if (yi - xi\
    \ != yj - xj) return yi - xi < yj - xj;\n                    if (yi != yj) return\
    \ yi > yj;\n                    return i < j;\n                });\n\n       \
    \         // compress y\n                std::vector<T> cs;\n                cs.reserve(pts.size());\n\
    \                for (auto [x, y] : pts) cs.push_back(y);\n                std::sort(cs.begin(),\
    \ cs.end());\n                cs.erase(std::unique(cs.begin(), cs.end()), cs.end());\n\
    \n                // sweep\n                SegmentTree<MinMonoid<T>> st(cs.size());\n\
    \n                for (int i : idx) {\n                    auto [x, y] = pts[i];\n\
    \                    int k =\n                        std::lower_bound(cs.begin(),\
    \ cs.end(), y) - cs.begin();\n                    auto [d, j] = st.fold(k, cs.size());\n\
    \                    if (j != -1) {\n                        edges.push_back(Edge<T>(i,\
    \ j, d - (x + y)));\n                    }\n                    st.update(k, {x\
    \ + y, i});\n                }\n\n                for (auto& p : pts) std::swap(p.first,\
    \ p.second);\n            }\n            for (auto& p : pts) p.first *= -1;\n\
    \        }\n        for (auto& p : pts) p.second *= -1;\n    }\n\n    return kruskal(edges,\
    \ pts.size());\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <vector>\n\
    \n#include \"../data-structure/segtree/segment_tree.hpp\"\n#include \"../graph/edge.cpp\"\
    \n#include \"../graph/mst.cpp\"\n\ntemplate <typename U>\nstruct MinMonoid {\n\
    \    using T = std::pair<U, int>;\n    static T id() { return {std::numeric_limits<U>::max(),\
    \ -1}; }\n    static T op(T a, T b) { return std::min(a, b); }\n};\n\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> manhattan_mst(\n    std::vector<std::pair<T,\
    \ T>> pts) {\n    std::vector<int> idx(pts.size());\n    std::iota(idx.begin(),\
    \ idx.end(), 0);\n\n    std::vector<Edge<T>> edges;\n\n    for (int i = 0; i <\
    \ 2; ++i) {\n        for (int j = 0; j < 2; ++j) {\n            for (int k = 0;\
    \ k < 2; ++k) {\n                // sort by y-x asc then by y desc\n         \
    \       std::sort(idx.begin(), idx.end(), [&](auto& i, auto& j) {\n          \
    \          auto [xi, yi] = pts[i];\n                    auto [xj, yj] = pts[j];\n\
    \                    if (yi - xi != yj - xj) return yi - xi < yj - xj;\n     \
    \               if (yi != yj) return yi > yj;\n                    return i <\
    \ j;\n                });\n\n                // compress y\n                std::vector<T>\
    \ cs;\n                cs.reserve(pts.size());\n                for (auto [x,\
    \ y] : pts) cs.push_back(y);\n                std::sort(cs.begin(), cs.end());\n\
    \                cs.erase(std::unique(cs.begin(), cs.end()), cs.end());\n\n  \
    \              // sweep\n                SegmentTree<MinMonoid<T>> st(cs.size());\n\
    \n                for (int i : idx) {\n                    auto [x, y] = pts[i];\n\
    \                    int k =\n                        std::lower_bound(cs.begin(),\
    \ cs.end(), y) - cs.begin();\n                    auto [d, j] = st.fold(k, cs.size());\n\
    \                    if (j != -1) {\n                        edges.push_back(Edge<T>(i,\
    \ j, d - (x + y)));\n                    }\n                    st.update(k, {x\
    \ + y, i});\n                }\n\n                for (auto& p : pts) std::swap(p.first,\
    \ p.second);\n            }\n            for (auto& p : pts) p.first *= -1;\n\
    \        }\n        for (auto& p : pts) p.second *= -1;\n    }\n\n    return kruskal(edges,\
    \ pts.size());\n}"
  dependsOn:
  - data-structure/segtree/segment_tree.hpp
  - graph/edge.cpp
  - graph/mst.cpp
  - data-structure/unionfind/union_find.hpp
  isVerificationFile: false
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '2024-01-07 20:49:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/manhattanmst.test.cpp
documentation_of: graph/manhattan_mst.hpp
layout: document
title: Manhattan Minimum Spanning Tree
---

## Description

2次元平面上に点が与えられ，各点の間にそのマンハッタン距離の重みを持つ辺が張られているとき，最小全域木を計算する．

## Operations

- `vector<T, Edge<T>> manhattan_mst(vector<pair<T, T>> pts)`
    - `pts` の点からなるグラフの最小全域木を求める
    - 時間計算量: $O(n\log n)$

## Reference

- [Manhattan Minimum Spanning Tree - 霧でも食ってろ](https://knuu.github.io/manhattan_mst.html)
- [Line Sweep Algorithms - topcoder](https://www.topcoder.com/thrive/articles/Line%20Sweep%20Algorithms)
