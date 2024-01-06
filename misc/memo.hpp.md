---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "misc/memo.hpp"


    '
  code: ''
  dependsOn: []
  isVerificationFile: false
  path: misc/memo.hpp
  requiredBy: []
  timestamp: '2022-05-06 14:57:56+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/memo.hpp
layout: document
title: Memo
---

## Description

ライブラリにするには微妙な数学の公式や定理，実装テクなどの置き場

## Number Theory

### Möbius Inversion Formula

$f$ を数論的関数 ($\mathbb{N}\rightarrow \mathbb{C}$)，$g$ を

$$
g(n) = \sum_{d|n} f(d)
$$

とすると，

$$
f(n) = \sum_{d|n}\mu(d)g\left(\frac{n}{d}\right)
$$

が成り立つ．ここで $\mu(n)$ は Möbius 関数であり，$n$ の素因数分解を $n=p_1^{e_1}p_2^{e_2}\cdots p_k^{e_k}$ とすると，

$$
\mu(n) = \begin{cases}
0 & \exists e_i \geq 2 \\
(-1)^k & \text{otherwise}
\end{cases}
$$

### Euler's Theorem

$a$ を $n$ と互いに素な正整数，$\phi$ を Euler 関数とすると，

$$
a^{\phi(n)} \equiv 1 \pmod n
$$

## Enumeration

### Cayley's Formula

$n$ 頂点のラベル付き木の個数は $n^{n-2}$．

競プロではこの公式をそのまま使うと言うよりは，その証明を応用して問題設定に応じて自分で公式を作るほうが多いと思われる．

証明は Prüfer code や double counting を用いたものなどがある．

