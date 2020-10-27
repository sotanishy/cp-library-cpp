---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/point_add_rectangle_sum.test.cpp
    title: test/yosupo/point_add_rectangle_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/data-structure/quadtree.cpp
    document_title: Quadtree
    links: []
  bundledCode: "#line 2 \"data-structure/quadtree.cpp\"\n#include <memory>\n#include\
    \ <vector>\n\n/*\n * @brief Quadtree\n * @docs docs/data-structure/quadtree.cpp\n\
    \ */\ntemplate <typename M>\nclass Quadtree {\n    using T = typename M::T;\n\n\
    public:\n    Quadtree() = default;\n    Quadtree(int n) : root(std::make_unique<Node>())\
    \ {\n        size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T get(int\
    \ x, int y) const { return fold(x, x + 1, y, y + 1); }\n\n    void update(int\
    \ x, int y, const T& val) const { update(x, y, val, root, 0, 0, size); }\n\n \
    \   T fold(int l, int r, int b, int t) const { return fold(l, r, b, t, root, 0,\
    \ 0, size); }\n\nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[4];\n        Node() :\
    \ val(M::id) {}\n    };\n\n    const node_ptr root;\n    int size;\n\n    void\
    \ update(int x, int y, const T& val, const node_ptr& n, int p, int q, int len)\
    \ const {\n        if (len == 1) {\n            n->val = val;\n            return;\n\
    \        }\n        len /= 2;\n        for (int i = 3; i >= 0; --i) {\n      \
    \      if (x >= p + len * (i >> 1) && y >= q + len * (i & 1)) {\n            \
    \    if (!n->ch[i]) n->ch[i] = std::make_unique<Node>();\n                update(x,\
    \ y, val, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len);\n           \
    \     break;\n            }\n        }\n        n->val = M::id;\n        for (int\
    \ i = 0; i < 4; ++i) {\n            if (n->ch[i]) n->val = M::op(n->val, n->ch[i]->val);\n\
    \        }\n    }\n\n    T fold(int l, int r, int b, int t, const node_ptr& n,\
    \ int p, int q, int len) const {\n        if (!n) return M::id;\n        if (p\
    \ + len <= l || r <= p || q + len <= b || t <= q) {\n            return M::id;\n\
    \        }\n        if (l <= p && p + len <= r && b <= q && q + len <= t) {\n\
    \            return n->val;\n        }\n        len /= 2;\n        T val = M::id;\n\
    \        for (int i = 0; i < 4; ++i) {\n            if (n->ch[i]) val = M::op(val,\
    \ fold(l, r, b, t, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len));\n \
    \       }\n        return val;\n    }\n};\n"
  code: "#pragma once\n#include <memory>\n#include <vector>\n\n/*\n * @brief Quadtree\n\
    \ * @docs docs/data-structure/quadtree.cpp\n */\ntemplate <typename M>\nclass\
    \ Quadtree {\n    using T = typename M::T;\n\npublic:\n    Quadtree() = default;\n\
    \    Quadtree(int n) : root(std::make_unique<Node>()) {\n        size = 1;\n \
    \       while (size < n) size <<= 1;\n    }\n\n    T get(int x, int y) const {\
    \ return fold(x, x + 1, y, y + 1); }\n\n    void update(int x, int y, const T&\
    \ val) const { update(x, y, val, root, 0, 0, size); }\n\n    T fold(int l, int\
    \ r, int b, int t) const { return fold(l, r, b, t, root, 0, 0, size); }\n\nprivate:\n\
    \    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n    struct Node\
    \ {\n        T val;\n        node_ptr ch[4];\n        Node() : val(M::id) {}\n\
    \    };\n\n    const node_ptr root;\n    int size;\n\n    void update(int x, int\
    \ y, const T& val, const node_ptr& n, int p, int q, int len) const {\n       \
    \ if (len == 1) {\n            n->val = val;\n            return;\n        }\n\
    \        len /= 2;\n        for (int i = 3; i >= 0; --i) {\n            if (x\
    \ >= p + len * (i >> 1) && y >= q + len * (i & 1)) {\n                if (!n->ch[i])\
    \ n->ch[i] = std::make_unique<Node>();\n                update(x, y, val, n->ch[i],\
    \ p + len * (i >> 1), q + len * (i & 1), len);\n                break;\n     \
    \       }\n        }\n        n->val = M::id;\n        for (int i = 0; i < 4;\
    \ ++i) {\n            if (n->ch[i]) n->val = M::op(n->val, n->ch[i]->val);\n \
    \       }\n    }\n\n    T fold(int l, int r, int b, int t, const node_ptr& n,\
    \ int p, int q, int len) const {\n        if (!n) return M::id;\n        if (p\
    \ + len <= l || r <= p || q + len <= b || t <= q) {\n            return M::id;\n\
    \        }\n        if (l <= p && p + len <= r && b <= q && q + len <= t) {\n\
    \            return n->val;\n        }\n        len /= 2;\n        T val = M::id;\n\
    \        for (int i = 0; i < 4; ++i) {\n            if (n->ch[i]) val = M::op(val,\
    \ fold(l, r, b, t, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len));\n \
    \       }\n        return val;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/quadtree.cpp
  requiredBy: []
  timestamp: '2020-10-27 21:10:27+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/point_add_rectangle_sum.test.cpp
documentation_of: data-structure/quadtree.cpp
layout: document
redirect_from:
- /library/data-structure/quadtree.cpp
- /library/data-structure/quadtree.cpp.html
title: Quadtree
---
