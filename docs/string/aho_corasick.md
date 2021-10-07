---
title: Aho-Corasick Algorithm
documentation_of: ../../string/aho_corasick.cpp
---

## Description

Aho-Corasick 法は，入力文字列に対して複数のパターンを高速にマッチするアルゴリズムである．

パターンからトライ木をもとにしてオートマトンを構築する．

## Operations

- `void insert(string p, int id)`
    - パターン $p$ を挿入する
    - 時間計算量: $O(|p|)$
- `void build()`
    - オートマトンを構築する
    - 時間計算量: $O(\sum |p|)$
- `map<int, int> match(string s)`
    - 文字列 $s$ に対する各パターンのマッチ回数を返す
    - 時間計算量: $O(|s| + \sum |p|)$
