---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/offline_dynamic_connectivity.cpp
    title: Offline Dynamic Connectivity
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
    title: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structures/unionfind/undoable_union_find.md
    document_title: Undoable Union Find
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/undoable_union_find.cpp\"\n#include\
    \ <algorithm>\n#include <cassert>\n#include <stack>\n#include <utility>\n#include\
    \ <vector>\n\n/*\n * @brief Undoable Union Find\n * @docs docs/data-structures/unionfind/undoable_union_find.md\n\
    \ */\ntemplate <typename M>\nclass UndoableUnionFind {\n    using T = typename\
    \ M::T;\n\npublic:\n    UndoableUnionFind() = default;\n    explicit UndoableUnionFind(int\
    \ n) : UndoableUnionFind(std::vector<T>(n, M::id)) {}\n    explicit UndoableUnionFind(const\
    \ std::vector<T>& v)\n        : data(v.size(), -1), val(v.begin(), v.end()) {}\n\
    \n    int find(int x) const {\n        if (data[x] < 0) return x;\n        return\
    \ find(data[x]);\n    }\n\n    void unite(int x, int y) {\n        x = find(x);\n\
    \        y = find(y);\n        history.emplace(-1, 0, M::id);\n        history.emplace(x,\
    \ data[x], val[x]);\n        history.emplace(y, data[y], val[y]);\n        if\
    \ (x == y) return;\n        if (data[x] > data[y]) std::swap(x, y);\n        data[x]\
    \ += data[y];\n        data[y] = x;\n        val[x] = M::op(val[x], val[y]);\n\
    \    }\n\n    void undo() {\n        assert(!history.empty());\n        while\
    \ (true) {\n            auto [x, dx, vx] = history.top();\n            history.pop();\n\
    \            if (x == -1) break;\n            data[x] = dx;\n            val[x]\
    \ = vx;\n        }\n    }\n\n    bool same(int x, int y) const {\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) const {\n        return -data[find(x)];\n\
    \    }\n\n    T component_fold(int x) const {\n        return val[find(x)];\n\
    \    }\n\n    void update(int x, const T& v) {\n        x = find(x);\n       \
    \ history.emplace(-1, 0, M::id);\n        history.emplace(x, data[x], val[x]);\n\
    \        val[x] = M::op(val[x], v);\n    }\n\nprivate:\n    std::vector<int> data;\n\
    \    std::vector<T> val;\n    std::stack<std::tuple<int, int, T>> history;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <stack>\n\
    #include <utility>\n#include <vector>\n\n/*\n * @brief Undoable Union Find\n *\
    \ @docs docs/data-structures/unionfind/undoable_union_find.md\n */\ntemplate <typename\
    \ M>\nclass UndoableUnionFind {\n    using T = typename M::T;\n\npublic:\n   \
    \ UndoableUnionFind() = default;\n    explicit UndoableUnionFind(int n) : UndoableUnionFind(std::vector<T>(n,\
    \ M::id)) {}\n    explicit UndoableUnionFind(const std::vector<T>& v)\n      \
    \  : data(v.size(), -1), val(v.begin(), v.end()) {}\n\n    int find(int x) const\
    \ {\n        if (data[x] < 0) return x;\n        return find(data[x]);\n    }\n\
    \n    void unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        history.emplace(-1, 0, M::id);\n        history.emplace(x, data[x], val[x]);\n\
    \        history.emplace(y, data[y], val[y]);\n        if (x == y) return;\n \
    \       if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n        val[x] = M::op(val[x], val[y]);\n    }\n\n    void\
    \ undo() {\n        assert(!history.empty());\n        while (true) {\n      \
    \      auto [x, dx, vx] = history.top();\n            history.pop();\n       \
    \     if (x == -1) break;\n            data[x] = dx;\n            val[x] = vx;\n\
    \        }\n    }\n\n    bool same(int x, int y) const {\n        return find(x)\
    \ == find(y);\n    }\n\n    int size(int x) const {\n        return -data[find(x)];\n\
    \    }\n\n    T component_fold(int x) const {\n        return val[find(x)];\n\
    \    }\n\n    void update(int x, const T& v) {\n        x = find(x);\n       \
    \ history.emplace(-1, 0, M::id);\n        history.emplace(x, data[x], val[x]);\n\
    \        val[x] = M::op(val[x], v);\n    }\n\nprivate:\n    std::vector<int> data;\n\
    \    std::vector<T> val;\n    std::stack<std::tuple<int, int, T>> history;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind/undoable_union_find.cpp
  requiredBy:
  - graph/offline_dynamic_connectivity.cpp
  timestamp: '2020-10-26 19:52:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
documentation_of: data-structure/unionfind/undoable_union_find.cpp
layout: document
redirect_from:
- /library/data-structure/unionfind/undoable_union_find.cpp
- /library/data-structure/unionfind/undoable_union_find.cpp.html
title: Undoable Union Find
---
