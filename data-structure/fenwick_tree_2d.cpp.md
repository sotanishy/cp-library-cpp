---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    document_title: 2D Fenwick Tree
    links: []
  bundledCode: "#line 1 \"data-structure/fenwick_tree_2d.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief 2D Fenwick Tree\n */\ntemplate <typename T>\nclass FenwickTree2D\
    \ {\npublic:\n    FenwickTree2D(int H, int W) : H(H), W(W), data(H+1, std::vector<T>(W+1))\
    \ {}\n\n    void add(int a, int b, T x) {\n        a++;\n        b++;\n      \
    \  for (int i = a; i <= H; i += i & -i) {\n            for (int j = b; j <= W;\
    \ j += j & -j) {\n                data[i][j] += x;\n            }\n        }\n\
    \    }\n\n    T sum(int a, int b) const {\n        a++;\n        b++;\n      \
    \  T ret = 0;\n        for (int i = a; i > 0; i -= i & -i) {\n            for\
    \ (int j = b; j > 0; j -= j & -j) {\n                ret += data[i][j];\n    \
    \        }\n        }\n        return ret;\n    }\n\nprivate:\n    int H, W;\n\
    \    std::vector<std::vector<T>> data;\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief 2D Fenwick Tree\n */\ntemplate\
    \ <typename T>\nclass FenwickTree2D {\npublic:\n    FenwickTree2D(int H, int W)\
    \ : H(H), W(W), data(H+1, std::vector<T>(W+1)) {}\n\n    void add(int a, int b,\
    \ T x) {\n        a++;\n        b++;\n        for (int i = a; i <= H; i += i &\
    \ -i) {\n            for (int j = b; j <= W; j += j & -j) {\n                data[i][j]\
    \ += x;\n            }\n        }\n    }\n\n    T sum(int a, int b) const {\n\
    \        a++;\n        b++;\n        T ret = 0;\n        for (int i = a; i > 0;\
    \ i -= i & -i) {\n            for (int j = b; j > 0; j -= j & -j) {\n        \
    \        ret += data[i][j];\n            }\n        }\n        return ret;\n \
    \   }\n\nprivate:\n    int H, W;\n    std::vector<std::vector<T>> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick_tree_2d.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/fenwick_tree_2d.cpp
layout: document
redirect_from:
- /library/data-structure/fenwick_tree_2d.cpp
- /library/data-structure/fenwick_tree_2d.cpp.html
title: 2D Fenwick Tree
---
