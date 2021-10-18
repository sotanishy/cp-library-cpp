---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path.cpp
    title: Shortest Path Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/range_edge_graph.cpp\"\n#include <vector>\n#line 2\
    \ \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n\
    \    T weight;\n    Edge() = default;\n    Edge(int to, T weight) : from(-1),\
    \ to(to), weight(weight) {}\n    Edge(int from, int to, T weight) : from(from),\
    \ to(to), weight(weight) {}\n};\n#line 2 \"graph/shortest_path.cpp\"\n#include\
    \ <limits>\n#include <queue>\n#include <tuple>\n#include <utility>\n#line 8 \"\
    graph/shortest_path.cpp\"\n\n/*\n * Bellman-Ford Algorithm\n */\ntemplate <typename\
    \ T>\nstd::vector<T> bellman_ford(const std::vector<Edge<T>>& G, int V, int s)\
    \ {\n    constexpr T INF = std::numeric_limits<T>::max();\n    std::vector<int>\
    \ dist(V, INF);\n    dist[s] = 0;\n    for (int i = 0; i < V; ++i) {\n       \
    \ for (auto& e : G) {\n            if (dist[e.from] != INF && dist[e.to] > dist[e.from]\
    \ + e.weight) {\n                dist[e.to] = dist[e.from] + e.weight;\n     \
    \           if (i == V - 1) return std::vector<T>();\n            }\n        }\n\
    \    }\n    return dist;\n}\n\n/*\n * Floyd-Warshall Algorithm\n */\ntemplate\
    \ <typename T>\nvoid floyd_warshall(std::vector<std::vector<T>>& dist) {\n   \
    \ int V = dist.size();\n    for (int k = 0; k < V; ++k) {\n        for (int i\
    \ = 0; i < V; ++i) {\n            for (int j = 0; j < V; ++j) {\n            \
    \    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);\n           \
    \ }\n        }\n    }\n}\n\n/*\n * Dijkstra's Algorithm\n */\ntemplate <typename\
    \ T>\nstd::vector<T> dijkstra(const std::vector<std::vector<Edge<T>>>& G, int\
    \ s) {\n    std::vector<T> dist(G.size(), std::numeric_limits<T>::max());\n  \
    \  dist[s] = 0;\n    using P = std::pair<T, int>;\n    std::priority_queue<P,\
    \ std::vector<P>, std::greater<P>> pq;\n    pq.emplace(0, s);\n\n    while (!pq.empty())\
    \ {\n        T d;\n        int v;\n        std::tie(d, v) = pq.top();\n      \
    \  pq.pop();\n        if (dist[v] < d) continue;\n        for (auto& e : G[v])\
    \ {\n            if (dist[e.to] > d + e.weight) {\n                dist[e.to]\
    \ = d + e.weight;\n                pq.emplace(dist[e.to], e.to);\n           \
    \ }\n        }\n    }\n\n    return dist;\n}\n\n/*\n * Breadth-First Search\n\
    \ */\nstd::vector<int> bfs(const std::vector<std::vector<int>>& G, int s) {\n\
    \    std::vector<int> dist(G.size(), -1);\n    dist[s] = 0;\n    std::queue<int>\
    \ que;\n    que.push(s);\n\n    while (!que.empty()) {\n        int v = que.front();\n\
    \        que.pop();\n        for (int u : G[v]) {\n            if (dist[u] ==\
    \ -1) {\n                dist[u] = dist[v] + 1;\n                que.push(u);\n\
    \            }\n        }\n    }\n\n    return dist;\n}\n\n/*\n * Dial's Algorithm\n\
    \ */\nstd::vector<int> dial(const std::vector<std::vector<Edge<int>>>& G, int\
    \ s, int w) {\n    std::vector<int> dist(G.size(), std::numeric_limits<int>::max());\n\
    \    dist[s] = 0;\n    std::vector<std::vector<int>> buckets(w * G.size(), std::vector<int>());\n\
    \    buckets[0].push_back(s);\n\n    for (int d = 0; d < (int) buckets.size();\
    \ ++d) {\n        while (!buckets[d].empty()) {\n            int v = buckets[d].back();\n\
    \            buckets[d].pop_back();\n            if (dist[v] < d) continue;\n\
    \            for (auto& e : G[v]) {\n                if (dist[e.to] > d + e.weight)\
    \ {\n                    dist[e.to] = d + e.weight;\n                    buckets[dist[e.to]].push_back(e.to);\n\
    \                }\n            }\n        }\n    }\n    return dist;\n}\n#line\
    \ 5 \"graph/range_edge_graph.cpp\"\n\ntemplate <typename T>\nclass RangeEdgeGraph\
    \ {\npublic:\n    RangeEdgeGraph() = default;\n    explicit RangeEdgeGraph(int\
    \ n) {\n        size = 1;\n        while (size < n) size <<= 1;\n        G.resize(4\
    \ * size);\n        for (int i = 1; i < size; ++i) {\n            int l = 2 *\
    \ i, r = 2 * i + 1;\n            G[i].emplace_back(l, 0);\n            G[i].emplace_back(r,\
    \ 0);\n            G[l + 2 * size].emplace_back(i + 2 * size, 0);\n          \
    \  G[r + 2 * size].emplace_back(i + 2 * size, 0);\n        }\n        for (int\
    \ i = size; i < 2 * size; ++i) G[i].emplace_back(i + 2 * size, 0);\n    }\n\n\
    \    void add_edge(int l1, int r1, int l2, int r2, T w) {\n        int idx = G.size();\n\
    \        for (l1 += size, r1 += size; l1 < r1; l1 >>= 1, r1 >>= 1) {\n       \
    \     if (l1 & 1) G[l1 + 2 * size].emplace_back(idx, 0), ++l1;\n            if\
    \ (r1 & 1) --r1, G[r1 + 2 * size].emplace_back(idx, 0);\n        }\n        std::vector<Edge<T>>\
    \ node;\n        for (l2 += size, r2 += size; l2 < r2; l2 >>= 1, r2 >>= 1) {\n\
    \            if (l2 & 1) node.emplace_back(l2++, w);\n            if (r2 & 1)\
    \ node.emplace_back(--r2, w);\n        }\n        G.push_back(node);\n    }\n\n\
    \    std::vector<T> dist(int s) const {\n        std::vector<T> dist = dijkstra(G,\
    \ s + size);\n        return std::vector<T>(dist.begin() + size, dist.begin()\
    \ + 2 * size);\n    }\n\nprivate:\n    int size;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n};\n\n\n/*\nImplementation with a sparse table\n\ntemplate <typename T>\n\
    class RangeEdgeGraph {\npublic:\n    RangeEdgeGraph() = default;\n    explicit\
    \ RangeEdgeGraph(int n) : n(n) {\n        b = 0;\n        while ((1 << b) <= n)\
    \ ++b;\n        G.resize(2 * n * b);\n        for (int i = 1; i < b; ++i) {\n\
    \            for (int j = 0; j + (1 << i) <= n; ++j) {\n                int k\
    \ = n * i + j;\n                int l = n * (i - 1) + j;\n                int\
    \ r = l + (1 << (i - 1));\n                G[k].emplace_back(l, 0);\n        \
    \        G[k].emplace_back(r, 0);\n                G[n * b + l].emplace_back(n\
    \ * b + k, 0);\n                G[n * b + r].emplace_back(n * b + k, 0);\n   \
    \         }\n        }\n        for (int j = 0; j < n; ++j) G[j].emplace_back(n\
    \ * b + j, 0);\n    }\n\n    void add_edge(int l1, int r1, int l2, int r2, T w)\
    \ {\n        int idx = G.size();\n        std::vector<Edge<T>> node;\n       \
    \ int i = 31 - __builtin_clz(r1 - l1);\n        G[n * b + n * i + l1].emplace_back(idx,\
    \ 0);\n        G[n * b + n * i + r1 - (1 << i)].emplace_back(idx, 0);\n\n    \
    \    i = 31 - __builtin_clz(r2 - l2);\n        node.emplace_back(n * i + l2, w);\n\
    \        node.emplace_back(n * i + r2 - (1 << i), w);\n        G.push_back(node);\n\
    \    }\n\n    std::vector<T> dist(int s) const {\n        std::vector<T> dist\
    \ = dijkstra(G, s);\n        return std::vector<T>(dist.begin(), dist.begin()\
    \ + n);\n    }\n\nprivate:\n    int n, b;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n};\n\n*/\n"
  code: "#pragma once\n#include <vector>\n#include \"edge.cpp\"\n#include \"shortest_path.cpp\"\
    \n\ntemplate <typename T>\nclass RangeEdgeGraph {\npublic:\n    RangeEdgeGraph()\
    \ = default;\n    explicit RangeEdgeGraph(int n) {\n        size = 1;\n      \
    \  while (size < n) size <<= 1;\n        G.resize(4 * size);\n        for (int\
    \ i = 1; i < size; ++i) {\n            int l = 2 * i, r = 2 * i + 1;\n       \
    \     G[i].emplace_back(l, 0);\n            G[i].emplace_back(r, 0);\n       \
    \     G[l + 2 * size].emplace_back(i + 2 * size, 0);\n            G[r + 2 * size].emplace_back(i\
    \ + 2 * size, 0);\n        }\n        for (int i = size; i < 2 * size; ++i) G[i].emplace_back(i\
    \ + 2 * size, 0);\n    }\n\n    void add_edge(int l1, int r1, int l2, int r2,\
    \ T w) {\n        int idx = G.size();\n        for (l1 += size, r1 += size; l1\
    \ < r1; l1 >>= 1, r1 >>= 1) {\n            if (l1 & 1) G[l1 + 2 * size].emplace_back(idx,\
    \ 0), ++l1;\n            if (r1 & 1) --r1, G[r1 + 2 * size].emplace_back(idx,\
    \ 0);\n        }\n        std::vector<Edge<T>> node;\n        for (l2 += size,\
    \ r2 += size; l2 < r2; l2 >>= 1, r2 >>= 1) {\n            if (l2 & 1) node.emplace_back(l2++,\
    \ w);\n            if (r2 & 1) node.emplace_back(--r2, w);\n        }\n      \
    \  G.push_back(node);\n    }\n\n    std::vector<T> dist(int s) const {\n     \
    \   std::vector<T> dist = dijkstra(G, s + size);\n        return std::vector<T>(dist.begin()\
    \ + size, dist.begin() + 2 * size);\n    }\n\nprivate:\n    int size;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n};\n\n\n/*\nImplementation with a sparse table\n\ntemplate <typename T>\n\
    class RangeEdgeGraph {\npublic:\n    RangeEdgeGraph() = default;\n    explicit\
    \ RangeEdgeGraph(int n) : n(n) {\n        b = 0;\n        while ((1 << b) <= n)\
    \ ++b;\n        G.resize(2 * n * b);\n        for (int i = 1; i < b; ++i) {\n\
    \            for (int j = 0; j + (1 << i) <= n; ++j) {\n                int k\
    \ = n * i + j;\n                int l = n * (i - 1) + j;\n                int\
    \ r = l + (1 << (i - 1));\n                G[k].emplace_back(l, 0);\n        \
    \        G[k].emplace_back(r, 0);\n                G[n * b + l].emplace_back(n\
    \ * b + k, 0);\n                G[n * b + r].emplace_back(n * b + k, 0);\n   \
    \         }\n        }\n        for (int j = 0; j < n; ++j) G[j].emplace_back(n\
    \ * b + j, 0);\n    }\n\n    void add_edge(int l1, int r1, int l2, int r2, T w)\
    \ {\n        int idx = G.size();\n        std::vector<Edge<T>> node;\n       \
    \ int i = 31 - __builtin_clz(r1 - l1);\n        G[n * b + n * i + l1].emplace_back(idx,\
    \ 0);\n        G[n * b + n * i + r1 - (1 << i)].emplace_back(idx, 0);\n\n    \
    \    i = 31 - __builtin_clz(r2 - l2);\n        node.emplace_back(n * i + l2, w);\n\
    \        node.emplace_back(n * i + r2 - (1 << i), w);\n        G.push_back(node);\n\
    \    }\n\n    std::vector<T> dist(int s) const {\n        std::vector<T> dist\
    \ = dijkstra(G, s);\n        return std::vector<T>(dist.begin(), dist.begin()\
    \ + n);\n    }\n\nprivate:\n    int n, b;\n    std::vector<std::vector<Edge<T>>>\
    \ G;\n};\n\n*/\n"
  dependsOn:
  - graph/edge.cpp
  - graph/shortest_path.cpp
  isVerificationFile: false
  path: graph/range_edge_graph.cpp
  requiredBy: []
  timestamp: '2021-10-07 16:56:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/range_edge_graph.cpp
