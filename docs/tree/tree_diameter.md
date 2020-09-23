# Diameter of a Tree

DFSを用いて木の直径を求める．

## Member functions

- `static int diameter(vector<vector<int>> G)`
    - $G$ の辺の重みをすべて1として直径を求める
    - 時間計算量: $O(n)$
- `static T diameter(vector<vector<Edge<T>>> G)`
    - $G$ の直径を求める
    - 時間計算量: $O(n)$