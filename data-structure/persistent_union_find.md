# Persistent Union Find

永続 union find を使うと，union find の過去のバージョンに対して操作ができる．

空間計算量: $O(n + m \log n)$, $m$ は変更の数

## Constructor

- `PersistentUnionFind(int n)`
    - サイズ`n` の永続 union find を構築する
    - 時間計算量: $O(n \log n)$

## Member functions

- `int find(int x)`
    - $x$ が属する木の根を返す
    - 時間計算量: $O(\log^2 n)$
- `PersistentUnionFind unite(int x, int y)`
    - $x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $O(\log^2 n)$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $O(\log^2 n)$
- `int size(int x)`
    - $x$ が属する集合の大きさを返す
    - 時間計算量: $O(\log^2 n)$
