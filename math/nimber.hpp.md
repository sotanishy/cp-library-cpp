---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/nim_product_64.test.cpp
    title: test/yosupo/nim_product_64.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/nimber.hpp\"\n#include <iostream>\n#include <array>\n\
    \nclass Nimber {\n    using ull = unsigned long long;\n\npublic:\n    Nimber(ull\
    \ x = 0) noexcept : x(x) {}\n    ull value() const noexcept { return x; }\n\n\
    \    Nimber operator+(const Nimber& r) const noexcept { return x ^ r.x; }\n  \
    \  Nimber operator*(const Nimber& r) const noexcept {\n        ull res = 0;\n\
    \        for (int i = 0; i < 8; ++i) {\n            ull a = (x >> (8 * i)) & 255;\n\
    \            for (int j = 0; j < 8; ++j) {\n                ull b = (r.x >> (8\
    \ * j)) & 255;\n                res ^= precalc[i][j][small[a][b]];\n         \
    \   }\n        }\n        return res;\n    }\n\n    Nimber& operator+=(const Nimber&\
    \ r) noexcept { return *this = *this + r; }\n    Nimber& operator*=(const Nimber&\
    \ r) noexcept { return *this = *this * r; }\n    bool operator==(const Nimber&\
    \ r) const noexcept { return x == r.x; }\n    bool operator!=(const Nimber& r)\
    \ const noexcept { return x != r.x; }\n    bool operator<(const Nimber& r) const\
    \ { return x < r.x; };\n    bool operator>(const Nimber& r) const { return x >\
    \ r.x; };\n    bool operator<=(const Nimber& r) const { return x <= r.x; };\n\
    \    bool operator>=(const Nimber& r) const { return x >= r.x; };\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Nimber& r) { return os << r.x;\
    \ }\n    friend std::istream& operator>>(std::istream& is, Nimber& r) {\n    \
    \    ull t;\n        is >> t;\n        r = Nimber(t);\n        return is;\n  \
    \  }\n\nprivate:\n    const static std::array<std::array<ull, 256>, 256> small;\n\
    \    const static std::array<std::array<std::array<ull, 256>, 8>, 8> precalc;\n\
    \n    static ull mul_naive(ull x, ull y) {\n        if (x <= 1 || y <= 1) return\
    \ x * y;\n        for (int k = 5; ; --k) {\n            int shift = 1 << k;\n\
    \            ull mask = (1ULL << shift) - 1;\n            if (std::max(x, y) >\
    \ mask) {\n                ull v00 = mul_naive(x & mask, y & mask);\n        \
    \        ull v01 = mul_naive(x & mask, y >> shift);\n                ull v10 =\
    \ mul_naive(x >> shift, y & mask);\n                ull v11 = mul_naive(x >> shift,\
    \ y >> shift);\n                return v00 ^ ((v01 ^ v10 ^ v11) << shift) ^ mul_naive(v11,\
    \ 1ULL << (shift - 1));\n            }\n        }\n    }\n\n    ull x;\n};\n\n\
    const std::array<std::array<Nimber::ull, 256>, 256> Nimber::small = []() {\n \
    \   std::array<std::array<ull, 256>, 256> ret;\n    for (int i = 0; i < 256; ++i)\
    \ {\n        for (int j = 0; j < 256; ++j) {\n            ret[i][j] = mul_naive(i,\
    \ j);\n        }\n    }\n    return ret;\n}();\n\nconst std::array<std::array<std::array<Nimber::ull,\
    \ 256>, 8>, 8> Nimber::precalc = []() {\n    std::array<std::array<std::array<ull,\
    \ 256>, 8>, 8> ret;\n    for (int i = 0; i < 8; ++i) {\n        for (int j = 0;\
    \ j < 8; ++j) {\n            ull p = mul_naive(1ULL << (8 * i), 1ULL << (8 * j));\n\
    \            for (int k = 0; k < 256; ++k) {\n                ret[i][j][k] = mul_naive(p,\
    \ k);\n            }\n        }\n    }\n    return ret;\n}();\n"
  code: "#pragma once\n#include <iostream>\n#include <array>\n\nclass Nimber {\n \
    \   using ull = unsigned long long;\n\npublic:\n    Nimber(ull x = 0) noexcept\
    \ : x(x) {}\n    ull value() const noexcept { return x; }\n\n    Nimber operator+(const\
    \ Nimber& r) const noexcept { return x ^ r.x; }\n    Nimber operator*(const Nimber&\
    \ r) const noexcept {\n        ull res = 0;\n        for (int i = 0; i < 8; ++i)\
    \ {\n            ull a = (x >> (8 * i)) & 255;\n            for (int j = 0; j\
    \ < 8; ++j) {\n                ull b = (r.x >> (8 * j)) & 255;\n             \
    \   res ^= precalc[i][j][small[a][b]];\n            }\n        }\n        return\
    \ res;\n    }\n\n    Nimber& operator+=(const Nimber& r) noexcept { return *this\
    \ = *this + r; }\n    Nimber& operator*=(const Nimber& r) noexcept { return *this\
    \ = *this * r; }\n    bool operator==(const Nimber& r) const noexcept { return\
    \ x == r.x; }\n    bool operator!=(const Nimber& r) const noexcept { return x\
    \ != r.x; }\n    bool operator<(const Nimber& r) const { return x < r.x; };\n\
    \    bool operator>(const Nimber& r) const { return x > r.x; };\n    bool operator<=(const\
    \ Nimber& r) const { return x <= r.x; };\n    bool operator>=(const Nimber& r)\
    \ const { return x >= r.x; };\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Nimber& r) { return os << r.x; }\n    friend std::istream& operator>>(std::istream&\
    \ is, Nimber& r) {\n        ull t;\n        is >> t;\n        r = Nimber(t);\n\
    \        return is;\n    }\n\nprivate:\n    const static std::array<std::array<ull,\
    \ 256>, 256> small;\n    const static std::array<std::array<std::array<ull, 256>,\
    \ 8>, 8> precalc;\n\n    static ull mul_naive(ull x, ull y) {\n        if (x <=\
    \ 1 || y <= 1) return x * y;\n        for (int k = 5; ; --k) {\n            int\
    \ shift = 1 << k;\n            ull mask = (1ULL << shift) - 1;\n            if\
    \ (std::max(x, y) > mask) {\n                ull v00 = mul_naive(x & mask, y &\
    \ mask);\n                ull v01 = mul_naive(x & mask, y >> shift);\n       \
    \         ull v10 = mul_naive(x >> shift, y & mask);\n                ull v11\
    \ = mul_naive(x >> shift, y >> shift);\n                return v00 ^ ((v01 ^ v10\
    \ ^ v11) << shift) ^ mul_naive(v11, 1ULL << (shift - 1));\n            }\n   \
    \     }\n    }\n\n    ull x;\n};\n\nconst std::array<std::array<Nimber::ull, 256>,\
    \ 256> Nimber::small = []() {\n    std::array<std::array<ull, 256>, 256> ret;\n\
    \    for (int i = 0; i < 256; ++i) {\n        for (int j = 0; j < 256; ++j) {\n\
    \            ret[i][j] = mul_naive(i, j);\n        }\n    }\n    return ret;\n\
    }();\n\nconst std::array<std::array<std::array<Nimber::ull, 256>, 8>, 8> Nimber::precalc\
    \ = []() {\n    std::array<std::array<std::array<ull, 256>, 8>, 8> ret;\n    for\
    \ (int i = 0; i < 8; ++i) {\n        for (int j = 0; j < 8; ++j) {\n         \
    \   ull p = mul_naive(1ULL << (8 * i), 1ULL << (8 * j));\n            for (int\
    \ k = 0; k < 256; ++k) {\n                ret[i][j][k] = mul_naive(p, k);\n  \
    \          }\n        }\n    }\n    return ret;\n}();\n"
  dependsOn: []
  isVerificationFile: false
  path: math/nimber.hpp
  requiredBy: []
  timestamp: '2022-04-18 22:20:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/nim_product_64.test.cpp
