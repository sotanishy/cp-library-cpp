---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/partially_persistent_union_find.cpp\"\
    \n#include <algorithm>\n#include <limits>\n#include <utility>\n#include <vector>\n\
    \nclass PartiallyPersistentUnionFind {\npublic:\n    PartiallyPersistentUnionFind()\
    \ = default;\n    explicit PartiallyPersistentUnionFind(int n) : data(n, -1),\
    \ time(n, INF), sz(n, {{0, 1}}) {}\n\n    int find(int t, int x) const {\n   \
    \     if (t < time[x]) return x;\n        return find(t, data[x]);\n    }\n\n\
    \    void unite(int x, int y) {\n        ++now;\n        x = find(now, x);\n \
    \       y = find(now, y);\n        if (x == y) return;\n        if (data[x] >\
    \ data[y]) std::swap(x, y);\n        data[x] += data[y];\n        sz[x].emplace_back(now,\
    \ -data[x]);\n        data[y] = x;\n        time[y] = now;\n    }\n\n    bool\
    \ same(int t, int x, int y) const {\n        return find(t, x) == find(t, y);\n\
    \    }\n\n    int size(int t, int x) const {\n        x = find(t, x);\n      \
    \  return (--std::lower_bound(sz[x].begin(), sz[x].end(), std::make_pair(t, INF)))->second;\n\
    \    }\n\nprivate:\n    static constexpr int INF = std::numeric_limits<int>::max();\n\
    \n    std::vector<int> data;\n    std::vector<int> time;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> sz;\n    int now = 0;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    #include <vector>\n\nclass PartiallyPersistentUnionFind {\npublic:\n    PartiallyPersistentUnionFind()\
    \ = default;\n    explicit PartiallyPersistentUnionFind(int n) : data(n, -1),\
    \ time(n, INF), sz(n, {{0, 1}}) {}\n\n    int find(int t, int x) const {\n   \
    \     if (t < time[x]) return x;\n        return find(t, data[x]);\n    }\n\n\
    \    void unite(int x, int y) {\n        ++now;\n        x = find(now, x);\n \
    \       y = find(now, y);\n        if (x == y) return;\n        if (data[x] >\
    \ data[y]) std::swap(x, y);\n        data[x] += data[y];\n        sz[x].emplace_back(now,\
    \ -data[x]);\n        data[y] = x;\n        time[y] = now;\n    }\n\n    bool\
    \ same(int t, int x, int y) const {\n        return find(t, x) == find(t, y);\n\
    \    }\n\n    int size(int t, int x) const {\n        x = find(t, x);\n      \
    \  return (--std::lower_bound(sz[x].begin(), sz[x].end(), std::make_pair(t, INF)))->second;\n\
    \    }\n\nprivate:\n    static constexpr int INF = std::numeric_limits<int>::max();\n\
    \n    std::vector<int> data;\n    std::vector<int> time;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> sz;\n    int now = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind/partially_persistent_union_find.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/unionfind/partially_persistent_union_find.cpp
layout: document
title: Partially Persistent Union Find
---

## Description

部分永続 union find は素集合森の過去の連結性に関する情報を保持する．以下の操作を提供する:
- 2つの集合を連結する
- 時刻 $t$ で2つの要素が同じ集合に属していたか判定する
- 時刻 $t$ での集合の大きさを返す

空間計算量: $O(n + q)$

## Operations

- `PartiallyPersistentUnionFind(int n)`
    - サイズ`n`の部分永続 union find を構築する．時刻の初期値は 0 である．
    - 時間計算量: $O(n)$
- `int find(int t, int x)`
    - 時刻 $t$ で $x$ が属する木の根を返す
    - 時間計算量: $O(\log n)$
- `void unite(int x, int y)`
    - 時刻を 1 増加させ，$x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $O(\log n)$
- `bool same(int t, int x, int y)`
    - 時刻 $t$ で $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $O(\log n)$
- `int size(int t, int x)`
    - 時刻 $t$ で $x$ が属する集合の大きさを返す
    - 時間計算量: $O(\log n)$

## Reference

- [部分永続Union-Find Treeについて](https://noshi91.hatenablog.com/entry/2018/02/18/161529)
- verify: [https://atcoder.jp/contests/agc002/submissions/31059136](https://atcoder.jp/contests/agc002/submissions/31059136)