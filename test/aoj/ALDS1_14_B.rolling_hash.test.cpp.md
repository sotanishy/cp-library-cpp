---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/rolling_hash.cpp
    title: Rolling Hash
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.rolling_hash.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\n\
    #line 2 \"string/rolling_hash.cpp\"\n#include <random>\n#include <string>\n#include\
    \ <vector>\n\n/*\n * @brief Rolling Hash\n * @docs docs/string/rolling_hash.md\n\
    \ */\nclass RollingHash {\npublic:\n    static long long generate_base() {\n \
    \       std::random_device rd;\n        std::mt19937_64 rng(rd());\n        std::uniform_int_distribution<long\
    \ long> rand(1, mod - 1);\n        return rand(rng);\n    }\n\n    RollingHash()\
    \ = default;\n    RollingHash(const std::string& s, long long base) : RollingHash(std::vector<char>(s.begin(),\
    \ s.end()), base) {}\n    template <typename T>\n    RollingHash(const std::vector<T>&\
    \ s, long long base)\n        : base(base), hashed(s.size() + 1), power(s.size()\
    \ + 1) {\n        power[0] = 1;\n        for (int i = 0; i < (int) s.size(); ++i)\
    \ {\n            power[i + 1] = mul(power[i], base);\n            hashed[i + 1]\
    \ = add(mul(hashed[i], base), s[i]);\n        }\n    }\n\n    long long query(int\
    \ l, int r) const {\n        return add(hashed[r], mod - mul(hashed[l], power[r\
    \ - l]));\n    }\n\n    long long combine(long long h1, long long h2, int len2)\
    \ const {\n        return add(mul(h1, power[len2]), h2);\n    }\n\n    void push_back(char\
    \ c) {\n        power.push_back(mul(power.back(), base));\n        hashed.push_back(add(mul(hashed.back(),\
    \ base), c));\n    }\n\nprivate:\n    static constexpr long long mod = (1LL <<\
    \ 61) - 1;\n\n    static inline long long add(long long a, long long b) {\n  \
    \      if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static\
    \ inline long long mul(long long a, long long b) {\n        __int128_t c = (__int128_t)\
    \ a * b;\n        return add(c >> 61, c & mod);\n    }\n\n    const long long\
    \ base;\n    std::vector<long long> hashed, power;\n};\n#line 4 \"test/aoj/ALDS1_14_B.rolling_hash.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string T;\n    cin >> T;\n    string P;\n    cin >> P;\n\
    \    long long base = RollingHash::generate_base();\n    RollingHash rht(T, base);\n\
    \    RollingHash rhp(P, base);\n    for (int i = 0; i + P.size() <= T.size();\
    \ ++i) {\n        if (rht.query(i, i + P.size()) == rhp.query(0, P.size())) {\n\
    \            cout << i << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include \"../../string/rolling_hash.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    string T;\n    cin >> T;\n    string P;\n    cin >> P;\n    long long base\
    \ = RollingHash::generate_base();\n    RollingHash rht(T, base);\n    RollingHash\
    \ rhp(P, base);\n    for (int i = 0; i + P.size() <= T.size(); ++i) {\n      \
    \  if (rht.query(i, i + P.size()) == rhp.query(0, P.size())) {\n            cout\
    \ << i << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - string/rolling_hash.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.rolling_hash.test.cpp
  requiredBy: []
  timestamp: '2020-12-17 22:11:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.rolling_hash.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.rolling_hash.test.cpp
- /verify/test/aoj/ALDS1_14_B.rolling_hash.test.cpp.html
title: test/aoj/ALDS1_14_B.rolling_hash.test.cpp
---
