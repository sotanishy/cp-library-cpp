---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/data-structure/partially_persistent_union_find.md
    document_title: Partially Persistent Union Find
    links: []
  bundledCode: "#line 1 \"data-structure/partially_persistent_union_find.cpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Partially Persistent\
    \ Union Find\n * @docs docs/data-structure/partially_persistent_union_find.md\n\
    \ */\nstruct PartiallyPersistentUnionFind {\n    vector<int> par;\n    vector<int>\
    \ time;\n    vector<vector<pair<int, int>>> sz;\n    int now = 0;\n    const int\
    \ INF = numeric_limits<int>::max();\n\n    PartiallyPersistentUnionFind(int n)\
    \ : par(n, -1), time(n, INF), sz(n, {{0, 1}}) {}\n\n    int find(int t, int x)\
    \ {\n        if (t < time[x]) return x;\n        return find(t, par[x]);\n   \
    \ }\n\n    void unite(int x, int y) {\n        now++;\n        x = find(now, x);\n\
    \        y = find(now, y);\n        if (x == y) return;\n        if (par[x] >\
    \ par[y]) swap(x, y);\n        par[x] += par[y];\n        sz[x].emplace_back(now,\
    \ -par[x]);\n        par[y] = x;\n        time[y] = now;\n    }\n\n    bool same(int\
    \ t, int x, int y) {\n        return find(t, x) == find(t, y);\n    }\n\n    int\
    \ size(int t, int x) {\n        x = find(t, x);\n        return (--lower_bound(sz[x].begin(),\
    \ sz[x].end(), make_pair(t, INF)))->second;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Partially\
    \ Persistent Union Find\n * @docs docs/data-structure/partially_persistent_union_find.md\n\
    \ */\nstruct PartiallyPersistentUnionFind {\n    vector<int> par;\n    vector<int>\
    \ time;\n    vector<vector<pair<int, int>>> sz;\n    int now = 0;\n    const int\
    \ INF = numeric_limits<int>::max();\n\n    PartiallyPersistentUnionFind(int n)\
    \ : par(n, -1), time(n, INF), sz(n, {{0, 1}}) {}\n\n    int find(int t, int x)\
    \ {\n        if (t < time[x]) return x;\n        return find(t, par[x]);\n   \
    \ }\n\n    void unite(int x, int y) {\n        now++;\n        x = find(now, x);\n\
    \        y = find(now, y);\n        if (x == y) return;\n        if (par[x] >\
    \ par[y]) swap(x, y);\n        par[x] += par[y];\n        sz[x].emplace_back(now,\
    \ -par[x]);\n        par[y] = x;\n        time[y] = now;\n    }\n\n    bool same(int\
    \ t, int x, int y) {\n        return find(t, x) == find(t, y);\n    }\n\n    int\
    \ size(int t, int x) {\n        x = find(t, x);\n        return (--lower_bound(sz[x].begin(),\
    \ sz[x].end(), make_pair(t, INF)))->second;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/partially_persistent_union_find.cpp
  requiredBy: []
  timestamp: '2020-09-15 16:09:04+09:00'
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