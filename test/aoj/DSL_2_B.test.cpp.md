---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick_tree.cpp
    title: Fenwick Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B
  bundledCode: "#line 1 \"test/aoj/DSL_2_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#line 1 \"data-structure/fenwick_tree.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n/*\n * @brief Fenwick Tree\n * @docs docs/data-structure/fenwick_tree.md\n\
    \ */\ntemplate <typename M>\nclass FenwickTree {\n    using T = typename M::T;\n\
    \npublic:\n    FenwickTree() = default;\n    explicit FenwickTree(int n) : n(n),\
    \ data(n + 1, M::id) {}\n\n    T prefix_fold(int i) const {\n        T ret = M::id;\n\
    \        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return\
    \ ret;\n    }\n\n    void update(int i, T x) {\n        for (++i; i <= n; i +=\
    \ i & -i) data[i] = M::op(data[i], x);\n    }\n\n    int find_first(const std::function<bool(T)>&\
    \ cond) const {\n        int k = 1;\n        while (k * 2 <= n) k <<= 1;\n   \
    \     int i = 0;\n        T x = M::id;\n        for (; k > 0; k >>= 1) {\n   \
    \         if (i + k <= n && !cond(M::op(x, data[i + k]))) {\n                x\
    \ = M::op(x, data[i + k]);\n                i += k;\n            }\n        }\n\
    \        return i - 1;\n    }\n\nprivate:\n    int n;\n    std::vector<T> data;\n\
    };\n#line 4 \"test/aoj/DSL_2_B.test.cpp\"\n\nusing namespace std;\n\nstruct Monoid\
    \ {\n    using T = int;\n    static inline T id = 0;\n    static T op(T a, T b)\
    \ {\n        return a + b;\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    FenwickTree<Monoid>\
    \ ft(n);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin\
    \ >> com >> x >> y;\n        if (com == 0) ft.update(x - 1, y);\n        else\
    \ cout << (ft.prefix_fold(y) - ft.prefix_fold(x - 1)) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B\"\
    \n\n#include \"../../data-structure/fenwick_tree.cpp\"\n\nusing namespace std;\n\
    \nstruct Monoid {\n    using T = int;\n    static inline T id = 0;\n    static\
    \ T op(T a, T b) {\n        return a + b;\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    FenwickTree<Monoid>\
    \ ft(n);\n    for (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin\
    \ >> com >> x >> y;\n        if (com == 0) ft.update(x - 1, y);\n        else\
    \ cout << (ft.prefix_fold(y) - ft.prefix_fold(x - 1)) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/fenwick_tree.cpp
  isVerificationFile: true
  path: test/aoj/DSL_2_B.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_B.test.cpp
- /verify/test/aoj/DSL_2_B.test.cpp.html
title: test/aoj/DSL_2_B.test.cpp
---
