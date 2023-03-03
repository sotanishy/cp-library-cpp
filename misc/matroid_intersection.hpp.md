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
  bundledCode: "#line 2 \"misc/matroid_intersection.hpp\"\n#include <algorithm>\n\
    #include <set>\n#include <queue>\n#include <vector>\n\n// given the ground set\
    \ E and oracles for M1 and M2\n// find the max cardinality set S that is in both\
    \ I(M1) and I(M2)\ntemplate <typename F1, typename F2>\nstd::set<int> matroid_intersection(int\
    \ E, F1 oracle1, F2 oracle2) {\n    std::set<int> S;\n    std::vector<bool> is_source(E),\
    \ is_sink(E);\n    std::vector<int> dist(E, -1), prv(E, -1);\n    std::queue<int>\
    \ que;\n    while (true) {\n        std::fill(is_source.begin(), is_source.end(),\
    \ false);\n        std::fill(is_sink.begin(), is_sink.end(), false);\n       \
    \ std::fill(dist.begin(), dist.end(), -1);\n        std::fill(prv.begin(), prv.end(),\
    \ -1);\n        while (!que.empty()) que.pop();\n\n        // check sink and source\n\
    \        bool upd = false;\n        for (int i = 0; i < E; ++i) {\n          \
    \  if (!S.count(i)) {\n                S.insert(i);\n                is_source[i]\
    \ = oracle1(S);\n                is_sink[i] = oracle2(S);\n                if\
    \ (is_source[i]) {\n                    if (is_sink[i]) {\n                  \
    \      // i is both a source and a sink, so i can be added to S\n            \
    \            upd = true;\n                        break;\n                   \
    \ }\n                    dist[i] = 0;\n                    que.push(i);\n    \
    \            }\n                S.erase(i);\n            }\n        }\n      \
    \  if (upd) continue;\n\n        // find the shortest path with BFS\n        while\
    \ (!que.empty()) {\n            int i = que.front();\n            que.pop();\n\
    \            if (is_sink[i]) {\n                // shortest source-sink path found,\
    \ update S\n                do {\n                    if (S.count(i)) {\n    \
    \                    S.erase(i);\n                    } else {\n             \
    \           S.insert(i);\n                    }\n                    i = prv[i];\n\
    \                } while (i != -1);\n                upd = true;\n           \
    \     break;\n            }\n            if (S.count(i)) {\n                //\
    \ i -> j\n                for (int j = 0; j < E; ++j) {\n                    if\
    \ (dist[j] == -1 && !is_source[j] && !S.count(j)) {\n                        S.erase(i);\n\
    \                        S.insert(j);\n                        if (oracle1(S))\
    \ {\n                            dist[j] = dist[i] + 1;\n                    \
    \        prv[j] = i;\n                            que.push(j);\n             \
    \           }\n                        S.insert(i);\n                        S.erase(j);\n\
    \                    }\n                }\n            } else {\n            \
    \    // j <- i\n                for (int j = 0; j < E; ++j) {\n              \
    \      if (dist[j] == -1 && S.count(j)) {\n                        S.erase(j);\n\
    \                        S.insert(i);\n                        if (oracle2(S))\
    \ {\n                            dist[j] = dist[i] + 1;\n                    \
    \        prv[j] = i;\n                            que.push(j);\n             \
    \           }\n                        S.insert(j);\n                        S.erase(i);\n\
    \                    }\n                }\n            }\n        }\n        if\
    \ (!upd) {\n            // no source-sink path found\n            break;\n   \
    \     }\n    }\n    return S;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <set>\n#include <queue>\n#include\
    \ <vector>\n\n// given the ground set E and oracles for M1 and M2\n// find the\
    \ max cardinality set S that is in both I(M1) and I(M2)\ntemplate <typename F1,\
    \ typename F2>\nstd::set<int> matroid_intersection(int E, F1 oracle1, F2 oracle2)\
    \ {\n    std::set<int> S;\n    std::vector<bool> is_source(E), is_sink(E);\n \
    \   std::vector<int> dist(E, -1), prv(E, -1);\n    std::queue<int> que;\n    while\
    \ (true) {\n        std::fill(is_source.begin(), is_source.end(), false);\n  \
    \      std::fill(is_sink.begin(), is_sink.end(), false);\n        std::fill(dist.begin(),\
    \ dist.end(), -1);\n        std::fill(prv.begin(), prv.end(), -1);\n        while\
    \ (!que.empty()) que.pop();\n\n        // check sink and source\n        bool\
    \ upd = false;\n        for (int i = 0; i < E; ++i) {\n            if (!S.count(i))\
    \ {\n                S.insert(i);\n                is_source[i] = oracle1(S);\n\
    \                is_sink[i] = oracle2(S);\n                if (is_source[i]) {\n\
    \                    if (is_sink[i]) {\n                        // i is both a\
    \ source and a sink, so i can be added to S\n                        upd = true;\n\
    \                        break;\n                    }\n                    dist[i]\
    \ = 0;\n                    que.push(i);\n                }\n                S.erase(i);\n\
    \            }\n        }\n        if (upd) continue;\n\n        // find the shortest\
    \ path with BFS\n        while (!que.empty()) {\n            int i = que.front();\n\
    \            que.pop();\n            if (is_sink[i]) {\n                // shortest\
    \ source-sink path found, update S\n                do {\n                   \
    \ if (S.count(i)) {\n                        S.erase(i);\n                   \
    \ } else {\n                        S.insert(i);\n                    }\n    \
    \                i = prv[i];\n                } while (i != -1);\n           \
    \     upd = true;\n                break;\n            }\n            if (S.count(i))\
    \ {\n                // i -> j\n                for (int j = 0; j < E; ++j) {\n\
    \                    if (dist[j] == -1 && !is_source[j] && !S.count(j)) {\n  \
    \                      S.erase(i);\n                        S.insert(j);\n   \
    \                     if (oracle1(S)) {\n                            dist[j] =\
    \ dist[i] + 1;\n                            prv[j] = i;\n                    \
    \        que.push(j);\n                        }\n                        S.insert(i);\n\
    \                        S.erase(j);\n                    }\n                }\n\
    \            } else {\n                // j <- i\n                for (int j =\
    \ 0; j < E; ++j) {\n                    if (dist[j] == -1 && S.count(j)) {\n \
    \                       S.erase(j);\n                        S.insert(i);\n  \
    \                      if (oracle2(S)) {\n                            dist[j]\
    \ = dist[i] + 1;\n                            prv[j] = i;\n                  \
    \          que.push(j);\n                        }\n                        S.insert(j);\n\
    \                        S.erase(i);\n                    }\n                }\n\
    \            }\n        }\n        if (!upd) {\n            // no source-sink\
    \ path found\n            break;\n        }\n    }\n    return S;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/matroid_intersection.hpp
  requiredBy: []
  timestamp: '2022-09-13 22:14:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/matroid_intersection.hpp
