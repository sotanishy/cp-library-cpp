---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.rolling_hash.test.cpp
    title: test/aoj/ALDS1_14_B.rolling_hash.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/rolling_hash.md
    document_title: Rolling Hash
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.cpp\"\n#include <random>\n#include <string>\n\
    #include <vector>\n\n/*\n * @brief Rolling Hash\n * @docs docs/string/rolling_hash.md\n\
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
    \ const {\n        return add(mul(h1, power[len2]), h2);\n    }\n\nprivate:\n\
    \    static constexpr long long mod = (1LL << 61) - 1;\n\n    static inline long\
    \ long add(long long a, long long b) {\n        if ((a += b) >= mod) a -= mod;\n\
    \        return a;\n    }\n\n    static inline long long mul(long long a, long\
    \ long b) {\n        __int128_t c = (__int128_t) a * b;\n        return add(c\
    \ >> 61, c & mod);\n    }\n\n    const long long base;\n    std::vector<long long>\
    \ hashed, power;\n};\n"
  code: "#pragma once\n#include <random>\n#include <string>\n#include <vector>\n\n\
    /*\n * @brief Rolling Hash\n * @docs docs/string/rolling_hash.md\n */\nclass RollingHash\
    \ {\npublic:\n    static long long generate_base() {\n        std::random_device\
    \ rd;\n        std::mt19937_64 rng(rd());\n        std::uniform_int_distribution<long\
    \ long> rand(1, mod - 1);\n        return rand(rng);\n    }\n\n    RollingHash()\
    \ = default;\n    RollingHash(const std::string& s, long long base) : RollingHash(std::vector<char>(s.begin(),\
    \ s.end()), base) {}\n    template <typename T>\n    RollingHash(const std::vector<T>&\
    \ s, long long base)\n        : base(base), hashed(s.size() + 1), power(s.size()\
    \ + 1) {\n        power[0] = 1;\n        for (int i = 0; i < (int) s.size(); ++i)\
    \ {\n            power[i + 1] = mul(power[i], base);\n            hashed[i + 1]\
    \ = add(mul(hashed[i], base), s[i]);\n        }\n    }\n\n    long long query(int\
    \ l, int r) const {\n        return add(hashed[r], mod - mul(hashed[l], power[r\
    \ - l]));\n    }\n\n    long long combine(long long h1, long long h2, int len2)\
    \ const {\n        return add(mul(h1, power[len2]), h2);\n    }\n\nprivate:\n\
    \    static constexpr long long mod = (1LL << 61) - 1;\n\n    static inline long\
    \ long add(long long a, long long b) {\n        if ((a += b) >= mod) a -= mod;\n\
    \        return a;\n    }\n\n    static inline long long mul(long long a, long\
    \ long b) {\n        __int128_t c = (__int128_t) a * b;\n        return add(c\
    \ >> 61, c & mod);\n    }\n\n    const long long base;\n    std::vector<long long>\
    \ hashed, power;\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.cpp
  requiredBy: []
  timestamp: '2020-10-26 15:47:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.rolling_hash.test.cpp
documentation_of: string/rolling_hash.cpp
layout: document
redirect_from:
- /library/string/rolling_hash.cpp
- /library/string/rolling_hash.cpp.html
title: Rolling Hash
---
# Rolling Hash

文字列または数列のハッシュ値を計算する．Rabin-Karp 法に用いる．

この実装では $\mod 2^{61} - 1$ を用いている．

## Constructor

- `RollingHash(string s, long long base)`
- `RollingHash(vector<T> s, long long base)`
    - `s` のハッシュ値を計算する．
    - 時間計算量: $O(n)$

## Member functions

- `static long long generate_base()`
    - ランダムな基数を返す．
    - 時間計算量: $O(1)$
- `long long query(int l, int r)`
    - 区間 $[l, r)$ のハッシュ値を返す．
    - 時間計算量: $O(1)$
- `long long combine(long long h1, long long h2, int len2)`
    - ハッシュ値 $h1$ と $h2$ を結合する．$h2$ の長さを $len2$ である．
    - 時間計算量: $O(1)$

## Reference

- [安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)