---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/mst.cpp
    title: Minimum Spanning Tree Algorithms
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
    path: test/aoj/GRL_2_A.prim.test.cpp
    title: test/aoj/GRL_2_A.prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/unionfind.test.cpp
    title: test/yosupo/unionfind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/union_find.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\nclass UnionFind {\npublic:\n    UnionFind() = default;\n\
    \    explicit UnionFind(int n) : data(n, -1) {}\n\n    int find(int x) {\n   \
    \     if (data[x] < 0) return x;\n        return data[x] = find(data[x]);\n  \
    \  }\n\n    void unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if (x == y) return;\n        if (data[x] > data[y]) std::swap(x, y);\n\
    \        data[x] += data[y];\n        data[y] = x;\n    }\n\n    bool same(int\
    \ x, int y) {\n        return find(x) == find(y);\n    }\n\n    int size(int x)\
    \ {\n        return -data[find(x)];\n    }\n\nprivate:\n    std::vector<int> data;\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\nclass UnionFind\
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
  - graph/mst.cpp
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/unionfind.test.cpp
  - test/aoj/GRL_2_A.prim.test.cpp
  - test/aoj/GRL_2_A.boruvka.test.cpp
  - test/aoj/DSL_1_A.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
documentation_of: data-structure/unionfind/union_find.cpp
layout: document
redirect_from:
- /library/data-structure/unionfind/union_find.cpp
- /library/data-structure/unionfind/union_find.cpp.html
title: data-structure/unionfind/union_find.cpp
---
