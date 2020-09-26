# Number Theoretic Transform

数論変換 (NTT) は，剰余環 $\mathbb{Z}/p\mathbb{Z}$ 上の高速フーリエ変換である．

## Template parameters

- `mint`
    - `Modint` $mod p$
- `primitive_root`
    - $p$ の原子根

## Member functions

- `static vector<mint> convolution(vector<mint> a, vector<mint> b)`
    - `a` と `b` の畳み込みを $\mod p$ で計算する
    - 時間計算量: $O(n\lg n)$

## Note

数列の長さ $n$ が $p - 1$ を割り切るとき，1の原子 $n$ 乗根が必ず存在する．$n$ の長さを2冪にするため，素数 $p$ は $a \times 2^k + 1$ の形に表したとき $k$ が十分大きいものを用いる．

以下の `p` と `primitive_root` の組み合わせがよく用いられる:
- <167772161, 3>
- <469762049, 3>
- <754974721, 11>
- <998244353, 3>
- <1224736769, 3>

$k$ の値はそれぞれ，25, 26, 24, 23, 24である．