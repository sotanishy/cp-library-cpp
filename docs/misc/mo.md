---
title: Mo's Algorithm
documentation_of: ../../misc/mo.cpp
---

## Description

Mo のアルゴリズム (クエリ平方分割) は，静的な列に対するクエリをオフラインで高速に処理するアルゴリズムである．

## Operations

- `Mo(int n)`
    - 長さ $n$ の列に対するクエリを処理する
    - 時間計算量: $O(1)$
- `void query(int l, int r)`
    - 区間 $[l, r)$ に対してクエリをする
    - 時間計算量: $O(1)$
- `void run(ExL exl, ShL shl, ExR exr, ShR shr, Out out)`
    - 以下の関数を引数に取り，クエリを実行する
        - `exl`: 区間を左に1マス伸ばしたときの状態を更新する
        - `shl`: 区間を左に1マス縮めたときの状態を更新する
        - `exr`: 区間を右に1マス伸ばしたときの状態を更新する
        - `shr`: 区間を右に1マス縮めたときの状態を更新する
        - `out`: $i$ 番目のクエリの結果を計算する
    - 時間計算量: $O(f(n)n\sqrt{n})$, $f(n)$ は状態の更新にかかる計算量
