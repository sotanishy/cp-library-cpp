---
title: Suffix Array
documentation_of: ../../string/suffix_array.hpp
---

## Description

接尾辞配列 (suffix array) は，文字列のインデックスを接尾辞の辞書順に並べたものである．文字列検索が効率的に行える．

この実装では Manber-Myers のアルゴリズムを用いている．ソートに基数ソートを用いることで時間計算量を $O(n\log^2 n)$ から $O(n\log n)$ に改善している．

なお，SA-IS という $O(n)$ のアルゴリズムもある (未実装)．

## Operations

- `vector<int> suffix_array(string s)`
    - `s` の接尾辞配列を構築する
    - 時間計算量: $O(n\log n)$

## Reference

- [Suffix Array](https://cp-algorithms.com/string/suffix-array.html)