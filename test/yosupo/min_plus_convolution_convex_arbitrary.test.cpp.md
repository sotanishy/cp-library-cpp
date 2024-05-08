---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/convex_min_plus_convolution.hpp
    title: Convex Min-Plus Convolution
  - icon: ':heavy_check_mark:'
    path: dp/monotone_minima.hpp
    title: Monotone Minima
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "#line 1 \"test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#include <bits/stdc++.h>\n\n#line 3 \"dp/monotone_minima.hpp\"\n\ntemplate\
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
    \ b);\n    for (auto& x : c) x = -x;\n    return c;\n}\n#line 7 \"test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<long long>\
    \ a(N), b(M);\n    for (auto& x : a) cin >> x;\n    for (auto& x : b) cin >> x;\n\
    \    auto c = convex_min_plus_convolution(b, a);\n    for (int i = 0; i < N +\
    \ M - 1; ++i)\n        cout << c[i] << (i < N + M - 2 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../convolution/convex_min_plus_convolution.hpp\"\
    \nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<long long>\
    \ a(N), b(M);\n    for (auto& x : a) cin >> x;\n    for (auto& x : b) cin >> x;\n\
    \    auto c = convex_min_plus_convolution(b, a);\n    for (int i = 0; i < N +\
    \ M - 1; ++i)\n        cout << c[i] << (i < N + M - 2 ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - convolution/convex_min_plus_convolution.hpp
  - dp/monotone_minima.hpp
  isVerificationFile: true
  path: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  requiredBy: []
  timestamp: '2024-04-25 15:52:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp.html
title: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
---
