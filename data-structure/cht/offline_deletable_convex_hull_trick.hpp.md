---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: data-structure/cht/undoable_li_chao_tree.hpp
    title: Undoable Li Chao Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/cht/offline_deletable_convex_hull_trick.hpp\"\
    \n#include <bit>\n#include <cassert>\n#include <map>\n#include <utility>\n#include\
    \ <vector>\n\n#line 2 \"data-structure/cht/undoable_li_chao_tree.hpp\"\n#include\
    \ <algorithm>\n#line 5 \"data-structure/cht/undoable_li_chao_tree.hpp\"\n#include\
    \ <limits>\n#line 8 \"data-structure/cht/undoable_li_chao_tree.hpp\"\n\n/**\n\
    \ * @brief Undoable Li Chao Tree\n */\ntemplate <typename T>\nclass UndoableLiChaoTree\
    \ {\n   public:\n    UndoableLiChaoTree() = default;\n    explicit UndoableLiChaoTree(const\
    \ std::vector<T>& vs) : xs(vs) {\n        std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n        size = std::bit_ceil(xs.size());\n        node.resize(2\
    \ * size, {0, INF});\n        while ((int)xs.size() <= size) xs.push_back(xs.back()\
    \ + 1);\n    }\n\n    void add(T a, T b) {\n        history.emplace_back(-1, Line(0,\
    \ 0));\n        Line line(a, b);\n        int k = 1, l = 0, r = size;\n      \
    \  while (true) {\n            int m = std::midpoint(l, r);\n            bool\
    \ left = line(xs[l]) < node[k](xs[l]);\n            bool mid = line(xs[m]) < node[k](xs[m]);\n\
    \            bool right = line(xs[r]) < node[k](xs[r]);\n\n            if (!left\
    \ && !right) break;\n            if (left && right) {\n                history.emplace_back(k,\
    \ node[k]);\n                node[k] = line;\n                break;\n       \
    \     }\n            if (mid) {\n                history.emplace_back(k, node[k]);\n\
    \                std::swap(node[k], line);\n            }\n            if (r -\
    \ l == 1) break;\n            if (left != mid) {\n                k = 2 * k;\n\
    \                r = m;\n            } else {\n                k = 2 * k + 1;\n\
    \                l = m;\n            }\n        }\n    }\n\n    T get(T x) const\
    \ {\n        int k = std::ranges::lower_bound(xs, x) - xs.begin();\n        k\
    \ += size;\n        T res = node[k](x);\n        while (k >>= 1) res = std::min(res,\
    \ node[k](x));\n        return res;\n    }\n\n    void undo() {\n        assert(!history.empty());\n\
    \        while (true) {\n            auto [k, line] = history.back();\n      \
    \      history.pop_back();\n            if (k == -1) break;\n            node[k]\
    \ = line;\n        }\n    }\n\n   private:\n    struct Line {\n        T a, b;\n\
    \        Line(T a, T b) : a(a), b(b) {}\n        T operator()(T x) const { return\
    \ a * x + b; }\n    };\n\n    static constexpr T INF = std::numeric_limits<T>::max();\n\
    \n    int size;\n    std::vector<T> xs;\n    std::vector<Line> node;\n    std::vector<std::pair<int,\
    \ Line>> history;\n};\n#line 9 \"data-structure/cht/offline_deletable_convex_hull_trick.hpp\"\
    \n\ntemplate <typename T>\nclass OfflineDeletableConvexHullTrick {\n   public:\n\
    \    void insert(T a, T b) { open.insert({{a, b}, now++}); }\n\n    void erase(T\
    \ a, T b) {\n        auto it = open.find({a, b});\n        assert(it != open.end());\n\
    \        closed.emplace_back(a, b, it->second, now++);\n        open.erase(it);\n\
    \    }\n\n    void get(T x) {\n        query[now++] = x;\n        xs.push_back(x);\n\
    \    }\n\n    std::vector<T> run() {\n        if (xs.empty()) return {};\n\n \
    \       // erase lines\n        for (auto [line, s] : open) {\n            closed.emplace_back(line.first,\
    \ line.second, s, now);\n        }\n\n        // build a segment tree\n      \
    \  int size = std::bit_ceil((unsigned int)now);\n        std::vector<std::vector<std::pair<T,\
    \ T>>> lines(2 * size);\n\n        for (auto [a, b, s, t] : closed) {\n      \
    \      for (s += size, t += size; s < t; s >>= 1, t >>= 1) {\n               \
    \ if (s & 1) lines[s++].emplace_back(a, b);\n                if (t & 1) lines[--t].emplace_back(a,\
    \ b);\n            }\n        }\n\n        // handle queries\n        UndoableLiChaoTree<T>\
    \ lct(xs);\n        std::vector<T> ret;\n\n        auto dfs = [&](const auto&\
    \ dfs, int k) -> void {\n            for (auto [a, b] : lines[k]) {\n        \
    \        lct.add(a, b);\n            }\n            if (k < size) {\n        \
    \        dfs(dfs, 2 * k);\n                dfs(dfs, 2 * k + 1);\n            }\
    \ else if (k < size + now) {\n                if (query.contains(k - size)) {\n\
    \                    ret.push_back(lct.get(query[k - size]));\n              \
    \  }\n            }\n            for (int i = 0; i < (int)lines[k].size(); ++i)\
    \ {\n                lct.undo();\n            }\n        };\n\n        dfs(dfs,\
    \ 1);\n        return ret;\n    }\n\n   private:\n    int now = 0;\n    std::multimap<std::pair<T,\
    \ T>, int> open;\n    std::vector<std::tuple<T, T, int, int>> closed;\n    std::map<int,\
    \ T> query;\n    std::vector<T> xs;\n};\n"
  code: "#pragma once\n#include <bit>\n#include <cassert>\n#include <map>\n#include\
    \ <utility>\n#include <vector>\n\n#include \"undoable_li_chao_tree.hpp\"\n\ntemplate\
    \ <typename T>\nclass OfflineDeletableConvexHullTrick {\n   public:\n    void\
    \ insert(T a, T b) { open.insert({{a, b}, now++}); }\n\n    void erase(T a, T\
    \ b) {\n        auto it = open.find({a, b});\n        assert(it != open.end());\n\
    \        closed.emplace_back(a, b, it->second, now++);\n        open.erase(it);\n\
    \    }\n\n    void get(T x) {\n        query[now++] = x;\n        xs.push_back(x);\n\
    \    }\n\n    std::vector<T> run() {\n        if (xs.empty()) return {};\n\n \
    \       // erase lines\n        for (auto [line, s] : open) {\n            closed.emplace_back(line.first,\
    \ line.second, s, now);\n        }\n\n        // build a segment tree\n      \
    \  int size = std::bit_ceil((unsigned int)now);\n        std::vector<std::vector<std::pair<T,\
    \ T>>> lines(2 * size);\n\n        for (auto [a, b, s, t] : closed) {\n      \
    \      for (s += size, t += size; s < t; s >>= 1, t >>= 1) {\n               \
    \ if (s & 1) lines[s++].emplace_back(a, b);\n                if (t & 1) lines[--t].emplace_back(a,\
    \ b);\n            }\n        }\n\n        // handle queries\n        UndoableLiChaoTree<T>\
    \ lct(xs);\n        std::vector<T> ret;\n\n        auto dfs = [&](const auto&\
    \ dfs, int k) -> void {\n            for (auto [a, b] : lines[k]) {\n        \
    \        lct.add(a, b);\n            }\n            if (k < size) {\n        \
    \        dfs(dfs, 2 * k);\n                dfs(dfs, 2 * k + 1);\n            }\
    \ else if (k < size + now) {\n                if (query.contains(k - size)) {\n\
    \                    ret.push_back(lct.get(query[k - size]));\n              \
    \  }\n            }\n            for (int i = 0; i < (int)lines[k].size(); ++i)\
    \ {\n                lct.undo();\n            }\n        };\n\n        dfs(dfs,\
    \ 1);\n        return ret;\n    }\n\n   private:\n    int now = 0;\n    std::multimap<std::pair<T,\
    \ T>, int> open;\n    std::vector<std::tuple<T, T, int, int>> closed;\n    std::map<int,\
    \ T> query;\n    std::vector<T> xs;\n};"
  dependsOn:
  - data-structure/cht/undoable_li_chao_tree.hpp
  isVerificationFile: false
  path: data-structure/cht/offline_deletable_convex_hull_trick.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cht/offline_deletable_convex_hull_trick.hpp
layout: document
title: Offline Deletable Convex Hull Trick
---

## Description

直線の多重集合に対する以下のクエリをオフラインで処理する:
- 直線の追加
- 直線の削除
- $x$ における最小値の取得

Undo 可能 Li Chao tree を用いて，offline dynamic connectivity の要領でこれを実現する．

空間計算量: $O(q\log q)$

## Operations

- `void add(T a, T b)`
    - 直線 $ax + b$ を追加する
    - 時間計算量: $O(\log q)$
- `void erase(T a, T b)`
    - 直線 $ax + b$ を削除する
    - 時間計算量: $O(\log q)$
- `void get(T x)`
    - $x$ における最小値を取得する
    - 時間計算量: $O(\log q)$
- `vector<T> run()`
    - クエリを実行し，`get`の結果を返す
    - 時間計算量: $O(q\log^2 q)$

## Reference

- [オフライン 削除可能 Convex Hull Trick - procon](https://mugen1337.github.io/procon/DataStructure/DeletableLiChaoTreeOffline.cpp)
- verify: [https://codeforces.com/contest/678/submission/131471122](https://codeforces.com/contest/678/submission/131471122)