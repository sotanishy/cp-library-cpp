---
title: Palindromic Tree
documentation_of: ../../string/palindromic_tree.hpp
---

## Description

Palindromic Tree は，文字列の回文の情報を保持するデータ構造である．

## Operations

- `void add(char c)`
    - 文字 $c$ を現在の文字列の末尾に追加する
    - 時間計算量: $\mathrm{amortized}\ O(1)$
- `vector<int> get_suffix_palindromes()`
    - 現在の文字列の suffix である回文の長さを列挙する
    - 時間計算量: $O(k)$, $k$ は回文の個数
- `vector<tuple<int, int, int>> get_palindrome_frequencies()`
    - 文字列の相異なる回文部分文字列の位置と長さと個数を列挙する．破壊的．
    - 時間計算量: $O(n)$

## Reference

- [Palindromic Tree - slideshare](https://www.slideshare.net/__math/palindromic-tree)


