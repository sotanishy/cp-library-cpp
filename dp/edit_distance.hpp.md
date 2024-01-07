---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Edit Distance
    links: []
  bundledCode: "#line 2 \"dp/edit_distance.hpp\"\n#include <algorithm>\n#include <string>\n\
    #include <vector>\n\n/**\n * @brief Edit Distance\n */\nint edit_distance(const\
    \ std::string& s, const std::string& t) {\n    const int n = s.size(), m = t.size();\n\
    \    std::vector dp(n + 1, std::vector<int>(m + 1));\n    dp[0][0] = 0;\n    for\
    \ (int i = 1; i <= n; ++i) dp[i][0] = i;\n    for (int j = 1; j <= m; ++j) dp[0][j]\
    \ = j;\n    for (int i = 1; i <= n; ++i) {\n        for (int j = 1; j <= m; ++j)\
    \ {\n            dp[i][j] = std::min({\n                dp[i - 1][j] + 1,    \
    \                      // insert\n                dp[i][j - 1] + 1,          \
    \                // delete\n                dp[i - 1][j - 1] + (s[i - 1] != t[j\
    \ - 1])  // replace\n            });\n        }\n    }\n    return dp[n][m];\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <string>\n#include <vector>\n\
    \n/**\n * @brief Edit Distance\n */\nint edit_distance(const std::string& s, const\
    \ std::string& t) {\n    const int n = s.size(), m = t.size();\n    std::vector\
    \ dp(n + 1, std::vector<int>(m + 1));\n    dp[0][0] = 0;\n    for (int i = 1;\
    \ i <= n; ++i) dp[i][0] = i;\n    for (int j = 1; j <= m; ++j) dp[0][j] = j;\n\
    \    for (int i = 1; i <= n; ++i) {\n        for (int j = 1; j <= m; ++j) {\n\
    \            dp[i][j] = std::min({\n                dp[i - 1][j] + 1,        \
    \                  // insert\n                dp[i][j - 1] + 1,              \
    \            // delete\n                dp[i - 1][j - 1] + (s[i - 1] != t[j -\
    \ 1])  // replace\n            });\n        }\n    }\n    return dp[n][m];\n}"
  dependsOn: []
  isVerificationFile: false
  path: dp/edit_distance.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/edit_distance.hpp
layout: document
redirect_from:
- /library/dp/edit_distance.hpp
- /library/dp/edit_distance.hpp.html
title: Edit Distance
---
