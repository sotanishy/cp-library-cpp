---
title: Offline Dynamic Connectivity
documentation_of: ../../graph/offline_dynamic_connectivity.cpp
---

## Description

グラフに対する以下のクエリをオフラインで処理する:
- 辺の追加
- 辺の削除
- 連結成分の fold
- 頂点の値の更新

Undo 可能 union find を用いることでこれらの操作を実現する．

空間計算量: $O(n + q\log q)$, $q$ はクエリ数

## Operations

- `OfflineDynamicConnectivity(int n)`
    - グラフを頂点数 `n`で初期化する．頂点の値は単位元 $e$ で初期化される．
    - 時間計算量: $O(n)$
- `OfflineDynamicConnectivity(vector<T> v)`
    - グラフを頂点数 `n = v.size()`で初期化する．頂点の値は `v` で初期化される．
    - 時間計算量: $O(n)$
- `void link(int u, int v)`
    - 辺 $uv$ を追加する
    - 時間計算量: $O(\log q)$
- `void cut(int u, int v)`
    - 辺 $uv$ を削除する
    - 時間計算量: $O(\log q)$
- `void update(int v, T x)`
    - $a_v$ を $a_v \cdot x$ に更新する
    - 時間計算量: $O(1)$
- `void component_fold(int v)`
    - 頂点 $v$ が属する連結成分の頂点の値を fold する
    - 時間計算量: $O(1)$
- `vector<T> run()`
    - クエリを実行し，`component_fold`の結果を返す
    - 時間計算量: $O(n + q\log q\log n)$