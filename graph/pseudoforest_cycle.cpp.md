---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Pseudoforest Cycle
    links: []
  bundledCode: "#line 2 \"graph/pseudoforest_cycle.cpp\"\n#include <stack>\n#include\
    \ <vector>\n\n/**\n * @brief Pseudoforest Cycle\n */\nstd::vector<int> pseudoforest_cycle(const\
    \ std::vector<std::vector<int>>& G) {\n    int n = G.size();\n    std::vector<int>\
    \ deg(n);\n    std::stack<int> st;\n    for (int i = 0; i < n; ++i) {\n      \
    \  deg[i] = G[i].size();\n        if (deg[i] == 1) st.push(i);\n    }\n    while\
    \ (!st.empty()) {\n        int v = st.top();\n        st.pop();\n        deg[v]\
    \ = 0;\n        for (int u : G[v]) {\n            if (deg[u] == 0) continue;\n\
    \            --deg[u];\n            if (deg[u] == 1) {\n                st.push(u);\n\
    \            }\n        }\n    }\n    int v, p = -1;\n    for (int i = 0; i <\
    \ n; ++i) {\n        if (deg[i] == 2) {\n            v = i;\n            break;\n\
    \        }\n    }\n    std::vector<int> cycle;\n    do {\n        cycle.push_back(v);\n\
    \        for (int u : G[v]) {\n            if (u != p && deg[u] == 2) {\n    \
    \            p = v;\n                v = u;\n                break;\n        \
    \    }\n        }\n    } while (v != cycle[0]);\n    return cycle;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\n\n/**\n * @brief Pseudoforest\
    \ Cycle\n */\nstd::vector<int> pseudoforest_cycle(const std::vector<std::vector<int>>&\
    \ G) {\n    int n = G.size();\n    std::vector<int> deg(n);\n    std::stack<int>\
    \ st;\n    for (int i = 0; i < n; ++i) {\n        deg[i] = G[i].size();\n    \
    \    if (deg[i] == 1) st.push(i);\n    }\n    while (!st.empty()) {\n        int\
    \ v = st.top();\n        st.pop();\n        deg[v] = 0;\n        for (int u :\
    \ G[v]) {\n            if (deg[u] == 0) continue;\n            --deg[u];\n   \
    \         if (deg[u] == 1) {\n                st.push(u);\n            }\n   \
    \     }\n    }\n    int v, p = -1;\n    for (int i = 0; i < n; ++i) {\n      \
    \  if (deg[i] == 2) {\n            v = i;\n            break;\n        }\n   \
    \ }\n    std::vector<int> cycle;\n    do {\n        cycle.push_back(v);\n    \
    \    for (int u : G[v]) {\n            if (u != p && deg[u] == 2) {\n        \
    \        p = v;\n                v = u;\n                break;\n            }\n\
    \        }\n    } while (v != cycle[0]);\n    return cycle;\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/pseudoforest_cycle.cpp
  requiredBy: []
  timestamp: '2022-03-06 22:28:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/pseudoforest_cycle.cpp
layout: document
redirect_from:
- /library/graph/pseudoforest_cycle.cpp
- /library/graph/pseudoforest_cycle.cpp.html
title: Pseudoforest Cycle
---
