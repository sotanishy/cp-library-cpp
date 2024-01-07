---
title: Persistent Union Find
documentation_of: ../../../data-structure/unionfind/persistent_union_find.hpp
---

## Description

永続 union find は，過去のバージョンを保持する union find である．

空間計算量: $O(n + m \log n)$, $m$ は変更の数

## Operations

- `PersistentUnionFind(int n)`
    - サイズ`n` の永続 union find を構築する
    - 時間計算量: $O(n \log n)$
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

## Reference

- [A Persistent Union-Find Data Structure](https://www.lri.fr/~filliatr/ftp/publis/puf-wml07.pdf)