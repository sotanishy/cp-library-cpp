# k-d Tree

k-d 木は，$k$ 次元空間の点を保持し，効率的に範囲探索を行うデータ構造である．

この k-d 木は2次元空間の長方形領域の探索を実現する．

空間計算量: $O(n)$

## Member functions

- `void add_point(int id, T x, T y)`
    - ラベル `id` の点 $(x, y)$ を追加する
    - 時間計算量: $O(1)$
- `void build()`
    - k-d 木を構築する
    - 時間計算量: $O(n\lg^2 n)$
- `vector<int> search(T sx, T tx, T sy, T ty)`
    -  $(sx, sy)$ から $(tx, ty)$ までの長方形領域内の点のラベルを返す
    - 時間計算量: $O(\sqrt{N} + m)$．$m$ は領域内の点の数