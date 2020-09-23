# Dijkstra's Algorithm

Dijkstra のアルゴリズムは，負辺のない重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．

- `vector<T> dijkstra(vector<vector<Edge<T>>> G, int s)`
    - グラフ $G$ の隣接リストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する
    - 時間計算量: $O(E \lg V)$