layout: document
title: Range Edge Graph
---

## Description

セグメント木と同様の構造を用いることで，効率的に区間に辺を張ることができる．

空間計算量: $O(n + m\log n)$, $m$ は張った辺の数

## Operations

- `RangeEdgeGraph(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$
- `void add_edge(int l1, int r1, int l2, int r2, T w)`
    - 区間 $[l_1, r_1)$ から区間 $[l_2, r_2)$ に重み $w$ の辺を張る
    - 時間計算量: $O(\log n)$
- `vector<T> dist(int s)`
    - 始点 $s$ から各頂点への最短距離を Dijkstra 法で求める
    - 時間計算量: $O((n + m\log n) \log (n + m))$

## Note

セグメント木ではなく sparse table の構造を用いて区間に辺を張ることもできる．この場合空間計算量は $O(n\log n + m)$，時間計算量は構築 $O(n\log n)$，辺の追加 $O(1)$，Dijkstra 法 $O((n\log n + m) \log (n\log n + m)))$ となる．特に辺が多いときに高速であるという利点があるが，空間計算量が大きくなるので注意が必要である．Sqrt tree の構造を用いることもできるが狂気である．

## Reference

- [区間に辺を貼る一般的なテクニック](https://www.slideshare.net/secret/r8gjH9xYxFR0Fu)
- [区間に辺を張るテクの実装例（Dijkstra法セット）と使用例](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)
