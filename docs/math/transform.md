## Description

変換アルゴリズム詰め合わせ

## Fast Zeta/Möbius Transform

ゼータ変換 (下位集合) は，写像 $f$ から以下を満たす写像 $g$ を求める．メビウス変換は，写像 $g$ から以下を満たす写像 $f$ を求める．

$$
g(S) = \sum_{T \subseteq S} f(T)
$$

上位集合も同様である．

以下の関数はすべて $a$ が2冪であることを必要とする．

- `void fzt(vector<T> a, bool subset)`
    - $a$ を高速ゼータ変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
- `void fmt(vector<T> a, bool subset)`
    - $a$ を高速メビウス変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$

## Divisor Fast Zeta/Möbius Transform

約数に関するゼータ変換 (下位集合) は，写像 $f$ から以下を満たす写像 $g$ を求める．メビウス変換は，写像 $g$ から以下を満たす写像 $f$ を求める．

$$
g(n) = \sum_{m | n} f(m)
$$

上位集合も同様である．

- `void divisor_fzt(vector<T> a, bool subset)`
    - $a$ を約数に関して高速ゼータ変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
    - ***NOT VERIFIED***
- `void divisor_fmt(vector<T> a, bool subset)`
    - $a$ を約数に関して高速メビウス変換する．`subset == true`なら下位集合，`false`なら上位集合をみる
    - 時間計算量: $n\lg n$
    - ***NOT VERIFIED***

## Fast Hadamard Transform

高速アダマール変換を使うと，添え字 xor の畳み込みができる．

以下の関数はすべて $a$ が2冪であることを必要とする．

- `void fht(vector<T> a)`
    - $a$ を高速アダマール変換する
    - 時間計算量: $n\lg n$
- `void ifht(vector<T> a)`
    - $a$ を逆高速アダマール変換する．
    - 時間計算量: $n\lg n$


## Note

| 畳み込み | 変換 | 逆変換 |
| $\max$ | ゼータ変換 (累積和，下位) | メビウス変換 (累積和，下位) |
| $\min$ | ゼータ変換 (累積和，上位) | メビウス変換 (累積和，上位) |
| $\gcd$ | ゼータ変換 (約数，上位) | メビウス変換 (約数，上位) |
| $\mathrm{lcm}$ | ゼータ変換 (約数，下位) | メビウス変換 (約数，下位) |
| $\mathrm{bitwise\ or}$ | ゼータ変換 (bit，下位) | メビウス変換 (bit，下位) |
| $\mathrm{bitwise\ and}$ | ゼータ変換 (bit，下位) | メビウス変換 (bit，下位) |
| $\mathrm{bitwise\ xor}$ | アダマール変換 | 逆アダマール変換 |
| $+$ | フーリエ変換，数論変換 | 逆フーリエ変換，逆数論変換 |



