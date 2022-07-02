---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"convolution/fft.hpp\"\n#include <complex>\n#include <vector>\n\
    \nconstexpr double PI = 3.14159265358979323846;\n\ntemplate <typename T>\nvoid\
    \ bit_reverse(std::vector<T>& a) {\n    int n = a.size();\n    for (int i = 0,\
    \ j = 1; j < n - 1; ++j) {\n        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n\
    \        if (i < j) std::swap(a[i], a[j]);\n    }\n}\n\nvoid fft(std::vector<std::complex<double>>&\
    \ a, bool ordered = true) {\n    int n = a.size();\n    for (int m = n; m > 1;\
    \ m >>= 1) {\n        double ang = 2.0 * PI / m;\n        std::complex<double>\
    \ omega(cos(ang), sin(ang));\n        for (int s = 0; s < n / m; ++s) {\n    \
    \        std::complex<double> w(1, 0);\n            for (int i = 0; i < m / 2;\
    \ ++i) {\n                auto l = a[s * m + i];\n                auto r = a[s\
    \ * m + i + m / 2];\n                a[s * m + i] = l + r;\n                a[s\
    \ * m + i + m / 2] = (l - r) * w;\n                w *= omega;\n            }\n\
    \        }\n    }\n    if (ordered) bit_reverse(a);\n}\n\nvoid ifft(std::vector<std::complex<double>>&\
    \ a, bool ordered = true) {\n    if (ordered) bit_reverse(a);\n    int n = a.size();\n\
    \    for (int m = 2; m <= n; m <<= 1) {\n        double ang = -2.0 * PI / m;\n\
    \        std::complex<double> omega(cos(ang), sin(ang));\n        for (int s =\
    \ 0; s < n / m; ++s) {\n            std::complex<double> w(1, 0);\n          \
    \  for (int i = 0; i < m / 2; ++i) {\n                auto l = a[s * m + i];\n\
    \                auto r = a[s * m + i + m / 2] * w;\n                a[s * m +\
    \ i] = l + r;\n                a[s * m + i + m / 2] = l - r;\n               \
    \ w *= omega;\n            }\n        }\n    }\n}\n\ntemplate <typename T>\nstd::vector<double>\
    \ convolution(const std::vector<T>& a, const std::vector<T>& b) {\n    int size\
    \ = a.size() + b.size() - 1;\n    int n = 1;\n    while (n < size) n <<= 1;\n\
    \    std::vector<std::complex<double>> na(a.begin(), a.end()), nb(b.begin(), b.end());\n\
    \    na.resize(n);\n    nb.resize(n);\n    fft(na, false);\n    fft(nb, false);\n\
    \    for (int i = 0; i < n; ++i) na[i] *= nb[i];\n    ifft(na, false);\n    std::vector<double>\
    \ ret(size);\n    for (int i = 0; i < size; ++i) ret[i] = na[i].real() / n;\n\
    \    return ret;\n}\n"
  code: "#pragma once\n#include <complex>\n#include <vector>\n\nconstexpr double PI\
    \ = 3.14159265358979323846;\n\ntemplate <typename T>\nvoid bit_reverse(std::vector<T>&\
    \ a) {\n    int n = a.size();\n    for (int i = 0, j = 1; j < n - 1; ++j) {\n\
    \        for (int k = n >> 1; k > (i ^= k); k >>= 1);\n        if (i < j) std::swap(a[i],\
    \ a[j]);\n    }\n}\n\nvoid fft(std::vector<std::complex<double>>& a, bool ordered\
    \ = true) {\n    int n = a.size();\n    for (int m = n; m > 1; m >>= 1) {\n  \
    \      double ang = 2.0 * PI / m;\n        std::complex<double> omega(cos(ang),\
    \ sin(ang));\n        for (int s = 0; s < n / m; ++s) {\n            std::complex<double>\
    \ w(1, 0);\n            for (int i = 0; i < m / 2; ++i) {\n                auto\
    \ l = a[s * m + i];\n                auto r = a[s * m + i + m / 2];\n        \
    \        a[s * m + i] = l + r;\n                a[s * m + i + m / 2] = (l - r)\
    \ * w;\n                w *= omega;\n            }\n        }\n    }\n    if (ordered)\
    \ bit_reverse(a);\n}\n\nvoid ifft(std::vector<std::complex<double>>& a, bool ordered\
    \ = true) {\n    if (ordered) bit_reverse(a);\n    int n = a.size();\n    for\
    \ (int m = 2; m <= n; m <<= 1) {\n        double ang = -2.0 * PI / m;\n      \
    \  std::complex<double> omega(cos(ang), sin(ang));\n        for (int s = 0; s\
    \ < n / m; ++s) {\n            std::complex<double> w(1, 0);\n            for\
    \ (int i = 0; i < m / 2; ++i) {\n                auto l = a[s * m + i];\n    \
    \            auto r = a[s * m + i + m / 2] * w;\n                a[s * m + i]\
    \ = l + r;\n                a[s * m + i + m / 2] = l - r;\n                w *=\
    \ omega;\n            }\n        }\n    }\n}\n\ntemplate <typename T>\nstd::vector<double>\
    \ convolution(const std::vector<T>& a, const std::vector<T>& b) {\n    int size\
    \ = a.size() + b.size() - 1;\n    int n = 1;\n    while (n < size) n <<= 1;\n\
    \    std::vector<std::complex<double>> na(a.begin(), a.end()), nb(b.begin(), b.end());\n\
    \    na.resize(n);\n    nb.resize(n);\n    fft(na, false);\n    fft(nb, false);\n\
    \    for (int i = 0; i < n; ++i) na[i] *= nb[i];\n    ifft(na, false);\n    std::vector<double>\
    \ ret(size);\n    for (int i = 0; i < size; ++i) ret[i] = na[i].real() / n;\n\
    \    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: convolution/fft.hpp
  requiredBy: []
  timestamp: '2022-03-24 12:11:41+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
documentation_of: convolution/fft.hpp
layout: document
title: Fast Fourier Transform
---

## Description

高速 Fourier 変換 (FFT) は数列の離散 Fourier 変換を計算するアルゴリズムであり，2つの数列の畳み込みを高速に計算するのに用いられる．

この実装では Cooley-Tukey のアルゴリズムを用いている．

## Operations

- `void fft(vector<complex<double>> a, bool ordered)`
    - 数列 $a$ を高速 Fourier 変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\log n)$
- `void ifft(vector<complex<double>> a, bool ordered)`
    - 数列 $a$ を逆高速 Fourier 変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\log n)$
- `vector<double> convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の畳み込みを計算する
    - 時間計算量: $O(n\log n)$