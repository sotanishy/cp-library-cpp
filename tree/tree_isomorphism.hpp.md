---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: Diameter of a Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2821.test.cpp
    title: test/aoj/2821.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree_isomorphism.hpp\"\n#include <algorithm>\n#include\
    \ <map>\n#include <random>\n#include <utility>\n#include <vector>\n#line 2 \"\
    graph/edge.cpp\"\n\ntemplate <typename T>\nstruct Edge {\n    int from, to;\n\
    \    T weight;\n    Edge() = default;\n    Edge(int to, T weight) : from(-1),\
    \ to(to), weight(weight) {}\n    Edge(int from, int to, T weight) : from(from),\
    \ to(to), weight(weight) {}\n};\n#line 6 \"tree/tree_diameter.cpp\"\n\nstd::pair<int,\
    \ std::vector<int>> tree_diameter(const std::vector<std::vector<int>>& G) {\n\
    \    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs, int\
    \ v, int p) -> std::pair<int, int> {\n        std::pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto weight = dfs(dfs, c, v);\n            ++weight.first;\n            if (ret\
    \ < weight) {\n                ret = weight;\n                to[v] = c;\n   \
    \         }\n        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0,\
    \ -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n   \
    \ int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>> tree_diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<int> to(G.size());\n\
    \n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T, int> {\n \
    \       std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n       \
    \     if (e.to == p) continue;\n            auto weight = dfs(dfs, e.to, v);\n\
    \            weight.first += e.weight;\n            if (ret < weight) {\n    \
    \            ret = weight;\n                to[v] = e.to;\n            }\n   \
    \     }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto\
    \ q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n#line 8 \"tree/tree_isomorphism.hpp\"\
    \n\nclass TreeHasher {\npublic:\n    TreeHasher() : rng(rd()), rand(1, mod-1)\
    \ {}\n\n    long long hash_all(const std::vector<std::vector<int>>& G, int root\
    \ = -1) {\n        long long res;\n        if (root == -1) {\n            auto\
    \ [d, path] = tree_diameter(G);\n            res = dfs_all(G, path[d / 2], -1).first;\n\
    \            if (d % 2 == 1) {\n                res = std::min(res, dfs_all(G,\
    \ path[d / 2 + 1], -1).first);\n            }\n        } else {\n            res\
    \ = dfs_all(G, root, -1).first;\n        }\n        return res;\n    }\n\n   \
    \ std::vector<long long> hash_subtrees(const std::vector<std::vector<int>>& G,\
    \ int root) {\n        std::vector<long long> hash(G.size());\n        dfs_subtrees(G,\
    \ hash, root, -1);\n        return hash;\n    }\n\nprivate:\n    static constexpr\
    \ long long mod = (1LL << 61) - 1;\n\n    static inline long long add(long long\
    \ a, long long b) {\n        if ((a += b) >= mod) a -= mod;\n        return a;\n\
    \    }\n\n    static inline long long mul(long long a, long long b) {\n      \
    \  __int128_t c = (__int128_t) a * b;\n        return add(c >> 61, c & mod);\n\
    \    }\n\n    std::random_device rd;\n    std::mt19937_64 rng;\n    std::uniform_int_distribution<long\
    \ long> rand;\n    std::vector<long long> R;\n\n    std::pair<long long, int>\
    \ dfs_all(const std::vector<std::vector<int>>& G, int v, int p) {\n        int\
    \ maxd = 0;\n        std::vector<long long> hash;\n        for (int c : G[v])\
    \ {\n            if (c != p) {\n                auto [h, d] = dfs_all(G, c, v);\n\
    \                maxd = std::max(maxd, d + 1);\n                hash.push_back(h);\n\
    \            }\n        }\n        if ((int) R.size() == maxd) {\n           \
    \ R.push_back(rand(rng));\n        }\n        long long res = 1;\n        for\
    \ (auto h : hash) {\n            res = mul(res, add(R[maxd], h));\n        }\n\
    \        return {res, maxd};\n    }\n\n    int dfs_subtrees(const std::vector<std::vector<int>>&\
    \ G, std::vector<long long>& hash, int v, int p) {\n        int maxd = 0;\n  \
    \      for (int c : G[v]) {\n            if (c != p) {\n                maxd =\
    \ std::max(maxd, dfs_subtrees(G, hash, c, v) + 1);\n            }\n        }\n\
    \        if ((int) R.size() == maxd) {\n            R.push_back(rand(rng));\n\
    \        }\n        long long res = 1;\n        for (int c : G[v]) {\n       \
    \     if (c != p) {\n                res = mul(res, add(R[maxd], hash[c]));\n\
    \            }\n        }\n        hash[v] = res;\n        return maxd;\n    }\n\
    };\n\n\nclass TreeEncoder {\npublic:\n    TreeEncoder() {\n        mp[{}] = 0;\n\
    \    }\n\n    std::vector<int> encode(const std::vector<std::vector<int>>& G,\
    \ int root) {\n        std::vector<int> val(G.size());\n        dfs(G, val, root,\
    \ -1);\n        return val;\n    }\n\nprivate:\n    std::map<std::vector<int>,\
    \ int> mp;\n    std::vector<long long> R;\n\n    void dfs(const std::vector<std::vector<int>>&\
    \ G, std::vector<int>& val, int v, int p) {\n        std::vector<int> ch;\n  \
    \      for (int c : G[v]) {\n            if (c != p) {\n                dfs(G,\
    \ val, c, v);\n                ch.push_back(val[c]);\n            }\n        }\n\
    \        std::sort(ch.begin(), ch.end());\n        if (!mp.count(ch)) {\n    \
    \        mp[ch] = mp.size();\n        }\n        val[v] = mp[ch];\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <map>\n#include <random>\n#include\
    \ <utility>\n#include <vector>\n#include \"tree_diameter.cpp\"\n\nclass TreeHasher\
    \ {\npublic:\n    TreeHasher() : rng(rd()), rand(1, mod-1) {}\n\n    long long\
    \ hash_all(const std::vector<std::vector<int>>& G, int root = -1) {\n        long\
    \ long res;\n        if (root == -1) {\n            auto [d, path] = tree_diameter(G);\n\
    \            res = dfs_all(G, path[d / 2], -1).first;\n            if (d % 2 ==\
    \ 1) {\n                res = std::min(res, dfs_all(G, path[d / 2 + 1], -1).first);\n\
    \            }\n        } else {\n            res = dfs_all(G, root, -1).first;\n\
    \        }\n        return res;\n    }\n\n    std::vector<long long> hash_subtrees(const\
    \ std::vector<std::vector<int>>& G, int root) {\n        std::vector<long long>\
    \ hash(G.size());\n        dfs_subtrees(G, hash, root, -1);\n        return hash;\n\
    \    }\n\nprivate:\n    static constexpr long long mod = (1LL << 61) - 1;\n\n\
    \    static inline long long add(long long a, long long b) {\n        if ((a +=\
    \ b) >= mod) a -= mod;\n        return a;\n    }\n\n    static inline long long\
    \ mul(long long a, long long b) {\n        __int128_t c = (__int128_t) a * b;\n\
    \        return add(c >> 61, c & mod);\n    }\n\n    std::random_device rd;\n\
    \    std::mt19937_64 rng;\n    std::uniform_int_distribution<long long> rand;\n\
    \    std::vector<long long> R;\n\n    std::pair<long long, int> dfs_all(const\
    \ std::vector<std::vector<int>>& G, int v, int p) {\n        int maxd = 0;\n \
    \       std::vector<long long> hash;\n        for (int c : G[v]) {\n         \
    \   if (c != p) {\n                auto [h, d] = dfs_all(G, c, v);\n         \
    \       maxd = std::max(maxd, d + 1);\n                hash.push_back(h);\n  \
    \          }\n        }\n        if ((int) R.size() == maxd) {\n            R.push_back(rand(rng));\n\
    \        }\n        long long res = 1;\n        for (auto h : hash) {\n      \
    \      res = mul(res, add(R[maxd], h));\n        }\n        return {res, maxd};\n\
    \    }\n\n    int dfs_subtrees(const std::vector<std::vector<int>>& G, std::vector<long\
    \ long>& hash, int v, int p) {\n        int maxd = 0;\n        for (int c : G[v])\
    \ {\n            if (c != p) {\n                maxd = std::max(maxd, dfs_subtrees(G,\
    \ hash, c, v) + 1);\n            }\n        }\n        if ((int) R.size() == maxd)\
    \ {\n            R.push_back(rand(rng));\n        }\n        long long res = 1;\n\
    \        for (int c : G[v]) {\n            if (c != p) {\n                res\
    \ = mul(res, add(R[maxd], hash[c]));\n            }\n        }\n        hash[v]\
    \ = res;\n        return maxd;\n    }\n};\n\n\nclass TreeEncoder {\npublic:\n\
    \    TreeEncoder() {\n        mp[{}] = 0;\n    }\n\n    std::vector<int> encode(const\
    \ std::vector<std::vector<int>>& G, int root) {\n        std::vector<int> val(G.size());\n\
    \        dfs(G, val, root, -1);\n        return val;\n    }\n\nprivate:\n    std::map<std::vector<int>,\
    \ int> mp;\n    std::vector<long long> R;\n\n    void dfs(const std::vector<std::vector<int>>&\
    \ G, std::vector<int>& val, int v, int p) {\n        std::vector<int> ch;\n  \
    \      for (int c : G[v]) {\n            if (c != p) {\n                dfs(G,\
    \ val, c, v);\n                ch.push_back(val[c]);\n            }\n        }\n\
    \        std::sort(ch.begin(), ch.end());\n        if (!mp.count(ch)) {\n    \
    \        mp[ch] = mp.size();\n        }\n        val[v] = mp[ch];\n    }\n};"
  dependsOn:
  - tree/tree_diameter.cpp
  - graph/edge.cpp
  isVerificationFile: false
  path: tree/tree_isomorphism.hpp
  requiredBy: []
  timestamp: '2022-10-20 22:01:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
  - test/aoj/2821.test.cpp
