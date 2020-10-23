---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/mod_pow.cpp
    title: Mod Exponentiation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B
  bundledCode: "#line 1 \"test/aoj/NTL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#line 2 \"math/mod_pow.cpp\"\n\n/*\n * @brief Mod Exponentiation\n * @docs\
    \ docs/math/mod_pow.md\n */\nlong long mod_pow(long long a, long long p, long\
    \ long mod) {\n    long long ret = 1;\n    while (p > 0) {\n        if (p & 1)\
    \ ret = ret * a % mod;\n        a = a * a % mod;\n        p >>= 1;\n    }\n  \
    \  return ret;\n}\n\nlong long mod_inv(long long a, long long mod) {\n    return\
    \ mod_pow(a, mod - 2, mod);\n}\n#line 4 \"test/aoj/NTL_1_B.test.cpp\"\n\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int m, n;\n    cin >> m >> n;\n    cout << mod_pow(m, n, 1e9 + 7) << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B\"\
    \n\n#include \"../../math/mod_pow.cpp\"\n\nusing namespace std;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int m, n;\n\
    \    cin >> m >> n;\n    cout << mod_pow(m, n, 1e9 + 7) << endl;\n}"
  dependsOn:
  - math/mod_pow.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_B.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 02:15:23+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/NTL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_B.test.cpp
- /verify/test/aoj/NTL_1_B.test.cpp.html
title: test/aoj/NTL_1_B.test.cpp
---
