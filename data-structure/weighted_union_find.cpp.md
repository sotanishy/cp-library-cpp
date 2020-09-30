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
    _deprecated_at_docs: docs/data-structure/weighted_union_find.md
    document_title: Weighted Union Find
    links: []
  bundledCode: "#line 1 \"data-structure/weighted_union_find.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Weighted Union Find\n * @docs docs/data-structure/weighted_union_find.md\n\
    \ */\ntemplate <typename T>\nclass WeightedUnionFind {\npublic:\n    WeightedUnionFind()\
    \ = default;\n    explicit WeightedUnionFind(int n) : data(n, -1), ws(n) {}\n\n\
    \    int find(int x) {\n        if (data[x] < 0) return x;\n        int r = find(data[x]);\n\
    \        ws[x] += ws[data[x]];\n        return data[x] = r;\n    }\n\n    T weight(int\
    \ x) {\n        find(x);\n        return ws[x];\n    }\n\n    bool unite(int x,\
    \ int y, T w) {\n        w += weight(x);\n        w -= weight(y);\n        x =\
    \ find(x);\n        y = find(y);\n        if (x == y) return false;\n        if\
    \ (data[x] > data[y]) {\n            std::swap(x, y);\n            w = -w;\n \
    \       }\n        data[x] += data[y];\n        data[y] = x;\n        ws[y] =\
    \ w;\n        return true;\n    }\n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    T diff(int x, int y) {\n        return weight(y)\
    \ - weight(x);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n    std::vector<T> ws;\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Weighted Union Find\n * @docs docs/data-structure/weighted_union_find.md\n\
    \ */\ntemplate <typename T>\nclass WeightedUnionFind {\npublic:\n    WeightedUnionFind()\
    \ = default;\n    explicit WeightedUnionFind(int n) : data(n, -1), ws(n) {}\n\n\
    \    int find(int x) {\n        if (data[x] < 0) return x;\n        int r = find(data[x]);\n\
    \        ws[x] += ws[data[x]];\n        return data[x] = r;\n    }\n\n    T weight(int\
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
  path: data-structure/weighted_union_find.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_1_B.test.cpp
documentation_of: data-structure/weighted_union_find.cpp
layout: document
redirect_from:
- /library/data-structure/weighted_union_find.cpp
- /library/data-structure/weighted_union_find.cpp.html
title: Weighted Union Find
---
# Weighted Union Find

重み付き union find は，union find の操作に加えて，同じ集合に属する他の要素に対する要素の相対的な重みを管理する．

この実装では経路圧縮と union by size を使用している．

空間計算量: $O(n)$

## Template parameters

- `T`
    - 重みの型

## Constructor

- `WeightedUnionFind(int n)`
    - サイズ`n`の重み付き union find を構築する．
    - 時間計算量: $O(n)$

## Member functions

- `int find(int x)`
    - $x$ が属する木の根を返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `T weight(int x)`
    - 木の根に対する $x$ の重みを返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(int x, int y, T w)`
    - $x$ が属する集合と $y$ が属する集合を $weight(y) - weight(x) = w$ となるように連結する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `T diff(int x, int y)`
    - $x$ に対する $y$ の重み，すなわち $weight(y) - weight(x)$ を返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `int size(int x)`
    - $x$ が属する集合の大きさを返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ は逆アッカーマン関数である．