---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/data-structure/li_chao_tree.md
    document_title: Li Chao Tree
    links: []
  bundledCode: "#line 1 \"data-structure/li_chao_tree.cpp\"\n#include <bits/stdc++.h>\n\
    \n/*\n * @brief Li Chao Tree\n * @docs docs/data-structure/li_chao_tree.md\n */\n\
    template <typename T>\nclass LiChaoTree {\npublic:\n    LiChaoTree() = default;\n\
    \    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {\n        size =\
    \ 1;\n        while (size < (int) xs.size()) size <<= 1;\n        node.resize(2\
    \ * size, {0, INF});\n        while ((int) xs.size() <= size) xs.push_back(xs.back()\
    \ + 1);\n    }\n\n    void add_line(T a, T b) {\n        update({a, b}, 1, 0,\
    \ size);\n    }\n\n    void add_segment(T a, T b, int l, int r) {\n        std::pair<T,\
    \ T> line(a, b);\n        int len = 1;\n        int l0 = l, r0 = r;\n        for\
    \ (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {\n            if\
    \ (l & 1) {\n                update(line, l, l0, l0 + len);\n                ++l;\n\
    \                l0 += len;\n            }\n            if (r & 1) {\n       \
    \         --r;\n                r0 -= len;\n                update(line, r, r0,\
    \ r0 + len);\n            }\n        }\n    }\n\n    T get_min(int k) const {\n\
    \        const T x = xs[k];\n        k += size;\n        T res = f(node[k], x);\n\
    \        while (k >>= 1) res = std::min(res, f(node[k], x));\n        return res;\n\
    \    }\n\nprivate:\n    const T INF = std::numeric_limits<T>::max();\n\n    int\
    \ size;\n    std::vector<T> xs;\n    std::vector<std::pair<T, T>> node;\n\n  \
    \  inline T f(const std::pair<T, T>& line, T x) const {\n        return line.first\
    \ * x + line.second;\n    }\n\n    void update(std::pair<T, T> line, int k, int\
    \ l, int r) {\n        while (true) {\n            int m = (l + r) / 2;\n    \
    \        bool left = f(line, xs[l]) < f(node[k], xs[l]);\n            bool mid\
    \ = f(line, xs[m]) < f(node[k], xs[m]);\n            bool right = f(line, xs[r])\
    \ < f(node[k], xs[r]);\n\n            if (!left && !right) break;\n          \
    \  if (left && right) {\n                node[k] = line;\n                break;\n\
    \            }\n            if (mid) std::swap(node[k], line);\n            if\
    \ (r - l == 1) break;\n            if (left != mid) {\n                k = 2 *\
    \ k;\n                r = m;\n            } else {\n                k = 2 * k\
    \ + 1;\n                l = m;\n            }\n        }\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Li Chao Tree\n * @docs docs/data-structure/li_chao_tree.md\n\
    \ */\ntemplate <typename T>\nclass LiChaoTree {\npublic:\n    LiChaoTree() = default;\n\
    \    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {\n        size =\
    \ 1;\n        while (size < (int) xs.size()) size <<= 1;\n        node.resize(2\
    \ * size, {0, INF});\n        while ((int) xs.size() <= size) xs.push_back(xs.back()\
    \ + 1);\n    }\n\n    void add_line(T a, T b) {\n        update({a, b}, 1, 0,\
    \ size);\n    }\n\n    void add_segment(T a, T b, int l, int r) {\n        std::pair<T,\
    \ T> line(a, b);\n        int len = 1;\n        int l0 = l, r0 = r;\n        for\
    \ (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {\n            if\
    \ (l & 1) {\n                update(line, l, l0, l0 + len);\n                ++l;\n\
    \                l0 += len;\n            }\n            if (r & 1) {\n       \
    \         --r;\n                r0 -= len;\n                update(line, r, r0,\
    \ r0 + len);\n            }\n        }\n    }\n\n    T get_min(int k) const {\n\
    \        const T x = xs[k];\n        k += size;\n        T res = f(node[k], x);\n\
    \        while (k >>= 1) res = std::min(res, f(node[k], x));\n        return res;\n\
    \    }\n\nprivate:\n    const T INF = std::numeric_limits<T>::max();\n\n    int\
    \ size;\n    std::vector<T> xs;\n    std::vector<std::pair<T, T>> node;\n\n  \
    \  inline T f(const std::pair<T, T>& line, T x) const {\n        return line.first\
    \ * x + line.second;\n    }\n\n    void update(std::pair<T, T> line, int k, int\
    \ l, int r) {\n        while (true) {\n            int m = (l + r) / 2;\n    \
    \        bool left = f(line, xs[l]) < f(node[k], xs[l]);\n            bool mid\
    \ = f(line, xs[m]) < f(node[k], xs[m]);\n            bool right = f(line, xs[r])\
    \ < f(node[k], xs[r]);\n\n            if (!left && !right) break;\n          \
    \  if (left && right) {\n                node[k] = line;\n                break;\n\
    \            }\n            if (mid) std::swap(node[k], line);\n            if\
    \ (r - l == 1) break;\n            if (left != mid) {\n                k = 2 *\
    \ k;\n                r = m;\n            } else {\n                k = 2 * k\
    \ + 1;\n                l = m;\n            }\n        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/li_chao_tree.cpp
  requiredBy: []
  timestamp: '2020-10-03 18:55:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/line_add_get_min.test.cpp
documentation_of: data-structure/li_chao_tree.cpp
layout: document
redirect_from:
- /library/data-structure/li_chao_tree.cpp
- /library/data-structure/li_chao_tree.cpp.html
title: Li Chao Tree
---
# Li Chao Tree

Li Chao tree は，直線及び線分の集合をセグメント木で管理し，与えられた $x$ 座標での最小値を取得するデータ構造である．

## Template parameter

- `T`
    - 値の型

## Constructor

- `LiChaoTree(vector<T> vs)`
    - クエリに用いる $x$ 座標を受け取り，Li Chao tree を構築する
    - 時間計算量: $O(n)$

## Member functions

- `void add_line(T a, T b)`
    - 直線 $y = ax + b$ を追加する
    - 時間計算量: $O(\lg n)$
- void add_segment(T a, T b, int l, int r)`
    - 線分 $y = ax + b \quad (x \in [vs_l, vs_r))$ を追加する
    - 時間計算量: $O(\lg^2 n)$
- `T get_min(int k)`
    - $x = vs_k$ での最小値を取得する
    - 時間計算量: $O(\lg n)$

## Reference

- [Li Chao Treeのメモ](https://smijake3.hatenablog.com/entry/2018/06/16/144548)