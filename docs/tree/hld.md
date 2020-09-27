# Heavy-Light Decomposition

HL 分解は，木をいくつかのパスに分解する手法である．分解されたパスからなる木は高さが高々 $O(\lg n)$ になる．これにより，木上のクエリを高速に処理することができる．

この実装ではクエリの処理にセグメント木を用いている．よって，一点更新と区間クエリが可能である．遅延伝搬セグメント木を使えば区間更新も可能だが面倒なので後でやる．

木に乗せられる代数的構造は可換モノイド $(T, \cdot, e)$ である．非可換にすることもできると思うが面倒なので後でやる．

空間計算量: $O(n)$

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `HLD(vector<vector<int>> G)`
    - 木 `G` を HL 分解する．頂点の値は $e$ で初期化される．
    - 時間計算量: $O(n)$
- `HLD(vector<vector<int>> G, vector<T> val)`
    - 木 `G` を HL 分解する．頂点の値は `val` の値で初期化される．
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int v)`
    - 頂点 $v$ の値を返す
    - 時間計算量: $O(1)$
- `void update(int v, T x)`
    - 頂点 $v$ の値を $x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int u, int v)`
    - $uv$ パス上の頂点の値を $\cdot$ で fold する．
    - 時間計算量: $O(\lg^2 n)$
- `int lca(int u, int v)`
    - $u$ と $v$ の最小共通祖先を返す
    - 時間計算量: $O(\lg n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\lg n)$


## Reference

- [Heavy-light decomposition](https://cp-algorithms.com/graph/hld.html)