---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: convolution/walsh_hadamard_transform.hpp
    title: Fast Walsh-Hadamard Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Bitwise XOR Convolution
    links: []
  bundledCode: "#line 2 \"convolution/xor_convolution.hpp\"\n#include <bit>\n#include\
    \ <vector>\n\n#line 3 \"convolution/walsh_hadamard_transform.hpp\"\n#include <cassert>\n\
    #line 5 \"convolution/walsh_hadamard_transform.hpp\"\n\ntemplate <typename T>\n\
    void fwht(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n \
    \   const int n = a.size();\n    for (int h = 1; h < n; h <<= 1) {\n        for\
    \ (int i = 0; i < n; i += h << 1) {\n            for (int j = i; j < i + h; ++j)\
    \ {\n                T x = a[j], y = a[j | h];\n                a[j] = x + y;\n\
    \                a[j | h] = x - y;\n            }\n        }\n    }\n}\n\ntemplate\
    \ <typename T>\nvoid ifwht(std::vector<T>& a) {\n    assert(std::has_single_bit(a.size()));\n\
    \    const int n = a.size();\n    const T inv2 = T(1) / 2;\n    for (int h = 1;\
    \ h < n; h <<= 1) {\n        for (int i = 0; i < n; i += h << 1) {\n         \
    \   for (int j = i; j < i + h; ++j) {\n                T x = a[j], y = a[j | h];\n\
    \                a[j] = (x + y) * inv2;\n                a[j | h] = (x - y) *\
    \ inv2;\n            }\n        }\n    }\n}\n#line 6 \"convolution/xor_convolution.hpp\"\
    \n\n/**\n * @brief Bitwise XOR Convolution\n */\n\ntemplate <typename T>\nstd::vector<T>\
    \ xor_convolution(std::vector<T> a, std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(),\
    \ b.size()));\n    a.resize(n);\n    b.resize(n);\n    fwht(a);\n    fwht(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    ifwht(a);\n    return a;\n\
    }\n"
  code: "#pragma once\n#include <bit>\n#include <vector>\n\n#include \"walsh_hadamard_transform.hpp\"\
    \n\n/**\n * @brief Bitwise XOR Convolution\n */\n\ntemplate <typename T>\nstd::vector<T>\
    \ xor_convolution(std::vector<T> a, std::vector<T> b) {\n    const int n = std::bit_ceil(std::max(a.size(),\
    \ b.size()));\n    a.resize(n);\n    b.resize(n);\n    fwht(a);\n    fwht(b);\n\
    \    for (int i = 0; i < n; ++i) a[i] *= b[i];\n    ifwht(a);\n    return a;\n\
    }"
  dependsOn:
  - convolution/walsh_hadamard_transform.hpp
  isVerificationFile: false
  path: convolution/xor_convolution.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bitwise_xor_convolution.test.cpp
documentation_of: convolution/xor_convolution.hpp
layout: document
redirect_from:
- /library/convolution/xor_convolution.hpp
- /library/convolution/xor_convolution.hpp.html
title: Bitwise XOR Convolution
---
