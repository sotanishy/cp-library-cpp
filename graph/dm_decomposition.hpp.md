---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/bipartite_matching.hpp
    title: Bipartite Matching
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/dm_decomposition.hpp\"\n#include <stack>\n#include\
    \ <utility>\n#include <vector>\n\n#line 2 \"graph/bipartite_matching.hpp\"\n#include\
    \ <limits>\n#include <queue>\n#line 6 \"graph/bipartite_matching.hpp\"\n\nclass\
    \ BipartiteMatching {\n   public:\n    BipartiteMatching() = default;\n    BipartiteMatching(int\
    \ U, int V)\n        : U(U),\n          V(V),\n          NIL(U + V),\n       \
    \   G(U),\n          level(U + V + 1),\n          match(U + V + 1, NIL) {}\n\n\
    \    void add_edge(int u, int v) { G[u].emplace_back(U + v); }\n\n    std::vector<std::pair<int,\
    \ int>> max_matching() {\n        while (bfs()) {\n            for (int u = 0;\
    \ u < U; ++u) {\n                if (match[u] == NIL) {\n                    dfs(u);\n\
    \                }\n            }\n        }\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int u = 0; u < U; ++u) {\n            if (match[u]\
    \ != NIL) ret.emplace_back(u, match[u] - U);\n        }\n        return ret;\n\
    \    }\n\n   private:\n    static constexpr int INF = std::numeric_limits<int>::max()\
    \ / 2;\n\n    const int U, V, NIL;\n    std::vector<std::vector<int>> G;\n   \
    \ std::vector<int> level, match;\n\n    bool bfs() {\n        std::ranges::fill(level,\
    \ INF);\n        std::queue<int> q;\n        for (int u = 0; u < U; ++u) {\n \
    \           if (match[u] == NIL) {\n                level[u] = 0;\n          \
    \      q.push(u);\n            }\n        }\n        while (!q.empty()) {\n  \
    \          int u = q.front();\n            q.pop();\n            if (level[u]\
    \ < level[NIL]) {\n                for (int v : G[u]) {\n                    if\
    \ (level[match[v]] == INF) {\n                        level[match[v]] = level[u]\
    \ + 1;\n                        q.push(match[v]);\n                    }\n   \
    \             }\n            }\n        }\n        return level[NIL] != INF;\n\
    \    }\n\n    bool dfs(int u) {\n        if (u == NIL) return true;\n        for\
    \ (int v : G[u]) {\n            if (level[match[v]] == level[u] + 1 && dfs(match[v]))\
    \ {\n                match[v] = u;\n                match[u] = v;\n          \
    \      return true;\n            }\n        }\n        level[u] = INF;\n     \
    \   return false;\n    }\n};\n\n/*\n * Bipartite matching using Ford-Fulkerson\
    \ algorithm\n * Time complexity: O(VE)\n */\nclass BipartiteMatchingFF {\n   public:\n\
    \    BipartiteMatchingFF() = default;\n    explicit BipartiteMatchingFF(int n)\
    \ : G(n), used(n), match(n) {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    std::vector<std::pair<int, int>> max_matching()\
    \ {\n        int res = 0;\n        std::ranges::fill(match, -1);\n        for\
    \ (int v = 0; v < (int)G.size(); ++v) {\n            if (match[v] == -1) {\n \
    \               std::fill(used.begin(), used.end(), false);\n                if\
    \ (dfs(v)) ++res;\n            }\n        }\n\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int i = 0; i < (int)G.size(); ++i) {\n            if\
    \ (i < match[i]) ret.emplace_back(i, match[i]);\n        }\n        return ret;\n\
    \    }\n\n   private:\n    std::vector<std::vector<int>> G;\n    std::vector<bool>\
    \ used;\n    std::vector<int> match;\n\n    bool dfs(int u) {\n        used[u]\
    \ = true;\n        for (int v : G[u]) {\n            int w = match[v];\n     \
    \       if (w == -1 || (!used[w] && dfs(w))) {\n                match[u] = v;\n\
    \                match[v] = u;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n};\n#line 7 \"graph/dm_decomposition.hpp\"\
    \n\nstd::vector<int> dm_decomposition(\n    int X, int Y, const std::vector<std::pair<int,\
    \ int>>& edges) {\n    int N = X + Y;\n    std::vector<std::vector<int>> G(N);\n\
    \    BipartiteMatching bm(X, Y);\n    for (auto [u, v] : edges) {\n        G[u].push_back(X\
    \ + v);\n        G[X + v].push_back(u);\n        bm.add_edge(u, v);\n    }\n \
    \   std::vector<int> comp(N), matched(N, -1);\n    for (auto [u, v] : bm.max_matching())\
    \ {\n        comp[u] = comp[v] = -1;\n        matched[u] = X + v;\n        matched[X\
    \ + v] = u;\n    }\n    std::stack<std::pair<int, bool>>\n        st;  // whether\
    \ or not the previous edge is used in the matching\n    for (int v = 0; v < N;\
    \ ++v) {\n        if (comp[v] == 0) {\n            st.push({v, 0});\n        \
    \    st.push({v, 1});\n        }\n    }\n    while (!st.empty()) {\n        auto\
    \ [u, b] = st.top();\n        st.pop();\n        for (int v : G[u]) {\n      \
    \      if (comp[v] == -1 && (b ^ (matched[u] == v))) {\n                comp[v]\
    \ = comp[u] ^ 1;\n                st.push({v, !b});\n            }\n        }\n\
    \    }\n    return comp;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <utility>\n#include <vector>\n\n\
    #include \"bipartite_matching.hpp\"\n\nstd::vector<int> dm_decomposition(\n  \
    \  int X, int Y, const std::vector<std::pair<int, int>>& edges) {\n    int N =\
    \ X + Y;\n    std::vector<std::vector<int>> G(N);\n    BipartiteMatching bm(X,\
    \ Y);\n    for (auto [u, v] : edges) {\n        G[u].push_back(X + v);\n     \
    \   G[X + v].push_back(u);\n        bm.add_edge(u, v);\n    }\n    std::vector<int>\
    \ comp(N), matched(N, -1);\n    for (auto [u, v] : bm.max_matching()) {\n    \
    \    comp[u] = comp[v] = -1;\n        matched[u] = X + v;\n        matched[X +\
    \ v] = u;\n    }\n    std::stack<std::pair<int, bool>>\n        st;  // whether\
    \ or not the previous edge is used in the matching\n    for (int v = 0; v < N;\
    \ ++v) {\n        if (comp[v] == 0) {\n            st.push({v, 0});\n        \
    \    st.push({v, 1});\n        }\n    }\n    while (!st.empty()) {\n        auto\
    \ [u, b] = st.top();\n        st.pop();\n        for (int v : G[u]) {\n      \
    \      if (comp[v] == -1 && (b ^ (matched[u] == v))) {\n                comp[v]\
    \ = comp[u] ^ 1;\n                st.push({v, !b});\n            }\n        }\n\
    \    }\n    return comp;\n}"
  dependsOn:
  - graph/bipartite_matching.hpp
  isVerificationFile: false
  path: graph/dm_decomposition.hpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/dm_decomposition.hpp
