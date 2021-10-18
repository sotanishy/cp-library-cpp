---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.cpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/persistent_union_find.cpp\"\n#include\
    \ <algorithm>\n#include <vector>\n#line 2 \"data-structure/persistent_array.cpp\"\
    \n#include <memory>\n#line 4 \"data-structure/persistent_array.cpp\"\n\n/*\n *\
    \ @brief Persistent Array\n * @docs docs/data-structure/persistent_array.md\n\
    \ */\ntemplate <typename T, int B = 2>\nclass PersistentArray {\npublic:\n   \
    \ PersistentArray() = default;\n    explicit PersistentArray(const std::vector<T>&\
    \ v) {\n        for (int i = 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n\
    \    }\n\n    T get(int k) const {\n        return get(root, k);\n    }\n\n  \
    \  PersistentArray set(int k, const T& x) const {\n        return PersistentArray(set(root,\
    \ k, x));\n    }\n\nprivate:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[B];\n    };\n\n    node_ptr\
    \ root = nullptr;\n\n    explicit PersistentArray(const node_ptr& root) : root(root)\
    \ {}\n\n    T get(const node_ptr& t, int k) const {\n        if (k == 0) return\
    \ t->val;\n        return get(t->ch[k % B], k / B);\n    }\n\n    node_ptr set(const\
    \ node_ptr& t, int k, const T& x) const {\n        node_ptr res = t ? std::make_shared<Node>(*t)\
    \ : std::make_shared<Node>();\n        if (k == 0) {\n            res->val = x;\n\
    \        } else {\n            res->ch[k % B] = set(res->ch[k % B], k / B, x);\n\
    \        }\n        return res;\n    }\n};\n#line 5 \"data-structure/unionfind/persistent_union_find.cpp\"\
    \n\nclass PersistentUnionFind {\npublic:\n    PersistentUnionFind() = default;\n\
    \    explicit PersistentUnionFind(int n) : data(std::vector<int>(n, -1)) {}\n\n\
    \    int find(int x) const {\n        int p = data.get(x);\n        if (p < 0)\
    \ return x;\n        return find(p);\n    }\n\n    PersistentUnionFind unite(int\
    \ x, int y) const {\n        x = find(x);\n        y = find(y);\n        if (x\
    \ == y) return *this;\n        int u = data.get(x);\n        int v = data.get(y);\n\
    \        if (u > v) std::swap(x, y);\n        auto tmp = data.set(x, u + v);\n\
    \        auto res = tmp.set(y, x);\n        return PersistentUnionFind(res);\n\
    \    }\n\n    bool same(int x, int y) const {\n        return find(x) == find(y);\n\
    \    }\n\n    int size(int x) const {\n        return -data.get(x);\n    }\n\n\
    private:\n    PersistentArray<int, 8> data;\n\n    explicit PersistentUnionFind(const\
    \ PersistentArray<int, 8>& pa) : data(pa) {}\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include \"../persistent_array.cpp\"\
    \n\nclass PersistentUnionFind {\npublic:\n    PersistentUnionFind() = default;\n\
    \    explicit PersistentUnionFind(int n) : data(std::vector<int>(n, -1)) {}\n\n\
    \    int find(int x) const {\n        int p = data.get(x);\n        if (p < 0)\
    \ return x;\n        return find(p);\n    }\n\n    PersistentUnionFind unite(int\
    \ x, int y) const {\n        x = find(x);\n        y = find(y);\n        if (x\
    \ == y) return *this;\n        int u = data.get(x);\n        int v = data.get(y);\n\
    \        if (u > v) std::swap(x, y);\n        auto tmp = data.set(x, u + v);\n\
    \        auto res = tmp.set(y, x);\n        return PersistentUnionFind(res);\n\
    \    }\n\n    bool same(int x, int y) const {\n        return find(x) == find(y);\n\
    \    }\n\n    int size(int x) const {\n        return -data.get(x);\n    }\n\n\
    private:\n    PersistentArray<int, 8> data;\n\n    explicit PersistentUnionFind(const\
    \ PersistentArray<int, 8>& pa) : data(pa) {}\n};"
  dependsOn:
  - data-structure/persistent_array.cpp
  isVerificationFile: false
  path: data-structure/unionfind/persistent_union_find.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: data-structure/unionfind/persistent_union_find.cpp
layout: document
title: Persistent Union Find
---

## Description

永続 union find は，過去のバージョンを保持する union find である．

空間計算量: $O(n + m \log n)$, $m$ は変更の数

## Operations

- `PersistentUnionFind(int n)`
    - サイズ`n` の永続 union find を構築する
    - 時間計算量: $O(n \log n)$
- `int find(int x)`
    - $x$ が属する木の根を返す
    - 時間計算量: $O(\log^2 n)$
- `PersistentUnionFind unite(int x, int y)`
    - $x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $O(\log^2 n)$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $O(\log^2 n)$
- `int size(int x)`
    - $x$ が属する集合の大きさを返す
    - 時間計算量: $O(\log^2 n)$

## Reference

- [A Persistent Union-Find Data Structure](https://www.lri.fr/~filliatr/ftp/publis/puf-wml07.pdf)