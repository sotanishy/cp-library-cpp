---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Largest Rectangle
    links: []
  bundledCode: "#line 2 \"dp/largest_rectangle.hpp\"\n#include <algorithm>\n#include\
    \ <stack>\n#include <utility>\n#include <vector>\n\n/**\n * @brief Largest Rectangle\n\
    \ */\ntemplate <typename T>\nT largest_rectangle(const std::vector<T>& h) {\n\
    \    int n = h.size();\n    std::vector<int> left(n), right(n);\n    std::stack<std::pair<T,\
    \ int>> st;\n    st.emplace(-1, -1);\n    for (int i = 0; i < n; ++i) {\n    \
    \    while (st.top().first >= h[i]) st.pop();\n        left[i] = st.top().second\
    \ + 1;\n        st.emplace(h[i], i);\n    }\n    while (!st.empty()) st.pop();\n\
    \    st.emplace(-1, n);\n    for (int i = n - 1; i >= 0; --i) {\n        while\
    \ (st.top().first >= h[i]) st.pop();\n        right[i] = st.top().second;\n  \
    \      st.emplace(h[i], i);\n    }\n    T ret = 0;\n    for (int i = 0; i < n;\
    \ ++i)\n        ret = std::max(ret, h[i] * (right[i] - left[i]));\n    return\
    \ ret;\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief Largest Rectangle\n */\ntemplate <typename\
    \ T>\nT largest_rectangle(const std::vector<T>& h) {\n    int n = h.size();\n\
    \    std::vector<int> left(n), right(n);\n    std::stack<std::pair<T, int>> st;\n\
    \    st.emplace(-1, -1);\n    for (int i = 0; i < n; ++i) {\n        while (st.top().first\
    \ >= h[i]) st.pop();\n        left[i] = st.top().second + 1;\n        st.emplace(h[i],\
    \ i);\n    }\n    while (!st.empty()) st.pop();\n    st.emplace(-1, n);\n    for\
    \ (int i = n - 1; i >= 0; --i) {\n        while (st.top().first >= h[i]) st.pop();\n\
    \        right[i] = st.top().second;\n        st.emplace(h[i], i);\n    }\n  \
    \  T ret = 0;\n    for (int i = 0; i < n; ++i)\n        ret = std::max(ret, h[i]\
    \ * (right[i] - left[i]));\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/largest_rectangle.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/largest_rectangle.hpp
layout: document
redirect_from:
- /library/dp/largest_rectangle.hpp
- /library/dp/largest_rectangle.hpp.html
title: Largest Rectangle
---
