---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: dp/lis.hpp
    title: Longest Increasing Subsequence
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_increasing_subsequence
    links:
    - https://judge.yosupo.jp/problem/longest_increasing_subsequence
  bundledCode: "#line 1 \"test/yosupo/longest_increasing_subsequence.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#line 2 \"dp/lis.hpp\"\n#include <algorithm>\n#include <limits>\n#include\
    \ <vector>\n\n/**\n * @brief Longest Increasing Subsequence\n */\n\ntemplate <typename\
    \ T>\nint longest_increasing_subsequence(const std::vector<T>& v, bool strict)\
    \ {\n    constexpr T INF = std::numeric_limits<T>::max();\n    std::vector<T>\
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
    \    return {res, idx};\n}\n#line 4 \"test/yosupo/longest_increasing_subsequence.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for\
    \ (auto& x : A) cin >> x;\n    auto [K, idx] = longest_increasing_subsequence_with_index(A,\
    \ true);\n    cout << K << endl;\n    for (int i = 0; i < K; ++i) cout << idx[i]\
    \ << (i < K-1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_increasing_subsequence\"\
    \n\n#include \"../../dp/lis.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int N;\n    cin >> N;\n    vector<int> A(N);\n    for (auto& x : A) cin\
    \ >> x;\n    auto [K, idx] = longest_increasing_subsequence_with_index(A, true);\n\
    \    cout << K << endl;\n    for (int i = 0; i < K; ++i) cout << idx[i] << (i\
    \ < K-1 ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - dp/lis.hpp
  isVerificationFile: true
  path: test/yosupo/longest_increasing_subsequence.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/longest_increasing_subsequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/longest_increasing_subsequence.test.cpp
- /verify/test/yosupo/longest_increasing_subsequence.test.cpp.html
title: test/yosupo/longest_increasing_subsequence.test.cpp
---
