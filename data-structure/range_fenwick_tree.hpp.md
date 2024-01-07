---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
    title: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/range_fenwick_tree.hpp\"\n#include <vector>\n\
    \ntemplate <typename T>\nclass RangeFenwickTree {\n   public:\n    RangeFenwickTree()\
    \ = default;\n    explicit RangeFenwickTree(int n) : n(n), data0(n + 1), data1(n\
    \ + 1) {}\n\n    T prefix_sum(int i) const {\n        return prefix_sum(data0,\
    \ i) * (i - 1) + prefix_sum(data1, i);\n    }\n\n    void add(int l, int r, T\
    \ x) {\n        add(data0, l, x);\n        add(data0, r, -x);\n        add(data1,\
    \ l, -x * (l - 1));\n        add(data1, r, x * (r - 1));\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> data0, data1;\n\n    T prefix_sum(const std::vector<T>&\
    \ data, int i) const {\n        T ret = 0;\n        for (; i > 0; i -= i & -i)\
    \ ret += data[i];\n        return ret;\n    }\n\n    void add(std::vector<T>&\
    \ data, int i, T x) {\n        for (++i; i <= n; i += i & -i) data[i] += x;\n\
    \    }\n};\n"
  code: "#pragma once\n#include <vector>\n\ntemplate <typename T>\nclass RangeFenwickTree\
    \ {\n   public:\n    RangeFenwickTree() = default;\n    explicit RangeFenwickTree(int\
    \ n) : n(n), data0(n + 1), data1(n + 1) {}\n\n    T prefix_sum(int i) const {\n\
    \        return prefix_sum(data0, i) * (i - 1) + prefix_sum(data1, i);\n    }\n\
    \n    void add(int l, int r, T x) {\n        add(data0, l, x);\n        add(data0,\
    \ r, -x);\n        add(data1, l, -x * (l - 1));\n        add(data1, r, x * (r\
    \ - 1));\n    }\n\n   private:\n    int n;\n    std::vector<T> data0, data1;\n\
    \n    T prefix_sum(const std::vector<T>& data, int i) const {\n        T ret =\
    \ 0;\n        for (; i > 0; i -= i & -i) ret += data[i];\n        return ret;\n\
    \    }\n\n    void add(std::vector<T>& data, int i, T x) {\n        for (++i;\
    \ i <= n; i += i & -i) data[i] += x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/range_fenwick_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DSL_2_G.range_fenwick_tree.test.cpp
documentation_of: data-structure/range_fenwick_tree.hpp
layout: document
title: Fenwick Tree with Range Update
---

## Description

接頭辞和を扱う Fenwick tree を2つ使うことで，区間加算を実現できる．

空間計算量: $O(n)$

## Operations

- `RangeFenwickTree(int n)`
    - サイズ`n`で要素がすべて $0$ の区間更新 Fenwick tree を構築する
    - 時間計算量: $O(n)$
- `T prefix_sum(int i)`
    - $[0, i)$ の総和を計算する
    - 時間計算量: $O(\log n)$
- `void add(int l, int r, T x)`
    - 区間 $[l, r)$ に $x$ を加える
    - 時間計算量: $O(\log n)$

## Reference

- [Binary Indexed Tree のはなし](http://hos.ac/slides/20140319_bit.pdf)