---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/dynamic_segment_tree.hpp
    title: Dynamic Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\n\n#line 2 \"data-structure/segtree/dynamic_segment_tree.hpp\"\
    \n#include <bit>\n#line 4 \"data-structure/segtree/dynamic_segment_tree.hpp\"\n\
    \ntemplate <typename M>\nclass DynamicSegmentTree {\n    using T = M::T;\n\n \
    \  public:\n    DynamicSegmentTree() = default;\n    explicit DynamicSegmentTree(long\
    \ long n)\n        : root(std::make_unique<Node>()),\n          size(std::bit_ceil((unsigned\
    \ long long)n)) {}\n\n    T operator[](long long k) const { return fold(k, k +\
    \ 1); }\n\n    void update(long long k, const T& x) const { update(k, x, root,\
    \ 0, size); }\n\n    T fold(long long l, long long r) const { return fold(l, r,\
    \ root, 0, size); }\n\n   private:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr left, right;\n        Node()\
    \ : val(M::id()), left(nullptr), right(nullptr) {}\n    };\n\n    const node_ptr\
    \ root;\n    long long size;\n\n    void update(long long k, const T& x, const\
    \ node_ptr& n, long long l,\n                long long r) const {\n        if\
    \ (r - l == 1) {\n            n->val = x;\n            return;\n        }\n  \
    \      long long m = std::midpoint(l, r);\n        if (k < m) {\n            if\
    \ (!n->left) n->left = std::make_unique<Node>();\n            update(k, x, n->left,\
    \ l, m);\n            n->val = M::op(n->left->val, n->right ? n->right->val :\
    \ M::id());\n        } else {\n            if (!n->right) n->right = std::make_unique<Node>();\n\
    \            update(k, x, n->right, m, r);\n            n->val = M::op(n->left\
    \ ? n->left->val : M::id(), n->right->val);\n        }\n    }\n\n    T fold(long\
    \ long a, long long b, const node_ptr& n, long long l,\n           long long r)\
    \ const {\n        if (r <= a || b <= l) return M::id();\n        if (a <= l &&\
    \ r <= b) return n->val;\n        long long m = std::midpoint(l, r);\n       \
    \ T vl = n->left ? fold(a, b, n->left, l, m) : M::id();\n        T vr = n->right\
    \ ? fold(a, b, n->right, m, r) : M::id();\n        return M::op(vl, vr);\n   \
    \ }\n};\n#line 7 \"test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp\"\nusing namespace\
    \ std;\n\nstruct Monoid {\n    using T = int;\n    static T id() { return 0; }\n\
    \    static T op(T a, T b) { return a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    DynamicSegmentTree<Monoid>\
    \ st(n);\n    for (int i = 0; i < q; ++i) {\n        int com, x, y;\n        cin\
    \ >> com >> x >> y;\n        if (com == 0)\n            st.update(x - 1, st[x\
    \ - 1] + y);\n        else\n            cout << st.fold(x - 1, y) << \"\\n\";\n\
    \    }\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/segtree/dynamic_segment_tree.hpp\"\
    \nusing namespace std;\n\nstruct Monoid {\n    using T = int;\n    static T id()\
    \ { return 0; }\n    static T op(T a, T b) { return a + b; }\n};\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n, q;\n\
    \    cin >> n >> q;\n    DynamicSegmentTree<Monoid> st(n);\n    for (int i = 0;\
    \ i < q; ++i) {\n        int com, x, y;\n        cin >> com >> x >> y;\n     \
    \   if (com == 0)\n            st.update(x - 1, st[x - 1] + y);\n        else\n\
    \            cout << st.fold(x - 1, y) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/segtree/dynamic_segment_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:09:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
- /verify/test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp.html
title: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
---
