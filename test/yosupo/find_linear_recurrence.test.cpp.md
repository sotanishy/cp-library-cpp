---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/berlekamp_massey.cpp
    title: Berlekamp-Massey Algorithm
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/find_linear_recurrence
    links:
    - https://judge.yosupo.jp/problem/find_linear_recurrence
  bundledCode: "#line 1 \"test/yosupo/find_linear_recurrence.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\n\n#line 2 \"math/modint.cpp\"\
    \n#include <iostream>\n#include <algorithm>\n\n/**\n * @brief Mod int\n */\ntemplate\
    \ <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod >\
    \ 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
    \ noexcept { return mod; }\n\n    constexpr Modint(long long y = 0) noexcept :\
    \ x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n    constexpr int value()\
    \ const noexcept { return x; }\n\n    constexpr mint& operator+=(const mint& r)\
    \ noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr mint&\
    \ operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -= mod;\
    \ return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept { x\
    \ = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr mint&\
    \ operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\n \
    \   constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
    \ mint operator+(const mint& r) const noexcept { return mint(*this) += r; }\n\
    \    constexpr mint operator-(const mint& r) const noexcept { return mint(*this)\
    \ -= r; }\n    constexpr mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n    constexpr mint operator/(const mint& r) const noexcept\
    \ { return mint(*this) /= r; }\n\n    constexpr bool operator==(const mint& r)\
    \ const noexcept { return x == r.x; }\n    constexpr bool operator!=(const mint&\
    \ r) const noexcept { return x != r.x; }\n\n    constexpr mint inv() const noexcept\
    \ {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0) {\n    \
    \        int t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u\
    \ -= t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n        while\
    \ (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n   \
    \         n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\nprivate:\n    int x;\n};\n#line 2 \"math/berlekamp_massey.cpp\"\n#include\
    \ <vector>\n\ntemplate <typename T>\nstd::vector<T> berlekamp_massey(const std::vector<T>&\
    \ a) {\n    int n = a.size();\n    std::vector<T> B = {1}, C = {1};\n    T b =\
    \ 1;\n    int L = 0, m = 1;\n    for (int i = 0; i < n; ++i) {\n        T d =\
    \ a[i];\n        for (int j = 1; j < (int) C.size(); ++j) {\n            d +=\
    \ a[i-j] * C[j];\n        }\n        if (d == 0) {\n            ++m;\n       \
    \ } else {\n            auto tmp =  C;\n            if (C.size() < m + B.size())\
    \ {\n                C.resize(m + B.size());\n            }\n            T f =\
    \ d / b;\n            for (int j = 0; j < (int) B.size(); ++j) {\n           \
    \     C[m + j] -= f * B[j];\n            }\n            if (2 * L <= i) {\n  \
    \              L = i + 1 - L;\n                b = d;\n                B = tmp;\n\
    \                m = 1;\n            } else {\n                ++m;\n        \
    \    }\n        }\n    }\n    std::vector<T> ret(L);\n    for (int i = 1; i <=\
    \ L; ++i) {\n        ret[i-1] = -C[i];\n    }\n    return ret;\n}\n#line 5 \"\
    test/yosupo/find_linear_recurrence.test.cpp\"\n\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nusing mint = Modint<998244353>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N;\n    cin >> N;\n    vector<mint> a(N);\n\
    \    for (auto& x : a) cin >> x;\n    auto ans = berlekamp_massey(a);\n    cout\
    \ << ans.size() << endl;\n    for (int i = 0; i < ans.size(); ++i) {\n       \
    \ cout << ans[i];\n        if (i < (int) ans.size() - 1) cout << \" \";\n    }\n\
    \    cout << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/find_linear_recurrence\"\
    \n\n#include \"../../math/modint.cpp\"\n#include \"../../math/berlekamp_massey.cpp\"\
    \n\n\n#include <bits/stdc++.h>\nusing namespace std;\n\nusing mint = Modint<998244353>;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N;\n    cin >> N;\n    vector<mint> a(N);\n    for (auto& x : a) cin\
    \ >> x;\n    auto ans = berlekamp_massey(a);\n    cout << ans.size() << endl;\n\
    \    for (int i = 0; i < ans.size(); ++i) {\n        cout << ans[i];\n       \
    \ if (i < (int) ans.size() - 1) cout << \" \";\n    }\n    cout << endl;\n}"
  dependsOn:
  - math/modint.cpp
  - math/berlekamp_massey.cpp
  isVerificationFile: true
  path: test/yosupo/find_linear_recurrence.test.cpp
  requiredBy: []
  timestamp: '2022-06-27 16:41:31+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/find_linear_recurrence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/find_linear_recurrence.test.cpp
- /verify/test/yosupo/find_linear_recurrence.test.cpp.html
title: test/yosupo/find_linear_recurrence.test.cpp
---
