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
  bundledCode: "#line 2 \"data-structure/convex_hull_trick.cpp\"\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename T>\nclass ConvexHullTrick\
    \ {\n    using Line = std::pair<T, T>;\n\npublic:\n    explicit ConvexHullTrick(bool\
    \ monotone_query = false) : monotone_query(monotone_query) {}\n\n    void add(T\
    \ a, T b) {\n        Line line(a, b);\n        while (lines.size() >= 2 && check(*(lines.end()\
    \ - 2), lines.back(), line)) {\n            lines.pop_back();\n        }\n   \
    \     lines.push_back(line);\n    }\n\n    T get(T x) {\n        if (monotone_query)\
    \ {\n            while (lines.size() - head >= 2 && f(head, x) > f(head + 1, x))\
    \ {\n                ++head;\n            }\n            return f(head, x);\n\
    \        } else {\n            int lb = -1, ub = lines.size() - 1;\n         \
    \   while (ub - lb > 1) {\n                int m = (lb + ub) / 2;\n          \
    \      if (f(m, x) > f(m + 1, x)) {\n                    lb = m;\n           \
    \     } else {\n                    ub = m;\n                }\n            }\n\
    \            return f(ub, x);\n        }\n    }\n\nprivate:\n    std::vector<Line>\
    \ lines;\n    bool monotone_query;\n    int head = 0;\n\n    bool check(Line l1,\
    \ Line l2, Line l3) {\n        if (l1 > l3) std::swap(l1, l3);\n        return\
    \ (l3.first - l1.first) * (l2.second - l1.second) >=\n               (l2.first\
    \ - l1.first) * (l3.second - l1.second);\n    }\n\n    inline T f(int i, T x)\
    \ {\n        return lines[i].first * x + lines[i].second;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename T>\nclass ConvexHullTrick {\n    using Line = std::pair<T,\
    \ T>;\n\npublic:\n    explicit ConvexHullTrick(bool monotone_query = false) :\
    \ monotone_query(monotone_query) {}\n\n    void add(T a, T b) {\n        Line\
    \ line(a, b);\n        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(),\
    \ line)) {\n            lines.pop_back();\n        }\n        lines.push_back(line);\n\
    \    }\n\n    T get(T x) {\n        if (monotone_query) {\n            while (lines.size()\
    \ - head >= 2 && f(head, x) > f(head + 1, x)) {\n                ++head;\n   \
    \         }\n            return f(head, x);\n        } else {\n            int\
    \ lb = -1, ub = lines.size() - 1;\n            while (ub - lb > 1) {\n       \
    \         int m = (lb + ub) / 2;\n                if (f(m, x) > f(m + 1, x)) {\n\
    \                    lb = m;\n                } else {\n                    ub\
    \ = m;\n                }\n            }\n            return f(ub, x);\n     \
    \   }\n    }\n\nprivate:\n    std::vector<Line> lines;\n    bool monotone_query;\n\
    \    int head = 0;\n\n    bool check(Line l1, Line l2, Line l3) {\n        if\
    \ (l1 > l3) std::swap(l1, l3);\n        return (l3.first - l1.first) * (l2.second\
    \ - l1.second) >=\n               (l2.first - l1.first) * (l3.second - l1.second);\n\
    \    }\n\n    inline T f(int i, T x) {\n        return lines[i].first * x + lines[i].second;\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2021-09-29 23:26:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/convex_hull_trick.cpp
layout: document
title: Convex Hull Trick
---

## Description

Convex hull trick は，直線集合 $L$ への追加クエリと最小値クエリを効率的に行う手法である．

この実装では，追加する直線の傾きが単調非増加である必要がある．傾きに単調性がないときは Li Chao tree を使用のこと．

空間計算量: $O(n)$

## Operations

- `ConvexHullTrick(bool monotone_query)`
    - 最小値クエリの $x$ が単調非減少ならば，`monotone_query = true` とすれば計算量が改善する．デフォルトは `monotone_query = false`
    - 時間計算量: $O(1)$
- `T add(T a, T b)`
    - 直線 $ax + b$ を $L$ に追加する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `T get(T x)`
    - 与えられた $x$ に対し，$L$ の中で最小値を取る直線の値を求める
    - 時間計算量: `monotone_query = true` なら $\mathrm{amortized} O(1)$, `false` なら $O(\lg n)$

## Reference

- [Convex-Hull Trick](https://satanic0258.hatenablog.com/entry/2016/08/16/181331)