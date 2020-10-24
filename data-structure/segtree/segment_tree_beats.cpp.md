---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
    title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/segtree/segment_tree_beats.md
    document_title: Segment Tree Beats
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/segment_tree_beats.cpp\"\n#include\
    \ <algorithm>\n#include <limits>\n#include <vector>\n\n/*\n * @brief Segment Tree\
    \ Beats\n * @docs docs/data-structure/segtree/segment_tree_beats.md\n */\ntemplate\
    \ <typename T>\nclass SegmentTreeBeats {\npublic:\n    SegmentTreeBeats() = default;\n\
    \    explicit SegmentTreeBeats(int n) : SegmentTreeBeats(std::vector<T>(n)) {}\n\
    \    explicit SegmentTreeBeats(const std::vector<T>& v) {\n        size = 1;\n\
    \        while (size < (int) v.size()) size <<= 1;\n        sum.resize(2 * size);\n\
    \        lazy.resize(2 * size);\n        max_val.resize(2 * size, NINF);\n   \
    \     smax_val.resize(2 * size, NINF);\n        max_cnt.resize(2 * size);\n  \
    \      min_val.resize(2 * size, INF);\n        smin_val.resize(2 * size, INF);\n\
    \        min_cnt.resize(2 * size);\n        len.resize(2 * size);\n        len[1]\
    \ = size;\n        for (int i = 2; i < 2 * size; ++i) len[i] = len[i / 2] >> 1;\n\
    \        for (int i = 0; i < (int) v.size(); ++i) {\n            sum[size + i]\
    \ = max_val[size + i] = min_val[size + i] = v[i];\n            max_cnt[size +\
    \ i] = min_cnt[size + i] = 1;\n        }\n        for (int i = size - 1; i > 0;\
    \ --i) recalc(i);\n    }\n\n    T operator[](int k) {\n        return fold_sum(k,\
    \ k + 1);\n    }\n\n    void chmin(int l, int r, T x) { update<CHMIN>(l, r, x,\
    \ 1, 0, size); }\n    void chmax(int l, int r, T x) { update<CHMAX>(l, r, x, 1,\
    \ 0, size); }\n    void add(int l, int r, T x) { update<ADD>(l, r, x, 1, 0, size);\
    \ }\n\n    T fold_min(int l, int r) { return fold<MIN>(l, r, 1, 0, size); }\n\
    \    T fold_max(int l, int r) { return fold<MAX>(l, r, 1, 0, size); }\n    T fold_sum(int\
    \ l, int r) { return fold<SUM>(l, r, 1, 0, size); }\n\nprivate:\n    enum OpType\
    \ {\n        CHMIN, CHMAX, ADD\n    };\n\n    enum QueryType {\n        MIN, MAX,\
    \ SUM\n    };\n\n    static constexpr T INF = std::numeric_limits<T>::max();\n\
    \    static constexpr T NINF = std::numeric_limits<T>::min();\n\n    int size;\n\
    \    std::vector<T> sum, lazy;\n    std::vector<T> max_val, smax_val;\n    std::vector<T>\
    \ min_val, smin_val;\n    std::vector<int> len, max_cnt, min_cnt;\n\n    void\
    \ recalc(int k) {\n        sum[k] = sum[2 * k] + sum[2 * k + 1];\n\n        if\
    \ (max_val[2 * k] > max_val[2 * k + 1]) {\n            max_val[k] = max_val[2\
    \ * k];\n            max_cnt[k] = max_cnt[2 * k];\n            smax_val[k] = std::max(smax_val[2\
    \ * k], max_val[2 * k + 1]);\n        } else if (max_val[2 * k] < max_val[2 *\
    \ k + 1]) {\n            max_val[k] = max_val[2 * k + 1];\n            max_cnt[k]\
    \ = max_cnt[2 * k + 1];\n            smax_val[k] = std::max(max_val[2 * k], smax_val[2\
    \ * k + 1]);\n        } else {\n            max_val[k] = max_val[2 * k];\n   \
    \         max_cnt[k] = max_cnt[2 * k] + max_cnt[2 * k + 1];\n            smax_val[k]\
    \ = std::max(smax_val[2 * k], smax_val[2 * k + 1]);\n        }\n\n        if (min_val[2\
    \ * k] < min_val[2 * k + 1]) {\n            min_val[k] = min_val[2 * k];\n   \
    \         min_cnt[k] = min_cnt[2 * k];\n            smin_val[k] = std::min(smin_val[2\
    \ * k], min_val[2 * k + 1]);\n        } else if (min_val[2 * k] > min_val[2 *\
    \ k + 1]) {\n            min_val[k] = min_val[2 * k + 1];\n            min_cnt[k]\
    \ = min_cnt[2 * k + 1];\n            smin_val[k] = std::min(min_val[2 * k], smin_val[2\
    \ * k + 1]);\n        } else {\n            min_val[k] = min_val[2 * k];\n   \
    \         min_cnt[k] = min_cnt[2 * k] + min_cnt[2 * k + 1];\n            smin_val[k]\
    \ = std::min(smin_val[2 * k], smin_val[2 * k + 1]);\n        }\n    }\n\n    template\
    \ <OpType TYPE>\n    void tag(int k, T x) {\n        if (TYPE == CHMIN) {\n  \
    \          sum[k] += (x - max_val[k]) * max_cnt[k];\n            if (max_val[k]\
    \ == min_val[k]) min_val[k] = x;\n            else if (max_val[k] == smin_val[k])\
    \ smin_val[k] = x;\n            max_val[k] = x;\n        } else if (TYPE == CHMAX)\
    \ {\n            sum[k] += (x - min_val[k]) * min_cnt[k];\n            if (min_val[k]\
    \ == max_val[k]) max_val[k] = x;\n            else if (min_val[k] == smax_val[k])\
    \ smax_val[k] = x;\n            min_val[k] = x;\n        } else if (TYPE == ADD)\
    \ {\n            min_val[k] += x;\n            if (smin_val[k] != INF) smin_val[k]\
    \ += x;\n            max_val[k] += x;\n            if (smax_val[k] != NINF) smax_val[k]\
    \ += x;\n            sum[k] += x * len[k];\n            lazy[k] += x;\n      \
    \  }\n    }\n\n    void push(int k) {\n        if (lazy[k] != 0) {\n         \
    \   tag<ADD>(2 * k, lazy[k]);\n            tag<ADD>(2 * k + 1, lazy[k]);\n   \
    \         lazy[k] = 0;\n        }\n        if (max_val[k] < max_val[2 * k]) tag<CHMIN>(2\
    \ * k, max_val[k]);\n        if (min_val[k] > min_val[2 * k]) tag<CHMAX>(2 * k,\
    \ min_val[k]);\n        if (max_val[k] < max_val[2 * k + 1]) tag<CHMIN>(2 * k\
    \ + 1, max_val[k]);\n        if (min_val[k] > min_val[2 * k + 1]) tag<CHMAX>(2\
    \ * k + 1, min_val[k]);\n    }\n\n    template <OpType TYPE>\n    inline bool\
    \ break_cond(int k, T x) {\n        if (TYPE == CHMIN) return max_val[k] <= x;\n\
    \        if (TYPE == CHMAX) return min_val[k] >= x;\n        if (TYPE == ADD)\
    \ return false;\n    }\n\n    template <OpType TYPE>\n    inline bool tag_cond(int\
    \ k, T x) {\n        if (TYPE == CHMIN) return smax_val[k] < x;\n        if (TYPE\
    \ == CHMAX) return smin_val[k] > x;\n        if (TYPE == ADD) return true;\n \
    \   }\n\n    template <OpType TYPE>\n    void update(int a, int b, T x, int k,\
    \ int l, int r) {\n        if (r <= a || b <= l || break_cond<TYPE>(k, x)) return;\n\
    \        if (a <= l && r <= b && tag_cond<TYPE>(k, x)) {\n            tag<TYPE>(k,\
    \ x);\n            return;\n        }\n        push(k);\n        int m = (l +\
    \ r) / 2;\n        update<TYPE>(a, b, x, 2 * k, l, m);\n        update<TYPE>(a,\
    \ b, x, 2 * k + 1, m, r);\n        recalc(k);\n    }\n\n    template <QueryType\
    \ TYPE>\n    T fold(int a, int b, int k, int l, int r) {\n        if (r <= a ||\
    \ b <= l) {\n            if (TYPE == MIN) return INF;\n            if (TYPE ==\
    \ MAX) return NINF;\n            if (TYPE == SUM) return 0;\n        }\n     \
    \   if (a <= l && r <= b) {\n            if (TYPE == MIN) return min_val[k];\n\
    \            if (TYPE == MAX) return max_val[k];\n            if (TYPE == SUM)\
    \ return sum[k];\n        }\n        push(k);\n        int m = (l + r) / 2;\n\
    \        T vl = fold<TYPE>(a, b, 2 * k, l, m);\n        T vr = fold<TYPE>(a, b,\
    \ 2 * k + 1, m, r);\n        if (TYPE == MIN) return std::min(vl, vr);\n     \
    \   if (TYPE == MAX) return std::max(vl, vr);\n        if (TYPE == SUM) return\
    \ vl + vr;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <vector>\n\
    \n/*\n * @brief Segment Tree Beats\n * @docs docs/data-structure/segtree/segment_tree_beats.md\n\
    \ */\ntemplate <typename T>\nclass SegmentTreeBeats {\npublic:\n    SegmentTreeBeats()\
    \ = default;\n    explicit SegmentTreeBeats(int n) : SegmentTreeBeats(std::vector<T>(n))\
    \ {}\n    explicit SegmentTreeBeats(const std::vector<T>& v) {\n        size =\
    \ 1;\n        while (size < (int) v.size()) size <<= 1;\n        sum.resize(2\
    \ * size);\n        lazy.resize(2 * size);\n        max_val.resize(2 * size, NINF);\n\
    \        smax_val.resize(2 * size, NINF);\n        max_cnt.resize(2 * size);\n\
    \        min_val.resize(2 * size, INF);\n        smin_val.resize(2 * size, INF);\n\
    \        min_cnt.resize(2 * size);\n        len.resize(2 * size);\n        len[1]\
    \ = size;\n        for (int i = 2; i < 2 * size; ++i) len[i] = len[i / 2] >> 1;\n\
    \        for (int i = 0; i < (int) v.size(); ++i) {\n            sum[size + i]\
    \ = max_val[size + i] = min_val[size + i] = v[i];\n            max_cnt[size +\
    \ i] = min_cnt[size + i] = 1;\n        }\n        for (int i = size - 1; i > 0;\
    \ --i) recalc(i);\n    }\n\n    T operator[](int k) {\n        return fold_sum(k,\
    \ k + 1);\n    }\n\n    void chmin(int l, int r, T x) { update<CHMIN>(l, r, x,\
    \ 1, 0, size); }\n    void chmax(int l, int r, T x) { update<CHMAX>(l, r, x, 1,\
    \ 0, size); }\n    void add(int l, int r, T x) { update<ADD>(l, r, x, 1, 0, size);\
    \ }\n\n    T fold_min(int l, int r) { return fold<MIN>(l, r, 1, 0, size); }\n\
    \    T fold_max(int l, int r) { return fold<MAX>(l, r, 1, 0, size); }\n    T fold_sum(int\
    \ l, int r) { return fold<SUM>(l, r, 1, 0, size); }\n\nprivate:\n    enum OpType\
    \ {\n        CHMIN, CHMAX, ADD\n    };\n\n    enum QueryType {\n        MIN, MAX,\
    \ SUM\n    };\n\n    static constexpr T INF = std::numeric_limits<T>::max();\n\
    \    static constexpr T NINF = std::numeric_limits<T>::min();\n\n    int size;\n\
    \    std::vector<T> sum, lazy;\n    std::vector<T> max_val, smax_val;\n    std::vector<T>\
    \ min_val, smin_val;\n    std::vector<int> len, max_cnt, min_cnt;\n\n    void\
    \ recalc(int k) {\n        sum[k] = sum[2 * k] + sum[2 * k + 1];\n\n        if\
    \ (max_val[2 * k] > max_val[2 * k + 1]) {\n            max_val[k] = max_val[2\
    \ * k];\n            max_cnt[k] = max_cnt[2 * k];\n            smax_val[k] = std::max(smax_val[2\
    \ * k], max_val[2 * k + 1]);\n        } else if (max_val[2 * k] < max_val[2 *\
    \ k + 1]) {\n            max_val[k] = max_val[2 * k + 1];\n            max_cnt[k]\
    \ = max_cnt[2 * k + 1];\n            smax_val[k] = std::max(max_val[2 * k], smax_val[2\
    \ * k + 1]);\n        } else {\n            max_val[k] = max_val[2 * k];\n   \
    \         max_cnt[k] = max_cnt[2 * k] + max_cnt[2 * k + 1];\n            smax_val[k]\
    \ = std::max(smax_val[2 * k], smax_val[2 * k + 1]);\n        }\n\n        if (min_val[2\
    \ * k] < min_val[2 * k + 1]) {\n            min_val[k] = min_val[2 * k];\n   \
    \         min_cnt[k] = min_cnt[2 * k];\n            smin_val[k] = std::min(smin_val[2\
    \ * k], min_val[2 * k + 1]);\n        } else if (min_val[2 * k] > min_val[2 *\
    \ k + 1]) {\n            min_val[k] = min_val[2 * k + 1];\n            min_cnt[k]\
    \ = min_cnt[2 * k + 1];\n            smin_val[k] = std::min(min_val[2 * k], smin_val[2\
    \ * k + 1]);\n        } else {\n            min_val[k] = min_val[2 * k];\n   \
    \         min_cnt[k] = min_cnt[2 * k] + min_cnt[2 * k + 1];\n            smin_val[k]\
    \ = std::min(smin_val[2 * k], smin_val[2 * k + 1]);\n        }\n    }\n\n    template\
    \ <OpType TYPE>\n    void tag(int k, T x) {\n        if (TYPE == CHMIN) {\n  \
    \          sum[k] += (x - max_val[k]) * max_cnt[k];\n            if (max_val[k]\
    \ == min_val[k]) min_val[k] = x;\n            else if (max_val[k] == smin_val[k])\
    \ smin_val[k] = x;\n            max_val[k] = x;\n        } else if (TYPE == CHMAX)\
    \ {\n            sum[k] += (x - min_val[k]) * min_cnt[k];\n            if (min_val[k]\
    \ == max_val[k]) max_val[k] = x;\n            else if (min_val[k] == smax_val[k])\
    \ smax_val[k] = x;\n            min_val[k] = x;\n        } else if (TYPE == ADD)\
    \ {\n            min_val[k] += x;\n            if (smin_val[k] != INF) smin_val[k]\
    \ += x;\n            max_val[k] += x;\n            if (smax_val[k] != NINF) smax_val[k]\
    \ += x;\n            sum[k] += x * len[k];\n            lazy[k] += x;\n      \
    \  }\n    }\n\n    void push(int k) {\n        if (lazy[k] != 0) {\n         \
    \   tag<ADD>(2 * k, lazy[k]);\n            tag<ADD>(2 * k + 1, lazy[k]);\n   \
    \         lazy[k] = 0;\n        }\n        if (max_val[k] < max_val[2 * k]) tag<CHMIN>(2\
    \ * k, max_val[k]);\n        if (min_val[k] > min_val[2 * k]) tag<CHMAX>(2 * k,\
    \ min_val[k]);\n        if (max_val[k] < max_val[2 * k + 1]) tag<CHMIN>(2 * k\
    \ + 1, max_val[k]);\n        if (min_val[k] > min_val[2 * k + 1]) tag<CHMAX>(2\
    \ * k + 1, min_val[k]);\n    }\n\n    template <OpType TYPE>\n    inline bool\
    \ break_cond(int k, T x) {\n        if (TYPE == CHMIN) return max_val[k] <= x;\n\
    \        if (TYPE == CHMAX) return min_val[k] >= x;\n        if (TYPE == ADD)\
    \ return false;\n    }\n\n    template <OpType TYPE>\n    inline bool tag_cond(int\
    \ k, T x) {\n        if (TYPE == CHMIN) return smax_val[k] < x;\n        if (TYPE\
    \ == CHMAX) return smin_val[k] > x;\n        if (TYPE == ADD) return true;\n \
    \   }\n\n    template <OpType TYPE>\n    void update(int a, int b, T x, int k,\
    \ int l, int r) {\n        if (r <= a || b <= l || break_cond<TYPE>(k, x)) return;\n\
    \        if (a <= l && r <= b && tag_cond<TYPE>(k, x)) {\n            tag<TYPE>(k,\
    \ x);\n            return;\n        }\n        push(k);\n        int m = (l +\
    \ r) / 2;\n        update<TYPE>(a, b, x, 2 * k, l, m);\n        update<TYPE>(a,\
    \ b, x, 2 * k + 1, m, r);\n        recalc(k);\n    }\n\n    template <QueryType\
    \ TYPE>\n    T fold(int a, int b, int k, int l, int r) {\n        if (r <= a ||\
    \ b <= l) {\n            if (TYPE == MIN) return INF;\n            if (TYPE ==\
    \ MAX) return NINF;\n            if (TYPE == SUM) return 0;\n        }\n     \
    \   if (a <= l && r <= b) {\n            if (TYPE == MIN) return min_val[k];\n\
    \            if (TYPE == MAX) return max_val[k];\n            if (TYPE == SUM)\
    \ return sum[k];\n        }\n        push(k);\n        int m = (l + r) / 2;\n\
    \        T vl = fold<TYPE>(a, b, 2 * k, l, m);\n        T vr = fold<TYPE>(a, b,\
    \ 2 * k + 1, m, r);\n        if (TYPE == MIN) return std::min(vl, vr);\n     \
    \   if (TYPE == MAX) return std::max(vl, vr);\n        if (TYPE == SUM) return\
    \ vl + vr;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/segment_tree_beats.cpp
  requiredBy: []
  timestamp: '2020-10-24 14:54:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: data-structure/segtree/segment_tree_beats.cpp
