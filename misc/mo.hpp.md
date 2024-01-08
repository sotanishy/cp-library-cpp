---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/mo.hpp\"\n#include <algorithm>\n#include <cmath>\n\
    #include <vector>\n\nclass Mo {\n   public:\n    Mo() = default;\n    explicit\
    \ Mo(int n) : n(n), cnt(0) {}\n\n    void query(int l, int r) { queries.emplace_back(cnt++,\
    \ l, r); }\n\n    template <typename ExL, typename ShL, typename ExR, typename\
    \ ShR,\n              typename Out>\n    void run(ExL exl, ShL shl, ExR exr, ShR\
    \ shr, Out out) {\n        int s = sqrt(n);\n        std::ranges::sort(\n    \
    \        queries, {}, [&](auto& q) { return std::make_pair(q.l / s, q.r); });\n\
    \        int curL = 0, curR = 0;\n        for (auto [id, l, r] : queries) {\n\
    \            while (curL > l) exl(--curL);\n            while (curR < r) exr(curR++);\n\
    \            while (curL < l) shl(curL++);\n            while (curR > r) shr(--curR);\n\
    \            out(id);\n        }\n    }\n\n   private:\n    struct Query {\n \
    \       int id, l, r;\n    };\n\n    int n, cnt;\n    std::vector<Query> queries;\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <vector>\n\
    \nclass Mo {\n   public:\n    Mo() = default;\n    explicit Mo(int n) : n(n),\
    \ cnt(0) {}\n\n    void query(int l, int r) { queries.emplace_back(cnt++, l, r);\
    \ }\n\n    template <typename ExL, typename ShL, typename ExR, typename ShR,\n\
    \              typename Out>\n    void run(ExL exl, ShL shl, ExR exr, ShR shr,\
    \ Out out) {\n        int s = sqrt(n);\n        std::ranges::sort(\n         \
    \   queries, {}, [&](auto& q) { return std::make_pair(q.l / s, q.r); });\n   \
    \     int curL = 0, curR = 0;\n        for (auto [id, l, r] : queries) {\n   \
    \         while (curL > l) exl(--curL);\n            while (curR < r) exr(curR++);\n\
    \            while (curL < l) shl(curL++);\n            while (curR > r) shr(--curR);\n\
    \            out(id);\n        }\n    }\n\n   private:\n    struct Query {\n \
    \       int id, l, r;\n    };\n\n    int n, cnt;\n    std::vector<Query> queries;\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: misc/mo.hpp
layout: document
title: Mo's Algorithm
---

## Description

Mo のアルゴリズム (クエリ平方分割) は，静的な列に対するクエリをオフラインで高速に処理するアルゴリズムである．

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
