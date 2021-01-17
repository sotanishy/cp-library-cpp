---
title: Union Find
documentation_of: ../../data-structure/unionfind/union_find.cpp
---

## Description

Union find (disjoint set union, 素集合データ構造) は，素集合を管理するデータ構造である．

空間計算量: $O(n)$

## Operations

- `UnionFind(int n)`
    - サイズ`n`の union find を構築する．
    - 時間計算量: $O(n)$
- `int find(int x)`
    - $x$ が属する木の根を返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(int x, int y)`
    - $x$ が属する集合と $y$ が属する集合を連結する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$
- `int size(int x)`
    - $x$ が属する集合の大きさを返す
    - 時間計算量: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ は逆アッカーマン関数である．

この実装では高速化に path compression と union by size を用いている．どちらか一方だと計算量は $O(\log n)$ になるが，両方使用することで $O(\alpha(n))$ になる．path compression の代わりに path splitting や path halving，union by size の代わりに union by rank といった実装手法もあり，どれも同じ計算量を実現する．

## Reference

- [Disjoint-set data structure](https://en.wikipedia.org/wiki/Disjoint-set_data_structure)
- [UnionFindTree に関する知見の諸々](https://noshi91.hatenablog.com/entry/2018/05/30/191943)
- [Union Find の計算量の話](https://qiita.com/kopricky/items/3e5847ab1451fe990367)
- [データ構造をマージする一般的なテク](https://wiki.kimiyuki.net/%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0%E3%82%92%E3%83%9E%E3%83%BC%E3%82%B8%E3%81%99%E3%82%8B%E4%B8%80%E8%88%AC%E7%9A%84%E3%81%AA%E3%83%86%E3%82%AF)
- [Disjoint Set Union](https://cp-algorithms.com/data_structures/disjoint_set_union.html#arpa)

## TODO

- 他の実装方針もみてみる
- retroactive
- 計算量の理解
- Arpa's trick
- Offline LCA

