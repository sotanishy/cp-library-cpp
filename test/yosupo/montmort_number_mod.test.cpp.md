---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/arbitrary_modint.cpp
    title: math/arbitrary_modint.cpp
  - icon: ':heavy_check_mark:'
    path: math/montmort.cpp
    title: Monmort Number
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/montmort_number_mod
    links:
    - https://judge.yosupo.jp/problem/montmort_number_mod
  bundledCode: "#line 1 \"test/yosupo/montmort_number_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\n#line 2 \"math/arbitrary_modint.cpp\"\
    \n#include <iostream>\n#include <algorithm>\n#include <cassert>\n\nclass ArbitraryModint\
    \ {\n    using mint = ArbitraryModint;\n\npublic:\n    static int& get_mod() noexcept\
    \ {\n        static int mod = 1;\n        return mod;\n    }\n\n    static void\
    \ set_mod(int mod) {\n        assert(mod > 0);\n        get_mod() = mod;\n   \
    \ }\n\n    ArbitraryModint(long long y = 0) noexcept : x(y >= 0 ? y % get_mod()\
    \ : (y % get_mod() + get_mod()) % get_mod()) {}\n\n    int value() const noexcept\
    \ { return x; }\n\n    mint& operator+=(const mint& r) noexcept { if ((x += r.x)\
    \ >= get_mod()) x -= get_mod(); return *this; }\n    mint& operator-=(const mint&\
    \ r) noexcept { if ((x += get_mod() - r.x) >= get_mod()) x -= get_mod(); return\
    \ *this; }\n    mint& operator*=(const mint& r) noexcept { x = static_cast<int>(1LL\
    \ * x * r.x % get_mod()); return *this; }\n    mint& operator/=(const mint& r)\
    \ noexcept { *this *= r.inv(); return *this; }\n\n    mint operator-() const noexcept\
    \ { return mint(-x); }\n\n    mint operator+(const mint& r) const noexcept { return\
    \ mint(*this) += r; }\n    mint operator-(const mint& r) const noexcept { return\
    \ mint(*this) -= r; }\n    mint operator*(const mint& r) const noexcept { return\
    \ mint(*this) *= r; }\n    mint operator/(const mint& r) const noexcept { return\
    \ mint(*this) /= r; }\n\n    bool operator==(const mint& r) const noexcept { return\
    \ x == r.x; }\n    bool operator!=(const mint& r) const noexcept { return x !=\
    \ r.x; }\n\n    mint inv() const noexcept {\n        int a = x, b = get_mod(),\
    \ u = 1, v = 0;\n        while (b > 0) {\n            int t = a / b;\n       \
    \     std::swap(a -= t * b, b);\n            std::swap(u -= t * v, v);\n     \
    \   }\n        return mint(u);\n    }\n\n    mint pow(long long n) const noexcept\
    \ {\n        mint ret(1), mul(x);\n        while (n > 0) {\n            if (n\
    \ & 1) ret *= mul;\n            mul *= mul;\n            n >>= 1;\n        }\n\
    \        return ret;\n    }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const mint& r) {\n        return os << r.x;\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, mint& r) {\n        long long t;\n        is >>\
    \ t;\n        r = mint(t);\n        return is;\n    }\n\nprivate:\n    int x;\n\
    };\n#line 2 \"math/montmort.cpp\"\n#include <vector>\n\n/*\n * @brief Monmort\
    \ Number\n */\ntemplate <typename T>\nstd::vector<T> montmort(int n) {\n    std::vector<T>\
    \ ret(n + 1);\n    if (n == 1) return ret;\n    ret[2] = 1;\n    for (int i =\
    \ 3; i <= n; ++i) {\n        ret[i] = (ret[i - 1] + ret[i - 2]) * (i - 1);\n \
    \   }\n    return ret;\n}\n#line 5 \"test/yosupo/montmort_number_mod.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    using mint =\
    \ ArbitraryModint;\n    mint::set_mod(M);\n    vector<mint> ans = montmort<mint>(N);\n\
    \    for (int i = 1; i <= N; ++i) cout << ans[i] << (i < N ? \" \" : \"\\n\");\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/montmort_number_mod\"\n\
    \n#include \"../../math/arbitrary_modint.cpp\"\n#include \"../../math/montmort.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    using mint =\
    \ ArbitraryModint;\n    mint::set_mod(M);\n    vector<mint> ans = montmort<mint>(N);\n\
    \    for (int i = 1; i <= N; ++i) cout << ans[i] << (i < N ? \" \" : \"\\n\");\n\
    }"
  dependsOn:
  - math/arbitrary_modint.cpp
  - math/montmort.cpp
  isVerificationFile: true
  path: test/yosupo/montmort_number_mod.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 00:37:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/montmort_number_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/montmort_number_mod.test.cpp
- /verify/test/yosupo/montmort_number_mod.test.cpp.html
title: test/yosupo/montmort_number_mod.test.cpp
---