layout: document
title: Dulmage-Mendelsohn Decomposition
---

## Description

Dulmage-Mendelsohn 分解 (DM分解) は，与えられた二部グラフの最大マッチングに関する性質による頂点の分類である．

この実装では，二部グラフ $G$ の頂点を3つの集合 $U, O, E$ に分類する．この分類は以下の性質を持つ:
- $U, O, E$ は pairwise disjoint である
- $G$ の任意の最大マッチングは $U-U$ 辺と $E-O$ 辺からなる
- $G$ の任意の最大マッチングにおいて，$U, O$ に属する頂点はすべてマッチされる
- $G$ の最大マッチングの大きさは $\vert O\vert + \vert U\vert/2$ である

DM 分解は疎行列のブロック対角化に用いられるらしい．行列を行と列の二部グラフとみなし，非零要素のところに辺を張って DM 分解をすると，ブロック対角化ができる (このとき，$U$を更に細かく分類することでブロックを小さくする)．大規模な線形連立方程式を小さな部分問題に分解できて嬉しいらしいが，競プロで使いどころがあるかは知らない．

## Operations

- `vector<int> dm_decomposition(int X, int Y, vector<pair<int, int>> edges)`
    - 二部グラフ $G$ (頂点数 $X$, $Y$，辺は `edges` ) を DM 分解する．返り値は，$0,\dots,X-1$ 番目は $X$ の頂点，$X,\dots,X+Y-1$ 番目は $Y$ の頂点が属する集合を表す．0は$E$, 1は$O$, -1は$U$に属することを意味する
    - 時間計算量: $O(E\sqrt{X + Y})$


## Reference

- [Dulmage Mendelsohn Decomposition](http://www.cse.iitm.ac.in/~meghana/matchings/bip-decomp.pdf)
- [Dulmage–Mendelsohn分解 (DM分解)](http://misojiro.t.u-tokyo.ac.jp/~murota/lect-ouyousurigaku/dm050410.pdf)
- verify: [https://atcoder.jp/contests/abc223/submissions/26666610](https://atcoder.jp/contests/abc223/submissions/26666610)