---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/prime.hpp
    title: Prime Number Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_primes
    links:
    - https://judge.yosupo.jp/problem/enumerate_primes
  bundledCode: "#line 1 \"test/yosupo/enumerate_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n#include <bits/stdc++.h>\n\
    \n#line 5 \"math/number-theory/prime.hpp\"\n\n/*\n * Primality Test\n */\nbool\
    \ is_prime(long long n) {\n    if (n <= 1) return false;\n    if (n <= 3) return\
    \ true;\n    if (n % 2 == 0 || n % 3 == 0) return false;\n    if (n < 9) return\
    \ true;\n    for (long long i = 5; i * i <= n; i += 6) {\n        if (n % i ==\
    \ 0 || n % (i + 2) == 0) return false;\n    }\n    return true;\n}\n\n/*\n * Prime\
    \ Table\n */\nstd::vector<bool> prime_table(int n) {\n    std::vector<bool> prime(n\
    \ + 1, true);\n    prime[0] = prime[1] = false;\n    for (int j = 4; j <= n; j\
    \ += 2) prime[j] = false;\n    for (int i = 3; i * i <= n; i += 2) {\n       \
    \ if (!prime[i]) continue;\n        for (int j = i * i; j <= n; j += 2 * i) prime[j]\
    \ = false;\n    }\n    return prime;\n}\n\n/*\n * Table of Minimum Prime Factors\n\
    \ */\nstd::vector<int> min_factor_table(int n) {\n    std::vector<int> factor(n\
    \ + 1);\n    std::iota(factor.begin(), factor.end(), 0);\n    for (int i = 2;\
    \ i * i <= n; ++i) {\n        if (factor[i] != i) continue;\n        for (int\
    \ j = i * i; j <= n; j += i) {\n            if (factor[j] == j) factor[j] = i;\n\
    \        }\n    }\n    return factor;\n}\n\n/*\n * Prime Factorization\n */\n\
    std::map<long long, int> prime_factor(long long n) {\n    std::map<long long,\
    \ int> ret;\n    if (n % 2 == 0) {\n        int cnt = 0;\n        while (n % 2\
    \ == 0) {\n            ++cnt;\n            n /= 2;\n        }\n        ret[2]\
    \ = cnt;\n    }\n    for (long long i = 3; i * i <= n; i += 2) {\n        if (n\
    \ % i == 0) {\n            int cnt = 0;\n            while (n % i == 0) {\n  \
    \              ++cnt;\n                n /= i;\n            }\n            ret[i]\
    \ = cnt;\n        }\n    }\n    if (n != 1) ret[n] = 1;\n    return ret;\n}\n\
    #line 6 \"test/yosupo/enumerate_primes.test.cpp\"\nusing namespace std;\nusing\
    \ ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n   \
    \ cin.tie(nullptr);\n\n    int N, A, B;\n    cin >> N >> A >> B;\n    auto is_prime\
    \ = prime_table(N);\n    vector<int> primes;\n    for (int i = 2; i <= N; ++i)\
    \ {\n        if (is_prime[i]) primes.push_back(i);\n    }\n    vector<int> ans;\n\
    \    for (int i = B; i < (int)primes.size(); i += A) {\n        ans.push_back(primes[i]);\n\
    \    }\n    int X = ans.size();\n    cout << primes.size() << \" \" << X << endl;\n\
    \    for (int i = 0; i < X; ++i) cout << ans[i] << (i < X - 1 ? \" \" : \"\\n\"\
    );\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_primes\"\n\n\
    #include <bits/stdc++.h>\n\n#include \"../../math/number-theory/prime.hpp\"\n\
    using namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, A, B;\n    cin >> N >> A >> B;\n    auto\
    \ is_prime = prime_table(N);\n    vector<int> primes;\n    for (int i = 2; i <=\
    \ N; ++i) {\n        if (is_prime[i]) primes.push_back(i);\n    }\n    vector<int>\
    \ ans;\n    for (int i = B; i < (int)primes.size(); i += A) {\n        ans.push_back(primes[i]);\n\
    \    }\n    int X = ans.size();\n    cout << primes.size() << \" \" << X << endl;\n\
    \    for (int i = 0; i < X; ++i) cout << ans[i] << (i < X - 1 ? \" \" : \"\\n\"\
    );\n}"
  dependsOn:
  - math/number-theory/prime.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_primes.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_primes.test.cpp
- /verify/test/yosupo/enumerate_primes.test.cpp.html
title: test/yosupo/enumerate_primes.test.cpp
---
