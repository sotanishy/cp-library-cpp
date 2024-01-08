---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree_beats.hpp
    title: Segment Tree Beats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/range_chmin_chmax_add_range_sum.test.cpp\"\n\
    #define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#line 3 \"data-structure/segtree/segment_tree_beats.hpp\"\
    \n#include <bit>\n#line 8 \"data-structure/segtree/segment_tree_beats.hpp\"\n\n\
    template <typename M, typename O,\n          std::pair<typename M::T, bool> (*act)(typename\
    \ M::T, typename O::T)>\nclass SegmentTreeBeats {\n    using T = M::T;\n    using\
    \ E = O::T;\n\n   public:\n    SegmentTreeBeats() = default;\n    explicit SegmentTreeBeats(int\
    \ n)\n        : SegmentTreeBeats(std::vector<T>(n, M::id())) {}\n    explicit\
    \ SegmentTreeBeats(const std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\n\
    \          node(2 * size, M::id()),\n          lazy(2 * size, O::id()) {\n   \
    \     std::ranges::copy(v, node.begin() + size);\n        for (int i = size -\
    \ 1; i > 0; --i) {\n            node[i] = M::op(node[2 * i], node[2 * i + 1]);\n\
    \        }\n    }\n\n    T operator[](int k) { return fold(k, k + 1); }\n\n  \
    \  void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size); }\n\n\
    \    T fold(int l, int r) { return fold(l, r, 1, 0, size); }\n\n   private:\n\
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
    \ x);\n            push(k);\n            return;\n        }\n        int m = std::midpoint(l,\
    \ r);\n        update(a, b, x, 2 * k, l, m);\n        update(a, b, x, 2 * k +\
    \ 1, m, r);\n        node[k] = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n\
    \    T fold(int a, int b, int k, int l, int r) {\n        push(k);\n        if\
    \ (r <= a || b <= l) return M::id();\n        if (a <= l && r <= b) return node[k];\n\
    \        int m = std::midpoint(l, r);\n        return M::op(fold(a, b, 2 * k,\
    \ l, m), fold(a, b, 2 * k + 1, m, r));\n    }\n};\n\n// the monoid for range chmin/chmax/add\
    \ range sum query\n\nusing ll = long long;\nconstexpr ll INF = 1e18;\n\nstruct\
    \ S {\n    ll max_val, smax_val;\n    ll min_val, smin_val;\n    ll sum;\n   \
    \ int max_cnt, min_cnt, len;\n    S()\n        : max_val(-INF),\n          smax_val(-INF),\n\
    \          min_val(INF),\n          smin_val(INF),\n          sum(0),\n      \
    \    max_cnt(0),\n          min_cnt(0),\n          len(0) {}\n    S(ll x, int\
    \ len)\n        : max_val(x),\n          smax_val(-INF),\n          min_val(x),\n\
    \          smin_val(INF),\n          sum(x * len),\n          max_cnt(len),\n\
    \          min_cnt(len),\n          len(len) {}\n};\n\nstruct MinMaxSumMonoid\
    \ {\n    using T = S;\n    static T id() { return S(); }\n    static T op(T a,\
    \ T b) {\n        T c;\n        c.sum = a.sum + b.sum;\n        c.len = a.len\
    \ + b.len;\n        if (a.min_val < b.min_val) {\n            c.min_val = a.min_val;\n\
    \            c.min_cnt = a.min_cnt;\n            c.smin_val = std::min(a.smin_val,\
    \ b.min_val);\n        } else if (a.min_val > b.min_val) {\n            c.min_val\
    \ = b.min_val;\n            c.min_cnt = b.min_cnt;\n            c.smin_val = std::min(a.min_val,\
    \ b.smin_val);\n        } else {\n            c.min_val = a.min_val;\n       \
    \     c.min_cnt = a.min_cnt + b.min_cnt;\n            c.smin_val = std::min(a.smin_val,\
    \ b.smin_val);\n        }\n        if (a.max_val > b.max_val) {\n            c.max_val\
    \ = a.max_val;\n            c.max_cnt = a.max_cnt;\n            c.smax_val = std::max(a.smax_val,\
    \ b.max_val);\n        } else if (a.max_val < b.max_val) {\n            c.max_val\
    \ = b.max_val;\n            c.max_cnt = b.max_cnt;\n            c.smax_val = std::max(a.max_val,\
    \ b.smax_val);\n        } else {\n            c.max_val = a.max_val;\n       \
    \     c.max_cnt = a.max_cnt + b.max_cnt;\n            c.smax_val = std::max(a.smax_val,\
    \ b.smax_val);\n        }\n        return c;\n    }\n};\n\nstruct F {\n    ll\
    \ lb, ub, diff;\n    F(ll lb = -INF, ll ub = INF, ll diff = 0) : lb(lb), ub(ub),\
    \ diff(diff) {}\n    static F chmin(ll x) { return F(-INF, x, 0); }\n    static\
    \ F chmax(ll x) { return F(x, INF, 0); }\n    static F add(ll x) { return F(-INF,\
    \ INF, x); }\n    bool operator==(const F& rhs) const {\n        return lb ==\
    \ rhs.lb && ub == rhs.ub && diff == rhs.diff;\n    }\n};\n\nstruct ChminChmaxAddMonoid\
    \ {\n    using T = F;\n    static T id() { return F(); }\n    static T op(T a,\
    \ T b) {\n        F c;\n        c.lb = std::clamp(a.lb + a.diff, b.lb, b.ub) -\
    \ a.diff;\n        c.ub = std::clamp(a.ub + a.diff, b.lb, b.ub) - a.diff;\n  \
    \      c.diff = a.diff + b.diff;\n        return c;\n    }\n};\n\nstd::pair<S,\
    \ bool> act(S a, F b) {\n    if (a.len == 0) return {a, true};\n    if (a.min_val\
    \ == a.max_val || b.lb == b.ub || a.max_val <= b.lb ||\n        b.ub < a.min_val)\
    \ {\n        return {S(std::clamp(a.min_val, b.lb, b.ub) + b.diff, a.len), true};\n\
    \    }\n    if (a.smin_val == a.max_val) {\n        a.min_val = a.smax_val = std::max(a.min_val,\
    \ b.lb) + b.diff;\n        a.max_val = a.smin_val = std::min(a.max_val, b.ub)\
    \ + b.diff;\n        a.sum = a.min_val * a.min_cnt + a.max_val * a.max_cnt;\n\
    \        return {a, true};\n    }\n    if (b.lb < a.smin_val && a.smax_val < b.ub)\
    \ {\n        ll min_nxt = std::max(a.min_val, b.lb);\n        ll max_nxt = std::min(a.max_val,\
    \ b.ub);\n        a.sum += (min_nxt - a.min_val) * a.min_cnt -\n             \
    \    (a.max_val - max_nxt) * a.max_cnt + b.diff * a.len;\n        a.min_val =\
    \ min_nxt + b.diff;\n        a.max_val = max_nxt + b.diff;\n        a.smin_val\
    \ += b.diff;\n        a.smax_val += b.diff;\n        return {a, true};\n    }\n\
    \    return {a, false};\n}\n#line 7 \"test/yosupo/range_chmin_chmax_add_range_sum.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    vector<S> init(N);\n    for\
    \ (int i = 0; i < N; ++i) init[i] = S(a[i], 1);\n    SegmentTreeBeats<MinMaxSumMonoid,\
    \ ChminChmaxAddMonoid, act> st(init);\n    for (int i = 0; i < Q; i++) {\n   \
    \     int t, l, r;\n        ll b;\n        cin >> t >> l >> r;\n        if (t\
    \ != 3) cin >> b;\n        if (t == 0) {\n            st.update(l, r, F::chmin(b));\n\
    \        } else if (t == 1) {\n            st.update(l, r, F::chmax(b));\n   \
    \     } else if (t == 2) {\n            st.update(l, r, F::add(b));\n        }\
    \ else {\n            cout << st.fold(l, r).sum << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/segtree/segment_tree_beats.hpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    vector<S> init(N);\n    for\
    \ (int i = 0; i < N; ++i) init[i] = S(a[i], 1);\n    SegmentTreeBeats<MinMaxSumMonoid,\
    \ ChminChmaxAddMonoid, act> st(init);\n    for (int i = 0; i < Q; i++) {\n   \
    \     int t, l, r;\n        ll b;\n        cin >> t >> l >> r;\n        if (t\
    \ != 3) cin >> b;\n        if (t == 0) {\n            st.update(l, r, F::chmin(b));\n\
    \        } else if (t == 1) {\n            st.update(l, r, F::chmax(b));\n   \
    \     } else if (t == 2) {\n            st.update(l, r, F::add(b));\n        }\
    \ else {\n            cout << st.fold(l, r).sum << \"\\n\";\n        }\n    }\n\
    }"
  dependsOn:
  - data-structure/segtree/segment_tree_beats.hpp
  isVerificationFile: true
  path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 15:51:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
---
