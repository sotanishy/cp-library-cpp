---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/line_add_get_min.test.cpp
    title: test/yosupo/line_add_get_min.test.cpp
  - icon: ':x:'
    path: test/yosupo/segment_add_get_min.test.cpp
    title: test/yosupo/segment_add_get_min.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/cht/li_chao_tree.cpp\"\n#include <algorithm>\n\
    #include <limits>\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass LiChaoTree {\npublic:\n    LiChaoTree() = default;\n    explicit LiChaoTree(const\
    \ std::vector<T>& vs) : xs(vs) {\n        size = 1;\n        while (size < (int)\
    \ xs.size()) size <<= 1;\n        node.resize(2 * size, {0, INF});\n        while\
    \ ((int) xs.size() <= size) xs.push_back(xs.back() + 1);\n    }\n\n    void add_line(T\
    \ a, T b) {\n        update({a, b}, 1, 0, size);\n    }\n\n    void add_segment(T\
    \ a, T b, int l, int r) {\n        Line line(a, b);\n        int len = 1;\n  \
    \      int l0 = l, r0 = r;\n        for (l += size, r += size; l < r; l >>= 1,\
    \ r >>= 1, len <<= 1) {\n            if (l & 1) {\n                update(line,\
    \ l, l0, l0 + len);\n                ++l;\n                l0 += len;\n      \
    \      }\n            if (r & 1) {\n                --r;\n                r0 -=\
    \ len;\n                update(line, r, r0, r0 + len);\n            }\n      \
    \  }\n    }\n\n    T get(int k) const {\n        const T x = xs[k];\n        k\
    \ += size;\n        T res = node[k](x);\n        while (k >>= 1) res = std::min(res,\
    \ node[k](x));\n        return res;\n    }\n\nprivate:\n    struct Line {\n  \
    \      T a, b;\n        Line(T a, T b) : a(a), b(b) {}\n        T operator()(T\
    \ x) { return a * x + b; }\n    };\n\n    static constexpr T INF = std::numeric_limits<T>::max();\n\
    \n    int size;\n    std::vector<T> xs;\n    std::vector<Line> node;\n\n    void\
    \ update(Line line, int k, int l, int r) {\n        while (true) {\n         \
    \   int m = (l + r) / 2;\n            bool left = line(xs[l]) < node[k](xs[l]);\n\
    \            bool mid = line(xs[m]) < node[k](xs[m]);\n            bool right\
    \ = line(xs[r]) < node[k](xs[r]);\n\n            if (!left && !right) break;\n\
    \            if (left && right) {\n                node[k] = line;\n         \
    \       break;\n            }\n            if (mid) std::swap(node[k], line);\n\
    \            if (r - l == 1) break;\n            if (left != mid) {\n        \
    \        k = 2 * k;\n                r = m;\n            } else {\n          \
    \      k = 2 * k + 1;\n                l = m;\n            }\n        }\n    }\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    #include <vector>\n\ntemplate <typename T>\nclass LiChaoTree {\npublic:\n    LiChaoTree()\
    \ = default;\n    explicit LiChaoTree(const std::vector<T>& vs) : xs(vs) {\n \
    \       size = 1;\n        while (size < (int) xs.size()) size <<= 1;\n      \
    \  node.resize(2 * size, {0, INF});\n        while ((int) xs.size() <= size) xs.push_back(xs.back()\
    \ + 1);\n    }\n\n    void add_line(T a, T b) {\n        update({a, b}, 1, 0,\
    \ size);\n    }\n\n    void add_segment(T a, T b, int l, int r) {\n        Line\
    \ line(a, b);\n        int len = 1;\n        int l0 = l, r0 = r;\n        for\
    \ (l += size, r += size; l < r; l >>= 1, r >>= 1, len <<= 1) {\n            if\
    \ (l & 1) {\n                update(line, l, l0, l0 + len);\n                ++l;\n\
    \                l0 += len;\n            }\n            if (r & 1) {\n       \
    \         --r;\n                r0 -= len;\n                update(line, r, r0,\
    \ r0 + len);\n            }\n        }\n    }\n\n    T get(int k) const {\n  \
    \      const T x = xs[k];\n        k += size;\n        T res = node[k](x);\n \
    \       while (k >>= 1) res = std::min(res, node[k](x));\n        return res;\n\
    \    }\n\nprivate:\n    struct Line {\n        T a, b;\n        Line(T a, T b)\
    \ : a(a), b(b) {}\n        T operator()(T x) { return a * x + b; }\n    };\n\n\
    \    static constexpr T INF = std::numeric_limits<T>::max();\n\n    int size;\n\
    \    std::vector<T> xs;\n    std::vector<Line> node;\n\n    void update(Line line,\
    \ int k, int l, int r) {\n        while (true) {\n            int m = (l + r)\
    \ / 2;\n            bool left = line(xs[l]) < node[k](xs[l]);\n            bool\
    \ mid = line(xs[m]) < node[k](xs[m]);\n            bool right = line(xs[r]) <\
    \ node[k](xs[r]);\n\n            if (!left && !right) break;\n            if (left\
    \ && right) {\n                node[k] = line;\n                break;\n     \
    \       }\n            if (mid) std::swap(node[k], line);\n            if (r -\
    \ l == 1) break;\n            if (left != mid) {\n                k = 2 * k;\n\
    \                r = m;\n            } else {\n                k = 2 * k + 1;\n\
    \                l = m;\n            }\n        }\n    }\n}"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/li_chao_tree.cpp
  requiredBy: []
  timestamp: '2021-10-09 01:30:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/segment_add_get_min.test.cpp
  - test/yosupo/line_add_get_min.test.cpp
documentation_of: data-structure/cht/li_chao_tree.cpp
layout: document
redirect_from:
- /library/data-structure/cht/li_chao_tree.cpp
- /library/data-structure/cht/li_chao_tree.cpp.html
title: data-structure/cht/li_chao_tree.cpp
---
