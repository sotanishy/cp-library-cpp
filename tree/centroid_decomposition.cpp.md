---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Centroid Decomposition
    links: []
  bundledCode: "#line 2 \"tree/centroid_decomposition.cpp\"\n#include <vector>\n\n\
    /*\n * @brief Centroid Decomposition\n */\n\nint find_centroid(const std::vector<std::vector<int>>&\
    \ G, int r,\n                  const std::vector<bool>& dead) {\n    static std::vector<int>\
    \ sz(G.size());\n\n    auto dfs_size = [&](auto& dfs_size, int v, int p) -> int\
    \ {\n        sz[v] = 1;\n        for (int c : G[v]) {\n            if (c != p\
    \ && !dead[c]) sz[v] += dfs_size(dfs_size, c, v);\n        }\n        return sz[v];\n\
    \    };\n\n    int n = dfs_size(dfs_size, r, -1);\n\n    auto dfs = [&](auto&\
    \ dfs, int v, int p) -> int {\n        for (int c : G[v]) {\n            if (c\
    \ != p && !dead[c] && sz[c] > n / 2) return dfs(dfs, c, v);\n        }\n     \
    \   return v;\n    };\n\n    return dfs(dfs, r, -1);\n}\n\nvoid solve(const std::vector<std::vector<int>>&\
    \ G) {\n    int N = G.size();\n    std::vector<bool> dead(N);\n\n    // implement\
    \ here\n    auto calc = [&](int s) {};\n\n    auto decompose = [&](auto& decompose,\
    \ int v) -> void {\n        int s = find_centroid(G, v, dead);\n        dead[s]\
    \ = true;\n        calc(s);\n        for (int c : G[s]) {\n            if (!dead[c])\
    \ decompose(decompose, c);\n        }\n    };\n\n    decompose(decompose, 0);\n\
    }\n"
  code: "#pragma once\n#include <vector>\n\n/*\n * @brief Centroid Decomposition\n\
    \ */\n\nint find_centroid(const std::vector<std::vector<int>>& G, int r,\n   \
    \               const std::vector<bool>& dead) {\n    static std::vector<int>\
    \ sz(G.size());\n\n    auto dfs_size = [&](auto& dfs_size, int v, int p) -> int\
    \ {\n        sz[v] = 1;\n        for (int c : G[v]) {\n            if (c != p\
    \ && !dead[c]) sz[v] += dfs_size(dfs_size, c, v);\n        }\n        return sz[v];\n\
    \    };\n\n    int n = dfs_size(dfs_size, r, -1);\n\n    auto dfs = [&](auto&\
    \ dfs, int v, int p) -> int {\n        for (int c : G[v]) {\n            if (c\
    \ != p && !dead[c] && sz[c] > n / 2) return dfs(dfs, c, v);\n        }\n     \
    \   return v;\n    };\n\n    return dfs(dfs, r, -1);\n}\n\nvoid solve(const std::vector<std::vector<int>>&\
    \ G) {\n    int N = G.size();\n    std::vector<bool> dead(N);\n\n    // implement\
    \ here\n    auto calc = [&](int s) {};\n\n    auto decompose = [&](auto& decompose,\
    \ int v) -> void {\n        int s = find_centroid(G, v, dead);\n        dead[s]\
    \ = true;\n        calc(s);\n        for (int c : G[s]) {\n            if (!dead[c])\
    \ decompose(decompose, c);\n        }\n    };\n\n    decompose(decompose, 0);\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: tree/centroid_decomposition.cpp
  requiredBy: []
  timestamp: '2022-03-06 20:10:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: tree/centroid_decomposition.cpp
layout: document
redirect_from:
- /library/tree/centroid_decomposition.cpp
- /library/tree/centroid_decomposition.cpp.html
title: Centroid Decomposition
---
