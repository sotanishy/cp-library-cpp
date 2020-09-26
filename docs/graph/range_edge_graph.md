# Range Edge Graph

セグメント木と同様の構造を用いることで，効率的に区間に辺を張ることができる．

空間計算量: $O(n + m\lg n)$, $m$ は張った辺の数

## Template parameter

- `T`
    - 重みの型

## Constructor

- `RangeEdgeGraph(int n)`
    - グラフを $n$ 頂点で初期化する
    - 時間計算量: $O(n)$

## Member functions

- `void add_edge(int l1, int r1, int l2, int r2, T w)`
    - 区間 $[l_1, r_1)$ から区間 $[l_2, r_2)$ に重み $w$ の辺を張る
    - 時間計算量: $O(\lg n)$
- `vector<T> dijkstra(int s)`
    - 始点 $s$ から各頂点への最短距離を Dijkstra 法で求める
    - 時間計算量: $O((n + m\lg n) \lg (n + m))$

## Note

セグメント木ではなく sparse table の構造を用いて区間に辺を張ることもできる．この場合空間計算量は $O(n\lg n)$，時間計算量は構築 $O(n\lg n)$，辺の追加 $O(1)$，Dijkstra 法 $O((n\lg n + m) \lg (n\lg n + m)))$ となる．特に辺が多いときに高速であるという利点があるが，空間計算量が大きくなるので注意が必要である．

## Reference

- [区間に辺を貼る一般的なテクニック](https://www.slideshare.net/secret/r8gjH9xYxFR0Fu)
- [区間に辺を張るテクの実装例（Dijkstra法セット）と使用例](https://lorent-kyopro.hatenablog.com/entry/2020/07/24/170656)
