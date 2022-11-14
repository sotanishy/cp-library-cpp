---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/assignment.test.cpp
    title: test/yosupo/assignment.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/assignment.hpp\"\n#include <algorithm>\n#include <queue>\n\
    #include <limits>\n#include <vector>\n\n\ntemplate <typename T>\nstd::vector<int>\
    \ assignment(const std::vector<std::vector<T>>& cost) {\n    constexpr T INF =\
    \ std::numeric_limits<T>::max();\n    const int n = cost.size(), m = cost[0].size();\n\
    \    std::vector<T> yrow(n), ycol(m);\n    std::vector<int> materow(n, -1), matecol(m,\
    \ -1), par(m, -1);\n    std::vector<bool> usedrow(n), usedcol(m);\n    std::vector<T>\
    \ slack(m), slack_idx(m, -1);\n\n    for (int i = 0; i < n; ++i) {\n        yrow[i]\
    \ = *std::max_element(cost[i].begin(), cost[i].end());\n    }\n\n    // add the\
    \ edge (j, i) to the alternating tree\n    auto add_to_tree = [&](int i) {\n \
    \       usedrow[i] = true;\n        for (int j = 0; j < m; ++j) {\n          \
    \  T s = yrow[i] + ycol[j] - cost[i][j];\n            if (s < slack[j]) {\n  \
    \              slack[j] = s;\n                slack_idx[j] = i;\n            }\n\
    \        }\n    };\n\n    auto augment = [&](int i, int j) {\n        while (true)\
    \ {\n            int k = materow[i];\n            matecol[j] = i;\n          \
    \  materow[i] = j;\n\n            if (k == -1) break;\n            j = k;\n  \
    \          i = par[j];\n        }\n    };\n\n    for (int t = 0; t < n; ++t) {\n\
    \        std::fill(usedrow.begin(), usedrow.end(), false);\n        std::fill(usedcol.begin(),\
    \ usedcol.end(), false);\n        std::fill(par.begin(), par.end(), -1);\n   \
    \     std::queue<int> que;\n        // seed\n        for (int i = 0; i < n; ++i)\
    \ {\n            if (materow[i] == -1) {\n                que.push(i);\n     \
    \           usedrow[i] = true;\n                for (int j = 0; j < m; ++j) {\n\
    \                    slack[j] = yrow[i] + ycol[j] - cost[i][j];\n            \
    \        slack_idx[j] = i;\n                }\n                break;\n      \
    \      }\n        }\n\n        // repeat until an augmenting path is found\n \
    \       bool aug = false;\n        while (!aug) {\n            while (!aug &&\
    \ !que.empty()) {\n                int i = que.front();\n                que.pop();\n\
    \                for (int j = 0; j < m; ++j) {\n                    if (cost[i][j]\
    \ == yrow[i] + ycol[j] && !usedcol[j]) {\n                        if (matecol[j]\
    \ == -1) {\n                            // augment\n                         \
    \   augment(i, j);\n                            aug = true;\n                \
    \            break;\n                        }\n                        // grow\n\
    \                        usedcol[j] = true;\n                        par[j] =\
    \ i;\n                        add_to_tree(matecol[j]);\n                     \
    \   que.push(matecol[j]);\n                    }\n                }\n        \
    \    }\n            if (aug) break;\n\n            // update y\n            T\
    \ delta = INF;\n            for (int j = 0; j < m; ++j) {\n                if\
    \ (!usedcol[j]) delta = std::min(delta, slack[j]);\n            }\n          \
    \  for (int i = 0; i < n; ++i) {\n                if (usedrow[i]) yrow[i] -= delta;\n\
    \            }\n            for (int j = 0; j < m; ++j) {\n                if\
    \ (usedcol[j]) ycol[j] += delta;\n                else slack[j] -= delta;\n  \
    \          }\n            // add new edges of the equality graph to the alternating\
    \ tree\n            for (int j = 0; j < m; ++j) {\n                if (!usedcol[j]\
    \ && slack[j] == 0) {\n                    if (matecol[j] == -1) {\n         \
    \               augment(slack_idx[j], j);\n                        aug = true;\n\
    \                        break;\n                    } else {\n              \
    \          usedcol[j] = true;\n                        par[j] = slack_idx[j];\n\
    \                        add_to_tree(matecol[j]);\n                        que.push(matecol[j]);\n\
    \                    }\n                }\n            }\n        }\n    }\n \
    \   return materow;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <queue>\n#include <limits>\n\
    #include <vector>\n\n\ntemplate <typename T>\nstd::vector<int> assignment(const\
    \ std::vector<std::vector<T>>& cost) {\n    constexpr T INF = std::numeric_limits<T>::max();\n\
    \    const int n = cost.size(), m = cost[0].size();\n    std::vector<T> yrow(n),\
    \ ycol(m);\n    std::vector<int> materow(n, -1), matecol(m, -1), par(m, -1);\n\
    \    std::vector<bool> usedrow(n), usedcol(m);\n    std::vector<T> slack(m), slack_idx(m,\
    \ -1);\n\n    for (int i = 0; i < n; ++i) {\n        yrow[i] = *std::max_element(cost[i].begin(),\
    \ cost[i].end());\n    }\n\n    // add the edge (j, i) to the alternating tree\n\
    \    auto add_to_tree = [&](int i) {\n        usedrow[i] = true;\n        for\
    \ (int j = 0; j < m; ++j) {\n            T s = yrow[i] + ycol[j] - cost[i][j];\n\
    \            if (s < slack[j]) {\n                slack[j] = s;\n            \
    \    slack_idx[j] = i;\n            }\n        }\n    };\n\n    auto augment =\
    \ [&](int i, int j) {\n        while (true) {\n            int k = materow[i];\n\
    \            matecol[j] = i;\n            materow[i] = j;\n\n            if (k\
    \ == -1) break;\n            j = k;\n            i = par[j];\n        }\n    };\n\
    \n    for (int t = 0; t < n; ++t) {\n        std::fill(usedrow.begin(), usedrow.end(),\
    \ false);\n        std::fill(usedcol.begin(), usedcol.end(), false);\n       \
    \ std::fill(par.begin(), par.end(), -1);\n        std::queue<int> que;\n     \
    \   // seed\n        for (int i = 0; i < n; ++i) {\n            if (materow[i]\
    \ == -1) {\n                que.push(i);\n                usedrow[i] = true;\n\
    \                for (int j = 0; j < m; ++j) {\n                    slack[j] =\
    \ yrow[i] + ycol[j] - cost[i][j];\n                    slack_idx[j] = i;\n   \
    \             }\n                break;\n            }\n        }\n\n        //\
    \ repeat until an augmenting path is found\n        bool aug = false;\n      \
    \  while (!aug) {\n            while (!aug && !que.empty()) {\n              \
    \  int i = que.front();\n                que.pop();\n                for (int\
    \ j = 0; j < m; ++j) {\n                    if (cost[i][j] == yrow[i] + ycol[j]\
    \ && !usedcol[j]) {\n                        if (matecol[j] == -1) {\n       \
    \                     // augment\n                            augment(i, j);\n\
    \                            aug = true;\n                            break;\n\
    \                        }\n                        // grow\n                \
    \        usedcol[j] = true;\n                        par[j] = i;\n           \
    \             add_to_tree(matecol[j]);\n                        que.push(matecol[j]);\n\
    \                    }\n                }\n            }\n            if (aug)\
    \ break;\n\n            // update y\n            T delta = INF;\n            for\
    \ (int j = 0; j < m; ++j) {\n                if (!usedcol[j]) delta = std::min(delta,\
    \ slack[j]);\n            }\n            for (int i = 0; i < n; ++i) {\n     \
    \           if (usedrow[i]) yrow[i] -= delta;\n            }\n            for\
    \ (int j = 0; j < m; ++j) {\n                if (usedcol[j]) ycol[j] += delta;\n\
    \                else slack[j] -= delta;\n            }\n            // add new\
    \ edges of the equality graph to the alternating tree\n            for (int j\
    \ = 0; j < m; ++j) {\n                if (!usedcol[j] && slack[j] == 0) {\n  \
    \                  if (matecol[j] == -1) {\n                        augment(slack_idx[j],\
    \ j);\n                        aug = true;\n                        break;\n \
    \                   } else {\n                        usedcol[j] = true;\n   \
    \                     par[j] = slack_idx[j];\n                        add_to_tree(matecol[j]);\n\
    \                        que.push(matecol[j]);\n                    }\n      \
    \          }\n            }\n        }\n    }\n    return materow;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/assignment.hpp
  requiredBy: []
  timestamp: '2022-11-14 13:04:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/assignment.test.cpp
documentation_of: graph/assignment.hpp
layout: document
title: Assignment Problem (Maximum Weight Perfect Matching)
---

## Description

割当問題 (最大重み完全マッチング) を Hungarian 法で解く．

## Operations

- `vector<int> assignment(vector<vector<T>> a)`
    - $\sum_{i=1}^n a_{i,p_i}$ を最大化する $(p_i)_{i=1,\dots,n}$ を返す
    - 時間計算量: $O(n^3)$

## Reference

- Lee, Jon. *A First Course in Combinatorial Optimization*. Cambridge: Cambridge University Press, 2010
- [Assignment Problem and Hungarian Algorithm](https://www.topcoder.com/thrive/articles/Assignment%20Problem%20and%20Hungarian%20Algorithm)