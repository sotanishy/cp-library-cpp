---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/persistent_array.cpp
    title: Persistent Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.test.cpp
    title: test/yosupo/persistent_unionfind.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/persistent_union_find.md
    document_title: Persistent Union Find
    links: []
  bundledCode: "#line 1 \"data-structure/persistent_union_find.cpp\"\n#include <bits/stdc++.h>\n\
    #line 2 \"data-structure/persistent_array.cpp\"\n\n/*\n * @brief Persistent Array\n\
    \ * @docs docs/data-structure/persistent_array.md\n */\ntemplate <typename T,\
    \ int B = 2>\nclass PersistentArray {\npublic:\n    PersistentArray() = default;\n\
    \    explicit PersistentArray(const std::vector<T>& v) {\n        for (int i =\
    \ 0; i < (int) v.size(); ++i) root = set(root, i, v[i]);\n    }\n\n    T get(int\
    \ k) const {\n        return get(root, k);\n    }\n\n    PersistentArray set(int\
    \ k, const T& x) const {\n        return PersistentArray(set(root, k, x));\n \
    \   }\n\nprivate:\n    struct Node {\n        T val;\n        std::vector<std::shared_ptr<Node>>\
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
    \ PersistentArray<int, 8>& pa) : data(pa) {}\n};\n"
  code: "#include <bits/stdc++.h>\n#include \"persistent_array.cpp\"\n\n/*\n * @brief\
    \ Persistent Union Find\n * @docs docs/data-structure/persistent_union_find.md\n\
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
    \ PersistentArray<int, 8>& pa) : data(pa) {}\n};"
  dependsOn:
  - data-structure/persistent_array.cpp
  isVerificationFile: false
  path: data-structure/persistent_union_find.cpp
  requiredBy: []
  timestamp: '2020-10-08 11:27:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.test.cpp
documentation_of: data-structure/persistent_union_find.cpp
layout: document
redirect_from:
- /library/data-structure/persistent_union_find.cpp
- /library/data-structure/persistent_union_find.cpp.html
title: Persistent Union Find
---
