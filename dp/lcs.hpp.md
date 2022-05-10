---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Longest Common Subsequence
    links: []
  bundledCode: "#line 2 \"dp/lcs.hpp\"\n#include <algorithm>\n#include <string>\n\
    #include <vector>\n\n/**\n * @brief Longest Common Subsequence\n */\nint longest_common_subsequence(const\
    \ std::string& s, const std::string& t) {\n    const int n = s.size(), m = t.size();\n\
    \    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));\n    for (int\
    \ i = 0; i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n            if\
    \ (s[i] == t[j]) {\n                dp[i+1][j+1] = dp[i][j] + 1;\n           \
    \ } else {\n                dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);\n\
    \            }\n        }\n    }\n    return dp[n][m];\n}\n\n"
  code: "#pragma once\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    \n/**\n * @brief Longest Common Subsequence\n */\nint longest_common_subsequence(const\
    \ std::string& s, const std::string& t) {\n    const int n = s.size(), m = t.size();\n\
    \    std::vector<std::vector<int>> dp(n+1, std::vector<int>(m+1));\n    for (int\
    \ i = 0; i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n            if\
    \ (s[i] == t[j]) {\n                dp[i+1][j+1] = dp[i][j] + 1;\n           \
    \ } else {\n                dp[i+1][j+1] = std::max(dp[i][j+1], dp[i+1][j]);\n\
    \            }\n        }\n    }\n    return dp[n][m];\n}\n\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/lcs.hpp
  requiredBy: []
  timestamp: '2022-05-10 23:59:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/lcs.hpp
layout: document
redirect_from:
- /library/dp/lcs.hpp
- /library/dp/lcs.hpp.html
title: Longest Common Subsequence
---
