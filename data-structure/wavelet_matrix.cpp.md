---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/bit_vector.cpp
    title: Rank/Select Dictionary
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_kth_smallest.test.cpp
    title: test/yosupo/range_kth_smallest.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/wavelet_matrix.md
    document_title: Wavelet Matrix
    links: []
  bundledCode: "#line 2 \"data-structure/wavelet_matrix.cpp\"\n#include <algorithm>\n\
    #include <unordered_map>\n#include <vector>\n#line 2 \"data-structure/bit_vector.cpp\"\
    \n#include <cstdint>\n#line 4 \"data-structure/bit_vector.cpp\"\n\n/*\n * @brief\
    \ Rank/Select Dictionary\n * @docs docs/data-structure/bit_vector.md\n */\nclass\
    \ BitVector {\npublic:\n    BitVector() = default;\n    explicit BitVector(const\
    \ std::vector<bool>& v) {\n        int n = (v.size() + sz - 1) / sz;\n       \
    \ data.resize(n);\n        sum.resize(n + 1);\n        for (int i = 0; i < (int)\
    \ v.size(); ++i) data[i / sz] |= v[i] << (i % sz);\n        for (int i = 0; i\
    \ < n; ++i) sum[i + 1] = sum[i] + __builtin_popcount(data[i]);\n    }\n\n    bool\
    \ access(int k) const {\n        return data[k / sz] >> (k % sz) & 1;\n    }\n\
    \n    int rank(int k, bool b) const {\n        int mask = (1 << (k % sz)) - 1;\n\
    \        int r = sum[k / sz] + __builtin_popcount(data[k / sz] & mask);\n    \
    \    return b ? r : k - r;\n    }\n\n    int select(int k, bool b) const {\n \
    \       int lb = 0, ub = data.size();\n        while (ub - lb > 1) {\n       \
    \     int m = (lb + ub) / 2;\n            if (rank(m, b) <= k) lb = m;\n     \
    \       else ub = m;\n        }\n        return lb;\n    }\n\nprivate:\n    static\
    \ constexpr int sz = 32;\n\n    std::vector<uint32_t> data;\n    std::vector<int>\
    \ sum;\n};\n#line 6 \"data-structure/wavelet_matrix.cpp\"\n\n/*\n * @brief Wavelet\
    \ Matrix\n * @docs docs/data-structure/wavelet_matrix.md\n */\ntemplate <typename\
    \ T>\nclass WaveletMatrix {\npublic:\n    WaveletMatrix() = default;\n    explicit\
    \ WaveletMatrix(std::vector<T> v) {\n        int n = v.size() ;\n        T m =\
    \ *std::max_element(v.begin(), v.end());\n        int d = 0;\n        while ((1\
    \ << d) <= m) ++d;\n        mat.resize(d);\n        cnt0.resize(d);\n        for\
    \ (d -= 1; d >= 0; --d) {\n            std::vector<bool> bit(n);\n           \
    \ for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;\n            mat[d] = BitVector(bit);\n\
    \            std::vector<int> cnt(2);\n            for (int i = 0; i < n; ++i)\
    \ if (!bit[i]) cnt[0]++;\n            cnt0[d] = cnt[0];\n            cnt[1] =\
    \ n;\n            std::vector<T> nv(n);\n            for (int i = n - 1; i >=\
    \ 0; --i) nv[--cnt[bit[i]]] = v[i];\n            v.swap(nv);\n        }\n    \
    \    for (int i = 0; i < n; ++i) if (!start.count(v[i])) start[v[i]] = i;\n  \
    \  }\n\n    T access(int k) const {\n        T ret = 0;\n        for (int d =\
    \ mat.size() - 1; d >= 0; --d) {\n            bool b = mat[d].access(k);\n   \
    \         ret |= T(b) << d;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n\
    \        }\n        return ret;\n    }\n\n    int rank(int k, T x) const {\n \
    \       for (int d = mat.size() - 1; d >= 0; --d) {\n            bool b = x >>\
    \ d & 1;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n      \
    \  return k - start.at(x);\n    }\n\n    int rank_less(int k, T x) const {\n \
    \       int ret = 0;\n        int l = 0;\n        for (int d = mat.size() - 1;\
    \ d >= 0; --d) {\n            bool b = x >> d & 1;\n            if (b) ret +=\
    \ mat[d].rank(k, 0) - mat[d].rank(l, 0);\n            l = cnt0[d] * b + mat[d].rank(l,\
    \ b);\n            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n        return\
    \ ret;\n    }\n\n    int select(int k, T x) const {\n        k += start.at(x);\n\
    \        for (int d = 0; d < (int) mat.size(); ++d) {\n            bool b = x\
    \ >> d & 1;\n            k = mat[d].select(k - cnt0[d] * b, b);\n        }\n \
    \       return k;\n    }\n\n    T quantile(int l, int r, int k) const {\n    \
    \    T ret = 0;\n        for (int d = (int) mat.size() - 1; d >= 0; --d) {\n \
    \           int cnt = mat[d].rank(r, 0) - mat[d].rank(l, 0);\n            bool\
    \ b = k < cnt ? 0 : 1;\n            l = cnt0[d] * b + mat[d].rank(l, b);\n   \
    \         r = cnt0[d] * b + mat[d].rank(r, b);\n            if (b) {\n       \
    \         ret |= T(1) << d;\n                k -= cnt;\n            }\n      \
    \  }\n        return ret;\n    }\n\nprivate:\n    std::vector<BitVector> mat;\n\
    \    std::vector<int> cnt0;\n    std::unordered_map<T, int> start;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <unordered_map>\n#include <vector>\n\
    #include \"bit_vector.cpp\"\n\n/*\n * @brief Wavelet Matrix\n * @docs docs/data-structure/wavelet_matrix.md\n\
    \ */\ntemplate <typename T>\nclass WaveletMatrix {\npublic:\n    WaveletMatrix()\
    \ = default;\n    explicit WaveletMatrix(std::vector<T> v) {\n        int n =\
    \ v.size() ;\n        T m = *std::max_element(v.begin(), v.end());\n        int\
    \ d = 0;\n        while ((1 << d) <= m) ++d;\n        mat.resize(d);\n       \
    \ cnt0.resize(d);\n        for (d -= 1; d >= 0; --d) {\n            std::vector<bool>\
    \ bit(n);\n            for (int i = 0; i < n; ++i) bit[i] = v[i] >> d & 1;\n \
    \           mat[d] = BitVector(bit);\n            std::vector<int> cnt(2);\n \
    \           for (int i = 0; i < n; ++i) if (!bit[i]) cnt[0]++;\n            cnt0[d]\
    \ = cnt[0];\n            cnt[1] = n;\n            std::vector<T> nv(n);\n    \
    \        for (int i = n - 1; i >= 0; --i) nv[--cnt[bit[i]]] = v[i];\n        \
    \    v.swap(nv);\n        }\n        for (int i = 0; i < n; ++i) if (!start.count(v[i]))\
    \ start[v[i]] = i;\n    }\n\n    T access(int k) const {\n        T ret = 0;\n\
    \        for (int d = mat.size() - 1; d >= 0; --d) {\n            bool b = mat[d].access(k);\n\
    \            ret |= T(b) << d;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n\
    \        }\n        return ret;\n    }\n\n    int rank(int k, T x) const {\n \
    \       for (int d = mat.size() - 1; d >= 0; --d) {\n            bool b = x >>\
    \ d & 1;\n            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n      \
    \  return k - start.at(x);\n    }\n\n    int rank_less(int k, T x) const {\n \
    \       int ret = 0;\n        int l = 0;\n        for (int d = mat.size() - 1;\
    \ d >= 0; --d) {\n            bool b = x >> d & 1;\n            if (b) ret +=\
    \ mat[d].rank(k, 0) - mat[d].rank(l, 0);\n            l = cnt0[d] * b + mat[d].rank(l,\
    \ b);\n            k = cnt0[d] * b + mat[d].rank(k, b);\n        }\n        return\
    \ ret;\n    }\n\n    int select(int k, T x) const {\n        k += start.at(x);\n\
    \        for (int d = 0; d < (int) mat.size(); ++d) {\n            bool b = x\
    \ >> d & 1;\n            k = mat[d].select(k - cnt0[d] * b, b);\n        }\n \
    \       return k;\n    }\n\n    T quantile(int l, int r, int k) const {\n    \
    \    T ret = 0;\n        for (int d = (int) mat.size() - 1; d >= 0; --d) {\n \
    \           int cnt = mat[d].rank(r, 0) - mat[d].rank(l, 0);\n            bool\
    \ b = k < cnt ? 0 : 1;\n            l = cnt0[d] * b + mat[d].rank(l, b);\n   \
    \         r = cnt0[d] * b + mat[d].rank(r, b);\n            if (b) {\n       \
    \         ret |= T(1) << d;\n                k -= cnt;\n            }\n      \
    \  }\n        return ret;\n    }\n\nprivate:\n    std::vector<BitVector> mat;\n\
    \    std::vector<int> cnt0;\n    std::unordered_map<T, int> start;\n};"
  dependsOn:
  - data-structure/bit_vector.cpp
  isVerificationFile: false
  path: data-structure/wavelet_matrix.cpp
  requiredBy: []
  timestamp: '2020-11-03 02:25:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_kth_smallest.test.cpp
