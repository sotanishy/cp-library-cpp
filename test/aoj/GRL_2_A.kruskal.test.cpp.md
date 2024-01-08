---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/unionfind/union_find.hpp
    title: Union Find
  - icon: ':question:'
    path: graph/mst.hpp
    title: Minimum Spanning Tree Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\n#define PROBLEM \\\n\
    \    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\n\n\
    #include <bits/stdc++.h>\n\n#line 6 \"graph/mst.hpp\"\n\n#line 4 \"data-structure/unionfind/union_find.hpp\"\
    \n\nclass UnionFind {\n   public:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) { return find(x) ==\
    \ find(y); }\n\n    int size(int x) { return -data[find(x)]; }\n\n   private:\n\
    \    std::vector<int> data;\n};\n#line 8 \"graph/mst.hpp\"\n\ntemplate <typename\
    \ T>\nusing Edge = std::tuple<int, int, T>;\n\n/*\n * Kruskal's Algorithm\n */\n\
    template <typename T>\nstd::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>>\
    \ G, int V) {\n    std::ranges::sort(G, {}, [](auto& e) { return std::get<2>(e);\
    \ });\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>> edges;\n\
    \    for (auto& [u, v, w] : G) {\n        if (!uf.same(u, v)) {\n            uf.unite(u,\
    \ v);\n            weight += w;\n            edges.push_back({u, v, w});\n   \
    \     }\n    }\n    return {weight, edges};\n}\n\n/*\n * Prim's Algorithm\n */\n\
    template <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(\n    const std::vector<std::vector<std::pair<int,\
    \ T>>>& G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto&\
    \ e1, const auto& e2) {\n        return std::get<2>(e1) > std::get<2>(e2);\n \
    \   };\n    std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)>\
    \ pq(cmp);\n    pq.emplace(0, 0, 0);\n    T weight = 0;\n    std::vector<Edge<T>>\
    \ edges;\n    while (!pq.empty()) {\n        auto [p, v, w] = pq.top();\n    \
    \    pq.pop();\n        if (used[v]) continue;\n        used[v] = true;\n    \
    \    weight += w;\n        if (v != 0) edges.push_back({p, v, w});\n        for\
    \ (auto& [u, w2] : G[v]) {\n            pq.emplace(v, u, w2);\n        }\n   \
    \ }\n    return {weight, edges};\n}\n\n/*\n * Boruvka's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> boruvka(std::vector<Edge<T>>\
    \ G, int V) {\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>>\
    \ edges;\n    while (uf.size(0) < V) {\n        std::vector<Edge<T>> cheapest(V,\n\
    \                                      {-1, -1, std::numeric_limits<T>::max()});\n\
    \        for (auto [u, v, w] : G) {\n            if (!uf.same(u, v)) {\n     \
    \           u = uf.find(u);\n                v = uf.find(v);\n               \
    \ if (w < std::get<2>(cheapest[u])) cheapest[u] = {u, v, w};\n               \
    \ if (w < std::get<2>(cheapest[v])) cheapest[v] = {u, v, w};\n            }\n\
    \        }\n        for (auto [u, v, w] : cheapest) {\n            if (u != -1\
    \ && !uf.same(u, v)) {\n                uf.unite(u, v);\n                weight\
    \ += w;\n                edges.push_back({u, v, w});\n            }\n        }\n\
    \    }\n    return {weight, edges};\n}\n#line 7 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int V, E;\n    cin >> V >> E;\n    vector<tuple<int, int,\
    \ int>> edges;\n    for (int i = 0; i < E; i++) {\n        int s, t, w;\n    \
    \    cin >> s >> t >> w;\n        edges.emplace_back(s, t, w);\n    }\n    cout\
    \ << kruskal(edges, V).first << endl;\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../graph/mst.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E;\n    cin >> V >> E;\n    vector<tuple<int, int, int>> edges;\n\
    \    for (int i = 0; i < E; i++) {\n        int s, t, w;\n        cin >> s >>\
    \ t >> w;\n        edges.emplace_back(s, t, w);\n    }\n    cout << kruskal(edges,\
    \ V).first << endl;\n}"
  dependsOn:
  - graph/mst.hpp
  - data-structure/unionfind/union_find.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.kruskal.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp.html
title: test/aoj/GRL_2_A.kruskal.test.cpp
---
