---
title: Knuth-Morris-Pratt Algorithm
documentation_of: ../../string/kmp.cpp
---

## Description

Knuth-Morris-Pratt のアルゴリズムは，文字列中のパターンの出現位置を列挙するアルゴリズムである．

パターンの prefix function (`P[:i]` の接尾辞でもある最長の proper prefix) を各$i$について前計算することで， 文字の比較の回数を減らしている．

## Operations

- `vector<int> prefix_function(string s)`
    - 文字列 `s` の prefix function を計算する
    - 時間計算量: $O(n)$
- `vector<int> kmp(string txt, string pat)`
    - `txt`中の`pat`の出現位置を列挙する
    - 時間計算量: $O(n + m)$
- `vector<vector<pair<int, bool>>> matching_automaton(string s)`
    - `s` のマッチングオートマトンを返す．`ret[i][c]` は，$i$ 文字マッチしているときに文字 `c` が出現したときの遷移先と，全体がマッチしたか否かを返す．
    - 時間計算量: $O(nA)$, $A$ はアルファベットサイズ

## Reference

- [KMP Algorithm for Pattern Searching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)