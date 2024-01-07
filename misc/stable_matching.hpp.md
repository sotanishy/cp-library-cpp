---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/stable_matching.hpp\"\n#include <stack>\n#include <vector>\n\
    \nstd::vector<int> stable_matching(const std::vector<std::vector<int>>& man,\n\
    \                                 const std::vector<std::vector<int>>& woman)\
    \ {\n    const int n = man.size();\n    // the smaller the better\n    std::vector\
    \ preference(n, std::vector<int>(n));\n    for (int j = 0; j < n; ++j) {\n   \
    \     for (int k = 0; k < n; ++k) {\n            preference[j][woman[j][k]] =\
    \ k;\n        }\n    }\n    std::vector<int> idx(n);\n    std::vector<int> engaged(n,\
    \ -1);\n    std::stack<int> st;\n    for (int i = 0; i < n; ++i) st.push(i);\n\
    \    while (!st.empty()) {\n        int i = st.top(), j = man[i][idx[i]++];\n\
    \        if (engaged[j] == -1 || preference[j][i] < preference[j][engaged[j]])\
    \ {\n            st.pop();\n            if (engaged[j] != -1) st.push(engaged[j]);\n\
    \            engaged[j] = i;\n        }\n    }\n    return engaged;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\n\nstd::vector<int> stable_matching(const\
    \ std::vector<std::vector<int>>& man,\n                                 const\
    \ std::vector<std::vector<int>>& woman) {\n    const int n = man.size();\n   \
    \ // the smaller the better\n    std::vector preference(n, std::vector<int>(n));\n\
    \    for (int j = 0; j < n; ++j) {\n        for (int k = 0; k < n; ++k) {\n  \
    \          preference[j][woman[j][k]] = k;\n        }\n    }\n    std::vector<int>\
    \ idx(n);\n    std::vector<int> engaged(n, -1);\n    std::stack<int> st;\n   \
    \ for (int i = 0; i < n; ++i) st.push(i);\n    while (!st.empty()) {\n       \
    \ int i = st.top(), j = man[i][idx[i]++];\n        if (engaged[j] == -1 || preference[j][i]\
    \ < preference[j][engaged[j]]) {\n            st.pop();\n            if (engaged[j]\
    \ != -1) st.push(engaged[j]);\n            engaged[j] = i;\n        }\n    }\n\
    \    return engaged;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/stable_matching.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/stable_matching.hpp
layout: document
title: Stable Matching
---

## Description

(男性最適) 安定マッチングを返す．

$n$ 人の男性と $n$ 人の女性がいる状況を考える．各人は異性に対して選好順序を持っている．このとき，安定マッチングとは，$n$ 組の男女のマッチングであって，互いに現在組んでいる相手よりもお互いのことが好きであるような男女のペア (ブロッキングペア) が存在しないようなものである．

どの男性も安定マッチングでペアになれる女性のうち，もっとも好きな女性とペアになっているような安定マッチングを男性最適安定マッチングと言う．男性最適安定マッチングは Gale-Shapley アルゴリズムによって $O(n^2)$ 時間で求めることができる．

## Operations

- `vector<int> stable_matching(vector<vector<int>> man, vector<vector<int>> woman)`
    - 男性と女性の各人の選好順序が与えられたとき，(男性最適) 安定マッチングの1つにおいて，各女性と婚約している男性を返す．
    - 時間計算量: $O(n^2)$


## Reference

- [Stable marriage problem - Wikipedia](https://en.wikipedia.org/wiki/Stable_marriage_problem)
- [Gale-Shapley algorithm - Wikipedia](https://en.wikipedia.org/wiki/Gale%E2%80%93Shapley_algorithm)
