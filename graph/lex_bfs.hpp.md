---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/partition_refinement.hpp
    title: Partition Refinement
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/chordal_graph_recognition.hpp
    title: Chordal Graph Recognition
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/chordal_graph_recognition.test.cpp
    title: test/yosupo/chordal_graph_recognition.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/lex_bfs.hpp\"\n#include <set>\n#include <vector>\n\
    \n#line 2 \"data-structure/partition_refinement.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <map>\n#line 7 \"data-structure/partition_refinement.hpp\"\
    \n\nclass PartitionRefinement {\n   public:\n    PartitionRefinement() = default;\n\
    \    explicit PartitionRefinement(int n) : sets(1), cls(n, 0) {\n        for (int\
    \ i = 0; i < n; ++i) sets[0].insert(i);\n    }\n\n    int find(int x) const {\
    \ return cls[x]; }\n\n    bool same(int x, int y) const {\n        int cx = find(x),\
    \ cy = find(y);\n        return cx != -1 && cy != -1 && cx == cy;\n    }\n\n \
    \   bool contains(int x) const { return cls[x] != -1; }\n\n    void erase(int\
    \ x) {\n        if (contains(x)) {\n            sets[cls[x]].erase(x);\n     \
    \       cls[x] = -1;\n        }\n    }\n\n    int size(int i) const { return sets[i].size();\
    \ }\n\n    int member(int i) const {\n        assert(0 <= i && i < (int)sets.size());\n\
    \        return *sets[i].begin();\n    }\n\n    std::vector<int> members(int i)\
    \ const {\n        assert(0 <= i && i < (int)sets.size());\n        return std::vector<int>(sets[i].begin(),\
    \ sets[i].end());\n    }\n\n    std::vector<std::pair<int, int>> refine(const\
    \ std::vector<int>& pivot) {\n        std::map<int, std::vector<int>> split;\n\
    \        for (auto x : pivot) {\n            if (!contains(x)) continue;\n   \
    \         int i = cls[x];\n            split[i].push_back(x);\n            sets[i].erase(x);\n\
    \        }\n        std::vector<std::pair<int, int>> updated;\n        for (auto&\
    \ [i, s] : split) {\n            int ni = sets.size();\n            sets.emplace_back(s.begin(),\
    \ s.end());\n            if (sets[i].size() < sets[ni].size()) {\n           \
    \     std::swap(sets[i], sets[ni]);\n            }\n            if (sets[ni].empty())\
    \ {\n                sets.pop_back();\n                continue;\n           \
    \ }\n            for (auto x : sets[ni]) {\n                cls[x] = ni;\n   \
    \         }\n            updated.push_back({i, ni});\n        }\n        return\
    \ updated;\n    }\n\n   private:\n    std::vector<std::set<int>> sets;\n    std::vector<int>\
    \ cls;\n};\n#line 6 \"graph/lex_bfs.hpp\"\n\nstd::vector<int> lex_bfs(const std::vector<std::vector<int>>&\
    \ G) {\n    const int n = G.size();\n    PartitionRefinement pr(n);\n    std::vector<int>\
    \ prv(1, -1), nxt(1, -1);\n    std::vector<int> ord;\n    int k = 0;\n    for\
    \ (int i = 0; i < n; ++i) {\n        while (pr.size(k) == 0) {\n            k\
    \ = nxt[k];\n        }\n        int x = pr.member(k);\n        ord.push_back(x);\n\
    \        pr.erase(x);\n        std::vector<int> pivot;\n        std::set<int>\
    \ neighbor;\n        for (int y : G[x]) {\n            if (pr.contains(y)) {\n\
    \                pivot.push_back(y);\n                neighbor.insert(y);\n  \
    \          }\n        }\n        for (auto [s, t] : pr.refine(pivot)) {\n    \
    \        if ((int)prv.size() <= t) {\n                prv.resize(t + 1, -1);\n\
    \                nxt.resize(t + 1, -1);\n            }\n            if (neighbor.contains(pr.member(s)))\
    \ {\n                if (nxt[s] >= 0) prv[nxt[s]] = t;\n                nxt[t]\
    \ = nxt[s];\n                prv[t] = s;\n                nxt[s] = t;\n      \
    \      } else {\n                if (prv[s] >= 0) nxt[prv[s]] = t;\n         \
    \       prv[t] = prv[s];\n                prv[s] = t;\n                nxt[t]\
    \ = s;\n            }\n        }\n        if (prv[k] != -1) k = prv[k];\n    }\n\
    \    return ord;\n}\n"
  code: "#pragma once\n#include <set>\n#include <vector>\n\n#include \"../data-structure/partition_refinement.hpp\"\
    \n\nstd::vector<int> lex_bfs(const std::vector<std::vector<int>>& G) {\n    const\
    \ int n = G.size();\n    PartitionRefinement pr(n);\n    std::vector<int> prv(1,\
    \ -1), nxt(1, -1);\n    std::vector<int> ord;\n    int k = 0;\n    for (int i\
    \ = 0; i < n; ++i) {\n        while (pr.size(k) == 0) {\n            k = nxt[k];\n\
    \        }\n        int x = pr.member(k);\n        ord.push_back(x);\n       \
    \ pr.erase(x);\n        std::vector<int> pivot;\n        std::set<int> neighbor;\n\
    \        for (int y : G[x]) {\n            if (pr.contains(y)) {\n           \
    \     pivot.push_back(y);\n                neighbor.insert(y);\n            }\n\
    \        }\n        for (auto [s, t] : pr.refine(pivot)) {\n            if ((int)prv.size()\
    \ <= t) {\n                prv.resize(t + 1, -1);\n                nxt.resize(t\
    \ + 1, -1);\n            }\n            if (neighbor.contains(pr.member(s))) {\n\
    \                if (nxt[s] >= 0) prv[nxt[s]] = t;\n                nxt[t] = nxt[s];\n\
    \                prv[t] = s;\n                nxt[s] = t;\n            } else\
    \ {\n                if (prv[s] >= 0) nxt[prv[s]] = t;\n                prv[t]\
    \ = prv[s];\n                prv[s] = t;\n                nxt[t] = s;\n      \
    \      }\n        }\n        if (prv[k] != -1) k = prv[k];\n    }\n    return\
    \ ord;\n}\n"
  dependsOn:
  - data-structure/partition_refinement.hpp
  isVerificationFile: false
  path: graph/lex_bfs.hpp
  requiredBy:
  - graph/chordal_graph_recognition.hpp
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/chordal_graph_recognition.test.cpp
documentation_of: graph/lex_bfs.hpp
layout: document
title: Lexicographic BFS
---

