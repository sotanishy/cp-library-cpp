---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime.cpp
    title: Prime Number Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A
  bundledCode: "#line 1 \"test/aoj/NTL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#line 2 \"math/prime.cpp\"\n#include <map>\n#include <vector>\n\n/*\n * Primality\
    \ Test\n */\nbool is_prime(long long n) {\n    if (n <= 1) return false;\n   \
    \ if (n <= 3) return true;\n    if (n % 2 == 0 || n % 3 == 0) return false;\n\
    \    if (n < 9) return true;\n    for (long long i = 5; i * i <= n; i += 6) {\n\
    \        if (n % i == 0 || n % (i + 2) == 0) return false;\n    }\n    return\
    \ true;\n}\n\n/*\n * Prime Table\n */\nstd::vector<bool> prime_table(int n) {\n\
    \    std::vector<bool> prime(n + 1, true);\n    prime[0] = prime[1] = false;\n\
    \    for (int j = 4; j <= n; j += 2) prime[j] = false;\n    for (int i = 3; i\
    \ * i <= n; i += 2) {\n        if (!prime[i]) continue;\n        for (int j =\
    \ i * i; j <= n; j += 2 * i) prime[j] = false;\n    }\n    return prime;\n}\n\n\
    /*\n * Prime Factorization\n */\nstd::map<long long, int> prime_factor(long long\
    \ n) {\n    std::map<long long, int> ret;\n    if (n % 2 == 0) {\n        int\
    \ cnt = 0;\n        while (n % 2 == 0) {\n            ++cnt;\n            n /=\
    \ 2;\n        }\n        ret[2] = cnt;\n    }\n    for (long long i = 3; i * i\
    \ <= n; i += 2) {\n        if (n % i == 0) {\n            int cnt = 0;\n     \
    \       while (n % i == 0) {\n                ++cnt;\n                n /= i;\n\
    \            }\n            ret[i] = cnt;\n        }\n    }\n    if (n != 1) ret[n]\
    \ = 1;\n    return ret;\n}\n#line 4 \"test/aoj/NTL_1_A.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    cout << n << \":\";\n    auto\
    \ prime = prime_factor(n);\n    for (auto& p : prime) {\n        for (int i =\
    \ 0; i < p.second; i++) cout << \" \" << p.first;\n    }\n    cout << endl;\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A\"\
    \n\n#include \"../../math/prime.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int n;\n    cin >> n;\n    cout << n << \":\";\n    auto prime = prime_factor(n);\n\
    \    for (auto& p : prime) {\n        for (int i = 0; i < p.second; i++) cout\
    \ << \" \" << p.first;\n    }\n    cout << endl;\n}"
  dependsOn:
  - math/prime.cpp
  isVerificationFile: true
  path: test/aoj/NTL_1_A.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 03:15:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_A.test.cpp
- /verify/test/aoj/NTL_1_A.test.cpp.html
title: test/aoj/NTL_1_A.test.cpp
---
