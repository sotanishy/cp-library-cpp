---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.cpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#line 2 \"graph/scc.cpp\"\n#include <algorithm>\n#include <vector>\n\nstd::vector<int>\
    \ scc(const std::vector<std::vector<int>>& G) {\n    const int n = G.size();\n\
    \    std::vector<std::vector<int>> G_rev(n);\n    for (int u = 0; u < n; ++u)\
    \ {\n        for (int v : G[u]) G_rev[v].push_back(u);\n    }\n    std::vector<int>\
    \ comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\n    auto dfs =\
    \ [&](const auto& self, int u) -> void {\n        if (visited[u]) return;\n  \
    \      visited[u] = true;\n        for (int v : G[u]) self(self, v);\n       \
    \ order.push_back(u);\n    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs, v);\n\
    \    std::reverse(order.begin(), order.end());\n    int c = 0;\n\n    auto rdfs\
    \ = [&](const auto& self, int u, int c) -> void {\n        if (comp[u] != -1)\
    \ return;\n        comp[u] = c;\n        for (int v : G_rev[u]) self(self, v,\
    \ c);\n    };\n\n    for (int v : order) if (comp[v] == -1) rdfs(rdfs, v, c++);\n\
    \    return comp;\n}\n\nstd::vector<std::vector<int>> contract(const std::vector<std::vector<int>>&\
    \ G, const std::vector<int>& comp) {\n    const int n = *max_element(comp.begin(),\
    \ comp.end()) + 1;\n    std::vector<std::vector<int>> G2(n);\n    for (int i =\
    \ 0; i < (int) G.size(); ++i) {\n        for (int j : G[i]) {\n            if\
    \ (comp[i] != comp[j]) {\n                G2[comp[i]].push_back(comp[j]);\n  \
    \          }\n        }\n    }\n    for (int i = 0; i < n; ++i) {\n        std::sort(G2[i].begin(),\
    \ G2[i].end());\n        G2[i].erase(std::unique(G2[i].begin(), G2[i].end()),\
    \ G2[i].end());\n    }\n    return G2;\n}\n#line 4 \"test/yosupo/scc.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> G(N);\n    for (int\
    \ i = 0; i < M; ++i) {\n        int a, b;\n        cin >> a >> b;\n        G[a].push_back(b);\n\
    \    }\n    auto comp = scc(G);\n    int n = *max_element(comp.begin(), comp.end())\
    \ + 1;\n    vector<vector<int>> comps(n);\n    for (int i = 0; i < N; ++i) comps[comp[i]].push_back(i);\n\
    \    cout << n << \"\\n\";\n    for (int i = 0; i < n; ++i) {\n        cout <<\
    \ comps[i].size();\n        for (int v : comps[i]) cout << \" \" << v;\n     \
    \   cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../graph/scc.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> G(N);\n    for (int\
    \ i = 0; i < M; ++i) {\n        int a, b;\n        cin >> a >> b;\n        G[a].push_back(b);\n\
    \    }\n    auto comp = scc(G);\n    int n = *max_element(comp.begin(), comp.end())\
    \ + 1;\n    vector<vector<int>> comps(n);\n    for (int i = 0; i < N; ++i) comps[comp[i]].push_back(i);\n\
    \    cout << n << \"\\n\";\n    for (int i = 0; i < n; ++i) {\n        cout <<\
    \ comps[i].size();\n        for (int v : comps[i]) cout << \" \" << v;\n     \
    \   cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - graph/scc.cpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2021-10-07 13:18:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
