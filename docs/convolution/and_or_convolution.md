---
title: Bitwise AND/OR Convolution (Subset/Superset Fast Zeta/Möbius Transform)
documentation_of: ../../convolution/and_or_convolution.hpp
---

## Description

下位集合に関する Zeta 変換は，写像 $f$ が与えられたとき，以下を満たす写像 $g$ を得る変換である．Möbius 変換は，zeta 変換の逆変換である (つまり，写像 $g$ が与えられたとき，以下を満たす写像 $f$ を得る変換である)．

$$
g(S) = \sum_{T \subseteq S} f(T)
$$

上位集合に関するものも同様である．

下位集合に関する FZT/FMT を用いると，bitwise OR convolution が高速に計算できる．

$$
c_k = \sum_{i\lor j=k} a_i b_j
$$

上位集合に関する FZT/FMT を用いると，bitwise AND convolution が高速に計算できる．

$$
c_k = \sum_{i\land j=k} a_i b_j
$$


## Operations

- `void fzt(vector<T> a, bool subset)`
    - 数列 $a$ を高速 zeta 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる．$a$ の長さが2冪であることを要求する．
    - 時間計算量: $O(n\log n)$
- `void fmt(vector<T> a, bool subset)`
    - 数列 $a$ を高速 Möbius 変換する．`subset == true`なら下位集合，`false`なら上位集合をみる．$a$ の長さが2冪であることを要求する．
    - 時間計算量: $O(n\log n)$
- `vector<T> and_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の bitwise AND convolution を計算する
    - 時間計算量: $O(n\log n)$
- `vector<T> or_convolution(vector<T> a, vector<T> b)`
    - 数列 $a$ と $b$ の bitwise OR convolution を計算する
    - 時間計算量: $O(n\log n)$

## Note

| 畳み込み | 変換 | 逆変換 |
| $\max$ | zeta 変換 (累積和，下位) | Möbius 変換 (累積和，下位) |
| $\min$ | zeta 変換 (累積和，上位) | Möbius 変換 (累積和，上位) |
| $\gcd$ | zeta 変換 (約数，上位) | Möbius 変換 (約数，上位) |
| $\mathrm{lcm}$ | zeta 変換 (約数，下位) | Möbius 変換 (約数，下位) |
| $\mathrm{bitwise\ and}$ | zeta 変換 (bit，上位) | Möbius 変換 (bit，上位) |
| $\mathrm{bitwise\ or}$ | zeta 変換 (bit，下位) | Möbius 変換 (bit，下位) |
| $\mathrm{bitwise\ xor}$ | Walsh-Hadamard 変換 | 逆 Walsh-Hadamard 変換 |
| $+$ | Fourier 変換，数論変換 | 逆 Fourier 変換，逆数論変換 |

## Reference

- [ゼータ変換・メビウス変換を理解する - Qiita](https://qiita.com/convexineq/items/afc84dfb9ee4ec4a67d5)
    - これを読むと，zeta/Möbius 変換が絡む一連の畳み込み操作に関して完全に理解した気持ちになれる．