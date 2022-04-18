---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/nimber.hpp
    title: Nimber
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/nim_product_64
    links:
    - https://judge.yosupo.jp/problem/nim_product_64
  bundledCode: "#line 1 \"test/yosupo/nim_product_64.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/nim_product_64\"\n\n#line 2 \"math/nimber.hpp\"\
    \n#include <iostream>\n#include <array>\n\nclass Nimber {\n    using ull = unsigned\
    \ long long;\n\npublic:\n    Nimber(ull x = 0) noexcept : x(x) {}\n    ull value()\
    \ const noexcept { return x; }\n\n    Nimber operator+(const Nimber& r) const\
    \ noexcept { return x ^ r.x; }\n    Nimber operator*(const Nimber& r) const noexcept\
    \ {\n        ull res = 0;\n        for (int i = 0; i < 8; ++i) {\n           \
    \ ull a = (x >> (8 * i)) & 255;\n            for (int j = 0; j < 8; ++j) {\n \
    \               ull b = (r.x >> (8 * j)) & 255;\n                res ^= precalc[i][j][small[a][b]];\n\
    \            }\n        }\n        return res;\n    }\n\n    Nimber& operator+=(const\
    \ Nimber& r) noexcept { return *this = *this + r; }\n    Nimber& operator*=(const\
    \ Nimber& r) noexcept { return *this = *this * r; }\n    bool operator==(const\
    \ Nimber& r) const noexcept { return x == r.x; }\n    bool operator!=(const Nimber&\
    \ r) const noexcept { return x != r.x; }\n    bool operator<(const Nimber& r)\
    \ const { return x < r.x; };\n    bool operator>(const Nimber& r) const { return\
    \ x > r.x; };\n    bool operator<=(const Nimber& r) const { return x <= r.x; };\n\
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
    \ k);\n            }\n        }\n    }\n    return ret;\n}();\n#line 4 \"test/yosupo/nim_product_64.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)\n#define revrep(i, t,\
    \ s) for (int i = (int)(t)-1; i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\n\
    template <typename T> bool chmax(T& a, const T& b) { return a < b ? (a = b, 1)\
    \ : 0; }\ntemplate <typename T> bool chmin(T& a, const T& b) { return a > b ?\
    \ (a = b, 1) : 0; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n \
    \   cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int T;\n\
    \    cin >> T;\n    while (T--) {\n        Nimber A, B;\n        cin >> A >> B;\n\
    \        cout << A*B << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/nim_product_64\"\n\n#include\
    \ \"../../math/nimber.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n#define rep(i, s, t) for (int i = (int)(s); i < (int)(t);\
    \ ++i)\n#define revrep(i, t, s) for (int i = (int)(t)-1; i >= (int)(s); --i)\n\
    #define all(x) begin(x), end(x)\ntemplate <typename T> bool chmax(T& a, const\
    \ T& b) { return a < b ? (a = b, 1) : 0; }\ntemplate <typename T> bool chmin(T&\
    \ a, const T& b) { return a > b ? (a = b, 1) : 0; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int T;\n\
    \    cin >> T;\n    while (T--) {\n        Nimber A, B;\n        cin >> A >> B;\n\
    \        cout << A*B << \"\\n\";\n    }\n}"
  dependsOn:
  - math/nimber.hpp
  isVerificationFile: true
  path: test/yosupo/nim_product_64.test.cpp
  requiredBy: []
  timestamp: '2022-04-18 22:20:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/nim_product_64.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/nim_product_64.test.cpp
- /verify/test/yosupo/nim_product_64.test.cpp.html
title: test/yosupo/nim_product_64.test.cpp
---
