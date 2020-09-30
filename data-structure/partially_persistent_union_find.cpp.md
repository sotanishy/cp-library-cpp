---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/data-structure/partially_persistent_union_find.md
    document_title: Partially Persistent Union Find
    links: []
  bundledCode: "#line 1 \"data-structure/partially_persistent_union_find.cpp\"\n#include\
    \ <bits/stdc++.h>\n\n/*\n * @brief Partially Persistent Union Find\n * @docs docs/data-structure/partially_persistent_union_find.md\n\
    \ */\nclass PartiallyPersistentUnionFind {\npublic:\n    PartiallyPersistentUnionFind()\
    \ = default;\n    explicit PartiallyPersistentUnionFind(int n) : data(n, -1),\
    \ time(n, INF), sz(n, {{0, 1}}) {}\n\n    int find(int t, int x) {\n        if\
    \ (t < time[x]) return x;\n        return find(t, data[x]);\n    }\n\n    void\
    \ unite(int x, int y) {\n        ++now;\n        x = find(now, x);\n        y\
    \ = find(now, y);\n        if (x == y) return;\n        if (data[x] > data[y])\
    \ std::swap(x, y);\n        data[x] += data[y];\n        sz[x].emplace_back(now,\
    \ -data[x]);\n        data[y] = x;\n        time[y] = now;\n    }\n\n    bool\
    \ same(int t, int x, int y) {\n        return find(t, x) == find(t, y);\n    }\n\
    \n    int size(int t, int x) {\n        x = find(t, x);\n        return (--std::lower_bound(sz[x].begin(),\
    \ sz[x].end(), std::make_pair(t, INF)))->second;\n    }\n\nprivate:\n    const\
    \ int INF = std::numeric_limits<int>::max();\n\n    std::vector<int> data;\n \
    \   std::vector<int> time;\n    std::vector<std::vector<std::pair<int, int>>>\
    \ sz;\n    int now = 0;\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Partially Persistent Union Find\n\
    \ * @docs docs/data-structure/partially_persistent_union_find.md\n */\nclass PartiallyPersistentUnionFind\
    \ {\npublic:\n    PartiallyPersistentUnionFind() = default;\n    explicit PartiallyPersistentUnionFind(int\
    \ n) : data(n, -1), time(n, INF), sz(n, {{0, 1}}) {}\n\n    int find(int t, int\
    \ x) {\n        if (t < time[x]) return x;\n        return find(t, data[x]);\n\
    \    }\n\n    void unite(int x, int y) {\n        ++now;\n        x = find(now,\
    \ x);\n        y = find(now, y);\n        if (x == y) return;\n        if (data[x]\
    \ > data[y]) std::swap(x, y);\n        data[x] += data[y];\n        sz[x].emplace_back(now,\
    \ -data[x]);\n        data[y] = x;\n        time[y] = now;\n    }\n\n    bool\
    \ same(int t, int x, int y) {\n        return find(t, x) == find(t, y);\n    }\n\
    \n    int size(int t, int x) {\n        x = find(t, x);\n        return (--std::lower_bound(sz[x].begin(),\
    \ sz[x].end(), std::make_pair(t, INF)))->second;\n    }\n\nprivate:\n    const\
    \ int INF = std::numeric_limits<int>::max();\n\n    std::vector<int> data;\n \
    \   std::vector<int> time;\n    std::vector<std::vector<std::pair<int, int>>>\
    \ sz;\n    int now = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/partially_persistent_union_find.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/partially_persistent_union_find.cpp
layout: document
redirect_from:
- /library/data-structure/partially_persistent_union_find.cpp
- /library/data-structure/partially_persistent_union_find.cpp.html
title: Partially Persistent Union Find
---
# Partially Persistent Union Find

部分永続 union find は素集合森の過去の情報を保持する．以下の操作を実現する:
- 2つの集合を連結する
- 時刻 $t$ で2つの要素が同じ集合に属していたか判定する
- 時刻 $t$ での集合の大きさを返す

空間計算量: $O(n + q)$

## Constructor

- `PartiallyPersistentUnionFind(int n)`
    - サイズ`n`の部分永続 union find を構築する．時刻の初期値は 0 である．
    - 時間計算量: $O(n)$

## Member functions

- `int find(int t, int x)`
    - 時刻 $t$ で $x$ が属する木の根を返す
    - 時間計算量: $O(\lg n)$
- `void unite(int x, int y)`
    - 時刻を 1 増加させ，$x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $O(\lg n)$
- `bool same(int t, int x, int y)`
    - 時刻 $t$ で $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $O(\lg n)$
- `int size(int t, int x)`
    - 時刻 $t$ で $x$ が属する集合の大きさを返す
    - 時間計算量: $O(\lg n)$

## Reference

[部分永続Union-Find Treeについて](https://noshi91.hatenablog.com/entry/2018/02/18/161529)