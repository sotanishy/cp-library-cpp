# Floyd-Warshall Algorithm

Floyd-Warshall のアルゴリズムは，重み付きグラフの全点対最短経路問題を解くアルゴリズムである．負閉路検出にも用いられる．

- `void floyd_warshall(vector<vector<T>>& dist)`
    - グラフ $G$ の隣接行列が与えられたとき，全頂点間の最短距離を計算する
    - 時間計算量: $O(V^3)$