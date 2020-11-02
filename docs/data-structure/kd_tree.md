# k-d Tree

k-d 木は，$k$ 次元空間の点を保持し，効率的に範囲探索を行うデータ構造である．この実装は2次元空間の長方形領域の探索を提供する．

空間計算量: $O(n)$

## Operations

- `void add_point(int id, T x, T y)`
    - ラベル `id` の点 $(x, y)$ を追加する
    - 時間計算量: $O(1)$
- `void build()`
    - k-d 木を構築する
    - 時間計算量: $O(n\lg^2 n)$
- `vector<int> search(T sx, T tx, T sy, T ty)`
    -  $(sx, sy)$ から $(tx, ty)$ までの長方形領域内の点のラベルを返す
    - 時間計算量: $O(\sqrt{N} + m)$．$m$ は領域内の点の数

## Reference

- [kd木](https://ja.wikipedia.org/wiki/Kd%E6%9C%A8)

## TODO

- $k$ 次元への拡張
- 最近傍点探索
- `insert`, `erase` の実装
- 線形中央値探索による $O(n\lg n)$ での構築