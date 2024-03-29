---
title: Li Chao Tree
documentation_of: ../../../data-structure/cht/li_chao_tree.hpp
---

## Description

Li Chao tree は，直線及び線分の集合をセグメント木で管理し，与えられた $x$ 座標での最小値を取得するデータ構造である．

## Operations

- `LiChaoTree(vector<T> xs)`
    - クエリに用いる $x$ 座標を受け取り，Li Chao tree を構築する
    - 時間計算量: $O(n)$
- `void add_line(T a, T b)`
    - 直線 $y = ax + b$ を追加する
    - 時間計算量: $O(\log n)$
- `void add_segment(T a, T b, T xl, T xr)`
    - 線分 $y = ax + b \quad (x \in [x_l, x_r))$ を追加する
    - 時間計算量: $O(\log^2 n)$
- `T get(T x)`
    - $x$ での最小値を取得する
    - 時間計算量: $O(\log n)$

## Reference

- [Li Chao Treeのメモ](https://smijake3.hatenablog.com/entry/2018/06/16/144548)