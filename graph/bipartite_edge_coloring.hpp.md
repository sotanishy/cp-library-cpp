---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/bipartite_matching.hpp
    title: Bipartite Matching
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
    #include <bit>\n#include <map>\n#include <stack>\n#include <utility>\n#include\
    \ <vector>\n\n#line 3 \"graph/bipartite_matching.hpp\"\n#include <limits>\n#include\
    \ <queue>\n#line 7 \"graph/bipartite_matching.hpp\"\n\nclass BipartiteMatching\
    \ {\n   public:\n    BipartiteMatching() = default;\n    BipartiteMatching(int\
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
    \        }\n        return false;\n    }\n};\n#line 10 \"graph/bipartite_edge_coloring.hpp\"\
    \n\nstd::vector<int> bipartite_edge_coloring(\n    const std::vector<std::pair<int,\
    \ int>>& edges, int n1, int n2) {\n    const int E = edges.size();\n    // find\
    \ the maximum degree D\n    std::vector<int> deg1(n1), deg2(n2);\n    for (auto\
    \ [a, b] : edges) {\n        ++deg1[a], ++deg2[b];\n    }\n    const int D = std::max(*std::ranges::max_element(deg1),\n\
    \                           *std::ranges::max_element(deg2));\n\n    // convert\
    \ to D-regular bipartite graph\n    // merge vertices with the sum of degrees\
    \ <= D\n    auto contract = [&](const auto& deg) {\n        const int n = deg.size();\n\
    \        std::vector<std::pair<int, int>> vs(n);\n        for (int i = 0; i <\
    \ n; ++i) vs[i] = {deg[i], i};\n        std::ranges::sort(vs);\n\n        std::vector<int>\
    \ id(n);\n        std::vector<int> ndeg;\n\n        int k = 0;\n        for (int\
    \ i = 0; i < n;) {\n            int d = 0;\n            int j = i;\n         \
    \   while (j < n && d + vs[j].first <= D) {\n                d += vs[j].first;\n\
    \                id[vs[j].second] = k;\n                ++j;\n            }\n\
    \            ndeg.push_back(d);\n            ++k;\n            i = j;\n      \
    \  }\n\n        return std::make_pair(id, ndeg);\n    };\n\n    auto [id1, ndeg1]\
    \ = contract(deg1);\n    auto [id2, ndeg2] = contract(deg2);\n\n    using Edge\
    \ = std::tuple<int, int, int>;\n    std::vector<Edge> edges2;\n    for (int i\
    \ = 0; i < E; ++i) {\n        auto [a, b] = edges[i];\n        edges2.emplace_back(id1[a],\
    \ id2[b], i);\n    }\n\n    // add dummy vertices\n    const int n = std::max(ndeg1.size(),\
    \ ndeg2.size());\n    ndeg1.resize(n);\n    ndeg2.resize(n);\n\n    // add dummy\
    \ edges\n    int j = 0;\n    int nE = E;\n    for (int i = 0; i < n; ++i) {\n\
    \        while (ndeg1[i] < D) {\n            while (ndeg2[j] == D) ++j;\n    \
    \        edges2.emplace_back(i, j, nE++);\n            ++ndeg1[i];\n         \
    \   ++ndeg2[j];\n        }\n    }\n\n    // find the edge coloring\n    std::vector<int>\
    \ color(nE);\n    int k = 0;\n\n    auto rec = [&](auto& rec, const std::vector<Edge>&\
    \ edges, int D) -> void {\n        if (D == 1) {\n            for (auto [a, b,\
    \ i] : edges) {\n                color[i] = k;\n            }\n            ++k;\n\
    \            return;\n        } else if (D % 2 == 0) {\n            // find an\
    \ eulerian walk for each connected component\n            // partition the graph\
    \ into two\n            std::vector<std::vector<std::pair<int, int>>> G(2 * n);\n\
    \            for (int j = 0; j < (int)edges.size(); ++j) {\n                auto\
    \ [a, b, i] = edges[j];\n                G[a].emplace_back(n + b, j);\n      \
    \          G[n + b].emplace_back(a, j);\n            }\n            std::vector<bool>\
    \ used_v(2 * n), used_e(edges.size());\n            std::vector<std::vector<Edge>>\
    \ edges2(2);\n\n            for (int v = 0; v < n; ++v) {\n                if\
    \ (used_v[v]) continue;\n\n                std::vector<int> walk;\n          \
    \      std::stack<std::pair<int, int>> st;\n                st.emplace(v, -1);\n\
    \                while (!st.empty()) {\n                    auto [u, j] = st.top();\n\
    \                    used_v[u] = true;\n                    while (!G[u].empty()\
    \ && used_e[G[u].back().second]) {\n                        G[u].pop_back();\n\
    \                    }\n                    if (G[u].empty()) {\n            \
    \            walk.push_back(j);\n                        st.pop();\n         \
    \           } else {\n                        auto [v, k] = G[u].back();\n   \
    \                     G[u].pop_back();\n                        used_e[k] = true;\n\
    \                        st.emplace(v, k);\n                    }\n          \
    \      }\n\n                for (int i = 0; i < (int)walk.size() - 1; ++i) {\n\
    \                    edges2[i % 2].push_back(edges[walk[i]]);\n              \
    \  }\n            }\n            rec(rec, edges2[0], D / 2);\n\n            int\
    \ nD = std::bit_ceil((unsigned int)(D / 2));\n\n            // add nD-D/2 edges\
    \ from edges2[0] to edges2[1]\n            for (auto [a, b, i] : edges2[0]) {\n\
    \                if (color[i] >= k - (nD - D / 2)) {\n                    edges2[1].emplace_back(a,\
    \ b, i);\n                }\n            }\n            k -= nD - D / 2;\n\n \
    \           rec(rec, edges2[1], nD);\n        } else {\n            // paint the\
    \ edges in a perfect matching with the same color\n            BipartiteMatching\
    \ bm(n, n);\n            for (auto [a, b, i] : edges) {\n                bm.add_edge(a,\
    \ b);\n            }\n            std::vector<int> match(n, -1);\n           \
    \ for (auto [a, b] : bm.max_matching()) {\n                match[a] = b;\n   \
    \         }\n            std::vector<Edge> edges2;\n            for (auto [a,\
    \ b, i] : edges) {\n                if (match[a] == b) {\n                   \
    \ color[i] = k;\n                    match[a] = -1;\n                } else {\n\
    \                    edges2.emplace_back(a, b, i);\n                }\n      \
    \      }\n            ++k;\n            rec(rec, edges2, D - 1);\n        }\n\
    \    };\n\n    rec(rec, edges2, D);\n    color.resize(E);\n    return color;\n\
    }\n\nstd::vector<std::pair<int, int>> regular_bipartite_matching(\n    const std::vector<std::pair<int,\
    \ int>>& edges, int D) {\n    const int n = edges.size() / D;\n\n    auto rec\
    \ = [&](auto& rec, const auto& edges, int D) {\n        if (D == 1) {\n      \
    \      return edges;\n        } else if (D % 2 == 0) {\n            // find an\
    \ eulerian walk for each connected component\n            // partition the graph\
    \ into two\n            std::vector<std::vector<std::pair<int, int>>> G(2 * n);\n\
    \            for (int j = 0; j < (int)edges.size(); ++j) {\n                auto\
    \ [a, b, d] = edges[j];\n                G[a].emplace_back(n + b, j);\n      \
    \          G[n + b].emplace_back(a, j);\n            }\n            std::vector<bool>\
    \ used_v(2 * n), used_e(edges.size());\n            std::vector<std::vector<std::tuple<int,\
    \ int, bool>>> edges2(2);\n            std::vector<int> dummy_cnt(2);\n\n    \
    \        for (int v = 0; v < n; ++v) {\n                if (used_v[v]) continue;\n\
    \n                std::vector<int> walk;\n                std::stack<std::pair<int,\
    \ int>> st;\n                st.emplace(v, -1);\n                while (!st.empty())\
    \ {\n                    auto [u, j] = st.top();\n                    used_v[u]\
    \ = true;\n                    while (!G[u].empty() && used_e[G[u].back().second])\
    \ {\n                        G[u].pop_back();\n                    }\n       \
    \             if (G[u].empty()) {\n                        walk.push_back(j);\n\
    \                        st.pop();\n                    } else {\n           \
    \             auto [v, k] = G[u].back();\n                        G[u].pop_back();\n\
    \                        used_e[k] = true;\n                        st.emplace(v,\
    \ k);\n                    }\n                }\n\n                for (int i\
    \ = 0; i < (int)walk.size() - 1; ++i) {\n                    edges2[i % 2].push_back(edges[walk[i]]);\n\
    \                    dummy_cnt[i % 2] += std::get<2>(edges[walk[i]]);\n      \
    \          }\n            }\n            return rec(rec, dummy_cnt[0] < dummy_cnt[1]\
    \ ? edges2[0] : edges2[1],\n                       D / 2);\n        } else {\n\
    \            int size = std::bit_ceil((unsigned int)D);\n\n            // add\
    \ size-D dummy edges\n            auto edges2 = edges;\n            for (int i\
    \ = 0; i < n; ++i) {\n                for (int j = 0; j < size - D; ++j) {\n \
    \                   edges2.emplace_back(i, i, true);\n                }\n    \
    \        }\n\n            while (true) {\n                auto res = rec(rec,\
    \ edges2, size);\n                int cnt = 0;\n                for (auto [a,\
    \ b, d] : res) {\n                    cnt += d;\n                }\n         \
    \       if (cnt == 0) return res;\n                // add res size-D times\n \
    \               edges2 = edges;\n                for (auto [a, b, d] : res) {\n\
    \                    for (int j = 0; j < size - D; ++j) {\n                  \
    \      edges2.emplace_back(a, b, d);\n                    }\n                }\n\
    \            }\n        }\n    };\n\n    std::vector<std::tuple<int, int, bool>>\
    \ edges2;\n    for (auto [a, b] : edges) {\n        edges2.emplace_back(a, b,\
    \ false);\n    }\n    auto res = rec(rec, edges2, D);\n    std::vector<std::pair<int,\
    \ int>> ret;\n    for (auto [a, b, d] : res) {\n        ret.emplace_back(a, b);\n\
    \    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <map>\n#include\
    \ <stack>\n#include <utility>\n#include <vector>\n\n#include \"../graph/bipartite_matching.hpp\"\
    \n\nstd::vector<int> bipartite_edge_coloring(\n    const std::vector<std::pair<int,\
    \ int>>& edges, int n1, int n2) {\n    const int E = edges.size();\n    // find\
    \ the maximum degree D\n    std::vector<int> deg1(n1), deg2(n2);\n    for (auto\
    \ [a, b] : edges) {\n        ++deg1[a], ++deg2[b];\n    }\n    const int D = std::max(*std::ranges::max_element(deg1),\n\
    \                           *std::ranges::max_element(deg2));\n\n    // convert\
    \ to D-regular bipartite graph\n    // merge vertices with the sum of degrees\
    \ <= D\n    auto contract = [&](const auto& deg) {\n        const int n = deg.size();\n\
    \        std::vector<std::pair<int, int>> vs(n);\n        for (int i = 0; i <\
    \ n; ++i) vs[i] = {deg[i], i};\n        std::ranges::sort(vs);\n\n        std::vector<int>\
    \ id(n);\n        std::vector<int> ndeg;\n\n        int k = 0;\n        for (int\
    \ i = 0; i < n;) {\n            int d = 0;\n            int j = i;\n         \
    \   while (j < n && d + vs[j].first <= D) {\n                d += vs[j].first;\n\
    \                id[vs[j].second] = k;\n                ++j;\n            }\n\
    \            ndeg.push_back(d);\n            ++k;\n            i = j;\n      \
    \  }\n\n        return std::make_pair(id, ndeg);\n    };\n\n    auto [id1, ndeg1]\
    \ = contract(deg1);\n    auto [id2, ndeg2] = contract(deg2);\n\n    using Edge\
    \ = std::tuple<int, int, int>;\n    std::vector<Edge> edges2;\n    for (int i\
    \ = 0; i < E; ++i) {\n        auto [a, b] = edges[i];\n        edges2.emplace_back(id1[a],\
    \ id2[b], i);\n    }\n\n    // add dummy vertices\n    const int n = std::max(ndeg1.size(),\
    \ ndeg2.size());\n    ndeg1.resize(n);\n    ndeg2.resize(n);\n\n    // add dummy\
    \ edges\n    int j = 0;\n    int nE = E;\n    for (int i = 0; i < n; ++i) {\n\
    \        while (ndeg1[i] < D) {\n            while (ndeg2[j] == D) ++j;\n    \
    \        edges2.emplace_back(i, j, nE++);\n            ++ndeg1[i];\n         \
    \   ++ndeg2[j];\n        }\n    }\n\n    // find the edge coloring\n    std::vector<int>\
    \ color(nE);\n    int k = 0;\n\n    auto rec = [&](auto& rec, const std::vector<Edge>&\
    \ edges, int D) -> void {\n        if (D == 1) {\n            for (auto [a, b,\
    \ i] : edges) {\n                color[i] = k;\n            }\n            ++k;\n\
    \            return;\n        } else if (D % 2 == 0) {\n            // find an\
    \ eulerian walk for each connected component\n            // partition the graph\
    \ into two\n            std::vector<std::vector<std::pair<int, int>>> G(2 * n);\n\
    \            for (int j = 0; j < (int)edges.size(); ++j) {\n                auto\
    \ [a, b, i] = edges[j];\n                G[a].emplace_back(n + b, j);\n      \
    \          G[n + b].emplace_back(a, j);\n            }\n            std::vector<bool>\
    \ used_v(2 * n), used_e(edges.size());\n            std::vector<std::vector<Edge>>\
    \ edges2(2);\n\n            for (int v = 0; v < n; ++v) {\n                if\
    \ (used_v[v]) continue;\n\n                std::vector<int> walk;\n          \
    \      std::stack<std::pair<int, int>> st;\n                st.emplace(v, -1);\n\
    \                while (!st.empty()) {\n                    auto [u, j] = st.top();\n\
    \                    used_v[u] = true;\n                    while (!G[u].empty()\
    \ && used_e[G[u].back().second]) {\n                        G[u].pop_back();\n\
    \                    }\n                    if (G[u].empty()) {\n            \
    \            walk.push_back(j);\n                        st.pop();\n         \
    \           } else {\n                        auto [v, k] = G[u].back();\n   \
    \                     G[u].pop_back();\n                        used_e[k] = true;\n\
    \                        st.emplace(v, k);\n                    }\n          \
    \      }\n\n                for (int i = 0; i < (int)walk.size() - 1; ++i) {\n\
    \                    edges2[i % 2].push_back(edges[walk[i]]);\n              \
    \  }\n            }\n            rec(rec, edges2[0], D / 2);\n\n            int\
    \ nD = std::bit_ceil((unsigned int)(D / 2));\n\n            // add nD-D/2 edges\
    \ from edges2[0] to edges2[1]\n            for (auto [a, b, i] : edges2[0]) {\n\
    \                if (color[i] >= k - (nD - D / 2)) {\n                    edges2[1].emplace_back(a,\
    \ b, i);\n                }\n            }\n            k -= nD - D / 2;\n\n \
    \           rec(rec, edges2[1], nD);\n        } else {\n            // paint the\
    \ edges in a perfect matching with the same color\n            BipartiteMatching\
    \ bm(n, n);\n            for (auto [a, b, i] : edges) {\n                bm.add_edge(a,\
    \ b);\n            }\n            std::vector<int> match(n, -1);\n           \
    \ for (auto [a, b] : bm.max_matching()) {\n                match[a] = b;\n   \
    \         }\n            std::vector<Edge> edges2;\n            for (auto [a,\
    \ b, i] : edges) {\n                if (match[a] == b) {\n                   \
    \ color[i] = k;\n                    match[a] = -1;\n                } else {\n\
    \                    edges2.emplace_back(a, b, i);\n                }\n      \
    \      }\n            ++k;\n            rec(rec, edges2, D - 1);\n        }\n\
    \    };\n\n    rec(rec, edges2, D);\n    color.resize(E);\n    return color;\n\
    }\n\nstd::vector<std::pair<int, int>> regular_bipartite_matching(\n    const std::vector<std::pair<int,\
    \ int>>& edges, int D) {\n    const int n = edges.size() / D;\n\n    auto rec\
    \ = [&](auto& rec, const auto& edges, int D) {\n        if (D == 1) {\n      \
    \      return edges;\n        } else if (D % 2 == 0) {\n            // find an\
    \ eulerian walk for each connected component\n            // partition the graph\
    \ into two\n            std::vector<std::vector<std::pair<int, int>>> G(2 * n);\n\
    \            for (int j = 0; j < (int)edges.size(); ++j) {\n                auto\
    \ [a, b, d] = edges[j];\n                G[a].emplace_back(n + b, j);\n      \
    \          G[n + b].emplace_back(a, j);\n            }\n            std::vector<bool>\
    \ used_v(2 * n), used_e(edges.size());\n            std::vector<std::vector<std::tuple<int,\
    \ int, bool>>> edges2(2);\n            std::vector<int> dummy_cnt(2);\n\n    \
    \        for (int v = 0; v < n; ++v) {\n                if (used_v[v]) continue;\n\
    \n                std::vector<int> walk;\n                std::stack<std::pair<int,\
    \ int>> st;\n                st.emplace(v, -1);\n                while (!st.empty())\
    \ {\n                    auto [u, j] = st.top();\n                    used_v[u]\
    \ = true;\n                    while (!G[u].empty() && used_e[G[u].back().second])\
    \ {\n                        G[u].pop_back();\n                    }\n       \
    \             if (G[u].empty()) {\n                        walk.push_back(j);\n\
    \                        st.pop();\n                    } else {\n           \
    \             auto [v, k] = G[u].back();\n                        G[u].pop_back();\n\
    \                        used_e[k] = true;\n                        st.emplace(v,\
    \ k);\n                    }\n                }\n\n                for (int i\
    \ = 0; i < (int)walk.size() - 1; ++i) {\n                    edges2[i % 2].push_back(edges[walk[i]]);\n\
    \                    dummy_cnt[i % 2] += std::get<2>(edges[walk[i]]);\n      \
    \          }\n            }\n            return rec(rec, dummy_cnt[0] < dummy_cnt[1]\
    \ ? edges2[0] : edges2[1],\n                       D / 2);\n        } else {\n\
    \            int size = std::bit_ceil((unsigned int)D);\n\n            // add\
    \ size-D dummy edges\n            auto edges2 = edges;\n            for (int i\
    \ = 0; i < n; ++i) {\n                for (int j = 0; j < size - D; ++j) {\n \
    \                   edges2.emplace_back(i, i, true);\n                }\n    \
    \        }\n\n            while (true) {\n                auto res = rec(rec,\
    \ edges2, size);\n                int cnt = 0;\n                for (auto [a,\
    \ b, d] : res) {\n                    cnt += d;\n                }\n         \
    \       if (cnt == 0) return res;\n                // add res size-D times\n \
    \               edges2 = edges;\n                for (auto [a, b, d] : res) {\n\
    \                    for (int j = 0; j < size - D; ++j) {\n                  \
    \      edges2.emplace_back(a, b, d);\n                    }\n                }\n\
    \            }\n        }\n    };\n\n    std::vector<std::tuple<int, int, bool>>\
    \ edges2;\n    for (auto [a, b] : edges) {\n        edges2.emplace_back(a, b,\
    \ false);\n    }\n    auto res = rec(rec, edges2, D);\n    std::vector<std::pair<int,\
    \ int>> ret;\n    for (auto [a, b, d] : res) {\n        ret.emplace_back(a, b);\n\
    \    }\n    return ret;\n}"
  dependsOn:
  - graph/bipartite_matching.hpp
  isVerificationFile: false
  path: graph/bipartite_edge_coloring.hpp
  requiredBy: []
  timestamp: '2024-01-08 14:54:00+09:00'
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
    - 時間計算量: $O(E\sqrt{V} + E\log D)$

## Note

計算量解析あってるかわからん．

正則二部グラフの完全マッチングを $O(E\log V)$ 時間で求めるアルゴリズムを用いれば，時間計算量を $O(E\log E)$ に改善できる．ただし，実測では普通に Hopcroft-Karp をやったほうが速かった．アルゴリズムについては，参考文献 (Twitter) を参照．

## Reference

- [辺彩色 - slideshare](https://www.slideshare.net/catupper/ss-25736611)
- [二部グラフの辺彩色 - ei1333の日記](https://ei1333.hateblo.jp/entry/2020/08/25/015955)
- [https://twitter.com/snuke_/status/1246630370415538176](https://twitter.com/snuke_/status/1246630370415538176)
- [Noga Alon の二部グラフの辺彩色 - 37zigenのHP](https://37zigen.com/noga-alon-edge-coloring-bipartite/)