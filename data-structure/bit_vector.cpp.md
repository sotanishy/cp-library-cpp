---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: data-structure/wavelet_matrix.cpp
    title: Wavelet Matrix
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/bit_vector.cpp\"\n#include <cstdint>\n#include\
    \ <vector>\n\nclass BitVector {\npublic:\n    BitVector() = default;\n    explicit\
    \ BitVector(const std::vector<bool>& v) {\n        int n = (v.size() + sz - 1)\
    \ / sz;\n        data.resize(n);\n        sum.resize(n + 1);\n        for (int\
    \ i = 0; i < (int) v.size(); ++i) data[i / sz] |= v[i] << (i % sz);\n        for\
    \ (int i = 0; i < n; ++i) sum[i + 1] = sum[i] + __builtin_popcount(data[i]);\n\
    \    }\n\n    bool access(int k) const {\n        return data[k / sz] >> (k %\
    \ sz) & 1;\n    }\n\n    int rank(int k, bool b) const {\n        int mask = (1\
    \ << (k % sz)) - 1;\n        int r = sum[k / sz] + __builtin_popcount(data[k /\
    \ sz] & mask);\n        return b ? r : k - r;\n    }\n\n    int select(int k,\
    \ bool b) const {\n        int lb = 0, ub = data.size();\n        while (ub -\
    \ lb > 1) {\n            int m = (lb + ub) / 2;\n            if (rank(m, b) <=\
    \ k) lb = m;\n            else ub = m;\n        }\n        return lb;\n    }\n\
    \nprivate:\n    static constexpr int sz = 32;\n\n    std::vector<uint32_t> data;\n\
    \    std::vector<int> sum;\n};\n"
  code: "#pragma once\n#include <cstdint>\n#include <vector>\n\nclass BitVector {\n\
    public:\n    BitVector() = default;\n    explicit BitVector(const std::vector<bool>&\
    \ v) {\n        int n = (v.size() + sz - 1) / sz;\n        data.resize(n);\n \
    \       sum.resize(n + 1);\n        for (int i = 0; i < (int) v.size(); ++i) data[i\
    \ / sz] |= v[i] << (i % sz);\n        for (int i = 0; i < n; ++i) sum[i + 1] =\
    \ sum[i] + __builtin_popcount(data[i]);\n    }\n\n    bool access(int k) const\
    \ {\n        return data[k / sz] >> (k % sz) & 1;\n    }\n\n    int rank(int k,\
    \ bool b) const {\n        int mask = (1 << (k % sz)) - 1;\n        int r = sum[k\
    \ / sz] + __builtin_popcount(data[k / sz] & mask);\n        return b ? r : k -\
    \ r;\n    }\n\n    int select(int k, bool b) const {\n        int lb = 0, ub =\
    \ data.size();\n        while (ub - lb > 1) {\n            int m = (lb + ub) /\
    \ 2;\n            if (rank(m, b) <= k) lb = m;\n            else ub = m;\n   \
    \     }\n        return lb;\n    }\n\nprivate:\n    static constexpr int sz =\
    \ 32;\n\n    std::vector<uint32_t> data;\n    std::vector<int> sum;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/bit_vector.cpp
  requiredBy:
  - data-structure/wavelet_matrix.cpp
  timestamp: '2021-10-30 12:57:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: data-structure/bit_vector.cpp
layout: document
title: Rank/Select Dictionary
---

## Description

完備辞書 (fully indexable dictionary)，または rank/select 辞書は，ビット列を扱うデータ構造である．`rank` 操作 ($k$ 番目までの1の個数) と `select` 操作 ($k$ 番目の1の位置) を提供する．

本来完備辞書は簡潔データ構造であるが，この実装ではコンパクト表現を採用している．競技プログラミングにおいてはコンパクト表現で十分であることと，コンパクト表現の方が実装が簡単であり，実測では高速であったことが理由である．コンパクト表現なら単純な累積和でも同じことを実現できるが，こちらの実装の方が省メモリである．


## Operations

- `BitVector(vector<bool> v)`
    - ビット列 `v` の完備辞書を構築する
    - 時間計算量: $O(n)$
- `bool access(int k)`
    - $k$ 番目の要素を取得する
    - 時間計算量: $O(1)$
- `int rank(int k)`
    - 区間 $[0, k)$ 中の1の数を返す
    - 時間計算量: $O(1)$
- `int select(int k)`
    - `rank(i) = k` となる最初の $i$ を返す
    - 時間計算量: $O(\log n)$

## Reference

- [完備辞書](https://miti-7.hatenablog.com/entry/2018/04/15/155638)
- [完備辞書（簡潔ビットベクトル）の解説](https://takeda25.hatenablog.jp/entry/20140201/1391250137)