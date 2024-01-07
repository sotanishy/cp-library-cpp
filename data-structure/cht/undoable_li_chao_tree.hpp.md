---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: data-structure/cht/offline_deletable_convex_hull_trick.hpp
    title: data-structure/cht/offline_deletable_convex_hull_trick.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Undoable Li Chao Tree
    links: []
  bundledCode: "#line 2 \"data-structure/cht/undoable_li_chao_tree.hpp\"\n#include\
    \ <algorithm>\n#include <bit>\n#include <cassert>\n#include <limits>\n#include\
    \ <utility>\n#include <vector>\n\n/**\n * @brief Undoable Li Chao Tree\n */\n\
    template <typename T>\nclass UndoableLiChaoTree {\n   public:\n    UndoableLiChaoTree()\
    \ = default;\n    explicit UndoableLiChaoTree(const std::vector<T>& vs) : xs(vs)\
    \ {\n        std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
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
    \ Line>> history;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <bit>\n#include <cassert>\n\
    #include <limits>\n#include <utility>\n#include <vector>\n\n/**\n * @brief Undoable\
    \ Li Chao Tree\n */\ntemplate <typename T>\nclass UndoableLiChaoTree {\n   public:\n\
    \    UndoableLiChaoTree() = default;\n    explicit UndoableLiChaoTree(const std::vector<T>&\
    \ vs) : xs(vs) {\n        std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
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
    \ Line>> history;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/cht/undoable_li_chao_tree.hpp
  requiredBy:
  - data-structure/cht/offline_deletable_convex_hull_trick.hpp
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/cht/undoable_li_chao_tree.hpp
layout: document
redirect_from:
- /library/data-structure/cht/undoable_li_chao_tree.hpp
- /library/data-structure/cht/undoable_li_chao_tree.hpp.html
title: Undoable Li Chao Tree
---
