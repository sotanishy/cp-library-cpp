---
title: Link/Cut Tree
documentation_of: ../../tree/link_cut_tree.hpp
---

## Description

Link/cut tree は，森を管理するデータ構造である．以下の機能を提供する:
- 辺の追加
- 辺の削除
- 根の変更
- 頂点の値の更新
- パス上の頂点の値 (モノイド) の総和

木をパスに分解し，それぞれのパスを splay tree で管理することでこれらの操作を実現する．

空間計算量: $O(n)$

## Operations

- `LinkCutTree(int n)`
    - 頂点数 $n$ で初期化する
    - 時間計算量: $O(n)$
- `void link(int u, int v)`
    - 辺 $uv$ を追加する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void cut(int v)`
    - 頂点 $v$ とその親を結ぶ辺を削除する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void evert(int v)`
    - 頂点 $v$ を木の根にする
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `void get(int v)`
    - 頂点 $v$ の値を取得する
    - 時間計算量: $O(1)$
- `void set(int v, T x)`
    - 頂点 $v$ の値を $x$ に変更する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$
- `T fold(int u, int v)`
    - $uv$ パス上の頂点の値を fold する
    - 時間計算量: $\mathrm{amortized}\ O(\log n)$

## Reference

- [プログラミングコンテストでのデータ構造 2　～動的木編～](https://www.slideshare.net/iwiwi/2-12188845)
- [Link-Cut 木](https://ei1333.hateblo.jp/entry/2018/05/29/011140)
- [Link-Cut Treeの実装メモ](https://smijake3.hatenablog.com/entry/2018/11/19/085919)
- [Link Cut Treeで部分木の情報を管理する](https://beet-aizu.hatenablog.com/entry/2019/06/08/221833)
- [A Data Structure for Dynamic Trees](https://www.cs.cmu.edu/~sleator/papers/dynamic-trees.pdf)