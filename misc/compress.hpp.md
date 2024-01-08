---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/point_add_rectangle_sum.quadtree.test.cpp
    title: test/yosupo/point_add_rectangle_sum.quadtree.test.cpp
  - icon: ':x:'
    path: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
    title: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
  - icon: ':x:'
    path: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  - icon: ':x:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: Coordinate Compression
    links: []
  bundledCode: "#line 2 \"misc/compress.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \n/**\n * @brief Coordinate Compression\n */\ntemplate <typename T>\nclass Compress\
    \ {\n   public:\n    Compress() = default;\n    explicit Compress(const std::vector<T>&\
    \ vs) : xs(vs) {\n        std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n    }\n\n    int compress(const T& x) const {\n        return std::ranges::lower_bound(xs,\
    \ x) - xs.begin();\n    }\n\n    std::vector<int> compress(const std::vector<T>&\
    \ vs) const {\n        std::vector<int> res;\n        std::ranges::transform(vs,\
    \ res.begin(),\n                               [&](const T& x) { return compress(x);\
    \ });\n        return res;\n    }\n\n    T decompress(int i) const { return xs[i];\
    \ }\n\n    int size() const { return xs.size(); }\n\n   private:\n    std::vector<T>\
    \ xs;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n/**\n * @brief Coordinate\
    \ Compression\n */\ntemplate <typename T>\nclass Compress {\n   public:\n    Compress()\
    \ = default;\n    explicit Compress(const std::vector<T>& vs) : xs(vs) {\n   \
    \     std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n    }\n\n    int compress(const T& x) const {\n        return std::ranges::lower_bound(xs,\
    \ x) - xs.begin();\n    }\n\n    std::vector<int> compress(const std::vector<T>&\
    \ vs) const {\n        std::vector<int> res;\n        std::ranges::transform(vs,\
    \ res.begin(),\n                               [&](const T& x) { return compress(x);\
    \ });\n        return res;\n    }\n\n    T decompress(int i) const { return xs[i];\
    \ }\n\n    int size() const { return xs.size(); }\n\n   private:\n    std::vector<T>\
    \ xs;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.hpp
  requiredBy: []
  timestamp: '2024-01-08 16:18:25+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  - test/yosupo/point_add_rectangle_sum.quadtree.test.cpp
  - test/yosupo/static_range_inversions_query.test.cpp
  - test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
documentation_of: misc/compress.hpp
layout: document
redirect_from:
- /library/misc/compress.hpp
- /library/misc/compress.hpp.html
title: Coordinate Compression
---
