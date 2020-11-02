## Description

Fenwick tree，または binary indexed tree (BIT) は，可換モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，一点更新と接頭辞和の計算を処理できるデータ構造である．

セグメント木より制約が強く，操作が限られているが，実装が簡潔で定数倍速い．浮動小数点の演算をするときは，セグメント木よりも誤差が大きくなる傾向があるので注意が必要である．

空間計算量: $O(n)$

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `FenwickTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の Fenwick tree を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T prefix_fold(int i)`
    - $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ を計算する
    - 時間計算量: $O(\lg n)$
- `void update(int i, T x)`
    - $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$
- `int lower_bound(T x)`
- `int lower_bound(T x, Compare cmp)`
    - `cmp(prefix_fold(i), x) == false` となる最初の $i$ を返す．そのような $i$ が存在しない場合は $n$ を返す．`cmp` を指定しない場合は `<` で比較される．列の単調性を仮定する．
    - 時間計算量: $O(\lg n)$

## Reference

- [Binary Indexed Tree のはなし](http://hos.ac/slides/20140319_bit.pdf)