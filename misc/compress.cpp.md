---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/misc/compress.md
    document_title: Coordinate Compression
    links: []
  bundledCode: "#line 1 \"misc/compress.cpp\"\n#include <bits/stdc++.h>\n\n/*\n *\
    \ @brief Coordinate Compression\n * @docs docs/misc/compress.md\n */\ntemplate\
    \ <typename T>\nclass Compress {\npublic:\n    Comress() = default;\n    explicit\
    \ Compress(const std::vector<T>& vs) : xs(vs) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \    }\n\n    int compress(const T& x) const {\n        return std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    }\n\n    T decompress(int i) const {\n     \
    \   return xs[i];\n    }\n\nprivate:\n    std::vector<T> xs;\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Coordinate Compression\n * @docs\
    \ docs/misc/compress.md\n */\ntemplate <typename T>\nclass Compress {\npublic:\n\
    \    Comress() = default;\n    explicit Compress(const std::vector<T>& vs) : xs(vs)\
    \ {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n\n    int compress(const T& x) const {\n     \
    \   return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\n\
    \    T decompress(int i) const {\n        return xs[i];\n    }\n\nprivate:\n \
    \   std::vector<T> xs;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/compress.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/compress.cpp
layout: document
redirect_from:
- /library/misc/compress.cpp
- /library/misc/compress.cpp.html
title: Coordinate Compression
---
# Coordinate Compression

座標圧縮．与えられた値の大小関係が保たれるように，値を連続した非負整数に変換する．

空間計算量: $O(n)$

## Template parameters

- `T`
    - 要素の型

## Constructor

- `Compress(const vector<T>& vs)`
    - `vs`の値を座標圧縮する
    - 時間計算量: $O(n \lg n)$

## Member functions

- `int compress(const T& x)`
    - $x$ を圧縮した値を返す
    - 時間計算量: $O(\lg n)$
- `T decompress(int i)`
    - $i$ の圧縮前の値を返す
    - 時間計算量: $O(1)$