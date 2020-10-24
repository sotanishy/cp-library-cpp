---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/union_find.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: Kruskal's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\n#define PROBLEM \"\
    http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\n\n#line 2\
    \ \"graph/kruskal.cpp\"\n#include <algorithm>\n#include <utility>\n#include <vector>\n\
    #line 2 \"graph/edge.cpp\"\n#include <bits/stdc++.h>\n\ntemplate <typename T>\n\
    struct Edge {\n    int from, to;\n    T weight;\n    Edge(int to, T weight) :\
    \ from(-1), to(to), weight(weight) {}\n    Edge(int from, int to, T weight) :\
    \ from(from), to(to), weight(weight) {}\n};\n#line 4 \"data-structure/unionfind/union_find.cpp\"\
    \n\n/*\n * @brief Union Find\n * @docs docs/data-structure/unionfind/union_find.md\n\
    \ */\nclass UnionFind {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};\n#line 7 \"graph/kruskal.cpp\"\
    \n\n/*\n * @brief Kruskal's Algorithm\n * @docs docs/graph/kruskal.md\n */\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>>\
    \ G, int V) {\n    std::sort(G.begin(), G.end(), [](const auto& e1, const auto&\
    \ e2) {\n        return e1.weight < e2.weight;\n    });\n    UnionFind uf(V);\n\
    \    T weight = 0;\n    std::vector<Edge<T>> edges;\n    for (auto& e : G) {\n\
    \        if (!uf.same(e.from, e.to)) {\n            uf.unite(e.from, e.to);\n\
    \            weight += e.weight;\n            edges.push_back(e);\n        }\n\
    \    }\n    return {weight, edges};\n}\n#line 4 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\
    \n\n#line 6 \"test/aoj/GRL_2_A.kruskal.test.cpp\"\nusing namespace std;\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ V, E;\n    cin >> V >> E;\n    vector<Edge<int>> edges;\n    for (int i = 0;\
    \ i < E; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n        edges.emplace_back(s,\
    \ t, w);\n    }\n    cout << kruskal(edges, V).first << endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A\"\
    \n\n#include \"../../graph/kruskal.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int V, E;\n    cin >> V >> E;\n    vector<Edge<int>> edges;\n    for (int\
    \ i = 0; i < E; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n  \
    \      edges.emplace_back(s, t, w);\n    }\n    cout << kruskal(edges, V).first\
    \ << endl;\n}"
  dependsOn:
  - graph/kruskal.cpp
  - graph/edge.cpp
  - data-structure/unionfind/union_find.cpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.kruskal.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 15:32:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.kruskal.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp
- /verify/test/aoj/GRL_2_A.kruskal.test.cpp.html
title: test/aoj/GRL_2_A.kruskal.test.cpp
---
