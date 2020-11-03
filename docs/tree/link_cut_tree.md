## Description

Link/cut 木は，森を管理するデータ構造である．以下の機能を提供する:
- 辺の追加
- 辺の削除
- 根の変更
- 頂点の値の更新
- パス上の頂点の値 (モノイド) の総和

木をパスに分解し，それぞれのパスをスプレー木で管理することでこれらの操作を実現する．

空間計算量: $O(n)$

## Operations

- `LinkCutTree(int n)`
    - 頂点数 $n$ の森を構築する
    - 時間計算量: $O(n)$
- `void link(int u, int v)`
    - 辺 $uv$ を追加する
    - 時間計算量: $\mathrm{amortized}\ O(\lg n)$
- `void cut(int v)`
    - $v$ とその親を結ぶ辺を削除する
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

## Reference

- [プログラミングコンテストでのデータ構造 2　～動的木編～](https://www.slideshare.net/iwiwi/2-12188845)
- [Link-Cut 木](https://ei1333.hateblo.jp/entry/2018/05/29/011140)
- [Link-Cut Treeの実装メモ](https://smijake3.hatenablog.com/entry/2018/11/19/085919)
- [Link Cut Treeで部分木の情報を管理する](https://beet-aizu.hatenablog.com/entry/2019/06/08/221833)
- [A Data Structure for Dynamic Trees](https://www.cs.cmu.edu/~sleator/papers/dynamic-trees.pdf)

## TODO

- 部分木クエリ
- 遅延伝搬
- オリジナル論文読む