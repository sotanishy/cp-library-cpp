---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Pseudotree Cycle
    links: []
  bundledCode: "#line 2 \"graph/pseudotree_cycle.hpp\"\n#include <stack>\n#include\
    \ <vector>\n\n/**\n * @brief Pseudotree Cycle\n */\nstd::vector<int> pseudotree_cycle(const\
    \ std::vector<std::vector<int>>& G) {\n    const int n = G.size();\n    std::vector<int>\
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
  code: "#pragma once\n#include <stack>\n#include <vector>\n\n/**\n * @brief Pseudotree\
    \ Cycle\n */\nstd::vector<int> pseudotree_cycle(const std::vector<std::vector<int>>&\
    \ G) {\n    const int n = G.size();\n    std::vector<int> deg(n);\n    std::stack<int>\
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
  path: graph/pseudotree_cycle.hpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/pseudotree_cycle.hpp
layout: document
redirect_from:
- /library/graph/pseudotree_cycle.hpp
- /library/graph/pseudotree_cycle.hpp.html
title: Pseudotree Cycle
---
