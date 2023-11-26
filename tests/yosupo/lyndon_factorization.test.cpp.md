---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/lyndon_factorization.hpp
    title: Lyndon Factorization
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lyndon_factorization
    links:
    - https://judge.yosupo.jp/problem/lyndon_factorization
  bundledCode: "#line 1 \"tests/yosupo/lyndon_factorization.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/lyndon_factorization\"\n\n#line 1 \"string/lyndon_factorization.hpp\"\
    \n#include <string>\n#include <vector>\n\nstd::vector<int> lyndon_factorization(const\
    \ std::string& s) {\n    const int n = s.size();\n    std::vector<int> res;\n\
    \    for (int i = 0; i < n;) {\n        int j = i + 1, k = i;\n        while (j\
    \ < n && s[k] <= s[j]) {\n            if (s[k] < s[j]) {\n                k =\
    \ i;\n            } else {\n                ++k;\n            }\n            ++j;\n\
    \        }\n        while (i <= k) {\n            res.push_back(i);\n        \
    \    i += j - k;\n        }\n    }\n    res.push_back(n);\n    return res;\n}\n\
    #line 4 \"tests/yosupo/lyndon_factorization.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string S;\n    cin >> S;\n    auto res = lyndon_factorization(S);\n\
    \    for (int i = 0; i < (int)res.size(); ++i)\n        cout << res[i] << (i <\
    \ (int)res.size() ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lyndon_factorization\"\n\
    \n#include \"../../string/lyndon_factorization.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string S;\n    cin >> S;\n    auto res = lyndon_factorization(S);\n\
    \    for (int i = 0; i < (int)res.size(); ++i)\n        cout << res[i] << (i <\
    \ (int)res.size() ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - string/lyndon_factorization.hpp
  isVerificationFile: true
  path: tests/yosupo/lyndon_factorization.test.cpp
  requiredBy: []
  timestamp: '2023-11-26 16:39:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: tests/yosupo/lyndon_factorization.test.cpp
layout: document
redirect_from:
- /verify/tests/yosupo/lyndon_factorization.test.cpp
- /verify/tests/yosupo/lyndon_factorization.test.cpp.html
title: tests/yosupo/lyndon_factorization.test.cpp
---
