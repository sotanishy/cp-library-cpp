# Dual Segment Tree

双対セグメント木は，作用素モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，列に対する区間更新と一点クエリを処理できるデータ構造である．これは遅延伝搬セグメント木から作用素のみを取り出した構造である．

一点更新・区間クエリはセグメント木を使用する．

区間更新・区間クエリは遅延伝搬セグメント木を使用する．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `DualSegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の双対セグメント木を構築する
    - 時間計算量: $O(n)$

## Methods

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(1)$
- `void update(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$