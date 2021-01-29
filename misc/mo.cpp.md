---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/mo.cpp\"\n#include <algorithm>\n#include <cmath>\n\
    #include <vector>\n\nclass Mo {\npublic:\n    Mo() = default;\n    explicit Mo(int\
    \ n) : n(n), cnt(0) {}\n\n    void query(int l, int r) {\n        queries.emplace_back(cnt++,\
    \ l, r);\n    }\n\n    template <typename ExL, typename ShL, typename ExR, typename\
    \ ShR, typename Out>\n    void run(ExL exl, ShL shl, ExR exr, ShR shr, Out out)\
    \ {\n        int s = sqrt(n);\n        std::sort(queries.begin(), queries.end(),\
    \ [&](const auto& a, const auto& b) {\n            if (a.l / s != b.l / s) return\
    \ a.l < b.l;\n            return a.r < b.r;\n        });\n        int curL = 0,\
    \ curR = 0;\n        for (auto [id, l, r] : queries) {\n            while (curL\
    \ > l) exl(--curL);\n            while (curL < l) shl(curL++);\n            while\
    \ (curR < r) exr(curR++);\n            while (curR > r) shr(--curR);\n       \
    \     out(id);\n        }\n    }\n\nprivate:\n    struct Query {\n        int\
    \ id, l, r;\n        Query(int id, int l, int r) : id(id), l(l), r(r) {}\n   \
    \ };\n\n    int n, cnt;\n    std::vector<Query> queries;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <vector>\n\
    \nclass Mo {\npublic:\n    Mo() = default;\n    explicit Mo(int n) : n(n), cnt(0)\
    \ {}\n\n    void query(int l, int r) {\n        queries.emplace_back(cnt++, l,\
    \ r);\n    }\n\n    template <typename ExL, typename ShL, typename ExR, typename\
    \ ShR, typename Out>\n    void run(ExL exl, ShL shl, ExR exr, ShR shr, Out out)\
    \ {\n        int s = sqrt(n);\n        std::sort(queries.begin(), queries.end(),\
    \ [&](const auto& a, const auto& b) {\n            if (a.l / s != b.l / s) return\
    \ a.l < b.l;\n            return a.r < b.r;\n        });\n        int curL = 0,\
    \ curR = 0;\n        for (auto [id, l, r] : queries) {\n            while (curL\
    \ > l) exl(--curL);\n            while (curL < l) shl(curL++);\n            while\
    \ (curR < r) exr(curR++);\n            while (curR > r) shr(--curR);\n       \
    \     out(id);\n        }\n    }\n\nprivate:\n    struct Query {\n        int\
    \ id, l, r;\n        Query(int id, int l, int r) : id(id), l(l), r(r) {}\n   \
    \ };\n\n    int n, cnt;\n    std::vector<Query> queries;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:23:01+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: misc/mo.cpp
layout: document
title: Mo's Algorithm
---

## Description

Mo のアルゴリズム，またはクエリ平方分割は，静的な列に対するクエリをオフラインで高速に処理するアルゴリズムである．

## Operations

- `Mo(int n)`
    - 長さ $n$ の列に対するクエリを処理する
    - 時間計算量: $O(1)$
- `void query(int l, int r)`
    - 区間 $[l, r)$ に対してクエリをする
    - 時間計算量: $O(1)$
- `void run(ExL exl, ShL shl, ExR exr, ShR shr, Out out)`
    - 以下の関数を引数に取り，クエリを実行する
        - `exl`: 区間を左に1マス伸ばしたときの状態を更新する
        - `shl`: 区間を左に1マス縮めたときの状態を更新する
        - `exr`: 区間を右に1マス伸ばしたときの状態を更新する
        - `shr`: 区間を右に1マス縮めたときの状態を更新する
        - `out`: $i$ 番目のクエリの結果を計算する
    - 時間計算量: $O(f(n)n\sqrt{n})$, $f(n)$ は状態の更新にかかる計算量