documentation_of: data-structure/wavelet_matrix.cpp
layout: document
redirect_from:
- /library/data-structure/wavelet_matrix.cpp
- /library/data-structure/wavelet_matrix.cpp.html
title: Wavelet Matrix
---
## Description

ウェーブレット行列は，静的な整数列に対する様々なクエリが処理できるデータ構造である．整数列を上位ビットからソートして完備辞書を構築する．

空間計算量: $O(n \lg m)$, $m$ は数列の最大値

## Operations

- `WaveletMatrix(vector<int> v)`
    - `v` からウェーブレット行列を構築する
    - 時間計算量: $O(n \lg m)$
- `int access(int k)`
    - $k$ 番目の要素を取得する
    - 時間計算量: $O(\lg m)$
- `int rank(int k, int x)`
    - $[0, k)$ での $x$ の個数を返す
    - 時間計算量: $O(\lg m)$
- `int rank_less(int k, int x)`
    - $[0, k)$ で $x$ より小さい要素の個数を返す
    - 時間計算量: $O(\lg m)$
- `int select(int k, int x)`
    - $k$ 番目の $x$ の位置を返す
    - 時間計算量: $O(\lg n \lg m)$
- `int quantile(int l, int r, int k)`
    - $[l, r)$ で $k$ 番目に小さい値を返す
    - 時間計算量: $O(\lg m)$

## Reference

- [ウェーブレット行列(wavelet matrix)](https://miti-7.hatenablog.com/entry/2018/04/28/152259)

## TODO

- 他の処理も実装
- [これ](https://www.slideshare.net/pfi/ss-15916040) 読む
- Wavelet tree 実装
- 動的 [https://miti-7.hatenablog.com/entry/2019/02/01/143655]()