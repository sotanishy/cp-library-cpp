---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/mod_pow.cpp
    title: Mod Exponentiation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#line 1 \"math/mod_pow.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief Mod\
    \ Exponentiation\n * @docs docs/math/mod_pow.md\n */\nstd::int64_t mod_pow(std::int64_t\
    \ a, std::int64_t p, std::int64_t mod) {\n    std::int64_t ret = 1;\n    while\
    \ (p > 0) {\n        if (p & 1) ret = ret * a % mod;\n        a = a * a % mod;\n\
    \        p >>= 1;\n    }\n    return ret;\n}\n\nstd::int64_t mod_inv(std::int64_t\
    \ a, std::int64_t mod) {\n    return mod_pow(a, mod - 2, mod);\n}\n#line 4 \"\
    test/aoj/NTL_1_B.test.cpp\"\n\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int m, n;\n    cin >> m >> n;\n    cout << mod_pow(m,\
    \ n, 1e9 + 7) << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include \"../../math/mod_pow.cpp\"\n\nusing namespace std;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int m, n;\n\
    \    cin >> m >> n;\n    cout << mod_pow(m, n, 1e9 + 7) << endl;\n}"
  dependsOn:
  - math/mod_pow.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:09:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
