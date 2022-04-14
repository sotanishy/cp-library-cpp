---
title: 2-SAT
documentation_of: ../../sat/twosat.hpp
---

## Description

2-SAT は，節内のリテラル数が高々2つであるような乗法標準形の論理式に対する充足可能性問題 (SAT) である．

節 $(u \lor v)$ が $(\lnot u \rightarrow v) \land (\lnot v \rightarrow u)$ と同値であることを利用すると，2-SAT を強連結成分分解を用いて解くことができる．

## Operations

- `vector<bool> two_sat(int n, vector<tuple<int, bool, int, bool>> clauses)`
    - $n$ リテラルを含む節のリストが与えられた時，すべての節を充足するリテラルの真偽値の組み合わせを一つ返す．節は `{i, f, j, g}` の形で与え，$((x_i = f) \lor (x_j = g))$ を追加する．問題が充足可能でない場合，空リストを返す．
    - 時間計算量: $O(n)$