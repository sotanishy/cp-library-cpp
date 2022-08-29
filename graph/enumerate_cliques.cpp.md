---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2306.test.cpp
    title: test/aoj/2306.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_cliques.test.cpp
    title: test/yosupo/enumerate_cliques.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/enumerate_cliques.cpp\"\n#include <cmath>\n#include\
    \ <vector>\n\nstd::vector<std::vector<int>> enumerate_cliques(const std::vector<std::vector<bool>>&\
    \ G) {\n    int N = G.size(), M = 0;\n    std::vector<int> deg(N);\n    for (int\
    \ i = 0; i < N; ++i) {\n        for (int j = 0; j < N; ++j) {\n            if\
    \ (G[i][j]) {\n                ++deg[i];\n                ++M;\n            }\n\
    \        }\n    }\n    M /= 2;\n    int B = std::sqrt(2*M);\n    std::vector<std::vector<int>>\
    \ cliques;\n\n    auto check = [&](const std::vector<int>& vs, bool use_first)\
    \ {\n        int n = vs.size();\n        for (int S = 1; S < 1 << n; ++S) {\n\
    \            if (use_first && !(S & 1)) continue;\n            bool ok = true;\n\
    \            for (int i = 0; i < n - 1; ++i) {\n                if (!(S >> i &\
    \ 1)) continue;\n                for (int j = i + 1; j < n; ++j) {\n         \
    \           if ((S >> j & 1) && !G[vs[i]][vs[j]]) {\n                        ok\
    \ = false;\n                        break;\n                    }\n          \
    \      }\n                if (!ok) break;\n            }\n            if (ok)\
    \ {\n                cliques.emplace_back();\n                for (int i = 0;\
    \ i < n; ++i) {\n                    if (S >> i & 1) {\n                     \
    \   cliques.back().push_back(vs[i]);\n                    }\n                }\n\
    \            }\n        }\n    };\n\n    std::vector<bool> checked(N);\n    std::vector<int>\
    \ big;\n    for (int i = 0; i < N; ++i) {\n        if (deg[i] >= B) {\n      \
    \      big.push_back(i);\n            continue;\n        }\n        std::vector<int>\
    \ vs;\n        vs.push_back(i);\n        for (int j = 0; j < N; ++j) {\n     \
    \       if (G[i][j] && !checked[j]) {\n                vs.push_back(j);\n    \
    \        }\n        }\n        check(vs, true);\n        checked[i] = true;\n\
    \    }\n    check(big, false);\n    return cliques;\n}\n"
  code: "#pragma once\n#include <cmath>\n#include <vector>\n\nstd::vector<std::vector<int>>\
    \ enumerate_cliques(const std::vector<std::vector<bool>>& G) {\n    int N = G.size(),\
    \ M = 0;\n    std::vector<int> deg(N);\n    for (int i = 0; i < N; ++i) {\n  \
    \      for (int j = 0; j < N; ++j) {\n            if (G[i][j]) {\n           \
    \     ++deg[i];\n                ++M;\n            }\n        }\n    }\n    M\
    \ /= 2;\n    int B = std::sqrt(2*M);\n    std::vector<std::vector<int>> cliques;\n\
    \n    auto check = [&](const std::vector<int>& vs, bool use_first) {\n       \
    \ int n = vs.size();\n        for (int S = 1; S < 1 << n; ++S) {\n           \
    \ if (use_first && !(S & 1)) continue;\n            bool ok = true;\n        \
    \    for (int i = 0; i < n - 1; ++i) {\n                if (!(S >> i & 1)) continue;\n\
    \                for (int j = i + 1; j < n; ++j) {\n                    if ((S\
    \ >> j & 1) && !G[vs[i]][vs[j]]) {\n                        ok = false;\n    \
    \                    break;\n                    }\n                }\n      \
    \          if (!ok) break;\n            }\n            if (ok) {\n           \
    \     cliques.emplace_back();\n                for (int i = 0; i < n; ++i) {\n\
    \                    if (S >> i & 1) {\n                        cliques.back().push_back(vs[i]);\n\
    \                    }\n                }\n            }\n        }\n    };\n\n\
    \    std::vector<bool> checked(N);\n    std::vector<int> big;\n    for (int i\
    \ = 0; i < N; ++i) {\n        if (deg[i] >= B) {\n            big.push_back(i);\n\
    \            continue;\n        }\n        std::vector<int> vs;\n        vs.push_back(i);\n\
    \        for (int j = 0; j < N; ++j) {\n            if (G[i][j] && !checked[j])\
    \ {\n                vs.push_back(j);\n            }\n        }\n        check(vs,\
    \ true);\n        checked[i] = true;\n    }\n    check(big, false);\n    return\
    \ cliques;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/enumerate_cliques.cpp
  requiredBy: []
  timestamp: '2021-10-23 12:21:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_cliques.test.cpp
  - test/aoj/2306.test.cpp
documentation_of: graph/enumerate_cliques.cpp
layout: document
title: Clique Enumeration
---

## Description

クリークを全列挙する．

クリークの個数は高々 $2^{\sqrt{2E}}$ 個である．

## Operations

- `vector<vector<int>> enumerate_cliques(vector<vector<bool>> G)`
    - グラフ $G$ の隣接行列が与えられたとき， $G$ のクリークを全列挙する．
    - 時間計算量: $O(2^{\sqrt{2E}} V)$


## Reference

- [指数時間アルゴリズム入門](https://www.slideshare.net/wata_orz/ss-12131479)