---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/lowlink.cpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/two_edge_connected_components.md
    document_title: Two-Edge-Connected Components
    links: []
  bundledCode: "#line 1 \"graph/two_edge_connected_components.cpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"graph/lowlink.cpp\"\n\n/*\n * @brief Lowlink\n * @docs docs/graph/lowlink.md\n\
    \ */\nclass Lowlink {\npublic:\n    Lowlink() = default;\n    explicit Lowlink(const\
    \ std::vector<std::vector<int>> G) : G(G), ord(G.size(), -1), low(G.size()) {\n\
    \        for (int i = 0; i < (int) G.size(); ++i) {\n            if (ord[i] ==\
    \ -1) dfs(i, -1);\n        }\n    }\n\n    std::vector<std::pair<int, int>> get_bridges()\
    \ const {\n        return bridge;\n    }\n\n    std::vector<int> get_articulation_points()\
    \ const {\n        return articulation;\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> ord, low;\n    std::vector<std::pair<int, int>> bridge;\n\
    \    std::vector<int> articulation;\n    int k = 0;\n\n    void dfs(int v, int\
    \ p) {\n        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n            if\
    \ (ord[c] == -1) {\n                ++cnt;\n                dfs(c, v);\n     \
    \           low[v] = std::min(low[v], low[c]);\n                if (p != -1 &&\
    \ ord[v] <= low[c]) is_articulation = true;\n                if (ord[v] < low[c])\
    \ bridge.emplace_back(std::min(v, c), std::max(v, c));\n            } else if\
    \ (c != p) {\n                low[v] = std::min(low[v], ord[c]);\n           \
    \ }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n    \
    \    if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 3 \"graph/two_edge_connected_components.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\n/*\n * @brief Two-Edge-Connected\
    \ Components\n * @docs docs/graph/two_edge_connected_components.md\n */\nclass\
    \ TwoEdgeConnectedComponents {\npublic:\n    TwoEdgeConnectedComponents() = default;\n\
    \    explicit TwoEdgeConnectedComponents(const std::vector<std::vector<int>>&\
    \ G)\n        : G(G), lowlink(G) {\n\n\n    }\n\nprivate:\n    vector<vector<int>>\
    \ G;\n    Lowlink lowlink;\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"lowlink.cpp\"\nusing namespace std;\n\
    using ll = long long;\n\n/*\n * @brief Two-Edge-Connected Components\n * @docs\
    \ docs/graph/two_edge_connected_components.md\n */\nclass TwoEdgeConnectedComponents\
    \ {\npublic:\n    TwoEdgeConnectedComponents() = default;\n    explicit TwoEdgeConnectedComponents(const\
    \ std::vector<std::vector<int>>& G)\n        : G(G), lowlink(G) {\n\n\n    }\n\
    \nprivate:\n    vector<vector<int>> G;\n    Lowlink lowlink;\n};\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\n}"
  dependsOn:
  - graph/lowlink.cpp
  isVerificationFile: false
  path: graph/two_edge_connected_components.cpp
  requiredBy: []
  timestamp: '2020-10-08 11:27:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/two_edge_connected_components.cpp
layout: document
redirect_from:
- /library/graph/two_edge_connected_components.cpp
- /library/graph/two_edge_connected_components.cpp.html
title: Two-Edge-Connected Components
---