layout: document
redirect_from:
- /library/data-structure/segtree/segment_tree_beats.cpp
- /library/data-structure/segtree/segment_tree_beats.cpp.html
title: Segment Tree Beats
---
# Segment Tree Beats

Segment tree beats は，遅延伝搬セグメント木の亜種で，区間 chmin/chmax/add 更新と区間 min/max/sum クエリを処理できる．

sum クエリがないときは遅延伝搬セグメント木で十分である．

時間計算量は $O(\lg^2 n)$ ではなく $O(\lg n)$かもしれない．よくわからないのでここでは前者を使用する（表記として間違ってはいない）．

空間計算量: $O(n)$

## Template parameters

- `T`
    - 要素の型

## Constructor

- `SegmentTreeBeats(int n)`
    - サイズ`n`で要素がすべて 0 の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `SegmentTreeBeats(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の segment tree beats を構築する
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int k)`
    - $a_k$ を返す
    - 時間計算量: $O(\lg^2 n)$
- `void chmin(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $min(a_i, x)$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `void chmax(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $max(a_i, x)$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `void add(int l, int r, T x)`
    - $i \in [l, r)$ について $a_i$ を $a_i + x$ に更新する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_min(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_max(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$
- `T fold_sum(int l, int r)`
    - $min(a_l, a_{l+1}, \cdots, a_{r-1})$ を計算する
    - 時間計算量: $O(\lg^2 n)$

## Reference

[A simple introduction to "Segment tree beats"](https://codeforces.com/blog/entry/5731)