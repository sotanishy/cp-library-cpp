---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/mod_arithmetic.hpp
    title: Modular Arithmetic
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_B.test.cpp
    title: test/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/NTL_1_D.test.cpp
    title: test/aoj/NTL_1_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/discrete_logarithm_mod.test.cpp
    title: test/yosupo/discrete_logarithm_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sqrt_mod.test.cpp
    title: test/yosupo/sqrt_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sum_of_totient_function.test.cpp
    title: test/yosupo/sum_of_totient_function.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tetration_mod.test.cpp
    title: test/yosupo/tetration_mod.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/number-theory/euler_totient.hpp\"\n#include <numeric>\n\
    #include <vector>\n\nlong long euler_totient(long long n) {\n    long long ret\
    \ = n;\n    if (n % 2 == 0) {\n        ret -= ret / 2;\n        while (n % 2 ==\
    \ 0) n /= 2;\n    }\n    for (long long i = 3; i * i <= n; i += 2) {\n       \
    \ if (n % i == 0) {\n            ret -= ret / i;\n            while (n % i ==\
    \ 0) n /= i;\n        }\n    }\n    if (n != 1) ret -= ret / n;\n    return ret;\n\
    }\n\nstd::vector<int> euler_totient_table(int n) {\n    std::vector<int> ret(n\
    \ + 1);\n    std::iota(ret.begin(), ret.end(), 0);\n    for (int i = 2; i <= n;\
    \ ++i) {\n        if (ret[i] == i) {\n            for (int j = i; j <= n; j +=\
    \ i) {\n                ret[j] = ret[j] / i * (i - 1);\n            }\n      \
    \  }\n    }\n    return ret;\n}\n\ntemplate <typename mint>\nstd::pair<std::vector<mint>,\
    \ std::vector<mint>> totient_summatory_table(\n    long long n) {\n    if (n ==\
    \ 0) return {{0}, {0}};\n    const int b = std::min(n, (long long)1e4);\n    std::vector<mint>\
    \ small(n / b + 1), large(b + 1);\n\n    std::vector<int> totient(n / b + 1);\n\
    \    std::iota(totient.begin(), totient.end(), 0);\n    for (int i = 2; i <= n\
    \ / b; ++i) {\n        if (totient[i] != i) continue;\n        for (int j = i;\
    \ j <= n / b; j += i) {\n            totient[j] = totient[j] / i * (i - 1);\n\
    \        }\n    }\n    for (int i = 0; i < n / b; ++i) small[i + 1] = small[i]\
    \ + totient[i + 1];\n\n    for (int i = 1; i <= b; ++i) {\n        mint k = n\
    \ / i;\n        large[i] = k * (k + 1) / 2;\n    }\n    for (long long i = b;\
    \ i >= 1; --i) {\n        for (long long l = 2; l <= n / i;) {\n            long\
    \ long q = n / (i * l), r = n / (i * q) + 1;\n            large[i] -=\n      \
    \          (i * l <= b ? large[i * l] : small[n / (i * l)]) * (r - l);\n     \
    \       l = r;\n        }\n    }\n    return {small, large};\n}\n"
  code: "#pragma once\n#include <numeric>\n#include <vector>\n\nlong long euler_totient(long\
    \ long n) {\n    long long ret = n;\n    if (n % 2 == 0) {\n        ret -= ret\
    \ / 2;\n        while (n % 2 == 0) n /= 2;\n    }\n    for (long long i = 3; i\
    \ * i <= n; i += 2) {\n        if (n % i == 0) {\n            ret -= ret / i;\n\
    \            while (n % i == 0) n /= i;\n        }\n    }\n    if (n != 1) ret\
    \ -= ret / n;\n    return ret;\n}\n\nstd::vector<int> euler_totient_table(int\
    \ n) {\n    std::vector<int> ret(n + 1);\n    std::iota(ret.begin(), ret.end(),\
    \ 0);\n    for (int i = 2; i <= n; ++i) {\n        if (ret[i] == i) {\n      \
    \      for (int j = i; j <= n; j += i) {\n                ret[j] = ret[j] / i\
    \ * (i - 1);\n            }\n        }\n    }\n    return ret;\n}\n\ntemplate\
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
    \ l);\n            l = r;\n        }\n    }\n    return {small, large};\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/euler_totient.hpp
  requiredBy:
  - math/number-theory/mod_arithmetic.hpp
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sqrt_mod.test.cpp
  - test/yosupo/sum_of_totient_function.test.cpp
  - test/yosupo/tetration_mod.test.cpp
  - test/yosupo/discrete_logarithm_mod.test.cpp
  - test/aoj/NTL_1_D.test.cpp
  - test/aoj/NTL_1_B.test.cpp
documentation_of: math/number-theory/euler_totient.hpp
layout: document
title: Euler's Totient Function
---

## Description

Euler の totient 関数 $\varphi(n)$ は，$n$ 以下の自然数のうち $n$ と互いに素であるものの個数である．

## Operations

- `long long euler_totient(long long n)`
    - $\varphi(n)$ を求める
    - 時間計算量: $O(\sqrt{n})$
- `vector<int> euler_totient_table(int n)`
    - $n$ 以下の正整数 $i$ について $\varphi(i)$ を求める
    - 時間計算量: $O(n \log\log n)$
- `pair<vector<mint>, vector<mint>> totient_summatory_table(long long n)`
    - 自然数 $1\leq i \leq N$ を用いて $k=\lfloor \frac{n}{i} \rfloor$ と表される各自然数について，$\Phi(k)=\sum_{j=1}^k \varphi(j)$ を求める
        - vector の組 `(small, large)` を返す．`small[i]` は $\Phi(i)$, `large[i]` は $\Phi(\lfloor \frac{n}{i} \rfloor)$ である．
    - 時間計算量: $O(n^{2/3}(\log\log n)^{1/3})$

## Reference

- [トーティエント関数 $\varphi(i)$ の和 $\sum_{i=1}^N \varphi(i)$ を $O(N^{2/3})$
で求める - yukicoder wiki](https://yukicoder.me/wiki/sum_totient)