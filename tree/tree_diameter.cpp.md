---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/tree_diameter.md
    document_title: Diameter of a Tree
    links: []
  bundledCode: "#line 1 \"tree/tree_diameter.cpp\"\n#include <bits/stdc++.h>\n#line\
    \ 2 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from,\
    \ to;\n    T weight;\n    Edge(int to, T weight) : from(-1), to(to), weight(weight)\
    \ {}\n    Edge(int from, int to, T weight) : from(from), to(to), weight(weight)\
    \ {}\n};\n#line 3 \"tree/tree_diameter.cpp\"\n\n/*\n * @brief Diameter of a Tree\n\
    \ * @docs docs/tree/tree_diameter.md\n */\nclass TreeDiameter {\npublic:\n   \
    \ TreeDiameter() = delete;\n\n    static int diameter(const std::vector<std::vector<int>>&\
    \ G) {\n        auto p = dfs(G, 0, -1);\n        auto q = dfs(G, p.second, -1);\n\
    \        return q.first;\n    }\n\n    template <typename T>\n    static T diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n        auto p = dfs(G, 0, -1);\n \
    \       auto q = dfs(G, p.second, -1);\n        return q.first;\n    }\n\nprivate:\n\
    \    static std::pair<int, int> dfs(const std::vector<std::vector<int>>& G, int\
    \ v, int p) {\n        std::pair<int, int> ret(0, v);\n        for (int c : G[v])\
    \ {\n            if (c == p) continue;\n            auto weight = dfs(G, c, v);\n\
    \            ++weight.first;\n            ret = std::max(ret, weight);\n     \
    \   }\n        return ret;\n    }\n\n    template <typename T>\n    static std::pair<T,\
    \ int> dfs(const std::vector<std::vector<Edge<T>>>& G, int v, int p) {\n     \
    \   std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n           \
    \ if (e.to == p) continue;\n            auto weight = dfs(G, e.to, v);\n     \
    \       weight.first += e.weight;\n            ret = std::max(ret, weight);\n\
    \        }\n        return ret;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n#include \"../graph/edge.cpp\"\n\n/*\n * @brief\
    \ Diameter of a Tree\n * @docs docs/tree/tree_diameter.md\n */\nclass TreeDiameter\
    \ {\npublic:\n    TreeDiameter() = delete;\n\n    static int diameter(const std::vector<std::vector<int>>&\
    \ G) {\n        auto p = dfs(G, 0, -1);\n        auto q = dfs(G, p.second, -1);\n\
    \        return q.first;\n    }\n\n    template <typename T>\n    static T diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n        auto p = dfs(G, 0, -1);\n \
    \       auto q = dfs(G, p.second, -1);\n        return q.first;\n    }\n\nprivate:\n\
    \    static std::pair<int, int> dfs(const std::vector<std::vector<int>>& G, int\
    \ v, int p) {\n        std::pair<int, int> ret(0, v);\n        for (int c : G[v])\
    \ {\n            if (c == p) continue;\n            auto weight = dfs(G, c, v);\n\
    \            ++weight.first;\n            ret = std::max(ret, weight);\n     \
    \   }\n        return ret;\n    }\n\n    template <typename T>\n    static std::pair<T,\
    \ int> dfs(const std::vector<std::vector<Edge<T>>>& G, int v, int p) {\n     \
    \   std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n           \
    \ if (e.to == p) continue;\n            auto weight = dfs(G, e.to, v);\n     \
    \       weight.first += e.weight;\n            ret = std::max(ret, weight);\n\
    \        }\n        return ret;\n    }\n};"
  dependsOn:
  - graph/edge.cpp
  isVerificationFile: false
  path: tree/tree_diameter.cpp
  requiredBy: []
  timestamp: '2020-10-03 00:05:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_A.test.cpp
documentation_of: tree/tree_diameter.cpp
layout: document
redirect_from:
- /library/tree/tree_diameter.cpp
- /library/tree/tree_diameter.cpp.html
title: Diameter of a Tree
---
# Diameter of a Tree

DFSを用いて木の直径を求める．

## Member functions

- `static int diameter(vector<vector<int>> G)`
    - $G$ の辺の重みをすべて1として直径を求める
    - 時間計算量: $O(n)$
- `static T diameter(vector<vector<Edge<T>>> G)`
    - $G$ の直径を求める
    - 時間計算量: $O(n)$