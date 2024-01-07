---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Bitwise XOR Convolution
    links: []
  bundledCode: "#line 2 \"set/xor_convolution.hpp\"\n#include <bit>\n#include <vector>\n\
    \n/**\n * @brief Bitwise XOR Convolution\n */\n\ntemplate <typename T>\nstd::vector<T>\
    \ xor_convolution(std::vector<T> a, std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(),\
    \ b.size()));\n    a.resize(n);\n    b.resize(n);\n    fwht(a);\n    fwht(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    ifwht(a);\n    return a;\n\
    }\n"
  code: "#pragma once\n#include <bit>\n#include <vector>\n\n/**\n * @brief Bitwise\
    \ XOR Convolution\n */\n\ntemplate <typename T>\nstd::vector<T> xor_convolution(std::vector<T>\
    \ a, std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(), b.size()));\n\
    \    a.resize(n);\n    b.resize(n);\n    fwht(a);\n    fwht(b);\n    for (int\
    \ i = 0; i < n; ++i) a[i] *= b[i];\n    ifwht(a);\n    return a;\n}"
  dependsOn: []
  isVerificationFile: false
  path: set/xor_convolution.hpp
  requiredBy: []
  timestamp: '2024-01-07 12:10:37+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/bitwise_xor_convolution.test.cpp
documentation_of: set/xor_convolution.hpp
layout: document
redirect_from:
- /library/set/xor_convolution.hpp
- /library/set/xor_convolution.hpp.html
title: Bitwise XOR Convolution
---
