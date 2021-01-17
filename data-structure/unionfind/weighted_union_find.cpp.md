---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/weighted_union_find.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n\ntemplate <typename T>\nclass WeightedUnionFind\
    \ {\npublic:\n    WeightedUnionFind() = default;\n    explicit WeightedUnionFind(int\
    \ n) : data(n, -1), ws(n) {}\n\n    int find(int x) {\n        if (data[x] < 0)\
    \ return x;\n        int r = find(data[x]);\n        ws[x] += ws[data[x]];\n \
    \       return data[x] = r;\n    }\n\n    T weight(int x) {\n        find(x);\n\
    \        return ws[x];\n    }\n\n    bool unite(int x, int y, T w) {\n       \
    \ w += weight(x);\n        w -= weight(y);\n        x = find(x);\n        y =\
    \ find(y);\n        if (x == y) return false;\n        if (data[x] > data[y])\
    \ {\n            std::swap(x, y);\n            w = -w;\n        }\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        ws[y] = w;\n        return true;\n\
    \    }\n\n    bool same(int x, int y) {\n        return find(x) == find(y);\n\
    \    }\n\n    T diff(int x, int y) {\n        return weight(y) - weight(x);\n\
    \    }\n\n    int size(int x) {\n        return -data[find(x)];\n    }\n\nprivate:\n\
    \    std::vector<int> data;\n    std::vector<T> ws;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass WeightedUnionFind {\npublic:\n    WeightedUnionFind() = default;\n\
    \    explicit WeightedUnionFind(int n) : data(n, -1), ws(n) {}\n\n    int find(int\
    \ x) {\n        if (data[x] < 0) return x;\n        int r = find(data[x]);\n \
    \       ws[x] += ws[data[x]];\n        return data[x] = r;\n    }\n\n    T weight(int\
    \ x) {\n        find(x);\n        return ws[x];\n    }\n\n    bool unite(int x,\
    \ int y, T w) {\n        w += weight(x);\n        w -= weight(y);\n        x =\
    \ find(x);\n        y = find(y);\n        if (x == y) return false;\n        if\
    \ (data[x] > data[y]) {\n            std::swap(x, y);\n            w = -w;\n \
    \       }\n        data[x] += data[y];\n        data[y] = x;\n        ws[y] =\
    \ w;\n        return true;\n    }\n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    T diff(int x, int y) {\n        return weight(y)\
    \ - weight(x);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n    std::vector<T> ws;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind/weighted_union_find.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_B.test.cpp
documentation_of: data-structure/unionfind/weighted_union_find.cpp
layout: document
redirect_from:
- /library/data-structure/unionfind/weighted_union_find.cpp
- /library/data-structure/unionfind/weighted_union_find.cpp.html
title: data-structure/unionfind/weighted_union_find.cpp
---
