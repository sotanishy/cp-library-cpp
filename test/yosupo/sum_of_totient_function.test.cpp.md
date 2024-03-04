---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.hpp
    title: Mod int
  - icon: ':heavy_check_mark:'
    path: math/number-theory/euler_totient.hpp
    title: Euler's Totient Function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_totient_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_totient_function
  bundledCode: "#line 1 \"test/yosupo/sum_of_totient_function.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 4 \"math/modint.hpp\"\n\n/**\n * @brief Mod int\n */\n\
    template <int m>\nclass Modint {\n    using mint = Modint;\n    static_assert(m\
    \ > 0, \"Modulus must be positive\");\n\n   public:\n    static constexpr int\
    \ mod() { return m; }\n\n    constexpr Modint(long long y = 0) : x(y >= 0 ? y\
    \ % m : (y % m + m) % m) {}\n\n    constexpr int val() const { return x; }\n\n\
    \    constexpr mint& operator+=(const mint& r) {\n        if ((x += r.x) >= m)\
    \ x -= m;\n        return *this;\n    }\n    constexpr mint& operator-=(const\
    \ mint& r) {\n        if ((x += m - r.x) >= m) x -= m;\n        return *this;\n\
    \    }\n    constexpr mint& operator*=(const mint& r) {\n        x = static_cast<int>(1LL\
    \ * x * r.x % m);\n        return *this;\n    }\n    constexpr mint& operator/=(const\
    \ mint& r) { return *this *= r.inv(); }\n\n    constexpr bool operator==(const\
    \ mint& r) const { return x == r.x; }\n\n    constexpr mint operator+() const\
    \ { return *this; }\n    constexpr mint operator-() const { return mint(-x); }\n\
    \n    constexpr friend mint operator+(const mint& l, const mint& r) {\n      \
    \  return mint(l) += r;\n    }\n    constexpr friend mint operator-(const mint&\
    \ l, const mint& r) {\n        return mint(l) -= r;\n    }\n    constexpr friend\
    \ mint operator*(const mint& l, const mint& r) {\n        return mint(l) *= r;\n\
    \    }\n    constexpr friend mint operator/(const mint& l, const mint& r) {\n\
    \        return mint(l) /= r;\n    }\n\n    constexpr mint inv() const {\n   \
    \     int a = x, b = m, u = 1, v = 0;\n        while (b > 0) {\n            int\
    \ t = a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u -=\
    \ t * v, v);\n        }\n        return mint(u);\n    }\n\n    constexpr mint\
    \ pow(long long n) const {\n        mint ret(1), mul(x);\n        while (n > 0)\
    \ {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n           \
    \ n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const mint& r) {\n        return os << r.x;\n \
    \   }\n\n    friend std::istream& operator>>(std::istream& is, mint& r) {\n  \
    \      long long t;\n        is >> t;\n        r = mint(t);\n        return is;\n\
    \    }\n\n   private:\n    int x;\n};\n#line 4 \"math/number-theory/euler_totient.hpp\"\
    \n\nlong long euler_totient(long long n) {\n    long long ret = n;\n    if (n\
    \ % 2 == 0) {\n        ret -= ret / 2;\n        while (n % 2 == 0) n /= 2;\n \
    \   }\n    for (long long i = 3; i * i <= n; i += 2) {\n        if (n % i == 0)\
    \ {\n            ret -= ret / i;\n            while (n % i == 0) n /= i;\n   \
    \     }\n    }\n    if (n != 1) ret -= ret / n;\n    return ret;\n}\n\nstd::vector<int>\
    \ euler_totient_table(int n) {\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(),\
    \ ret.end(), 0);\n    for (int i = 2; i <= n; ++i) {\n        if (ret[i] == i)\
    \ {\n            for (int j = i; j <= n; j += i) {\n                ret[j] = ret[j]\
    \ / i * (i - 1);\n            }\n        }\n    }\n    return ret;\n}\n\ntemplate\
    \ <typename mint>\nstd::pair<std::vector<mint>, std::vector<mint>> totient_summatory_table(\n\
    \    long long n) {\n    if (n == 0) return {{0}, {0}};\n    const int b = std::min(n,\
    \ (long long)1e4);\n    std::vector<mint> small(n / b + 1), large(b + 1);\n\n\
    \    std::vector<int> totient(n / b + 1);\n    std::iota(totient.begin(), totient.end(),\
    \ 0);\n    for (int i = 2; i <= n / b; ++i) {\n        if (totient[i] != i) continue;\n\
    \        for (int j = i; j <= n / b; j += i) {\n            totient[j] = totient[j]\
    \ / i * (i - 1);\n        }\n    }\n    for (int i = 0; i < n / b; ++i) small[i\
    \ + 1] = small[i] + totient[i + 1];\n\n    for (int i = 1; i <= b; ++i) {\n  \
    \      mint k = n / i;\n        large[i] = k * (k + 1) / 2;\n    }\n    for (long\
    \ long i = b; i >= 1; --i) {\n        for (long long l = 2; l <= n / i;) {\n \
    \           long long q = n / (i * l), r = n / (i * q) + 1;\n            large[i]\
    \ -=\n                (i * l <= b ? large[i * l] : small[n / (i * l)]) * (r -\
    \ l);\n            l = r;\n        }\n    }\n    return {small, large};\n}\n#line\
    \ 7 \"test/yosupo/sum_of_totient_function.test.cpp\"\nusing namespace std;\n\n\
    using mint = Modint<998244353>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    long long N;\n    cin >> N;\n    auto [small, large]\
    \ = totient_summatory_table<mint>(N);\n    mint ans = large[1];\n    cout << ans\
    \ << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/modint.hpp\"\n#include \"\
    ../../math/number-theory/euler_totient.hpp\"\nusing namespace std;\n\nusing mint\
    \ = Modint<998244353>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    long long N;\n    cin >> N;\n    auto [small, large]\
    \ = totient_summatory_table<mint>(N);\n    mint ans = large[1];\n    cout << ans\
    \ << endl;\n}"
  dependsOn:
  - math/modint.hpp
  - math/number-theory/euler_totient.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.test.cpp
- /verify/test/yosupo/sum_of_totient_function.test.cpp.html
title: test/yosupo/sum_of_totient_function.test.cpp
---
