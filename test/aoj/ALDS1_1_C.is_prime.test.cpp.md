---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/is_prime.cpp
    title: Primality Test
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/aoj/ALDS1_1_C.is_prime.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\n\n#line\
    \ 1 \"math/is_prime.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief Primality\
    \ Test\n * @docs docs/math/is_prime.md\n */\nbool is_prime(long long n) {\n  \
    \  if (n <= 1) return false;\n    if (n <= 3) return true;\n    if (n % 2 == 0\
    \ || n % 3 == 0) return false;\n    if (n < 9) return true;\n    for (long long\
    \ i = 5; i * i <= n; i += 6) {\n        if (n % i == 0 || n % (i + 2) == 0) return\
    \ false;\n    }\n    return true;\n}\n#line 4 \"test/aoj/ALDS1_1_C.is_prime.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    int ans = 0;\n    for (int\
    \ i = 0; i < n; i++) {\n        int a;\n        cin >> a;\n        if (is_prime(a))\
    \ ans++;\n    }\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n\n#include \"../../math/is_prime.cpp\"\n\nusing namespace std;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n;\n  \
    \  cin >> n;\n    int ans = 0;\n    for (int i = 0; i < n; i++) {\n        int\
    \ a;\n        cin >> a;\n        if (is_prime(a)) ans++;\n    }\n    cout << ans\
    \ << endl;\n}"
  dependsOn:
  - math/is_prime.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_1_C.is_prime.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:28:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_1_C.is_prime.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_1_C.is_prime.test.cpp
- /verify/test/aoj/ALDS1_1_C.is_prime.test.cpp.html
title: test/aoj/ALDS1_1_C.is_prime.test.cpp
---
