---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/boruvka.cpp
    title: Boruvka's Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: Kruskal's Algorithm
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_A.test.cpp
    title: test/aoj/DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.boruvka.test.cpp
    title: test/aoj/GRL_2_A.boruvka.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/unionfind/union_find.md
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/union_find.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\n/*\n * @brief Union Find\n * @docs docs/data-structure/unionfind/union_find.md\n\
    \ */\nclass UnionFind {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n/*\n * @brief Union\
    \ Find\n * @docs docs/data-structure/unionfind/union_find.md\n */\nclass UnionFind\
    \ {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int n) : data(n,\
    \ -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return x;\n      \
    \  return data[x] = find(data[x]);\n    }\n\n    void unite(int x, int y) {\n\
    \        x = find(x);\n        y = find(y);\n        if (x == y) return;\n   \
    \     if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n \
    \       data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind/union_find.cpp
  requiredBy:
  - graph/kruskal.cpp
  - graph/boruvka.cpp
  timestamp: '2020-10-24 00:37:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/GRL_2_A.boruvka.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/yosupo/unionfind.test.cpp
documentation_of: data-structure/unionfind/union_find.cpp
layout: document
redirect_from:
- /library/data-structure/unionfind/union_find.cpp
- /library/data-structure/unionfind/union_find.cpp.html
title: Union Find
---
# Union Find

Union find (素集合データ構造) は，素集合を管理するデータ構造である．

この実装では経路圧縮と union by size を使用している．

空間計算量: $O(n)$

## Constructor

- `UnionFind(int n)`
    - サイズ`n`の union find を構築する．
    - 時間計算量: $O(n)$

## Member functions

- `int find(int x)`
    - $x$ が属する木の根を返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(int x, int y)`
    - $x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `int size(int x)`
    - $x$ が属する集合の大きさを返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ は逆アッカーマン関数である．