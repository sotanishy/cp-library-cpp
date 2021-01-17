---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/monoids.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// monoids\n\nstruct AddMonoid {\n    using T = int;\n    static constexpr\
    \ T id = 0;\n    static T op(T a, T b) {\n        return a + b;\n    }\n};\n\n\
    struct MinMonoid {\n    using T = int;\n    static constexpr T id = (1u << 31)\
    \ - 1;\n    static T op(T a, T b) {\n        return min(a, b);\n    }\n};\n\n\
    struct AddRangeMonoid {\n    using T = pair<int, int>;\n    static constexpr T\
    \ id = {0, 0};\n    static T op(T a, T b) {\n        return {a.first + b.first,\
    \ a.second + b.second};\n    }\n};\n\nstruct UpdateMonoid {\n    using T = int;\n\
    \    static constexpr T id = -1;\n    static T op(T a, T b) {\n        return\
    \ b;\n    }\n};\n\nstruct AffineMonoid {\n    using T = pair<int, int>;\n    static\
    \ constexpr T id = {1, 0};\n    static T op(T a, T b) {\n        return {a.first\
    \ * b.first, a.second * b.first + b.second};\n    }\n};\n\n// actions\n\nAddRangeMonoid::T\
    \ act(AddRangeMonoid::T a, AffineMonoid::T b) {\n    return {a.first * b.first\
    \ + a.second * b.second, a.second};\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// monoids\n\nstruct AddMonoid\
    \ {\n    using T = int;\n    static constexpr T id = 0;\n    static T op(T a,\
    \ T b) {\n        return a + b;\n    }\n};\n\nstruct MinMonoid {\n    using T\
    \ = int;\n    static constexpr T id = (1u << 31) - 1;\n    static T op(T a, T\
    \ b) {\n        return min(a, b);\n    }\n};\n\nstruct AddRangeMonoid {\n    using\
    \ T = pair<int, int>;\n    static constexpr T id = {0, 0};\n    static T op(T\
    \ a, T b) {\n        return {a.first + b.first, a.second + b.second};\n    }\n\
    };\n\nstruct UpdateMonoid {\n    using T = int;\n    static constexpr T id = -1;\n\
    \    static T op(T a, T b) {\n        return b;\n    }\n};\n\nstruct AffineMonoid\
    \ {\n    using T = pair<int, int>;\n    static constexpr T id = {1, 0};\n    static\
    \ T op(T a, T b) {\n        return {a.first * b.first, a.second * b.first + b.second};\n\
    \    }\n};\n\n// actions\n\nAddRangeMonoid::T act(AddRangeMonoid::T a, AffineMonoid::T\
    \ b) {\n    return {a.first * b.first + a.second * b.second, a.second};\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/monoids.cpp
  requiredBy: []
  timestamp: '2021-01-17 23:20:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/monoids.cpp
layout: document
redirect_from:
- /library/misc/monoids.cpp
- /library/misc/monoids.cpp.html
title: misc/monoids.cpp
---
