---
title: Convex Min-Plus Convolution
documentation_of: ../../convolution/convex_min_plus_convolution.hpp
---

## Description

数列 $a$ と上に凸な数列 $b$ の min-plus convolution $c_i=\min_j \{a_j + b_{i-j}\}$ を求める．

- `vector<T> convex_min_plus_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と上に凸な数列 $b$ の min-plus convolution を求める
    - 時間計算量: $O((n + m) \log (n+m))$
- `vector<T> concave_max_plus_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と下に凸な数列 $b$ の max-plus convolution を求める
    - 時間計算量: $O((n + m) \log (n+m))$

## Reference

- [[Tutorial] Knapsack, Subset Sum and the (max,+) Convolution](https://codeforces.com/blog/entry/98663)
