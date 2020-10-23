---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/union_find.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/kruskal.md
    document_title: Kruskal's Algorithm
    links: []
  bundledCode: "#line 1 \"graph/kruskal.cpp\"\n#include <bits/stdc++.h>\n#line 3 \"\
    graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n\
    \    T weight;\n    Edge(int to, T weight) : from(-1), to(to), weight(weight)\
    \ {}\n    Edge(int from, int to, T weight) : from(from), to(to), weight(weight)\
    \ {}\n};\n#line 4 \"data-structure/unionfind/union_find.cpp\"\n\n/*\n * @brief\
    \ Union Find\n * @docs docs/data-structure/unionfind/union_find.md\n */\nclass\
    \ UnionFind {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};\n#line 4 \"graph/kruskal.cpp\"\
    \n\n/*\n * @brief Kruskal's Algorithm\n * @docs docs/graph/kruskal.md\n */\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>>\
    \ G, int V) {\n    std::sort(G.begin(), G.end(), [](const auto& e1, const auto&\
    \ e2) {\n        return e1.weight < e2.weight;\n    });\n    UnionFind uf(V);\n\
    \    T weight = 0;\n    std::vector<Edge<T>> edges;\n    for (auto& e : G) {\n\
    \        if (!uf.same(e.from, e.to)) {\n            uf.unite(e.from, e.to);\n\
    \            weight += e.weight;\n            edges.push_back(e);\n        }\n\
    \    }\n    return {weight, edges};\n}\n"
  code: "#include <bits/stdc++.h>\n#include \"edge.cpp\"\n#include \"../data-structure/unionfind/union_find.cpp\"\
    \n\n/*\n * @brief Kruskal's Algorithm\n * @docs docs/graph/kruskal.md\n */\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>>\
    \ G, int V) {\n    std::sort(G.begin(), G.end(), [](const auto& e1, const auto&\
    \ e2) {\n        return e1.weight < e2.weight;\n    });\n    UnionFind uf(V);\n\
    \    T weight = 0;\n    std::vector<Edge<T>> edges;\n    for (auto& e : G) {\n\
    \        if (!uf.same(e.from, e.to)) {\n            uf.unite(e.from, e.to);\n\
    \            weight += e.weight;\n            edges.push_back(e);\n        }\n\
    \    }\n    return {weight, edges};\n}"
  dependsOn:
  - graph/edge.cpp
  - data-structure/unionfind/union_find.cpp
  isVerificationFile: false
  path: graph/kruskal.cpp
  requiredBy: []
  timestamp: '2020-10-24 00:37:28+09:00'
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

- `pair<T, vector<Edge<T>>> kruskal(vector<Edge<T>> G, int V)`
    - 頂点数 $V$ のグラフ $G$ の辺のリストが与えられたとき，最小全域木とその重みを求める
    - 時間計算量: $O(E\lg V)$