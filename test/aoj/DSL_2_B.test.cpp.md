---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick_tree.hpp
    title: Fenwick Tree
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
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.test.cpp\"\n#define PROBLEM \\\n    \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 4 \"data-structure/fenwick_tree.hpp\"\n\ntemplate <typename\
    \ M>\nclass FenwickTree {\n    using T = M::T;\n\n   public:\n    FenwickTree()\
    \ = default;\n    explicit FenwickTree(int n) : n(n), data(n + 1, M::id()) {}\n\
    \n    T prefix_fold(int i) const {\n        T ret = M::id();\n        for (; i\
    \ > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return ret;\n    }\n\n\
    \    void update(int i, const T& x) {\n        for (++i; i <= n; i += i & -i)\
    \ data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const T& x) const\
    \ { return lower_bound(x, std::less<>()); }\n\n    template <typename Compare>\n\
    \    int lower_bound(const T& x, Compare cmp) const {\n        if (!cmp(M::id(),\
    \ x)) return 0;\n        int k = 1;\n        while (k * 2 <= n) k <<= 1;\n   \
    \     int i = 0;\n        T v = M::id();\n        for (; k > 0; k >>= 1) {\n \
    \           if (i + k > n) continue;\n            T nv = M::op(v, data[i + k]);\n\
    \            if (cmp(nv, x)) {\n                v = nv;\n                i +=\
    \ k;\n            }\n        }\n        return i + 1;\n    }\n\n   private:\n\
    \    int n;\n    std::vector<T> data;\n};\n#line 7 \"test/aoj/DSL_2_B.test.cpp\"\
    \nusing namespace std;\n\nstruct Monoid {\n    using T = int;\n    static T id()\
    \ { return 0; }\n    static T op(T a, T b) { return a + b; }\n};\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n, q;\n\
    \    cin >> n >> q;\n    FenwickTree<Monoid> ft(n);\n    for (int i = 0; i < q;\
    \ i++) {\n        int com, x, y;\n        cin >> com >> x >> y;\n        if (com\
    \ == 0)\n            ft.update(x - 1, y);\n        else\n            cout << (ft.prefix_fold(y)\
    \ - ft.prefix_fold(x - 1)) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../data-structure/fenwick_tree.hpp\"\
    \nusing namespace std;\n\nstruct Monoid {\n    using T = int;\n    static T id()\
    \ { return 0; }\n    static T op(T a, T b) { return a + b; }\n};\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n, q;\n\
    \    cin >> n >> q;\n    FenwickTree<Monoid> ft(n);\n    for (int i = 0; i < q;\
    \ i++) {\n        int com, x, y;\n        cin >> com >> x >> y;\n        if (com\
    \ == 0)\n            ft.update(x - 1, y);\n        else\n            cout << (ft.prefix_fold(y)\
    \ - ft.prefix_fold(x - 1)) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/fenwick_tree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---
