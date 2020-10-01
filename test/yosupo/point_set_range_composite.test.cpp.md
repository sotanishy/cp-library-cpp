---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segment_tree.cpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/yosupo/point_set_range_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\n\n#line\
    \ 1 \"data-structure/segment_tree.cpp\"\n#include <bits/stdc++.h>\n\n/*\n * @brief\
    \ Segment Tree\n * @docs docs/data-structure/segment_tree.md\n */\ntemplate <typename\
    \ M>\nclass SegmentTree {\n    using T = typename M::T;\n\npublic:\n    SegmentTree()\
    \ = default;\n    explicit SegmentTree(int n): SegmentTree(vector<T>(n, M::id))\
    \ {}\n    explicit SegmentTree(const vector<T>& v) {\n        size = 1;\n    \
    \    while (size < (int) v.size()) size <<= 1;\n        node.resize(2 * size,\
    \ M::id);\n        copy(v.begin(), v.end(), node.begin() + size);\n        for\
    \ (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2 * i + 1]);\n\
    \    }\n\n    T operator[](int k) const {\n        return node[k + size];\n  \
    \  }\n\n    void update(int k, const T& x) {\n        k += size;\n        node[k]\
    \ = x;\n        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);\n\
    \    }\n\n    T fold(int l, int r) const {\n        T vl = M::id, vr = M::id;\n\
    \        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (l & 1) vl = M::op(vl, node[l++]);\n            if (r & 1) vr = M::op(node[--r],\
    \ vr);\n        }\n        return M::op(vl, vr);\n    }\n\n    template <typename\
    \ F>\n    int find_first(int l, const F& cond) const {\n        T vl = M::id;\n\
    \        int r = size;\n        for (l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) {\n                T nxt = M::op(vl, node[l]);\n\
    \                if (cond(nxt)) {\n                    while (l < size) {\n  \
    \                      nxt = M::op(vl, node[2 * l]);\n                       \
    \ if (cond(nxt)) l = 2 * l;\n                        else vl = nxt, l = 2 * l\
    \ + 1;\n                    }\n                    return l - size;\n        \
    \        }\n                vl = nxt;\n                ++l;\n            }\n \
    \       }\n        return -1;\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, const F& cond) const {\n        T vr = M::id;\n        int l = 0;\n     \
    \   for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (r &\
    \ 1) {\n                --r;\n                T nxt = M::op(node[r], vr);\n  \
    \              if (cond(nxt)) {\n                    while (r < size) {\n    \
    \                    nxt = M::op(node[2 * r + 1], vr);\n                     \
    \   if (cond(nxt)) r = 2 * r + 1;\n                        else vr = nxt, r =\
    \ 2 * r;\n                    }\n                    return r - size;\n      \
    \          }\n                vr = nxt;\n            }\n        }\n        return\
    \ -1;\n    }\n\nprivate:\n    int size;\n    vector<T> node;\n};\n#line 4 \"test/yosupo/point_set_range_composite.test.cpp\"\
    \n\nusing ll = long long;\n\nconst ll mod = 998244353;\n\nstruct Monoid {\n  \
    \  using T = pair<ll, ll>;\n    static inline T id = {1, 0};\n    static T op(T\
    \ a, T b) {\n        return {a.first * b.first % mod, (a.second * b.first + b.second)\
    \ % mod};\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<pair<ll, ll>>\
    \ ab(N);\n    for (int i = 0; i < N; i++) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        ab[i] = {a, b};\n    }\n    SegmentTree<Monoid> st(ab);\n \
    \   for (int i = 0; i < Q; i++) {\n        int t;\n        cin >> t;\n       \
    \ if (t == 0) {\n            int p, c, d;\n            cin >> p >> c >> d;\n \
    \           st.update(p, {c, d});\n        } else {\n            int l, r, x;\n\
    \            cin >> l >> r >> x;\n            auto f = st.fold(l, r);\n      \
    \      cout << (f.first * x + f.second) % mod << \"\\n\";\n        }\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../data-structure/segment_tree.cpp\"\n\nusing ll = long long;\n\
    \nconst ll mod = 998244353;\n\nstruct Monoid {\n    using T = pair<ll, ll>;\n\
    \    static inline T id = {1, 0};\n    static T op(T a, T b) {\n        return\
    \ {a.first * b.first % mod, (a.second * b.first + b.second) % mod};\n    }\n};\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int N, Q;\n    cin >> N >> Q;\n    vector<pair<ll, ll>> ab(N);\n    for (int\
    \ i = 0; i < N; i++) {\n        int a, b;\n        cin >> a >> b;\n        ab[i]\
    \ = {a, b};\n    }\n    SegmentTree<Monoid> st(ab);\n    for (int i = 0; i < Q;\
    \ i++) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n         \
    \   int p, c, d;\n            cin >> p >> c >> d;\n            st.update(p, {c,\
    \ d});\n        } else {\n            int l, r, x;\n            cin >> l >> r\
    \ >> x;\n            auto f = st.fold(l, r);\n            cout << (f.first * x\
    \ + f.second) % mod << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/segment_tree.cpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2020-10-01 22:29:44+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
