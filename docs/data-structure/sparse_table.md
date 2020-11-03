## Description

スパーステーブルは，冪等半群 $(T, \cdot)$ の静的な列の区間和を高速に計算するデータ構造である．

冪等な二項演算とは， $\forall a \in T, a \cdot a = a$ が成り立つような写像 $\cdot: T \times T \rightarrow T$ である．冪等な二項演算には，max, min, gcd, bitwise and, bitwise or などがある．

空間計算量: $O(n \lg n)$

## Operations

- `SparseTable(vector<T> v)`
    - `v`の要素からスパーステーブルを構築する
    - 時間計算量: $O(n \lg n)$
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する
    - 時間計算量: $O(1)$

## Reference

- [Sparse Table](https://cp-algorithms.com/data_structures/sparse-table.html)