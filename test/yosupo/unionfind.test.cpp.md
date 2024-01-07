---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/unionfind/union_find.hpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/yosupo/unionfind.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\n#line 2 \"data-structure/unionfind/union_find.hpp\"\n#include <algorithm>\n\
    #include <vector>\n\nclass UnionFind {\n   public:\n    UnionFind() = default;\n\
    \    explicit UnionFind(int n) : data(n, -1) {}\n\n    int find(int x) {\n   \
    \     if (data[x] < 0) return x;\n        return data[x] = find(data[x]);\n  \
    \  }\n\n    void unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        if (x == y) return;\n        if (data[x] > data[y]) std::swap(x, y);\n\
    \        data[x] += data[y];\n        data[y] = x;\n    }\n\n    bool same(int\
    \ x, int y) { return find(x) == find(y); }\n\n    int size(int x) { return -data[find(x)];\
    \ }\n\n   private:\n    std::vector<int> data;\n};\n#line 4 \"test/yosupo/unionfind.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n\
    \    for (int i = 0; i < Q; i++) {\n        int t, u, v;\n        cin >> t >>\
    \ u >> v;\n        if (t == 0) uf.unite(u, v);\n        else cout << uf.same(u,\
    \ v) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\n\n#include\
    \ \"../../data-structure/unionfind/union_find.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    UnionFind uf(N);\n\
    \    for (int i = 0; i < Q; i++) {\n        int t, u, v;\n        cin >> t >>\
    \ u >> v;\n        if (t == 0) uf.unite(u, v);\n        else cout << uf.same(u,\
    \ v) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/unionfind/union_find.hpp
  isVerificationFile: true
  path: test/yosupo/unionfind.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:49:49+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/unionfind.test.cpp
- /verify/test/yosupo/unionfind.test.cpp.html
title: test/yosupo/unionfind.test.cpp
---
