---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"math/change_base.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nvector<int> change_base(int n, int base) {\n    int q = n\
    \ / base, r = n % base;\n    if (q == 0) return {r};\n    auto ret = change_base(q,\
    \ base);\n    ret.push_back(r);\n    return ret;\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nvector<int> change_base(int\
    \ n, int base) {\n    int q = n / base, r = n % base;\n    if (q == 0) return\
    \ {r};\n    auto ret = change_base(q, base);\n    ret.push_back(r);\n    return\
    \ ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/change_base.cpp
  requiredBy: []
  timestamp: '2020-08-31 09:52:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/change_base.cpp
layout: document
redirect_from:
- /library/math/change_base.cpp
- /library/math/change_base.cpp.html
title: math/change_base.cpp
---
