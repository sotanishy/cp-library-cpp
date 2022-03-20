---
title: Enumerate Cliques
documentation_of: ../../graph/enumerate_cliques.cpp
---

## Description

クリークを全列挙する．

クリークの個数は高々 $2^{\sqrt{2E}}$ 個である．

## Operations

- `vector<vector<int>> enumerate_cliques(vector<vector<bool>> G)`
    - グラフ $G$ の隣接行列が与えられたとき， $G$ のクリークを全列挙する．
    - 時間計算量: $O(2^{\sqrt{2E}} V)$


## Reference

- [指数時間アルゴリズム入門](https://www.slideshare.net/wata_orz/ss-12131479)