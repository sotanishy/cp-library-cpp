---
title: Auxiliary Tree
documentation_of: ../../tree/auxiliary_tree.cpp
---

## Description

Auxiliary tree は，木の頂点のある部分集合と集合内の頂点間の LCA のみを含み，頂点同士の関係を保ったままもとの木を圧縮したものである．

## Operations

- `AuxiliaryTree(vector<vector<int>> G, int root)`
    - 前計算をする
    - 時間計算量: $O(n\log n)$
- `vector<pair<int, int>> query(vector<int> vs)`
    - 頂点集合 `vs` から定まる auxiliary tree の辺を返す
    - 時間計算量: $O(k\log n)$

## Reference

- [LCAをベースに構築するAuxiliary Treeのメモ](https://smijake3.hatenablog.com/entry/2019/09/15/200200)
- verify: [https://atcoder.jp/contests/typical90/submissions/30186948]()