---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Convex Hull Trick
    links: []
  bundledCode: "#line 1 \"data-structure/convex_hull_trick.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Convex Hull Trick\n */\ntemplate <typename T>\nclass ConvexHullTrick\
    \ {\npublic:\n    void add(T a, T b) {\n        std::pair<T, T> line(a, b);\n\
    \        while (lines.size() >= 2 && check(*(lines.end() - 2), lines.back(), line))\
    \ {\n            lines.pop_back();\n        }\n        lines.push_back(line);\n\
    \    }\n\n    T get(T x) {\n        int lb = 0, ub = lines.size() - 1;\n     \
    \   while (ub - lb > 1) {\n            int m = (lb + ub) / 2;\n            if\
    \ (f(m, x) > f(m + 1, x))) lb = m;\n            else ub = m;\n        }\n    \
    \    return f(ub, x);\n    }\n\nprivate:\n    std::vector<std::pair<T, T>> lines;\n\
    \n    bool check(const std::pair<T, T>& l1, const std::pair<T, T>& l2, const std::pair<T,\
    \ T>& l3) {\n        if (l1 > l3) std::swap(l1, l3);\n        return (l3.first\
    \ - l1.first) * (l2.second - l1.second) >= (l2.first - l1.first) * (l3.second\
    \ - l1.second);\n\n    }\n\n    inline T f(int i, T x) {\n        return lines[i].first\
    \ * x + lines[i].second;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Convex Hull Trick\n */\ntemplate\
    \ <typename T>\nclass ConvexHullTrick {\npublic:\n    void add(T a, T b) {\n \
    \       std::pair<T, T> line(a, b);\n        while (lines.size() >= 2 && check(*(lines.end()\
    \ - 2), lines.back(), line)) {\n            lines.pop_back();\n        }\n   \
    \     lines.push_back(line);\n    }\n\n    T get(T x) {\n        int lb = 0, ub\
    \ = lines.size() - 1;\n        while (ub - lb > 1) {\n            int m = (lb\
    \ + ub) / 2;\n            if (f(m, x) > f(m + 1, x))) lb = m;\n            else\
    \ ub = m;\n        }\n        return f(ub, x);\n    }\n\nprivate:\n    std::vector<std::pair<T,\
    \ T>> lines;\n\n    bool check(const std::pair<T, T>& l1, const std::pair<T, T>&\
    \ l2, const std::pair<T, T>& l3) {\n        if (l1 > l3) std::swap(l1, l3);\n\
    \        return (l3.first - l1.first) * (l2.second - l1.second) >= (l2.first -\
    \ l1.first) * (l3.second - l1.second);\n\n    }\n\n    inline T f(int i, T x)\
    \ {\n        return lines[i].first * x + lines[i].second;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/convex_hull_trick.cpp
  requiredBy: []
  timestamp: '2020-10-03 18:58:25+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/convex_hull_trick.cpp
layout: document
redirect_from:
- /library/data-structure/convex_hull_trick.cpp
- /library/data-structure/convex_hull_trick.cpp.html
title: Convex Hull Trick
---
