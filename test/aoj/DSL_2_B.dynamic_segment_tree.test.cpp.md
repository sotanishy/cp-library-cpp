---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/dynamic_segment_tree.cpp
    title: Dynamic Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp\"\n#define\
    \ PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#line 1 \"data-structure/dynamic_segment_tree.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Dynamic Segment Tree\n * @docs docs/data-structure/dynamic_segment_tree.md\n\
    \ */\ntemplate <typename M>\nclass DynamicSegmentTree {\n    using T = typename\
    \ M::T;\n\npublic:\n    DynamicSegmentTree() = default;\n    explicit DynamicSegmentTree(int\
    \ n) {\n        size = 1;\n        while (size < n) size <<= 1;\n        root\
    \ = std::make_unique<Node>();\n    }\n\n    T operator[](int k) const {\n    \
    \    return fold(k, k + 1);\n    }\n\n    void update(int k, const T& x) const\
    \ { update(k, x, root, 0, size); }\n\n    T fold(int l, int r) const { return\
    \ fold(l, r, root, 0, size); }\n\nprivate:\n    struct Node {\n        std::unique_ptr<Node>\
    \ left, right;\n        T val;\n        Node() : left(nullptr), right(nullptr),\
    \ val(M::id) {}\n    };\n\n    std::unique_ptr<Node> root;\n    int size;\n\n\
    \    void update(int k, const T& x, std::unique_ptr<Node> const& n, int l, int\
    \ r) const {\n        if (r - l == 1) {\n            n->val = x;\n           \
    \ return;\n        }\n        int m = (l + r) / 2;\n        if (k < m) {\n   \
    \         if (!n->left) n->left = std::make_unique<Node>();\n            update(k,\
    \ x, n->left, l, m);\n            n->val = M::op(n->left->val, n->right ? n->right->val\
    \ : M::id);\n        } else {\n            if (!n->right) n->right = std::make_unique<Node>();\n\
    \            update(k, x, n->right, m, r);\n            n->val = M::op(n->left\
    \ ? n->left->val : M::id, n->right->val);\n        }\n    }\n\n    T fold(int\
    \ a, int b, std::unique_ptr<Node> const& n, int l, int r) const {\n        if\
    \ (r <= a || b <= l) return M::id;\n        if (a <= l && r <= b) return n->val;\n\
    \        int m = (l + r) / 2;\n        T vl = n->left ? fold(a, b, n->left, l,\
    \ m) : M::id;\n        T vr = n->right ? fold(a, b, n->right, m, r) : M::id;\n\
    \        return vl + vr;\n    }\n};\n#line 4 \"test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp\"\
    \n\nusing namespace std;\n\nstruct Monoid {\n    using T = int;\n    static inline\
    \ T id = 0;\n    static T op(T a, T b) {\n        return a + b;\n    }\n};\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ n, q;\n    cin >> n >> q;\n    DynamicSegmentTree<Monoid> st(n);\n    for (int\
    \ i = 0; i < q; ++i) {\n        int com, x, y;\n        cin >> com >> x >> y;\n\
    \        if (com == 0) st.update(x - 1, st[x - 1] + y);\n        else cout <<\
    \ st.fold(x - 1, y) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"../../data-structure/dynamic_segment_tree.cpp\"\n\nusing namespace\
    \ std;\n\nstruct Monoid {\n    using T = int;\n    static inline T id = 0;\n \
    \   static T op(T a, T b) {\n        return a + b;\n    }\n};\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n, q;\n   \
    \ cin >> n >> q;\n    DynamicSegmentTree<Monoid> st(n);\n    for (int i = 0; i\
    \ < q; ++i) {\n        int com, x, y;\n        cin >> com >> x >> y;\n       \
    \ if (com == 0) st.update(x - 1, st[x - 1] + y);\n        else cout << st.fold(x\
    \ - 1, y) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/dynamic_segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 01:39:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
- /verify/test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp.html
title: test/aoj/DSL_2_B.dynamic_segment_tree.test.cpp
---
