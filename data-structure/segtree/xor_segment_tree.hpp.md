---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/xor_segment_tree.hpp\"\n#include\
    \ <algorithm>\n#include <bit>\n#include <vector>\n\ntemplate <typename M>\nclass\
    \ XorSegmentTree {\n    using T = M::T;\n\n   public:\n    XorSegmentTree() =\
    \ default;\n    explicit XorSegmentTree(int n)\n        : XorSegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    explicit XorSegmentTree(const std::vector<T>& v)\n       \
    \ : size(std::bit_ceil(v.size())),\n          n(std::bit_width(size) - 1),\n \
    \         table(2 * size),\n          half(1 << ((n + 1) / 2)) {\n        for\
    \ (int k = 0; k < size; ++k) {\n            table[size + k].resize(1, k < (int)v.size()\
    \ ? v[k] : M::id());\n        }\n        for (int k = size - 1; k >= half; --k)\
    \ pull(k);\n    }\n\n    void update(int k, const T& x) {\n        k += size;\n\
    \        table[k][0] = x;\n        for (k >>= 1; k >= half; k >>= 1) pull(k);\n\
    \    }\n\n    T fold(int l, int r, int x) const {\n        T vl = M::id(), vr\
    \ = M::id();\n        int i = 0;\n        for (l += size, r += size; l < r &&\
    \ l > 2 * half;\n             l >>= 1, r >>= 1, ++i) {\n            if (l & 1)\
    \ {\n                vl = M::op(vl, table[l++ ^ (x >> i)][x & ((1 << i) - 1)]);\n\
    \            }\n            if (r & 1) {\n                vr = M::op(table[--r\
    \ ^ (x >> i)][x & ((1 << i) - 1)], vr);\n            }\n        }\n        for\
    \ (int k = l; k < r; ++k) {\n            vl = M::op(vl, table[k ^ (x >> i)][x\
    \ & ((1 << i) - 1)]);\n        }\n        return M::op(vl, vr);\n    }\n\n   private:\n\
    \    int n, size, half;\n    std::vector<std::vector<T>> table;\n\n    void pull(int\
    \ k) {\n        int i = n - std::bit_width(k) + 1;\n        table[k].resize(1\
    \ << i);\n        for (int x = 0; x < (1 << i); ++x) {\n            T vl = table[2\
    \ * k][x & ~(1 << (i - 1))];\n            T vr = table[2 * k + 1][x & ~(1 << (i\
    \ - 1))];\n            if (x >> (i - 1) & 1) std::swap(vl, vr);\n            table[k][x]\
    \ = M::op(vl, vr);\n        }\n    }\n};\n\ntemplate <typename M>\nclass XorSegmentTreeCommutative\
    \ {\n    using T = M::T;\n\n   public:\n    XorSegmentTreeCommutative() = default;\n\
    \    explicit XorSegmentTreeCommutative(int n)\n        : XorSegmentTreeCommutative(std::vector<T>(n,\
    \ M::id())) {}\n    explicit XorSegmentTreeCommutative(const std::vector<T>& v)\n\
    \        : size(std::bit_ceil(v.size())), node(2 * size, M::id()) {\n        std::ranges::copy(v,\
    \ node.begin() + size);\n\n        for (int k = size - 1; k > 0; --k) {\n    \
    \        node[k] = M::op(node[2 * k], node[2 * k + 1]);\n        }\n    }\n\n\
    \    void update(int k, const T& x) {\n        k += size;\n        node[k] = x;\n\
    \        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\
    \n    T fold(int l, int r, int x) const {\n        T res = M::id();\n        for\
    \ (l += size, r += size; l < r; l >>= 1, r >>= 1, x >>= 1) {\n            if (l\
    \ & 1) res = M::op(res, node[l++ ^ x]);\n            if (r & 1) res = M::op(node[--r\
    \ ^ x], res);\n        }\n        return res;\n    }\n\n   private:\n    int size;\n\
    \    std::vector<T> node;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <vector>\n\n\
    template <typename M>\nclass XorSegmentTree {\n    using T = M::T;\n\n   public:\n\
    \    XorSegmentTree() = default;\n    explicit XorSegmentTree(int n)\n       \
    \ : XorSegmentTree(std::vector<T>(n, M::id())) {}\n    explicit XorSegmentTree(const\
    \ std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\n          n(std::bit_width(size)\
    \ - 1),\n          table(2 * size),\n          half(1 << ((n + 1) / 2)) {\n  \
    \      for (int k = 0; k < size; ++k) {\n            table[size + k].resize(1,\
    \ k < (int)v.size() ? v[k] : M::id());\n        }\n        for (int k = size -\
    \ 1; k >= half; --k) pull(k);\n    }\n\n    void update(int k, const T& x) {\n\
    \        k += size;\n        table[k][0] = x;\n        for (k >>= 1; k >= half;\
    \ k >>= 1) pull(k);\n    }\n\n    T fold(int l, int r, int x) const {\n      \
    \  T vl = M::id(), vr = M::id();\n        int i = 0;\n        for (l += size,\
    \ r += size; l < r && l > 2 * half;\n             l >>= 1, r >>= 1, ++i) {\n \
    \           if (l & 1) {\n                vl = M::op(vl, table[l++ ^ (x >> i)][x\
    \ & ((1 << i) - 1)]);\n            }\n            if (r & 1) {\n             \
    \   vr = M::op(table[--r ^ (x >> i)][x & ((1 << i) - 1)], vr);\n            }\n\
    \        }\n        for (int k = l; k < r; ++k) {\n            vl = M::op(vl,\
    \ table[k ^ (x >> i)][x & ((1 << i) - 1)]);\n        }\n        return M::op(vl,\
    \ vr);\n    }\n\n   private:\n    int n, size, half;\n    std::vector<std::vector<T>>\
    \ table;\n\n    void pull(int k) {\n        int i = n - std::bit_width(k) + 1;\n\
    \        table[k].resize(1 << i);\n        for (int x = 0; x < (1 << i); ++x)\
    \ {\n            T vl = table[2 * k][x & ~(1 << (i - 1))];\n            T vr =\
    \ table[2 * k + 1][x & ~(1 << (i - 1))];\n            if (x >> (i - 1) & 1) std::swap(vl,\
    \ vr);\n            table[k][x] = M::op(vl, vr);\n        }\n    }\n};\n\ntemplate\
    \ <typename M>\nclass XorSegmentTreeCommutative {\n    using T = M::T;\n\n   public:\n\
    \    XorSegmentTreeCommutative() = default;\n    explicit XorSegmentTreeCommutative(int\
    \ n)\n        : XorSegmentTreeCommutative(std::vector<T>(n, M::id())) {}\n   \
    \ explicit XorSegmentTreeCommutative(const std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\
    \ node(2 * size, M::id()) {\n        std::ranges::copy(v, node.begin() + size);\n\
    \n        for (int k = size - 1; k > 0; --k) {\n            node[k] = M::op(node[2\
    \ * k], node[2 * k + 1]);\n        }\n    }\n\n    void update(int k, const T&\
    \ x) {\n        k += size;\n        node[k] = x;\n        while (k >>= 1) node[k]\
    \ = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n    T fold(int l, int r, int\
    \ x) const {\n        T res = M::id();\n        for (l += size, r += size; l <\
    \ r; l >>= 1, r >>= 1, x >>= 1) {\n            if (l & 1) res = M::op(res, node[l++\
    \ ^ x]);\n            if (r & 1) res = M::op(node[--r ^ x], res);\n        }\n\
    \        return res;\n    }\n\n   private:\n    int size;\n    std::vector<T>\
    \ node;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/xor_segment_tree.hpp
  requiredBy: []
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/segtree/xor_segment_tree.hpp
layout: document
title: Xor Segment Tree
---

## Description

XOR セグメント木は，通常のセグメント木の操作の際に， index をすべて非負整数 $x$ との xor を適用したものに置き換えて操作することができる．

空間計算量: $O(n \log n)$

## Operations

- `XorSegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ のセグメント木を構築する
    - 時間計算量: $O(n\log n)$
- `SegmentTree(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`のセグメント木を構築する
    - 時間計算量: $O(n\log n)$
- `void update(int k, T x)`
    - $k$ 番目の要素を $x$ に更新する
    - 時間計算量: $O(\sqrt{n})$
- `T fold(int l, int r, int x)`
    - $a_{l\oplus x} * a_{(l+1)\oplus x} * \dots * a_{(r-1) \oplus x}$ を計算する
    - 時間計算量: $O(\sqrt{n})$

## Note

モノイドが可換であるバージョン `XorSegmentTreeCommutative` は，通常のセグメント木と同じ計算量で各種操作を実行することができる．

## Reference

- verify (`XorSegmentTree`): [https://yukicoder.me/submissions/942181](https://yukicoder.me/submissions/942181)
- verify (`XorSegmentTreeCommutative`): [https://codeforces.com/contest/1401/submission/197492564](https://codeforces.com/contest/1401/submission/197492564)