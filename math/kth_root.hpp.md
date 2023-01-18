---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/kth_root_integer.test.cpp
    title: test/yosupo/kth_root_integer.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/kth_root.hpp\"\n#include <cassert>\n#include <cmath>\n\
    \nunsigned long long kth_root(unsigned long long x, int k) {\n    using ull =\
    \ unsigned long long;\n    assert(k >= 1);\n    if (x <= 1 || k == 1) return x;\n\
    \    auto check = [&](ull a) {\n        ull y = x;\n        int e = k;\n     \
    \   while (e) {\n            if (e & 1) {\n                if (a == 0) return\
    \ false;\n                y /= a;\n            }\n            if (a > 0 && a >\
    \ y / a)\n                a = 0;\n            else\n                a *= a;\n\
    \            e >>= 1;\n        }\n        return y > 0;\n    };\n    ull res =\
    \ std::pow(x, std::nextafter(1.0 / k, 0.0));\n    while (check(res + 1)) ++res;\n\
    \    return res;\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n\nunsigned long long\
    \ kth_root(unsigned long long x, int k) {\n    using ull = unsigned long long;\n\
    \    assert(k >= 1);\n    if (x <= 1 || k == 1) return x;\n    auto check = [&](ull\
    \ a) {\n        ull y = x;\n        int e = k;\n        while (e) {\n        \
    \    if (e & 1) {\n                if (a == 0) return false;\n               \
    \ y /= a;\n            }\n            if (a > 0 && a > y / a)\n              \
    \  a = 0;\n            else\n                a *= a;\n            e >>= 1;\n \
    \       }\n        return y > 0;\n    };\n    ull res = std::pow(x, std::nextafter(1.0\
    \ / k, 0.0));\n    while (check(res + 1)) ++res;\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/kth_root.hpp
  requiredBy: []
  timestamp: '2023-01-18 15:33:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/kth_root_integer.test.cpp
documentation_of: math/kth_root.hpp
layout: document
redirect_from:
- /library/math/kth_root.hpp
- /library/math/kth_root.hpp.html
title: math/kth_root.hpp
---
