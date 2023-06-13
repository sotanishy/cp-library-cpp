---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree.cpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_range_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n#line 2 \"data-structure/segtree/segment_tree.cpp\"\
    \n#include <algorithm>\n#include <vector>\n\ntemplate <typename M>\nclass SegmentTree\
    \ {\n    using T = typename M::T;\n\n   public:\n    SegmentTree() = default;\n\
    \    explicit SegmentTree(int n) : SegmentTree(std::vector<T>(n, M::id())) {}\n\
    \    explicit SegmentTree(const std::vector<T>& v) {\n        size = 1;\n    \
    \    while (size < (int)v.size()) size <<= 1;\n        node.resize(2 * size, M::id());\n\
    \        std::copy(v.begin(), v.end(), node.begin() + size);\n        for (int\
    \ i = size - 1; i > 0; --i)\n            node[i] = M::op(node[2 * i], node[2 *\
    \ i + 1]);\n    }\n\n    T operator[](int k) const { return node[k + size]; }\n\
    \n    void update(int k, const T& x) {\n        k += size;\n        node[k] =\
    \ x;\n        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);\n\
    \    }\n\n    T fold(int l, int r) const {\n        T vl = M::id(), vr = M::id();\n\
    \        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) vl = M::op(vl, node[l++]);\n            if (r & 1) vr = M::op(node[--r],\
    \ vr);\n        }\n        return M::op(vl, vr);\n    }\n\n    template <typename\
    \ F>\n    int find_first(int l, F cond) const {\n        T v = M::id();\n    \
    \    for (l += size; l > 0; l >>= 1) {\n            if (l & 1) {\n           \
    \     T nv = M::op(v, node[l]);\n                if (cond(nv)) {\n           \
    \         while (l < size) {\n                        nv = M::op(v, node[2 * l]);\n\
    \                        if (cond(nv))\n                            l = 2 * l;\n\
    \                        else\n                            v = nv, l = 2 * l +\
    \ 1;\n                    }\n                    return l + 1 - size;\n      \
    \          }\n                v = nv;\n                ++l;\n            }\n \
    \       }\n        return -1;\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) const {\n        T v = M::id();\n        for (r += size; r > 0; r\
    \ >>= 1) {\n            if (r & 1) {\n                --r;\n                T\
    \ nv = M::op(node[r], v);\n                if (cond(nv)) {\n                 \
    \   while (r < size) {\n                        nv = M::op(node[2 * r + 1], v);\n\
    \                        if (cond(nv))\n                            r = 2 * r\
    \ + 1;\n                        else\n                            v = nv, r =\
    \ 2 * r;\n                    }\n                    return r - size;\n      \
    \          }\n                v = nv;\n            }\n        }\n        return\
    \ -1;\n    }\n\n   private:\n    int size;\n    std::vector<T> node;\n};\n#line\
    \ 4 \"test/yosupo/point_add_range_sum.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nstruct Monoid {\n    using T =\
    \ ll;\n    static T id() { return 0; }\n    static T op(T a, T b) { return a +\
    \ b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> a[i];\n    SegmentTree<Monoid> st(a);\n    for (int i = 0;\
    \ i < Q; i++) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n  \
    \          int p, x;\n            cin >> p >> x;\n            st.update(p, st[p]\
    \ + x);\n        } else {\n            int l, r;\n            cin >> l >> r;\n\
    \            cout << st.fold(l, r) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include \"../../data-structure/segtree/segment_tree.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nstruct Monoid {\n    using T =\
    \ ll;\n    static T id() { return 0; }\n    static T op(T a, T b) { return a +\
    \ b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> a[i];\n    SegmentTree<Monoid> st(a);\n    for (int i = 0;\
    \ i < Q; i++) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n  \
    \          int p, x;\n            cin >> p >> x;\n            st.update(p, st[p]\
    \ + x);\n        } else {\n            int l, r;\n            cin >> l >> r;\n\
    \            cout << st.fold(l, r) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/segment_tree.cpp
  isVerificationFile: true
  path: test/yosupo/point_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2023-06-13 22:58:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_range_sum.test.cpp
- /verify/test/yosupo/point_add_range_sum.test.cpp.html
title: test/yosupo/point_add_range_sum.test.cpp
---
