---
title: Partition Refinement
documentation_of: ../../data-structure/partition_refinement.hpp
---

## Description

Partition refinement は，素集合を管理するデータ構造である．Union find が集合の併合を処理するのに対し，partition refinement は集合の分割を処理する．

DFA 最小化などに用いられる．

空間計算量: $O(n)$

## Operations

- `PartitionRefinement(int n)`
    - 集合を $\{0,1,\dots, n-1\}$ で初期化する．
    - 時間計算量: $O(n)$
- `int find(int x)`
    - $x$ が属する集合の番号を返す
    - 時間計算量: $O(1)$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $O(1)$
- `int size(int i)`
    - 集合 $i$ の要素数を返す
    - 時間計算量: $O(1)$
- `vector<int> members(int i)`
    - 集合 $i$ の要素のリストを返す
    - 時間計算量: $O(\vert S_i \vert)$
- `vector<pair<int, int>> refine(vector<int> pivot)`
    - 与えられたピボット $P$ を用いて，各集合 $S_i$ を $S_i \cap P$ と $S_i - P$ に分割する．
    - 分割された集合の番号を返す
    - 時間計算量: $O(\vert P \vert \log n)$

## Note

Refine 操作は $O(\vert P \vert)$ でできるが，実装が面倒なので log をつけている．

DFA 最小化では，集合が分割されたときに要素数が小さい方に注目して，それに遷移してくる集合をさらに分割するということを繰り返す．計算量は，逆マージテクの要領で解析でき，遷移の数を $m$ として $O(m \log^2 n)$ (refine 操作を線形時間で行えば $O(m \log n)$) となる．

## Reference

- [Partition refinement - TryAlgo](https://tryalgo.org/en/data%20structures/2016/09/16/partition-refinement/)
- [DFA minimization - Wikpedia](https://tryalgo.org/en/data%20structures/2016/09/16/partition-refinement/)
- verify: [https://atcoder.jp/contests/tupc2022/submissions/39481650](https://atcoder.jp/contests/tupc2022/submissions/39481650)