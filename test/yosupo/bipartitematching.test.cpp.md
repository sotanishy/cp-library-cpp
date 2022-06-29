---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/hopcroft_karp.hpp
    title: Hopcroft-Karp Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "#line 1 \"test/yosupo/bipartitematching.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n#line 2 \"flow/hopcroft_karp.hpp\"\
    \n#include <limits>\n#include <queue>\n#include <utility>\n#include <vector>\n\
    \n\nclass HopcroftKarp {\npublic:\n    HopcroftKarp() = default;\n    HopcroftKarp(int\
    \ U, int V) : U(U), V(V), NIL(U + V), G(U), level(U + V + 1), match(U + V + 1,\
    \ NIL) {}\n\n    void add_edge(int u, int v) {\n        G[u].emplace_back(U +\
    \ v);\n    }\n\n    std::vector<std::pair<int, int>> bipartite_matching() {\n\
    \        while (bfs()) {\n            for (int u = 0; u < U; ++u) {\n        \
    \        if (match[u] == NIL) {\n                    dfs(u);\n               \
    \ }\n            }\n        }\n        std::vector<std::pair<int, int>> ret;\n\
    \        for (int u = 0; u < U; ++u) {\n            if (match[u] != NIL) ret.emplace_back(u,\
    \ match[u] - U);\n        }\n        return ret;\n    }\n\nprivate:\n    static\
    \ constexpr int INF = std::numeric_limits<int>::max() / 2;\n\n    const int U,\
    \ V, NIL;\n    std::vector<std::vector<int>> G;\n    std::vector<int> level, match;\n\
    \n    bool bfs() {\n        std::fill(level.begin(), level.end(), INF);\n    \
    \    std::queue<int> q;\n        for (int u = 0; u < U; ++u) {\n            if\
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
    \  }\n};\n#line 4 \"test/yosupo/bipartitematching.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int L, R, M;\n    cin >> L >> R >> M;\n    HopcroftKarp\
    \ hk(L, R);\n    for (int i = 0; i < M; ++i) {\n        int a, b;\n        cin\
    \ >> a >> b;\n        hk.add_edge(a, b);\n    }\n    auto ans = hk.bipartite_matching();\n\
    \    cout << ans.size() << \"\\n\";\n    for (auto [c, d] : ans) cout << c <<\
    \ \" \" << d << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"../../flow/hopcroft_karp.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int L, R, M;\n    cin >> L >> R >> M;\n    HopcroftKarp hk(L, R);\n    for\
    \ (int i = 0; i < M; ++i) {\n        int a, b;\n        cin >> a >> b;\n     \
    \   hk.add_edge(a, b);\n    }\n    auto ans = hk.bipartite_matching();\n    cout\
    \ << ans.size() << \"\\n\";\n    for (auto [c, d] : ans) cout << c << \" \" <<\
    \ d << \"\\n\";\n}"
  dependsOn:
  - flow/hopcroft_karp.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2022-06-29 12:22:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
