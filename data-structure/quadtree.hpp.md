---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/point_add_rectangle_sum.quadtree.test.cpp
    title: test/yosupo/point_add_rectangle_sum.quadtree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/quadtree.hpp\"\n#include <memory>\n#include\
    \ <vector>\n\ntemplate <typename M>\nclass Quadtree {\n    using T = M::T;\n\n\
    \   public:\n    Quadtree() = default;\n    Quadtree(int n) : root(std::make_unique<Node>())\
    \ {\n        size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T get(int\
    \ x, int y) const { return fold(x, x + 1, y, y + 1); }\n\n    void update(int\
    \ x, int y, const T& val) const {\n        update(x, y, val, root, 0, 0, size);\n\
    \    }\n\n    T fold(int l, int r, int b, int t) const {\n        return fold(l,\
    \ r, b, t, root, 0, 0, size);\n    }\n\n   private:\n    struct Node;\n    using\
    \ node_ptr = std::unique_ptr<Node>;\n\n    struct Node {\n        T val;\n   \
    \     node_ptr ch[4];\n        Node() : val(M::id()) {}\n    };\n\n    const node_ptr\
    \ root;\n    int size;\n\n    void update(int x, int y, const T& val, const node_ptr&\
    \ n, int p, int q,\n                int len) const {\n        if (len == 1) {\n\
    \            n->val = val;\n            return;\n        }\n        len /= 2;\n\
    \        for (int i = 3; i >= 0; --i) {\n            if (x >= p + len * (i >>\
    \ 1) && y >= q + len * (i & 1)) {\n                if (!n->ch[i]) n->ch[i] = std::make_unique<Node>();\n\
    \                update(x, y, val, n->ch[i], p + len * (i >> 1),\n           \
    \            q + len * (i & 1), len);\n                break;\n            }\n\
    \        }\n        n->val = M::id();\n        for (int i = 0; i < 4; ++i) {\n\
    \            if (n->ch[i]) n->val = M::op(n->val, n->ch[i]->val);\n        }\n\
    \    }\n\n    T fold(int l, int r, int b, int t, const node_ptr& n, int p, int\
    \ q,\n           int len) const {\n        if (!n) return M::id();\n        if\
    \ (p + len <= l || r <= p || q + len <= b || t <= q) {\n            return M::id();\n\
    \        }\n        if (l <= p && p + len <= r && b <= q && q + len <= t) {\n\
    \            return n->val;\n        }\n        len /= 2;\n        T val = M::id();\n\
    \        for (int i = 0; i < 4; ++i) {\n            if (n->ch[i])\n          \
    \      val = M::op(val, fold(l, r, b, t, n->ch[i], p + len * (i >> 1),\n     \
    \                                 q + len * (i & 1), len));\n        }\n     \
    \   return val;\n    }\n};\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n\ntemplate <typename\
    \ M>\nclass Quadtree {\n    using T = M::T;\n\n   public:\n    Quadtree() = default;\n\
    \    Quadtree(int n) : root(std::make_unique<Node>()) {\n        size = 1;\n \
    \       while (size < n) size <<= 1;\n    }\n\n    T get(int x, int y) const {\
    \ return fold(x, x + 1, y, y + 1); }\n\n    void update(int x, int y, const T&\
    \ val) const {\n        update(x, y, val, root, 0, 0, size);\n    }\n\n    T fold(int\
    \ l, int r, int b, int t) const {\n        return fold(l, r, b, t, root, 0, 0,\
    \ size);\n    }\n\n   private:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[4];\n        Node() :\
    \ val(M::id()) {}\n    };\n\n    const node_ptr root;\n    int size;\n\n    void\
    \ update(int x, int y, const T& val, const node_ptr& n, int p, int q,\n      \
    \          int len) const {\n        if (len == 1) {\n            n->val = val;\n\
    \            return;\n        }\n        len /= 2;\n        for (int i = 3; i\
    \ >= 0; --i) {\n            if (x >= p + len * (i >> 1) && y >= q + len * (i &\
    \ 1)) {\n                if (!n->ch[i]) n->ch[i] = std::make_unique<Node>();\n\
    \                update(x, y, val, n->ch[i], p + len * (i >> 1),\n           \
    \            q + len * (i & 1), len);\n                break;\n            }\n\
    \        }\n        n->val = M::id();\n        for (int i = 0; i < 4; ++i) {\n\
    \            if (n->ch[i]) n->val = M::op(n->val, n->ch[i]->val);\n        }\n\
    \    }\n\n    T fold(int l, int r, int b, int t, const node_ptr& n, int p, int\
    \ q,\n           int len) const {\n        if (!n) return M::id();\n        if\
    \ (p + len <= l || r <= p || q + len <= b || t <= q) {\n            return M::id();\n\
    \        }\n        if (l <= p && p + len <= r && b <= q && q + len <= t) {\n\
    \            return n->val;\n        }\n        len /= 2;\n        T val = M::id();\n\
    \        for (int i = 0; i < 4; ++i) {\n            if (n->ch[i])\n          \
    \      val = M::op(val, fold(l, r, b, t, n->ch[i], p + len * (i >> 1),\n     \
    \                                 q + len * (i & 1), len));\n        }\n     \
    \   return val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/quadtree.hpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/point_add_rectangle_sum.quadtree.test.cpp
documentation_of: data-structure/quadtree.hpp
layout: document
title: Quadtree
---

## Description

四分木は，二次元領域を扱うデータ構造である．この実装では，可換モノイドの一点更新と長方形領域和を扱う．一点更新は高速だが，長方形領域取得は最悪計算量が悪い．実用上は愚直よりは高速であると思われる．

空間計算量: $O(m\log n)$, $m$ は点の数

## Operations

- `Quadtree(int n)`
    - $n \times n$ の領域を扱う四分木を構築する．
    - 時間計算量: $O(\log n)$
- `T get(int x, int y)`
    - 点 $(x, y)$ の値を返す
    - 時間計算量: $O(\log n)$
- `void update(int x, int y, T val)`
    - 点 $(x, y)$ の値を `val` に更新する
    - 時間計算量: $O(\log n)$
- `T fold(int l, int r, int b, int t)`
    - 領域 ${(x, y) : x \in [l, r),\ y \in [b, t)}$ 内の点を fold した値を返す
    - 時間計算量: $O(m\log n)$