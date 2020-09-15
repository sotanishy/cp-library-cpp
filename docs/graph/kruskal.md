# Kruskal's Algorithm

Kruskal のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `T kruskal(vector<Edge<T>>& G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木の重みを求める
    - 時間計算量: $O(E\lg E)$