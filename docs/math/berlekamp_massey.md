---
title: Berlekamp-Massey Algorithm
documentation_of: ../../math/berlekamp_massey.cpp
---

## Description

Berlekamp-Massey のアルゴリズムは，与えられた数列を生成する最短の線形漸化式を求めるアルゴリズムである．

## Operations

- `vector<T> berlekamp_massey(vector<T> a)`
    - $a$ を生成する最短の線形漸化式を1つ求める
    - 時間計算量: $O(n^2)$

## Note

漸化式がわからない数列`f`の最初のいくつかを愚直に求めて，Berlekamp-Masseyで漸化式を得て，高速 Kitamasa 法で第`k`項を求めるという暴力的な方法がある．

```
auto coef = berlekamp_massey(f);
f.resize(coef.size());
reverse(coef.begin(), coef.end());
auto ans = kitamasa(f, coef, k);
```


## Reference

- [Berlekamp–Massey algorithm](https://en.wikipedia.org/wiki/Berlekamp%E2%80%93Massey_algorithm)
- [Linear Recurrence and Berlekamp-Massey Algorithm](https://codeforces.com/blog/entry/61306?f0a28=1)