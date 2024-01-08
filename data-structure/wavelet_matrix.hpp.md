---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bit_vector.hpp
    title: Rank/Select Dictionary
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_frequency.test.cpp
    title: test/yosupo/static_range_frequency.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/wavelet_matrix.hpp\"\n#include <algorithm>\n\
    #include <unordered_map>\n#include <vector>\n\n#line 2 \"data-structure/bit_vector.hpp\"\
    \n#include <bit>\n#include <cstdint>\n#include <numeric>\n#line 6 \"data-structure/bit_vector.hpp\"\
    \n\nclass BitVector {\n   public:\n    BitVector() = default;\n    explicit BitVector(const\
    \ std::vector<bool>& v) {\n        const int n = v.size() / sz + 1;\n        data.resize(n);\n\
    \        sum.resize(n + 1);\n        for (int i = 0; i < (int)v.size(); ++i)\n\
    \            data[i / sz] |= v[i] << (i % sz);\n        for (int i = 0; i < n;\
    \ ++i)\n            sum[i + 1] = sum[i] + std::popcount(data[i]);\n    }\n\n \
    \   bool operator[](int k) const { return data[k / sz] >> (k % sz) & 1; }\n\n\
    \    int rank(int k, bool b) const {\n        int mask = (1U << (k % sz)) - 1;\n\
    \        int r = sum[k / sz] + std::popcount(data[k / sz] & mask);\n        return\
    \ b ? r : k - r;\n    }\n\n    int select(int k, bool b) const {\n        int\
    \ lb = 0, ub = data.size();\n        while (ub - lb > 1) {\n            int m\
    \ = std::midpoint(lb, ub);\n            if (rank(m, b) <= k)\n               \
    \ lb = m;\n            else\n                ub = m;\n        }\n        return\
    \ lb;\n    }\n\n   private:\n    static constexpr int sz = 32;\n\n    std::vector<uint32_t>\
    \ data;\n    std::vector<int> sum;\n};\n#line 7 \"data-structure/wavelet_matrix.hpp\"\
    \n\ntemplate <typename T, int MAX_LOG>\nclass WaveletMatrix {\n   public:\n  \
    \  WaveletMatrix() = default;\n    explicit WaveletMatrix(std::vector<T> v) :\
    \ mat(MAX_LOG), cnt0(MAX_LOG) {\n        const int n = v.size();\n        for\
    \ (int d = MAX_LOG - 1; d >= 0; --d) {\n            std::vector<bool> bit(n);\n\
    \            for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;\n           \
    \ mat[d] = BitVector(bit);\n            std::vector<int> cnt(2);\n           \
    \ for (int i = 0; i < n; ++i) {\n                if (!bit[i]) cnt[0]++;\n    \
    \        }\n            cnt0[d] = cnt[0];\n            cnt[1] = n;\n         \
    \   std::vector<T> nv(n);\n            for (int i = n - 1; i >= 0; --i) {\n  \
    \              nv[--cnt[bit[i]]] = v[i];\n            }\n            v.swap(nv);\n\
    \        }\n        for (int i = 0; i < n; ++i) {\n            if (!start.contains(v[i]))\
    \ start[v[i]] = i;\n        }\n    }\n\n    T operator[](int k) const {\n    \
    \    T ret = 0;\n        for (int d = mat.size() - 1; d >= 0; --d) {\n       \
    \     bool b = mat[d][k];\n            ret |= T(b) << d;\n            k = cnt0[d]\
    \ * b + mat[d].rank(k, b);\n        }\n        return ret;\n    }\n\n    int rank(int\
    \ k, T x) const {\n        for (int d = mat.size() - 1; d >= 0; --d) {\n     \
    \       bool b = x >> d & 1;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n\
    \        }\n        if (start.contains(x)) return k - start.at(x);\n        return\
    \ k;\n    }\n\n    int range_freq(int l, int r, T ub) const {\n        if (l >=\
    \ r) return 0;\n        int ret = 0;\n        for (int d = mat.size() - 1; d >=\
    \ 0; --d) {\n            bool b = ub >> d & 1;\n            if (b) ret += mat[d].rank(r,\
    \ 0) - mat[d].rank(l, 0);\n            l = cnt0[d] * b + mat[d].rank(l, b);\n\
    \            r = cnt0[d] * b + mat[d].rank(r, b);\n        }\n        return ret;\n\
    \    }\n\n    int range_freq(int l, int r, T lb, T ub) const {\n        if (lb\
    \ >= ub) return 0;\n        return range_freq(l, r, ub) - range_freq(l, r, lb);\n\
    \    }\n\n    int select(int k, T x) const {\n        k += start.at(x);\n    \
    \    for (int d = 0; d < (int)mat.size(); ++d) {\n            bool b = x >> d\
    \ & 1;\n            k = mat[d].select(k - cnt0[d] * b, b);\n        }\n      \
    \  return k;\n    }\n\n    T quantile(int l, int r, int k) const {\n        T\
    \ ret = 0;\n        for (int d = (int)mat.size() - 1; d >= 0; --d) {\n       \
    \     int cnt = mat[d].rank(r, 0) - mat[d].rank(l, 0);\n            bool b = k\
    \ < cnt ? 0 : 1;\n            l = cnt0[d] * b + mat[d].rank(l, b);\n         \
    \   r = cnt0[d] * b + mat[d].rank(r, b);\n            if (b) {\n             \
    \   ret |= T(1) << d;\n                k -= cnt;\n            }\n        }\n \
    \       return ret;\n    }\n\n   private:\n    std::vector<BitVector> mat;\n \
    \   std::vector<int> cnt0;\n    std::unordered_map<T, int> start;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <unordered_map>\n#include <vector>\n\
    \n#include \"bit_vector.hpp\"\n\ntemplate <typename T, int MAX_LOG>\nclass WaveletMatrix\
    \ {\n   public:\n    WaveletMatrix() = default;\n    explicit WaveletMatrix(std::vector<T>\
    \ v) : mat(MAX_LOG), cnt0(MAX_LOG) {\n        const int n = v.size();\n      \
    \  for (int d = MAX_LOG - 1; d >= 0; --d) {\n            std::vector<bool> bit(n);\n\
    \            for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;\n           \
    \ mat[d] = BitVector(bit);\n            std::vector<int> cnt(2);\n           \
    \ for (int i = 0; i < n; ++i) {\n                if (!bit[i]) cnt[0]++;\n    \
    \        }\n            cnt0[d] = cnt[0];\n            cnt[1] = n;\n         \
    \   std::vector<T> nv(n);\n            for (int i = n - 1; i >= 0; --i) {\n  \
    \              nv[--cnt[bit[i]]] = v[i];\n            }\n            v.swap(nv);\n\
    \        }\n        for (int i = 0; i < n; ++i) {\n            if (!start.contains(v[i]))\
    \ start[v[i]] = i;\n        }\n    }\n\n    T operator[](int k) const {\n    \
    \    T ret = 0;\n        for (int d = mat.size() - 1; d >= 0; --d) {\n       \
    \     bool b = mat[d][k];\n            ret |= T(b) << d;\n            k = cnt0[d]\
    \ * b + mat[d].rank(k, b);\n        }\n        return ret;\n    }\n\n    int rank(int\
    \ k, T x) const {\n        for (int d = mat.size() - 1; d >= 0; --d) {\n     \
    \       bool b = x >> d & 1;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n\
    \        }\n        if (start.contains(x)) return k - start.at(x);\n        return\
    \ k;\n    }\n\n    int range_freq(int l, int r, T ub) const {\n        if (l >=\
    \ r) return 0;\n        int ret = 0;\n        for (int d = mat.size() - 1; d >=\
    \ 0; --d) {\n            bool b = ub >> d & 1;\n            if (b) ret += mat[d].rank(r,\
    \ 0) - mat[d].rank(l, 0);\n            l = cnt0[d] * b + mat[d].rank(l, b);\n\
    \            r = cnt0[d] * b + mat[d].rank(r, b);\n        }\n        return ret;\n\
    \    }\n\n    int range_freq(int l, int r, T lb, T ub) const {\n        if (lb\
    \ >= ub) return 0;\n        return range_freq(l, r, ub) - range_freq(l, r, lb);\n\
    \    }\n\n    int select(int k, T x) const {\n        k += start.at(x);\n    \
    \    for (int d = 0; d < (int)mat.size(); ++d) {\n            bool b = x >> d\
    \ & 1;\n            k = mat[d].select(k - cnt0[d] * b, b);\n        }\n      \
    \  return k;\n    }\n\n    T quantile(int l, int r, int k) const {\n        T\
    \ ret = 0;\n        for (int d = (int)mat.size() - 1; d >= 0; --d) {\n       \
    \     int cnt = mat[d].rank(r, 0) - mat[d].rank(l, 0);\n            bool b = k\
    \ < cnt ? 0 : 1;\n            l = cnt0[d] * b + mat[d].rank(l, b);\n         \
    \   r = cnt0[d] * b + mat[d].rank(r, b);\n            if (b) {\n             \
    \   ret |= T(1) << d;\n                k -= cnt;\n            }\n        }\n \
    \       return ret;\n    }\n\n   private:\n    std::vector<BitVector> mat;\n \
    \   std::vector<int> cnt0;\n    std::unordered_map<T, int> start;\n};"
  dependsOn:
  - data-structure/bit_vector.hpp
  isVerificationFile: false
  path: data-structure/wavelet_matrix.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
  - test/yosupo/static_range_frequency.test.cpp
