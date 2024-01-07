---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/fenwick_tree.hpp
    title: data-structure/fenwick_tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Lexicographic Index of Permutations (in Factorial Number System)
    links: []
  bundledCode: "#line 2 \"misc/permutation.hpp\"\n#include <vector>\n\n#line 2 \"\
    data-structure/fenwick_tree.hpp\"\n#include <functional>\n#line 4 \"data-structure/fenwick_tree.hpp\"\
    \n\ntemplate <typename M>\nclass FenwickTree {\n    using T = M::T;\n\n   public:\n\
    \    FenwickTree() = default;\n    explicit FenwickTree(int n) : n(n), data(n\
    \ + 1, M::id()) {}\n\n    T prefix_fold(int i) const {\n        T ret = M::id();\n\
    \        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return\
    \ ret;\n    }\n\n    void update(int i, const T& x) {\n        for (++i; i <=\
    \ n; i += i & -i) data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const\
    \ T& x) const { return lower_bound(x, std::less<>()); }\n\n    template <typename\
    \ Compare>\n    int lower_bound(const T& x, Compare cmp) const {\n        if (!cmp(M::id(),\
    \ x)) return 0;\n        int k = 1;\n        while (k * 2 <= n) k <<= 1;\n   \
    \     int i = 0;\n        T v = M::id();\n        for (; k > 0; k >>= 1) {\n \
    \           if (i + k > n) continue;\n            T nv = M::op(v, data[i + k]);\n\
    \            if (cmp(nv, x)) {\n                v = nv;\n                i +=\
    \ k;\n            }\n        }\n        return i + 1;\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> data;\n};\n#line 5 \"misc/permutation.hpp\"\n\n\
    /**\n * @brief Lexicographic Index of Permutations (in Factorial Number System)\n\
    \ */\n\nstruct AddMonoid {\n    using T = int;\n    static T id() { return 0;\
    \ }\n    static T op(T a, T b) { return a + b; }\n};\n\nstd::vector<int> perm_to_num(const\
    \ std::vector<int>& p) {\n    const int n = p.size();\n    std::vector<int> num(n);\n\
    \    FenwickTree<AddMonoid> ft(n);\n    for (int i = n - 1; i >= 0; --i) {\n \
    \       ft.update(p[i], 1);\n        num[n - i - 1] = ft.prefix_fold(p[i]);\n\
    \    }\n    return num;\n}\n\nstd::vector<int> num_to_perm(const std::vector<int>&\
    \ num) {\n    const int n = num.size();\n    std::vector<int> p(n);\n    FenwickTree<AddMonoid>\
    \ ft(n);\n    for (int i = 0; i < n; ++i) ft.update(i, 1);\n    for (int i = 0;\
    \ i < n; ++i) {\n        p[i] = ft.lower_bound(num[n - i - 1] + 1);\n        ft.update(p[i],\
    \ -1);\n    }\n    return p;\n}\n"
  code: "#pragma once\n#include <vector>\n\n#include \"../data-structure/fenwick_tree.hpp\"\
    \n\n/**\n * @brief Lexicographic Index of Permutations (in Factorial Number System)\n\
    \ */\n\nstruct AddMonoid {\n    using T = int;\n    static T id() { return 0;\
    \ }\n    static T op(T a, T b) { return a + b; }\n};\n\nstd::vector<int> perm_to_num(const\
    \ std::vector<int>& p) {\n    const int n = p.size();\n    std::vector<int> num(n);\n\
    \    FenwickTree<AddMonoid> ft(n);\n    for (int i = n - 1; i >= 0; --i) {\n \
    \       ft.update(p[i], 1);\n        num[n - i - 1] = ft.prefix_fold(p[i]);\n\
    \    }\n    return num;\n}\n\nstd::vector<int> num_to_perm(const std::vector<int>&\
    \ num) {\n    const int n = num.size();\n    std::vector<int> p(n);\n    FenwickTree<AddMonoid>\
    \ ft(n);\n    for (int i = 0; i < n; ++i) ft.update(i, 1);\n    for (int i = 0;\
    \ i < n; ++i) {\n        p[i] = ft.lower_bound(num[n - i - 1] + 1);\n        ft.update(p[i],\
    \ -1);\n    }\n    return p;\n}"
  dependsOn:
  - data-structure/fenwick_tree.hpp
  isVerificationFile: false
  path: misc/permutation.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/permutation.hpp
layout: document
redirect_from:
- /library/misc/permutation.hpp
- /library/misc/permutation.hpp.html
title: Lexicographic Index of Permutations (in Factorial Number System)
---
