---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Euler Tour
    links: []
  bundledCode: "#line 2 \"tree/euler_tour.hpp\"\n#include <vector>\n\n/**\n * @brief\
    \ Euler Tour\n */\nstd::pair<std::vector<int>, std::vector<int>> euler_tour(\n\
    \    const std::vector<std::vector<int>>& G, int root) {\n    std::vector<int>\
    \ in(G.size()), out(G.size());\n    int k = 0;\n\n    auto dfs = [&](auto& dfs,\
    \ int v, int p) -> void {\n        in[v] = k++;\n        for (int c : G[v])\n\
    \            if (c != p) dfs(dfs, c, v);\n        out[v] = k;\n    };\n\n    dfs(dfs,\
    \ root, -1);\n    return {in, out};\n}\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief Euler Tour\n */\nstd::pair<std::vector<int>,\
    \ std::vector<int>> euler_tour(\n    const std::vector<std::vector<int>>& G, int\
    \ root) {\n    std::vector<int> in(G.size()), out(G.size());\n    int k = 0;\n\
    \n    auto dfs = [&](auto& dfs, int v, int p) -> void {\n        in[v] = k++;\n\
    \        for (int c : G[v])\n            if (c != p) dfs(dfs, c, v);\n       \
    \ out[v] = k;\n    };\n\n    dfs(dfs, root, -1);\n    return {in, out};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/euler_tour.hpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
documentation_of: tree/euler_tour.hpp
layout: document
redirect_from:
- /library/tree/euler_tour.hpp
- /library/tree/euler_tour.hpp.html
title: Euler Tour
---
