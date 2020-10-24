# Shortest Path Algorithms

最短経路問題を解くアルゴリズム詰め合わせ

## Bellman-Ford Algorithm

Bellman-Ford のアルゴリズムは，重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．負閉路の検出にも用いられる．

- `vector<T> bellman_ford(vector<Edge<T>> G, int V, int s)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する．$G$ が負閉路を含む場合は，空のリストを返す
    - 時間計算量: $O(VE)$

## Floyd-Warshall Algorithm

Floyd-Warshall のアルゴリズムは，重み付きグラフの全点対最短経路問題を解くアルゴリズムである．負閉路検出にも用いられる．

- `void floyd_warshall(vector<vector<T>> dist)`
    - グラフ $G$ の隣接行列が与えられたとき，全頂点間の最短距離を計算する
    - 時間計算量: $O(V^3)$

## Dijkstra's Algorithm

Dijkstra のアルゴリズムは，負辺のない重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．

- `vector<T> dijkstra(vector<vector<Edge<T>>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する
    - 時間計算量: $O(E \lg V)$
