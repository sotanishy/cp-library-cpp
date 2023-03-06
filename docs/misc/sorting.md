---
title: Sorting Algorithms
documentation_of: ../../misc/sorting.hpp
---

## Description

いくつかのソーティングアルゴリズムの実装．主にインタラクティブ問題での使用を想定しており，時間計算量よりも比較回数を重視している．

- `void merge_sort(vector<T> arr, int l, int r, Compare cmp)`
    - リスト $\mathrm{arr}$ の区間 $[l, r)$ を比較関数 $\mathrm{cmp}$ によってマージソートする
    - 時間計算量: $O(n \log n)$
- `void merge_insertion_sort(vector<T> arr, Compare cmp)`
    - 要素に重複のないリスト $\mathrm{arr}$ を比較関数 $\mathrm{cmp}$ によってソートする
    - 時間計算量: $O(n^2 \log n)$ ($O(n (\log n)^2)$ に高速化可能)

## Note

比較ソートの最悪比較回数の情報理論的下界は $\lceil \log_2 n! \rceil \approx n\log_2 n - 1.443 n$ 回である．

マージソートの最悪比較回数は $n\log_2 n-0.915n$ から $n\log_2 n-n$ の間になることが知られている．

マージ挿入ソートの最悪比較回数は $n\log_2 n-1.415n$ 程度であることが知られている．マージ挿入ソートは，最悪比較回数が情報理論的下界に最も近いソーティングアルゴリズムの一つである．