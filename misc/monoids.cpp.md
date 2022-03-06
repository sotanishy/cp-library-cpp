---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"misc/monoids.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\n// monoids\n\nstruct AddMonoid {\n    using T = int;\n    static T id()\
    \ { return 0; }\n    static T op(T a, T b) {\n        return a + b;\n    }\n};\n\
    \nstruct MinMonoid {\n    using T = int;\n    static T id() { return (1u << 31)\
    \ - 1; }\n    static T op(T a, T b) {\n        return min(a, b);\n    }\n};\n\n\
    struct MaxMonoid {\n    using T = int;\n    static T id() { return 0; }\n    static\
    \ T op(T a, T b) {\n        return max(a, b);\n    }\n};\n\nstruct AddRangeMonoid\
    \ {\n    using T = pair<int, int>;\n    static T id() { return {0, 0}; }\n   \
    \ static T op(T a, T b) {\n        return {a.first + b.first, a.second + b.second};\n\
    \    }\n};\n\nstruct UpdateMonoid {\n    using T = int;\n    static T id() { return\
    \ -1; }\n    static T op(T a, T b) {\n        return b;\n    }\n};\n\nstruct AffineMonoid\
    \ {\n    using T = pair<int, int>;\n    static T id() { return {1, 0}; }\n   \
    \ static T op(T a, T b) {\n        return {a.first * b.first, a.second * b.first\
    \ + b.second};\n    }\n};\n\n// actions\n\nAddRangeMonoid::T act(AddRangeMonoid::T\
    \ a, AffineMonoid::T b) {\n    return {a.first * b.first + a.second * b.second,\
    \ a.second};\n}\n\nAddRangeMonoid::T act(AddRangeMonoid::T a, UpdateMonoid::T\
    \ b) {\n    if (b == UpdateMonoid::id) return a;\n    return {b * a.second, a.second};\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\n// monoids\n\nstruct AddMonoid\
    \ {\n    using T = int;\n    static T id() { return 0; }\n    static T op(T a,\
    \ T b) {\n        return a + b;\n    }\n};\n\nstruct MinMonoid {\n    using T\
    \ = int;\n    static T id() { return (1u << 31) - 1; }\n    static T op(T a, T\
    \ b) {\n        return min(a, b);\n    }\n};\n\nstruct MaxMonoid {\n    using\
    \ T = int;\n    static T id() { return 0; }\n    static T op(T a, T b) {\n   \
    \     return max(a, b);\n    }\n};\n\nstruct AddRangeMonoid {\n    using T = pair<int,\
    \ int>;\n    static T id() { return {0, 0}; }\n    static T op(T a, T b) {\n \
    \       return {a.first + b.first, a.second + b.second};\n    }\n};\n\nstruct\
    \ UpdateMonoid {\n    using T = int;\n    static T id() { return -1; }\n    static\
    \ T op(T a, T b) {\n        return b;\n    }\n};\n\nstruct AffineMonoid {\n  \
    \  using T = pair<int, int>;\n    static T id() { return {1, 0}; }\n    static\
    \ T op(T a, T b) {\n        return {a.first * b.first, a.second * b.first + b.second};\n\
    \    }\n};\n\n// actions\n\nAddRangeMonoid::T act(AddRangeMonoid::T a, AffineMonoid::T\
    \ b) {\n    return {a.first * b.first + a.second * b.second, a.second};\n}\n\n\
    AddRangeMonoid::T act(AddRangeMonoid::T a, UpdateMonoid::T b) {\n    if (b ==\
    \ UpdateMonoid::id) return a;\n    return {b * a.second, a.second};\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/monoids.cpp
  requiredBy: []
  timestamp: '2022-03-06 20:10:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/monoids.cpp
layout: document
redirect_from:
- /library/misc/monoids.cpp
- /library/misc/monoids.cpp.html
title: misc/monoids.cpp
---
