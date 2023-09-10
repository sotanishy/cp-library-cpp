---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/complement_bfs.hpp\"\n#include <numeric>\n#include\
    \ <queue>\n#include <vector>\n\nstd::vector<int> complement_bfs(const std::vector<std::vector<int>>&\
    \ Gcomp,\n                                int s) {\n    std::vector<int> dist(Gcomp.size(),\
    \ -1);\n    dist[s] = 0;\n\n    std::vector<int> unvisited(Gcomp.size() - 1);\n\
    \    std::iota(unvisited.begin(), unvisited.end(), 1);\n\n    std::vector<bool>\
    \ not_neighbor(Gcomp.size());\n\n    std::queue<int> que;\n    que.push(s);\n\n\
    \    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \n        for (int u : Gcomp[v]) {\n            not_neighbor[u] = true;\n    \
    \    }\n\n        std::vector<int> nxt_unvisited;\n\n        for (int u : unvisited)\
    \ {\n            if (not_neighbor[u]) {\n                nxt_unvisited.push_back(u);\n\
    \            } else {\n                dist[u] = dist[v] + 1;\n              \
    \  que.push(u);\n            }\n        }\n\n        unvisited.swap(nxt_unvisited);\n\
    \n        for (int u : Gcomp[v]) {\n            not_neighbor[u] = false;\n   \
    \     }\n    }\n\n    return dist;\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <queue>\n#include <vector>\n\n\
    std::vector<int> complement_bfs(const std::vector<std::vector<int>>& Gcomp,\n\
    \                                int s) {\n    std::vector<int> dist(Gcomp.size(),\
    \ -1);\n    dist[s] = 0;\n\n    std::vector<int> unvisited(Gcomp.size() - 1);\n\
    \    std::iota(unvisited.begin(), unvisited.end(), 1);\n\n    std::vector<bool>\
    \ not_neighbor(Gcomp.size());\n\n    std::queue<int> que;\n    que.push(s);\n\n\
    \    while (!que.empty()) {\n        int v = que.front();\n        que.pop();\n\
    \n        for (int u : Gcomp[v]) {\n            not_neighbor[u] = true;\n    \
    \    }\n\n        std::vector<int> nxt_unvisited;\n\n        for (int u : unvisited)\
    \ {\n            if (not_neighbor[u]) {\n                nxt_unvisited.push_back(u);\n\
    \            } else {\n                dist[u] = dist[v] + 1;\n              \
    \  que.push(u);\n            }\n        }\n\n        unvisited.swap(nxt_unvisited);\n\
    \n        for (int u : Gcomp[v]) {\n            not_neighbor[u] = false;\n   \
    \     }\n    }\n\n    return dist;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/complement_bfs.hpp
  requiredBy: []
  timestamp: '2023-09-10 15:17:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/complement_bfs.hpp
layout: document
redirect_from:
- /library/graph/complement_bfs.hpp
- /library/graph/complement_bfs.hpp.html
title: graph/complement_bfs.hpp
---
