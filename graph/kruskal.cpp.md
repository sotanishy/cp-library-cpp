---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: data-structure/union_find.cpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/graph/kruskal.md
    document_title: Kruskal's Algorithm
    links: []
  bundledCode: "#line 1 \"graph/kruskal.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"\
    graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n\
    \    T cost;\n    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}\n   \
    \ Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n};\n#line\
    \ 2 \"data-structure/union_find.cpp\"\n\n/*\n * @brief Union Find\n * @docs docs/data-structure/union_find.md\n\
    \ */\nclass UnionFind {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};\n#line 4 \"graph/kruskal.cpp\"\
    \n\n/*\n * @brief Kruskal's Algorithm\n * @docs docs/graph/kruskal.md\n */\ntemplate\
    \ <typename T>\nT kruskal(std::vector<Edge<T>>& G, int V) {\n    std::sort(G.begin(),\
    \ G.end(), [](const auto& e1, const auto& e2) {\n        return e1.cost < e2.cost;\n\
    \    });\n    UnionFind uf(V);\n    T ret = 0;\n    for (auto& e : G) {\n    \
    \    if (!uf.same(e.from, e.to)) {\n            uf.unite(e.from, e.to);\n    \
    \        ret += e.cost;\n        }\n    }\n    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"edge.cpp\"\n#include \"../data-structure/union_find.cpp\"\
    \n\n/*\n * @brief Kruskal's Algorithm\n * @docs docs/graph/kruskal.md\n */\ntemplate\
    \ <typename T>\nT kruskal(std::vector<Edge<T>>& G, int V) {\n    std::sort(G.begin(),\
    \ G.end(), [](const auto& e1, const auto& e2) {\n        return e1.cost < e2.cost;\n\
    \    });\n    UnionFind uf(V);\n    T ret = 0;\n    for (auto& e : G) {\n    \
    \    if (!uf.same(e.from, e.to)) {\n            uf.unite(e.from, e.to);\n    \
    \        ret += e.cost;\n        }\n    }\n    return ret;\n}"
  dependsOn:
  - graph/edge.cpp
  - data-structure/union_find.cpp
  isVerificationFile: false
  path: graph/kruskal.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.kruskal.test.cpp
documentation_of: graph/kruskal.cpp
layout: document
redirect_from:
- /library/graph/kruskal.cpp
- /library/graph/kruskal.cpp.html
title: Kruskal's Algorithm
---
# Kruskal's Algorithm

Kruskal のアルゴリズムは，無向重み付きグラフの最小全域木を求めるアルゴリズムである．

- `T kruskal(vector<Edge<T>>& G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木の重みを求める
    - 時間計算量: $O(E\lg E)$