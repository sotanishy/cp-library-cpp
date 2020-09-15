---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union_find.cpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A
  bundledCode: "#line 1 \"test/aoj/DSL_1_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#line 1 \"data-structure/union_find.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n/*\n * @brief Union Find\n * @docs docs/data-structure/union_find.md\n\
    \ */\nstruct UnionFind {\n    vector<int> par;\n\n    UnionFind(int n) : par(n,\
    \ -1) {}\n\n    int find(int x) {\n        if (par[x] < 0) return x;\n       \
    \ return par[x] = find(par[x]);\n    }\n\n    void unite(int x, int y) {\n   \
    \     x = find(x);\n        y = find(y);\n        if (x == y) return;\n      \
    \  if (par[x] > par[y]) swap(x, y);\n        par[x] += par[y];\n        par[y]\
    \ = x;\n    }\n\n    bool same(int x, int y) {\n        return find(x) == find(y);\n\
    \    }\n\n    int size(int x) {\n        return -par[find(x)];\n    }\n};\n#line\
    \ 4 \"test/aoj/DSL_1_A.test.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\
    \    for (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin >> com\
    \ >> x >> y;\n        if (com == 0) uf.unite(x, y);\n        else cout << (uf.same(x,\
    \ y) ? 1 : 0) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A\"\
    \n\n#include \"../../data-structure/union_find.cpp\"\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    UnionFind uf(n);\n\
    \    for (int i = 0; i < q; i++) {\n        int com, x, y;\n        cin >> com\
    \ >> x >> y;\n        if (com == 0) uf.unite(x, y);\n        else cout << (uf.same(x,\
    \ y) ? 1 : 0) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/union_find.cpp
  isVerificationFile: true
  path: test/aoj/DSL_1_A.test.cpp
  requiredBy: []
  timestamp: '2020-09-14 04:40:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_A.test.cpp
- /verify/test/aoj/DSL_1_A.test.cpp.html
title: test/aoj/DSL_1_A.test.cpp
---
