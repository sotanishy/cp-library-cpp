# Dynamic Segment Tree

動的セグメント木は，モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，列に対する一点更新と区間クエリを処理できるデータ構造である．

$n$ が十分小さいとき (およそ $10^6$ 以下) は，通常のセグメント木を使用する．

空間計算量: $O(m\lg n)$．$m$ は追加した要素の数である

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `DynamicSegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ の動的セグメント木を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(1)$
- `void update(int k, const T& x)`
    - $a_k$ を $x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ を計算する．$l = r$ ならば $e$ を返す．
    - 時間計算量: $O(\lg n)$