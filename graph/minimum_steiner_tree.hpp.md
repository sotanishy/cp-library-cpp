---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1040.test.cpp
    title: test/aoj/1040.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/minimum_steiner_tree.hpp\"\n#include <algorithm>\n\
    #include <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n#line\
    \ 2 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from,\
    \ to;\n    T weight;\n    Edge() = default;\n    Edge(int to, T weight) : from(-1),\
    \ to(to), weight(weight) {}\n    Edge(int from, int to, T weight) : from(from),\
    \ to(to), weight(weight) {}\n};\n#line 8 \"graph/minimum_steiner_tree.hpp\"\n\n\
    template <typename T>\nT minimum_steiner_tree(std::vector<std::vector<Edge<T>>>&\
    \ G, std::vector<int>& terminals) {\n    const int n = G.size();\n    const int\
    \ t = terminals.size();\n    constexpr T INF = std::numeric_limits<T>::max() /\
    \ 2;\n    using P = std::pair<T, int>;\n\n    std::vector<std::vector<T>> dp(1\
    \ << t, std::vector<T>(n, INF));\n    for (int i = 0; i < t; ++i) dp[1 << i][terminals[i]]\
    \ = 0;\n\n    for (int S = 1; S < (1 << t); ++S) {\n        for (int i = 0; i\
    \ < n; ++i) {\n            for (int U = S; U > 0; U = (U - 1) & S) {\n       \
    \         dp[S][i] = std::min(dp[S][i], dp[S ^ U][i] + dp[U][i]);\n          \
    \  }\n        }\n        if (S == (1 << t) - 1) continue;\n        std::priority_queue<P,\
    \ std::vector<P>, std::greater<>> pq;\n        for (int i = 0; i < n; ++i) {\n\
    \            pq.emplace(dp[S][i], i);\n        }\n        while (!pq.empty())\
    \ {\n            auto [d, v] = pq.top();\n            pq.pop();\n            if\
    \ (dp[S][v] < d) continue;\n            for (auto& e : G[v]) {\n             \
    \   if (dp[S][e.to] > d + e.weight) {\n                    dp[S][e.to] = d + e.weight;\n\
    \                    pq.emplace(dp[S][e.to], e.to);\n                }\n     \
    \       }\n        }\n    }\n\n    return dp.back()[terminals[0]];\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n#include \"edge.cpp\"\n\ntemplate <typename\
    \ T>\nT minimum_steiner_tree(std::vector<std::vector<Edge<T>>>& G, std::vector<int>&\
    \ terminals) {\n    const int n = G.size();\n    const int t = terminals.size();\n\
    \    constexpr T INF = std::numeric_limits<T>::max() / 2;\n    using P = std::pair<T,\
    \ int>;\n\n    std::vector<std::vector<T>> dp(1 << t, std::vector<T>(n, INF));\n\
    \    for (int i = 0; i < t; ++i) dp[1 << i][terminals[i]] = 0;\n\n    for (int\
    \ S = 1; S < (1 << t); ++S) {\n        for (int i = 0; i < n; ++i) {\n       \
    \     for (int U = S; U > 0; U = (U - 1) & S) {\n                dp[S][i] = std::min(dp[S][i],\
    \ dp[S ^ U][i] + dp[U][i]);\n            }\n        }\n        if (S == (1 <<\
    \ t) - 1) continue;\n        std::priority_queue<P, std::vector<P>, std::greater<>>\
    \ pq;\n        for (int i = 0; i < n; ++i) {\n            pq.emplace(dp[S][i],\
    \ i);\n        }\n        while (!pq.empty()) {\n            auto [d, v] = pq.top();\n\
    \            pq.pop();\n            if (dp[S][v] < d) continue;\n            for\
    \ (auto& e : G[v]) {\n                if (dp[S][e.to] > d + e.weight) {\n    \
    \                dp[S][e.to] = d + e.weight;\n                    pq.emplace(dp[S][e.to],\
    \ e.to);\n                }\n            }\n        }\n    }\n\n    return dp.back()[terminals[0]];\n\
    }\n"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: graph/minimum_steiner_tree.hpp
  requiredBy: []
  timestamp: '2022-06-27 14:23:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1040.test.cpp
documentation_of: graph/minimum_steiner_tree.hpp
layout: document
title: Minimum Steiner Tree
---

## Description

最小 Steiner 木は，グラフ $G$ の頂点集合 $S \subset V$ を含む最小の木である．

最小 Steiner 木問題は NP 困難である．Dreyfus-Wagner のアルゴリズムを用いて $\vert S\vert$ に関する指数時間で解ける．

## Operations

- `T minimum_steiner_tree(vector<vector<Edge<T>>> G, vector<int> terminals)`
    - $G$ の `terminals` を含む最小 Steiner 木の重みを求める
    - 時間計算量: $O(n3^{k} + (n+m)2^k \log n)\,\text{where}\,k = \vert S\vert$

## Reference

- [Steiner Tree - My Algirithm](https://kopricky.github.io/code/Academic/steiner_tree.html)
- [指数時間アルゴリズム入門 - slideshare](https://www.slideshare.net/wata_orz/ss-12131479)