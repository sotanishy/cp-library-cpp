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
    \        }\n        lines.push_back(line);\n    }\n\n    T get(T x) const {\n\
    \        if (monotone_query) {\n            while (lines.size() - head >= 2 &&\
    \ lines[head](x) > lines[head + 1](x)) {\n                ++head;\n          \
    \  }\n            return lines[head](x);\n        } else {\n            int lb\
    \ = -1, ub = lines.size() - 1;\n            while (ub - lb > 1) {\n          \
    \      int m = (lb + ub) / 2;\n                if (lines[m](x) > lines[m + 1](x))\
    \ {\n                    lb = m;\n                } else {\n                 \
    \   ub = m;\n                }\n            }\n            return lines[ub](x);\n\
    \        }\n    }\n\nprivate:\n    struct Line {\n        T a, b;\n        Line(T\
    \ a, T b) : a(a), b(b) {}\n        T operator()(T x) { return a * x + b; }\n \
    \   };\n\n    std::vector<Line> lines;\n    bool monotone_query;\n    int head\
    \ = 0;\n\n    bool check(Line l1, Line l2, Line l3) const {\n        if (l1 >\
    \ l3) std::swap(l1, l3);\n        return (l3.first - l1.first) * (l2.second -\
    \ l1.second) >=\n               (l2.first - l1.first) * (l3.second - l1.second);\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    \ntemplate <typename T>\nclass ConvexHullTrick {\npublic:\n    explicit ConvexHullTrick(bool\
    \ monotone_query = false) : monotone_query(monotone_query) {}\n\n    void add(T\
    \ a, T b) {\n        Line line(a, b);\n        while (lines.size() >= 2 && check(*(lines.end()\
    \ - 2), lines.back(), line)) {\n            lines.pop_back();\n        }\n   \
    \     lines.push_back(line);\n    }\n\n    T get(T x) const {\n        if (monotone_query)\
    \ {\n            while (lines.size() - head >= 2 && lines[head](x) > lines[head\
    \ + 1](x)) {\n                ++head;\n            }\n            return lines[head](x);\n\
    \        } else {\n            int lb = -1, ub = lines.size() - 1;\n         \
    \   while (ub - lb > 1) {\n                int m = (lb + ub) / 2;\n          \
    \      if (lines[m](x) > lines[m + 1](x)) {\n                    lb = m;\n   \
    \             } else {\n                    ub = m;\n                }\n     \
    \       }\n            return lines[ub](x);\n        }\n    }\n\nprivate:\n  \
    \  struct Line {\n        T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n  \
    \      T operator()(T x) { return a * x + b; }\n    };\n\n    std::vector<Line>\
    \ lines;\n    bool monotone_query;\n    int head = 0;\n\n    bool check(Line l1,\
    \ Line l2, Line l3) const {\n        if (l1 > l3) std::swap(l1, l3);\n       \
    \ return (l3.first - l1.first) * (l2.second - l1.second) >=\n               (l2.first\
    \ - l1.first) * (l3.second - l1.second);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2021-10-09 01:30:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cht/convex_hull_trick.cpp
layout: document
redirect_from:
- /library/data-structure/cht/convex_hull_trick.cpp
- /library/data-structure/cht/convex_hull_trick.cpp.html
title: data-structure/cht/convex_hull_trick.cpp
---
