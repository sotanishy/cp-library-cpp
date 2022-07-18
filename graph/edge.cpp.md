---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/minimum_spanning_arborescence.cpp
    title: Minimum Spanning Arborescence
  - icon: ':heavy_check_mark:'
    path: graph/minimum_steiner_tree.hpp
    title: Minimum Steiner Tree
  - icon: ':heavy_check_mark:'
    path: graph/mst.cpp
    title: Minimum Spanning Tree Algorithms
  - icon: ':warning:'
    path: graph/range_edge_graph.cpp
    title: Range Edge Graph
  - icon: ':heavy_check_mark:'
    path: graph/shortest_path.cpp
    title: Shortest Path Algorithms
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: Diameter of a Tree
  - icon: ':heavy_check_mark:'
    path: tree/tree_hash.hpp
    title: Tree Hashing
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1040.test.cpp
    title: test/aoj/1040.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2821.test.cpp
    title: test/aoj/2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_B.test.cpp
    title: test/aoj/GRL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_C.test.cpp
    title: test/aoj/GRL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.boruvka.test.cpp
    title: test/aoj/GRL_2_A.boruvka.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.kruskal.test.cpp
    title: test/aoj/GRL_2_A.kruskal.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.prim.test.cpp
    title: test/aoj/GRL_2_A.prim.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n\
    \    int from, to;\n    T weight;\n    Edge() = default;\n    Edge(int to, T weight)\
    \ : from(-1), to(to), weight(weight) {}\n    Edge(int from, int to, T weight)\
    \ : from(from), to(to), weight(weight) {}\n};\n"
  code: "#pragma once\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n\
    \    T weight;\n    Edge() = default;\n    Edge(int to, T weight) : from(-1),\
    \ to(to), weight(weight) {}\n    Edge(int from, int to, T weight) : from(from),\
    \ to(to), weight(weight) {}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/edge.cpp
  requiredBy:
  - graph/mst.cpp
  - graph/shortest_path.cpp
  - graph/range_edge_graph.cpp
  - graph/minimum_spanning_arborescence.cpp
  - graph/minimum_steiner_tree.hpp
  - tree/tree_diameter.cpp
  - tree/tree_hash.hpp
  timestamp: '2021-02-09 14:52:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_1_B.test.cpp
  - test/aoj/GRL_2_A.boruvka.test.cpp
  - test/aoj/GRL_5_A.test.cpp
  - test/aoj/2821.test.cpp
  - test/aoj/GRL_2_A.prim.test.cpp
  - test/aoj/GRL_2_A.kruskal.test.cpp
  - test/aoj/GRL_1_C.test.cpp
  - test/aoj/GRL_1_A.test.cpp
  - test/aoj/1040.test.cpp
  - test/yosupo/tree_diameter.test.cpp
  - test/yosupo/directedmst.test.cpp
documentation_of: graph/edge.cpp
layout: document
redirect_from:
- /library/graph/edge.cpp
- /library/graph/edge.cpp.html
title: graph/edge.cpp
---
