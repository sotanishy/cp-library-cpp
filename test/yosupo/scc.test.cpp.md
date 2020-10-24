---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.cpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo/scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#line 2 \"graph/scc.cpp\"\n#include <algorithm>\n#include <vector>\n\n/*\n\
    \ * @brief Strongly Connected Components\n * @docs docs/graph/scc.md\n */\nclass\
    \ SCC {\npublic:\n    SCC() = default;\n    explicit SCC(int n) : G(n), G_rev(n),\
    \ comp(n, -1), visited(n) {}\n\n    void add_edge(int u, int v) {\n        G[u].push_back(v);\n\
    \        G_rev[v].push_back(u);\n    }\n\n    void build() {\n        for (int\
    \ v = 0; v < (int) G.size(); ++v) dfs(v);\n        std::reverse(order.begin(),\
    \ order.end());\n        cnt = 0;\n        for (int v : order) if (comp[v] ==\
    \ -1) rdfs(v, cnt++);\n    }\n\n    int operator[](int i) const {\n        return\
    \ comp[i];\n    }\n\n    int count() const noexcept {\n        return cnt;\n \
    \   }\n\nprivate:\n    std::vector<std::vector<int>> G, G_rev;\n    std::vector<int>\
    \ comp, order;\n    std::vector<bool> visited;\n    int cnt;\n\n    void dfs(int\
    \ u) {\n        if (visited[u]) return;\n        visited[u] = true;\n        for\
    \ (int v : G[u]) dfs(v);\n        order.push_back(u);\n    }\n\n    void rdfs(int\
    \ u, int c) {\n        if (comp[u] != -1) return;\n        comp[u] = c;\n    \
    \    for (int v : G_rev[u]) rdfs(v, c);\n    }\n};\n\n/*\nstd::vector<int> scc_decomposition(const\
    \ std::vector<std::vector<int>>& G) {\n    const int n = G.size();\n    std::vector<std::vector<int>>\
    \ G_rev(n);\n    for (int u = 0; u < n; ++u) {\n        for (int v : G[u]) G_rev[v].push_back(u);\n\
    \    }\n    std::vector<int> comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\
    \n    auto dfs = [&](const auto& self, int u) -> void {\n        if (visited[u])\
    \ return;\n        visited[u] = true;\n        for (int v : G[u]) self(self, v);\n\
    \        order.push_back(v);\n    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs,\
    \ v);\n    std::reverse(order.begin(), order.end());\n    int c = 0;\n\n    auto\
    \ rdfs = [&](const auto& self, int u, int c) -> void {\n        if (comp[u] !=\
    \ -1) return;\n        comp[u] = c;\n        for (int v : G_rev[u]) self(self,\
    \ v, c);\n    }\n\n    for (int v : order) if (comp[v] == -1) rdfs(rdfs, v, c++);\n\
    \    return comp;\n}\n*/\n#line 4 \"test/yosupo/scc.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    SCC scc(N);\n\
    \    for (int i = 0; i < M; ++i) {\n        int a, b;\n        cin >> a >> b;\n\
    \        scc.add_edge(a, b);\n    }\n    scc.build();\n    vector<vector<int>>\
    \ comps(scc.count());\n    for (int i = 0; i < N; ++i) comps[scc[i]].push_back(i);\n\
    \    cout << comps.size() << \"\\n\";\n    for (int i = 0; i < comps.size(); ++i)\
    \ {\n        cout << comps[i].size();\n        for (int v : comps[i]) cout <<\
    \ \" \" << v;\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../graph/scc.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int N, M;\n    cin >> N >> M;\n    SCC scc(N);\n    for (int i = 0; i < M;\
    \ ++i) {\n        int a, b;\n        cin >> a >> b;\n        scc.add_edge(a, b);\n\
    \    }\n    scc.build();\n    vector<vector<int>> comps(scc.count());\n    for\
    \ (int i = 0; i < N; ++i) comps[scc[i]].push_back(i);\n    cout << comps.size()\
    \ << \"\\n\";\n    for (int i = 0; i < comps.size(); ++i) {\n        cout << comps[i].size();\n\
    \        for (int v : comps[i]) cout << \" \" << v;\n        cout << \"\\n\";\n\
    \    }\n}\n"
  dependsOn:
  - graph/scc.cpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 20:53:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
