---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.test.cpp
    title: test/yosupo/point_add_rectangle_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
    title: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
    title: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Coordinate Compression
    links: []
  bundledCode: "#line 2 \"misc/compress.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \n/*\n * @brief Coordinate Compression\n */\ntemplate <typename T>\nclass Compress\
    \ {\npublic:\n    Compress() = default;\n    explicit Compress(const std::vector<T>&\
    \ vs) : xs(vs) {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n\n    int compress(const T& x) const {\n     \
    \   return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\n\
    \    std::vector<int> compress(const std::vector<T>& vs) const {\n        std::vector<int>\
    \ ret;\n        std::transform(vs.begin(), vs.end(), std::back_inserter(ret),\
    \ [&](const T& x) {\n            return compress(x);\n        });\n        return\
    \ ret;\n    }\n\n    T decompress(int i) const {\n        return xs[i];\n    }\n\
    \n    int size() const {\n        return xs.size();\n    }\n\nprivate:\n    std::vector<T>\
    \ xs;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\n/*\n * @brief Coordinate\
    \ Compression\n */\ntemplate <typename T>\nclass Compress {\npublic:\n    Compress()\
    \ = default;\n    explicit Compress(const std::vector<T>& vs) : xs(vs) {\n   \
    \     std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n\n    int compress(const T& x) const {\n     \
    \   return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\n\
    \    std::vector<int> compress(const std::vector<T>& vs) const {\n        std::vector<int>\
    \ ret;\n        std::transform(vs.begin(), vs.end(), std::back_inserter(ret),\
    \ [&](const T& x) {\n            return compress(x);\n        });\n        return\
    \ ret;\n    }\n\n    T decompress(int i) const {\n        return xs[i];\n    }\n\
    \n    int size() const {\n        return xs.size();\n    }\n\nprivate:\n    std::vector<T>\
    \ xs;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.cpp
  requiredBy: []
  timestamp: '2021-01-29 21:41:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
  - test/yosupo/point_add_rectangle_sum.test.cpp
  - test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: misc/compress.cpp
layout: document
redirect_from:
- /library/misc/compress.cpp
- /library/misc/compress.cpp.html
title: Coordinate Compression
---
