---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
    title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/segtree/segment_tree_beats.cpp\"\n#include\
    \ <algorithm>\n#include <limits>\n#include <vector>\n\ntemplate <typename M, typename\
    \ O, std::pair<typename M::T, bool> (*act)(typename M::T, typename O::T)>\nclass\
    \ SegmentTreeBeats {\n    using T = typename M::T;\n    using E = typename O::T;\n\
    \npublic:\n    SegmentTreeBeats() = default;\n    explicit SegmentTreeBeats(int\
    \ n) : SegmentTreeBeats(std::vector<T>(n, M::id())) {}\n    explicit SegmentTreeBeats(const\
    \ std::vector<T>& v) {\n        size = 1;\n        while (size < (int) v.size())\
    \ size <<= 1;\n        node.resize(2 * size, M::id());\n        lazy.resize(2\
    \ * size, O::id());\n        std::copy(v.begin(), v.end(), node.begin() + size);\n\
    \        for (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2\
    \ * i + 1]);\n    }\n\n    T operator[](int k) {\n        return fold(k, k + 1);\n\
    \    }\n\n    void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size);\
    \ }\n\n    T fold(int l, int r) { return fold(l, r, 1, 0, size); }\n\nprivate:\n\
    \    int size;\n    std::vector<T> node;\n    std::vector<E> lazy;\n\n    void\
    \ push(int k) {\n        if (lazy[k] == O::id()) return;\n        if (k < size)\
    \ {\n            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);\n            lazy[2\
    \ * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n        }\n        bool success;\n\
    \        std::tie(node[k], success) = act(node[k], lazy[k]);\n        if (!success)\
    \ {\n            assert(k < size);\n            push(2 * k);\n            push(2\
    \ * k + 1);\n            node[k] = M::op(node[2 * k], node[2 * k + 1]);\n    \
    \    }\n        lazy[k] = O::id();\n    }\n\n    void update(int a, int b, const\
    \ E& x, int k, int l, int r) {\n        push(k);\n        if (r <= a || b <= l)\
    \ return;\n        if (a <= l && r <= b) {\n            lazy[k] = O::op(lazy[k],\
    \ x);\n            push(k);\n            return;\n        }\n        int m = (l\
    \ + r) / 2;\n        update(a, b, x, 2 * k, l, m);\n        update(a, b, x, 2\
    \ * k + 1, m, r);\n        node[k] = M::op(node[2 * k], node[2 * k + 1]);\n  \
    \  }\n\n    T fold(int a, int b, int k, int l, int r) {\n        push(k);\n  \
    \      if (r <= a || b <= l) return M::id();\n        if (a <= l && r <= b) return\
    \ node[k];\n        int m = (l + r) / 2;\n        return M::op(fold(a, b, 2 *\
    \ k, l, m),\n                     fold(a, b, 2 * k + 1, m, r));\n    }\n};\n\n\
    \n// the monoid for range chmin/chmax/add range sum query\n\nconstexpr ll INF\
    \ = 1e18;\n\nstruct S {\n    ll max_val, smax_val;\n    ll min_val, smin_val;\n\
    \    ll sum;\n    int max_cnt, min_cnt, len;\n    S() : max_val(-INF), smax_val(-INF),\
    \ min_val(INF), smin_val(INF),\n          sum(0), max_cnt(0), min_cnt(0), len(0)\
    \ {}\n    S(ll x, int len) : max_val(x), smax_val(-INF), min_val(x), smin_val(INF),\n\
    \                       sum(x * len), max_cnt(len), min_cnt(len), len(len) {}\n\
    };\n\nstruct MinMaxSumMonoid {\n    using T = S;\n    static T id() { return S();\
    \ }\n    static T op(T a, T b) {\n        T c;\n        c.sum = a.sum + b.sum;\n\
    \        c.len = a.len + b.len;\n        if (a.min_val < b.min_val) {\n      \
    \      c.min_val = a.min_val;\n            c.min_cnt = a.min_cnt;\n          \
    \  c.smin_val = std::min(a.smin_val, b.min_val);\n        } else if (a.min_val\
    \ > b.min_val) {\n            c.min_val = b.min_val;\n            c.min_cnt =\
    \ b.min_cnt;\n            c.smin_val = std::min(a.min_val, b.smin_val);\n    \
    \    } else {\n            c.min_val = a.min_val;\n            c.min_cnt = a.min_cnt\
    \ + b.min_cnt;\n            c.smin_val = std::min(a.smin_val, b.smin_val);\n \
    \       }\n        if (a.max_val > b.max_val) {\n            c.max_val = a.max_val;\n\
    \            c.max_cnt = a.max_cnt;\n            c.smax_val = std::max(a.smax_val,\
    \ b.max_val);\n        } else if (a.max_val < b.max_val) {\n            c.max_val\
    \ = b.max_val;\n            c.max_cnt = b.max_cnt;\n            c.smax_val = std::max(a.max_val,\
    \ b.smax_val);\n        } else {\n            c.max_val = a.max_val;\n       \
    \     c.max_cnt = a.max_cnt + b.max_cnt;\n            c.smax_val = std::max(a.smax_val,\
    \ b.smax_val);\n        }\n        return c;\n    }\n};\n\nstruct F {\n    ll\
    \ lb, ub, diff;\n    F(ll lb = -INF, ll ub = INF, ll diff = 0) : lb(lb), ub(ub),\
    \ diff(diff) {}\n    static F chmin(ll x) { return F(-INF, x, 0); }\n    static\
    \ F chmax(ll x) { return F(x, INF, 0); }\n    static F add(ll x) { return F(-INF,\
    \ INF, x); }\n    bool operator==(const F& rhs) const { return lb == rhs.lb &&\
    \ ub == rhs.ub && diff == rhs.diff; }\n};\n\nstruct ChminChmaxAddMonoid {\n  \
    \  using T = F;\n    static T id() { return F(); }\n    static T op(T a, T b)\
    \ {\n        F c;\n        c.lb = std::clamp(a.lb + a.diff, b.lb, b.ub) - a.diff;\n\
    \        c.ub = std::clamp(a.ub + a.diff, b.lb, b.ub) - a.diff;\n        c.diff\
    \ = a.diff + b.diff;\n        return c;\n    }\n};\n\nstd::pair<S, bool> act(S\
    \ a, F b) {\n    if (a.len == 0) return {a, true};\n    if (a.min_val == a.max_val\
    \ || b.lb == b.ub || a.max_val <= b.lb || b.ub < a.min_val) {\n        return\
    \ {S(std::clamp(a.min_val, b.lb, b.ub) + b.diff, a.len), true};\n    }\n    if\
    \ (a.smin_val == a.max_val) {\n        a.min_val = a.smax_val = std::max(a.min_val,\
    \ b.lb) + b.diff;\n        a.max_val = a.smin_val = std::min(a.max_val, b.ub)\
    \ + b.diff;\n        a.sum = a.min_val * a.min_cnt + a.max_val * a.max_cnt;\n\
    \        return {a, true};\n    }\n    if (b.lb < a.smin_val && a.smax_val < b.ub)\
    \ {\n        ll min_nxt = std::max(a.min_val, b.lb);\n        ll max_nxt = std::min(a.max_val,\
    \ b.ub);\n        a.sum += (min_nxt - a.min_val) * a.min_cnt - (a.max_val - max_nxt)\
    \ * a.max_cnt + b.diff * a.len;\n        a.min_val = min_nxt + b.diff;\n     \
    \   a.max_val = max_nxt + b.diff;\n        a.smin_val += b.diff;\n        a.smax_val\
    \ += b.diff;\n        return {a, true};\n    }\n    return {a, false};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <vector>\n\
    \ntemplate <typename M, typename O, std::pair<typename M::T, bool> (*act)(typename\
    \ M::T, typename O::T)>\nclass SegmentTreeBeats {\n    using T = typename M::T;\n\
    \    using E = typename O::T;\n\npublic:\n    SegmentTreeBeats() = default;\n\
    \    explicit SegmentTreeBeats(int n) : SegmentTreeBeats(std::vector<T>(n, M::id()))\
    \ {}\n    explicit SegmentTreeBeats(const std::vector<T>& v) {\n        size =\
    \ 1;\n        while (size < (int) v.size()) size <<= 1;\n        node.resize(2\
    \ * size, M::id());\n        lazy.resize(2 * size, O::id());\n        std::copy(v.begin(),\
    \ v.end(), node.begin() + size);\n        for (int i = size - 1; i > 0; --i) node[i]\
    \ = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int k) {\n\
    \        return fold(k, k + 1);\n    }\n\n    void update(int l, int r, const\
    \ E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int l, int r) { return\
    \ fold(l, r, 1, 0, size); }\n\nprivate:\n    int size;\n    std::vector<T> node;\n\
    \    std::vector<E> lazy;\n\n    void push(int k) {\n        if (lazy[k] == O::id())\
    \ return;\n        if (k < size) {\n            lazy[2 * k] = O::op(lazy[2 * k],\
    \ lazy[k]);\n            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n\
    \        }\n        bool success;\n        std::tie(node[k], success) = act(node[k],\
    \ lazy[k]);\n        if (!success) {\n            assert(k < size);\n        \
    \    push(2 * k);\n            push(2 * k + 1);\n            node[k] = M::op(node[2\
    \ * k], node[2 * k + 1]);\n        }\n        lazy[k] = O::id();\n    }\n\n  \
    \  void update(int a, int b, const E& x, int k, int l, int r) {\n        push(k);\n\
    \        if (r <= a || b <= l) return;\n        if (a <= l && r <= b) {\n    \
    \        lazy[k] = O::op(lazy[k], x);\n            push(k);\n            return;\n\
    \        }\n        int m = (l + r) / 2;\n        update(a, b, x, 2 * k, l, m);\n\
    \        update(a, b, x, 2 * k + 1, m, r);\n        node[k] = M::op(node[2 * k],\
    \ node[2 * k + 1]);\n    }\n\n    T fold(int a, int b, int k, int l, int r) {\n\
    \        push(k);\n        if (r <= a || b <= l) return M::id();\n        if (a\
    \ <= l && r <= b) return node[k];\n        int m = (l + r) / 2;\n        return\
    \ M::op(fold(a, b, 2 * k, l, m),\n                     fold(a, b, 2 * k + 1, m,\
    \ r));\n    }\n};\n\n\n// the monoid for range chmin/chmax/add range sum query\n\
    \nconstexpr ll INF = 1e18;\n\nstruct S {\n    ll max_val, smax_val;\n    ll min_val,\
    \ smin_val;\n    ll sum;\n    int max_cnt, min_cnt, len;\n    S() : max_val(-INF),\
    \ smax_val(-INF), min_val(INF), smin_val(INF),\n          sum(0), max_cnt(0),\
    \ min_cnt(0), len(0) {}\n    S(ll x, int len) : max_val(x), smax_val(-INF), min_val(x),\
    \ smin_val(INF),\n                       sum(x * len), max_cnt(len), min_cnt(len),\
    \ len(len) {}\n};\n\nstruct MinMaxSumMonoid {\n    using T = S;\n    static T\
    \ id() { return S(); }\n    static T op(T a, T b) {\n        T c;\n        c.sum\
    \ = a.sum + b.sum;\n        c.len = a.len + b.len;\n        if (a.min_val < b.min_val)\
    \ {\n            c.min_val = a.min_val;\n            c.min_cnt = a.min_cnt;\n\
    \            c.smin_val = std::min(a.smin_val, b.min_val);\n        } else if\
    \ (a.min_val > b.min_val) {\n            c.min_val = b.min_val;\n            c.min_cnt\
    \ = b.min_cnt;\n            c.smin_val = std::min(a.min_val, b.smin_val);\n  \
    \      } else {\n            c.min_val = a.min_val;\n            c.min_cnt = a.min_cnt\
    \ + b.min_cnt;\n            c.smin_val = std::min(a.smin_val, b.smin_val);\n \
    \       }\n        if (a.max_val > b.max_val) {\n            c.max_val = a.max_val;\n\
    \            c.max_cnt = a.max_cnt;\n            c.smax_val = std::max(a.smax_val,\
    \ b.max_val);\n        } else if (a.max_val < b.max_val) {\n            c.max_val\
    \ = b.max_val;\n            c.max_cnt = b.max_cnt;\n            c.smax_val = std::max(a.max_val,\
    \ b.smax_val);\n        } else {\n            c.max_val = a.max_val;\n       \
    \     c.max_cnt = a.max_cnt + b.max_cnt;\n            c.smax_val = std::max(a.smax_val,\
    \ b.smax_val);\n        }\n        return c;\n    }\n};\n\nstruct F {\n    ll\
    \ lb, ub, diff;\n    F(ll lb = -INF, ll ub = INF, ll diff = 0) : lb(lb), ub(ub),\
    \ diff(diff) {}\n    static F chmin(ll x) { return F(-INF, x, 0); }\n    static\
    \ F chmax(ll x) { return F(x, INF, 0); }\n    static F add(ll x) { return F(-INF,\
    \ INF, x); }\n    bool operator==(const F& rhs) const { return lb == rhs.lb &&\
    \ ub == rhs.ub && diff == rhs.diff; }\n};\n\nstruct ChminChmaxAddMonoid {\n  \
    \  using T = F;\n    static T id() { return F(); }\n    static T op(T a, T b)\
    \ {\n        F c;\n        c.lb = std::clamp(a.lb + a.diff, b.lb, b.ub) - a.diff;\n\
    \        c.ub = std::clamp(a.ub + a.diff, b.lb, b.ub) - a.diff;\n        c.diff\
    \ = a.diff + b.diff;\n        return c;\n    }\n};\n\nstd::pair<S, bool> act(S\
    \ a, F b) {\n    if (a.len == 0) return {a, true};\n    if (a.min_val == a.max_val\
    \ || b.lb == b.ub || a.max_val <= b.lb || b.ub < a.min_val) {\n        return\
    \ {S(std::clamp(a.min_val, b.lb, b.ub) + b.diff, a.len), true};\n    }\n    if\
    \ (a.smin_val == a.max_val) {\n        a.min_val = a.smax_val = std::max(a.min_val,\
    \ b.lb) + b.diff;\n        a.max_val = a.smin_val = std::min(a.max_val, b.ub)\
    \ + b.diff;\n        a.sum = a.min_val * a.min_cnt + a.max_val * a.max_cnt;\n\
    \        return {a, true};\n    }\n    if (b.lb < a.smin_val && a.smax_val < b.ub)\
    \ {\n        ll min_nxt = std::max(a.min_val, b.lb);\n        ll max_nxt = std::min(a.max_val,\
    \ b.ub);\n        a.sum += (min_nxt - a.min_val) * a.min_cnt - (a.max_val - max_nxt)\
    \ * a.max_cnt + b.diff * a.len;\n        a.min_val = min_nxt + b.diff;\n     \
    \   a.max_val = max_nxt + b.diff;\n        a.smin_val += b.diff;\n        a.smax_val\
    \ += b.diff;\n        return {a, true};\n    }\n    return {a, false};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/segtree/segment_tree_beats.cpp
  requiredBy: []
  timestamp: '2022-06-26 17:14:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
