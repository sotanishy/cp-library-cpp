---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Enumerate Subsets
    links: []
  bundledCode: "#line 2 \"misc/enumerate_subsets.hpp\"\n#include <vector>\n\n/**\n\
    \ * @brief Enumerate Subsets\n */\nstd::vector<int> enumerate_subsets(int n, int\
    \ k) {\n    if (k < 0 || n < k) return {};\n    if (k == 0) return {0};\n    std::vector<int>\
    \ ret;\n    int comb = (1 << k) - 1;\n    while (comb < (1 << n)) {\n        ret.push_back(comb);\n\
    \        int x = comb & -comb;\n        int y = comb + x;\n        comb = ((comb\
    \ & ~y) / x >> 1) | y;\n    }\n    return ret;\n}\n"
  code: "#pragma once\n#include <vector>\n\n/**\n * @brief Enumerate Subsets\n */\n\
    std::vector<int> enumerate_subsets(int n, int k) {\n    if (k < 0 || n < k) return\
    \ {};\n    if (k == 0) return {0};\n    std::vector<int> ret;\n    int comb =\
    \ (1 << k) - 1;\n    while (comb < (1 << n)) {\n        ret.push_back(comb);\n\
    \        int x = comb & -comb;\n        int y = comb + x;\n        comb = ((comb\
    \ & ~y) / x >> 1) | y;\n    }\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/enumerate_subsets.hpp
  requiredBy: []
  timestamp: '2022-06-27 13:45:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/enumerate_subsets.hpp
layout: document
redirect_from:
- /library/misc/enumerate_subsets.hpp
- /library/misc/enumerate_subsets.hpp.html
title: Enumerate Subsets
---