## Description

辞書順最小幅優先探索 (Lex-BFS) は，グラフ $G$ の頂点の並べ方 $(v_1,v_2,\dots,v_n)$ であって，以下の性質を持つものである．

- 各 $i=1,2,\dots,n$ について，集合 $S_i$ を $S_i=\{j \mid j \lt i, v_j \in N(v_i) \}$ と定義する (ここで， $N(v)$ は頂点 $v$ の隣接頂点の集合である)．列 $(S_1,S_2,\dots,S_n)$ は辞書順の昇順に並んでいる．

Partition refinement を用いて線形時間で実行できる．

## Operations

- `vector<int> lex_bfs(vector<vector<int>> G)`
    - $G$ の頂点を Lex-BFS 順に並べたリストを返す
    - 時間計算量: $O((n+m)\log n)$

## Note

Partition refinement の実装をサボって log をつけているので，この実装でも時間計算量に log がついている．

Lex-BFS はいくつかのグラフクラスの認識のサブルーチンとして用いられる．
- chordal graph
    - [Chordal Graph Recognition](chordal_graph_recognition.md) を参照
    - 任意の長さ $4$ 以上のサイクルが弧 (chord) を持つグラフ
    - Perfect Elimination Ordering を持つ (参考文献参照)
    - Lex-BFS の逆順が PEO になる
- cograph
    - よくわかっていないが，参考文献 (hos さんのスライド) には色々な応用例が載っている

## Reference

- [辞書順幅優先探索Lex BFS（Chordal Graph 5回）- kazu0x17’s diary](https://chocobaby-aporo.hatenablog.com/entry/2018/12/25/011447)
- [Lexicographic breadth-first search - Wikipedia](https://en.wikipedia.org/wiki/Lexicographic_breadth-first_search)
- [グラフ探索アルゴリズムとその応用](http://hos.ac/slides/20110504_graph.pdf)