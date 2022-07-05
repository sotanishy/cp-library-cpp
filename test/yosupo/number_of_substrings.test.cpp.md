---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: string/lcp_array.cpp
    title: Longest Common Prefix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_substrings
    links:
    - https://judge.yosupo.jp/problem/number_of_substrings
  bundledCode: "#line 1 \"test/yosupo/number_of_substrings.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\n#line 2 \"string/lcp_array.cpp\"\
    \n#include <string>\n#include <vector>\n\nstd::vector<int> lcp_array(const std::string&\
    \ s, const std::vector<int>& sa) {\n    int n = s.size();\n    std::vector<int>\
    \ rank(n);\n    for (int i = 0; i < n; ++i) rank[sa[i]] = i;\n    int h = 0;\n\
    \    std::vector<int> lcp(n - 1);\n    for (int i = 0; i < n; ++i) {\n       \
    \ if (h > 0) --h;\n        if (rank[i] == 0) continue;\n        int j = sa[rank[i]\
    \ - 1];\n        while (j + h < n && i + h < n && s[j + h] == s[i + h]) ++h;\n\
    \        lcp[rank[i] - 1] = h;\n    }\n    return lcp;\n}\n#line 4 \"test/yosupo/number_of_substrings.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string S;\n    cin >> S;\n    int N = S.size();\n    auto\
    \ sa = suffix_array(S);\n    auto lcp = lcp_array(S, sa);\n    long long ans =\
    \ 1LL * N * (N + 1) / 2;\n    for (int i = 0; i < lcp.size(); ++i) ans -= lcp[i];\n\
    \    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_substrings\"\n\
    \n#include \"../../string/lcp_array.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    string S;\n    cin >> S;\n    int N = S.size();\n    auto sa = suffix_array(S);\n\
    \    auto lcp = lcp_array(S, sa);\n    long long ans = 1LL * N * (N + 1) / 2;\n\
    \    for (int i = 0; i < lcp.size(); ++i) ans -= lcp[i];\n    cout << ans << endl;\n\
    }"
  dependsOn:
  - string/lcp_array.cpp
  isVerificationFile: true
  path: test/yosupo/number_of_substrings.test.cpp
  requiredBy: []
  timestamp: '2022-07-05 13:16:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/number_of_substrings.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_of_substrings.test.cpp
- /verify/test/yosupo/number_of_substrings.test.cpp.html
title: test/yosupo/number_of_substrings.test.cpp
---
