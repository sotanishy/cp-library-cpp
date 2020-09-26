---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/ntt.md
    document_title: Number Theoretic Transform
    links: []
  bundledCode: "#line 1 \"math/ntt.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Number Theoretic Transform\n * @docs docs/math/ntt.md\n */\ntemplate <typename\
    \ mint, int primitive_root>\nclass NTT {\n    static constexpr int mod = mint::get_mod();\n\
    \npublic:\n    NTT() = delete;\n\n    static std::vector<mint> convolution(const\
    \ std::vector<mint>& a, const std::vector<mint>& b) {\n        int size = a.size()\
    \ + b.size() - 1;\n        int n = 1;\n        while (n < size) n <<= 1;\n   \
    \     std::vector<mint> na(n), nb(n);\n        for (int i = 0; i < (int) a.size();\
    \ ++i) na[i] = a[i];\n        for (int i = 0; i < (int) b.size(); ++i) nb[i] =\
    \ b[i];\n        untt(na);\n        untt(nb);\n        for (int i = 0; i < n;\
    \ ++i) na[i] *= nb[i];\n        iuntt(na);\n        na.resize(size);\n       \
    \ mint n_inv = mint(n).inv();\n        for (int i = 0; i < size; ++i) na[i] *=\
    \ n_inv;\n        return na;\n    }\n\nprivate:\n    static void untt(std::vector<mint>&\
    \ a) {\n        int n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n\
    \            mint omega = mint(primitive_root).pow((mod - 1) / m);\n         \
    \   for (int s = 0; s < n / m; ++s) {\n                mint w = 1;\n         \
    \       for (int i = 0; i < m / 2; ++i) {\n                    mint l = a[s *\
    \ m + i];\n                    mint r = a[s * m + i + m / 2];\n              \
    \      a[s * m + i] = l + r;\n                    a[s * m + i + m / 2] = (l -\
    \ r) * w;\n                    w *= omega;\n                }\n            }\n\
    \        }\n    }\n\n    static void iuntt(std::vector<mint>& a) {\n        int\
    \ n = a.size();\n        for (int m = 2; m <= n; m <<= 1) {\n            mint\
    \ omega = mint(primitive_root).pow((mod - 1) / m).inv();\n            for (int\
    \ s = 0; s < n / m; ++s) {\n                mint w = 1;\n                for (int\
    \ i = 0; i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n     \
    \               mint r = a[s * m + i + m / 2] * w;\n                    a[s *\
    \ m + i] = l + r;\n                    a[s * m + i + m / 2] = l - r;\n       \
    \             w *= omega;\n                }\n            }\n        }\n    }\n\
    };\n\n// <167772161, 3>\n// <469762049, 3>\n// <754974721, 11>\n// <998244353,\
    \ 3>\n// <1224736769, 3>\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Number Theoretic Transform\n *\
    \ @docs docs/math/ntt.md\n */\ntemplate <typename mint, int primitive_root>\n\
    class NTT {\n    static constexpr int mod = mint::get_mod();\n\npublic:\n    NTT()\
    \ = delete;\n\n    static std::vector<mint> convolution(const std::vector<mint>&\
    \ a, const std::vector<mint>& b) {\n        int size = a.size() + b.size() - 1;\n\
    \        int n = 1;\n        while (n < size) n <<= 1;\n        std::vector<mint>\
    \ na(n), nb(n);\n        for (int i = 0; i < (int) a.size(); ++i) na[i] = a[i];\n\
    \        for (int i = 0; i < (int) b.size(); ++i) nb[i] = b[i];\n        untt(na);\n\
    \        untt(nb);\n        for (int i = 0; i < n; ++i) na[i] *= nb[i];\n    \
    \    iuntt(na);\n        na.resize(size);\n        mint n_inv = mint(n).inv();\n\
    \        for (int i = 0; i < size; ++i) na[i] *= n_inv;\n        return na;\n\
    \    }\n\nprivate:\n    static void untt(std::vector<mint>& a) {\n        int\
    \ n = a.size();\n        for (int m = n; m > 1; m >>= 1) {\n            mint omega\
    \ = mint(primitive_root).pow((mod - 1) / m);\n            for (int s = 0; s <\
    \ n / m; ++s) {\n                mint w = 1;\n                for (int i = 0;\
    \ i < m / 2; ++i) {\n                    mint l = a[s * m + i];\n            \
    \        mint r = a[s * m + i + m / 2];\n                    a[s * m + i] = l\
    \ + r;\n                    a[s * m + i + m / 2] = (l - r) * w;\n            \
    \        w *= omega;\n                }\n            }\n        }\n    }\n\n \
    \   static void iuntt(std::vector<mint>& a) {\n        int n = a.size();\n   \
    \     for (int m = 2; m <= n; m <<= 1) {\n            mint omega = mint(primitive_root).pow((mod\
    \ - 1) / m).inv();\n            for (int s = 0; s < n / m; ++s) {\n          \
    \      mint w = 1;\n                for (int i = 0; i < m / 2; ++i) {\n      \
    \              mint l = a[s * m + i];\n                    mint r = a[s * m +\
    \ i + m / 2] * w;\n                    a[s * m + i] = l + r;\n               \
    \     a[s * m + i + m / 2] = l - r;\n                    w *= omega;\n       \
    \         }\n            }\n        }\n    }\n};\n\n// <167772161, 3>\n// <469762049,\
    \ 3>\n// <754974721, 11>\n// <998244353, 3>\n// <1224736769, 3>"
  dependsOn: []
  isVerificationFile: false
  path: math/ntt.cpp
  requiredBy: []
  timestamp: '2020-09-26 16:05:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
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

- `mint`
    - `Modint` $mod p$
- `primitive_root`
    - $p$ の原子根

## Member functions

- `static vector<mint> convolution(vector<mint> a, vector<mint> b)`
    - `a` と `b` の畳み込みを $\mod p$ で計算する
    - 時間計算量: $O(n\lg n)$

## Note

数列の長さ $n$ が $p - 1$ を割り切るとき，1の原子 $n$ 乗根が必ず存在する．$n$ の長さを2冪にするため，素数 $p$ は $a \times 2^k + 1$ の形に表したとき $k$ が十分大きいものを用いる．

以下の `p` と `primitive_root` の組み合わせがよく用いられる:
- <167772161, 3>
- <469762049, 3>
- <754974721, 11>
- <998244353, 3>
- <1224736769, 3>

$k$ の値はそれぞれ，25, 26, 24, 23, 24である．