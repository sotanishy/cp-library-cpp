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
  bundledCode: "#line 2 \"data-structure/cht/convex_hull_trick.hpp\"\n#include <algorithm>\n\
    #include <deque>\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass ConvexHullTrick {\n   public:\n    void add(T a, T b) {\n        Line\
    \ line(a, b);\n        while (lines.size() >= 2 &&\n               check(*(lines.end()\
    \ - 2), lines.back(), line)) {\n            lines.pop_back();\n        }\n   \
    \     lines.push_back(line);\n    }\n\n    T get(T x) {\n        while (lines.size()\
    \ >= 2 && lines.front()(x) > lines[1](x)) {\n            lines.pop_front();\n\
    \        }\n        return lines.front()(x);\n    }\n\n   private:\n    struct\
    \ Line {\n        T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n        T operator()(T\
    \ x) const { return a * x + b; }\n    };\n\n    std::deque<Line> lines;\n\n  \
    \  static bool check(Line l1, Line l2, Line l3) {\n        if (l1.a == l2.a) return\
    \ l2.b >= l1.b;\n        if (l2.a == l3.a) return l2.b >= l3.b;\n        return\
    \ 1.0 * (l2.b - l1.b) / (l2.a - l1.a) <=\n               1.0 * (l3.b - l2.b) /\
    \ (l3.a - l2.a);\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <deque>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T>\nclass ConvexHullTrick {\n   public:\n\
    \    void add(T a, T b) {\n        Line line(a, b);\n        while (lines.size()\
    \ >= 2 &&\n               check(*(lines.end() - 2), lines.back(), line)) {\n \
    \           lines.pop_back();\n        }\n        lines.push_back(line);\n   \
    \ }\n\n    T get(T x) {\n        while (lines.size() >= 2 && lines.front()(x)\
    \ > lines[1](x)) {\n            lines.pop_front();\n        }\n        return\
    \ lines.front()(x);\n    }\n\n   private:\n    struct Line {\n        T a, b;\n\
    \        Line(T a, T b) : a(a), b(b) {}\n        T operator()(T x) const { return\
    \ a * x + b; }\n    };\n\n    std::deque<Line> lines;\n\n    static bool check(Line\
    \ l1, Line l2, Line l3) {\n        if (l1.a == l2.a) return l2.b >= l1.b;\n  \
    \      if (l2.a == l3.a) return l2.b >= l3.b;\n        return 1.0 * (l2.b - l1.b)\
    \ / (l2.a - l1.a) <=\n               1.0 * (l3.b - l2.b) / (l3.a - l2.a);\n  \
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cht/convex_hull_trick.hpp
layout: document
redirect_from:
- /library/data-structure/cht/convex_hull_trick.hpp
- /library/data-structure/cht/convex_hull_trick.hpp.html
title: data-structure/cht/convex_hull_trick.hpp
---
