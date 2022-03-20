---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/cartesian_tree.test.cpp
    title: test/yosupo/cartesian_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/cartesian_tree.cpp\"\n#include <stack>\n#include <vector>\n\
    \ntemplate <typename T>\nstd::vector<int> cartesian_tree(const std::vector<T>&\
    \ a) {\n    int n = a.size();\n    std::vector<int> par(n, -1);\n    std::stack<int>\
    \ st;\n    for (int i = 0; i < n; ++i) {\n        int j = -1;\n        while (!st.empty()\
    \ && a[st.top()] >= a[i]) {\n            j = st.top();\n            st.pop();\n\
    \        }\n        if (!st.empty()) {\n            par[i] = st.top();\n     \
    \   }\n        if (j != -1) {\n            par[j] = i;\n        }\n        st.push(i);\n\
    \    }\n    return par;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\n\ntemplate <typename T>\n\
    std::vector<int> cartesian_tree(const std::vector<T>& a) {\n    int n = a.size();\n\
    \    std::vector<int> par(n, -1);\n    std::stack<int> st;\n    for (int i = 0;\
    \ i < n; ++i) {\n        int j = -1;\n        while (!st.empty() && a[st.top()]\
    \ >= a[i]) {\n            j = st.top();\n            st.pop();\n        }\n  \
    \      if (!st.empty()) {\n            par[i] = st.top();\n        }\n       \
    \ if (j != -1) {\n            par[j] = i;\n        }\n        st.push(i);\n  \
    \  }\n    return par;\n}"
  dependsOn: []
  isVerificationFile: false
  path: tree/cartesian_tree.cpp
  requiredBy: []
  timestamp: '2022-03-20 18:18:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/cartesian_tree.test.cpp
documentation_of: tree/cartesian_tree.cpp
layout: document
title: Cartesian Tree
---

## Description

Cartesian tree は，数列から定まる二分木で，以下の条件を満たすものである．
- 各頂点の重みは，そのどの子の重みよりも小さい
- 木の in-order traversal がもとの数列と一致する

## Operations

- `vector<int> cartesian_tree(vector<int> a)`
    - 数列 $a$ から定まる Cartesian tree を返す．それぞれの頂点の親のラベルを返す．根の親は `-1` とする．
    - 時間計算量: $O(n)$

## Reference

- [列を最小値で分割して再帰するパターンと Cartesian tree](https://kmyk.github.io/blog/blog/2020/07/27/recursion-on-cartesian-tree/)