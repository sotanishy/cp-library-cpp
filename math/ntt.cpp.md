---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/formal_power_series.cpp
    title: Formal Power Series
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/ntt.md
    document_title: Number Theoretic Transform
    links: []
  bundledCode: "#line 1 \"math/ntt.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Number Theoretic Transform\n * @docs docs/math/ntt.md\n */\ntemplate <typename\
    \ mint>\nclass NTT {\npublic:\n    NTT() = delete;\n\n    static std::vector<mint>\
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
    \    }\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Number Theoretic Transform\n *\
    \ @docs docs/math/ntt.md\n */\ntemplate <typename mint>\nclass NTT {\npublic:\n\
    \    NTT() = delete;\n\n    static std::vector<mint> convolution(const std::vector<mint>&\
    \ a, const std::vector<mint>& b) {\n        int size = a.size() + b.size() - 1;\n\
    \        int n = 1;\n        while (n < size) n <<= 1;\n        std::vector<mint>\
    \ na(n), nb(n);\n        for (int i = 0; i < (int) a.size(); ++i) na[i] = a[i];\n\
    \        for (int i = 0; i < (int) b.size(); ++i) nb[i] = b[i];\n        untt(na);\n\
    \        untt(nb);\n        for (int i = 0; i < n; ++i) na[i] *= nb[i];\n    \
    \    iuntt(na);\n        na.resize(size);\n        mint n_inv = mint(n).inv();\n\
    \        for (int i = 0; i < size; ++i) na[i] *= n_inv;\n        return na;\n\
    \    }\n\nprivate:\n    static constexpr mint get_primitive_root(int mod) {\n\
    \        if (mod == 167772161) return 3;\n        if (mod == 469762049) return\
    \ 3;\n        if (mod == 754974721) return 11;\n        if (mod == 998244353)\
    \ return 3;\n        if (mod == 1224736769) return 3;\n        mint r = 2;\n \
    \       while (r.pow((mod - 1) >> 1) == 1) r += 1;\n        return r;\n    }\n\
    \n    static constexpr int mod = mint::get_mod();\n    static constexpr mint primitive_root\
    \ = get_primitive_root(mod);\n\n    static void untt(std::vector<mint>& a) {\n\
    \        int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n      \
    \      mint omega = primitive_root.pow((mod - 1) / m);\n            for (int s\
    \ = 0; s < n / m; ++s) {\n                mint w = 1;\n                for (int\
    \ i = 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n     \
    \               mint r = a[s * m + i + m / 2];\n                    a[s * m +\
    \ i] = l + r;\n                    a[s * m + i + m / 2] = (l - r) * w;\n     \
    \               w *= omega;\n                }\n            }\n        }\n   \
    \ }\n\n    static void iuntt(std::vector<mint>& a) {\n        int n = a.size();\n\
    \        for (int m = 2; m <= n; m <<= 1) {\n            mint omega = primitive_root.pow((mod\
    \ - 1) / m).inv();\n            for (int s = 0; s < n / m; ++s) {\n          \
    \      mint w = 1;\n                for (int i = 0; i < m / 2; ++i) {\n      \
    \              mint l = a[s * m + i];\n                    mint r = a[s * m +\
    \ i + m / 2] * w;\n                    a[s * m + i] = l + r;\n               \
    \     a[s * m + i + m / 2] = l - r;\n                    w *= omega;\n       \
    \         }\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/ntt.cpp
  requiredBy:
  - math/formal_power_series.cpp
  timestamp: '2020-10-12 18:08:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
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

- `mint`
    - `Modint` $mod p$

## Member functions

- `static vector<mint> convolution(vector<mint> a, vector<mint> b)`
    - `a` と `b` の畳み込みを $\mod p$ で計算する
    - 時間計算量: $O(n\lg n)$

## Note

数列の長さ $n$ が $p - 1$ を割り切るとき，1の原子 $n$ 乗根が必ず存在する．$n$ の長さを2冪にするため，素数 $p$ は $a \times 2^k + 1$ の形に表したとき $k$ が十分大きいものを用いる．

以下の `p` と原子根の組み合わせがよく用いられる:
- <167772161, 3>
- <469762049, 3>
- <754974721, 11>
- <998244353, 3>
- <1224736769, 3>

$k$ の値はそれぞれ，25, 26, 24, 23, 24である．