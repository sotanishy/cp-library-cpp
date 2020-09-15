# Sparse Table

スパーステーブルは，冪等半群 $(T, \cdot)$ の静的な列 $(a_0, a_1, \dots, a_{n-1})$ に対する区間クエリを高速に処理するデータ構造である．

冪等な二項演算とは， $\forall a \in T, a \cdot a = a$ が成り立つような写像 $\cdot: T \times T \rightarrow T$ である．冪等な二項演算には，max, min, gcd, bitwise and, bitwise or などがある．

空間計算量: $O(n \lg n)$

## Template parameters

- `S`
    - 冪等半群 $(T, \cdot)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T op(T, T)`: 結合的かつ冪等な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `SparseTable(const vector<T>& v)`
    - `v`の要素からスパーステーブルを構築する
    - 時間計算量: $O(n \lg n)$

## Member functions

- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ を計算する．
    - 時間計算量: $O(1)$