---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/disjoint_sparse_table.cpp
    title: Disjoint Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Combination (Large)
    links: []
  bundledCode: "#line 2 \"math/combination_large.hpp\"\n#include <vector>\n\n#line\
    \ 2 \"data-structure/disjoint_sparse_table.cpp\"\n#include <algorithm>\n#line\
    \ 4 \"data-structure/disjoint_sparse_table.cpp\"\n\ntemplate <typename M>\nclass\
    \ DisjointSparseTable {\n    using T = typename M::T;\n\n   public:\n    DisjointSparseTable()\
    \ = default;\n    explicit DisjointSparseTable(const std::vector<T>& v) {\n  \
    \      int n = v.size(), b = 0;\n        while ((1 << b) < n) ++b;\n        lookup.resize(b\
    \ + 1, std::vector<T>(n));\n        std::copy(v.begin(), v.end(), lookup[0].begin());\n\
    \        for (int i = 1; i <= b; ++i) {\n            int len = 1 << i;\n     \
    \       for (int l = 0; l + len / 2 < n; l += len) {\n                int m =\
    \ l + len / 2;\n                lookup[i][m - 1] = v[m - 1];\n               \
    \ for (int j = m - 2; j >= l; --j) {\n                    lookup[i][j] = M::op(lookup[i][j\
    \ + 1], v[j]);\n                }\n                lookup[i][m] = v[m];\n    \
    \            for (int j = m + 1; j < std::min(l + len, n); ++j) {\n          \
    \          lookup[i][j] = M::op(lookup[i][j - 1], v[j]);\n                }\n\
    \            }\n        }\n    }\n\n    T fold(int l, int r) const {\n       \
    \ if (l == r) return M::id();\n        if (r - l == 1) return lookup[0][l];\n\
    \        int i = 32 - __builtin_clz(l ^ (r - 1));\n        return M::op(lookup[i][l],\
    \ lookup[i][r - 1]);\n    }\n\n   private:\n    std::vector<std::vector<T>> lookup;\n\
    };\n#line 5 \"math/combination_large.hpp\"\n\n/**\n * @brief Combination (Large)\n\
    \ */\ntemplate <typename mint>\nclass CombinationLarge {\n   public:\n    CombinationLarge()\
    \ = default;\n    CombinationLarge(int N, long long M)\n        : N(N), M(M),\
    \ fact_(N + 1), fact_inv_(N + 1) {\n        fact_[0] = 1;\n        for (int i\
    \ = 1; i <= N; ++i) fact_[i] = fact_[i - 1] * i;\n        fact_inv_[N] = fact_[N].inv();\n\
    \        for (int i = N; i > 0; --i) fact_inv_[i - 1] = fact_inv_[i] * i;\n\n\
    \        std::vector<mint> num(N + 1);\n        for (int i = 0; i <= N; ++i) {\n\
    \            num[i] = M - i;\n        }\n        st = DisjointSparseTable<MulMonoid>(num);\n\
    \    }\n\n    mint perm(long long n, int k) const {\n        assert(M - N + k\
    \ - 1 <= n && n <= M);\n        if (k < 0 || n < k) return 0;\n        return\
    \ st.fold(M - n, M - n + k);\n    }\n\n    mint comb(long long n, int k) const\
    \ {\n        assert(M - N + k - 1 <= n && n <= M);\n        if (k < 0 || n < k)\
    \ return 0;\n        return st.fold(M - n, M - n + k) * fact_inv_[k];\n    }\n\
    \n    mint fact(int n) const { return fact_[n]; }\n    mint fact_inv(int n) const\
    \ { return fact_inv_[n]; }\n\n   private:\n    struct MulMonoid {\n        using\
    \ T = mint;\n        static T id() { return 1; }\n        static T op(T a, T b)\
    \ { return a * b; }\n    };\n\n    int N;\n    long long M;\n    std::vector<mint>\
    \ fact_, fact_inv_;\n    DisjointSparseTable<MulMonoid> st;\n};\n"
  code: "#pragma once\n#include <vector>\n\n#include \"../data-structure/disjoint_sparse_table.cpp\"\
    \n\n/**\n * @brief Combination (Large)\n */\ntemplate <typename mint>\nclass CombinationLarge\
    \ {\n   public:\n    CombinationLarge() = default;\n    CombinationLarge(int N,\
    \ long long M)\n        : N(N), M(M), fact_(N + 1), fact_inv_(N + 1) {\n     \
    \   fact_[0] = 1;\n        for (int i = 1; i <= N; ++i) fact_[i] = fact_[i - 1]\
    \ * i;\n        fact_inv_[N] = fact_[N].inv();\n        for (int i = N; i > 0;\
    \ --i) fact_inv_[i - 1] = fact_inv_[i] * i;\n\n        std::vector<mint> num(N\
    \ + 1);\n        for (int i = 0; i <= N; ++i) {\n            num[i] = M - i;\n\
    \        }\n        st = DisjointSparseTable<MulMonoid>(num);\n    }\n\n    mint\
    \ perm(long long n, int k) const {\n        assert(M - N + k - 1 <= n && n <=\
    \ M);\n        if (k < 0 || n < k) return 0;\n        return st.fold(M - n, M\
    \ - n + k);\n    }\n\n    mint comb(long long n, int k) const {\n        assert(M\
    \ - N + k - 1 <= n && n <= M);\n        if (k < 0 || n < k) return 0;\n      \
    \  return st.fold(M - n, M - n + k) * fact_inv_[k];\n    }\n\n    mint fact(int\
    \ n) const { return fact_[n]; }\n    mint fact_inv(int n) const { return fact_inv_[n];\
    \ }\n\n   private:\n    struct MulMonoid {\n        using T = mint;\n        static\
    \ T id() { return 1; }\n        static T op(T a, T b) { return a * b; }\n    };\n\
    \n    int N;\n    long long M;\n    std::vector<mint> fact_, fact_inv_;\n    DisjointSparseTable<MulMonoid>\
    \ st;\n};"
  dependsOn:
  - data-structure/disjoint_sparse_table.cpp
  isVerificationFile: false
  path: math/combination_large.hpp
  requiredBy: []
  timestamp: '2023-05-27 03:55:18+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/combination_large.hpp
layout: document
redirect_from:
- /library/math/combination_large.hpp
- /library/math/combination_large.hpp.html
title: Combination (Large)
---
