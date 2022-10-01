---
title: Hungarian Algorithm
documentation_of: ../../flow/hungarian.cpp
---

## Description

ハンガリアン法は，割当問題 (2部グラフの最小重み最大マッチング) を解くアルゴリズムである．

## Operations

- `pair<T, vector<int>> hungarian(vector<vector<T>> A)`
  - 割当問題を解く．最小重みとそれを達成する割り当て方法を返す
  - 時間計算量: $O(n^3)$