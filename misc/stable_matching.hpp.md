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
  bundledCode: "#line 2 \"misc/stable_matching.hpp\"\n#include <stack>\n#include <vector>\n\
    \nstd::vector<int> stable_matching(const std::vector<std::vector<int>>& man, const\
    \ std::vector<std::vector<int>>& woman) {\n    const int n = man.size();\n   \
    \ // the smaller the better\n    std::vector<std::vector<int>> preference(n, std::vector<int>(n));\n\
    \    for (int j = 0; j < n; ++j) {\n        for (int k = 0; k < n; ++k) {\n  \
    \          preference[j][woman[j][k]] = k;\n        }\n    }\n    std::vector<int>\
    \ idx(n);\n    std::vector<int> engaged(n, -1);\n    std::stack<int> st;\n   \
    \ for (int i = 0; i < n; ++i) st.push(i);\n    while (!st.empty()) {\n       \
    \ int i = st.top();\n        int j = man[i][idx[i]++];\n        if (engaged[j]\
    \ == -1 || preference[j][i] < preference[j][engaged[j]]) {\n            st.pop();\n\
    \            if (engaged[j] != -1) st.push(engaged[j]);\n            engaged[j]\
    \ = i;\n        }\n    }\n    return engaged;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <vector>\n\nstd::vector<int> stable_matching(const\
    \ std::vector<std::vector<int>>& man, const std::vector<std::vector<int>>& woman)\
    \ {\n    const int n = man.size();\n    // the smaller the better\n    std::vector<std::vector<int>>\
    \ preference(n, std::vector<int>(n));\n    for (int j = 0; j < n; ++j) {\n   \
    \     for (int k = 0; k < n; ++k) {\n            preference[j][woman[j][k]] =\
    \ k;\n        }\n    }\n    std::vector<int> idx(n);\n    std::vector<int> engaged(n,\
    \ -1);\n    std::stack<int> st;\n    for (int i = 0; i < n; ++i) st.push(i);\n\
    \    while (!st.empty()) {\n        int i = st.top();\n        int j = man[i][idx[i]++];\n\
    \        if (engaged[j] == -1 || preference[j][i] < preference[j][engaged[j]])\
    \ {\n            st.pop();\n            if (engaged[j] != -1) st.push(engaged[j]);\n\
    \            engaged[j] = i;\n        }\n    }\n    return engaged;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/stable_matching.hpp
  requiredBy: []
  timestamp: '2022-05-05 23:09:02+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/stable_matching.hpp
layout: document
redirect_from:
- /library/misc/stable_matching.hpp
- /library/misc/stable_matching.hpp.html
title: misc/stable_matching.hpp
---
