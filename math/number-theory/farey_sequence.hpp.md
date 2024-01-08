---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Farey Sequence
    links: []
  bundledCode: "#line 2 \"math/number-theory/farey_sequence.hpp\"\n#include <utility>\n\
    #include <vector>\n\n/**\n * @brief Farey Sequence\n */\nstd::vector<std::pair<int,\
    \ int>> farey_sequence(int n) {\n    int a = 0, b = 1, c = 1, d = n;\n    std::vector<std::pair<int,\
    \ int>> seq;\n    seq.push_back({a, b});\n    seq.push_back({c, d});\n    while\
    \ (d != 1) {\n        int k = (n + b) / d;\n        int e = k * c - a;\n     \
    \   int f = k * d - b;\n        seq.push_back({e, f});\n        a = c;\n     \
    \   b = d;\n        c = e;\n        d = f;\n    }\n    return seq;\n}\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n\n/**\n * @brief Farey\
    \ Sequence\n */\nstd::vector<std::pair<int, int>> farey_sequence(int n) {\n  \
    \  int a = 0, b = 1, c = 1, d = n;\n    std::vector<std::pair<int, int>> seq;\n\
    \    seq.push_back({a, b});\n    seq.push_back({c, d});\n    while (d != 1) {\n\
    \        int k = (n + b) / d;\n        int e = k * c - a;\n        int f = k *\
    \ d - b;\n        seq.push_back({e, f});\n        a = c;\n        b = d;\n   \
    \     c = e;\n        d = f;\n    }\n    return seq;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/number-theory/farey_sequence.hpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/number-theory/farey_sequence.hpp
layout: document
redirect_from:
- /library/math/number-theory/farey_sequence.hpp
- /library/math/number-theory/farey_sequence.hpp.html
title: Farey Sequence
---
