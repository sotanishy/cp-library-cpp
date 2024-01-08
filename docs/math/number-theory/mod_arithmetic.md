---
title: Modular Arithmetic
documentation_of: ../../../math/number-theory/mod_arithmetic.hpp
---

## Description

モジュラ計算アルゴリズム詰め合わせ

## Modular Exponentiation

$a^e \mod mod$ を二分累乗法で計算する．

また，$mod$ が素数であるとき，Fermat の小定理を利用して $n$ の法 $mod$ での逆元を計算することができる．(拡張 Euclid 互除法を用いた逆元の計算では $mod$ が素数である必要がなく，定数倍速いため，基本的にはそちらを用いる)

- `long long mod_pow(long long a, long long e, int mod)`
    - $a^e \mod mod$ を計算する
    - 時間計算量: $O(\log e)$

- `long long mod_inv(long long a, int mod)`
    - $a$ の $\mod mod$ での逆元を計算する
    - 時間計算量: $O(\log mod)$

## Discrete Logarithm

離散対数を計算する．すなわち，$a^x \equiv b \mod mod$ を満たす $x$ を求める．

Baby-step giant-step 法を用いている．

- `int mod_log(long long a, long long b, int mod)`
    - $a^x \equiv b \mod mod$ を満たす $x$ を求める．存在しない場合は $-1$ を返す．
    - 時間計算量: $O(\sqrt{mod})$

## Quadratic Residue

平方剰余を計算する．すなわち，$r^2 \equiv n \mod mod$ を満たす $r$ を求める．

Tonelli-Shanks のアルゴリズムを用いている．時間計算量はよくわからない．

- `long long mod_sqrt(long long n, int mod)`
    - $r^2 \equiv n \mod mod$ を満たす $r$ を求める．$n = 0$ のときは $0$ を返す．$n$ と $mod$ が互いに素でないときと $r$ が存在しないときは$-1$ を返す．


## Modular Tetration

$a \uparrow \uparrow b \mod mod$ を再帰的に計算する．

- `long long mod_tetration(long long a, long long b, int mod)`
  - $a \uparrow \uparrow b \mod mod$ を計算する
  - 時間計算量: $O(\sqrt{mod})$

## Table of Modular Inverses

$1, 2, \dots, n$ の $\mathrm{mod}\, mod$ での逆元を計算する．

- `vector<int> mod_inv_table(int n, int mod)`
  - $1, 2, \dots, n$ の $\mathrm{mod}\,mod$ での逆元を計算する．
  - 時間計算量: $O(n)$