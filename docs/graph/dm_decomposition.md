---
title: Dulmage-Mendelsohn Decomposition
documentation_of: ../../graph/dm_decomposition.cpp
---

## Description

Dulmage-Mendelsohn 分解 (DM分解) は，与えられた二部グラフの最大マッチングに関する性質による頂点の分類である．

この実装では，二部グラフ $G$ の頂点を3つの集合 $U, O, E$ に分類する．これらは pairwise disjoint である．
$G$ の任意の最大マッチングにおいて，$U$ に属する頂点は $U$ に属する頂点と，$O$ に属する頂点は $E$ に属する頂点とマッチされる．$U, O$ に属する頂点は必ずマッチされるが，$E$ に属する頂点はマッチされないことがある．

- `vector<int> dm_decomposition(vector<vector<int>> G)`
    - 二部グラフ $G$ を DM 分解する．0は$E$, 1は$O$, -1は$U$に属することを意味する
    - 時間計算量: $O(VE)$