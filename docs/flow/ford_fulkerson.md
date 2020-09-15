# Ford-Fulkerson Algorithm

Ford-Fulkerson のアルゴリズムは，フローネットワークの最大流を求めるアルゴリズムである．残余グラフの増加パスを DFS で見つけ，そのパスにフローを流すことを繰り返す．

## Template parameters

- `T`
    - 容量の型

## Construcor

- `FordFulkerson(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$

## Member functions

- `void add_edge(int u, int v, T cap)`
    - 容量 $cap$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `T max_flow(int s, int t)`
    - 始点 $s$ から終点 $t$ への最大流を求める
    - 時間計算量: $O(Ef)$