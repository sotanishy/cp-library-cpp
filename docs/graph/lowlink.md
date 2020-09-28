# Lowlink

Lowlink はグラフの橋や間接点などを求める際に有効な概念である．グラフの DFS tree において，頂点 $v$ の訪問時刻を `ord[v]` としたとき，$v$ から後退辺 (DFS tree に含まれない辺) を高々1回用いて到達することができる頂点の `ord` の最小値 `low[v]` を lowlink という．

辺 $(u, v)$ が橋であるとき，`ord[u] < low[v]` が成り立つ．

頂点 $v$ が間接点であるとき，$v$ が DFS tree の根なら $v$ は2つ以上の子を持ち，そうでないなら $v$ ある子 $c$ について `ord[v] <= low[v]` が成り立つ．

空間計算量: $O(V + E)$

## Constructor

- `Lowlink(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ の橋と間接点を求める
    - 時間計算量: $O(V + E)$
- `vector<pair<int, int>> get_bridges()`
    - $G$ の橋を返す
- `vector<int> get_articulation_points()`
    - $G$ の間接点を返す

## Reference

- [橋と関節点, lowlink](https://kagamiz.hatenablog.com/entry/2013/10/05/005213)