## Description

HL 分解 (重軽分解) は，木をいくつかのパスに分解する手法である．分解されたパスからなる木は高さが高々 $O(\lg n)$ になる．これにより，木上のクエリを高速に処理することができる．木に乗せられる代数的構造は可換モノイド $(T, \cdot, e)$ である．

空間計算量: $O(n)$

## Operations

- `HLD(vector<vector<int>> G, bool edge)`
    - 木 `G` を HL 分解する．`edge == true` ならクエリは辺に対して実行される．
    - 時間計算量: $O(n)$
- `void update(int v, T x, F update)`
    - 頂点 $v$ に対して $update(x)$ を実行する
    - 時間計算量: $O(f(n) \lg n)$
- `void update(int u, int v, T x, F update)`
    - $uv$ パス上の頂点/辺に対して $update(x)$ を実行する．
    - 時間計算量: $O(f(n) \lg n)$
- `T path_fold(int u, int v, F fold)`
    - $uv$ パス上の頂点/辺に対して $fold()$ を実行する．
    - 時間計算量: $O(f(n) \lg n)$
- `T subtree_fold(int v, F fold)`
    - $v$ を根とする部分木の頂点/辺に対して $fold()$ を実行する．
    - 時間計算量: $O(f(n))$
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