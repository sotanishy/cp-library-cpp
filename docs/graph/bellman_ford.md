# Bellman-Ford Algorithm

Bellman-Ford のアルゴリズムは，重み付きグラフの単一始点最短経路問題を解くアルゴリズムである．負閉路の検出にも用いられる．

- `vector<T> bellman_ford(vector<Edge<T>>& G, int V, int s)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，始点 $s$ から各頂点への最短経路を計算する．$G$ が負閉路を含む場合は，空のリストを返す
    - 時間計算量: $O(VE)$