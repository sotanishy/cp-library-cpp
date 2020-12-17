---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/fft.md
    document_title: Fast Fourier Transform
    links: []
  bundledCode: "#line 2 \"math/fft.cpp\"\n#include <algorithm>\n#include <cmath>\n\
    #include <complex>\n#include <vector>\n\n/*\n * @brief Fast Fourier Transform\n\
    \ * @docs docs/math/fft.md\n */\nclass FFT {\n    using C = std::complex<double>;\n\
    \npublic:\n    FFT() = delete;\n\n    template <typename T>\n    static std::vector<double>\
    \ convolve(const std::vector<T>& a, const std::vector<T>& b) {\n        int size\
    \ = a.size() + b.size() - 1;\n        int n = 1;\n        while (n < size) n <<=\
    \ 1;\n        std::vector<C> na(a.begin(), a.end()), nb(b.begin(), b.end());\n\
    \        na.resize(n);\n        nb.resize(n);\n        fft(na, false);\n     \
    \   fft(nb, false);\n        for (int i = 0; i < n; ++i) na[i] = na[i] * nb[i];\n\
    \        ifft(na, false);\n        std::vector<double> ret(size);\n        for\
    \ (int i = 0; i < size; ++i) ret[i] = na[i].real() / n;\n        return ret;\n\
    \    }\n\n    static void fft(std::vector<C>& a, bool ordered = true) {\n    \
    \    int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n          \
    \  double ang = 2.0 * PI / m;\n            C omega(cos(ang), sin(ang));\n    \
    \        for (int s = 0; s < n / m; ++s) {\n                C w(1, 0);\n     \
    \           for (int i = 0; i < m / 2; ++i) {\n                    C l = a[s *\
    \ m + i];\n                    C r = a[s * m + i + m / 2];\n                 \
    \   a[s * m + i] = l + r;\n                    a[s * m + i + m / 2] = (l - r)\
    \ * w;\n                    w *= omega;\n                }\n            }\n  \
    \      }\n        if (ordered) bit_reverse(a);\n    }\n\n    static void ifft(std::vector<C>&\
    \ a, bool ordered = true) {\n        if (ordered) bit_reverse(a);\n        int\
    \ n = a.size();\n        for (int m = 2; m <= n; m <<= 1) {\n            double\
    \ ang = -2.0 * PI / m;\n            C omega(cos(ang), sin(ang));\n           \
    \ for (int s = 0; s < n / m; ++s) {\n                C w(1, 0);\n            \
    \    for (int i = 0; i < m / 2; ++i) {\n                    C l = a[s * m + i];\n\
    \                    C r = a[s * m + i + m / 2] * w;\n                    a[s\
    \ * m + i] = l + r;\n                    a[s * m + i + m / 2] = l - r;\n     \
    \               w *= omega;\n                }\n            }\n        }\n   \
    \ }\n\nprivate:\n    static constexpr double PI = 3.14159265358979323846;\n\n\
    \    static void bit_reverse(std::vector<C>& a) {\n        int n = a.size();\n\
    \        for (int i = 0, j = 1; j < n - 1; ++j) {\n            for (int k = n\
    \ >> 1; k > (i ^= k); k >>= 1);\n            if (i < j) std::swap(a[i], a[j]);\n\
    \        }\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <complex>\n\
    #include <vector>\n\n/*\n * @brief Fast Fourier Transform\n * @docs docs/math/fft.md\n\
    \ */\nclass FFT {\n    using C = std::complex<double>;\n\npublic:\n    FFT() =\
    \ delete;\n\n    template <typename T>\n    static std::vector<double> convolve(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n        int size = a.size() +\
    \ b.size() - 1;\n        int n = 1;\n        while (n < size) n <<= 1;\n     \
    \   std::vector<C> na(a.begin(), a.end()), nb(b.begin(), b.end());\n        na.resize(n);\n\
    \        nb.resize(n);\n        fft(na, false);\n        fft(nb, false);\n   \
    \     for (int i = 0; i < n; ++i) na[i] = na[i] * nb[i];\n        ifft(na, false);\n\
    \        std::vector<double> ret(size);\n        for (int i = 0; i < size; ++i)\
    \ ret[i] = na[i].real() / n;\n        return ret;\n    }\n\n    static void fft(std::vector<C>&\
    \ a, bool ordered = true) {\n        int n = a.size();\n        for (int m = n;\
    \ m > 1; m >>= 1) {\n            double ang = 2.0 * PI / m;\n            C omega(cos(ang),\
    \ sin(ang));\n            for (int s = 0; s < n / m; ++s) {\n                C\
    \ w(1, 0);\n                for (int i = 0; i < m / 2; ++i) {\n              \
    \      C l = a[s * m + i];\n                    C r = a[s * m + i + m / 2];\n\
    \                    a[s * m + i] = l + r;\n                    a[s * m + i +\
    \ m / 2] = (l - r) * w;\n                    w *= omega;\n                }\n\
    \            }\n        }\n        if (ordered) bit_reverse(a);\n    }\n\n   \
    \ static void ifft(std::vector<C>& a, bool ordered = true) {\n        if (ordered)\
    \ bit_reverse(a);\n        int n = a.size();\n        for (int m = 2; m <= n;\
    \ m <<= 1) {\n            double ang = -2.0 * PI / m;\n            C omega(cos(ang),\
    \ sin(ang));\n            for (int s = 0; s < n / m; ++s) {\n                C\
    \ w(1, 0);\n                for (int i = 0; i < m / 2; ++i) {\n              \
    \      C l = a[s * m + i];\n                    C r = a[s * m + i + m / 2] * w;\n\
    \                    a[s * m + i] = l + r;\n                    a[s * m + i +\
    \ m / 2] = l - r;\n                    w *= omega;\n                }\n      \
    \      }\n        }\n    }\n\nprivate:\n    static constexpr double PI = 3.14159265358979323846;\n\
    \n    static void bit_reverse(std::vector<C>& a) {\n        int n = a.size();\n\
    \        for (int i = 0, j = 1; j < n - 1; ++j) {\n            for (int k = n\
    \ >> 1; k > (i ^= k); k >>= 1);\n            if (i < j) std::swap(a[i], a[j]);\n\
    \        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/fft.cpp
  requiredBy: []
  timestamp: '2020-12-06 15:01:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fft.cpp
layout: document
redirect_from:
- /library/math/fft.cpp
- /library/math/fft.cpp.html
title: Fast Fourier Transform
---
## Description

高速フーリエ変換 (FFT) は数列の離散フーリエ変換を計算するアルゴリズムであり，2つの数列の畳み込みを高速に計算するのに用いられる．

この実装では Cooley-Tukey のアルゴリズムを用いている．

## Operations

- `static vector<double> convolve(vector<T> a, vector<T> b)`
    - $a$ と $b$ の畳み込みを計算する
    - 時間計算量: $O(n\lg n)$
- `static void fft(vector<complex<double>> a, bool ordered)`
    - $a$ を高速フーリエ変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\lg n)$
- `static void ifft(vector<complex<double>> a, bool ordered)`
    - $a$ を逆高速フーリエ変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\lg n)$