---
title: Transform
documentation_of: ../../math/transform.cpp
---

## Description

変換アルゴリズム詰め合わせ

## Fast Zeta/Möbius Transform

Zeta 変換 (下位集合) は，写像 $f$ から以下を満たす写像 $g$ を求める．Möbius 変換は，写像 $g$ から以下を満たす写像 $f$ を求める．

$$
g(S) = \sum_{T \subseteq S} f(T)
$$

上位集合も同様である．

以下の関数はすべて $a$ が2冪であることを必要とする．

- `void fzt(vector<T> a, bool subset)`
    - $a$ を高速 zeta 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
- `void fmt(vector<T> a, bool subset)`
    - $a$ を高速 Möbius 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$

## Divisor Fast Zeta/Möbius Transform

約数に関する zeta 変換 (下位集合) は，写像 $f$ から以下を満たす写像 $g$ を求める．Möbius 変換は，写像 $g$ から以下を満たす写像 $f$ を求める．

$$
g(n) = \sum_{m | n} f(m)
$$

上位集合も同様である．

- `void divisor_fzt(vector<T> a, bool subset)`
    - $a$ を約数に関して高速 zeta 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
- `void divisor_fmt(vector<T> a, bool subset)`
    - $a$ を約数に関して高速 Möbius 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$

## Fast Walsh-Hadamard Transform

高速 Walsh-Hadamard 変換を使うと，添え字 xor の畳み込みができる．

以下の関数はすべて $a$ が2冪であることを必要とする．

- `void fwht(vector<T> a)`
    - $a$ を高速 Walsh-Hadamard 変換する
    - 時間計算量: $n\lg n$
- `void ifwht(vector<T> a)`
    - $a$ を逆高速 Walsh-Hadamard 変換する
    - 時間計算量: $n\lg n$


## Note

| 畳み込み | 変換 | 逆変換 |
| $\max$ | zeta 変換 (累積和，下位) | Möbius 変換 (累積和，下位) |
| $\min$ | zeta 変換 (累積和，上位) | Möbius 変換 (累積和，上位) |
| $\gcd$ | zeta 変換 (約数，上位) | Möbius 変換 (約数，上位) |
| $\mathrm{lcm}$ | zeta 変換 (約数，下位) | Möbius 変換 (約数，下位) |
| $\mathrm{bitwise\ or}$ | zeta 変換 (bit，下位) | Möbius 変換 (bit，下位) |
| $\mathrm{bitwise\ and}$ | zeta 変換 (bit，下位) | Möbius 変換 (bit，下位) |
| $\mathrm{bitwise\ xor}$ | Walsh-Hadamard 変換 | 逆 Walsh-Hadamard 変換 |
| $+$ | Fourier 変換，数論変換 | 逆 Fourier 変換，逆数論変換 |



