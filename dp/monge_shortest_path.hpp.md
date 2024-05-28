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
  bundledCode: "#line 2 \"dp/monge_shortest_path.hpp\"\n#include <limits>\n#include\
    \ <vector>\n\ntemplate <typename T, typename F>\nstd::vector<T> monge_shortest_path(int\
    \ n, const F& cost) {\n    const T INF = std::numeric_limits<T>::max() / 2;\n\
    \    std::vector<T> dist(n, INF);\n    dist[0] = 0;\n    std::vector<int> amin(n);\n\
    \n    auto update = [&](int i, int k) {\n        if (i <= k) return;\n       \
    \ auto nd = dist[k] + cost(k, i);\n        if (nd < dist[i]) {\n            dist[i]\
    \ = nd;\n            amin[i] = k;\n        }\n    };\n\n    auto dfs = [&](auto&\
    \ dfs, int l, int r) -> void {\n        if (r - l == 1) return;\n        int m\
    \ = (l + r) / 2;\n        for (int k = amin[l]; k <= amin[r]; ++k) update(m, k);\n\
    \        dfs(dfs, l, m);\n        for (int k = l + 1; k <= m; ++k) update(r, k);\n\
    \        dfs(dfs, m, r);\n    };\n\n    dfs(dfs, 0, n - 1);\n    return dist;\n\
    }\n"
  code: "#pragma once\n#include <limits>\n#include <vector>\n\ntemplate <typename\
    \ T, typename F>\nstd::vector<T> monge_shortest_path(int n, const F& cost) {\n\
    \    const T INF = std::numeric_limits<T>::max() / 2;\n    std::vector<T> dist(n,\
    \ INF);\n    dist[0] = 0;\n    std::vector<int> amin(n);\n\n    auto update =\
    \ [&](int i, int k) {\n        if (i <= k) return;\n        auto nd = dist[k]\
    \ + cost(k, i);\n        if (nd < dist[i]) {\n            dist[i] = nd;\n    \
    \        amin[i] = k;\n        }\n    };\n\n    auto dfs = [&](auto& dfs, int\
    \ l, int r) -> void {\n        if (r - l == 1) return;\n        int m = (l + r)\
    \ / 2;\n        for (int k = amin[l]; k <= amin[r]; ++k) update(m, k);\n     \
    \   dfs(dfs, l, m);\n        for (int k = l + 1; k <= m; ++k) update(r, k);\n\
    \        dfs(dfs, m, r);\n    };\n\n    dfs(dfs, 0, n - 1);\n    return dist;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: dp/monge_shortest_path.hpp
  requiredBy: []
  timestamp: '2024-05-28 22:29:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/monge_shortest_path.hpp
layout: document
title: Monge Shortest Path
---

## Description

Monge な辺重みを持つ完全 DAG 上の最短距離を求める．この問題は LARSCH algorithm によって $O(N)$ 時間で解けるが，この実装ではより実装が簡単で定数倍高速な $O(N \log N)$ 時間の簡易版 LARSCH algorithm を用いている．

- `vector<T> monge_shortest_path(int n, F cost)`
    - 辺 $(i,j)$ の重みが $\mathrm{cost}(i,j)$ で与えられる $n$ 頂点完全 DAG の頂点 $0$ から各頂点への最短距離を返す
    - 時間計算量: $O(n \log n)$

## Reference

- [簡易版 LARSCH Algorithm - noshi91のメモ](https://noshi91.hatenablog.com/entry/2023/02/18/005856)
- verify: [https://atcoder.jp/contests/abc355/submissions/53788299](https://atcoder.jp/contests/abc355/submissions/53788299)