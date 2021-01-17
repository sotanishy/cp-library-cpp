---
title: 2-SAT
documentation_of: ../../graph/twosat.cpp
---

## Description

2-SAT は，節内のリテラル数が高々2つであるような乗法標準形の論理式に対する充足可能性問題 (SAT) である．

節 $(u \lor v)$ が $(\lnot u \implies v) \land (\lnot v \implies u)$ と同値であることを利用すると，2-SAT を強連結成分分解を用いて解くことができる．

空間計算量: $O(n + m)$．$n$ は変の数，$m$ は節の数

## Operations

- `TwoSat(int n)`
    - $n$ 変数で初期化する
    - 時間計算量: $O(n)$
- `void add_clause(int u, bool a, int v, bool b)`
    - 節 $(u \lor v)$ を追加する．`a == false` ならば，$u$ を $\lnot u$ で置き換える．同様に`b == false` ならば，$v$ を $\lnot v$ で置き換える
    - 時間計算量: $O(1)$
- `void solve()`
    - 問題を解く
    - 時間計算量: $O(n + m)$
- `bool is_satisfiable()`
    - 問題が充足可能かどうか返す
    - 時間計算量: $O(1)$
- `bool operator[](int i)`
    - 充足可能ならば，$i$ 番目の変数の真偽値を返す
    - 時間計算量: $O(1)$