---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/cht/nonlinear_convex_hull_trick.hpp\"\n#include\
    \ <algorithm>\n#include <deque>\n#include <utility>\n\ntemplate <typename T, typename\
    \ F, T (*eval)(F, T)>\nclass NonlinearConvexHullTrick {\n   public:\n    NonlinearConvexHullTrick(T\
    \ lb, T ub) : lb(lb), ub(ub) {}\n\n    void add(const F& f) {\n        T x = lb;\n\
    \        while (funcs.size() >= 2 &&\n               funcs.back().second >=\n\
    \                   (x = intersection(funcs.back().first, f))) {\n           \
    \ funcs.pop_back();\n        }\n        if (funcs.size() == 1) x = intersection(funcs.back().first,\
    \ f);\n        funcs.push_back({f, x});\n    }\n\n    T get(T x) {\n        while\
    \ (funcs.size() >= 2 &&\n               eval(funcs.front().first, x) > eval(funcs[1].first,\
    \ x)) {\n            funcs.pop_front();\n        }\n        funcs.front().second\
    \ = lb;\n        return eval(funcs.front().first, x);\n    }\n\n   private:\n\
    \    // pair (function, intersection with the previous function)\n    std::deque<std::pair<F,\
    \ T>> funcs;\n    T lb, ub;\n\n    // smallest x s.t. f1(x) >= f2(x)\n    T intersection(const\
    \ F& f1, const F& f2) {\n        T l = lb - 1, r = ub + 1;\n        while (r -\
    \ l > 1) {\n            T m = std::midpoint(l, r);\n            if (eval(f1, m)\
    \ < eval(f2, m)) {\n                l = m;\n            } else {\n           \
    \     r = m;\n            }\n        }\n        return r;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <deque>\n#include <utility>\n\
    \ntemplate <typename T, typename F, T (*eval)(F, T)>\nclass NonlinearConvexHullTrick\
    \ {\n   public:\n    NonlinearConvexHullTrick(T lb, T ub) : lb(lb), ub(ub) {}\n\
    \n    void add(const F& f) {\n        T x = lb;\n        while (funcs.size() >=\
    \ 2 &&\n               funcs.back().second >=\n                   (x = intersection(funcs.back().first,\
    \ f))) {\n            funcs.pop_back();\n        }\n        if (funcs.size() ==\
    \ 1) x = intersection(funcs.back().first, f);\n        funcs.push_back({f, x});\n\
    \    }\n\n    T get(T x) {\n        while (funcs.size() >= 2 &&\n            \
    \   eval(funcs.front().first, x) > eval(funcs[1].first, x)) {\n            funcs.pop_front();\n\
    \        }\n        funcs.front().second = lb;\n        return eval(funcs.front().first,\
    \ x);\n    }\n\n   private:\n    // pair (function, intersection with the previous\
    \ function)\n    std::deque<std::pair<F, T>> funcs;\n    T lb, ub;\n\n    // smallest\
    \ x s.t. f1(x) >= f2(x)\n    T intersection(const F& f1, const F& f2) {\n    \
    \    T l = lb - 1, r = ub + 1;\n        while (r - l > 1) {\n            T m =\
    \ std::midpoint(l, r);\n            if (eval(f1, m) < eval(f2, m)) {\n       \
    \         l = m;\n            } else {\n                r = m;\n            }\n\
    \        }\n        return r;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/nonlinear_convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2024-12-20 23:39:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cht/nonlinear_convex_hull_trick.hpp
layout: document
title: Nonlinear Convex Hull Trick
---

## Description

互いにたかだか 1 回しか交わらない関数の集合への追加クエリと最小値取得クエリを処理する．

追加クエリは次の意味での単調性を満たす必要がある：最も新しく追加された関数は，十分大きな $x$ において，集合内の関数の中で最小値を取る．

空間計算量: $O(n)$

## Operations

- `void add(F f)`
    - 関数 $f$ を集合に追加する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `T get(T x)`
    - 与えられた $x$ に対し，最小値を取る関数の値を求める
    - 時間計算量: $\mathrm{amortized}\ O(1)$

## Reference

- verify: [https://atcoder.jp/contests/abc373/submissions/58145171](https://atcoder.jp/contests/abc373/submissions/58145171)