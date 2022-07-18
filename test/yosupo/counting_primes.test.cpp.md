---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/prime_count.hpp
    title: Prime Counting Function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_primes
    links:
    - https://judge.yosupo.jp/problem/counting_primes
  bundledCode: "#line 1 \"test/yosupo/counting_primes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#line 2 \"math/prime_count.hpp\"\
    \n#include <cmath>\n#include <vector>\n\nlong long prime_count(long long n) {\n\
    \    int s = (int) std::sqrt(n);\n    std::vector<long long> small(n / s + 1),\
    \ large(s + 1);\n    for (int i = 1; i <= n / s; ++i) small[i] = i - 1;\n    for\
    \ (int i = 1; i <= s; ++i) large[i] = n / i - 1;\n    for (long long i = 2; i\
    \ <= s; ++i) {\n        if (small[i - 1] == small[i]) continue;  // i is not prime\n\
    \        long long pi = small[i - 1];\n        for (long long j = 1; j <= s &&\
    \ n / j >= i * i; ++j) {\n            long long x = i * j <= s ? large[i * j]\
    \ : small[n / (i * j)];\n            if (j <= s) {\n                large[j] -=\
    \ x - pi;\n            }\n            if (n / j <= n / s) {\n                small[n\
    \ / j] -= x - pi;\n            }\n        }\n        for (long long j = n / s\
    \ - 1; j >= i * i; --j) {\n            small[j] -= small[j / i] - pi;\n      \
    \  }\n    }\n    return large[1];\n}\n#line 4 \"test/yosupo/counting_primes.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    long long N;\n    cin >> N;\n    cout << prime_count(N) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_primes\"\n\n#include\
    \ \"../../math/prime_count.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    long long N;\n    cin >> N;\n    cout << prime_count(N)\
    \ << endl;\n}"
  dependsOn:
  - math/prime_count.hpp
  isVerificationFile: true
  path: test/yosupo/counting_primes.test.cpp
  requiredBy: []
  timestamp: '2022-07-18 21:37:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/counting_primes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/counting_primes.test.cpp
- /verify/test/yosupo/counting_primes.test.cpp.html
title: test/yosupo/counting_primes.test.cpp
---
