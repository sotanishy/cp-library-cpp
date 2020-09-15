# Disjoint Sparse Table

Disjoint sparse table は，半群 $(T, \cdot)$ の静的な列 $(a_0, a_1, \dots, a_{n-1})$ に対する区間クエリを高速に処理するデータ構造である．

二項演算 $\cdot$ が冪等であるとき，スパーステーブルの方が定数倍速いと思われる．

空間計算量: $O(n \lg n)$

## Template parameters

- `S`
    - 半群 $(T, \cdot)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `DisjointSparseTable(const vector<T>& v)`
    - `v`の要素から disjoint sparse table を構築する
    - 時間計算量: $O(n \lg n)$

## Member functions

- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ を計算する
    - 時間計算量: $O(1)$