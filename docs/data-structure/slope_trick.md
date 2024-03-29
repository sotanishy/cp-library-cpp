---
title: Slope Trick
documentation_of: ../../data-structure/slope_trick.hpp
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
    - 時間計算量: $O(\log n)$
- `void add_a_minus_x(T a)`
    - $\max(0, a - x)$ を加える
    - 時間計算量: $O(\log n)$
- `void add_abs(T a)`
    - $\vert x - a\vert$ を加える
    - 時間計算量: $O(\log n)$
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

## Note

slope trick では，
- $a$ だけ平行移動: $O(1)$
- 傾き $c$ の関数を加算: $O(\vert c \vert \log n)$

となる．凸共役を取ることで，
- $a$ だけ平行移動: $O(\vert a \vert \log n)$
- 傾き $c$ の関数を加算: $O(1)$

にできる．(参考文献参照)


## Reference

- [slope trick (1) 解説編](https://maspypy.com/slope-trick-1-%e8%a7%a3%e8%aa%ac%e7%b7%a8)
- [slope trick (3) slope trick の凸共役](https://maspypy.com/slope-trick-3-slope-trick-%e3%81%ae%e5%87%b8%e5%85%b1%e5%bd%b9)
- verify: [https://atcoder.jp/contests/abc217/submissions/25616122](https://atcoder.jp/contests/abc217/submissions/25616122)