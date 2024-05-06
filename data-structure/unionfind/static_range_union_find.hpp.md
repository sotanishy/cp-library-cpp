---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/static_range_union_find.hpp\"\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\n#line 2 \"data-structure/unionfind/union_find.hpp\"\
    \n#include <algorithm>\n#line 4 \"data-structure/unionfind/union_find.hpp\"\n\n\
    class UnionFind {\n   public:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) { return find(x) ==\
    \ find(y); }\n\n    int size(int x) { return -data[find(x)]; }\n\n   private:\n\
    \    std::vector<int> data;\n};\n#line 7 \"data-structure/unionfind/static_range_union_find.hpp\"\
    \n\nclass StaticRangeUnionFind {\n   public:\n    StaticRangeUnionFind() = default;\n\
    \    explicit StaticRangeUnionFind(int n) : n(n), uf(n), lst(n) {}\n\n    void\
    \ unite(int x, int y, int len) {\n        assert(x + len <= n && y + len <= n);\n\
    \        if (x == y) return;\n        lst[len].push_back({x, y});\n    }\n\n \
    \   std::vector<int> run() {\n        for (int len = n - 1; len >= 1; --len) {\n\
    \            for (auto [x, y] : lst[len]) {\n                if (uf.same(x, y))\
    \ continue;\n                uf.unite(x, y);\n                if (len > 1) lst[len\
    \ - 1].push_back({x + 1, y + 1});\n            }\n        }\n        std::vector<int>\
    \ res(n);\n        for (int i = 0; i < n; ++i) res[i] = uf.find(i);\n        return\
    \ res;\n    }\n\n   private:\n    int n;\n    UnionFind uf;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> lst;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \n#include \"union_find.hpp\"\n\nclass StaticRangeUnionFind {\n   public:\n  \
    \  StaticRangeUnionFind() = default;\n    explicit StaticRangeUnionFind(int n)\
    \ : n(n), uf(n), lst(n) {}\n\n    void unite(int x, int y, int len) {\n      \
    \  assert(x + len <= n && y + len <= n);\n        if (x == y) return;\n      \
    \  lst[len].push_back({x, y});\n    }\n\n    std::vector<int> run() {\n      \
    \  for (int len = n - 1; len >= 1; --len) {\n            for (auto [x, y] : lst[len])\
    \ {\n                if (uf.same(x, y)) continue;\n                uf.unite(x,\
    \ y);\n                if (len > 1) lst[len - 1].push_back({x + 1, y + 1});\n\
    \            }\n        }\n        std::vector<int> res(n);\n        for (int\
    \ i = 0; i < n; ++i) res[i] = uf.find(i);\n        return res;\n    }\n\n   private:\n\
    \    int n;\n    UnionFind uf;\n    std::vector<std::vector<std::pair<int, int>>>\
    \ lst;\n};"
  dependsOn:
  - data-structure/unionfind/union_find.hpp
  isVerificationFile: false
  path: data-structure/unionfind/static_range_union_find.hpp
  requiredBy: []
  timestamp: '2024-05-07 01:21:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/unionfind/static_range_union_find.hpp
layout: document
title: Static Range Union Find
---

## Description

区間に対するマージクエリを静的に処理する．

空間計算量: $O(n\alpha(n) + q)$

## Operations

- `StaticRangeUnionFind(int n)`
    - サイズ`n`の union find を構築する．
    - 時間計算量: $O(n)$
- `void unite(int x, int y, int len)`
    - $[x, x+\mathrm{len})$ と $[y,y+\mathrm{len})$ が属する集合を連結する
    - 時間計算量: $O(1)$
- `vector<int> run()`
    - 各頂点が属する集合の代表元を返す
    - 時間計算量: $O(n\alpha(n) + q)$, $q$ は `unite` クエリの個数

## Note

アルゴリズムを説明する．このアルゴリズムは yosupo 氏による（参考文献参照）．

`unite` クエリを $\mathrm{len}$ の降順に処理する．クエリ $(x,y,\mathrm{len})$ に対する処理は以下のようにする．
1. $x,y$ が同じ集合に属していれば，このクエリの処理を終了する
2. $x,y$ が属する集合をマージし，新たにクエリ $(x+1,y+1,\mathrm{len}-1)$ を追加する

マージが起こる回数はたかだか $n-1$ 回である．また， $(x,y,\mathrm{len})$ の処理を行う際に， $x,y$ がすでに同じ集合に属しているならば，より $\mathrm{len}$ が大きいようなクエリで $(x+1,y+1),(x+2,y+2),\dots$ もすでに処理されているはずだから，このアルゴリズムは正しく動作する．

## Reference

- [Static Range Union Find - よすぽの日記](https://yosupo.hatenablog.com/entry/2019/11/12/001535)
- [verify: https://atcoder.jp/contests/yahoo-procon2018-final/submissions/53204551](https://atcoder.jp/contests/yahoo-procon2018-final/submissions/53204551)
