---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
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
    \nprivate:\n    std::vector<T> xs;\n};\n"
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
    \nprivate:\n    std::vector<T> xs;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.cpp
  requiredBy: []
  timestamp: '2020-10-24 00:03:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/compress.cpp
layout: document
redirect_from:
- /library/misc/compress.cpp
- /library/misc/compress.cpp.html
title: Coordinate Compression
---
