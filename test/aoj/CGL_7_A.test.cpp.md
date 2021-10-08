---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A
  bundledCode: "#line 1 \"test/aoj/CGL_7_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\
    \n\n// #include \"../../math/geometry.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing T = double;\nusing Vec = std::complex<T>;\n\nconstexpr\
    \ T eps = 1e-12;\ninline bool eq(T a, T b) { return std::abs(a - b) < eps; }\n\
    inline bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) {\
    \ return a < b + eps; }\n\nstd::istream& operator>>(std::istream& is, Vec& p)\
    \ {\n    T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n}\n\nT dot(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\nT cross(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nint ccw(const\
    \ Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b - a, c - a), 0)) return\
    \ 0;  // collinear\n    if (lt(cross(b - a, c - a), 0)) return -1;  // clockwise\n\
    \    return 1;  // counter clockwise\n}\n\nstd::vector<Vec> intersection_circles(const\
    \ Vec& c1, T r1, const Vec& c2, T r2) {\n    T d = std::abs(c1 - c2);\n    //\
    \ if the circles are outside of each other\n    if (lt(r1 + r2, d)) return {};\n\
    \    // if one contains the other entirely\n    if (lt(d, std::abs(r2 - r1)))\
    \ return {};\n    T x = (r1*r1 - r2*r2 + d*d) / (2*d);\n    T y = std::sqrt(r1*r1\
    \ - x*x);\n    Vec e1 = (c2 - c1) / std::abs(c2 - c1);\n    Vec e2 = Vec(-e1.imag(),\
    \ e1.real());\n    return {c1 + x*e1 + y*e2, c1 + x*e1 - y*e2};\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout <<\
    \ fixed << setprecision(15);\n\n    int n;\n    cin >> n;\n    vector<Vec> pts(n);\n\
    \    for (auto& x : pts) cin >> x;\n    int q;\n    cin >> q;\n    while (q--)\
    \ {\n        Vec p;\n        cin >> p;\n        cout << contains(pts, p) << \"\
    \\n\";\n    }\n}\n\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_7_A\"\
    \n\n// #include \"../../math/geometry.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nusing T = double;\nusing Vec = std::complex<T>;\n\nconstexpr\
    \ T eps = 1e-12;\ninline bool eq(T a, T b) { return std::abs(a - b) < eps; }\n\
    inline bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) {\
    \ return a < b + eps; }\n\nstd::istream& operator>>(std::istream& is, Vec& p)\
    \ {\n    T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n}\n\nT dot(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).real();\n}\n\nT cross(const\
    \ Vec& a, const Vec& b) {\n    return (std::conj(a) * b).imag();\n}\n\nint ccw(const\
    \ Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b - a, c - a), 0)) return\
    \ 0;  // collinear\n    if (lt(cross(b - a, c - a), 0)) return -1;  // clockwise\n\
    \    return 1;  // counter clockwise\n}\n\nstd::vector<Vec> intersection_circles(const\
    \ Vec& c1, T r1, const Vec& c2, T r2) {\n    T d = std::abs(c1 - c2);\n    //\
    \ if the circles are outside of each other\n    if (lt(r1 + r2, d)) return {};\n\
    \    // if one contains the other entirely\n    if (lt(d, std::abs(r2 - r1)))\
    \ return {};\n    T x = (r1*r1 - r2*r2 + d*d) / (2*d);\n    T y = std::sqrt(r1*r1\
    \ - x*x);\n    Vec e1 = (c2 - c1) / std::abs(c2 - c1);\n    Vec e2 = Vec(-e1.imag(),\
    \ e1.real());\n    return {c1 + x*e1 + y*e2, c1 + x*e1 - y*e2};\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n    cout <<\
    \ fixed << setprecision(15);\n\n    int n;\n    cin >> n;\n    vector<Vec> pts(n);\n\
    \    for (auto& x : pts) cin >> x;\n    int q;\n    cin >> q;\n    while (q--)\
    \ {\n        Vec p;\n        cin >> p;\n        cout << contains(pts, p) << \"\
    \\n\";\n    }\n}\n\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL_7_A.test.cpp
  requiredBy: []
  timestamp: '2021-10-09 01:30:29+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/CGL_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_7_A.test.cpp
- /verify/test/aoj/CGL_7_A.test.cpp.html
title: test/aoj/CGL_7_A.test.cpp
---
