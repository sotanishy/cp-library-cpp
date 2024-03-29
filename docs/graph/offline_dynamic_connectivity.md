---
title: Offline Dynamic Connectivity
documentation_of: ../../graph/offline_dynamic_connectivity.hpp
---

## Description

グラフに対する以下のクエリをオフラインで処理する:
- 辺の追加
- 辺の削除
- 頂点の値の更新
- 2頂点が同一の連結成分に属するかの判定
- 連結成分の fold

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
- `void cut(int u, int v)`
    - 辺 $uv$ を削除する
- `void update(int v, T x)`
    - $a_v$ を $a_v \cdot x$ に更新する
- `void same(int u, int v)`
    - 頂点 $u,v$ が同一の連結成分に属するかどうか判定する
- `void component_fold(int v)`
    - 頂点 $v$ が属する連結成分の頂点の値を fold する
- `vector<pair<bool, T>> run()`
    - クエリを実行し， `same` と `component_fold`の結果を返す． (返り値は `{same の結果, M::id()}` または `{false, component_fold の結果}` の形式)
    - 時間計算量: $O(n + q\log q\log n)$