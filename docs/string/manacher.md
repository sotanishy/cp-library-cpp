---
title: Manacher's Algorithm
documentation_of: ../../string/manacher.cpp
---

## Description

Manacher のアルゴリズムは，文字列中の回文である部分文字列を求めるアルゴリズムである．

返り値を$A$とする．$S_i$を中心とする最大の回文の長さを$x$とすると，$A[2i] = (x + 1) / 2$．$S_iS_{i+1}$を中心とする最大の回文の長さを$x$とすると，$A[2i + 1] = x / 2$．

- `vector<int> manacher(string s)`
    - Manacher のアルゴリズムを実行する
    - 時間計算量: $O(n)$

## Reference

- [Manacher's Algorithm - Finding all sub-palindromes in O(N)](https://cp-algorithms.com/string/manacher.html)