---
title: Shortest Path Algorithms
documentation_of: ../../graph/shortest_path.hpp
---

## Description

最短経路問題を解くアルゴリズム詰め合わせ

## Bellman-Ford Algorithm

Bellman-Ford のアルゴリズムは，重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．負閉路検出にも用いられる．

- `vector<T> bellman_ford(vector<tuple<int, int, T>> G, int V, int s)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する．$G$ が負閉路を含む場合は，空のリストを返す
    - 時間計算量: $O(VE)$

## Floyd-Warshall Algorithm

Floyd-Warshall のアルゴリズムは，重み付きグラフの全点対最短経路問題を解くアルゴリズムである．負閉路検出にも用いられる．

- `void floyd_warshall(vector<vector<T>> dist)`
    - グラフ $G$ の隣接行列が与えられたとき，全頂点間の最短距離を計算する
    - 時間計算量: $O(V^3)$

## Dijkstra's Algorithm

Dijkstra のアルゴリズムは，負辺のない重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．

- `vector<T> dijkstra(vector<vector<pair<int, T>>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短距離を計算する
    - 時間計算量: $O(E \log V)$
- `pair<vector<T>, vector<T>> shortest_path_tree(vector<vector<pair<int, T>>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短距離と， $s$ を根とするある最短経路木における各頂点の親を返す
    - 時間計算量: $O(E \log V)$

## Breadth-First Search

***NOT VERIFIED***

幅優先探索は，重みがすべて1のグラフの単一始点最短経路問題を解くアルゴリズムである．

- `vector<T> bfs(vector<vector<int>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短距離を計算する
    - 時間計算量: $O(V + E)$

## Dial's Algorithm

***NOT VERIFIED***

Dial のアルゴリズムは，負辺のない重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．辺の重みが整数であり，上限が小さいときに Dijkstra のアルゴリズムより高速に動作する．

- `vector<int> dial(vector<vector<pair<int, int>>> G, int s, int w)`
    - グラフ $G$ の隣接リストと辺の重みの上限 $w$ が与えられたとき，始点 $s$ から各頂点への最短距離を計算する
    - 時間計算量: $O(E + wV)$