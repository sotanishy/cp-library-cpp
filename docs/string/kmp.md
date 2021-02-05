---
title: Knuth-Morris-Pratt Algorithm
documentation_of: ../../string/kmp.cpp
---

## Description

Knuth-Morris-Pratt のアルゴリズムは，文字列中のパターンの出現位置を列挙するアルゴリズムである．

`P[:i]` の接尾辞でもある最長の proper prefix を各$i$について前計算することで， 文字の比較の回数を減らしている．

- `vector<int> kmp(string txt, string pat)`
    - `txt`中の`pat`の出現位置を列挙する
    - 時間計算量: $O(n + m)$

## Reference

- [KMP Algorithm for Pattern Searching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)