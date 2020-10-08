---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.cpp
    title: Persistent Array
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_union_find.cpp
    title: Persistent Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/persistent_unionfind
    links:
    - https://judge.yosupo.jp/problem/persistent_unionfind
  bundledCode: "#line 1 \"test/yosupo/persistent_unionfind.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\n#line 1 \"data-structure/persistent_union_find.cpp\"\
    \n#include <bits/stdc++.h>\n#line 2 \"data-structure/persistent_array.cpp\"\n\n\
    /*\n * @brief Persistent Array\n * @docs docs/data-structure/persistent_array.md\n\
    \ */\ntemplate <typename T, int B = 2>\nclass PersistentArray {\npublic:\n   \
    \ PersistentArray() = default;\n    explicit PersistentArray(const std::vector<T>&\
    \ v) {\n        for (int i = 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n\
    \    }\n\n    T get(int k) const {\n        return get(root, k);\n    }\n\n  \
    \  PersistentArray set(int k, const T& x) const {\n        return PersistentArray(set(root,\
    \ k, x));\n    }\n\nprivate:\n    struct Node {\n        T val;\n        std::vector<std::shared_ptr<Node>>\
    \ ch;\n        Node() : ch(B) {}\n    };\n\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    node_ptr root = nullptr;\n\n    explicit PersistentArray(const node_ptr&\
    \ root) : root(root) {}\n\n    T get(const node_ptr& t, int k) const {\n     \
    \   if (k == 0) return t->val;\n        return get(t->ch[k % B], k / B);\n   \
    \ }\n\n    node_ptr set(const node_ptr& t, int k, const T& x) const {\n      \
    \  node_ptr res = t ? std::make_shared<Node>(*t) : std::make_shared<Node>();\n\
    \        if (k == 0) {\n            res->val = x;\n        } else {\n        \
    \    res->ch[k % B] = set(res->ch[k % B], k / B, x);\n        }\n        return\
    \ res;\n    }\n};\n#line 3 \"data-structure/persistent_union_find.cpp\"\n\n/*\n\
    \ * @brief Persistent Union Find\n * @docs docs/data-structure/persistent_union_find.md\n\
    \ */\nclass PersistentUnionFind {\npublic:\n    PersistentUnionFind() = default;\n\
    \    explicit PersistentUnionFind(int n) : data(std::vector<int>(n, -1)) {}\n\n\
    \    int find(int x) const {\n        int p = data.get(x);\n        if (p < 0)\
    \ return x;\n        return find(p);\n    }\n\n    PersistentUnionFind unite(int\
    \ x, int y) const {\n        x = find(x);\n        y = find(y);\n        if (x\
    \ == y) return *this;\n        int u = data.get(x);\n        int v = data.get(y);\n\
    \        if (u > v) std::swap(x, y);\n        auto tmp = data.set(x, u + v);\n\
    \        auto res = tmp.set(y, x);\n        return PersistentUnionFind(res);\n\
    \    }\n\n    bool same(int x, int y) const {\n        return find(x) == find(y);\n\
    \    }\n\n    int size(int x) const {\n        return -data.get(x);\n    }\n\n\
    private:\n    PersistentArray<int, 8> data;\n\n    explicit PersistentUnionFind(const\
    \ PersistentArray<int, 8>& pa) : data(pa) {}\n};\n#line 4 \"test/yosupo/persistent_unionfind.test.cpp\"\
    \n\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    PersistentUnionFind\
    \ init(N);\n    vector<PersistentUnionFind> ver(Q);\n    for (int i = 0; i < Q;\
    \ ++i) {\n        int t, k, u, v;\n        cin >> t >> k >> u >> v;\n        if\
    \ (t == 0) {\n            if (k == -1) ver[i] = init.unite(u, v);\n          \
    \  else ver[i] = ver[k].unite(u, v);\n        } else {\n            int b;\n \
    \           if (k == -1) b = init.same(u, v);\n            else b = ver[k].same(u,\
    \ v);\n            cout << b << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/persistent_unionfind\"\n\
    \n#include \"../../data-structure/persistent_union_find.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    PersistentUnionFind init(N);\n    vector<PersistentUnionFind>\
    \ ver(Q);\n    for (int i = 0; i < Q; ++i) {\n        int t, k, u, v;\n      \
    \  cin >> t >> k >> u >> v;\n        if (t == 0) {\n            if (k == -1) ver[i]\
    \ = init.unite(u, v);\n            else ver[i] = ver[k].unite(u, v);\n       \
    \ } else {\n            int b;\n            if (k == -1) b = init.same(u, v);\n\
    \            else b = ver[k].same(u, v);\n            cout << b << \"\\n\";\n\
    \        }\n    }\n}"
  dependsOn:
  - data-structure/persistent_union_find.cpp
  - data-structure/persistent_array.cpp
  isVerificationFile: true
  path: test/yosupo/persistent_unionfind.test.cpp
  requiredBy: []
  timestamp: '2020-10-08 11:27:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/persistent_unionfind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/persistent_unionfind.test.cpp
- /verify/test/yosupo/persistent_unionfind.test.cpp.html
title: test/yosupo/persistent_unionfind.test.cpp
---
