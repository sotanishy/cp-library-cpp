# Segment Tree

セグメント木は，モノイド $(T, \cdot, e)$ の列 $(a_0, a_1, \dots, a_{n-1})$ を管理し，列に対する一点更新と区間クエリを処理できるデータ構造である．

区間更新・一点クエリは双対セグメント木を使用する．

区間更新・区間クエリは遅延伝搬セグメント木を使用する．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `SegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e$ のセグメント木を構築する
    - 時間計算量: $O(n)$
- `SegmentTree(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`のセグメント木を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(1)$
- `void update(int k, T x)`
    - $a_k$ を $x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ を計算する．$l = r$ ならば $e$ を返す．
    - 時間計算量: $O(\lg n)$
- `int find_first(int l, F cond)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ が条件 `cond` を満たすような最小の $r (> l)$ 返す．列の単調性を仮定する．そのような $r$ が存在しない場合は `-1` を返す．
    - 時間計算量: $O(\lg n)$
- `int find_last(int r, F cond)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ が条件 `cond` を満たすような最大の $l (< r)$ 返す．列の単調性を仮定する．そのような $l$ が存在しない場合は `-1` を返す．
    - 時間計算量: $O(\lg n)$