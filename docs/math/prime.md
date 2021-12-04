---
title: Prime Number Algorithms
documentation_of: ../../math/prime.cpp
---

## Description

素数に関するアルゴリズム詰め合わせ

## Primality Test

$n$ を試し割り法で素数判定する．

- `bool is_prime(long long n)`
    - $n$ を素数判定する
    - 時間計算量: $O(\sqrt{n})$

## Prime Table

エラトステネスの篩を用いて，$n$ 以下の整数の素数表を構築する．

- `vector<bool> prime_table(int n)`
    - $n$ 以下の整数の素数表を構築する
    - 時間計算量: $O(n\log\log n)$

## Table of Minimum Prime Factors

エラトステネスの篩を用いて，$n$ 以下の整数のそれぞれについてその最小の素因数を計算する．

- `vector<bool> min_factor_table(int n)`
    - $n$ 以下の各整数の最小の素因数を計算する
    - 時間計算量: $O(n\log\log n)$

## Prime Factorization

$n$ を試し割り法で素因数分解する．

- `map<long long, int> prime_factor(long long n)`
    - $n$ を素因数分解し，素因数とその個数を返す．
    - 時間計算量: $O(\sqrt{n})$