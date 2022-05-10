---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Longest Increasing Subsequence
    links: []
  bundledCode: "#line 2 \"dp/lis.hpp\"\n#include <algorithm>\n#include <numeric>\n\
    #include <vector>\n\n/**\n * @brief Longest Increasing Subsequence\n */\ntemplate\
    \ <typename T>\nint longest_increasing_subsequence(const std::vector<T>& v, bool\
    \ strict) {\n    constexpr T INF = std::numeric_limits<T>::max();\n    std::vector<T>\
    \ dp(v.size() + 1, INF);\n    dp[0] = -INF;\n    for (auto& x : v) {\n       \
    \ int k;\n        if (strict) {\n            k = std::lower_bound(dp.begin(),\
    \ dp.end(), x) - dp.begin();\n        } else {\n            k = std::upper_bound(dp.begin(),\
    \ dp.end(), x) - dp.begin();\n        }\n        dp[k] = x;\n    }\n    return\
    \ std::lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    \n/**\n * @brief Longest Increasing Subsequence\n */\ntemplate <typename T>\n\
    int longest_increasing_subsequence(const std::vector<T>& v, bool strict) {\n \
    \   constexpr T INF = std::numeric_limits<T>::max();\n    std::vector<T> dp(v.size()\
    \ + 1, INF);\n    dp[0] = -INF;\n    for (auto& x : v) {\n        int k;\n   \
    \     if (strict) {\n            k = std::lower_bound(dp.begin(), dp.end(), x)\
    \ - dp.begin();\n        } else {\n            k = std::upper_bound(dp.begin(),\
    \ dp.end(), x) - dp.begin();\n        }\n        dp[k] = x;\n    }\n    return\
    \ std::lower_bound(dp.begin(), dp.end(), INF) - dp.begin();\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/lis.hpp
  requiredBy: []
  timestamp: '2022-05-10 23:59:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/lis.hpp
layout: document
redirect_from:
- /library/dp/lis.hpp
- /library/dp/lis.hpp.html
title: Longest Increasing Subsequence
---
