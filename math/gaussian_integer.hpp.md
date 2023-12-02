---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/gcd_of_gaussian_integers.test.cpp
    title: test/yosupo/gcd_of_gaussian_integers.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Gaussian Integer
    links: []
  bundledCode: "#line 1 \"math/gaussian_integer.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <iostream>\n\n/**\n * @brief Gaussian Integer\n */\n\ntemplate\
    \ <typename T>\nstruct GaussianInteger {\n    using G = GaussianInteger<T>;\n\n\
    \    T x, y;\n\n    GaussianInteger() = default;\n    explicit GaussianInteger(T\
    \ x) : x(x), y(0) {}\n    constexpr GaussianInteger(T x, T y) : x(x), y(y) {}\n\
    \n    constexpr G& operator+=(const G& r) noexcept {\n        x += r.x, y += r.y;\n\
    \        return *this;\n    }\n    constexpr G& operator-=(const G& r) noexcept\
    \ {\n        x -= r.x, y -= r.y;\n        return *this;\n    }\n    constexpr\
    \ G& operator*=(const G& r) noexcept {\n        T nx = x * r.x - y * r.y;\n  \
    \      T ny = x * r.y + y * r.x;\n        x = nx, y = ny;\n        return *this;\n\
    \    }\n\n    constexpr G operator-() const noexcept { return G(-x, -y); }\n\n\
    \    constexpr G operator+(const G& r) const noexcept { return G(*this) += r;\
    \ }\n    constexpr G operator-(const G& r) const noexcept { return G(*this) -=\
    \ r; }\n    constexpr G operator*(const G& r) const noexcept { return G(*this)\
    \ *= r; }\n\n    constexpr bool operator==(const G& r) const noexcept {\n    \
    \    return x == r.x && y == r.y;\n    }\n    constexpr bool operator!=(const\
    \ G& r) const noexcept {\n        return x != r.x || y != r.y;\n    }\n\n    constexpr\
    \ G conj() const { return G(x, -y); }\n\n    constexpr T norm() const { return\
    \ x * x + y * y; }\n\n    static constexpr std::pair<G, G> divmod(const G& a,\
    \ const G& b) {\n        assert(b.norm() > 0);\n        if (a.norm() < b.norm())\
    \ return {G(0), G(a)};\n\n        G num = a * b.conj();\n        T den = b.norm();\n\
    \n        auto [qx, rx] = divmod(num.x, den);\n        if (rx > den / 2) ++qx;\n\
    \        auto [qy, ry] = divmod(num.y, den);\n        if (ry > den / 2) ++qy;\n\
    \n        G q(qx, qy);\n        return {q, a - q * b};\n    }\n\n    static constexpr\
    \ G gcd(G a, G b) {\n        while (b.norm() > 0) {\n            auto [q, r] =\
    \ divmod(a, b);\n            a = b;\n            b = r;\n        }\n        return\
    \ a;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const G&\
    \ r) {\n        return os << r.x << \"+\" << r.y << \"i\";\n    }\n\n   private:\n\
    \    static constexpr std::pair<T, T> divmod(T a, T b) {\n        assert(b > 0);\n\
    \        T q = a / b;\n        if (a == b * q) return {q, 0};\n        if (a <\
    \ 0) --q;\n        return {q, a - b * q};\n    }\n};\n"
  code: "#include <algorithm>\n#include <cassert>\n#include <iostream>\n\n/**\n *\
    \ @brief Gaussian Integer\n */\n\ntemplate <typename T>\nstruct GaussianInteger\
    \ {\n    using G = GaussianInteger<T>;\n\n    T x, y;\n\n    GaussianInteger()\
    \ = default;\n    explicit GaussianInteger(T x) : x(x), y(0) {}\n    constexpr\
    \ GaussianInteger(T x, T y) : x(x), y(y) {}\n\n    constexpr G& operator+=(const\
    \ G& r) noexcept {\n        x += r.x, y += r.y;\n        return *this;\n    }\n\
    \    constexpr G& operator-=(const G& r) noexcept {\n        x -= r.x, y -= r.y;\n\
    \        return *this;\n    }\n    constexpr G& operator*=(const G& r) noexcept\
    \ {\n        T nx = x * r.x - y * r.y;\n        T ny = x * r.y + y * r.x;\n  \
    \      x = nx, y = ny;\n        return *this;\n    }\n\n    constexpr G operator-()\
    \ const noexcept { return G(-x, -y); }\n\n    constexpr G operator+(const G& r)\
    \ const noexcept { return G(*this) += r; }\n    constexpr G operator-(const G&\
    \ r) const noexcept { return G(*this) -= r; }\n    constexpr G operator*(const\
    \ G& r) const noexcept { return G(*this) *= r; }\n\n    constexpr bool operator==(const\
    \ G& r) const noexcept {\n        return x == r.x && y == r.y;\n    }\n    constexpr\
    \ bool operator!=(const G& r) const noexcept {\n        return x != r.x || y !=\
    \ r.y;\n    }\n\n    constexpr G conj() const { return G(x, -y); }\n\n    constexpr\
    \ T norm() const { return x * x + y * y; }\n\n    static constexpr std::pair<G,\
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
    \ b * q};\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/gaussian_integer.hpp
  requiredBy: []
  timestamp: '2023-11-26 17:31:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/gcd_of_gaussian_integers.test.cpp
documentation_of: math/gaussian_integer.hpp
layout: document
redirect_from:
- /library/math/gaussian_integer.hpp
- /library/math/gaussian_integer.hpp.html
title: Gaussian Integer
---
