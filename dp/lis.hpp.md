---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/longest_increasing_subsequence.test.cpp
    title: test/yosupo/longest_increasing_subsequence.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Longest Increasing Subsequence
    links: []
  bundledCode: "#line 2 \"dp/lis.hpp\"\n#include <algorithm>\n#include <limits>\n\
    #include <vector>\n\n/**\n * @brief Longest Increasing Subsequence\n */\n\ntemplate\
    \ <typename T>\nint longest_increasing_subsequence(const std::vector<T>& v, bool\
    \ strict) {\n    constexpr T INF = std::numeric_limits<T>::max();\n    std::vector<T>\
    \ dp(v.size() + 1, INF);\n    dp[0] = -INF;\n    for (auto& x : v) {\n       \
    \ int k;\n        if (strict) {\n            k = std::ranges::lower_bound(dp,\
    \ x) - dp.begin();\n        } else {\n            k = std::ranges::upper_bound(dp,\
    \ x) - dp.begin();\n        }\n        dp[k] = x;\n    }\n    return std::ranges::lower_bound(dp,\
    \ INF) - dp.begin();\n}\n\ntemplate <typename T>\nstd::pair<int, std::vector<int>>\
    \ longest_increasing_subsequence_with_index(\n    const std::vector<T>& v, bool\
    \ strict) {\n    constexpr T INF = std::numeric_limits<T>::max();\n    const int\
    \ n = v.size();\n    std::vector<T> dp(n + 1, INF);\n    std::vector<int> len(n);\n\
    \    dp[0] = -INF;\n    for (int i = 0; i < n; ++i) {\n        T x = v[i];\n \
    \       int k;\n        if (strict) {\n            k = std::ranges::lower_bound(dp,\
    \ x) - dp.begin();\n        } else {\n            k = std::ranges::upper_bound(dp,\
    \ x) - dp.begin();\n        }\n        dp[k] = x;\n        len[i] = k;\n    }\n\
    \n    int res = *std::ranges::max_element(len);\n    int k = res;\n    std::vector<int>\
    \ idx;\n    for (int i = n - 1; i >= 0; --i) {\n        if (len[i] == k) {\n \
    \           idx.push_back(i);\n            --k;\n        }\n    }\n    std::ranges::reverse(idx);\n\
    \    return {res, idx};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <vector>\n\
    \n/**\n * @brief Longest Increasing Subsequence\n */\n\ntemplate <typename T>\n\
    int longest_increasing_subsequence(const std::vector<T>& v, bool strict) {\n \
    \   constexpr T INF = std::numeric_limits<T>::max();\n    std::vector<T> dp(v.size()\
    \ + 1, INF);\n    dp[0] = -INF;\n    for (auto& x : v) {\n        int k;\n   \
    \     if (strict) {\n            k = std::ranges::lower_bound(dp, x) - dp.begin();\n\
    \        } else {\n            k = std::ranges::upper_bound(dp, x) - dp.begin();\n\
    \        }\n        dp[k] = x;\n    }\n    return std::ranges::lower_bound(dp,\
    \ INF) - dp.begin();\n}\n\ntemplate <typename T>\nstd::pair<int, std::vector<int>>\
    \ longest_increasing_subsequence_with_index(\n    const std::vector<T>& v, bool\
    \ strict) {\n    constexpr T INF = std::numeric_limits<T>::max();\n    const int\
    \ n = v.size();\n    std::vector<T> dp(n + 1, INF);\n    std::vector<int> len(n);\n\
    \    dp[0] = -INF;\n    for (int i = 0; i < n; ++i) {\n        T x = v[i];\n \
    \       int k;\n        if (strict) {\n            k = std::ranges::lower_bound(dp,\
    \ x) - dp.begin();\n        } else {\n            k = std::ranges::upper_bound(dp,\
    \ x) - dp.begin();\n        }\n        dp[k] = x;\n        len[i] = k;\n    }\n\
    \n    int res = *std::ranges::max_element(len);\n    int k = res;\n    std::vector<int>\
    \ idx;\n    for (int i = n - 1; i >= 0; --i) {\n        if (len[i] == k) {\n \
    \           idx.push_back(i);\n            --k;\n        }\n    }\n    std::ranges::reverse(idx);\n\
    \    return {res, idx};\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/lis.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/longest_increasing_subsequence.test.cpp
documentation_of: dp/lis.hpp
layout: document
redirect_from:
- /library/dp/lis.hpp
- /library/dp/lis.hpp.html
title: Longest Increasing Subsequence
---