- [ケイリーの公式の証明6種類 - ｼﾞｮｲｼﾞｮｲｼﾞｮｲ](https://joisino.hatenablog.com/entry/2017/08/20/200000)

### Matrix Tree Theorem

グラフ $G$ の全域木の個数は，$G$ の Laplacian 行列 $L$ (次数行列を $D$，隣接行列を $A$ としたとき，$L=D-A$) の任意の余因子に等しい．

- [行列木定理の証明 - blogoid](https://mizuwater0.hatenablog.com/entry/2018/11/25/233547)

### Negative Binomial Theorem

$$
\frac{1}{(1-x)^n} = \sum_{k=0}^\infty \binom{n+k-1}{k}x^k
$$

### Euler's Pentagonal Number Theorem

$$
\prod_{n=1}^\infty (1-x^n) = \sum_{n=-\infty}^\infty (-1)^n x^{n(3n-1)/2}
$$

### Burnside's Lemma

群 $G$ が集合 $X$ に作用しているとき，軌道の数 $\vert X/G\vert$ は，

$$
|X/G|=\frac{1}{|G|}\sum_{g\in G}|X^g|
$$

ここで，$X^g$ は $g\in G$ によって固定される $X$ の元の全体である．

### Twelvefold Way

| ボールの区別 | 箱の区別 | 0個以上 | 1個以上 |
| --- | --- | --- | --- |
| あり | あり | $k^n$ | $\sum_{i=0}^k(-1)^{(k-i)}\binom{k}{i}i^n$ |
| なし | あり | $\binom{n+k-1}{n}$ | $\binom{n-1}{k-1}$ |
| あり | なし | $B(n,k)$ | $S(n,k)$ |
| なし | なし | $P(n,k)$ | $P(n-k,k)$ |

### Lagrange Inversion Formula

形式的べき級数 $F(x), G(x)$ が互いに逆関数である，すなわち $G(F(x)) = x$ のとき，

$$
[x^n] G(x)=\frac{1}{n} [x^{-1}] \frac{1}{F(x)^n}
$$

例えば，$G(x) = x\phi(G(x))$ という関数方程式を満たす $G(x)$ の係数を求めたいとき，$F(x) = x/\phi(x)$ と置けば $F, G$ は互いに逆関数になる．これらに Lagrange の反転公式を適用すると，

$$
[x^n] G(x) = \frac{1}{n} [x^{n-1}] \phi(x)^n
$$

が得られる．

- [ABC222 H - Beautiful Binary Tree 解説](https://atcoder.jp/contests/abc222/editorial/2742)

### LGV Formula

LGV 公式は，DAG の非交差経路の数え上げに用いられる公式である．

- $\mathcal{N}(S,T)$: 頂点集合 $S=\{s_1,s_2,\dots,s_k\}$ から $T=\{t_1,t_2,\dots,t_k\}$ の非交差経路の数
- $M$: $k \times k$ 行列で，$M_{ij}$ は $s_i$ から $t_j$ への経路数

のもと，

$$
\det(M)=\sum_{\sigma(T)} \mathrm{sgn}(\sigma)\vert \mathcal{N}(S,\sigma(T))\vert
$$

が成り立つ．特に，$\sigma$ が恒等置換でないとき，必ず $\mathcal{N}(S,\sigma(T))=0$ となるとすると，

$$
\det(M)=\vert \mathcal{N}(S,T)\vert
$$

である．

- [離散数理工学 第 6 回 離散代数：非交差経路の数え上げ](http://dopal.cs.uec.ac.jp/okamotoy/lect/2020/dme/handout06.pdf)

## $q$-Binomial

要素数 $q$ の体上の $n$ 次元ベクトル空間の， $k$ 次元部分空間の個数は， $q$-二項係数を用いて $\binom{n}{k}_2$ と表される．

また， $k$ 次元部分空間 $V$ を一つ固定したとき， $m\,(m \geq k)$ 本のベクトルの順序組 $(v_1,v_2,\dots,v_m)$ で $\operatorname{span}\{v_1,v_2,\dots,v_m\}=V$ となるものの個数は $q^{k(k-1)/2} \frac{[m]_q!}{[m-k]_q!}$ である．

- [ABC278 Ex - make 1 解説](https://atcoder.jp/contests/abc278/editorial/5210)

## Graph

### Hall's Marriage Theorem

頂点集合 $U,V$ からなる二部グラフ $G$ において，$U$ の全頂点をカバーするマッチングが存在する必要十分条件は，任意の $A\subset U$ に対して $\vert A\vert \leq \vert N(A)\vert$ が成り立つこと．ここで $N(A)$ は $A$ の隣接頂点の集合．

### Covering/Packing-Problem Pairs

最大マッチング + 最小辺被覆 = $V$  (孤立点がない場合)

最大独立集合 + 最小頂点被覆 = $V$

### Kőnig's Theorem

二部グラフにおいて，最大マッチングと最小点カバーの大きさは等しい．

### Vizing's Theorem

任意のグラフは，最大次数を $D$ とすると，$D+1$ 色で辺彩色可能．

下界は明らかに $D$ 色なので，任意のグラフは $D$ 色または $D+1$ 色で辺彩色できることになる．二部グラフの場合はかならず $D$ 色で辺彩色可能である (Kőnig's Line Coloring Theorem)．

## Geometry

### Pick's Theorem

頂点がすべて格子点上にある多角形の面積を求める公式．内部の格子点の個数を $i$，境界上の格子点の個数を $b$ とすると，多角形の面積 $S$ は

$$
S = i+\frac{1}{2}b-1
$$

で求まる．

### Simpson's Rule

$$
\int_a^b f(x)dx \approx \frac{b-a}{6} \left( f(a) + 4f\left(\frac{a+b}{2}\right) + f(b) \right)
$$

$f(x)$ が2次以下の多項式であればこの公式は厳密な値を与える．

## Implementation

### $N$ 要素の集合の $K$ 要素の部分集合の列挙

$K=0$ のときに注意! (無限ループに陥る)

```cpp
int comb = (1 << K) - 1;
while (comb < (1 << N)) {
    // operation with comb
    // ...
    int x = comb & -comb;
    int y = comb + x;
    comb = ((comb & ~y) / x >> 1) | y;
}
```

## Others

### Dual LP

線形計画問題

$$
\begin{aligned}
\text{maximize } \quad & \boldsymbol{c}^\intercal \boldsymbol{x} \\
\text{subject to } \quad & A\boldsymbol{x}\leq \boldsymbol{b}
\end{aligned}
$$

の双対問題は

$$
\begin{aligned}
\text{minimize } \quad & \boldsymbol{y}^\intercal \boldsymbol{b} \\
\text{subject to } \quad & \boldsymbol{y}^\intercal A = \boldsymbol{c} \\
& \boldsymbol{y}^\intercal \geq \boldsymbol{0}
\end{aligned}
$$

### Matroid Intersection Duality Theorem

$$
\max \{|S| \mid S \in \mathcal{I}(M_1) \cap \mathcal{I}(M_2) \} = \min \{r_{M_1}(E_1) + r_{M_2}(E_2) \mid E_1 \cup E_2 = E \}
$$

### Euler's Polyhedron Theorem

$$
V - E + F = 2
$$