---
title: Horn-SAT
documentation_of: ../../sat/hornsat.hpp
---

## Description

2-SAT は，節内の肯定リテラル数が高々1つであるような乗法標準形の論理式に対する充足可能性問題 (SAT) である．

$(a_1 \land a_2 \land \dots \land a_n \rightarrow b)$ や $(a_1 \land a_2 \land \dots \land a_n \rightarrow \lnot b)$ といった論理式は，高々1つの肯定リテラルからなる節 (Horn 節) に変換できる．

この問題は unit-propagation によって解ける．肯定リテラルのみからなる節がない場合はすべてのリテラルを `false` にし，そのような節があればそのリテラルの値を `true` に確定し残りのリテラルについて同じ問題を解けば良い．

## Operations

- `vector<bool> horn_sat(int n_literals, vector<pair<int, vector<int>>> clauses)`
    - $n_{literals}$ リテラルを含む Horn 節のリストが与えられたとき，すべての節を充足するリテラルの真偽値の組み合わせを一つ返す．節は `{p, {n}}` の形で与え，$(p \lor \lnot n_1 \lor \dots \lor \lnot n_k)$ を追加する．肯定リテラルがない場合は `pos = -1` とする．問題が充足可能でない場合，空リストを返す．
    - 時間計算量: $O(n_{literals})$

## Reference

- [Horn-satisfiability - Wikipedia](https://en.wikipedia.org/wiki/Horn-satisfiability)
- [Horn SATのメモ - むげんのぶろぐ](https://mugen1337.hatenablog.com/entry/2021/08/22/230456)
- verify: [https://codeforces.com/gym/103202/submission/153602970](https://codeforces.com/gym/103202/submission/153602970)