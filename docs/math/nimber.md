---
title: Nimber
documentation_of: ../../math/nimber.hpp
---

## Description

Nimber $\mathbb{F}_{2^{64}}$ を表す．

$a, b \in \mathbb{F}_{2^{64}}$ に対して，nimber addition は以下のように定義される．

$$
a \oplus b = \mathrm{mex}(\{a \oplus b' \mid b' < b\} \cup \{a' \oplus b \mid a' < a\})
$$

これは bitwise XOR で計算できる．

$a, b \in \mathbb{F}_{2^{64}}$ に対して，nimber multiplication は以下のように定義される．

$$
a \otimes b = \mathrm{mex}(\{(a \otimes b') \oplus (a' \otimes b) \oplus (a' \otimes b') \mid a' < a, b' < b\})
$$

これは以下の恒等式を用いて再帰的に計算できる．
- $n < 2^{2^k} \Rightarrow n \otimes 2^{2^k} = n \times 2^{2^k}$
- $2^{2^k} \otimes 2^{2^k} = 2^{2^k} + 2^{2^k-1}$

## Operations

- `Nimber operator+(Nimber r)`
    - $r$ との nimber addition を計算する
    - 時間計算量: $O(1)$
- `Nimber operator*(Nimber r)`
    - $r$ との nimber multiplication を計算する
    - 時間計算量: $O(1)$

その他すべて時間計算量 $O(1)$

## Reference

- [Nim product - kyopro_friends’ diary](https://kyopro-friends.hatenablog.com/entry/2020/04/07/195850)
    - Nimber multiplication の解説
- [Nimber, Nim product - cplib-cpp](https://hitonanode.github.io/cplib-cpp/number/nimber.hpp.html)
    - 実装の参考にした