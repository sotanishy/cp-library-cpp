---
data:
  _extendedDependsOn: []
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
    \ PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\n\n// #include\
    \ \"../../math/modint.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \ntemplate <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod\
    \ > 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
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
    \    }\n\nprivate:\n    int x;\n};\n\ntemplate <typename mint>\nstd::pair<std::vector<mint>,\
    \ std::vector<mint>> totient_summatory_table(long long n) {\n    if (n == 0) return\
    \ {{0}, {0}};\n    const int b = std::min(n, (long long) 1e4);\n    std::vector<mint>\
    \ small(n/b + 1), large(b + 1);\n\n    std::vector<int> totient(n/b + 1);\n  \
    \  std::iota(totient.begin(), totient.end(), 0);\n    for (int i = 2; i <= n/b;\
    \ ++i) {\n        if (totient[i] != i) continue;\n        for (int j = i; j <=\
    \ n/b; j += i) {\n            totient[j] = totient[j] / i * (i - 1);\n       \
    \ }\n    }\n    for (int i = 0; i < n/b; ++i) small[i+1] = small[i] + totient[i+1];\n\
    \n    for (int i = 1; i <= b; ++i) {\n        mint k = n / i;\n        large[i]\
    \ = k * (k + 1) / 2;\n    }\n    for (long long i = b; i >= 1; --i) {\n      \
    \  for (long long l = 2; l <= n/i; ) {\n            long long q = n/(i*l), r =\
    \ n/(i*q) + 1;\n            large[i] -= (i*l <= b ? large[i*l] : small[n/(i*l)])\
    \ * (r - l);\n            l = r;\n        }\n    }\n    return {small, large};\n\
    }\n\nstd::vector<int> euler_totient_table(int n) {\n    std::vector<int> ret(n\
    \ + 1);\n    std::iota(ret.begin(), ret.end(), 0);\n    for (int i = 2; i <= n;\
    \ ++i) {\n        if (ret[i] == i) {\n            for (int j = i; j <= n; j +=\
    \ i) {\n                ret[j] = ret[j] / i * (i - 1);\n            }\n      \
    \  }\n    }\n    return ret;\n}\n\nusing mint = Modint<998244353>;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    long\
    \ long N;\n    cin >> N;\n    auto [small, large] = totient_summatory_table<mint>(N);\n\
    \    mint ans = large[1];\n    cout << ans << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_totient_function\"\
    \n\n// #include \"../../math/modint.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <int mod>\nclass Modint {\n    using mint = Modint;\n    static_assert(mod\
    \ > 0, \"Modulus must be positive\");\n\npublic:\n    static constexpr int get_mod()\
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
    \    }\n\nprivate:\n    int x;\n};\n\ntemplate <typename mint>\nstd::pair<std::vector<mint>,\
    \ std::vector<mint>> totient_summatory_table(long long n) {\n    if (n == 0) return\
    \ {{0}, {0}};\n    const int b = std::min(n, (long long) 1e4);\n    std::vector<mint>\
    \ small(n/b + 1), large(b + 1);\n\n    std::vector<int> totient(n/b + 1);\n  \
    \  std::iota(totient.begin(), totient.end(), 0);\n    for (int i = 2; i <= n/b;\
    \ ++i) {\n        if (totient[i] != i) continue;\n        for (int j = i; j <=\
    \ n/b; j += i) {\n            totient[j] = totient[j] / i * (i - 1);\n       \
    \ }\n    }\n    for (int i = 0; i < n/b; ++i) small[i+1] = small[i] + totient[i+1];\n\
    \n    for (int i = 1; i <= b; ++i) {\n        mint k = n / i;\n        large[i]\
    \ = k * (k + 1) / 2;\n    }\n    for (long long i = b; i >= 1; --i) {\n      \
    \  for (long long l = 2; l <= n/i; ) {\n            long long q = n/(i*l), r =\
    \ n/(i*q) + 1;\n            large[i] -= (i*l <= b ? large[i*l] : small[n/(i*l)])\
    \ * (r - l);\n            l = r;\n        }\n    }\n    return {small, large};\n\
    }\n\nstd::vector<int> euler_totient_table(int n) {\n    std::vector<int> ret(n\
    \ + 1);\n    std::iota(ret.begin(), ret.end(), 0);\n    for (int i = 2; i <= n;\
    \ ++i) {\n        if (ret[i] == i) {\n            for (int j = i; j <= n; j +=\
    \ i) {\n                ret[j] = ret[j] / i * (i - 1);\n            }\n      \
    \  }\n    }\n    return ret;\n}\n\nusing mint = Modint<998244353>;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    long\
    \ long N;\n    cin >> N;\n    auto [small, large] = totient_summatory_table<mint>(N);\n\
    \    mint ans = large[1];\n    cout << ans << endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/sum_of_totient_function.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_totient_function.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_totient_function.test.cpp
- /verify/test/yosupo/sum_of_totient_function.test.cpp.html
title: test/yosupo/sum_of_totient_function.test.cpp
---