documentation_of: data-structure/segtree/segment_tree_beats.cpp
layout: document
title: Segment Tree Beats
---

## Description

Segment tree beats は，遅延伝搬セグメント木の亜種で，作用の分配則が成り立たず，作用に失敗した場合に，子に関する計算結果を用いてボトムアップに再構築するデータ構造である．

作用 `act` の返り値の型は `pair<M::T, bool>` で，作用に失敗した場合 `false` を返す．

空間計算量: $O(n)$

## Operations

- `SegmentTreeBeats(int n)`
    - サイズ`n`で要素がすべて単位元 $e_M$ の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `SegmentTreeBeats(vector<T> v)`
    - `v`の要素からサイズ`n = v.size()`の segment tree beats を構築する
    - 時間計算量: $O(n)$
- `T operator[](int k)`
    - $k$ 番目の要素を返す
- `void update(int l, int r, E x)`
    - 区間 $[l, r)$ の値に $x$ を作用させる
- `T fold(int l, int r)`
    - 区間 $[l, r)$ の値を fold する

## Note

時間計算量はモノイドや作用の設計による．

実現できる機能の例
- range chmin/chmax/add, range sum (Library Checker - Range Chmin Chmax Add Range Sum)
    - chmin/chmax クエリで，sum の計算に失敗する．
    - 計算量は $\mathrm{amortized}\,O(\log^2 n)$
    - 計算量解析はわからん．
- range divide/update, range sum (ABC256Ex - I like Query Problem)
    - 区間に含まれる要素がすべて同じではない場合，divide クエリに失敗する．
    - 計算量は $\mathrm{amortiezed}\,O(\log n \log \max A)$
    - 計算量解析は [公式解説](https://atcoder.jp/contests/abc256/editorial/4113) を参照．

## Reference

- [A simple introduction to "Segment tree beats" - Codeforces](https://codeforces.com/blog/entry/5731)
- [Segment Tree Beatsの実装メモ (基本まわり) - 日々ｄｒｄｒする人のメモ](https://smijake3.hatenablog.com/entry/2019/04/28/021457)
- [atcoder::lazy_segtree に1行書き足すだけの抽象化 Segment Tree Beats - ひとなので](https://rsm9.hatenablog.com/entry/2021/02/01/220408)