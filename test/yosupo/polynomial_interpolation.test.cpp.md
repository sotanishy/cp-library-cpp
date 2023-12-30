---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: convolution/ntt.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: math/lagrange_polynomial.hpp
    title: Lagrange Polynomial
  - icon: ':question:'
    path: math/modint.cpp
    title: Mod int
  - icon: ':heavy_check_mark:'
    path: math/multipoint_evaluation.cpp
    title: Multipoint Evaluation
  - icon: ':question:'
    path: math/polynomial.cpp
    title: Polynomial
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/polynomial_interpolation
    links:
    - https://judge.yosupo.jp/problem/polynomial_interpolation
  bundledCode: "#line 1 \"test/yosupo/polynomial_interpolation.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\n\n#line\
    \ 2 \"math/modint.cpp\"\n#include <iostream>\n#include <algorithm>\n\n/**\n *\
    \ @brief Mod int\n */\ntemplate <int mod>\nclass Modint {\n    using mint = Modint;\n\
    \    static_assert(mod > 0, \"Modulus must be positive\");\n\npublic:\n    static\
    \ constexpr int get_mod() noexcept { return mod; }\n\n    constexpr Modint(long\
    \ long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod + mod) % mod) {}\n\n  \
    \  constexpr int value() const noexcept { return x; }\n\n    constexpr mint& operator+=(const\
    \ mint& r) noexcept { if ((x += r.x) >= mod) x -= mod; return *this; }\n    constexpr\
    \ mint& operator-=(const mint& r) noexcept { if ((x += mod - r.x) >= mod) x -=\
    \ mod; return *this; }\n    constexpr mint& operator*=(const mint& r) noexcept\
    \ { x = static_cast<int>(1LL * x * r.x % mod); return *this; }\n    constexpr\
    \ mint& operator/=(const mint& r) noexcept { *this *= r.inv(); return *this; }\n\
    \n    constexpr mint operator-() const noexcept { return mint(-x); }\n\n    constexpr\
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
    \    }\n\nprivate:\n    int x;\n};\n#line 2 \"math/lagrange_polynomial.hpp\"\n\
    #include <utility>\n#include <vector>\n\n#line 3 \"math/multipoint_evaluation.cpp\"\
    \n\n#line 3 \"math/polynomial.cpp\"\n#include <cassert>\n#line 5 \"math/polynomial.cpp\"\
    \n\n#line 3 \"convolution/ntt.hpp\"\n\nconstexpr int get_primitive_root(int mod)\
    \ {\n    if (mod == 167772161) return 3;\n    if (mod == 469762049) return 3;\n\
    \    if (mod == 754974721) return 11;\n    if (mod == 998244353) return 3;\n \
    \   if (mod == 1224736769) return 3;\n}\n\ntemplate <typename T>\nvoid bit_reverse(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int i = 0, j = 1; j < n - 1; ++j) {\n\
    \        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n        if (i < j) std::swap(a[i],\
    \ a[j]);\n    }\n}\n\ntemplate <typename mint>\nvoid ntt(std::vector<mint>& a,\
    \ bool ordered = false) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    int n = a.size();\n  \
    \  for (int m = n; m > 1; m >>= 1) {\n        mint omega = primitive_root.pow((mod\
    \ - 1) / m);\n        for (int s = 0; s < n / m; ++s) {\n            mint w =\
    \ 1;\n            for (int i = 0; i < m / 2; ++i) {\n                mint l =\
    \ a[s * m + i];\n                mint r = a[s * m + i + m / 2];\n            \
    \    a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = (l - r) * w;\n\
    \                w *= omega;\n            }\n        }\n    }\n    if (ordered)\
    \ bit_reverse(a);\n}\n\ntemplate <typename mint>\nvoid intt(std::vector<mint>&\
    \ a, bool ordered = false) {\n    constexpr int mod = mint::get_mod();\n    constexpr\
    \ mint primitive_root = get_primitive_root(mod);\n\n    if (ordered) bit_reverse(a);\n\
    \    int n = a.size();\n    for (int m = 2; m <= n; m <<= 1) {\n        mint omega\
    \ = primitive_root.pow((mod - 1) / m).inv();\n        for (int s = 0; s < n /\
    \ m; ++s) {\n            mint w = 1;\n            for (int i = 0; i < m / 2; ++i)\
    \ {\n                mint l = a[s * m + i];\n                mint r = a[s * m\
    \ + i + m / 2] * w;\n                a[s * m + i] = l + r;\n                a[s\
    \ * m + i + m / 2] = l - r;\n                w *= omega;\n            }\n    \
    \    }\n    }\n}\n\ntemplate <typename mint>\nstd::vector<mint> convolution(std::vector<mint>\
    \ a, std::vector<mint> b) {\n    int size = a.size() + b.size() - 1;\n    int\
    \ n = 1;\n    while (n < size) n <<= 1;\n    a.resize(n);\n    b.resize(n);\n\
    \    ntt(a);\n    ntt(b);\n    for (int i = 0; i < n; ++i) a[i] *= b[i];\n   \
    \ intt(a);\n    a.resize(size);\n    mint n_inv = mint(n).inv();\n    for (int\
    \ i = 0; i < size; ++i) a[i] *= n_inv;\n    return a;\n}\n#line 7 \"math/polynomial.cpp\"\
    \n\ntemplate <typename mint>\nclass Polynomial : public std::vector<mint> {\n\
    \    using Poly = Polynomial;\n\n   public:\n    using std::vector<mint>::vector;\n\
    \    using std::vector<mint>::operator=;\n\n    Poly pre(int size) const {\n \
    \       return Poly(this->begin(),\n                    this->begin() + std::min((int)this->size(),\
    \ size));\n    }\n\n    Poly rev(int deg = -1) const {\n        auto ret = *this;\n\
    \        if (deg != -1) ret.resize(deg, 0);\n        return Poly(ret.rbegin(),\
    \ ret.rend());\n    }\n\n    void trim() {\n        while (!this->empty() && this->back()\
    \ == 0) this->pop_back();\n    }\n\n    // --- unary operation ---\n\n    Poly&\
    \ operator-() const {\n        auto ret = *this;\n        for (auto& x : ret)\
    \ x = -x;\n        return ret;\n    }\n\n    // -- binary operation with scalar\
    \ ---\n\n    Poly& operator+=(const mint& rhs) {\n        if (this->empty()) this->resize(1);\n\
    \        (*this)[0] += rhs;\n        return *this;\n    }\n\n    Poly& operator-=(const\
    \ mint& rhs) {\n        if (this->empty()) this->resize(1);\n        (*this)[0]\
    \ -= rhs;\n        return *this;\n    }\n\n    Poly& operator*=(const mint& rhs)\
    \ {\n        for (auto& x : *this) x *= rhs;\n        return *this;\n    }\n\n\
    \    Poly& operator/=(const mint& rhs) { return *this *= rhs.inv(); }\n\n    Poly\
    \ operator+(const mint& rhs) const { return Poly(*this) += rhs; }\n    Poly operator-(const\
    \ mint& rhs) const { return Poly(*this) -= rhs; }\n    Poly operator*(const mint&\
    \ rhs) const { return Poly(*this) *= rhs; }\n    Poly operator/(const mint& rhs)\
    \ const { return Poly(*this) /= rhs; }\n\n    // --- binary operation with polynomial\
    \ ---\n\n    Poly& operator+=(const Poly& rhs) {\n        if (this->size() < rhs.size())\
    \ this->resize(rhs.size());\n        for (int i = 0; i < (int)rhs.size(); ++i)\
    \ (*this)[i] += rhs[i];\n        return *this;\n    }\n\n    Poly& operator-=(const\
    \ Poly& rhs) {\n        if (this->size() < rhs.size()) this->resize(rhs.size());\n\
    \        for (int i = 0; i < (int)rhs.size(); ++i) (*this)[i] -= rhs[i];\n   \
    \     return *this;\n    }\n\n    Poly& operator*=(const Poly& rhs) {\n      \
    \  *this = convolution(*this, rhs);\n        return *this;\n        // // naive\
    \ convolution O(N^2)\n        // std::vector<mint> res(this->size() + rhs.size()\
    \ - 1);\n        // for (int i = 0; i < (int)this->size(); ++i) {\n        //\
    \     for (int j = 0; j < (int)rhs.size(); ++j) {\n        //         res[i +\
    \ j] += (*this)[i] * rhs[j];\n        //     }\n        // }\n        // return\
    \ *this = res;\n    }\n\n    Poly& operator/=(const Poly& rhs) {\n        if (this->size()\
    \ < rhs.size()) {\n            this->clear();\n            return *this;\n   \
    \     }\n        int n = this->size() - rhs.size() + 1;\n        return *this\
    \ = (rev().pre(n) * rhs.rev().inv(n)).pre(n).rev(n);\n    }\n\n    Poly& operator%=(const\
    \ Poly& rhs) {\n        *this -= *this / rhs * rhs;\n        trim();\n       \
    \ return *this;\n    }\n\n    std::pair<Poly, Poly> divmod(const Poly& rhs) {\n\
    \        auto q = *this / rhs;\n        auto r = *this - q * rhs;\n        r.trim();\n\
    \        return {q, r};\n    }\n\n    Poly operator+(const Poly& rhs) const {\
    \ return Poly(*this) += rhs; }\n    Poly operator-(const Poly& rhs) const { return\
    \ Poly(*this) -= rhs; }\n    Poly operator*(const Poly& rhs) const { return Poly(*this)\
    \ *= rhs; }\n    Poly operator/(const Poly& rhs) const { return Poly(*this) /=\
    \ rhs; }\n    Poly operator%(const Poly& rhs) const { return Poly(*this) %= rhs;\
    \ }\n\n    // --- shift operation ---\n\n    Poly operator<<(int n) const {\n\
    \        auto ret = *this;\n        ret.insert(ret.begin(), n, 0);\n        return\
    \ ret;\n    }\n\n    Poly operator>>(int n) const {\n        if ((int)this->size()\
    \ <= n) return {};\n        auto ret = *this;\n        ret.erase(ret.begin(),\
    \ ret.begin() + n);\n        return ret;\n    }\n\n    // --- evaluation ---\n\
    \n    mint operator()(const mint& x) {\n        mint y = 0, powx = 1;\n      \
    \  for (int i = 0; i < (int)this->size(); ++i) {\n            for (auto c : *this)\
    \ {\n                y += c * powx;\n                powx *= x;\n            }\n\
    \            return y;\n        }\n    }\n\n    // --- other operations ---\n\n\
    \    Poly inv(int deg = -1) const {\n        assert((*this)[0] != mint(0));\n\
    \        if (deg == -1) deg = this->size();\n        Poly res = {(*this)[0].inv()};\n\
    \        for (int d = 1; d < deg; d <<= 1) {\n            auto f = pre(2 * d);\n\
    \            auto g = res;\n            f.resize(2 * d);\n            g.resize(2\
    \ * d);\n\n            // g_{n+1} = g_n * (2 - g_n * f) mod x^{2^{n+1}}\n\n  \
    \          ntt(f);\n            ntt(g);\n            for (int i = 0; i < 2 * d;\
    \ ++i) f[i] *= g[i];\n            intt(f);\n\n            for (int i = 0; i <\
    \ d; ++i) f[i] = 0;\n\n            ntt(f);\n            for (int i = 0; i < 2\
    \ * d; ++i) f[i] *= g[i];\n            intt(f);\n\n            res.resize(2 *\
    \ d);\n            auto coef = mint(2 * d).inv().pow(2);\n            for (int\
    \ i = d; i < 2 * d; ++i) res[i] = -f[i] * coef;\n        }\n        return res.pre(deg);\n\
    \    }\n\n    Poly exp(int deg = -1) const {\n        assert((*this)[0] == mint(0));\n\
    \        if (deg == -1) deg = this->size();\n        Poly ret = {mint(1)};\n \
    \       for (int i = 1; i < deg; i <<= 1) {\n            ret = (ret * (this->pre(i\
    \ << 1) + mint(1) - ret.log(i << 1)))\n                      .pre(i << 1);\n \
    \       }\n        return ret;\n    }\n\n    Poly log(int deg = -1) const {\n\
    \        assert((*this)[0] == mint(1));\n        if (deg == -1) deg = this->size();\n\
    \        return (diff() * inv(deg)).pre(deg - 1).integral();\n    }\n\n    Poly\
    \ pow(long long k, int deg = -1) const {\n        if (k == 0) return {1};\n  \
    \      if (deg == -1) deg = this->size();\n        auto ret = *this;\n       \
    \ int cnt0 = 0;\n        while (cnt0 < (int)ret.size() && ret[cnt0] == 0) ++cnt0;\n\
    \        if (cnt0 > (deg - 1) / k) return {};\n        ret = ret >> cnt0;\n  \
    \      deg -= cnt0 * k;\n        ret = ((ret / ret[0]).log(deg) * k).exp(deg)\
    \ * ret[0].pow(k);\n        ret = ret << (cnt0 * k);\n        return ret;\n  \
    \  }\n\n    Poly diff() const {\n        Poly ret(std::max(0, (int)this->size()\
    \ - 1));\n        for (int i = 1; i <= (int)ret.size(); ++i)\n            ret[i\
    \ - 1] = (*this)[i] * mint(i);\n        return ret;\n    }\n\n    Poly integral()\
    \ const {\n        Poly ret(this->size() + 1);\n        ret[0] = mint(0);\n  \
    \      for (int i = 0; i < (int)ret.size() - 1; ++i)\n            ret[i + 1] =\
    \ (*this)[i] / mint(i + 1);\n        return ret;\n    }\n\n    Poly taylor_shift(long\
    \ long c) const {\n        const int n = this->size();\n        std::vector<mint>\
    \ fact(n, 1), fact_inv(n, 1);\n        for (int i = 1; i < n; ++i) fact[i] = fact[i\
    \ - 1] * i;\n        fact_inv[n - 1] = mint(1) / fact[n - 1];\n        for (int\
    \ i = n - 1; i > 0; --i) fact_inv[i - 1] = fact_inv[i] * i;\n\n        auto ret\
    \ = *this;\n        Poly e(n + 1);\n        e[0] = 1;\n        mint p = c;\n \
    \       for (int i = 1; i < n; ++i) {\n            ret[i] *= fact[i];\n      \
    \      e[i] = p * fact_inv[i];\n            p *= c;\n        }\n        ret =\
    \ (ret.rev() * e).pre(n).rev();\n        for (int i = n - 1; i >= 0; --i) {\n\
    \            ret[i] *= fact_inv[i];\n        }\n        return ret;\n    }\n};\n\
    #line 5 \"math/multipoint_evaluation.cpp\"\n\ntemplate <typename T>\nstd::vector<T>\
    \ multipoint_evaluation(const Polynomial<T>& p,\n                            \
    \         const std::vector<T>& x) {\n    int m = x.size();\n    int n = 1;\n\
    \    while (n < m) n <<= 1;\n    std::vector<Polynomial<T>> q(2 * n, {1});\n \
    \   for (int i = 0; i < m; ++i) q[n + i] = {-x[i], 1};\n    for (int i = n - 1;\
    \ i > 0; --i) q[i] = q[2 * i] * q[2 * i + 1];\n    q[1] = p % q[1];\n    for (int\
    \ i = 2; i < n + m; ++i) q[i] = q[i / 2] % q[i];\n    std::vector<T> y(m);\n \
    \   for (int i = 0; i < m; ++i) y[i] = q[n + i].empty() ? 0 : q[n + i][0];\n \
    \   return y;\n}\n#line 7 \"math/lagrange_polynomial.hpp\"\n\ntemplate <typename\
    \ T>\nPolynomial<T> lagrange_polynomial(const std::vector<T>& x,\n           \
    \                       const std::vector<T>& y) {\n    int n = x.size();\n  \
    \  int sz = 1;\n    while (sz < n) sz <<= 1;\n\n    auto rec = [&](auto& rec,\
    \ int l, int r) -> Polynomial<T> {\n        if (r - l == 1) {\n            return\
    \ {-x[l], 1};\n        }\n        int m = (l + r) / 2;\n        return rec(rec,\
    \ l, m) * rec(rec, m, r);\n    };\n\n    auto g = rec(rec, 0, n);\n    auto dg\
    \ = multipoint_evaluation(g.diff(), x);\n\n    auto rec2 = [&](auto& rec2, int\
    \ l,\n                    int r) -> std::pair<Polynomial<T>, Polynomial<T>> {\n\
    \        if (r - l == 1) {\n            return {{y[l] / dg[l]}, {-x[l], 1}};\n\
    \        }\n        int m = (l + r) / 2;\n        auto [pl, ql] = rec2(rec2, l,\
    \ m);\n        auto [pr, qr] = rec2(rec2, m, r);\n        return {pl * qr + pr\
    \ * ql, ql * qr};\n    };\n\n    return rec2(rec2, 0, n).first;\n}\n#line 5 \"\
    test/yosupo/polynomial_interpolation.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n#define rep(i, s, t) for (int i =\
    \ (int)(s); i < (int)(t); ++i)\n#define revrep(i, t, s) for (int i = (int)(t)-1;\
    \ i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\ntemplate <typename T>\n\
    bool chmax(T& a, const T& b) {\n    return a < b ? (a = b, 1) : 0;\n}\ntemplate\
    \ <typename T>\nbool chmin(T& a, const T& b) {\n    return a > b ? (a = b, 1)\
    \ : 0;\n}\n\nusing mint = Modint<998244353>;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int N;\n\
    \    cin >> N;\n    vector<mint> x(N), y(N);\n    for (auto& a : x) cin >> a;\n\
    \    for (auto& a : y) cin >> a;\n    auto p = lagrange_polynomial(x, y);\n  \
    \  rep(i, 0, N) cout << p[i] << (i < N - 1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/polynomial_interpolation\"\
    \n\n#include \"../../math/modint.cpp\"\n#include \"../../math/lagrange_polynomial.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)\n#define revrep(i, t,\
    \ s) for (int i = (int)(t)-1; i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\n\
    template <typename T>\nbool chmax(T& a, const T& b) {\n    return a < b ? (a =\
    \ b, 1) : 0;\n}\ntemplate <typename T>\nbool chmin(T& a, const T& b) {\n    return\
    \ a > b ? (a = b, 1) : 0;\n}\n\nusing mint = Modint<998244353>;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout <<\
    \ fixed << setprecision(15);\n\n    int N;\n    cin >> N;\n    vector<mint> x(N),\
    \ y(N);\n    for (auto& a : x) cin >> a;\n    for (auto& a : y) cin >> a;\n  \
    \  auto p = lagrange_polynomial(x, y);\n    rep(i, 0, N) cout << p[i] << (i <\
    \ N - 1 ? \" \" : \"\\n\");\n}"
  dependsOn:
  - math/modint.cpp
  - math/lagrange_polynomial.hpp
  - math/multipoint_evaluation.cpp
  - math/polynomial.cpp
  - convolution/ntt.hpp
  isVerificationFile: true
  path: test/yosupo/polynomial_interpolation.test.cpp
  requiredBy: []
  timestamp: '2023-12-24 17:02:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/polynomial_interpolation.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/polynomial_interpolation.test.cpp
- /verify/test/yosupo/polynomial_interpolation.test.cpp.html
title: test/yosupo/polynomial_interpolation.test.cpp
---
