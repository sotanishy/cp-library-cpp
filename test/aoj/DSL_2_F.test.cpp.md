---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/segtree/lazy_segment_tree.cpp
    title: Segment Tree with Lazy Propagation
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F
  bundledCode: "#line 1 \"test/aoj/DSL_2_F.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#line 2 \"data-structure/segtree/lazy_segment_tree.cpp\"\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <typename M, typename O, typename M::T (*act)(typename\
    \ M::T, typename O::T)>\nclass LazySegmentTree {\n    using T = typename M::T;\n\
    \    using E = typename O::T;\n\npublic:\n    LazySegmentTree() = default;\n \
    \   explicit LazySegmentTree(int n) : LazySegmentTree(std::vector<T>(n, M::id()))\
    \ {}\n    explicit LazySegmentTree(const std::vector<T>& v) {\n        size =\
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
    \        }\n        node[k] = act(node[k], lazy[k]);\n        lazy[k] = O::id();\n\
    \    }\n\n    void update(int a, int b, const E& x, int k, int l, int r) {\n \
    \       push(k);\n        if (r <= a || b <= l) return;\n        if (a <= l &&\
    \ r <= b) {\n            lazy[k] = O::op(lazy[k], x);\n            push(k);\n\
    \            return;\n        }\n        int m = (l + r) / 2;\n        update(a,\
    \ b, x, 2 * k, l, m);\n        update(a, b, x, 2 * k + 1, m, r);\n        node[k]\
    \ = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n    T fold(int a, int b, int\
    \ k, int l, int r) {\n        push(k);\n        if (r <= a || b <= l) return M::id();\n\
    \        if (a <= l && r <= b) return node[k];\n        int m = (l + r) / 2;\n\
    \        return M::op(fold(a, b, 2 * k, l, m),\n                     fold(a, b,\
    \ 2 * k + 1, m, r));\n    }\n};\n#line 4 \"test/aoj/DSL_2_F.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nstruct M {\n    using T = int;\n  \
    \  static T id() { return (1u << 31) - 1; }\n    static T op(T a, T b) {\n   \
    \     return min(a, b);\n    }\n};\n\nstruct O {\n    using T = int;\n    static\
    \ T id() { return (1u << 31) - 1; }\n    static T op(T a, T b) {\n        return\
    \ b;\n    }\n};\n\nM::T act(M::T a, O::T b) {\n    return b;\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n, q;\n\
    \    cin >> n >> q;\n    LazySegmentTree<M, O, act> st(n);\n    for (int i = 0;\
    \ i < q; i++) {\n        int type, s, t;\n        cin >> type >> s >> t;\n   \
    \     if (type == 0) {\n            int x;\n            cin >> x;\n          \
    \  st.update(s, t + 1, x);\n        } else {\n            cout << st.fold(s, t\
    \ + 1) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F\"\
    \n\n#include \"../../data-structure/segtree/lazy_segment_tree.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nstruct M {\n    using T = int;\n  \
    \  static T id() { return (1u << 31) - 1; }\n    static T op(T a, T b) {\n   \
    \     return min(a, b);\n    }\n};\n\nstruct O {\n    using T = int;\n    static\
    \ T id() { return (1u << 31) - 1; }\n    static T op(T a, T b) {\n        return\
    \ b;\n    }\n};\n\nM::T act(M::T a, O::T b) {\n    return b;\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n, q;\n\
    \    cin >> n >> q;\n    LazySegmentTree<M, O, act> st(n);\n    for (int i = 0;\
    \ i < q; i++) {\n        int type, s, t;\n        cin >> type >> s >> t;\n   \
    \     if (type == 0) {\n            int x;\n            cin >> x;\n          \
    \  st.update(s, t + 1, x);\n        } else {\n            cout << st.fold(s, t\
    \ + 1) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/segtree/lazy_segment_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_F.test.cpp
  requiredBy: []
  timestamp: '2022-03-06 20:10:50+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_F.test.cpp
- /verify/test/aoj/DSL_2_F.test.cpp.html
title: test/aoj/DSL_2_F.test.cpp
---
