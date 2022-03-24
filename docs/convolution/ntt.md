---
title: Number Theoretic Transform
documentation_of: ../../convolution/ntt.hpp
---

## Description

数論変換 (NTT) は，有限体 $\mathbb{F}_p$ 上の高速 Fourier 変換である．

## Operations

- `void ntt(vector<mint> a, bool ordered)`
    - 数列 $a$ を数論変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\log n)$
- `void intt(vector<mint> a, bool ordered)`
    - 数列 $a$ を逆数論変換する．`ordered = false` なら並べ替えは行われない．
    - 時間計算量: $O(n\log n)$
- `vector<mint> convolution(vector<mint> a, vector<mint> b)`
    - 数列 $a$ と $b$ の畳み込みを計算する
    - 時間計算量: $O(n\log n)$

## Note

数列の長さ $n$ が $p - 1$ を割り切るとき，1の原子 $n$ 乗根が必ず存在する．$n$ の長さを2冪にするため，素数 $p$ は $a \times 2^k + 1$ の形に表したとき $k$ が十分大きいものを用いる．

以下の `p` と原子根の組み合わせがよく用いられる:
- (167772161, 3)
- (469762049, 3)
- (754974721, 11)
- (998244353, 3)
- (1224736769, 3) ($2p$ が 32-bit 符号付き整数に収まらないので，私の `Modint` では扱えない)

$k$ の値はそれぞれ，25, 26, 24, 23, 24である．