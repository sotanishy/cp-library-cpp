---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: misc/permutation.hpp
    title: Lexicographic Index of Permutations (in Factorial Number System)
  - icon: ':x:'
    path: tree/range_contour_aggregation.hpp
    title: Range Contour Aggregation
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_subsequences.test.cpp
    title: test/yosupo/number_of_subsequences.test.cpp
  - icon: ':x:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
    title: test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/fenwick_tree.hpp\"\n#include <functional>\n\
    #include <vector>\n\ntemplate <typename M>\nclass FenwickTree {\n    using T =\
    \ M::T;\n\n   public:\n    FenwickTree() = default;\n    explicit FenwickTree(int\
    \ n) : n(n), data(n + 1, M::id()) {}\n\n    T prefix_fold(int i) const {\n   \
    \     T ret = M::id();\n        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);\n\
    \        return ret;\n    }\n\n    void update(int i, const T& x) {\n        for\
    \ (++i; i <= n; i += i & -i) data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const\
    \ T& x) const { return lower_bound(x, std::less<>()); }\n\n    template <typename\
    \ Compare>\n    int lower_bound(const T& x, Compare cmp) const {\n        if (!cmp(M::id(),\
    \ x)) return 0;\n        int k = 1;\n        while (k * 2 <= n) k <<= 1;\n   \
    \     int i = 0;\n        T v = M::id();\n        for (; k > 0; k >>= 1) {\n \
    \           if (i + k > n) continue;\n            T nv = M::op(v, data[i + k]);\n\
    \            if (cmp(nv, x)) {\n                v = nv;\n                i +=\
    \ k;\n            }\n        }\n        return i + 1;\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> data;\n};\n"
  code: "#pragma once\n#include <functional>\n#include <vector>\n\ntemplate <typename\
    \ M>\nclass FenwickTree {\n    using T = M::T;\n\n   public:\n    FenwickTree()\
    \ = default;\n    explicit FenwickTree(int n) : n(n), data(n + 1, M::id()) {}\n\
    \n    T prefix_fold(int i) const {\n        T ret = M::id();\n        for (; i\
    \ > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return ret;\n    }\n\n\
    \    void update(int i, const T& x) {\n        for (++i; i <= n; i += i & -i)\
    \ data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const T& x) const\
    \ { return lower_bound(x, std::less<>()); }\n\n    template <typename Compare>\n\
    \    int lower_bound(const T& x, Compare cmp) const {\n        if (!cmp(M::id(),\
    \ x)) return 0;\n        int k = 1;\n        while (k * 2 <= n) k <<= 1;\n   \
    \     int i = 0;\n        T v = M::id();\n        for (; k > 0; k >>= 1) {\n \
    \           if (i + k > n) continue;\n            T nv = M::op(v, data[i + k]);\n\
    \            if (cmp(nv, x)) {\n                v = nv;\n                i +=\
    \ k;\n            }\n        }\n        return i + 1;\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> data;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/fenwick_tree.hpp
  requiredBy:
  - misc/permutation.hpp
  - tree/range_contour_aggregation.hpp
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  - test/yosupo/vertex_add_range_contour_sum_on_tree.test.cpp
  - test/yosupo/static_range_inversions_query.test.cpp
  - test/yosupo/number_of_subsequences.test.cpp
  - test/aoj/DSL_2_B.test.cpp
documentation_of: data-structure/fenwick_tree.hpp
layout: document
redirect_from:
- /library/data-structure/fenwick_tree.hpp
- /library/data-structure/fenwick_tree.hpp.html
title: data-structure/fenwick_tree.hpp
---
