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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.4/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../data-structure/segtree/segment_tree.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <vector>\n\
    \n#include \"../../data-structure/segtree/segment_tree.cpp\"\n#include \"../../graph/edge.cpp\"\
    \n#include \"../../graph/mst.cpp\"\n\ntemplate <typename U>\nstruct MinMonoid\
    \ {\n    using T = std::pair<U, int>;\n    static T id() { return {std::numeric_limits<U>::max(),\
    \ -1}; }\n    static T op(T a, T b) { return std::min(a, b); }\n};\n\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> manhattan_mst(\n    std::vector<std::pair<T,\
    \ T>> pts) {\n    std::vector<int> idx(pts.size());\n    std::iota(idx.begin(),\
    \ idx.end(), 0);\n\n    std::vector<Edge<T>> edges;\n\n    for (int i = 0; i <\
    \ 2; ++i) {\n        for (int j = 0; j < 2; ++j) {\n            for (int k = 0;\
    \ k < 2; ++k) {\n                // sort by y-x asc then by y desc\n         \
    \       std::sort(idx.begin(), idx.end(), [&](auto& i, auto& j) {\n          \
    \          auto [xi, yi] = pts[i];\n                    auto [xj, yj] = pts[j];\n\
    \                    if (yi - xi != yj - xj) return yi - xi < yj - xj;\n     \
    \               if (yi != yj) return yi > yj;\n                    return i <\
    \ j;\n                });\n\n                // compress y\n                std::vector<T>\
    \ cs;\n                cs.reserve(pts.size());\n                for (auto [x,\
    \ y] : pts) cs.push_back(y);\n                std::sort(cs.begin(), cs.end());\n\
    \                cs.erase(std::unique(cs.begin(), cs.end()), cs.end());\n\n  \
    \              // sweep\n                SegmentTree<MinMonoid<T>> st(cs.size());\n\
    \n                for (int i : idx) {\n                    auto [x, y] = pts[i];\n\
    \                    int k =\n                        std::lower_bound(cs.begin(),\
    \ cs.end(), y) - cs.begin();\n                    auto [d, j] = st.fold(k, cs.size());\n\
    \                    if (j != -1) {\n                        edges.push_back(Edge<T>(i,\
    \ j, d - (x + y)));\n                    }\n                    st.update(k, {x\
    \ + y, i});\n                }\n\n                for (auto& p : pts) std::swap(p.first,\
    \ p.second);\n            }\n            for (auto& p : pts) p.first *= -1;\n\
    \        }\n        for (auto& p : pts) p.second *= -1;\n    }\n\n    return kruskal(edges,\
    \ pts.size());\n}"
  dependsOn: []
  isVerificationFile: false
  path: graph/manhattan_mst.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/manhattan_mst.hpp
layout: document
title: Manhattan Minimum Spanning Tree
---

## Description

2次元平面上に点が与えられ，各点の間にそのマンハッタン距離の重みを持つ辺が張られているとき，最小全域木を計算する．

## Operations

- `vector<T, Edge<T>> manhattan_mst(vector<pair<T, T>> pts)`
    - `pts` の点からなるグラフの最小全域木を求める
    - 時間計算量: $O(n\log n)$

## Reference

- [Manhattan Minimum Spanning Tree - 霧でも食ってろ](https://knuu.github.io/manhattan_mst.html)
- [Line Sweep Algorithms - topcoder](https://www.topcoder.com/thrive/articles/Line%20Sweep%20Algorithms)
