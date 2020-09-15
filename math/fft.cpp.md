---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/fft.md
    document_title: Fast Fourier Transform
    links: []
  bundledCode: "#line 1 \"math/fft.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n/*\n * @brief Fast Fourier Transform\n * @docs docs/math/fft.md\n */\n\
    struct FFT {\nprivate:\n    inline static const double PI = acos(-1);\n\n    struct\
    \ C {\n        double real, imag;\n        C() : real(0), imag(0) {}\n       \
    \ C(double real, double imag) : real(real), imag(imag) {}\n        C operator+(const\
    \ C& c) { return C(real + c.real, imag + c.imag); }\n        C operator-(const\
    \ C& c) { return C(real - c.real, imag - c.imag); }\n        C operator*(const\
    \ C& c) { return C(real * c.real - imag * c.imag, real * c.imag + imag * c.real);\
    \ }\n    };\n\n    static void ufft(vector<C>& a) {\n        int n = a.size();\n\
    \        for (int m = n; m > 1; m >>= 1) {\n            double ang = 2.0 * PI\
    \ / m;\n            C omega(cos(ang), sin(ang));\n            for (int s = 0;\
    \ s < n / m; s++) {\n                C w(1, 0);\n                for (int i =\
    \ 0; i < m / 2; i++) {\n                    C l = a[s * m + i];\n            \
    \        C r = a[s * m + i + m / 2];\n                    a[s * m + i] = l + r;\n\
    \                    a[s * m + i + m / 2] = (l - r) * w;\n                   \
    \ w = w * omega;\n                }\n            }\n        }\n    }\n\n    static\
    \ void iufft(vector<C>& a) {\n        int n = a.size();\n        for (int m =\
    \ 2; m <= n; m <<= 1) {\n            double ang = -2.0 * PI / m;\n           \
    \ C omega(cos(ang), sin(ang));\n            for (int s = 0; s < n / m; s++) {\n\
    \                C w(1, 0);\n                for (int i = 0; i < m / 2; i++) {\n\
    \                    C l = a[s * m + i];\n                    C r = a[s * m +\
    \ i + m / 2] * w;\n                    a[s * m + i] = l + r;\n               \
    \     a[s * m + i + m / 2] = l - r;\n                    w = w * omega;\n    \
    \            }\n            }\n        }\n    }\n\npublic:\n    template <typename\
    \ T>\n    static vector<double> convolution(const vector<T>& a, const vector<T>&\
    \ b) {\n        int size = a.size() + b.size() - 1;\n        int n = 1;\n    \
    \    while (n < size) n <<= 1;\n        vector<C> na(n), nb(n);\n        for (int\
    \ i = 0; i < a.size(); i++) na[i].real = a[i];\n        for (int i = 0; i < b.size();\
    \ i++) nb[i].real = b[i];\n        ufft(na);\n        ufft(nb);\n        for (int\
    \ i = 0; i < n; i++) na[i] = na[i] * nb[i];\n        iufft(na);\n        vector<double>\
    \ ret(size);\n        for (int i = 0; i < size; i++) ret[i] = na[i].real / n;\n\
    \        return ret;\n    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n/*\n * @brief Fast Fourier\
    \ Transform\n * @docs docs/math/fft.md\n */\nstruct FFT {\nprivate:\n    inline\
    \ static const double PI = acos(-1);\n\n    struct C {\n        double real, imag;\n\
    \        C() : real(0), imag(0) {}\n        C(double real, double imag) : real(real),\
    \ imag(imag) {}\n        C operator+(const C& c) { return C(real + c.real, imag\
    \ + c.imag); }\n        C operator-(const C& c) { return C(real - c.real, imag\
    \ - c.imag); }\n        C operator*(const C& c) { return C(real * c.real - imag\
    \ * c.imag, real * c.imag + imag * c.real); }\n    };\n\n    static void ufft(vector<C>&\
    \ a) {\n        int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n\
    \            double ang = 2.0 * PI / m;\n            C omega(cos(ang), sin(ang));\n\
    \            for (int s = 0; s < n / m; s++) {\n                C w(1, 0);\n \
    \               for (int i = 0; i < m / 2; i++) {\n                    C l = a[s\
    \ * m + i];\n                    C r = a[s * m + i + m / 2];\n               \
    \     a[s * m + i] = l + r;\n                    a[s * m + i + m / 2] = (l - r)\
    \ * w;\n                    w = w * omega;\n                }\n            }\n\
    \        }\n    }\n\n    static void iufft(vector<C>& a) {\n        int n = a.size();\n\
    \        for (int m = 2; m <= n; m <<= 1) {\n            double ang = -2.0 * PI\
    \ / m;\n            C omega(cos(ang), sin(ang));\n            for (int s = 0;\
    \ s < n / m; s++) {\n                C w(1, 0);\n                for (int i =\
    \ 0; i < m / 2; i++) {\n                    C l = a[s * m + i];\n            \
    \        C r = a[s * m + i + m / 2] * w;\n                    a[s * m + i] = l\
    \ + r;\n                    a[s * m + i + m / 2] = l - r;\n                  \
    \  w = w * omega;\n                }\n            }\n        }\n    }\n\npublic:\n\
    \    template <typename T>\n    static vector<double> convolution(const vector<T>&\
    \ a, const vector<T>& b) {\n        int size = a.size() + b.size() - 1;\n    \
    \    int n = 1;\n        while (n < size) n <<= 1;\n        vector<C> na(n), nb(n);\n\
    \        for (int i = 0; i < a.size(); i++) na[i].real = a[i];\n        for (int\
    \ i = 0; i < b.size(); i++) nb[i].real = b[i];\n        ufft(na);\n        ufft(nb);\n\
    \        for (int i = 0; i < n; i++) na[i] = na[i] * nb[i];\n        iufft(na);\n\
    \        vector<double> ret(size);\n        for (int i = 0; i < size; i++) ret[i]\
    \ = na[i].real / n;\n        return ret;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/fft.cpp
  requiredBy: []
  timestamp: '2020-09-13 11:34:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/fft.cpp
layout: document
redirect_from:
- /library/math/fft.cpp
- /library/math/fft.cpp.html
title: Fast Fourier Transform
---
# Fast Fourier Transform

高速フーリエ変換 (FFT) は数列の離散フーリエ変換を計算するアルゴリズムであり，2つの数列の畳み込みを高速に計算するのに用いられる．

この実装では Cooley-Tukey のアルゴリズムを用いている．

## Member functions

- `template <typename T> static vector<double> convolution(const vector<T>& a, const vector<T>& b)`
    - `a` と `b` の畳み込みを計算する
    - 時間計算量: $O(n\lg n)$