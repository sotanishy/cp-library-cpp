---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.hpp
    title: Lowlink
  - icon: ':heavy_check_mark:'
    path: graph/two_edge_connected_components.hpp
    title: 2-Edge-Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #line 2 \"graph/lowlink.hpp\"\n#include <algorithm>\n#include <utility>\n#include\
    \ <vector>\n\nclass Lowlink {\n   public:\n    std::vector<int> ord, low;\n  \
    \  std::vector<std::pair<int, int>> bridge;\n    std::vector<int> articulation;\n\
    \n    Lowlink() = default;\n    explicit Lowlink(const std::vector<std::vector<int>>&\
    \ G)\n        : ord(G.size(), -1), low(G.size()), G(G) {\n        for (int i =\
    \ 0; i < (int)G.size(); ++i) {\n            if (ord[i] == -1) dfs(i, -1);\n  \
    \      }\n    }\n\n    bool is_bridge(int u, int v) const {\n        if (ord[u]\
    \ > ord[v]) std::swap(u, v);\n        return ord[u] < low[v];\n    }\n\n   private:\n\
    \    std::vector<std::vector<int>> G;\n    int k = 0;\n\n    void dfs(int v, int\
    \ p) {\n        low[v] = ord[v] = k++;\n        bool is_articulation = false,\
    \ checked = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n     \
    \       if (c == p && !checked) {\n                checked = true;\n         \
    \       continue;\n            }\n            if (ord[c] == -1) {\n          \
    \      ++cnt;\n                dfs(c, v);\n                low[v] = std::min(low[v],\
    \ low[c]);\n                if (p != -1 && ord[v] <= low[c]) is_articulation =\
    \ true;\n                if (ord[v] < low[c]) bridge.push_back(std::minmax(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 4 \"\
    graph/two_edge_connected_components.hpp\"\n\n#line 6 \"graph/two_edge_connected_components.hpp\"\
    \n\nstd::vector<int> two_edge_connected_components(\n    const std::vector<std::vector<int>>&\
    \ G, const Lowlink& low) {\n    int k = 0;\n    std::vector<int> comp(G.size(),\
    \ -1);\n\n    auto dfs = [&](const auto& dfs, int u) -> void {\n        comp[u]\
    \ = k;\n        for (int v : G[u]) {\n            if (comp[v] == -1 && !low.is_bridge(u,\
    \ v)) dfs(dfs, v);\n        }\n    };\n\n    for (int v = 0; v < (int)G.size();\
    \ ++v) {\n        if (comp[v] == -1) {\n            dfs(dfs, v);\n           \
    \ ++k;\n        }\n    }\n    return comp;\n}\n\nstd::vector<std::vector<int>>\
    \ contract(const std::vector<std::vector<int>>& G,\n                         \
    \              const std::vector<int>& comp) {\n    const int n = *std::ranges::max_element(comp)\
    \ + 1;\n    std::vector<std::vector<int>> G2(n);\n    for (int i = 0; i < (int)G.size();\
    \ ++i) {\n        for (int j : G[i]) {\n            if (comp[i] != comp[j]) {\n\
    \                G2[comp[i]].push_back(comp[j]);\n            }\n        }\n \
    \   }\n    for (int i = 0; i < n; ++i) {\n        std::ranges::sort(G2[i]);\n\
    \        G2[i].erase(std::ranges::unique(G2[i]).begin(), G2[i].end());\n    }\n\
    \    return G2;\n}\n#line 5 \"test/yosupo/two_edge_connected_components.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < M; ++i) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n    }\n   \
    \ Lowlink low(G);\n    auto comp = two_edge_connected_components(G, low);\n  \
    \  vector<vector<int>> ans(*max_element(comp.begin(), comp.end()) + 1);\n    for\
    \ (int i = 0; i < N; ++i) ans[comp[i]].push_back(i);\n    cout << ans.size() <<\
    \ \"\\n\";\n    for (auto& v : ans) {\n        cout << v.size();\n        for\
    \ (int u : v) cout << \" \" << u;\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../../graph/lowlink.hpp\"\n#include \"../../graph/two_edge_connected_components.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < M; ++i) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n    }\n   \
    \ Lowlink low(G);\n    auto comp = two_edge_connected_components(G, low);\n  \
    \  vector<vector<int>> ans(*max_element(comp.begin(), comp.end()) + 1);\n    for\
    \ (int i = 0; i < N; ++i) ans[comp[i]].push_back(i);\n    cout << ans.size() <<\
    \ \"\\n\";\n    for (auto& v : ans) {\n        cout << v.size();\n        for\
    \ (int u : v) cout << \" \" << u;\n        cout << \"\\n\";\n    }\n}"
  dependsOn:
  - graph/lowlink.hpp
  - graph/two_edge_connected_components.hpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2025-02-21 23:59:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
