---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/dual_segment_tree.cpp
    title: Dual Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D
  bundledCode: "#line 1 \"test/aoj/DSL_2_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#line 1 \"data-structure/segtree/dual_segment_tree.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Dual Segment Tree\n * @docs docs/data-structure/segtree/dual_segment_tree.md\n\
    \ */\ntemplate <typename M>\nclass DualSegmentTree {\n    using T = typename M::T;\n\
    \npublic:\n    DualSegmentTree() = default;\n    explicit DualSegmentTree(int\
    \ n) {\n        size = 1;\n        height = 1;\n        while (size < n) size\
    \ <<= 1, ++height;\n        lazy.resize(2 * size, M::id);\n    }\n\n    T operator[](int\
    \ k) {\n        k += size;\n        propagate(k);\n        return lazy[k];\n \
    \   }\n\n    void update(int l, int r, const T& x) {\n        l += size;\n   \
    \     r += size;\n        propagate(l);\n        propagate(r - 1);\n        for\
    \ (; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) lazy[l] = M::op(lazy[l],\
    \ x), ++l;\n            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);\n       \
    \ }\n    }\n\nprivate:\n    int size, height;\n    std::vector<T> lazy;\n\n  \
    \  void push(int k) {\n        if (lazy[k] == M::id) return;\n        lazy[2 *\
    \ k] = M::op(lazy[2 * k], lazy[k]);\n        lazy[2 * k + 1] = M::op(lazy[2 *\
    \ k + 1], lazy[k]);\n        lazy[k] = M::id;\n    }\n\n    void propagate(int\
    \ k) {\n        for (int i = height; i > 0; --i) push(k >> i);\n    }\n};\n#line\
    \ 4 \"test/aoj/DSL_2_D.test.cpp\"\n\nusing namespace std;\n\nstruct Monoid {\n\
    \    using T = int;\n    static constexpr T id = (1u << 31) - 1;\n    static T\
    \ op(T a, T b) {\n        return b;\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    DualSegmentTree<Monoid>\
    \ st(n);\n    for (int i = 0; i < q; i++) {\n        int type;\n        cin >>\
    \ type;\n        if (type == 0) {\n            int s, t, x;\n            cin >>\
    \ s >> t >> x;\n            st.update(s, t + 1, x);\n        } else {\n      \
    \      int i;\n            cin >> i;\n            cout << st[i] << \"\\n\";\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D\"\
    \n\n#include \"../../data-structure/segtree/dual_segment_tree.cpp\"\n\nusing namespace\
    \ std;\n\nstruct Monoid {\n    using T = int;\n    static constexpr T id = (1u\
    \ << 31) - 1;\n    static T op(T a, T b) {\n        return b;\n    }\n};\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ n, q;\n    cin >> n >> q;\n    DualSegmentTree<Monoid> st(n);\n    for (int\
    \ i = 0; i < q; i++) {\n        int type;\n        cin >> type;\n        if (type\
    \ == 0) {\n            int s, t, x;\n            cin >> s >> t >> x;\n       \
    \     st.update(s, t + 1, x);\n        } else {\n            int i;\n        \
    \    cin >> i;\n            cout << st[i] << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/dual_segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_D.test.cpp
  requiredBy: []
  timestamp: '2020-10-12 02:39:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_D.test.cpp
- /verify/test/aoj/DSL_2_D.test.cpp.html
title: test/aoj/DSL_2_D.test.cpp
---
