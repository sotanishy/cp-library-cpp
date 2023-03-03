---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick_tree.cpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/permutation.hpp\"\n#include <vector>\n\n#line 2 \"\
    data-structure/fenwick_tree.cpp\"\n#include <functional>\n#line 4 \"data-structure/fenwick_tree.cpp\"\
    \n\ntemplate <typename M>\nclass FenwickTree {\n    using T = typename M::T;\n\
    \npublic:\n    FenwickTree() = default;\n    explicit FenwickTree(int n) : n(n),\
    \ data(n + 1, M::id()) {}\n\n    T prefix_fold(int i) const {\n        T ret =\
    \ M::id();\n        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);\n  \
    \      return ret;\n    }\n\n    void update(int i, const T& x) {\n        for\
    \ (++i; i <= n; i += i & -i) data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const\
    \ T& x) const {\n        if (x <= M::id()) return 0;\n        int k = 1;\n   \
    \     while (k * 2 <= n) k <<= 1;\n        int i = 0;\n        T v = M::id();\n\
    \        for (; k > 0; k >>= 1) {\n            if (i + k > n) continue;\n    \
    \        T nv = M::op(v, data[i + k]);\n            if (nv < x) {\n          \
    \      v = nv;\n                i += k;\n            }\n        }\n        return\
    \ i;\n    }\n\nprivate:\n    int n;\n    std::vector<T> data;\n};\n#line 5 \"\
    misc/permutation.hpp\"\n\nstruct AddMonoid {\n    using T = int;\n    static T\
    \ id() { return 0; }\n    static T op(T a, T b) { return a + b; }\n};\n\nstd::vector<int>\
    \ perm_to_num(const std::vector<int>& P) {\n    int N = P.size();\n    std::vector<int>\
    \ num(N);\n    FenwickTree<AddMonoid> ft(N);\n    for (int i = N - 1; i >= 0;\
    \ --i) {\n        ft.update(P[i], 1);\n        num[N - i - 1] = ft.prefix_fold(P[i]);\n\
    \    }\n    return num;\n}\n\nstd::vector<int> num_to_perm(const std::vector<int>&\
    \ num) {\n    int N = num.size();\n    std::vector<int> P(N);\n    FenwickTree<AddMonoid>\
    \ ft(N);\n    for (int i = 0; i < N; ++i) ft.update(i, 1);\n    for (int i = 0;\
    \ i < N; ++i) {\n        P[i] = ft.lower_bound(num[N - i - 1] + 1);\n        ft.update(P[i],\
    \ -1);\n    }\n    return P;\n}\n"
  code: "#pragma once\n#include <vector>\n\n#include \"../data-structure/fenwick_tree.cpp\"\
    \n\nstruct AddMonoid {\n    using T = int;\n    static T id() { return 0; }\n\
    \    static T op(T a, T b) { return a + b; }\n};\n\nstd::vector<int> perm_to_num(const\
    \ std::vector<int>& P) {\n    int N = P.size();\n    std::vector<int> num(N);\n\
    \    FenwickTree<AddMonoid> ft(N);\n    for (int i = N - 1; i >= 0; --i) {\n \
    \       ft.update(P[i], 1);\n        num[N - i - 1] = ft.prefix_fold(P[i]);\n\
    \    }\n    return num;\n}\n\nstd::vector<int> num_to_perm(const std::vector<int>&\
    \ num) {\n    int N = num.size();\n    std::vector<int> P(N);\n    FenwickTree<AddMonoid>\
    \ ft(N);\n    for (int i = 0; i < N; ++i) ft.update(i, 1);\n    for (int i = 0;\
    \ i < N; ++i) {\n        P[i] = ft.lower_bound(num[N - i - 1] + 1);\n        ft.update(P[i],\
    \ -1);\n    }\n    return P;\n}"
  dependsOn:
  - data-structure/fenwick_tree.cpp
  isVerificationFile: false
  path: misc/permutation.hpp
  requiredBy: []
  timestamp: '2023-03-03 22:38:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/permutation.hpp
layout: document
redirect_from:
- /library/misc/permutation.hpp
- /library/misc/permutation.hpp.html
title: misc/permutation.hpp
---
