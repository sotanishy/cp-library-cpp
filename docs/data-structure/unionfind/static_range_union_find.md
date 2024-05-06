---
title: Static Range Union Find
documentation_of: ../../../data-structure/unionfind/static_range_union_find.hpp
---

## Description

区間に対するマージクエリを静的に処理する．

空間計算量: $O(n\alpha(n) + q)$

## Operations

- `StaticRangeUnionFind(int n)`
    - サイズ`n`の union find を構築する．
    - 時間計算量: $O(n)$
- `void unite(int x, int y, int len)`
    - $[x, x+\mathrm{len})$ と $[y,y+\mathrm{len})$ が属する集合を連結する
    - 時間計算量: $O(1)$
- `vector<int> run()`
    - 各頂点が属する集合の代表元を返す
    - 時間計算量: $O(n\alpha(n) + q)$, $q$ は `unite` クエリの個数

## Note

アルゴリズムを説明する．このアルゴリズムは yosupo 氏による（参考文献参照）．

`unite` クエリを $\mathrm{len}$ の降順に処理する．クエリ $(x,y,\mathrm{len})$ に対する処理は以下のようにする．
1. $x,y$ が同じ集合に属していれば，このクエリの処理を終了する
2. $x,y$ が属する集合をマージし，新たにクエリ $(x+1,y+1,\mathrm{len}-1)$ を追加する

マージが起こる回数はたかだか $n-1$ 回である．また， $(x,y,\mathrm{len})$ の処理を行う際に， $x,y$ がすでに同じ集合に属しているならば，より $\mathrm{len}$ が大きいようなクエリで $(x+1,y+1),(x+2,y+2),\dots$ もすでに処理されているはずだから，このアルゴリズムは正しく動作する．

## Reference

- [Static Range Union Find - よすぽの日記](https://yosupo.hatenablog.com/entry/2019/11/12/001535)
- [verify: https://atcoder.jp/contests/yahoo-procon2018-final/submissions/53204551](https://atcoder.jp/contests/yahoo-procon2018-final/submissions/53204551)
