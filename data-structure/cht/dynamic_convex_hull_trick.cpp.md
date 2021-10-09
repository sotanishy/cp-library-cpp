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
  bundledCode: "#line 1 \"data-structure/cht/dynamic_convex_hull_trick.cpp\"\n#include\
    \ <bits/stdc++.h>\n\ntemplate <typename T>\nclass DynamicConvexHullTrick {\npublic:\n\
    \    static DynamicConvexHullTrick merge(DynamicConvexHullTrick& a, DynamicConvexHullTrick&\
    \ b) {\n        if (a.lines.size() > b.lines.size()) std::swap(a, b);\n      \
    \  for (auto& l : b.lines) {\n            a.add(l.a, l.b);\n        }\n      \
    \  return a;\n    }\n\n    void add(T a, T b) {\n        auto m = lines.insert({a,\
    \ b, 0});\n        auto l = m, r = m;\n        ++r;\n        while (update(m,\
    \ r)) {\n            r = lines.erase(r);\n        }\n        if (l != lines.begin()\
    \ && update(--l, m)) {\n            m = lines.erase(m);\n            update(l,\
    \ m);\n        }\n        m = l;\n        while (l != lines.begin() && (--l)->p\
    \ >= m->p) {\n            update(l, lines.erase(m));\n            m = l;\n   \
    \     }\n    }\n\n    T get(T x) const {\n        auto it = *lines.lower_bound(x);\n\
    \        return it.a * x + it.b;\n    }\n\nprivate:\n    struct Line {\n     \
    \   T a, b, p;  // ax + b, intersection point with the next line\n        bool\
    \ operator<(const Line& o) const { return a < o.a; }\n        bool operator<(T\
    \ x) const { return p < x; }\n    };\n\n    using iterator = std::multiset<Line>::iterator;\n\
    \n    std::multiset<Line> lines;\n    constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n\n    bool update(iterator x, iterator y) const {\n        if (y == lines.end())\
    \ return false;\n        if (x->a == y->a) {\n            x->p = (x->b > y->b\
    \ ? INF : -INF);\n        } else {\n            x->p = floor_div(y->b - x->b,\
    \ x->a - y->a);\n        }\n        return x->p >= y->p;\n    }\n\n    inline\
    \ T floor_div(T a, T b) const { return a / b - ((a^b) < 0 && a % b); }\n};\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <typename T>\nclass DynamicConvexHullTrick\
    \ {\npublic:\n    static DynamicConvexHullTrick merge(DynamicConvexHullTrick&\
    \ a, DynamicConvexHullTrick& b) {\n        if (a.lines.size() > b.lines.size())\
    \ std::swap(a, b);\n        for (auto& l : b.lines) {\n            a.add(l.a,\
    \ l.b);\n        }\n        return a;\n    }\n\n    void add(T a, T b) {\n   \
    \     auto m = lines.insert({a, b, 0});\n        auto l = m, r = m;\n        ++r;\n\
    \        while (update(m, r)) {\n            r = lines.erase(r);\n        }\n\
    \        if (l != lines.begin() && update(--l, m)) {\n            m = lines.erase(m);\n\
    \            update(l, m);\n        }\n        m = l;\n        while (l != lines.begin()\
    \ && (--l)->p >= m->p) {\n            update(l, lines.erase(m));\n           \
    \ m = l;\n        }\n    }\n\n    T get(T x) const {\n        auto it = *lines.lower_bound(x);\n\
    \        return it.a * x + it.b;\n    }\n\nprivate:\n    struct Line {\n     \
    \   T a, b, p;  // ax + b, intersection point with the next line\n        bool\
    \ operator<(const Line& o) const { return a < o.a; }\n        bool operator<(T\
    \ x) const { return p < x; }\n    };\n\n    using iterator = std::multiset<Line>::iterator;\n\
    \n    std::multiset<Line> lines;\n    constexpr T INF = std::numeric_limits<T>::max()\
    \ / 2;\n\n    bool update(iterator x, iterator y) const {\n        if (y == lines.end())\
    \ return false;\n        if (x->a == y->a) {\n            x->p = (x->b > y->b\
    \ ? INF : -INF);\n        } else {\n            x->p = floor_div(y->b - x->b,\
    \ x->a - y->a);\n        }\n        return x->p >= y->p;\n    }\n\n    inline\
    \ T floor_div(T a, T b) const { return a / b - ((a^b) < 0 && a % b); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/dynamic_convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2021-10-09 19:00:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cht/dynamic_convex_hull_trick.cpp
layout: document
redirect_from:
- /library/data-structure/cht/dynamic_convex_hull_trick.cpp
- /library/data-structure/cht/dynamic_convex_hull_trick.cpp.html
title: data-structure/cht/dynamic_convex_hull_trick.cpp
---
