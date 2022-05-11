---
title: Heavy-Light Decomposition
documentation_of: ../../tree/hld.cpp
---

## Description

HL 分解 (重軽分解) は，木をいくつかのパスに分解する手法である．分解されたパスからなる木は高さが高々 $O(\log n)$ になる．列に対するクエリを処理するデータ構造を用いて各パスを管理することにより，木上のパスクエリを高速に処理することができる．

空間計算量: $O(n)$

## Operations

`update` および `fold` の時間計算量を $f(n)$ とする

- `HLD(vector<vector<int>> G, bool edge)`
    - 木 `G` を HL 分解する．`edge == true` ならクエリは辺に対して実行される．
    - 時間計算量: $O(n)$
- `void update(int v, T x, F update)`
    - 頂点 $v$ に対して `update(x)` を実行する
    - 時間計算量: $O(f(n) \log n)$
- `void update(int u, int v, T x, F update)`
    - $uv$ パス上の頂点/辺に対して `update(x)` を実行する．
    - 時間計算量: $O(f(n) \log n)$
- `T path_fold(int u, int v, F fold)`
    - $uv$ パス上の頂点/辺に対して `fold()` を実行する．
    - 時間計算量: $O(f(n) \log n)$
- `T path_fold(int u, int v, F fold, Flip flip)`
    - $uv$ パス上の頂点/辺に対して `fold()` を実行する．値が非可換なら，左から積をとったときと右から積をとったときの値を入れ替える `flip` 関数を与える必要がある．
    - 時間計算量: $O(f(n) \log n)$
- `T subtree_fold(int v, F fold)`
    - 頂点 $v$ を根とする部分木の頂点/辺に対して `fold()` を実行する．
    - 時間計算量: $O(f(n))$
- `int lca(int u, int v)`
    - 頂点 $u$ と頂点 $v$ の最小共通祖先を返す
    - 時間計算量: $O(\log n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\log n)$

## Reference

- [Heavy-Light Decomposition](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [Heavy-light decomposition](https://cp-algorithms.com/graph/hld.html)
- [Easiest HLD with subtree queries](https://codeforces.com/blog/entry/53170)