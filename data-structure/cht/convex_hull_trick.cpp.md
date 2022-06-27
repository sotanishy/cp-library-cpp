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
  bundledCode: "#line 2 \"data-structure/cht/convex_hull_trick.cpp\"\n#include <algorithm>\n\
    #include <utility>\n#include <vector>\n\ntemplate <typename T>\nclass ConvexHullTrick\
    \ {\npublic:\n    explicit ConvexHullTrick(bool monotone_query = false) : monotone_query(monotone_query)\
    \ {}\n\n    void add(T a, T b) {\n        Line line(a, b);\n        while (lines.size()\
    \ >= 2 && check(*(lines.end() - 2), lines.back(), line)) {\n            lines.pop_back();\n\
    \        }\n        lines.push_back(line);\n    }\n\n    T get(T x) {\n      \
    \  if (monotone_query) {\n            while (lines.size() - head >= 2 && lines[head](x)\
    \ > lines[head + 1](x)) {\n                ++head;\n            }\n          \
    \  return lines[head](x);\n        } else {\n            int lb = -1, ub = lines.size()\
    \ - 1;\n            while (ub - lb > 1) {\n                int m = (lb + ub) /\
    \ 2;\n                if (lines[m](x) > lines[m + 1](x)) {\n                 \
    \   lb = m;\n                } else {\n                    ub = m;\n         \
    \       }\n            }\n            return lines[ub](x);\n        }\n    }\n\
    \nprivate:\n    struct Line {\n        T a, b;\n        Line(T a, T b) : a(a),\
    \ b(b) {}\n        T operator()(T x) const { return a * x + b; }\n    };\n\n \
    \   std::vector<Line> lines;\n    bool monotone_query;\n    int head = 0;\n\n\
    \    static bool check(Line l1, Line l2, Line l3) {\n        if (l2.a == l3.a)\
    \ return l2.b >= l3.b;\n        return 1.0 * (l2.b - l1.b) / (l2.a - l1.a) <=\
    \ 1.0 * (l3.b - l2.b) / (l3.a - l2.a);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename T>\nclass ConvexHullTrick {\npublic:\n    explicit ConvexHullTrick(bool\
    \ monotone_query = false) : monotone_query(monotone_query) {}\n\n    void add(T\
    \ a, T b) {\n        Line line(a, b);\n        while (lines.size() >= 2 && check(*(lines.end()\
    \ - 2), lines.back(), line)) {\n            lines.pop_back();\n        }\n   \
    \     lines.push_back(line);\n    }\n\n    T get(T x) {\n        if (monotone_query)\
    \ {\n            while (lines.size() - head >= 2 && lines[head](x) > lines[head\
    \ + 1](x)) {\n                ++head;\n            }\n            return lines[head](x);\n\
    \        } else {\n            int lb = -1, ub = lines.size() - 1;\n         \
    \   while (ub - lb > 1) {\n                int m = (lb + ub) / 2;\n          \
    \      if (lines[m](x) > lines[m + 1](x)) {\n                    lb = m;\n   \
    \             } else {\n                    ub = m;\n                }\n     \
    \       }\n            return lines[ub](x);\n        }\n    }\n\nprivate:\n  \
    \  struct Line {\n        T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n  \
    \      T operator()(T x) const { return a * x + b; }\n    };\n\n    std::vector<Line>\
    \ lines;\n    bool monotone_query;\n    int head = 0;\n\n    static bool check(Line\
    \ l1, Line l2, Line l3) {\n        if (l2.a == l3.a) return l2.b >= l3.b;\n  \
    \      return 1.0 * (l2.b - l1.b) / (l2.a - l1.a) <= 1.0 * (l3.b - l2.b) / (l3.a\
    \ - l2.a);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2021-10-18 15:45:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cht/convex_hull_trick.cpp
layout: document
title: Convex Hull Trick
---

## Description

Convex hull trick は，直線集合 $L$ への追加クエリと最小値クエリを効率的に行う手法である．

この実装では，追加する直線の傾きが単調非増加である必要がある．傾きに単調性がないときは平衡二分探索木を用いた CHT または Li Chao tree を使用せよ．

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
    - 時間計算量: `monotone_query = true` なら $\mathrm{amortized}\ O(1)$, `false` なら $O(\log n)$

## Reference

- [Convex-Hull Trick](https://satanic0258.hatenablog.com/entry/2016/08/16/181331)