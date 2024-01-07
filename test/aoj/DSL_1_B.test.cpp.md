---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/weighted_union_find.hpp
    title: Weighted Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B
  bundledCode: "#line 1 \"test/aoj/DSL_1_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#line 2 \"data-structure/unionfind/weighted_union_find.hpp\"\n#include <algorithm>\n\
    #include <vector>\n\ntemplate <typename T>\nclass WeightedUnionFind {\n   public:\n\
    \    WeightedUnionFind() = default;\n    explicit WeightedUnionFind(int n) : data(n,\
    \ -1), ws(n) {}\n\n    int find(int x) {\n        if (data[x] < 0) return x;\n\
    \        int r = find(data[x]);\n        ws[x] += ws[data[x]];\n        return\
    \ data[x] = r;\n    }\n\n    T weight(int x) {\n        find(x);\n        return\
    \ ws[x];\n    }\n\n    bool unite(int x, int y, T w) {\n        w += weight(x);\n\
    \        w -= weight(y);\n        x = find(x);\n        y = find(y);\n       \
    \ if (x == y) return false;\n        if (data[x] > data[y]) {\n            std::swap(x,\
    \ y);\n            w = -w;\n        }\n        data[x] += data[y];\n        data[y]\
    \ = x;\n        ws[y] = w;\n        return true;\n    }\n\n    bool same(int x,\
    \ int y) { return find(x) == find(y); }\n\n    T diff(int x, int y) { return weight(y)\
    \ - weight(x); }\n\n    int size(int x) { return -data[find(x)]; }\n\n   private:\n\
    \    std::vector<int> data;\n    std::vector<T> ws;\n};\n#line 4 \"test/aoj/DSL_1_B.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    WeightedUnionFind<int>\
    \ wuf(n);\n    for (int i = 0; i < q; i++) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int x, y, z;\n            cin >> x >> y >>\
    \ z;\n            wuf.unite(x, y, z);\n        } else {\n            int x, y;\n\
    \            cin >> x >> y;\n            if (wuf.same(x, y)) cout << wuf.diff(x,\
    \ y) << \"\\n\";\n            else cout << \"?\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B\"\
    \n\n#include \"../../data-structure/unionfind/weighted_union_find.hpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n, q;\n    cin >> n >> q;\n    WeightedUnionFind<int>\
    \ wuf(n);\n    for (int i = 0; i < q; i++) {\n        int t;\n        cin >> t;\n\
    \        if (t == 0) {\n            int x, y, z;\n            cin >> x >> y >>\
    \ z;\n            wuf.unite(x, y, z);\n        } else {\n            int x, y;\n\
    \            cin >> x >> y;\n            if (wuf.same(x, y)) cout << wuf.diff(x,\
    \ y) << \"\\n\";\n            else cout << \"?\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - data-structure/unionfind/weighted_union_find.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:49:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_B.test.cpp
- /verify/test/aoj/DSL_1_B.test.cpp.html
title: test/aoj/DSL_1_B.test.cpp
---
