---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/ntt.md
    document_title: Number Theoretic Transform
    links: []
  bundledCode: "#line 1 \"math/ntt.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Number Theoretic Transform\n * @docs docs/math/ntt.md\n */\ntemplate <std::int64_t\
    \ mod, std::int64_t primitive_root>\nclass NTT {\npublic:\n    NTT() = delete;\n\
    \n    static std::vector<std::int64_t> convolution(const std::vector<std::int64_t>&\
    \ a, const std::vector<std::int64_t>& b) {\n        int size = a.size() + b.size()\
    \ - 1;\n        int n = 1;\n        while (n < size) n <<= 1;\n        std::vector<std::int64_t>\
    \ na = a, nb = b;\n        na.resize(n);\n        nb.resize(n);\n        untt(na);\n\
    \        untt(nb);\n        for (int i = 0; i < n; ++i) na[i] = na[i] * nb[i]\
    \ % mod;\n        iuntt(na);\n        na.resize(size);\n        std::int64_t n_inv\
    \ = mod_inv(n);\n        for (int i = 0; i < size; ++i) na[i] = na[i] * n_inv\
    \ % mod;\n        return na;\n    }\n\nprivate:\n    static std::int64_t mod_pow(std::int64_t\
    \ n, std::int64_t p) {\n        std::int64_t ret = 1;\n        while (p > 0) {\n\
    \            if (p & 1) ret = ret * n % mod;\n            n = n * n % mod;\n \
    \           p >>= 1;\n        }\n        return ret;\n    }\n\n    static std::int64_t\
    \ mod_inv(std::int64_t a) {\n        std::int64_t b = mod, u = 1, v = 0, t;\n\
    \        while (b > 0) {\n            t = a / b;\n            std::swap(a -= t\
    \ * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return (u\
    \ % mod + mod) % mod;\n    }\n\n    static void untt(std::vector<std::int64_t>&\
    \ a) {\n        int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n\
    \            std::int64_t omega = mod_pow(primitive_root, (mod - 1) / m);\n  \
    \          for (int s = 0; s < n / m; ++s) {\n                std::int64_t w =\
    \ 1;\n                for (int i = 0; i < m / 2; ++i) {\n                    std::int64_t\
    \ l = a[s * m + i];\n                    std::int64_t r = a[s * m + i + m / 2];\n\
    \                    a[s * m + i] = (l + r) % mod;\n                    a[s *\
    \ m + i + m / 2] = (l - r + mod) * w % mod;\n                    w = w * omega\
    \ % mod;\n                }\n            }\n        }\n    }\n\n    static void\
    \ iuntt(std::vector<std::int64_t>& a) {\n        int n = a.size();\n        for\
    \ (int m = 2; m <= n; m <<= 1) {\n            std::int64_t omega = mod_inv(mod_pow(primitive_root,\
    \ (mod - 1) / m));\n            for (int s = 0; s < n / m; ++s) {\n          \
    \      std::int64_t w = 1;\n                for (int i = 0; i < m / 2; ++i) {\n\
    \                    std::int64_t l = a[s * m + i];\n                    std::int64_t\
    \ r = a[s * m + i + m / 2] * w % mod;\n                    a[s * m + i] = (l +\
    \ r) % mod;\n                    a[s * m + i + m / 2] = (l - r + mod) % mod;\n\
    \                    w = w * omega % mod;\n                }\n            }\n\
    \        }\n    }\n};\n\n// <167772161, 3>\n// <469762049, 3>\n// <754974721,\
    \ 11>\n// <998244353, 3>\n// <1224736769, 3>\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Number Theoretic Transform\n *\
    \ @docs docs/math/ntt.md\n */\ntemplate <std::int64_t mod, std::int64_t primitive_root>\n\
    class NTT {\npublic:\n    NTT() = delete;\n\n    static std::vector<std::int64_t>\
    \ convolution(const std::vector<std::int64_t>& a, const std::vector<std::int64_t>&\
    \ b) {\n        int size = a.size() + b.size() - 1;\n        int n = 1;\n    \
    \    while (n < size) n <<= 1;\n        std::vector<std::int64_t> na = a, nb =\
    \ b;\n        na.resize(n);\n        nb.resize(n);\n        untt(na);\n      \
    \  untt(nb);\n        for (int i = 0; i < n; ++i) na[i] = na[i] * nb[i] % mod;\n\
    \        iuntt(na);\n        na.resize(size);\n        std::int64_t n_inv = mod_inv(n);\n\
    \        for (int i = 0; i < size; ++i) na[i] = na[i] * n_inv % mod;\n       \
    \ return na;\n    }\n\nprivate:\n    static std::int64_t mod_pow(std::int64_t\
    \ n, std::int64_t p) {\n        std::int64_t ret = 1;\n        while (p > 0) {\n\
    \            if (p & 1) ret = ret * n % mod;\n            n = n * n % mod;\n \
    \           p >>= 1;\n        }\n        return ret;\n    }\n\n    static std::int64_t\
    \ mod_inv(std::int64_t a) {\n        std::int64_t b = mod, u = 1, v = 0, t;\n\
    \        while (b > 0) {\n            t = a / b;\n            std::swap(a -= t\
    \ * b, b);\n            std::swap(u -= t * v, v);\n        }\n        return (u\
    \ % mod + mod) % mod;\n    }\n\n    static void untt(std::vector<std::int64_t>&\
    \ a) {\n        int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n\
    \            std::int64_t omega = mod_pow(primitive_root, (mod - 1) / m);\n  \
    \          for (int s = 0; s < n / m; ++s) {\n                std::int64_t w =\
    \ 1;\n                for (int i = 0; i < m / 2; ++i) {\n                    std::int64_t\
    \ l = a[s * m + i];\n                    std::int64_t r = a[s * m + i + m / 2];\n\
    \                    a[s * m + i] = (l + r) % mod;\n                    a[s *\
    \ m + i + m / 2] = (l - r + mod) * w % mod;\n                    w = w * omega\
    \ % mod;\n                }\n            }\n        }\n    }\n\n    static void\
    \ iuntt(std::vector<std::int64_t>& a) {\n        int n = a.size();\n        for\
    \ (int m = 2; m <= n; m <<= 1) {\n            std::int64_t omega = mod_inv(mod_pow(primitive_root,\
    \ (mod - 1) / m));\n            for (int s = 0; s < n / m; ++s) {\n          \
    \      std::int64_t w = 1;\n                for (int i = 0; i < m / 2; ++i) {\n\
    \                    std::int64_t l = a[s * m + i];\n                    std::int64_t\
    \ r = a[s * m + i + m / 2] * w % mod;\n                    a[s * m + i] = (l +\
    \ r) % mod;\n                    a[s * m + i + m / 2] = (l - r + mod) % mod;\n\
    \                    w = w * omega % mod;\n                }\n            }\n\
    \        }\n    }\n};\n\n// <167772161, 3>\n// <469762049, 3>\n// <754974721,\
    \ 11>\n// <998244353, 3>\n// <1224736769, 3>"
  dependsOn: []
  isVerificationFile: false
  path: math/ntt.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:09:57+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/convolution_mod.test.cpp
documentation_of: math/ntt.cpp
layout: document
redirect_from:
- /library/math/ntt.cpp
- /library/math/ntt.cpp.html
title: Number Theoretic Transform
---
# Number Theoretic Transform

数論変換 (NTT) は，剰余環 $\mathbb{Z}/p\mathbb{Z}$ 上の高速フーリエ変換である．

## Template parameters

- `mod`
    - 素数 $p$.
- `primitive_root`
    - $p$ の原子根

## Member functions

- `static vector<long long> convolution(const vector<long long>& a, const vector<long long>& b)`
    - `a` と `b` の畳み込みを $\mod p$ で計算する
    - 時間計算量: $O(n\lg n)$

## Note

数列の長さ $n$ が $p - 1$ を割り切るとき，1の原子 $n$ 乗根が必ず存在する．$n$ の長さを2冪にするため，素数 $p$ は $a \times 2^k + 1$ の形に表したとき $k$ が十分大きいものを用いる．

以下の `mod` と `primitive_root` の組み合わせがよく用いられる:
- <167772161, 3>
- <469762049, 3>
- <754974721, 11>
- <998244353, 3>
- <1224736769, 3>

$k$ の値はそれぞれ，25, 26, 24, 23, 24である．