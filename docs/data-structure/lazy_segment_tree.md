# Segment Tree with Lazy Propagation

遅延伝搬セグメント木は，モノイド $(T, \cdot, e_M)$ の列 $(a_0, a_1, \dots, a_{n-1})$ と，作用素モノイド $(E, \circ, e_O)$ による作用 $*$ を扱うデータ構造である．区間更新と区間クエリを処理することができる．

作用 $*: T \times E \rightarrow T$ は $T$ の準自己同型である．すなわち，以下の性質が成り立つ．
- $\forall a \in T, a * e_O = a$
- $\forall a \in T, f, g \in E, a * (f \circ g) = (a * f) * g$
- $\forall a, b \in T, f \in E, (a \cdot b) * f = (a * f) \cdot (b * f)$

作用が区間の長さに比例するとき (e.g. 区間加算)，作用の分配則は成り立たないが，これはモノイドを $T \times \mathbb{N}$ に拡張して区間の長さを持たせ，適切に $*$ を定義することで対処できる．

また，作用素が単位元を持たない半群であるとき（e.g. 区間更新）は，適当な値を集合に添加してそれを単位元として扱うことができる．

一点更新・区間クエリはセグメント木を使用する．

区間更新・一点クエリは双対セグメント木を使用する．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e_M)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e_M$
        - `T op(T, T)`: 結合的な二項演算 $\cdot: T \times T \rightarrow T$
- `O`
    - 作用素モノイド $(E, \circ, e_O)$. 以下のメンバーが定義されている:
        - `T`: 集合 $E$ の型
        - `T id`: 単位元 $e_O$
        - `T op(T, T)`: 結合的な二項演算 $\circ: E \times E \rightarrow E$
- `T act(T, E)`
    - 作用 $*: T \times E \rightarrow T$.

## Constructor

- `LazySegmentTree(int n)`
    - サイズ`n`で要素がすべて単位元 $e_M$ の遅延伝搬セグメント木を構築する
    - 時間計算量: $O(n)$
- `LazySegmentTree(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の遅延伝搬セグメント木を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(\lg n)$
- `void update(int l, int r, E x)`
    - $i \in [l, r)$ について $a_i$ を $a_i \cdot x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r)`
    - $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}\$ を計算する
    - 時間計算量: $O(\lg n)$