documentation_of: math/nimber.hpp
layout: document
title: Nimber
---

## Description

Nimber $\mathbb{F}_{2^{64}}$ を表す．

$a, b \in \mathbb{F}_{2^{64}}$ に対して，nimber addition は以下のように定義される．

$$
a \oplus b = \mathrm{mex}(\{a \oplus b' \mid b' < b\} \cup \{a' \oplus b \mid a' < a\})
$$

これは bitwise XOR で計算できる．

$a, b \in \mathbb{F}_{2^{64}}$ に対して，nimber multiplication は以下のように定義される．

$$
a \otimes b = \mathrm{mex}(\{(a \otimes b') \oplus (a' \otimes b) \oplus (a' \otimes b') \mid a' < a, b' < b\})
$$

これは以下の恒等式を用いて再帰的に計算できる．
- $n < 2^{2^k} \Rightarrow n \otimes 2^{2^k} = n \times 2^{2^k}$
- $2^{2^k} \otimes 2^{2^k} = 2^{2^k} + 2^{2^k-1}$

## Operations

- `Nimber operator+(Nimber r)`
    - $r$ との nimber addition を計算する
    - 時間計算量: $O(1)$
- `Nimber operator*(Nimber r)`
    - $r$ との nimber multiplication を計算する
    - 時間計算量: $O(1)$

その他すべて時間計算量 $O(1)$

## Reference

- [Nim product - kyopro_friends’ diary](https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850)
    - Nimber multiplication の解説
- [Nimber, Nim product - cplib-cpp](https://hitonanode.github.io/cplib-cpp/number/nimber.hpp.html)
    - 実装の参考にした