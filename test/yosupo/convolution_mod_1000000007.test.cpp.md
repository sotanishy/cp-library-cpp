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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/yosupo/convolution_mod_1000000007.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\n\n//\
    \ #include \"../../graph/chromatic_number.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\ntemplate <int mod>\nclass Modint\
    \ {\n    using mint = Modint;\n    static_assert(mod > 0, \"Modulus must be positive\"\
    );\n\npublic:\n    static constexpr int get_mod() noexcept { return mod; }\n\n\
    \    constexpr Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod\
    \ + mod) % mod) {}\n\n    constexpr int value() const noexcept { return x; }\n\
    \n    constexpr mint& operator+=(const mint& r) noexcept { if ((x += r.x) >= mod)\
    \ x -= mod; return *this; }\n    constexpr mint& operator-=(const mint& r) noexcept\
    \ { if ((x += mod - r.x) >= mod) x -= mod; return *this; }\n    constexpr mint&\
    \ operator*=(const mint& r) noexcept { x = static_cast<int>(1LL * x * r.x % mod);\
    \ return *this; }\n    constexpr mint& operator/=(const mint& r) noexcept { *this\
    \ *= r.inv(); return *this; }\n\n    constexpr mint operator-() const noexcept\
    \ { return mint(-x); }\n\n    constexpr mint operator+(const mint& r) const noexcept\
    \ { return mint(*this) += r; }\n    constexpr mint operator-(const mint& r) const\
    \ noexcept { return mint(*this) -= r; }\n    constexpr mint operator*(const mint&\
    \ r) const noexcept { return mint(*this) *= r; }\n    constexpr mint operator/(const\
    \ mint& r) const noexcept { return mint(*this) /= r; }\n\n    constexpr bool operator==(const\
    \ mint& r) const noexcept { return x == r.x; }\n    constexpr bool operator!=(const\
    \ mint& r) const noexcept { return x != r.x; }\n\n    constexpr mint inv() const\
    \ noexcept {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0)\
    \ {\n            int t = a / b;\n            std::swap(a -= t * b, b);\n     \
    \       std::swap(u -= t * v, v);\n        }\n        return mint(u);\n    }\n\
    \n    constexpr mint pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend std::ostream& operator<<(std::ostream& os, const mint& r) {\n       \
    \ return os << r.x;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& r) {\n        long long t;\n        is >> t;\n        r = mint(t);\n\
    \        return is;\n    }\n\nprivate:\n    int x;\n};\n\ntemplate <typename mint>\n\
    class NTT {\npublic:\n    NTT() = delete;\n\n    static std::vector<mint> convolve(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n        int size = a.size()\
    \ + b.size() - 1;\n        int n = 1;\n        while (n < size) n <<= 1;\n   \
    \     std::vector<mint> na(a.begin(), a.end()), nb(b.begin(), b.end());\n    \
    \    na.resize(n);\n        nb.resize(n);\n        ntt(na, false);\n        ntt(nb,\
    \ false);\n        for (int i = 0; i < n; ++i) na[i] *= nb[i];\n        intt(na,\
    \ false);\n        na.resize(size);\n        mint n_inv = mint(n).inv();\n   \
    \     for (int i = 0; i < size; ++i) na[i] *= n_inv;\n        return na;\n   \
    \ }\n\n    static void ntt(std::vector<mint>& a, bool ordered = true) {\n    \
    \    int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n          \
    \  mint omega = primitive_root.pow((mod - 1) / m);\n            for (int s = 0;\
    \ s < n / m; ++s) {\n                mint w = 1;\n                for (int i =\
    \ 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n         \
    \           mint r = a[s * m + i + m / 2];\n                    a[s * m + i] =\
    \ l + r;\n                    a[s * m + i + m / 2] = (l - r) * w;\n          \
    \          w *= omega;\n                }\n            }\n        }\n        if\
    \ (ordered) bit_reverse(a);\n    }\n\n    static void intt(std::vector<mint>&\
    \ a, bool ordered = true) {\n        if (ordered) bit_reverse(a);\n        int\
    \ n = a.size();\n        for (int m = 2; m <= n; m <<= 1) {\n            mint\
    \ omega = primitive_root.pow((mod - 1) / m).inv();\n            for (int s = 0;\
    \ s < n / m; ++s) {\n                mint w = 1;\n                for (int i =\
    \ 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n         \
    \           mint r = a[s * m + i + m / 2] * w;\n                    a[s * m +\
    \ i] = l + r;\n                    a[s * m + i + m / 2] = l - r;\n           \
    \         w *= omega;\n                }\n            }\n        }\n    }\n\n\
    private:\n    static constexpr mint get_primitive_root(int mod) {\n        if\
    \ (mod == 167772161) return 3;\n        if (mod == 469762049) return 3;\n    \
    \    if (mod == 754974721) return 11;\n        if (mod == 998244353) return 3;\n\
    \        if (mod == 1224736769) return 3;\n    }\n\n    static constexpr int mod\
    \ = mint::get_mod();\n    static constexpr mint primitive_root = get_primitive_root(mod);\n\
    \n    static void bit_reverse(std::vector<mint>& a) {\n        int n = a.size();\n\
    \        for (int i = 0, j = 1; j < n - 1; ++j) {\n            for (int k = n\
    \ >> 1; k > (i ^= k); k >>= 1);\n            if (i < j) std::swap(a[i], a[j]);\n\
    \        }\n    }\n};\n\nstd::pair<long long, long long> extgcd(long long a, long\
    \ long b) {\n    long long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;\n   \
    \ while (t) {\n        long long q = s / t;\n        std::swap(s -= t * q, t);\n\
    \        std::swap(sx -= tx * q, tx);\n        std::swap(sy -= ty * q, ty);\n\
    \    }\n    return {sx, sy};\n}\n\nlong long mod_inv(long long a, long long mod)\
    \ {\n    long long inv = extgcd(a, mod).first;\n    return (inv % mod + mod) %\
    \ mod;\n}\n\nlong long garner(const std::vector<long long>& b, std::vector<long\
    \ long> m, long long mod) {\n    m.push_back(mod);\n    int n = m.size();\n  \
    \  std::vector<long long> coeffs(n, 1);\n    std::vector<long long> consts(n,\
    \ 0);\n    for (int k = 0; k < n - 1; ++k) {\n        long long t = (b[k] - consts[k])\
    \ * mod_inv(coeffs[k], m[k]) % m[k];\n        if (t < 0) t += m[k];\n        for\
    \ (int i = k + 1; i < n; ++i) {\n            consts[i] = (consts[i] + t * coeffs[i])\
    \ % m[i];\n            coeffs[i] = coeffs[i] * m[k] % m[i];\n        }\n    }\n\
    \    return consts.back();\n}\n\nstd::vector<int> arbitrary_mod_convolution(std::vector<int>&\
    \ a, std::vector<int>& b, int mod) {\n    using mint1 = Modint<167772161>;\n \
    \   using mint2 = Modint<469762049>;\n    using mint3 = Modint<754974721>;\n\n\
    \    std::vector<mint1> a1(a.begin(), a.end()), b1(b.begin(), b.end());\n    std::vector<mint2>\
    \ a2(a.begin(), a.end()), b2(b.begin(), b.end());\n    std::vector<mint3> a3(a.begin(),\
    \ a.end()), b3(b.begin(), b.end());\n\n    auto c1 = NTT<mint1>::convolve(a1,\
    \ b1);\n    auto c2 = NTT<mint2>::convolve(a2, b2);\n    auto c3 = NTT<mint3>::convolve(a3,\
    \ b3);\n\n    std::vector<int> c(c1.size());\n    std::vector<long long> d(3);\n\
    \    const vector<long long> mods = {167772161, 469762049, 754974721};\n    for\
    \ (int i = 0; i < (int) c1.size(); ++i) {\n        d[0] = c1[i].value();\n   \
    \     d[1] = c2[i].value();\n        d[2] = c3[i].value();\n        c[i] = garner(d,\
    \ mods, mod);\n    }\n    return c;\n}\n\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<int> a(N),\
    \ b(M);\n    for (auto& x : a) cin >> x;\n    for (auto& x : b) cin >> x;\n  \
    \  auto c = arbitrary_mod_convolution(a, b, 1e9+7);\n    for (int i = 0; i < (int)\
    \ c.size(); ++i) cout << c[i] << (i < (int)c.size()-1 ? \" \" : \"\\n\");\n}\n\
    \n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n// #include \"../../graph/chromatic_number.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\ntemplate <int mod>\nclass Modint\
    \ {\n    using mint = Modint;\n    static_assert(mod > 0, \"Modulus must be positive\"\
    );\n\npublic:\n    static constexpr int get_mod() noexcept { return mod; }\n\n\
    \    constexpr Modint(long long y = 0) noexcept : x(y >= 0 ? y % mod : (y % mod\
    \ + mod) % mod) {}\n\n    constexpr int value() const noexcept { return x; }\n\
    \n    constexpr mint& operator+=(const mint& r) noexcept { if ((x += r.x) >= mod)\
    \ x -= mod; return *this; }\n    constexpr mint& operator-=(const mint& r) noexcept\
    \ { if ((x += mod - r.x) >= mod) x -= mod; return *this; }\n    constexpr mint&\
    \ operator*=(const mint& r) noexcept { x = static_cast<int>(1LL * x * r.x % mod);\
    \ return *this; }\n    constexpr mint& operator/=(const mint& r) noexcept { *this\
    \ *= r.inv(); return *this; }\n\n    constexpr mint operator-() const noexcept\
    \ { return mint(-x); }\n\n    constexpr mint operator+(const mint& r) const noexcept\
    \ { return mint(*this) += r; }\n    constexpr mint operator-(const mint& r) const\
    \ noexcept { return mint(*this) -= r; }\n    constexpr mint operator*(const mint&\
    \ r) const noexcept { return mint(*this) *= r; }\n    constexpr mint operator/(const\
    \ mint& r) const noexcept { return mint(*this) /= r; }\n\n    constexpr bool operator==(const\
    \ mint& r) const noexcept { return x == r.x; }\n    constexpr bool operator!=(const\
    \ mint& r) const noexcept { return x != r.x; }\n\n    constexpr mint inv() const\
    \ noexcept {\n        int a = x, b = mod, u = 1, v = 0;\n        while (b > 0)\
    \ {\n            int t = a / b;\n            std::swap(a -= t * b, b);\n     \
    \       std::swap(u -= t * v, v);\n        }\n        return mint(u);\n    }\n\
    \n    constexpr mint pow(long long n) const noexcept {\n        mint ret(1), mul(x);\n\
    \        while (n > 0) {\n            if (n & 1) ret *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return ret;\n    }\n\n   \
    \ friend std::ostream& operator<<(std::ostream& os, const mint& r) {\n       \
    \ return os << r.x;\n    }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, mint& r) {\n        long long t;\n        is >> t;\n        r = mint(t);\n\
    \        return is;\n    }\n\nprivate:\n    int x;\n};\n\ntemplate <typename mint>\n\
    class NTT {\npublic:\n    NTT() = delete;\n\n    static std::vector<mint> convolve(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n        int size = a.size()\
    \ + b.size() - 1;\n        int n = 1;\n        while (n < size) n <<= 1;\n   \
    \     std::vector<mint> na(a.begin(), a.end()), nb(b.begin(), b.end());\n    \
    \    na.resize(n);\n        nb.resize(n);\n        ntt(na, false);\n        ntt(nb,\
    \ false);\n        for (int i = 0; i < n; ++i) na[i] *= nb[i];\n        intt(na,\
    \ false);\n        na.resize(size);\n        mint n_inv = mint(n).inv();\n   \
    \     for (int i = 0; i < size; ++i) na[i] *= n_inv;\n        return na;\n   \
    \ }\n\n    static void ntt(std::vector<mint>& a, bool ordered = true) {\n    \
    \    int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n          \
    \  mint omega = primitive_root.pow((mod - 1) / m);\n            for (int s = 0;\
    \ s < n / m; ++s) {\n                mint w = 1;\n                for (int i =\
    \ 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n         \
    \           mint r = a[s * m + i + m / 2];\n                    a[s * m + i] =\
    \ l + r;\n                    a[s * m + i + m / 2] = (l - r) * w;\n          \
    \          w *= omega;\n                }\n            }\n        }\n        if\
    \ (ordered) bit_reverse(a);\n    }\n\n    static void intt(std::vector<mint>&\
    \ a, bool ordered = true) {\n        if (ordered) bit_reverse(a);\n        int\
    \ n = a.size();\n        for (int m = 2; m <= n; m <<= 1) {\n            mint\
    \ omega = primitive_root.pow((mod - 1) / m).inv();\n            for (int s = 0;\
    \ s < n / m; ++s) {\n                mint w = 1;\n                for (int i =\
    \ 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n         \
    \           mint r = a[s * m + i + m / 2] * w;\n                    a[s * m +\
    \ i] = l + r;\n                    a[s * m + i + m / 2] = l - r;\n           \
    \         w *= omega;\n                }\n            }\n        }\n    }\n\n\
    private:\n    static constexpr mint get_primitive_root(int mod) {\n        if\
    \ (mod == 167772161) return 3;\n        if (mod == 469762049) return 3;\n    \
    \    if (mod == 754974721) return 11;\n        if (mod == 998244353) return 3;\n\
    \        if (mod == 1224736769) return 3;\n    }\n\n    static constexpr int mod\
    \ = mint::get_mod();\n    static constexpr mint primitive_root = get_primitive_root(mod);\n\
    \n    static void bit_reverse(std::vector<mint>& a) {\n        int n = a.size();\n\
    \        for (int i = 0, j = 1; j < n - 1; ++j) {\n            for (int k = n\
    \ >> 1; k > (i ^= k); k >>= 1);\n            if (i < j) std::swap(a[i], a[j]);\n\
    \        }\n    }\n};\n\nstd::pair<long long, long long> extgcd(long long a, long\
    \ long b) {\n    long long s = a, sx = 1, sy = 0, t = b, tx = 0, ty = 1;\n   \
    \ while (t) {\n        long long q = s / t;\n        std::swap(s -= t * q, t);\n\
    \        std::swap(sx -= tx * q, tx);\n        std::swap(sy -= ty * q, ty);\n\
    \    }\n    return {sx, sy};\n}\n\nlong long mod_inv(long long a, long long mod)\
    \ {\n    long long inv = extgcd(a, mod).first;\n    return (inv % mod + mod) %\
    \ mod;\n}\n\nlong long garner(const std::vector<long long>& b, std::vector<long\
    \ long> m, long long mod) {\n    m.push_back(mod);\n    int n = m.size();\n  \
    \  std::vector<long long> coeffs(n, 1);\n    std::vector<long long> consts(n,\
    \ 0);\n    for (int k = 0; k < n - 1; ++k) {\n        long long t = (b[k] - consts[k])\
    \ * mod_inv(coeffs[k], m[k]) % m[k];\n        if (t < 0) t += m[k];\n        for\
    \ (int i = k + 1; i < n; ++i) {\n            consts[i] = (consts[i] + t * coeffs[i])\
    \ % m[i];\n            coeffs[i] = coeffs[i] * m[k] % m[i];\n        }\n    }\n\
    \    return consts.back();\n}\n\nstd::vector<int> arbitrary_mod_convolution(std::vector<int>&\
    \ a, std::vector<int>& b, int mod) {\n    using mint1 = Modint<167772161>;\n \
    \   using mint2 = Modint<469762049>;\n    using mint3 = Modint<754974721>;\n\n\
    \    std::vector<mint1> a1(a.begin(), a.end()), b1(b.begin(), b.end());\n    std::vector<mint2>\
    \ a2(a.begin(), a.end()), b2(b.begin(), b.end());\n    std::vector<mint3> a3(a.begin(),\
    \ a.end()), b3(b.begin(), b.end());\n\n    auto c1 = NTT<mint1>::convolve(a1,\
    \ b1);\n    auto c2 = NTT<mint2>::convolve(a2, b2);\n    auto c3 = NTT<mint3>::convolve(a3,\
    \ b3);\n\n    std::vector<int> c(c1.size());\n    std::vector<long long> d(3);\n\
    \    const vector<long long> mods = {167772161, 469762049, 754974721};\n    for\
    \ (int i = 0; i < (int) c1.size(); ++i) {\n        d[0] = c1[i].value();\n   \
    \     d[1] = c2[i].value();\n        d[2] = c3[i].value();\n        c[i] = garner(d,\
    \ mods, mod);\n    }\n    return c;\n}\n\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<int> a(N),\
    \ b(M);\n    for (auto& x : a) cin >> x;\n    for (auto& x : b) cin >> x;\n  \
    \  auto c = arbitrary_mod_convolution(a, b, 1e9+7);\n    for (int i = 0; i < (int)\
    \ c.size(); ++i) cout << c[i] << (i < (int)c.size()-1 ? \" \" : \"\\n\");\n}\n\
    \n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/convolution_mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2022-03-20 20:27:06+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp.html
title: test/yosupo/convolution_mod_1000000007.test.cpp
---
