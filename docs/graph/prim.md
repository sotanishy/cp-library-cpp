# Prim's Algorithm

Prim のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `T prim(vector<vector<Edge<T>>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，最小全域木の重みを求める
    - 時間計算量: $O(E\lg V)$