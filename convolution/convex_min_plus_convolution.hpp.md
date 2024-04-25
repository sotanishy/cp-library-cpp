---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: dp/monotone_minima.hpp
    title: Monotone Minima
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
    title: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/convex_min_plus_convolution.hpp\"\n#include\
    \ <limits>\n#include <vector>\n#line 3 \"dp/monotone_minima.hpp\"\n\ntemplate\
    \ <typename F>\nstd::vector<int> monotone_minima(int n, int m, const F& f) {\n\
    \    std::vector<int> idx(n, -1);\n\n    auto calc = [&](const auto& calc, int\
    \ l, int r, int optl,\n                    int optr) -> void {\n        if (l\
    \ > r) return;\n        int m = std::midpoint(l, r);\n        auto mi = f(m, optl);\n\
    \        idx[m] = optl;\n        for (int i = optl + 1; i <= optr; ++i) {\n  \
    \          auto v = f(m, i);\n            if (mi > v) {\n                mi =\
    \ v;\n                idx[m] = i;\n            }\n        }\n        calc(calc,\
    \ l, m - 1, optl, idx[m]);\n        calc(calc, m + 1, r, idx[m], optr);\n    };\n\
    \n    calc(calc, 0, n - 1, 0, m - 1);\n    return idx;\n}\n#line 5 \"convolution/convex_min_plus_convolution.hpp\"\
    \n\n// b is convex\ntemplate <typename T>\nstd::vector<T> convex_min_plus_convolution(const\
    \ std::vector<T>& a,\n                                           const std::vector<T>&\
    \ b) {\n    int len = a.size() + b.size() - 1;\n\n    auto f = [&](int i, int\
    \ j) {\n        if (i - j < 0 || (int)b.size() <= i - j)\n            return std::numeric_limits<T>::max();\n\
    \        return a[j] + b[i - j];\n    };\n\n    auto idx = monotone_minima(len,\
    \ a.size(), f);\n    std::vector<T> res(len);\n    for (int i = 0; i < len; ++i)\
    \ res[i] = f(i, idx[i]);\n    return res;\n}\n\n// b is concave\ntemplate <typename\
    \ T>\nstd::vector<T> concave_max_plus_convolution(std::vector<T> a,\n        \
    \                                    std::vector<T> b) {\n    for (auto& x : a)\
    \ x = -x;\n    for (auto& x : b) x = -x;\n    auto c = convex_min_plus_convolution(a,\
    \ b);\n    for (auto& x : c) x = -x;\n    return c;\n}\n"
  code: "#pragma once\n#include <limits>\n#include <vector>\n#include \"../dp/monotone_minima.hpp\"\
    \n\n// b is convex\ntemplate <typename T>\nstd::vector<T> convex_min_plus_convolution(const\
    \ std::vector<T>& a,\n                                           const std::vector<T>&\
    \ b) {\n    int len = a.size() + b.size() - 1;\n\n    auto f = [&](int i, int\
    \ j) {\n        if (i - j < 0 || (int)b.size() <= i - j)\n            return std::numeric_limits<T>::max();\n\
    \        return a[j] + b[i - j];\n    };\n\n    auto idx = monotone_minima(len,\
    \ a.size(), f);\n    std::vector<T> res(len);\n    for (int i = 0; i < len; ++i)\
    \ res[i] = f(i, idx[i]);\n    return res;\n}\n\n// b is concave\ntemplate <typename\
    \ T>\nstd::vector<T> concave_max_plus_convolution(std::vector<T> a,\n        \
    \                                    std::vector<T> b) {\n    for (auto& x : a)\
    \ x = -x;\n    for (auto& x : b) x = -x;\n    auto c = convex_min_plus_convolution(a,\
    \ b);\n    for (auto& x : c) x = -x;\n    return c;\n}\n"
  dependsOn:
  - dp/monotone_minima.hpp
  isVerificationFile: false
  path: convolution/convex_min_plus_convolution.hpp
  requiredBy: []
  timestamp: '2024-04-25 15:52:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
documentation_of: convolution/convex_min_plus_convolution.hpp
layout: document
redirect_from:
- /library/convolution/convex_min_plus_convolution.hpp
- /library/convolution/convex_min_plus_convolution.hpp.html
title: convolution/convex_min_plus_convolution.hpp
---
