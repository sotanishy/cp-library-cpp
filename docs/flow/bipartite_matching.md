# Bipartite Matching

Ford-Fulkerson のアルゴリズムを用いて二部グラフの最大マッチングを計算する．

## Constructor

- `BipartiteMatching(int n)`‘
    - 二部グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$

## Member functions

- `void add_edge(int u, int v)`
    - 辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `int bipartite_matching()`
    - 二部グラフの最大マッチングを計算する
    - 時間計算量: $O(VE)$