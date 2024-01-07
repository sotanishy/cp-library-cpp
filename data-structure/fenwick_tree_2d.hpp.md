---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: 2D Fenwick Tree
    links: []
  bundledCode: "#line 2 \"data-structure/fenwick_tree_2d.hpp\"\n#include <vector>\n\
    \n/**\n * @brief 2D Fenwick Tree\n */\ntemplate <typename T>\nclass FenwickTree2D\
    \ {\n   public:\n    FenwickTree2D() = default;\n    FenwickTree2D(int H, int\
    \ W)\n        : H(H), W(W), data(H + 1, std::vector<T>(W + 1)) {}\n\n    void\
    \ add(int a, int b, T x) {\n        ++a;\n        ++b;\n        for (int i = a;\
    \ i <= H; i += i & -i) {\n            for (int j = b; j <= W; j += j & -j) {\n\
    \                data[i][j] += x;\n            }\n        }\n    }\n\n    T sum(int\
    \ a, int b) const {\n        ++a;\n        ++b;\n        T ret = 0;\n        for\
    \ (int i = a; i > 0; i -= i & -i) {\n            for (int j = b; j > 0; j -= j\
    \ & -j) {\n                ret += data[i][j];\n            }\n        }\n    \
    \    return ret;\n    }\n\n   private:\n    int H, W;\n    std::vector<std::vector<T>>\
    \ data;\n};\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief 2D Fenwick Tree\n */\n\
    template <typename T>\nclass FenwickTree2D {\n   public:\n    FenwickTree2D()\
    \ = default;\n    FenwickTree2D(int H, int W)\n        : H(H), W(W), data(H +\
    \ 1, std::vector<T>(W + 1)) {}\n\n    void add(int a, int b, T x) {\n        ++a;\n\
    \        ++b;\n        for (int i = a; i <= H; i += i & -i) {\n            for\
    \ (int j = b; j <= W; j += j & -j) {\n                data[i][j] += x;\n     \
    \       }\n        }\n    }\n\n    T sum(int a, int b) const {\n        ++a;\n\
    \        ++b;\n        T ret = 0;\n        for (int i = a; i > 0; i -= i & -i)\
    \ {\n            for (int j = b; j > 0; j -= j & -j) {\n                ret +=\
    \ data[i][j];\n            }\n        }\n        return ret;\n    }\n\n   private:\n\
    \    int H, W;\n    std::vector<std::vector<T>> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick_tree_2d.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/fenwick_tree_2d.hpp
layout: document
redirect_from:
- /library/data-structure/fenwick_tree_2d.hpp
- /library/data-structure/fenwick_tree_2d.hpp.html
title: 2D Fenwick Tree
---
