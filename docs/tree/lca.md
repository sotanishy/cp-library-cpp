# Lowest Common Ancestor

根付き木の2頂点間の最小共通祖先を計算する．

## Constructor

- `LCA(vector<vector<int>>& G, int root)`
    - 前計算をする
    - 時間計算量: $O(n\lg n)$

## Member functions

- `int query(int u, int v)`
    - $u$ と $v$ の最小共通祖先を返す
    - 時間計算量: $O(\lg n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\lg n)$