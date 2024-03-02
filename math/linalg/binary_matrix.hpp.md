---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/matrix_product_mod_2.test.cpp
    title: test/yosupo/matrix_product_mod_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Matrix
    links: []
  bundledCode: "#line 2 \"math/linalg/binary_matrix.hpp\"\n#include <bitset>\n#include\
    \ <cassert>\n#include <vector>\n\n/**\n * @brief Binary Matrix\n */\ntemplate\
    \ <int SZ>\nclass BinaryMatrix {\n    using Mat = BinaryMatrix;\n    using Vec\
    \ = std::bitset<SZ>;\n\n   public:\n    BinaryMatrix() = default;\n    BinaryMatrix(int\
    \ m, int n) : mat(m), m(m), n(n) {}\n\n    void set(int i, int j) { mat[i].set(j);\
    \ }\n\n    bool get(int i, int j) { return mat[i].test(j); }\n\n    Mat matmul(const\
    \ Mat& B) const {\n        Mat res(m, B.n);\n        for (int i = 0; i < m; ++i)\
    \ {\n            for (int k = 0; k < n; ++k) {\n                if (mat[i][k])\
    \ res.mat[i] ^= B.mat[k];\n            }\n        }\n        return res;\n   \
    \ }\n\n    Mat pow(long long k) const {\n        assert(m == n);\n        Mat\
    \ ret(n, n), A(*this);\n        for (int i = 0; i < n; ++i) {\n            ret.mat[i].set(i);\n\
    \            ret.matt[i].set(i);\n        }\n        while (k > 0) {\n       \
    \     if (k & 1) ret = ret.matmul(A);\n            A = A.matmul(A);\n        \
    \    k >>= 1;\n        }\n        return ret;\n    }\n\n   protected:\n    std::vector<Vec>\
    \ mat;\n    int m, n;\n};\n"
  code: "#pragma once\n#include <bitset>\n#include <cassert>\n#include <vector>\n\n\
    /**\n * @brief Binary Matrix\n */\ntemplate <int SZ>\nclass BinaryMatrix {\n \
    \   using Mat = BinaryMatrix;\n    using Vec = std::bitset<SZ>;\n\n   public:\n\
    \    BinaryMatrix() = default;\n    BinaryMatrix(int m, int n) : mat(m), m(m),\
    \ n(n) {}\n\n    void set(int i, int j) { mat[i].set(j); }\n\n    bool get(int\
    \ i, int j) { return mat[i].test(j); }\n\n    Mat matmul(const Mat& B) const {\n\
    \        Mat res(m, B.n);\n        for (int i = 0; i < m; ++i) {\n           \
    \ for (int k = 0; k < n; ++k) {\n                if (mat[i][k]) res.mat[i] ^=\
    \ B.mat[k];\n            }\n        }\n        return res;\n    }\n\n    Mat pow(long\
    \ long k) const {\n        assert(m == n);\n        Mat ret(n, n), A(*this);\n\
    \        for (int i = 0; i < n; ++i) {\n            ret.mat[i].set(i);\n     \
    \       ret.matt[i].set(i);\n        }\n        while (k > 0) {\n            if\
    \ (k & 1) ret = ret.matmul(A);\n            A = A.matmul(A);\n            k >>=\
    \ 1;\n        }\n        return ret;\n    }\n\n   protected:\n    std::vector<Vec>\
    \ mat;\n    int m, n;\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/linalg/binary_matrix.hpp
  requiredBy: []
  timestamp: '2024-03-02 18:46:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/matrix_product_mod_2.test.cpp
documentation_of: math/linalg/binary_matrix.hpp
layout: document
redirect_from:
- /library/math/linalg/binary_matrix.hpp
- /library/math/linalg/binary_matrix.hpp.html
title: Binary Matrix
---
