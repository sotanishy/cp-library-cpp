# Quadtree

四分木は，二次元領域を扱うデータ構造である．

この実装では，モノイドの一点更新と長方形領域取得を扱う．

一点更新は高速だが，長方形領域取得は最悪計算量が悪い．実用上は愚直よりは高速であると思われる．

空間計算量: $O(m\lg n)$, $m$ は点の数

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `Quadtree(int n)`
    - $n \times n$ の領域を扱う四分木を構築する．
    - 時間計算量: $O(\lg n)$

## Member functions

- `T get(int x, int y)`
    - 点 $(x, y)$ の値を返す
    - 時間計算量: $O(\lg n)$
- `void update(int x, int y, T val)`
    - 点 $(x, y)$ の値を `val` に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int l, int r, int b, int t)`
    - 領域 ${(x, y) | x \in [l, r),\ y \in [b, t)}$ 内の点を fold した値を返す
    - 時間計算量: $O(m\lg n)$