# Link/Cut Tree

Link/cut 木は，森を管理するデータ構造である．以下のクエリを処理できる:
- 辺の追加
- 辺の削除
- 根の変更
- 頂点の値の更新
- パス上の頂点の値の fold

木をパスに分解し，それぞれのパスに splay 木を用いることでこれらの操作を実現する．

空間計算量: $O(n)$

## Template parameters

- `M`
    - モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Member functions

- `void link(int u, int v)`
    - 木 $u$ と木 $v$ を連結する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void cut(int v)`
    - 木 $v$ を親から切る
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void evert(int v)`
    - $v$ を木の根にする
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void get(int v)`
    - $v$ の値を取得する
    - 時間計算量: $O(1)$
- `void set(int v, T x)`
    - 頂点 $v$ の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `T fold(int u, int v)`
    - $uv$ パス上の頂点の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$