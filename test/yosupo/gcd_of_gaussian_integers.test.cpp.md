---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/gaussian_integer.hpp
    title: Gaussian Integer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/gcd_of_gaussian_integers
    links:
    - https://judge.yosupo.jp/problem/gcd_of_gaussian_integers
  bundledCode: "#line 1 \"test/yosupo/gcd_of_gaussian_integers.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/gcd_of_gaussian_integers\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 4 \"math/gaussian_integer.hpp\"\n\n/**\n * @brief Gaussian\
    \ Integer\n */\n\ntemplate <typename T>\nstruct GaussianInteger {\n    using G\
    \ = GaussianInteger<T>;\n\n    T x, y;\n\n    GaussianInteger() = default;\n \
    \   explicit GaussianInteger(T x) : x(x), y(0) {}\n    constexpr GaussianInteger(T\
    \ x, T y) : x(x), y(y) {}\n\n    constexpr G& operator+=(const G& r) noexcept\
    \ {\n        x += r.x, y += r.y;\n        return *this;\n    }\n    constexpr\
    \ G& operator-=(const G& r) noexcept {\n        x -= r.x, y -= r.y;\n        return\
    \ *this;\n    }\n    constexpr G& operator*=(const G& r) noexcept {\n        T\
    \ nx = x * r.x - y * r.y;\n        T ny = x * r.y + y * r.x;\n        x = nx,\
    \ y = ny;\n        return *this;\n    }\n\n    constexpr G operator-() const noexcept\
    \ { return G(-x, -y); }\n\n    constexpr G operator+(const G& r) const noexcept\
    \ { return G(*this) += r; }\n    constexpr G operator-(const G& r) const noexcept\
    \ { return G(*this) -= r; }\n    constexpr G operator*(const G& r) const noexcept\
    \ { return G(*this) *= r; }\n\n    constexpr bool operator==(const G& r) const\
    \ noexcept {\n        return x == r.x && y == r.y;\n    }\n    constexpr bool\
    \ operator!=(const G& r) const noexcept {\n        return x != r.x || y != r.y;\n\
    \    }\n\n    constexpr G conj() const { return G(x, -y); }\n\n    constexpr T\
    \ norm() const { return x * x + y * y; }\n\n    static constexpr std::pair<G,\
    \ G> divmod(const G& a, const G& b) {\n        assert(b.norm() > 0);\n       \
    \ if (a.norm() < b.norm()) return {G(0), G(a)};\n\n        G num = a * b.conj();\n\
    \        T den = b.norm();\n\n        auto [qx, rx] = divmod(num.x, den);\n  \
    \      if (rx > den / 2) ++qx;\n        auto [qy, ry] = divmod(num.y, den);\n\
    \        if (ry > den / 2) ++qy;\n\n        G q(qx, qy);\n        return {q, a\
    \ - q * b};\n    }\n\n    static constexpr G gcd(G a, G b) {\n        while (b.norm()\
    \ > 0) {\n            auto [q, r] = divmod(a, b);\n            a = b;\n      \
    \      b = r;\n        }\n        return a;\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const G& r) {\n        return os << r.x << \"+\"\
    \ << r.y << \"i\";\n    }\n\n   private:\n    static constexpr std::pair<T, T>\
    \ divmod(T a, T b) {\n        assert(b > 0);\n        T q = a / b;\n        if\
    \ (a == b * q) return {q, 0};\n        if (a < 0) --q;\n        return {q, a -\
    \ b * q};\n    }\n};\n#line 6 \"test/yosupo/gcd_of_gaussian_integers.test.cpp\"\
    \nusing namespace std;\n\nusing G = GaussianInteger<long long>;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int T;\n  \
    \  cin >> T;\n    while (T--) {\n        long long a1, b1, a2, b2;\n        cin\
    \ >> a1 >> b1 >> a2 >> b2;\n        G x(a1, b1), y(a2, b2);\n        auto g =\
    \ G::gcd(x, y);\n        cout << g.x << \" \" << g.y << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/gcd_of_gaussian_integers\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../math/gaussian_integer.hpp\"\n\
    using namespace std;\n\nusing G = GaussianInteger<long long>;\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int T;\n    cin\
    \ >> T;\n    while (T--) {\n        long long a1, b1, a2, b2;\n        cin >>\
    \ a1 >> b1 >> a2 >> b2;\n        G x(a1, b1), y(a2, b2);\n        auto g = G::gcd(x,\
    \ y);\n        cout << g.x << \" \" << g.y << \"\\n\";\n    }\n}"
  dependsOn:
  - math/gaussian_integer.hpp
  isVerificationFile: true
  path: test/yosupo/gcd_of_gaussian_integers.test.cpp
  requiredBy: []
  timestamp: '2023-12-02 22:50:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/gcd_of_gaussian_integers.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/gcd_of_gaussian_integers.test.cpp
- /verify/test/yosupo/gcd_of_gaussian_integers.test.cpp.html
title: test/yosupo/gcd_of_gaussian_integers.test.cpp
---
