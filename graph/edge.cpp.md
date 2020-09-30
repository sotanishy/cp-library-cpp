---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/bellman_ford.cpp
    title: Bellman-Ford Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/dijkstra.cpp
    title: Dijkstra's Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/kruskal.cpp
    title: Kruskal's Algorithm
  - icon: ':heavy_check_mark:'
    path: graph/prim.cpp
    title: Prim's Algorithm
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: Diameter of a Tree
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.prim.test.cpp
    title: test/aoj/GRL_2_A.prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"graph/edge.cpp\"\n#include <bits/stdc++.h>\n\ntemplate <typename\
    \ T>\nstruct Edge {\n    int from, to;\n    T cost;\n    Edge(int to, T cost)\
    \ : from(-1), to(to), cost(cost) {}\n    Edge(int from, int to, T cost) : from(from),\
    \ to(to), cost(cost) {}\n};\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <typename T>\nstruct Edge {\n    int\
    \ from, to;\n    T cost;\n    Edge(int to, T cost) : from(-1), to(to), cost(cost)\
    \ {}\n    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/edge.cpp
  requiredBy:
  - tree/tree_diameter.cpp
  - graph/kruskal.cpp
  - graph/dijkstra.cpp
  - graph/bellman_ford.cpp
  - graph/prim.cpp
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/aoj/GRL_1_A.test.cpp
  - test/aoj/GRL_5_A.test.cpp
  - test/aoj/GRL_2_A.prim.test.cpp
documentation_of: graph/edge.cpp
layout: document
redirect_from:
- /library/graph/edge.cpp
- /library/graph/edge.cpp.html
title: graph/edge.cpp
---
