---
title: Partially Persistent Union Find
documentation_of: ../../../data-structure/unionfind/partially_persistent_union_find.cpp
---

## Description

部分永続 union find は素集合森の過去の連結性に関する情報を保持する．以下の操作を提供する:
- 2つの集合を連結する
- 時刻 $t$ で2つの要素が同じ集合に属していたか判定する
- 時刻 $t$ での集合の大きさを返す

空間計算量: $O(n + q)$

## Operations

- `PartiallyPersistentUnionFind(int n)`
    - サイズ`n`の部分永続 union find を構築する．時刻の初期値は 0 である．
    - 時間計算量: $O(n)$
- `int find(int t, int x)`
    - 時刻 $t$ で $x$ が属する木の根を返す
    - 時間計算量: $O(\log n)$
- `void unite(int x, int y)`
    - 時刻を 1 増加させ，$x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $O(\log n)$
- `bool same(int t, int x, int y)`
    - 時刻 $t$ で $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $O(\log n)$
- `int size(int t, int x)`
    - 時刻 $t$ で $x$ が属する集合の大きさを返す
    - 時間計算量: $O(\log n)$

## Reference

- [部分永続Union-Find Treeについて](https://noshi91.hatenablog.com/entry/2018/02/18/161529)