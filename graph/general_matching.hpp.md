---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/general_matching.test.cpp
    title: test/yosupo/general_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/general_matching.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <vector>\n\nclass GeneralMatching {\n\
    \   public:\n    GeneralMatching() = default;\n    explicit GeneralMatching(int\
    \ n)\n        : n(n), m(n + n / 2), G(m, std::vector<bool>(m)), mate(m, -1) {}\n\
    \n    void add_edge(int u, int v) { G[u][v] = G[v][u] = true; }\n\n    std::vector<std::pair<int,\
    \ int>> max_matching() {\n        // par: parent in the alternating forest\n \
    \       // dep: 0 if even, 1 if odd, -1 if not in the forest\n        // comp:\
    \ id of the comp in the forest\n        // alive: whether the blossom/vertex is\
    \ alive\n        // blossom: members of the blossom\n        std::vector<int>\
    \ par(m), dep(m), comp(m);\n        std::vector<bool> alive(m, true);\n      \
    \  std::vector<std::vector<int>> blossom(m);\n\n        auto get_ancestors = [&](int\
    \ v) {\n            std::vector<int> ret;\n            while (v != -1) {\n   \
    \             ret.push_back(v);\n                v = par[v];\n            }\n\
    \            return ret;\n        };\n\n        auto flip_to_root = [&](int v)\
    \ {\n            mate[v] = -1;\n            int w = par[v];\n            while\
    \ (w != -1) {\n                int p = par[w];\n                mate[w] = p;\n\
    \                mate[p] = w;\n                w = par[p];\n            }\n  \
    \      };\n\n        for (int ans = 0;; ++ans) {\n            std::ranges::fill(par,\
    \ -1);\n            std::ranges::fill(dep, -1);\n            std::ranges::fill(comp,\
    \ -1);\n            bool augment = false;\n            int c = n;  // n + number\
    \ of blossoms\n\n            // seed\n            std::queue<int> que;\n     \
    \       for (int v = 0; v < n; ++v) {\n                if (mate[v] == -1) {\n\
    \                    que.push(v);\n                    dep[v] = 0;\n         \
    \           comp[v] = v;\n                }\n            }\n\n            // repeat\
    \ until an augmenting path is found\n            while (!que.empty() && !augment)\
    \ {\n                int v = que.front();\n                que.pop();\n      \
    \          if (!alive[v]) continue;\n                for (int u = 0; u < c; ++u)\
    \ {\n                    if (!G[v][u] || !alive[u] || dep[u] == 1) continue;\n\
    \                    if (dep[u] == -1) {\n                        // grow\n  \
    \                      int w = mate[u];\n                        par[u] = v;\n\
    \                        par[w] = u;\n                        dep[u] = 1;\n  \
    \                      dep[w] = 0;\n                        comp[u] = comp[w]\
    \ = comp[v];\n                        que.push(w);\n                    } else\
    \ if (comp[v] == comp[u]) {\n                        // shrink\n\n           \
    \             // build the blossom\n                        auto av = get_ancestors(v);\n\
    \                        auto au = get_ancestors(u);\n                       \
    \ int w;  // lca\n                        while (!av.empty() && !au.empty() &&\n\
    \                               av.back() == au.back()) {\n                  \
    \          w = av.back();\n                            av.pop_back();\n      \
    \                      au.pop_back();\n                        }\n           \
    \             blossom[c] = std::move(av);\n                        blossom[c].push_back(w);\n\
    \                        std::ranges::reverse(blossom[c]);\n                 \
    \       std::ranges::move(au, std::back_inserter(blossom[c]));\n\n           \
    \             // contract\n                        if (par[w] != -1) mate[par[w]]\
    \ = c;\n                        par[c] = mate[c] = par[w];\n                 \
    \       dep[c] = 0;\n                        comp[c] = comp[w];\n            \
    \            for (int x : blossom[c]) {\n                            alive[x]\
    \ = false;\n                            mate[x] = -1;\n                      \
    \  }\n                        for (int x : blossom[c]) {\n                   \
    \         for (int y = 0; y < c; ++y) {\n                                if (G[x][y]\
    \ && alive[y]) {\n                                    G[y][c] = G[c][y] = true;\n\
    \                                    if (par[y] == x) par[y] = c;\n          \
    \                      }\n                            }\n                    \
    \    }\n\n                        que.push(c);\n                        ++c;\n\
    \                        break;\n                    } else {\n              \
    \          // augment\n                        augment = true;\n             \
    \           flip_to_root(v);\n                        flip_to_root(u);\n     \
    \                   mate[v] = u;\n                        mate[u] = v;\n     \
    \                   break;\n                    }\n                }\n       \
    \     }\n\n            // restore blossoms\n            while (c > n) {\n    \
    \            --c;\n                int b = blossom[c].size();\n\n            \
    \    // select the base\n                int base_idx;\n                if (mate[c]\
    \ == -1) {\n                    base_idx = 0;\n                } else {\n    \
    \                base_idx = -1;\n                    for (int i = 0; i < b; ++i)\
    \ {\n                        int x = blossom[c][i];\n                        int\
    \ y = mate[c];\n                        if (G[x][y]) {\n                     \
    \       base_idx = i;\n                            mate[c] = -1;\n           \
    \                 mate[y] = x;\n                            mate[x] = y;\n   \
    \                         break;\n                        }\n                \
    \    }\n                    assert(base_idx != -1);\n                }\n\n   \
    \             // restore matches\n                for (int i = 1; i < b; i +=\
    \ 2) {\n                    int u = blossom[c][(base_idx + i) % b];\n        \
    \            int v = blossom[c][(base_idx + i + 1) % b];\n                   \
    \ mate[u] = v;\n                    mate[v] = u;\n                }\n\n      \
    \          for (int x : blossom[c]) alive[x] = true;\n                for (int\
    \ y = 0; y < c; ++y) G[c][y] = G[y][c] = false;\n                blossom[c].clear();\n\
    \            }\n\n            if (!augment) {\n                std::vector<std::pair<int,\
    \ int>> matches;\n                for (int i = 0; i < n; ++i) {\n            \
    \        if (i < mate[i]) {\n                        matches.emplace_back(i, mate[i]);\n\
    \                    }\n                }\n                return matches;\n \
    \           }\n        }\n    }\n\n   private:\n    int n, m;  // m: maximum number\
    \ of vertices + blossoms\n    std::vector<std::vector<bool>> G;  // adjacency\
    \ matrix\n    std::vector<int> mate;             // -1 if not matched\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <vector>\n\nclass GeneralMatching {\n   public:\n    GeneralMatching()\
    \ = default;\n    explicit GeneralMatching(int n)\n        : n(n), m(n + n / 2),\
    \ G(m, std::vector<bool>(m)), mate(m, -1) {}\n\n    void add_edge(int u, int v)\
    \ { G[u][v] = G[v][u] = true; }\n\n    std::vector<std::pair<int, int>> max_matching()\
    \ {\n        // par: parent in the alternating forest\n        // dep: 0 if even,\
    \ 1 if odd, -1 if not in the forest\n        // comp: id of the comp in the forest\n\
    \        // alive: whether the blossom/vertex is alive\n        // blossom: members\
    \ of the blossom\n        std::vector<int> par(m), dep(m), comp(m);\n        std::vector<bool>\
    \ alive(m, true);\n        std::vector<std::vector<int>> blossom(m);\n\n     \
    \   auto get_ancestors = [&](int v) {\n            std::vector<int> ret;\n   \
    \         while (v != -1) {\n                ret.push_back(v);\n             \
    \   v = par[v];\n            }\n            return ret;\n        };\n\n      \
    \  auto flip_to_root = [&](int v) {\n            mate[v] = -1;\n            int\
    \ w = par[v];\n            while (w != -1) {\n                int p = par[w];\n\
    \                mate[w] = p;\n                mate[p] = w;\n                w\
    \ = par[p];\n            }\n        };\n\n        for (int ans = 0;; ++ans) {\n\
    \            std::ranges::fill(par, -1);\n            std::ranges::fill(dep, -1);\n\
    \            std::ranges::fill(comp, -1);\n            bool augment = false;\n\
    \            int c = n;  // n + number of blossoms\n\n            // seed\n  \
    \          std::queue<int> que;\n            for (int v = 0; v < n; ++v) {\n \
    \               if (mate[v] == -1) {\n                    que.push(v);\n     \
    \               dep[v] = 0;\n                    comp[v] = v;\n              \
    \  }\n            }\n\n            // repeat until an augmenting path is found\n\
    \            while (!que.empty() && !augment) {\n                int v = que.front();\n\
    \                que.pop();\n                if (!alive[v]) continue;\n      \
    \          for (int u = 0; u < c; ++u) {\n                    if (!G[v][u] ||\
    \ !alive[u] || dep[u] == 1) continue;\n                    if (dep[u] == -1) {\n\
    \                        // grow\n                        int w = mate[u];\n \
    \                       par[u] = v;\n                        par[w] = u;\n   \
    \                     dep[u] = 1;\n                        dep[w] = 0;\n     \
    \                   comp[u] = comp[w] = comp[v];\n                        que.push(w);\n\
    \                    } else if (comp[v] == comp[u]) {\n                      \
    \  // shrink\n\n                        // build the blossom\n               \
    \         auto av = get_ancestors(v);\n                        auto au = get_ancestors(u);\n\
    \                        int w;  // lca\n                        while (!av.empty()\
    \ && !au.empty() &&\n                               av.back() == au.back()) {\n\
    \                            w = av.back();\n                            av.pop_back();\n\
    \                            au.pop_back();\n                        }\n     \
    \                   blossom[c] = std::move(av);\n                        blossom[c].push_back(w);\n\
    \                        std::ranges::reverse(blossom[c]);\n                 \
    \       std::ranges::move(au, std::back_inserter(blossom[c]));\n\n           \
    \             // contract\n                        if (par[w] != -1) mate[par[w]]\
    \ = c;\n                        par[c] = mate[c] = par[w];\n                 \
    \       dep[c] = 0;\n                        comp[c] = comp[w];\n            \
    \            for (int x : blossom[c]) {\n                            alive[x]\
    \ = false;\n                            mate[x] = -1;\n                      \
    \  }\n                        for (int x : blossom[c]) {\n                   \
    \         for (int y = 0; y < c; ++y) {\n                                if (G[x][y]\
    \ && alive[y]) {\n                                    G[y][c] = G[c][y] = true;\n\
    \                                    if (par[y] == x) par[y] = c;\n          \
    \                      }\n                            }\n                    \
    \    }\n\n                        que.push(c);\n                        ++c;\n\
    \                        break;\n                    } else {\n              \
    \          // augment\n                        augment = true;\n             \
    \           flip_to_root(v);\n                        flip_to_root(u);\n     \
    \                   mate[v] = u;\n                        mate[u] = v;\n     \
    \                   break;\n                    }\n                }\n       \
    \     }\n\n            // restore blossoms\n            while (c > n) {\n    \
    \            --c;\n                int b = blossom[c].size();\n\n            \
    \    // select the base\n                int base_idx;\n                if (mate[c]\
    \ == -1) {\n                    base_idx = 0;\n                } else {\n    \
    \                base_idx = -1;\n                    for (int i = 0; i < b; ++i)\
    \ {\n                        int x = blossom[c][i];\n                        int\
    \ y = mate[c];\n                        if (G[x][y]) {\n                     \
    \       base_idx = i;\n                            mate[c] = -1;\n           \
    \                 mate[y] = x;\n                            mate[x] = y;\n   \
    \                         break;\n                        }\n                \
    \    }\n                    assert(base_idx != -1);\n                }\n\n   \
    \             // restore matches\n                for (int i = 1; i < b; i +=\
    \ 2) {\n                    int u = blossom[c][(base_idx + i) % b];\n        \
    \            int v = blossom[c][(base_idx + i + 1) % b];\n                   \
    \ mate[u] = v;\n                    mate[v] = u;\n                }\n\n      \
    \          for (int x : blossom[c]) alive[x] = true;\n                for (int\
    \ y = 0; y < c; ++y) G[c][y] = G[y][c] = false;\n                blossom[c].clear();\n\
    \            }\n\n            if (!augment) {\n                std::vector<std::pair<int,\
    \ int>> matches;\n                for (int i = 0; i < n; ++i) {\n            \
    \        if (i < mate[i]) {\n                        matches.emplace_back(i, mate[i]);\n\
    \                    }\n                }\n                return matches;\n \
    \           }\n        }\n    }\n\n   private:\n    int n, m;  // m: maximum number\
    \ of vertices + blossoms\n    std::vector<std::vector<bool>> G;  // adjacency\
    \ matrix\n    std::vector<int> mate;             // -1 if not matched\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/general_matching.hpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/general_matching.test.cpp
documentation_of: graph/general_matching.hpp
layout: document
title: General Matching
---

## Description

一般グラフの最大マッチングを，Edmonds の花アルゴリズムで求める．

## Operations

- `GeneralMatching(int n)`
    - 頂点数 $n$ で初期化する
- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
- `vector<pair<int, int>> max_matching()`
    - 一般グラフの最大マッチングを一つ返す
    - 時間計算量: $O(n^3)$

## Reference

- Lee, Jon. *A First Course in Combinatorial Optimization*. Cambridge: Cambridge University Press, 2010
- [[Tutorial] Blossom Algorithm for General Matching in O(n^3) - Codeforces](https://codeforces.com/blog/entry/92339)