## Description

HL 分解 (重軽分解) は，木をいくつかのパスに分解する手法である．分解されたパスからなる木は高さが高々 $O(\lg n)$ になる．これにより，木上のクエリを高速に処理することができる．ここで，木に乗せられる代数的構造は可換モノイド $(T, \cdot, e)$ である．本来 HL 分解はパスクエリを処理する手法だが，部分木クエリを処理するように簡単に拡張できる．

この実装ではクエリの処理にセグメント木を用いている．よって，一点更新と区間取得が可能である．遅延伝搬セグメント木を使えば区間更新も可能である (と思う)．

空間計算量: $O(n)$

## Operations

- `HLD(vector<vector<int>> G)`
    - 木 `G` を HL 分解する．頂点の値は $e$ で初期化される．
    - 時間計算量: $O(n)$
- `HLD(vector<vector<int>> G, vector<T> val)`
    - 木 `G` を HL 分解する．頂点の値は `val` の値で初期化される．
    - 時間計算量: $O(n)$
- `T operator[](int v)`
    - 頂点 $v$ の値を返す
    - 時間計算量: $O(1)$
- `void update(int v, T x)`
    - 頂点 $v$ の値を $x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T path_fold(int u, int v)`
    - $uv$ パス上の頂点の値を fold する．
    - 時間計算量: $O(\lg^2 n)$
- `T subtree_fold(int u)`
    - $u$ を根とする部分木の頂点の値を fold する．
    - 時間計算量: $O(\lg n)$
- `int lca(int u, int v)`
    - $u$ と $v$ の最小共通祖先を返す
    - 時間計算量: $O(\lg n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\lg n)$

## Note

非可換モノイドを載せたいときは，以下のような方法が使える．
- $uv$ パス上で fold したいとする．上から下に下る分には非可換で fold できるので，$u$ と $v$ の LCA $p$ を求めて，$pu$ パスと $pv$ パスを fold する．
- $pu$ パスの結果を反転する．これは，モノイドに2方向から fold した結果を持たせておけばよい．
- $a_{up} \cdot a_p^{-1} \cdot a_{pv}$ を計算する．
以上の方法は自己流であるうえ，逆元の存在を仮定するのであまりよくない．天才をすればもっと楽にできそうである．

## Reference

- [Heavy-Light Decomposition](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [Heavy-light decomposition](https://cp-algorithms.com/graph/hld.html)
- [Easiest HLD with subtree queries](https://codeforces.com/blog/entry/53170)

## TODO

- 非可換 fold ましなやり方
- 遅延セグ木