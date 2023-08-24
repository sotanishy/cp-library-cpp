---
title: Relaxed Convolution
documentation_of: ../../convolution/relaxed_convolution.hpp
---

## Description

Relaxed convolution は，畳み込みをオンラインで処理するアルゴリズムである．すなわち，数列 $F, G$ の項が前から順番に与えられたとき，それらの畳み込み $H=F*G$ の各項を前から順番に返す．

## Operations

- `mint get(mint a, mint b)`
    - $F_n=a,G_n=b$ が与えられたとき， $H_n=\sum_{k=0}^n F_k G_{n-k}$ を返す．
    - 時間計算量: $\mathrm{amortized}\, O(N (\log N)^2)$

## Reference

- [オンライン畳み込み - Qiita](https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c)
- verify: [https://atcoder.jp/contests/abc315/submissions/44768767](https://atcoder.jp/contests/abc315/submissions/44768767)