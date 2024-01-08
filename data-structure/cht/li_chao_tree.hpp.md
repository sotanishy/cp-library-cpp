---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.lct.test.cpp
    title: test/yosupo/line_add_get_min.lct.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/cht/li_chao_tree.hpp\"\n#include <algorithm>\n\
    #include <bit>\n#include <limits>\n#include <utility>\n#include <vector>\n\ntemplate\
    \ <typename T>\nclass LiChaoTree {\n   public:\n    LiChaoTree() = default;\n\
    \    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {\n        std::ranges::sort(xs);\n\
    \        xs.erase(std::ranges::unique(xs).begin(), xs.end());\n        size =\
    \ std::bit_ceil(xs.size());\n        node.resize(2 * size, {0, INF});\n      \
    \  while ((int)xs.size() <= size) xs.push_back(xs.back() + 1);\n    }\n\n    void\
    \ add_line(T a, T b) { update({a, b}, 1, 0, size); }\n\n    void add_segment(T\
    \ a, T b, T xl, T xr) {\n        int l = std::ranges::lower_bound(xs, xl) - xs.begin();\n\
    \        int r = std::ranges::lower_bound(xs, xr) - xs.begin();\n\n        Line\
    \ line(a, b);\n        int len = 1;\n        int l0 = l, r0 = r;\n        for\
    \ (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {\n            if\
    \ (l & 1) {\n                update(line, l++, l0, l0 + len);\n              \
    \  ++l;\n                l0 += len;\n            }\n            if (r & 1) {\n\
    \                --r;\n                r0 -= len;\n                update(line,\
    \ r, r0, r0 + len);\n            }\n        }\n    }\n\n    T get(T x) const {\n\
    \        int k = std::ranges::lower_bound(xs, x) - xs.begin();\n        k += size;\n\
    \        T res = node[k](x);\n        while (k >>= 1) res = std::min(res, node[k](x));\n\
    \        return res;\n    }\n\n   private:\n    struct Line {\n        T a, b;\n\
    \        Line(T a, T b) : a(a), b(b) {}\n        T operator()(T x) const { return\
    \ a * x + b; }\n    };\n\n    static constexpr T INF = std::numeric_limits<T>::max();\n\
    \n    int size;\n    std::vector<T> xs;\n    std::vector<Line> node;\n\n    void\
    \ update(Line line, int k, int l, int r) {\n        while (true) {\n         \
    \   int m = std::midpoint(l, r);\n            bool left = line(xs[l]) < node[k](xs[l]);\n\
    \            bool mid = line(xs[m]) < node[k](xs[m]);\n            bool right\
    \ = line(xs[r]) < node[k](xs[r]);\n\n            if (!left && !right) break;\n\
    \            if (left && right) {\n                node[k] = line;\n         \
    \       break;\n            }\n            if (mid) std::swap(node[k], line);\n\
    \            if (r - l == 1) break;\n            if (left != mid) {\n        \
    \        k = 2 * k;\n                r = m;\n            } else {\n          \
    \      k = 2 * k + 1;\n                l = m;\n            }\n        }\n    }\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <limits>\n#include\
    \ <utility>\n#include <vector>\n\ntemplate <typename T>\nclass LiChaoTree {\n\
    \   public:\n    LiChaoTree() = default;\n    explicit LiChaoTree(const std::vector<T>&\
    \ vs) : xs(vs) {\n        std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n        size = std::bit_ceil(xs.size());\n        node.resize(2\
    \ * size, {0, INF});\n        while ((int)xs.size() <= size) xs.push_back(xs.back()\
    \ + 1);\n    }\n\n    void add_line(T a, T b) { update({a, b}, 1, 0, size); }\n\
    \n    void add_segment(T a, T b, T xl, T xr) {\n        int l = std::ranges::lower_bound(xs,\
    \ xl) - xs.begin();\n        int r = std::ranges::lower_bound(xs, xr) - xs.begin();\n\
    \n        Line line(a, b);\n        int len = 1;\n        int l0 = l, r0 = r;\n\
    \        for (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {\n  \
    \          if (l & 1) {\n                update(line, l++, l0, l0 + len);\n  \
    \              ++l;\n                l0 += len;\n            }\n            if\
    \ (r & 1) {\n                --r;\n                r0 -= len;\n              \
    \  update(line, r, r0, r0 + len);\n            }\n        }\n    }\n\n    T get(T\
    \ x) const {\n        int k = std::ranges::lower_bound(xs, x) - xs.begin();\n\
    \        k += size;\n        T res = node[k](x);\n        while (k >>= 1) res\
    \ = std::min(res, node[k](x));\n        return res;\n    }\n\n   private:\n  \
    \  struct Line {\n        T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n  \
    \      T operator()(T x) const { return a * x + b; }\n    };\n\n    static constexpr\
    \ T INF = std::numeric_limits<T>::max();\n\n    int size;\n    std::vector<T>\
    \ xs;\n    std::vector<Line> node;\n\n    void update(Line line, int k, int l,\
    \ int r) {\n        while (true) {\n            int m = std::midpoint(l, r);\n\
    \            bool left = line(xs[l]) < node[k](xs[l]);\n            bool mid =\
    \ line(xs[m]) < node[k](xs[m]);\n            bool right = line(xs[r]) < node[k](xs[r]);\n\
    \n            if (!left && !right) break;\n            if (left && right) {\n\
    \                node[k] = line;\n                break;\n            }\n    \
    \        if (mid) std::swap(node[k], line);\n            if (r - l == 1) break;\n\
    \            if (left != mid) {\n                k = 2 * k;\n                r\
    \ = m;\n            } else {\n                k = 2 * k + 1;\n               \
    \ l = m;\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/line_add_get_min.lct.test.cpp
documentation_of: data-structure/cht/li_chao_tree.hpp
layout: document
title: Li Chao Tree
---

## Description

Li Chao tree は，直線及び線分の集合をセグメント木で管理し，与えられた $x$ 座標での最小値を取得するデータ構造である．

## Operations

- `LiChaoTree(vector<T> xs)`
    - クエリに用いる $x$ 座標を受け取り，Li Chao tree を構築する
    - 時間計算量: $O(n)$
- `void add_line(T a, T b)`
    - 直線 $y = ax + b$ を追加する
    - 時間計算量: $O(\log n)$
- `void add_segment(T a, T b, T xl, T xr)`
    - 線分 $y = ax + b \quad (x \in [x_l, x_r))$ を追加する
    - 時間計算量: $O(\log^2 n)$
- `T get(T x)`
    - $x$ での最小値を取得する
    - 時間計算量: $O(\log n)$

## Reference

- [Li Chao Treeのメモ](https://smijake3.hatenablog.com/entry/2018/06/16/144548)