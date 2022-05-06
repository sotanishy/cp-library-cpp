---
title: Delaunay Diagram
documentation_of: ../../geometry/delaunay_diagram.hpp
---

## Description

与えられた点の Delaunay 図は，Voronoi 図の双対であり，Voronoi 領域の隣接関係を表す．

Voronoi 図とは，平面に配置された母点に対して，平面の各点がどの母点に最も近いかによって領域分けされた図である．

Delaunay 辺の本数は Euler の多面体定理より $O(n)$ 本である．また，Euclidean MST は Delaunay 図の部分グラフである．

Delaunay 図は平面走査アルゴリズムである Fortune のアルゴリズムで求めることができる．

## Operations

- `vector<pair<int, int>> delaunay_diagram(vector<Vec> pts)`
    - `pts` から定まる Delaunay 図の辺を返す
    - 時間計算量: $O(n\log n)$

## Reference

- [[Tutorial] Voronoi Diagram and Delaunay Triangulation in O(n log n) with Fortune's Algorithm - Codeforces](https://codeforces.com/blog/entry/85638?f0a28=1)
- [ユークリッド最小全域木 - SlideShare](https://www.slideshare.net/maroonrk/ss-65378126)
- verify: [https://atcoder.jp/contests/abc181/submissions/31463286](https://atcoder.jp/contests/abc181/submissions/31463286)
