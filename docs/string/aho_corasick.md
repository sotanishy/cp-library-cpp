---
title: Aho-Corasick Algorithm
documentation_of: ../../string/aho_corasick.hpp
---

## Description

Aho-Corasick 法は，入力文字列に対して複数のパターンを高速にマッチするアルゴリズムである．

パターンからトライ木をもとにしてオートマトンを構築する．

## Operations (AhoCorasick)

- `void insert(string p)`
    - パターン $p$ を挿入する
    - 時間計算量: $O(\vert p\vert)$
- `void build()`
    - オートマトンを構築する
    - 時間計算量: $O(\sum \vert p\vert)$
- `int get_next(int i, char c)`
    - 状態 $i$ にいるときに文字 $c$ が出現したときの遷移先の状態を返す
- `long long count(string s)`
    - 文字列 $s$ に対する各パターンのマッチ回数の合計を返す
    - 時間計算量: $O(\vert s\vert + \sum \vert p\vert)$
- `vector<pair<int, int>> match(string s)`
    - 文字列 $s$ に対する各パターンのマッチ位置を返す
    - 時間計算量: $O(\vert s\vert + \sum \vert p\vert)$

## Operations (DynamicAhoCorasick)

- `void insert(string p)`
    - パターン $p$ を挿入する
    - 時間計算量: $\mathrm{amortized}\,O(\vert p\vert\log n)$
- `map<int, int> match(string s)`
    - 文字列 $s$ に対する各パターンのマッチ回数を返す
    - 時間計算量: $O((\vert s\vert + \sum \vert p\vert)\log n)$

## Reference

- [静的データ構造で動的に処理する (1) - えびちゃんの日記](https://rsk0315.hatenablog.com/entry/2019/06/19/124528)