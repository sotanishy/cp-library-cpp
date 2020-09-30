---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure/monoids.cpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// monoids\n\nstruct AddMonoid {\n    using T = int;\n\
    \    inline static const T id = 0;\n    static T op(T a, T b) {\n        return\
    \ a + b;\n    }\n};\n\nstruct MinMonoid {\n    using T = int;\n    inline static\
    \ const T id = (1u << 31) - 1;\n    static T op(T a, T b) {\n        return min(a,\
    \ b);\n    }\n};\n\nstruct AddRangeMonoid {\n    using T = pair<int, int>;\n \
    \   inline static const T id = {0, 0};\n    static T op(T a, T b) {\n        return\
    \ {a.first + b.first, a.second + b.second};\n    }\n};\n\nstruct UpdateMonoid\
    \ {\n    using T = int;\n    inline static const T id = -1;\n    static T op(T\
    \ a, T b) {\n        return b;\n    }\n};\n\nstruct AffineMonoid {\n    using\
    \ T = pair<int, int>;\n    inline static const T id = {1, 0};\n    static T op(T\
    \ a, T b) {\n        return {a.first * b.first, a.second * b.first + b.second};\n\
    \    }\n};\n\n// actions\n\nAddRangeMonoid::T act(AddRangeMonoid::T a, AffineMonoid::T\
    \ b) {\n    return {a.first * b.first + a.second * b.second, a.second};\n}\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// monoids\n\nstruct AddMonoid\
    \ {\n    using T = int;\n    inline static const T id = 0;\n    static T op(T\
    \ a, T b) {\n        return a + b;\n    }\n};\n\nstruct MinMonoid {\n    using\
    \ T = int;\n    inline static const T id = (1u << 31) - 1;\n    static T op(T\
    \ a, T b) {\n        return min(a, b);\n    }\n};\n\nstruct AddRangeMonoid {\n\
    \    using T = pair<int, int>;\n    inline static const T id = {0, 0};\n    static\
    \ T op(T a, T b) {\n        return {a.first + b.first, a.second + b.second};\n\
    \    }\n};\n\nstruct UpdateMonoid {\n    using T = int;\n    inline static const\
    \ T id = -1;\n    static T op(T a, T b) {\n        return b;\n    }\n};\n\nstruct\
    \ AffineMonoid {\n    using T = pair<int, int>;\n    inline static const T id\
    \ = {1, 0};\n    static T op(T a, T b) {\n        return {a.first * b.first, a.second\
    \ * b.first + b.second};\n    }\n};\n\n// actions\n\nAddRangeMonoid::T act(AddRangeMonoid::T\
    \ a, AffineMonoid::T b) {\n    return {a.first * b.first + a.second * b.second,\
    \ a.second};\n}"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/monoids.cpp
  requiredBy: []
  timestamp: '2020-09-22 03:12:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/monoids.cpp
layout: document
redirect_from:
- /library/data-structure/monoids.cpp
- /library/data-structure/monoids.cpp.html
title: data-structure/monoids.cpp
---
