---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: math/formal_power_series.cpp
    title: Formal Power Series
  - icon: ':question:'
    path: math/modint.cpp
    title: math/modint.cpp
  - icon: ':question:'
    path: math/ntt.cpp
    title: Number Theoretic Transform
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/pow_of_formal_power_series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\n\n#line\
    \ 2 \"math/modint.cpp\"\n#include <bits/stdc++.h>\n\ntemplate <int mod>\nclass\
    \ Modint {\n    static_assert(mod > 0, \"Modulus must be positive\");\n\npublic:\n\
    \    static constexpr int get_mod() noexcept { return mod; }\n\n    constexpr\
    \ Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod)\
    \ {}\n\n    constexpr int value() const noexcept { return x; }\n\n    constexpr\
    \ Modint& operator+=(const Modint& p) noexcept { if ((x += p.x) >= mod) x -= mod;\
    \ return *this; }\n    constexpr Modint& operator-=(const Modint& p) noexcept\
    \ { if ((x += mod - p.x) >= mod) x -= mod; return *this; }\n    constexpr Modint&\
    \ operator*=(const Modint& p) noexcept { x = static_cast<int>(1LL * x * p.x %\
    \ mod); return *this; }\n    constexpr Modint& operator/=(const Modint& p) noexcept\
    \ { *this *= p.inv(); return *this; }\n\n    constexpr Modint operator-() const\
    \ noexcept { return Modint(-x); }\n\n    constexpr Modint operator+(const Modint&\
    \ p) const noexcept { return Modint(*this) += p; }\n    constexpr Modint operator-(const\
    \ Modint& p) const noexcept { return Modint(*this) -= p; }\n    constexpr Modint\
    \ operator*(const Modint& p) const noexcept { return Modint(*this) *= p; }\n \
    \   constexpr Modint operator/(const Modint& p) const noexcept { return Modint(*this)\
    \ /= p; }\n\n    constexpr bool operator==(const Modint& p) const noexcept { return\
    \ x == p.x; }\n    constexpr bool operator!=(const Modint& p) const noexcept {\
    \ return x != p.x; }\n\n    constexpr Modint inv() const noexcept {\n        int\
    \ a = x, b = mod, u = 1, v = 0;\n        while (b > 0) {\n            int t =\
    \ a / b;\n            std::swap(a -= t * b, b);\n            std::swap(u -= t\
    \ * v, v);\n        }\n        return Modint(u);\n    }\n\n    constexpr Modint\
    \ pow(long long n) const noexcept {\n        Modint ret(1), mul(x);\n        while\
    \ (n > 0) {\n            if (n & 1) ret *= mul;\n            mul *= mul;\n   \
    \         n >>= 1;\n        }\n        return ret;\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream& os, const Modint& p) {\n        return os << p.x;\n\
    \    }\n\n    friend std::istream &operator>>(std::istream& is, Modint& a) {\n\
    \        long long t;\n        is >> t;\n        a = Modint<mod>(t);\n       \
    \ return is;\n    }\n\nprivate:\n    int x;\n};\n#line 2 \"math/ntt.cpp\"\n\n\
    /*\n * @brief Number Theoretic Transform\n * @docs docs/math/ntt.md\n */\ntemplate\
    \ <typename mint>\nclass NTT {\npublic:\n    NTT() = delete;\n\n    static std::vector<mint>\
    \ convolution(const std::vector<mint>& a, const std::vector<mint>& b) {\n    \
    \    int size = a.size() + b.size() - 1;\n        int n = 1;\n        while (n\
    \ < size) n <<= 1;\n        std::vector<mint> na(n), nb(n);\n        for (int\
    \ i = 0; i < (int) a.size(); ++i) na[i] = a[i];\n        for (int i = 0; i < (int)\
    \ b.size(); ++i) nb[i] = b[i];\n        untt(na);\n        untt(nb);\n       \
    \ for (int i = 0; i < n; ++i) na[i] *= nb[i];\n        iuntt(na);\n        na.resize(size);\n\
    \        mint n_inv = mint(n).inv();\n        for (int i = 0; i < size; ++i) na[i]\
    \ *= n_inv;\n        return na;\n    }\n\nprivate:\n    static constexpr mint\
    \ get_primitive_root(int mod) {\n        if (mod == 167772161) return 3;\n   \
    \     if (mod == 469762049) return 3;\n        if (mod == 754974721) return 11;\n\
    \        if (mod == 998244353) return 3;\n        if (mod == 1224736769) return\
    \ 3;\n        mint r = 2;\n        while (r.pow((mod - 1) >> 1) == 1) r += 1;\n\
    \        return r;\n    }\n\n    static constexpr int mod = mint::get_mod();\n\
    \    static constexpr mint primitive_root = get_primitive_root(mod);\n\n    static\
    \ void untt(std::vector<mint>& a) {\n        int n = a.size();\n        for (int\
    \ m = n; m > 1; m >>= 1) {\n            mint omega = primitive_root.pow((mod -\
    \ 1) / m);\n            for (int s = 0; s < n / m; ++s) {\n                mint\
    \ w = 1;\n                for (int i = 0; i < m / 2; ++i) {\n                \
    \    mint l = a[s * m + i];\n                    mint r = a[s * m + i + m / 2];\n\
    \                    a[s * m + i] = l + r;\n                    a[s * m + i +\
    \ m / 2] = (l - r) * w;\n                    w *= omega;\n                }\n\
    \            }\n        }\n    }\n\n    static void iuntt(std::vector<mint>& a)\
    \ {\n        int n = a.size();\n        for (int m = 2; m <= n; m <<= 1) {\n \
    \           mint omega = primitive_root.pow((mod - 1) / m).inv();\n          \
    \  for (int s = 0; s < n / m; ++s) {\n                mint w = 1;\n          \
    \      for (int i = 0; i < m / 2; ++i) {\n                    mint l = a[s * m\
    \ + i];\n                    mint r = a[s * m + i + m / 2] * w;\n            \
    \        a[s * m + i] = l + r;\n                    a[s * m + i + m / 2] = l -\
    \ r;\n                    w *= omega;\n                }\n            }\n    \
    \    }\n    }\n};\n#line 3 \"math/formal_power_series.cpp\"\n\n/*\n * @brief Formal\
    \ Power Series\n */\ntemplate <typename mint>\nclass FormalPowerSeries : public\
    \ std::vector<mint> {\n    using FPS = FormalPowerSeries;\n\npublic:\n    using\
    \ std::vector<mint>::vector;\n\n    FPS& operator+=(const FPS& rhs) {\n      \
    \  if (this->size() < rhs.size()) this->resize(rhs.size());\n        for (int\
    \ i = 0; i < (int) rhs.size(); ++i) (*this)[i] += rhs[i];\n        return *this;\n\
    \    }\n\n    FPS& operator+=(const mint& rhs) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += rhs;\n        return *this;\n    }\n\n    FPS& operator-=(const\
    \ FPS& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int) rhs.size(); ++i) (*this)[i] -= rhs[i];\n  \
    \      return *this;\n    }\n\n    FPS& operator-=(const mint& rhs) {\n      \
    \  if (this->empty()) this->resize(1);\n        (*this)[0] -= rhs;\n        return\
    \ *this;\n    }\n\n    FPS& operator*=(const FPS& rhs) {\n        *this = NTT<mint>::convolution(*this,\
    \ rhs);\n        return *this;\n    }\n\n    FPS& operator*=(const mint& rhs)\
    \ {\n        for (int i = 0; i < (int) this->size(); ++i) (*this)[i] *= rhs;\n\
    \        return *this;\n    }\n\n    FPS& operator-() const {\n        FPS ret(this->size());\n\
    \        for (int i = 0; i < (int) this->size(); ++i) ret[i] = -(*this)[i];\n\
    \        return ret;\n    }\n\n    FPS operator+(const FPS& rhs) const { return\
    \ FPS(*this) += rhs; }\n    FPS operator+(const mint& rhs) const { return FPS(*this)\
    \ += rhs; }\n    FPS operator-(const FPS& rhs) const { return FPS(*this) -= rhs;\
    \ }\n    FPS operator-(const mint& rhs) const { return FPS(*this) -= rhs; }\n\
    \    FPS operator*(const FPS& rhs) const { return FPS(*this) *= rhs; }\n    FPS\
    \ operator*(const mint& rhs) const { return FPS(*this) *= rhs; }\n\n    FPS inv(int\
    \ deg = -1) const {\n        assert((*this)[0] != mint(0));\n        if (deg ==\
    \ -1) deg = this->size();\n        FPS ret({mint(1) / (*this)[0]});\n        for\
    \ (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * mint(2) - ret * ret\
    \ * this->pre(i << 1)).pre(i << 1);\n        }\n        return ret;\n    }\n\n\
    \    FPS exp(int deg = -1) const {\n        assert((*this)[0] == mint(0));\n \
    \       if (deg == -1) deg = this->size();\n        FPS ret({mint(1)});\n    \
    \    for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (this->pre(i\
    \ << 1) + mint(1) - ret.log(i << 1))).pre(i << 1);\n        }\n        return\
    \ ret;\n    }\n\n    FPS log(int deg = -1) const {\n        assert((*this)[0]\
    \ == mint(1));\n        if (deg == -1) deg = this->size();\n        return (this->diff()\
    \ * this->inv(deg)).pre(deg - 1).integral();\n    }\n\n    FPS pow(long long k,\
    \ int deg = -1) const {\n        if (deg == -1) deg = this->size();\n        FPS\
    \ ret(*this);\n        int cnt = 0;\n        while (cnt < (int) ret.size() &&\
    \ ret[cnt] == mint(0)) ++cnt;\n        if (cnt * k >= deg) return FPS(deg, mint(0));\n\
    \        ret.erase(ret.begin(), ret.begin() + cnt);\n        deg -= cnt * k;\n\
    \        ret = ((ret * mint(ret[0]).inv()).log(deg) * mint(k)).pre(deg).exp(deg)\
    \ * mint(ret[0]).pow(k);\n        ret.insert(ret.begin(), cnt * k, mint(0));\n\
    \        return ret;\n    }\n\n    FPS diff() const {\n        FPS ret(max(0,\
    \ (int) this->size() - 1));\n        for (int i = 1; i <= (int) ret.size(); ++i)\
    \ ret[i - 1] = (*this)[i] * mint(i);\n        return ret;\n    }\n\n    FPS integral()\
    \ const {\n        FPS ret(this->size() + 1);\n        ret[0] = mint(0);\n   \
    \     for (int i = 0; i < (int) ret.size() - 1; ++i) ret[i + 1] = (*this)[i] /\
    \ mint(i + 1);\n        return ret;\n    }\n\nprivate:\n    FPS pre(int size)\
    \ const { return FPS(this->begin(), this->begin() + min((int) this->size(), size));\
    \ }\n};\n#line 5 \"test/yosupo/pow_of_formal_power_series.test.cpp\"\n\nusing\
    \ namespace std;\nusing mint = Modint<998244353>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    FormalPowerSeries<mint>\
    \ f(N);\n    for (int i = 0; i < N; ++i) cin >> f[i];\n    auto g = f.pow(M);\n\
    \    for (int i = 0; i < N; ++i) cout << g[i] << (i < N - 1 ? \" \" : \"\\n\"\
    );\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include \"../../math/modint.cpp\"\n#include \"../../math/formal_power_series.cpp\"\
    \n\nusing namespace std;\nusing mint = Modint<998244353>;\n\nint main() {\n  \
    \  ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N, M;\n\
    \    cin >> N >> M;\n    FormalPowerSeries<mint> f(N);\n    for (int i = 0; i\
    \ < N; ++i) cin >> f[i];\n    auto g = f.pow(M);\n    for (int i = 0; i < N; ++i)\
    \ cout << g[i] << (i < N - 1 ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - math/modint.cpp
  - math/formal_power_series.cpp
  - math/ntt.cpp
  isVerificationFile: true
  path: test/yosupo/pow_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2020-10-12 18:08:02+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/pow_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/pow_of_formal_power_series.test.cpp
- /verify/test/yosupo/pow_of_formal_power_series.test.cpp.html
title: test/yosupo/pow_of_formal_power_series.test.cpp
---
