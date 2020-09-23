---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_factor.cpp
    title: Prime Factor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/aoj/NTL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#line 1 \"math/prime_factor.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Prime Factor\n * @docs docs/math/prime_factor.md\n */\nstd::map<std::int64_t,\
    \ int> prime_factor(std::int64_t n) {\n    std::map<std::int64_t, int> ret;\n\
    \    if (n % 2 == 0) {\n        int cnt = 0;\n        while (n % 2 == 0) {\n \
    \           ++cnt;\n            n /= 2;\n        }\n        ret[2] = cnt;\n  \
    \  }\n    for (std::int64_t i = 3; i * i <= n; i += 2) {\n        if (n % i ==\
    \ 0) {\n            int cnt = 0;\n            while (n % i == 0) {\n         \
    \       ++cnt;\n                n /= i;\n            }\n            ret[i] = cnt;\n\
    \        }\n    }\n    if (n != 1) ret[n] = 1;\n    return ret;\n}\n#line 4 \"\
    test/aoj/NTL_1_A.test.cpp\"\n\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    cout << n << \":\";\n    auto\
    \ prime = prime_factor(n);\n    for (auto& p : prime) {\n        for (int i =\
    \ 0; i < p.second; i++) cout << \" \" << p.first;\n    }\n    cout << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#include \"../../math/prime_factor.cpp\"\n\nusing namespace std;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n;\n  \
    \  cin >> n;\n    cout << n << \":\";\n    auto prime = prime_factor(n);\n   \
    \ for (auto& p : prime) {\n        for (int i = 0; i < p.second; i++) cout <<\
    \ \" \" << p.first;\n    }\n    cout << endl;\n}"
  dependsOn:
  - math/prime_factor.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:09:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_A.test.cpp
- /verify/test/aoj/NTL_1_A.test.cpp.html
title: test/aoj/NTL_1_A.test.cpp
---