documentation_of: data-structure/wavelet_matrix.hpp
layout: document
title: Wavelet Matrix
---

## Description

Wavelet 行列は，静的な非負整数列に対する様々なクエリが処理できるデータ構造である．非負整数列を上位ビットからソートして完備辞書を構築する．

空間計算量: $O(n \log m)$, $m$ は数列およびクエリで与えられる非負整数の最大値

## Operations

- `WaveletMatrix(vector<T> v)`
    - `v` からウェーブレット行列を構築する
    - 時間計算量: $O(n \log m)$
- `T operator[](int k)`
    - $k$ 番目の要素を取得する
    - 時間計算量: $O(\log m)$
- `int rank(int k, T x)`
    - $[0, k)$ での $x$ の個数を返す
    - 時間計算量: $O(\log m)$
- `int range_freq(int l, int r, T ub)`
    - $[l, r)$ で値が $[0, ub)$ に含まれる要素の個数を返す
    - 時間計算量: $O(\log m)$
- `int range_freq(int l, int r, T lb, T ub)`
    - $[l, r)$ で値が $[lb, ub)$ に含まれる要素の個数を返す
    - 時間計算量: $O(\log m)$
- `int select(int k, T x)`
    - $k$ 番目の $x$ の位置を返す
    - 時間計算量: $O(\log n \log m)$
- `T quantile(int l, int r, int k)`
    - $[l, r)$ で $k$ 番目に小さい値を返す
    - 時間計算量: $O(\log m)$

## Reference

- [ウェーブレット行列(wavelet matrix)](https://miti-7.hatenablog.com/entry/2018/04/28/152259)