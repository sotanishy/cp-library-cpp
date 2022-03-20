---
title: Chromatic Number
documentation_of: ../../graph/chromatic_number.cpp
---

## Description

グラフの彩色数は，グラフの隣り合う頂点の色が異なるように頂点を彩色するために必要な最小の色の数である．

## Operations

- `int chromatic_number(vector<vector<bool>> G)`
    - グラフ $G$ の隣接行列が与えられたとき，$G$ の彩色数を求める
    - 時間計算量: $O(n 2^n)$