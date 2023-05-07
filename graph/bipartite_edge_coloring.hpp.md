---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/unionfind/union_find.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_matching.hpp
    title: Bipartite Matching
  - icon: ':heavy_check_mark:'
    path: graph/eulerian_path.hpp
    title: Eulerian Path
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartite_edge_coloring.test.cpp
    title: test/yosupo/bipartite_edge_coloring.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/bipartite_edge_coloring.hpp\"\n#include <algorithm>\n\
    #include <map>\n#include <queue>\n#include <utility>\n#include <vector>\n#line\
    \ 4 \"data-structure/unionfind/union_find.cpp\"\n\nclass UnionFind {\npublic:\n\
    \    UnionFind() = default;\n    explicit UnionFind(int n) : data(n, -1) {}\n\n\
    \    int find(int x) {\n        if (data[x] < 0) return x;\n        return data[x]\
    \ = find(data[x]);\n    }\n\n    void unite(int x, int y) {\n        x = find(x);\n\
    \        y = find(y);\n        if (x == y) return;\n        if (data[x] > data[y])\
    \ std::swap(x, y);\n        data[x] += data[y];\n        data[y] = x;\n    }\n\
    \n    bool same(int x, int y) {\n        return find(x) == find(y);\n    }\n\n\
    \    int size(int x) {\n        return -data[find(x)];\n    }\n\nprivate:\n  \
    \  std::vector<int> data;\n};\n#line 2 \"graph/bipartite_matching.hpp\"\n#include\
    \ <limits>\n#line 6 \"graph/bipartite_matching.hpp\"\n\nclass BipartiteMatching\
    \ {\npublic:\n    BipartiteMatching() = default;\n    BipartiteMatching(int U,\
    \ int V) : U(U), V(V), NIL(U + V), G(U), level(U + V + 1), match(U + V + 1, NIL)\
    \ {}\n\n    void add_edge(int u, int v) {\n        G[u].emplace_back(U + v);\n\
    \    }\n\n    std::vector<std::pair<int, int>> max_matching() {\n        while\
    \ (bfs()) {\n            for (int u = 0; u < U; ++u) {\n                if (match[u]\
    \ == NIL) {\n                    dfs(u);\n                }\n            }\n \
    \       }\n        std::vector<std::pair<int, int>> ret;\n        for (int u =\
    \ 0; u < U; ++u) {\n            if (match[u] != NIL) ret.emplace_back(u, match[u]\
    \ - U);\n        }\n        return ret;\n    }\n\nprivate:\n    static constexpr\
    \ int INF = std::numeric_limits<int>::max() / 2;\n\n    const int U, V, NIL;\n\
    \    std::vector<std::vector<int>> G;\n    std::vector<int> level, match;\n\n\
    \    bool bfs() {\n        std::fill(level.begin(), level.end(), INF);\n     \
    \   std::queue<int> q;\n        for (int u = 0; u < U; ++u) {\n            if\
    \ (match[u] == NIL) {\n                level[u] = 0;\n                q.push(u);\n\
    \            }\n        }\n        while (!q.empty()) {\n            int u = q.front();\n\
    \            q.pop();\n            if (level[u] < level[NIL]) {\n            \
    \    for (int v : G[u]) {\n                    if (level[match[v]] == INF) {\n\
    \                        level[match[v]] = level[u] + 1;\n                   \
    \     q.push(match[v]);\n                    }\n                }\n          \
    \  }\n        }\n        return level[NIL] != INF;\n    }\n\n    bool dfs(int\
    \ u) {\n        if (u == NIL) return true;\n        for (int v : G[u]) {\n   \
    \         if (level[match[v]] == level[u] + 1 && dfs(match[v])) {\n          \
    \      match[v] = u;\n                match[u] = v;\n                return true;\n\
    \            }\n        }\n        level[u] = INF;\n        return false;\n  \
    \  }\n};\n\n\n/*\n * Bipartite matching using Ford-Fulkerson algorithm\n * Time\
    \ complexity: O(VE)\n */\nclass BipartiteMatchingFF {\npublic:\n    BipartiteMatchingFF()\
    \ = default;\n    explicit BipartiteMatchingFF(int n) : G(n), used(n), match(n)\
    \ {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n      \
    \  G[v].push_back(u);\n    }\n\n    std::vector<std::pair<int, int>> max_matching()\
    \ {\n        int res = 0;\n        std::fill(match.begin(), match.end(), -1);\n\
    \        for (int v = 0; v < (int) G.size(); ++v) {\n            if (match[v]\
    \ == -1) {\n                std::fill(used.begin(), used.end(), false);\n    \
    \            if (dfs(v)) ++res;\n            }\n        }\n\n        std::vector<std::pair<int,\
    \ int>> ret;\n        for (int i = 0; i < (int) G.size(); ++i) {\n           \
    \ if (i < match[i]) ret.emplace_back(i, match[i]);\n        }\n        return\
    \ ret;\n    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<bool>\
    \ used;\n    std::vector<int> match;\n\n    bool dfs(int u) {\n        used[u]\
    \ = true;\n        for (int v : G[u]) {\n            int w = match[v];\n     \
    \       if (w == -1 || (!used[w] && dfs(w))) {\n                match[u] = v;\n\
    \                match[v] = u;\n                return true;\n            }\n\
    \        }\n        return false;\n    }\n};\n#line 2 \"graph/eulerian_path.hpp\"\
    \n#include <stack>\n#line 5 \"graph/eulerian_path.hpp\"\n\nstd::vector<int> eulerian_path(const\
    \ std::vector<std::pair<int, int>>& edges, int V) {\n    std::vector<std::vector<std::pair<int,\
    \ int>>> G(V);\n    std::vector<int> deg(V);\n    for (int i = 0; i < (int) edges.size();\
    \ ++i) {\n        auto [a, b] = edges[i];\n        G[a].push_back({b, i});\n \
    \       G[b].push_back({a, i});\n        ++deg[a];\n        ++deg[b];\n    }\n\
    \    int s = 0;\n    int cnt = 0;\n    for (int i = 0; i < V; ++i) {\n       \
    \ if (deg[i] % 2) {\n            ++cnt;\n            s = i;\n        }\n    }\n\
    \    if (cnt != 0 && cnt != 2) return {};\n    std::vector<int> ret;\n    std::stack<int>\
    \ st;\n    st.push(s);\n    std::vector<bool> used(edges.size());\n    while (!st.empty())\
    \ {\n        int u = st.top();\n        while (!G[u].empty() && used[G[u].back().second])\
    \ G[u].pop_back();\n        if (G[u].empty()) {\n            ret.push_back(u);\n\
    \            st.pop();\n        } else {\n            auto [v, i] = G[u].back();\n\
    \            G[u].pop_back();\n            used[i] = true;\n            st.emplace(v);\n\
    \        }\n    }\n    return ret;\n}\n#line 10 \"graph/bipartite_edge_coloring.hpp\"\
    \n\n\nstd::vector<int> bipartite_edge_coloring(const std::vector<std::pair<int,\
    \ int>>& G, int n, int m) {\n    // find the maximum degree\n    std::vector<int>\
    \ deg0(n), deg1(m);\n    for (auto [a, b] : G) {\n        ++deg0[a];\n       \
    \ ++deg1[b];\n    }\n    const int D = std::max(*max_element(deg0.begin(), deg0.end()),\
    \ *max_element(deg1.begin(), deg1.end()));\n\n    // convert to D-regular bipartite\
    \ graph\n    // merge vertices with the sum of degrees <= D\n    auto contract\
    \ = [&](const auto& deg) {\n        using P = std::pair<int, int>;\n        const\
    \ int n = deg.size();\n        std::priority_queue<P, std::vector<P>, std::greater<>>\
    \ pq;\n        for (int i = 0; i < n; ++i) {\n            pq.emplace(deg[i], i);\n\
    \        }\n        UnionFind uf(deg.size());\n        while (pq.size() > 1) {\n\
    \            auto [p, i] = pq.top();\n            pq.pop();\n            auto\
    \ [q, j] = pq.top();\n            pq.pop();\n            if (p + q > D) break;\n\
    \            uf.unite(i, j);\n            pq.emplace(p + q, i);\n        }\n \
    \       // rename vertices\n        int k = 0;\n        std::vector<int> id(n);\n\
    \        for (int i = 0; i < n; ++i) {\n            if (uf.find(i) == i) id[i]\
    \ = k++;\n        }\n        std::vector<int> ndeg(k);\n        for (int i = 0;\
    \ i < n; ++i) {\n            id[i] = id[uf.find(i)];\n            ndeg[id[i]]\
    \ += deg[i];\n        }\n        return std::make_pair(id, ndeg);\n    };\n\n\
    \    auto [id0, ndeg0] = contract(deg0);\n    auto [id1, ndeg1] = contract(deg1);\n\
    \n    // add dummy vertices\n    const int n2 = std::max(ndeg0.size(), ndeg1.size());\n\
    \    ndeg0.resize(n2);\n    ndeg1.resize(n2);\n\n    // rename edges and add dummy\
    \ edges\n    std::vector<std::pair<int, int>> G2;\n    for (auto [a, b] : G) {\n\
    \        a = id0[a];\n        b = id1[b];\n        G2.emplace_back(a, b);\n  \
    \  }\n    int j = 0;\n    for (int i = 0; i < n2; ++i) {\n        while (ndeg0[i]\
    \ < D) {\n            while (ndeg1[j] == D) ++j;\n            G2.emplace_back(i,\
    \ j);\n            ++ndeg0[i];\n            ++ndeg1[j];\n        }\n    }\n\n\
    \    // find the edge coloring\n    std::map<std::pair<int, int>, std::vector<int>>\
    \ color;\n    int k = 0;\n\n    auto rec = [&](auto& rec, const std::vector<std::pair<int,\
    \ int>>& G, int D) -> void {\n        if (D == 1) {\n            for (auto& e\
    \ : G) {\n                color[e].push_back(k);\n            }\n            ++k;\n\
    \            return;\n        } else if (D % 2 == 0) {\n            // find an\
    \ eulerian trail for each connected component\n            // partition the graph\
    \ into two and recurse\n            std::vector<std::vector<int>> H(n2 + n2);\n\
    \            for (auto [a, b] : G) {\n                H[a].push_back(n2 + b);\n\
    \                H[n2 + b].push_back(a);\n            }\n            std::vector<int>\
    \ idx(n2 + n2, -1), invidx(n2 + n2, -1), prevv(n2 + n2, -1);\n            std::vector<std::vector<std::pair<int,\
    \ int>>> G2(2);\n            for (int i = 0; i < n2; ++i) {\n                if\
    \ (idx[i] != -1) continue;\n                // find the connected component\n\
    \                std::stack<int> st;\n                st.push(i);\n          \
    \      int k = 0;\n                idx[i] = k;\n                invidx[k] = i;\n\
    \                ++k;\n                std::vector<std::pair<int, int>> edges2;\n\
    \                while (!st.empty()) {\n                    int u = st.top();\n\
    \                    st.pop();\n                    for (int v : H[u]) {\n   \
    \                     if (idx[v] == -1) {\n                            idx[v]\
    \ = k;\n                            invidx[k] = v;\n                         \
    \   prevv[v] = u;\n                            ++k;\n                        \
    \    edges2.emplace_back(idx[u], idx[v]);\n                            st.push(v);\n\
    \                        } else if (prevv[u] != v && idx[u] < idx[v]) {\n    \
    \                        edges2.emplace_back(idx[u], idx[v]);\n              \
    \          }\n                    }\n                }\n                // get\
    \ an eulerian path and partition it into two\n                auto path = eulerian_path(edges2,\
    \ k);\n                for (int i = 0; i < (int) path.size() - 1; ++i) {\n   \
    \                 int u = invidx[path[i]], v = invidx[path[i + 1]];\n        \
    \            if (u > v) std::swap(u, v);\n                    v -= n2;\n     \
    \               G2[i % 2].emplace_back(u, v);\n                }\n           \
    \ }\n            rec(rec, G2[0], D / 2);\n            rec(rec, G2[1], D / 2);\n\
    \        } else {\n            // paint the edges in a perfect matching with the\
    \ same color\n            BipartiteMatching bm(n2, n2);\n            for (auto\
    \ [a, b] : G) {\n                bm.add_edge(a, b);\n            }\n         \
    \   std::vector<int> match(n2, -1);\n            for (auto [a, b] : bm.max_matching())\
    \ {\n                match[a] = b;\n            }\n            std::vector<std::pair<int,\
    \ int>> G2;\n            for (auto [a, b] : G) {\n                if (match[a]\
    \ == b) {\n                    color[{a, b}].push_back(k);\n                 \
    \   match[a] = -1;\n                } else {\n                    G2.emplace_back(a,\
    \ b);\n                }\n            }\n            ++k;\n            rec(rec,\
    \ G2, D - 1);\n        }\n    };\n\n    rec(rec, G2, D);\n\n    // get colors\
    \ for edges in the original graph\n    std::vector<int> ans(G.size());\n    for\
    \ (int i = 0; i < (int) G.size(); ++i) {\n        auto [a, b] = G[i];\n      \
    \  std::pair<int, int> e(id0[a], id1[b]);\n        ans[i] = color[e].back();\n\
    \        color[e].pop_back();\n    }\n\n    return ans;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <queue>\n#include\
    \ <utility>\n#include <vector>\n#include \"../data-structure/unionfind/union_find.cpp\"\
    \n#include \"../graph/bipartite_matching.hpp\"\n#include \"../graph/eulerian_path.hpp\"\
    \n\n\nstd::vector<int> bipartite_edge_coloring(const std::vector<std::pair<int,\
    \ int>>& G, int n, int m) {\n    // find the maximum degree\n    std::vector<int>\
    \ deg0(n), deg1(m);\n    for (auto [a, b] : G) {\n        ++deg0[a];\n       \
    \ ++deg1[b];\n    }\n    const int D = std::max(*max_element(deg0.begin(), deg0.end()),\
    \ *max_element(deg1.begin(), deg1.end()));\n\n    // convert to D-regular bipartite\
    \ graph\n    // merge vertices with the sum of degrees <= D\n    auto contract\
    \ = [&](const auto& deg) {\n        using P = std::pair<int, int>;\n        const\
    \ int n = deg.size();\n        std::priority_queue<P, std::vector<P>, std::greater<>>\
    \ pq;\n        for (int i = 0; i < n; ++i) {\n            pq.emplace(deg[i], i);\n\
    \        }\n        UnionFind uf(deg.size());\n        while (pq.size() > 1) {\n\
    \            auto [p, i] = pq.top();\n            pq.pop();\n            auto\
    \ [q, j] = pq.top();\n            pq.pop();\n            if (p + q > D) break;\n\
    \            uf.unite(i, j);\n            pq.emplace(p + q, i);\n        }\n \
    \       // rename vertices\n        int k = 0;\n        std::vector<int> id(n);\n\
    \        for (int i = 0; i < n; ++i) {\n            if (uf.find(i) == i) id[i]\
    \ = k++;\n        }\n        std::vector<int> ndeg(k);\n        for (int i = 0;\
    \ i < n; ++i) {\n            id[i] = id[uf.find(i)];\n            ndeg[id[i]]\
    \ += deg[i];\n        }\n        return std::make_pair(id, ndeg);\n    };\n\n\
    \    auto [id0, ndeg0] = contract(deg0);\n    auto [id1, ndeg1] = contract(deg1);\n\
    \n    // add dummy vertices\n    const int n2 = std::max(ndeg0.size(), ndeg1.size());\n\
    \    ndeg0.resize(n2);\n    ndeg1.resize(n2);\n\n    // rename edges and add dummy\
    \ edges\n    std::vector<std::pair<int, int>> G2;\n    for (auto [a, b] : G) {\n\
    \        a = id0[a];\n        b = id1[b];\n        G2.emplace_back(a, b);\n  \
    \  }\n    int j = 0;\n    for (int i = 0; i < n2; ++i) {\n        while (ndeg0[i]\
    \ < D) {\n            while (ndeg1[j] == D) ++j;\n            G2.emplace_back(i,\
    \ j);\n            ++ndeg0[i];\n            ++ndeg1[j];\n        }\n    }\n\n\
    \    // find the edge coloring\n    std::map<std::pair<int, int>, std::vector<int>>\
    \ color;\n    int k = 0;\n\n    auto rec = [&](auto& rec, const std::vector<std::pair<int,\
    \ int>>& G, int D) -> void {\n        if (D == 1) {\n            for (auto& e\
    \ : G) {\n                color[e].push_back(k);\n            }\n            ++k;\n\
    \            return;\n        } else if (D % 2 == 0) {\n            // find an\
    \ eulerian trail for each connected component\n            // partition the graph\
    \ into two and recurse\n            std::vector<std::vector<int>> H(n2 + n2);\n\
    \            for (auto [a, b] : G) {\n                H[a].push_back(n2 + b);\n\
    \                H[n2 + b].push_back(a);\n            }\n            std::vector<int>\
    \ idx(n2 + n2, -1), invidx(n2 + n2, -1), prevv(n2 + n2, -1);\n            std::vector<std::vector<std::pair<int,\
    \ int>>> G2(2);\n            for (int i = 0; i < n2; ++i) {\n                if\
    \ (idx[i] != -1) continue;\n                // find the connected component\n\
    \                std::stack<int> st;\n                st.push(i);\n          \
    \      int k = 0;\n                idx[i] = k;\n                invidx[k] = i;\n\
    \                ++k;\n                std::vector<std::pair<int, int>> edges2;\n\
    \                while (!st.empty()) {\n                    int u = st.top();\n\
    \                    st.pop();\n                    for (int v : H[u]) {\n   \
    \                     if (idx[v] == -1) {\n                            idx[v]\
    \ = k;\n                            invidx[k] = v;\n                         \
    \   prevv[v] = u;\n                            ++k;\n                        \
    \    edges2.emplace_back(idx[u], idx[v]);\n                            st.push(v);\n\
    \                        } else if (prevv[u] != v && idx[u] < idx[v]) {\n    \
    \                        edges2.emplace_back(idx[u], idx[v]);\n              \
    \          }\n                    }\n                }\n                // get\
    \ an eulerian path and partition it into two\n                auto path = eulerian_path(edges2,\
    \ k);\n                for (int i = 0; i < (int) path.size() - 1; ++i) {\n   \
    \                 int u = invidx[path[i]], v = invidx[path[i + 1]];\n        \
    \            if (u > v) std::swap(u, v);\n                    v -= n2;\n     \
    \               G2[i % 2].emplace_back(u, v);\n                }\n           \
    \ }\n            rec(rec, G2[0], D / 2);\n            rec(rec, G2[1], D / 2);\n\
    \        } else {\n            // paint the edges in a perfect matching with the\
    \ same color\n            BipartiteMatching bm(n2, n2);\n            for (auto\
    \ [a, b] : G) {\n                bm.add_edge(a, b);\n            }\n         \
    \   std::vector<int> match(n2, -1);\n            for (auto [a, b] : bm.max_matching())\
    \ {\n                match[a] = b;\n            }\n            std::vector<std::pair<int,\
    \ int>> G2;\n            for (auto [a, b] : G) {\n                if (match[a]\
    \ == b) {\n                    color[{a, b}].push_back(k);\n                 \
    \   match[a] = -1;\n                } else {\n                    G2.emplace_back(a,\
    \ b);\n                }\n            }\n            ++k;\n            rec(rec,\
    \ G2, D - 1);\n        }\n    };\n\n    rec(rec, G2, D);\n\n    // get colors\
    \ for edges in the original graph\n    std::vector<int> ans(G.size());\n    for\
    \ (int i = 0; i < (int) G.size(); ++i) {\n        auto [a, b] = G[i];\n      \
    \  std::pair<int, int> e(id0[a], id1[b]);\n        ans[i] = color[e].back();\n\
    \        color[e].pop_back();\n    }\n\n    return ans;\n}\n"
  dependsOn:
  - data-structure/unionfind/union_find.cpp
  - graph/bipartite_matching.hpp
  - graph/eulerian_path.hpp
  isVerificationFile: false
  path: graph/bipartite_edge_coloring.hpp
  requiredBy: []
  timestamp: '2022-10-31 15:58:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/bipartite_edge_coloring.test.cpp
documentation_of: graph/bipartite_edge_coloring.hpp
layout: document
title: Bipartite Edge Coloring
---

## Description

二部グラフの辺彩色を求める．

Kőnig's Line Coloring Theorem によると，二部グラフ $G$ の頂点の最大次数を $D$ とすると，$G$ は必ず $D$ 色で辺彩色可能である．

## Operations

- `vector<int> bipartite_edge_coloring(vector<pair<int, int>> G, int n, int m)`
    - 頂点数が $(n, m)$ の二部グラフ $G$ の最小辺彩色における各辺の色を返す
    - 時間計算量: $O(E\sqrt{V}\log D)$

## Reference

- [辺彩色 - slideshare](https://www.slideshare.net/catupper/ss-25736611)
- [二部グラフの辺彩色 - ei1333の日記](https://ei1333.hateblo.jp/entry/2020/08/25/015955)
