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
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A
  bundledCode: "#line 1 \"test/aoj/DSL_2_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#line 2 \"data-structure/segtree/segment_tree.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <typename M>\nclass SegmentTree {\n    using T =\
    \ typename M::T;\n\npublic:\n    SegmentTree() = default;\n    explicit SegmentTree(int\
    \ n): SegmentTree(std::vector<T>(n, M::id)) {}\n    explicit SegmentTree(const\
    \ std::vector<T>& v) {\n        size = 1;\n        while (size < (int) v.size())\
    \ size <<= 1;\n        node.resize(2 * size, M::id);\n        std::copy(v.begin(),\
    \ v.end(), node.begin() + size);\n        for (int i = size - 1; i > 0; --i) node[i]\
    \ = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int k) const\
    \ {\n        return node[k + size];\n    }\n\n    void update(int k, const T&\
    \ x) {\n        k += size;\n        node[k] = x;\n        while (k >>= 1) node[k]\
    \ = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n    T fold(int l, int r) const\
    \ {\n        T vl = M::id, vr = M::id;\n        for (l += size, r += size; l <\
    \ r; l >>= 1, r >>= 1) {\n            if (l & 1) vl = M::op(vl, node[l++]);\n\
    \            if (r & 1) vr = M::op(node[--r], vr);\n        }\n        return\
    \ M::op(vl, vr);\n    }\n\n    template <typename F>\n    int find_first(int l,\
    \ F cond) const {\n        T vl = M::id;\n        int r = size;\n        for (l\
    \ += size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n \
    \               T nxt = M::op(vl, node[l]);\n                if (cond(nxt)) {\n\
    \                    while (l < size) {\n                        nxt = M::op(vl,\
    \ node[2 * l]);\n                        if (cond(nxt)) l = 2 * l;\n         \
    \               else vl = nxt, l = 2 * l + 1;\n                    }\n       \
    \             return l - size;\n                }\n                vl = nxt;\n\
    \                ++l;\n            }\n        }\n        return -1;\n    }\n\n\
    \    template <typename F>\n    int find_last(int r, F cond) const {\n       \
    \ T vr = M::id;\n        int l = 0;\n        for (l += size, r += size; l < r;\
    \ l >>= 1, r >>= 1) {\n            if (r & 1) {\n                --r;\n      \
    \          T nxt = M::op(node[r], vr);\n                if (cond(nxt)) {\n   \
    \                 while (r < size) {\n                        nxt = M::op(node[2\
    \ * r + 1], vr);\n                        if (cond(nxt)) r = 2 * r + 1;\n    \
    \                    else vr = nxt, r = 2 * r;\n                    }\n      \
    \              return r - size;\n                }\n                vr = nxt;\n\
    \            }\n        }\n        return -1;\n    }\n\nprivate:\n    int size;\n\
    \    std::vector<T> node;\n};\n#line 4 \"test/aoj/DSL_2_A.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nstruct Monoid {\n    using T = int;\n\
    \    static constexpr T id = (1u << 31) - 1;\n    static T op(T a, T b) {\n  \
    \      return min(a, b);\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    SegmentTree<Monoid>\
    \ st(n);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin\
    \ >> com >> x >> y;\n        if (com == 0) st.update(x, y);\n        else cout\
    \ << st.fold(x, y + 1) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A\"\
    \n\n#include \"../../data-structure/segtree/segment_tree.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct Monoid {\n    using T = int;\n    static constexpr\
    \ T id = (1u << 31) - 1;\n    static T op(T a, T b) {\n        return min(a, b);\n\
    \    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int n, q;\n    cin >> n >> q;\n    SegmentTree<Monoid> st(n);\n    for (int\
    \ i = 0; i < q; i++) {\n        int com, x, y;\n        cin >> com >> x >> y;\n\
    \        if (com == 0) st.update(x, y);\n        else cout << st.fold(x, y + 1)\
    \ << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/segtree/segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-04-29 16:04:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.test.cpp
- /verify/test/aoj/DSL_2_A.test.cpp.html
title: test/aoj/DSL_2_A.test.cpp
---
