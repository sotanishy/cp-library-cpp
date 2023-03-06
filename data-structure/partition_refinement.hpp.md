---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/partition_refinement.hpp\"\n#include <algorithm>\n\
    #include <map>\n#include <set>\n#include <vector>\n\nclass PartitionRefinement\
    \ {\n   public:\n    PartitionRefinement() = default;\n    explicit PartitionRefinement(int\
    \ n) : sets(1), cls(n, 0) {\n        for (int i = 0; i < n; ++i) sets[0].insert(i);\n\
    \    }\n\n    int find(int x) { return cls[x]; }\n\n    bool same(int x, int y)\
    \ { return find(x) == find(y); }\n\n    int size(int i) { return sets[i].size();\
    \ }\n\n    std::vector<int> members(int i) {\n        return std::vector<int>(sets[i].begin(),\
    \ sets[i].end());\n    }\n\n    std::vector<std::pair<int, int>> refine(const\
    \ std::vector<int>& pivot) {\n        std::map<int, std::vector<int>> split;\n\
    \        for (auto x : pivot) {\n            int i = cls[x];\n            split[i].push_back(x);\n\
    \            sets[i].erase(x);\n        }\n        std::vector<std::pair<int,\
    \ int>> updated;\n        for (auto& [i, s] : split) {\n            int ni = sets.size();\n\
    \            sets.emplace_back(s.begin(), s.end());\n            if (sets[i].size()\
    \ < sets[ni].size()) {\n                std::swap(sets[i], sets[ni]);\n      \
    \      }\n            if (sets[ni].empty()) {\n                sets.pop_back();\n\
    \                continue;\n            }\n            for (auto x : sets[ni])\
    \ {\n                cls[x] = ni;\n            }\n            updated.push_back({i,\
    \ ni});\n        }\n        return updated;\n    }\n\n   private:\n    std::vector<std::set<int>>\
    \ sets;\n    std::vector<int> cls;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <set>\n#include\
    \ <vector>\n\nclass PartitionRefinement {\n   public:\n    PartitionRefinement()\
    \ = default;\n    explicit PartitionRefinement(int n) : sets(1), cls(n, 0) {\n\
    \        for (int i = 0; i < n; ++i) sets[0].insert(i);\n    }\n\n    int find(int\
    \ x) { return cls[x]; }\n\n    bool same(int x, int y) { return find(x) == find(y);\
    \ }\n\n    int size(int i) { return sets[i].size(); }\n\n    std::vector<int>\
    \ members(int i) {\n        return std::vector<int>(sets[i].begin(), sets[i].end());\n\
    \    }\n\n    std::vector<std::pair<int, int>> refine(const std::vector<int>&\
    \ pivot) {\n        std::map<int, std::vector<int>> split;\n        for (auto\
    \ x : pivot) {\n            int i = cls[x];\n            split[i].push_back(x);\n\
    \            sets[i].erase(x);\n        }\n        std::vector<std::pair<int,\
    \ int>> updated;\n        for (auto& [i, s] : split) {\n            int ni = sets.size();\n\
    \            sets.emplace_back(s.begin(), s.end());\n            if (sets[i].size()\
    \ < sets[ni].size()) {\n                std::swap(sets[i], sets[ni]);\n      \
    \      }\n            if (sets[ni].empty()) {\n                sets.pop_back();\n\
    \                continue;\n            }\n            for (auto x : sets[ni])\
    \ {\n                cls[x] = ni;\n            }\n            updated.push_back({i,\
    \ ni});\n        }\n        return updated;\n    }\n\n   private:\n    std::vector<std::set<int>>\
    \ sets;\n    std::vector<int> cls;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/partition_refinement.hpp
  requiredBy: []
  timestamp: '2023-03-06 14:13:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/partition_refinement.hpp
layout: document
title: Partition Refinement
---

## Description

Partition refinement は，素集合を管理するデータ構造である．Union find が集合の併合を処理するのに対し，partition refinement は集合の分割を処理する．

DFA 最小化などに用いられる．

空間計算量: $O(n)$

## Operations

- `PartitionRefinement(int n)`
    - 集合を $\{0,1,\dots, n-1\}$ で初期化する．
    - 時間計算量: $O(n)$
- `int find(int x)`
    - $x$ が属する集合の番号を返す
    - 時間計算量: $O(1)$
- `bool same(int x, int y)`
    - $x$ と $y$ が同じ集合に属するかを判定する
    - 時間計算量: $O(1)$
- `int size(int i)`
    - 集合 $i$ の要素数を返す
    - 時間計算量: $O(1)$
- `vector<int> members(int i)`
    - 集合 $i$ の要素のリストを返す
    - 時間計算量: $O(\vert S_i \vert)$
- `vector<pair<int, int>> refine(vector<int> pivot)`
    - 与えられたピボット $P$ を用いて，各集合 $S_i$ を $S_i \cap P$ と $S_i - P$ に分割する．
    - 分割された集合の番号を返す
    - 時間計算量: $O(\vert P \vert \log n)$

## Note

Refine 操作は $O(\vert P \vert)$ でできるが，実装が面倒なので log をつけている．

DFA 最小化では，集合が分割されたときに要素数が小さい方に注目して，それに遷移してくる集合をさらに分割するということを繰り返す．計算量は，逆マージテクの要領で解析でき，遷移の数を $m$ として $O(m \log^2 n)$ (refine 操作を線形時間で行えば $O(m \log n)$) となる．

## Reference

- [Partition refinement - TryAlgo](https://tryalgo.org/en/data%20structures/2016/09/16/partition-refinement/)
- [DFA minimization - Wikpedia](https://tryalgo.org/en/data%20structures/2016/09/16/partition-refinement/)
- verify: [https://atcoder.jp/contests/tupc2022/submissions/39481650](https://atcoder.jp/contests/tupc2022/submissions/39481650)