layout: document
title: Matroid Intersection
---

## Description

共通の台集合 $E$ 上の 2 つのマトロイド $M_1=(E, \mathcal{I}(M_1)),\,M_2=(E, \mathcal{I}(M_2))$ が与えられたとき，$S\in \mathcal{I}(M_1) \cap \mathcal{I}(M_2)$ を満たす $S$ の中で $\vert S\vert$ が最大のものを一つ計算する．

各 $k=1,2,\dots$ について $|S|=k$ の実行可能集合を保ちながら，bipartite augmentation graph 上での augmenting path に沿って augment を繰り返すアルゴリズムを用いている．

## Operations

- `set<int> matroid_intersection(int E, F1 oracle1, F2 oracle2)`
    - $\vert E\vert$ と，$M_1,\,M_2$ のオラクルが与えられたとき，$\mathcal{I}(M_1) \cap \mathcal{I}(M_2)$ 中で要素数が最大の集合 $S$ を返す．
    - 時間計算量: $O(R^{1.5}\vert E\vert(C_1+C_2)\log R)$, $R$ は $\min(r_{M_1}(E), r_{M_2}(E))$, $C_i$ はオラクル $i$ の計算量

## Note

- この実装では，オラクルを呼び出すごとに $S$ 全体を見て独立性を判定しているが，差分だけ更新するような実装ができれば $C_i$ を小さくすることができる．
- この実装では重みなしのマトロイド交差を解く．重みがある場合は，最短路の代わりに「最大重みの source-sink パスの中で最短のもの」を用いて augment すればよい．
- 基本的には，問題のマトロイドの構造に特化したアルゴリズムを用いるほうが高速なことが多い．

## Reference

- Lee, Jon. *A First Course in Combinatorial Optimization*. Cambridge: Cambridge University Press, 2010
- [[Tutorial] Matroid intersection in simple words - Codeforces](https://codeforces.com/blog/entry/69287)
- [ICPC国内予選F解説 - slideshare](https://www.slideshare.net/tmaehara/icpcf)
- verify: [https://codeforces.com/gym/102156/submission/172034538](https://codeforces.com/gym/102156/submission/172034538)
