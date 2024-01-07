---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Boolean Square Matrix
    links: []
  bundledCode: "#line 2 \"misc/boolean_square_matrix.hpp\"\n#include <array>\n#include\
    \ <bitset>\n\n/**\n * @brief Boolean Square Matrix\n */\ntemplate <int N>\nclass\
    \ BooleanSquareMatrix {\n    using BSMatrix = BooleanSquareMatrix;\n    using\
    \ Matrix = std::array<std::bitset<N>, N>;\n\n   public:\n    void set(int r, int\
    \ c) {\n        rmat[r].set(c);\n        cmat[c].set(r);\n    }\n\n    bool get(int\
    \ r, int c) { return rmat[r][c]; }\n\n    BSMatrix matmul(const BSMatrix& B) const\
    \ {\n        BSMatrix res;\n        for (int i = 0; i < N; ++i) {\n          \
    \  for (int j = 0; j < N; ++j) {\n                res.rmat[i][j] = res.cmat[j][i]\
    \ = (rmat[i] & B.cmat[j]).any();\n            }\n        }\n        return res;\n\
    \    }\n\n    BSMatrix pow(long long k) const {\n        BSMatrix ret, A(*this);\n\
    \        for (int i = 0; i < N; ++i) {\n            ret.rmat[i].set(i);\n    \
    \        ret.cmat[i].set(i);\n        }\n        while (k > 0) {\n           \
    \ if (k & 1) ret = ret.matmul(A);\n            A = A.matmul(A);\n            k\
    \ >>= 1;\n        }\n        return ret;\n    }\n\n   private:\n    Matrix rmat,\
    \ cmat;\n};\n"
  code: "#pragma once\n#include <array>\n#include <bitset>\n\n/**\n * @brief Boolean\
    \ Square Matrix\n */\ntemplate <int N>\nclass BooleanSquareMatrix {\n    using\
    \ BSMatrix = BooleanSquareMatrix;\n    using Matrix = std::array<std::bitset<N>,\
    \ N>;\n\n   public:\n    void set(int r, int c) {\n        rmat[r].set(c);\n \
    \       cmat[c].set(r);\n    }\n\n    bool get(int r, int c) { return rmat[r][c];\
    \ }\n\n    BSMatrix matmul(const BSMatrix& B) const {\n        BSMatrix res;\n\
    \        for (int i = 0; i < N; ++i) {\n            for (int j = 0; j < N; ++j)\
    \ {\n                res.rmat[i][j] = res.cmat[j][i] = (rmat[i] & B.cmat[j]).any();\n\
    \            }\n        }\n        return res;\n    }\n\n    BSMatrix pow(long\
    \ long k) const {\n        BSMatrix ret, A(*this);\n        for (int i = 0; i\
    \ < N; ++i) {\n            ret.rmat[i].set(i);\n            ret.cmat[i].set(i);\n\
    \        }\n        while (k > 0) {\n            if (k & 1) ret = ret.matmul(A);\n\
    \            A = A.matmul(A);\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n   private:\n    Matrix rmat, cmat;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/boolean_square_matrix.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/boolean_square_matrix.hpp
layout: document
redirect_from:
- /library/misc/boolean_square_matrix.hpp
- /library/misc/boolean_square_matrix.hpp.html
title: Boolean Square Matrix
---
