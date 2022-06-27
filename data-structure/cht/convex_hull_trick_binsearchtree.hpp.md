---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/line_add_get_min.cht.test.cpp
    title: test/yosupo/line_add_get_min.cht.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/cht/convex_hull_trick_binsearchtree.hpp\"\
    \n#include <cassert>\n#include <limits>\n#include <set>\n#include <utility>\n\n\
    template <typename T>\nclass ConvexHullTrick {\npublic:\n\n    void add(T a, T\
    \ b) {\n        a = -a, b = -b;\n        auto m = lines.insert({a, b, 0});\n \
    \       auto l = m, r = m;\n        ++r;\n        while (update(m, r)) {\n   \
    \         r = lines.erase(r);\n        }\n        if (l != lines.begin() && update(--l,\
    \ m)) {\n            m = lines.erase(m);\n            update(l, m);\n        }\n\
    \        m = l;\n        while (l != lines.begin() && (--l)->p >= m->p) {\n  \
    \          update(l, lines.erase(m));\n            m = l;\n        }\n    }\n\n\
    \    T get(T x) const {\n        assert(!lines.empty());\n        auto it = *lines.lower_bound(x);\n\
    \        return -(it.a * x + it.b);\n    }\n\nprivate:\n    struct Line {\n  \
    \      mutable T a, b;  // ax + b\n        mutable double p;  // intersection\
    \ point with the next line\n        bool operator<(const Line& o) const { return\
    \ a < o.a; }\n        bool operator<(T x) const { return p < x; }\n    };\n\n\
    \    using iterator = typename std::multiset<Line, std::less<>>::iterator;\n \
    \   static constexpr double INF = std::numeric_limits<double>::max() / 2;\n\n\
    \    std::multiset<Line, std::less<>> lines;\n\n    bool update(iterator x, iterator\
    \ y) const {\n        if (y == lines.end()) {\n            x->p = INF;\n     \
    \       return false;\n        }\n        if (x->a == y->a) {\n            x->p\
    \ = (x->b > y->b ? INF : -INF);\n        } else {\n            x->p = 1.0 * (y->b\
    \ - x->b) / (x->a - y->a);\n        }\n        return x->p >= y->p;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <set>\n#include\
    \ <utility>\n\ntemplate <typename T>\nclass ConvexHullTrick {\npublic:\n\n   \
    \ void add(T a, T b) {\n        a = -a, b = -b;\n        auto m = lines.insert({a,\
    \ b, 0});\n        auto l = m, r = m;\n        ++r;\n        while (update(m,\
    \ r)) {\n            r = lines.erase(r);\n        }\n        if (l != lines.begin()\
    \ && update(--l, m)) {\n            m = lines.erase(m);\n            update(l,\
    \ m);\n        }\n        m = l;\n        while (l != lines.begin() && (--l)->p\
    \ >= m->p) {\n            update(l, lines.erase(m));\n            m = l;\n   \
    \     }\n    }\n\n    T get(T x) const {\n        assert(!lines.empty());\n  \
    \      auto it = *lines.lower_bound(x);\n        return -(it.a * x + it.b);\n\
    \    }\n\nprivate:\n    struct Line {\n        mutable T a, b;  // ax + b\n  \
    \      mutable double p;  // intersection point with the next line\n        bool\
    \ operator<(const Line& o) const { return a < o.a; }\n        bool operator<(T\
    \ x) const { return p < x; }\n    };\n\n    using iterator = typename std::multiset<Line,\
    \ std::less<>>::iterator;\n    static constexpr double INF = std::numeric_limits<double>::max()\
    \ / 2;\n\n    std::multiset<Line, std::less<>> lines;\n\n    bool update(iterator\
    \ x, iterator y) const {\n        if (y == lines.end()) {\n            x->p =\
    \ INF;\n            return false;\n        }\n        if (x->a == y->a) {\n  \
    \          x->p = (x->b > y->b ? INF : -INF);\n        } else {\n            x->p\
    \ = 1.0 * (y->b - x->b) / (x->a - y->a);\n        }\n        return x->p >= y->p;\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/convex_hull_trick_binsearchtree.hpp
  requiredBy: []
  timestamp: '2022-06-27 13:45:26+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/line_add_get_min.cht.test.cpp
documentation_of: data-structure/cht/convex_hull_trick_binsearchtree.hpp
layout: document
title: Convex Hull Trick (Binary Search Tree)
---

## Description

Convex hull trick は，直線集合 $L$ への追加クエリと最小値クエリを効率的に行う手法である．本実装では平衡二分探索木を用いており，追加する直線の傾きの単調性が無くても動作する．

空間計算量: $O(n)$

## Operations

- `T add(T a, T b)`
    - 直線 $ax + b$ を $L$ に追加する
    - 時間計算量: $O(\log n)$
- `T get(T x)`
    - 与えられた $x$ に対し，$L$ の中で最小値を取る直線の値を求める
    - 時間計算量: $O(\log n)$