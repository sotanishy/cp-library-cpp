---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/convert_base.md
    document_title: Base Conversion
    links: []
  bundledCode: "#line 1 \"math/convert_base.cpp\"\n#include <bits/stdc++.h>\n\n/*\n\
    \ * @brief Base Conversion\n * @docs docs/math/convert_base.md\n */\nstd::vector<int>\
    \ convert_base(int n, int base) {\n    int q = n / base, r = n % base;\n    if\
    \ (q == 0) return {r};\n    auto ret = convert_base(q, base);\n    ret.push_back(r);\n\
    \    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Base Conversion\n * @docs docs/math/convert_base.md\n\
    \ */\nstd::vector<int> convert_base(int n, int base) {\n    int q = n / base,\
    \ r = n % base;\n    if (q == 0) return {r};\n    auto ret = convert_base(q, base);\n\
    \    ret.push_back(r);\n    return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/convert_base.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:45:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/convert_base.cpp
layout: document
redirect_from:
- /library/math/convert_base.cpp
- /library/math/convert_base.cpp.html
title: Base Conversion
---
# Base Conversion

10進数の整数 $n$ を $base$ 進数に変換する

- `vector<int> convert_base(int n, int base)`
    - 時間計算量: $O(\log_{base} n)$