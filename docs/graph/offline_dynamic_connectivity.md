# Offline Dynamic Connectivity

グラフに対する以下のクエリをオフラインで処理する:
- 辺の追加
- 辺の削除
- 連結成分の fold
- 頂点の値の更新

Undo 可能 union find を用いることでこれらの操作を実現する．

空間計算量: $O(n + q\lg q)$, $q$ はクエリ数

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `OfflineDynamicConnectivity(int n)`
    - グラフを頂点数 `n`で初期化する．頂点の値は単位元 $e$ で初期化される．
    - 時間計算量: $O(n)$
- `OfflineDynamicConnectivity(vector<T> v)`
    - グラフを頂点数 `n = v.size()`で初期化する．頂点の値は `v` で初期化される．
    - 時間計算量: $O(n)$

## Member functions

- `void link(int u, int v)`
    - 辺 $uv$ を追加する
    - 時間計算量: $O(\lg q)$
- `void cut(int u, int v)`
    - 辺 $uv$ を削除する
    - 時間計算量: $O(\lg q)$
- `void update(int v, T x)`
    - $a_v$ を $a_v \cdot x$ に更新する
    - 時間計算量: $O(1)$
- `void component_fold(int v)`
    - $v$ が属する連結成分の頂点の値を fold する
    - 時間計算量: $O(1)$
- `vector<T> run()`
    - クエリを実行し，`component_fold`の結果を返す
    - 時間計算量: $O(n + q\log nq)$