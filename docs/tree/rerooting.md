---
title: Rerooting
documentation_of: ../../tree/rerooting.cpp
---

## Description

全方位木DP (rerooting) は，木において，各頂点を根としたときの木DPの値を求めるアルゴリズムである．

空間計算量: $O(n)$

## Template Parameters

- `M`
    - 可換モノイド
- `Cost`
    - 辺のコストの型
- `T leaf()`
    - 葉におけるDPの値
- `T apply(T a, int s, int t, Cost c)`
    - 辺 $st$ のコストが $c$ で $t$ の部分木の値が $a$ であるときに $s$ の部分木の値を求める

## Operations

- `Rerooting(int n)`
    - 頂点数 $n$ で木を初期化する
    - 時間計算量: $O(n)$
- `void add_edge(int u, int v, Cost c)`
    - 頂点 $uv$ 間にコスト $c$ の辺を張る
    - 時間計算量: $O(1)$
- `vector<T> run()`
    - 各頂点を根としたときの木DPの値を求める
    - 時間計算量: $O(n)$

## Reference

- [†全方位木DP†について](https://ei1333.hateblo.jp/entry/2017/04/10/224413)
- [【全方位木DP】明日使える便利な木構造のアルゴリズム](https://qiita.com/keymoon/items/2a52f1b0fb7ef67fb89e)