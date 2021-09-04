---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/slope_trick.cpp\"\n#include <functional>\n\
    #include <limits>\n#include <queue>\n#include <vector>\n\ntemplate <typename T>\n\
    class SlopeTrick {\n   public:\n    SlopeTrick() {\n        const T INF = std::numeric_limits<T>::max()\
    \ / 2;\n        left.push(-INF);\n        right.push(INF);\n    }\n\n    void\
    \ add_const(T a) { min_y += a; }\n\n    void add_x_minus_a(T a) {\n        T l\
    \ = top_l();\n        if (l < a) {\n            push_r(a);\n        } else {\n\
    \            min_y += l - a;\n            push_l(a);\n            push_r(pop_l());\n\
    \        }\n    }\n\n    void add_a_minus_x(T a) {\n        T r = top_r();\n \
    \       if (a < r) {\n            push_l(a);\n        } else {\n            min_y\
    \ += a - r;\n            push_r(a);\n            push_l(pop_r());\n        }\n\
    \    }\n\n    void add_abs(T a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n\
    \    }\n\n    void clear_left() { left.clear(); }\n    void clear_right() { right.clear();\
    \ }\n\n    void shift(T a) { shift(a, a); }\n\n    void shift(T a, T b) {\n  \
    \      add_l += a;\n        add_r += b;\n    }\n\n    T get_min() { return min_y;\
    \ }\n\n    T get(T x) {\n        T ret = min_y;\n        std::priority_queue<T,\
    \ std::vector<T>> tmp_l;\n        std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ tmp_r;\n        while (!left.empty()) {\n            T a = pop_l();\n      \
    \      ret += max(T(0), a - x);\n            tmp_l.push(a);\n        }\n     \
    \   while (!right.empty()) {\n            T a = pop_r();\n            ret += max(T(0),\
    \ x - a);\n            tmp_r.push(a);\n        }\n        left.swap(tmp_l);\n\
    \        right.swap(tmp_r);\n        add_l = add_r = 0;\n        return ret;\n\
    \    }\n\n   private:\n    T min_y = 0, add_l = 0, add_r = 0;\n    std::priority_queue<T,\
    \ std::vector<T>> left;\n    std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ right;\n\n    void push_l(T a) { left.push(a - add_l); }\n    void push_r(T\
    \ a) { right.push(a - add_r); }\n\n    T top_l() { return left.top() + add_l;\
    \ }\n    T top_r() { return right.top() + add_r; }\n\n    T pop_l() {\n      \
    \  T a = top_l();\n        left.pop();\n        return a;\n    }\n\n    T pop_r()\
    \ {\n        T a = top_r();\n        right.pop();\n        return a;\n    }\n\
    };\n"
  code: "#pragma once\n#include <functional>\n#include <limits>\n#include <queue>\n\
    #include <vector>\n\ntemplate <typename T>\nclass SlopeTrick {\n   public:\n \
    \   SlopeTrick() {\n        const T INF = std::numeric_limits<T>::max() / 2;\n\
    \        left.push(-INF);\n        right.push(INF);\n    }\n\n    void add_const(T\
    \ a) { min_y += a; }\n\n    void add_x_minus_a(T a) {\n        T l = top_l();\n\
    \        if (l < a) {\n            push_r(a);\n        } else {\n            min_y\
    \ += l - a;\n            push_l(a);\n            push_r(pop_l());\n        }\n\
    \    }\n\n    void add_a_minus_x(T a) {\n        T r = top_r();\n        if (a\
    \ < r) {\n            push_l(a);\n        } else {\n            min_y += a - r;\n\
    \            push_r(a);\n            push_l(pop_r());\n        }\n    }\n\n  \
    \  void add_abs(T a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n\
    \    }\n\n    void clear_left() { left.clear(); }\n    void clear_right() { right.clear();\
    \ }\n\n    void shift(T a) { shift(a, a); }\n\n    void shift(T a, T b) {\n  \
    \      add_l += a;\n        add_r += b;\n    }\n\n    T get_min() { return min_y;\
    \ }\n\n    T get(T x) {\n        T ret = min_y;\n        std::priority_queue<T,\
    \ std::vector<T>> tmp_l;\n        std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ tmp_r;\n        while (!left.empty()) {\n            T a = pop_l();\n      \
    \      ret += max(T(0), a - x);\n            tmp_l.push(a);\n        }\n     \
    \   while (!right.empty()) {\n            T a = pop_r();\n            ret += max(T(0),\
    \ x - a);\n            tmp_r.push(a);\n        }\n        left.swap(tmp_l);\n\
    \        right.swap(tmp_r);\n        add_l = add_r = 0;\n        return ret;\n\
    \    }\n\n   private:\n    T min_y = 0, add_l = 0, add_r = 0;\n    std::priority_queue<T,\
    \ std::vector<T>> left;\n    std::priority_queue<T, std::vector<T>, std::greater<T>>\
    \ right;\n\n    void push_l(T a) { left.push(a - add_l); }\n    void push_r(T\
    \ a) { right.push(a - add_r); }\n\n    T top_l() { return left.top() + add_l;\
    \ }\n    T top_r() { return right.top() + add_r; }\n\n    T pop_l() {\n      \
    \  T a = top_l();\n        left.pop();\n        return a;\n    }\n\n    T pop_r()\
    \ {\n        T a = top_r();\n        right.pop();\n        return a;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slope_trick.cpp
  requiredBy: []
  timestamp: '2021-09-05 01:22:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/slope_trick.cpp
layout: document
title: Slope Trick
---

## Description

Slope Trick は，区分線形凸関数 $f: T \mapsto T$ を管理するテクニックである．傾きの変化点を，傾きが正である部分と負である部分で別々に優先度付きキューで管理することで，この関数に対する様々な操作を高速に処理する．

空間計算量: $O(n)$

## Operations

- `void add_const(T a)`
    - $a$ を加える
    - 時間計算量: $O(1)$
- `void add_x_minus_a(T a)`
    - $\max(0, x - a)$ を加える
    - 時間計算量: $O(\lg n)$
- `void add_a_minus_x(T a)`
    - $\max(0, a - x)$ を加える
    - 時間計算量: $O(\lg n)$
- `void add_abs(T a)`
    - $|x - a|$ を加える
    - 時間計算量: $O(\lg n)$
- `void clear_left()`
    - $g(x) := \min_{y \leq x} f(y)$ として，$f$ を $g$ に置き換える
    - 時間計算量: $O(n)$
- `void clear_right()`
    - $g(x) := \min_{y \geq x} f(y)$ として，$f$ を $g$ に置き換える
    - 時間計算量: $O(n)$
- `void shift(T a)`
    - $g(x) := f(x - a)$ として，$f$ を $g$ に置き換える
    - 時間計算量: $O(1)$
- `void shift(T a, T b)`
    - $g(x) := \min_{x - b \leq y \leq x - a} f(y)$ として，$f$ を $g$ に置き換える
    - 時間計算量: $O(1)$
- `T get_min()`
    - $f$ の最小値を返す
    - 時間計算量: $O(1)$
- `T get(T x)`
    - $f(x)$ を返す
    - 時間計算量: $O(n)$

## Reference

- [slope trick (1) 解説編](https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8)