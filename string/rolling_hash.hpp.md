---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2292.test.cpp
    title: test/aoj/2292.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.rolling_hash.test.cpp
    title: test/aoj/ALDS1_14_B.rolling_hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling_hash.hpp\"\n#include <random>\n#include <string>\n\
    #include <vector>\n\nclass RollingHash {\n   public:\n    static long long generate_base()\
    \ {\n        std::random_device rd;\n        std::mt19937_64 rng(rd());\n    \
    \    std::uniform_int_distribution<long long> rand(1, mod - 1);\n        return\
    \ rand(rng);\n    }\n\n    RollingHash() = default;\n    RollingHash(const std::string&\
    \ s, long long base)\n        : RollingHash(std::vector<char>(s.begin(), s.end()),\
    \ base) {}\n    template <typename T>\n    RollingHash(const std::vector<T>& s,\
    \ long long base)\n        : base(base), hashed(s.size() + 1), power(s.size()\
    \ + 1) {\n        power[0] = 1;\n        for (int i = 0; i < (int)s.size(); ++i)\
    \ {\n            power[i + 1] = mul(power[i], base);\n            hashed[i + 1]\
    \ = add(mul(hashed[i], base), s[i]);\n        }\n    }\n\n    long long query(int\
    \ l, int r) const {\n        return add(hashed[r], mod - mul(hashed[l], power[r\
    \ - l]));\n    }\n\n    long long combine(long long h1, long long h2, int len2)\
    \ const {\n        return add(mul(h1, power[len2]), h2);\n    }\n\n    void push_back(char\
    \ c) {\n        power.push_back(mul(power.back(), base));\n        hashed.push_back(add(mul(hashed.back(),\
    \ base), c));\n    }\n\n   private:\n    static constexpr long long mod = (1LL\
    \ << 61) - 1;\n\n    static inline long long add(long long a, long long b) {\n\
    \        if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static\
    \ inline long long mul(long long a, long long b) {\n        __int128_t c = (__int128_t)a\
    \ * b;\n        return add(c >> 61, c & mod);\n    }\n\n    const long long base;\n\
    \    std::vector<long long> hashed, power;\n};\n"
  code: "#pragma once\n#include <random>\n#include <string>\n#include <vector>\n\n\
    class RollingHash {\n   public:\n    static long long generate_base() {\n    \
    \    std::random_device rd;\n        std::mt19937_64 rng(rd());\n        std::uniform_int_distribution<long\
    \ long> rand(1, mod - 1);\n        return rand(rng);\n    }\n\n    RollingHash()\
    \ = default;\n    RollingHash(const std::string& s, long long base)\n        :\
    \ RollingHash(std::vector<char>(s.begin(), s.end()), base) {}\n    template <typename\
    \ T>\n    RollingHash(const std::vector<T>& s, long long base)\n        : base(base),\
    \ hashed(s.size() + 1), power(s.size() + 1) {\n        power[0] = 1;\n       \
    \ for (int i = 0; i < (int)s.size(); ++i) {\n            power[i + 1] = mul(power[i],\
    \ base);\n            hashed[i + 1] = add(mul(hashed[i], base), s[i]);\n     \
    \   }\n    }\n\n    long long query(int l, int r) const {\n        return add(hashed[r],\
    \ mod - mul(hashed[l], power[r - l]));\n    }\n\n    long long combine(long long\
    \ h1, long long h2, int len2) const {\n        return add(mul(h1, power[len2]),\
    \ h2);\n    }\n\n    void push_back(char c) {\n        power.push_back(mul(power.back(),\
    \ base));\n        hashed.push_back(add(mul(hashed.back(), base), c));\n    }\n\
    \n   private:\n    static constexpr long long mod = (1LL << 61) - 1;\n\n    static\
    \ inline long long add(long long a, long long b) {\n        if ((a += b) >= mod)\
    \ a -= mod;\n        return a;\n    }\n\n    static inline long long mul(long\
    \ long a, long long b) {\n        __int128_t c = (__int128_t)a * b;\n        return\
    \ add(c >> 61, c & mod);\n    }\n\n    const long long base;\n    std::vector<long\
    \ long> hashed, power;\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling_hash.hpp
  requiredBy: []
  timestamp: '2024-01-07 22:05:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.rolling_hash.test.cpp
  - test/aoj/2292.test.cpp
documentation_of: string/rolling_hash.hpp
layout: document
title: Rolling Hash
---

## Description

文字列または数列のハッシュ値を計算する．Rabin-Karp 法に用いる．

この実装では $\mod 2^{61} - 1$ を用いている．

この実装は内部で `__int128_t` を用いているが，Codeforces ではそれが使用できないので注意．Codeforces で rolling hash を使いたいときは，`mod` を 32 bit 以下の適当な整数 (素数?) に設定し，`long long` で乗算を行えばよい．

## Operations

- `RollingHash(string s, long long base)`
- `RollingHash(vector<T> s, long long base)`
    - `s` のハッシュ値を計算する
    - 時間計算量: $O(n)$
- `static long long generate_base()`
    - ランダムな基数を返す
    - 時間計算量: $O(1)$
- `long long query(int l, int r)`
    - 区間 $[l, r)$ のハッシュ値を返す
    - 時間計算量: $O(1)$
- `long long combine(long long h1, long long h2, int len2)`
    - ハッシュ値 $h1$ と $h2$ を結合する．$h2$ の長さを $len2$ である
    - 時間計算量: $O(1)$
- `void push_back(char c)`
    - 文字 $c$ を末尾に結合する
    - 時間計算量: $O(1)$

## Reference

- [安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)