documentation_of: tree/tree_isomorphism.hpp
layout: document
title: Tree Isomorphism
---

## Description

同型な木に同一のラベルを付与するアルゴリズム．

## Operations

- `TreeHasher`
    - 確率的だが高速．ハッシュを用いている．
    - `long long hash_all(vector<vector<int>> G, int root)`
        - 木 $G$ の隣接リストが与えられたとき，$G$ のハッシュを計算する．`root` が与えられた場合はそれを根とする．そうでない場合は，直径の中心を根とする．直径の中心が複数ある場合は，ハッシュ値が小さくなる方を返す
        - 時間計算量: $O(n)$
    - `vector<long long> hash_subtrees(vector<vector<int>> G, int root)`
        - 木 $G$ の隣接リストが与えられたとき，$G$ の各部分木のハッシュを計算する．
        - 時間計算量: $O(n)$
- `TreeEncoder`
    - 決定的だが低速．AHU algorithm を用いている．
    - `vector<int> encode(vector<vector<int>> G, int root)`
        - 木 $G$ の隣接リストが与えられたとき，$G$ の各部分木のラベルを計算する．
        - 時間計算量: $O(n\log n)$


## Reference

- [Tree Isomorphism - My Algorithm](https://kopricky.github.io/code/Graph/tree_isomorphism.html)
- [根付き木のハッシュ - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2017/02/03/054210)
- [Tree isomorphism](https://logic.pdmi.ras.ru/~smal/files/smal_jass08_slides.pdf)