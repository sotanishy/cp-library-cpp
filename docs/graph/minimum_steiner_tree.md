---
title: Minimum Steiner Tree
documentation_of: ../../graph/minimum_steiner_tree.hpp
---

## Description

最小 Steiner 木は，グラフ $G$ の頂点集合 $S \subset V$ を含む最小の木である．

最小 Steiner 木問題は NP 困難である．Dreyfus-Wagner のアルゴリズムを用いて $\vert S\vert$ に関する指数時間で解ける．

## Operations

- `T minimum_steiner_tree(vector<vector<Edge<T>>> G, vector<int> terminals)`
    - $G$ の `terminals` を含む最小 Steiner 木の重みを求める
    - 時間計算量: $O(n3^{k} + (n+m)2^k \log n)\,\text{where}\,k = \vert S\vert$

## Reference

- [Steiner Tree - My Algorithm](https://kopricky.github.io/code/Academic/steiner_tree.html)
- [指数時間アルゴリズム入門 - slideshare](https://www.slideshare.net/wata_orz/ss-12131479)