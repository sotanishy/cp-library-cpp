---
title: Z Array
documentation_of: ../../string/z_array.cpp
---

## Description

Z array は，文字列 `S` と `S[i:]` の最長共通接頭辞の長さを表す配列である．Z array を求めるアルゴリズムは Z algorithm と呼ばれる．

Z array を用いると文字列中のパターンをすべて検索することができる．文字列を `S`，パターンを `P` とし，`P$S` (`$` は `S` にも `P` にも含まれない文字) の Z array を構築すると，値が `P` の長さと一致するところで `P` が現れる．

## Operations

- `vector<int> z_array(string s)`
    - Z array を構築する
    - 時間計算量: $O(n)$

## Reference

- [Z algorithm (Linear time pattern searching Algorithm)](https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/)