---
title: Longest Common Prefix Array
documentation_of: ../../string/lcp_array.cpp
---

## Description

高さ配列 (LCP array) は，接尾辞配列における隣同士の接尾辞で，先頭何文字が共通しているかを表す配列である．`lcp[i]` は接尾辞 `s[sa[i]..]` と接尾辞 `s[sa[i + 1]..]` の先頭で共通している文字数になる．

## Operations

- `vector<int> lcp_array(string s, SuffixArray sa)`
    - 文字列 `s` と `s` の接尾辞配列 `sa` から高さ配列を構築する
    - 時間計算量: $O(n)$