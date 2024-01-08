---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/cht/convex_hull_trick_binsearchtree.hpp
    title: Convex Hull Trick (Binary Search Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Inner-Product Search
    links: []
  bundledCode: "#line 2 \"data-structure/inner_product_search.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <limits>\n\n#line 4 \"data-structure/cht/convex_hull_trick_binsearchtree.hpp\"\
    \n#include <set>\n#include <utility>\n\ntemplate <typename T>\nclass ConvexHullTrick\
    \ {\n   public:\n    void add(T a, T b) {\n        a = -a, b = -b;\n        auto\
    \ m = lines.insert({a, b, 0});\n        auto l = m, r = m;\n        ++r;\n   \
    \     while (update(m, r)) {\n            r = lines.erase(r);\n        }\n   \
    \     if (l != lines.begin() && update(--l, m)) {\n            m = lines.erase(m);\n\
    \            update(l, m);\n        }\n        m = l;\n        while (l != lines.begin()\
    \ && (--l)->p >= m->p) {\n            update(l, lines.erase(m));\n           \
    \ m = l;\n        }\n    }\n\n    T get(T x) const {\n        assert(!lines.empty());\n\
    \        auto it = *lines.lower_bound(x);\n        return -(it.a * x + it.b);\n\
    \    }\n\n   private:\n    struct Line {\n        mutable T a, b;    // ax + b\n\
    \        mutable double p;  // intersection point with the next line\n       \
    \ bool operator<(const Line& o) const { return a < o.a; }\n        bool operator<(T\
    \ x) const { return p < x; }\n    };\n\n    using iterator = typename std::multiset<Line,\
    \ std::less<>>::iterator;\n    static constexpr double INF = std::numeric_limits<double>::max()\
    \ / 2;\n\n    std::multiset<Line, std::less<>> lines;\n\n    bool update(iterator\
    \ x, iterator y) const {\n        if (y == lines.end()) {\n            x->p =\
    \ INF;\n            return false;\n        }\n        if (x->a == y->a) {\n  \
    \          x->p = (x->b > y->b ? INF : -INF);\n        } else {\n            x->p\
    \ = 1.0 * (y->b - x->b) / (x->a - y->a);\n        }\n        return x->p >= y->p;\n\
    \    }\n};\n#line 7 \"data-structure/inner_product_search.hpp\"\n\n/**\n * @brief\
    \ Inner-Product Search\n */\ntemplate <typename T>\nclass InnerProductSearch {\n\
    \   public:\n    void add(T a, T b) {\n        ++n;\n        a_min = std::min(a_min,\
    \ a);\n        a_max = std::max(a_max, a);\n        cht_pos.add(a, b);\n     \
    \   cht_neg.add(-a, -b);\n    }\n\n    T query(T x, T y) const {\n        assert(n\
    \ > 0);\n        if (y == 0) {\n            return (x > 0 ? a_min : a_max) * x;\n\
    \        } else if (y > 0) {\n            return cht_pos.get(x / y) * y;\n   \
    \     } else {\n            return -cht_neg.get(x / y) * y;\n        }\n    }\n\
    \n    int size() const { return n; }\n\n   private:\n    static constexpr T INF\
    \ = std::numeric_limits<T>::max();\n\n    int n = 0;\n    T a_min = INF, a_max\
    \ = -INF;\n    ConvexHullTrick<T> cht_0, cht_pos, cht_neg;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    \n#include \"cht/convex_hull_trick_binsearchtree.hpp\"\n\n/**\n * @brief Inner-Product\
    \ Search\n */\ntemplate <typename T>\nclass InnerProductSearch {\n   public:\n\
    \    void add(T a, T b) {\n        ++n;\n        a_min = std::min(a_min, a);\n\
    \        a_max = std::max(a_max, a);\n        cht_pos.add(a, b);\n        cht_neg.add(-a,\
    \ -b);\n    }\n\n    T query(T x, T y) const {\n        assert(n > 0);\n     \
    \   if (y == 0) {\n            return (x > 0 ? a_min : a_max) * x;\n        }\
    \ else if (y > 0) {\n            return cht_pos.get(x / y) * y;\n        } else\
    \ {\n            return -cht_neg.get(x / y) * y;\n        }\n    }\n\n    int\
    \ size() const { return n; }\n\n   private:\n    static constexpr T INF = std::numeric_limits<T>::max();\n\
    \n    int n = 0;\n    T a_min = INF, a_max = -INF;\n    ConvexHullTrick<T> cht_0,\
    \ cht_pos, cht_neg;\n};\n"
  dependsOn:
  - data-structure/cht/convex_hull_trick_binsearchtree.hpp
  isVerificationFile: false
  path: data-structure/inner_product_search.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/inner_product_search.hpp
layout: document
redirect_from:
- /library/data-structure/inner_product_search.hpp
- /library/data-structure/inner_product_search.hpp.html
title: Inner-Product Search
---
