---
title: 2D Pattern Search (Baker-Bird Algorithm)
documentation_of: ../../string/pattern_search_2d.hpp
---

## Description

2次元のテキストから長方形のパターンを探索する．

## Operations

- `vector<pair<int, int>> pattern_search_2d(vector<string> txt, vector<string> pat)`
    - `txt` 中の `pat` の出現位置 (左上) を列挙する
    - 時間計算量: $O(HW + RC)$, $H \times W$ は `txt` のサイズ，$R \times C$ は `pat` のサイズ

## Reference

- [Aho-Corasick で 2 次元パターンマッチング - tobya's blog](https://tobya.hatenablog.com/entry/2017/12/20/223629)
