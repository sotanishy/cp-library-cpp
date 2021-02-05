---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
  bundledCode: "#line 1 \"test/aoj/CGL_4_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n// #include \"../../math/geometry.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nconstexpr double eps = 1e-12;\n\ninline bool eq(double a,\
    \ double b) { return std::abs(a - b) < eps; }\ninline bool lt(double a, double\
    \ b) { return a < b - eps; }\ninline bool leq(double a, double b) { return a <\
    \ b + eps; }\n\nstruct Vec {\n    double x, y;\n\n    Vec() = default;\n    Vec(double\
    \ x, double y) : x(x), y(y) {}\n\n    Vec operator+(const Vec& other) const {\
    \ return Vec(x + other.x, y + other.y); }\n    Vec operator-(const Vec& other)\
    \ const { return Vec(x - other.x, y - other.y); }\n    Vec operator*(double k)\
    \ const { return Vec(x * k, y * k); }\n    Vec operator/(double k) const { return\
    \ Vec(x / k, y / k); }\n\n    double abs() const { return sqrt(x * x + y * y);\
    \ }\n    double dot(const Vec& other) const { return x * other.x + y * other.y;\
    \ }\n    double cross(const Vec& other) const { return x * other.y - y * other.x;\
    \ }\n\n    Vec rot(double ang) const {\n        double c = cos(ang), s = sin(ang);\n\
    \        return Vec(c * x - s * y, s * x + c * y);\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Vec& v) {\n        return os << \"(\" <<\
    \ v.x << \", \" << v.y << \")\";\n    }\n};\n\nstd::vector<Vec> convex_hull(std::vector<Vec>&\
    \ points) {\n    int n = points.size();\n    std::sort(points.begin(), points.end(),\
    \ [](const Vec& v1, const Vec& v2) {\n        return (v1.y != v2.y) ? (v1.y <\
    \ v2.y) : (v1.x < v2.x);\n    });\n    int k = 0; // the number of vertices in\
    \ the convex hull\n    std::vector<Vec> ch(2 * n);\n    // right\n    for (int\
    \ i = 0; i < n; ++i) {\n        while (k > 1 && lt((ch[k-1] - ch[k-2]).cross(points[i]\
    \ - ch[k-1]), 0)) --k;\n        ch[k++] = points[i];\n    }\n    int t = k;\n\
    \    // left\n    for (int i = n - 2; i >= 0; --i) {\n        while (k > t &&\
    \ lt((ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]), 0)) --k;\n        ch[k++]\
    \ = points[i];\n    }\n    ch.resize(k - 1);\n    return ch;\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n;\n\
    \    cin >> n;\n    vector<Vec> points(n);\n    for (auto& p : points) cin >>\
    \ p.x >> p.y;\n    auto ans = convex_hull(points);\n    cout << ans.size() <<\
    \ endl;\n    for (auto& p : ans) cout << p.x << \" \" << p.y << \"\\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A\"\
    \n\n// #include \"../../math/geometry.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\nconstexpr double eps = 1e-12;\n\ninline bool eq(double a,\
    \ double b) { return std::abs(a - b) < eps; }\ninline bool lt(double a, double\
    \ b) { return a < b - eps; }\ninline bool leq(double a, double b) { return a <\
    \ b + eps; }\n\nstruct Vec {\n    double x, y;\n\n    Vec() = default;\n    Vec(double\
    \ x, double y) : x(x), y(y) {}\n\n    Vec operator+(const Vec& other) const {\
    \ return Vec(x + other.x, y + other.y); }\n    Vec operator-(const Vec& other)\
    \ const { return Vec(x - other.x, y - other.y); }\n    Vec operator*(double k)\
    \ const { return Vec(x * k, y * k); }\n    Vec operator/(double k) const { return\
    \ Vec(x / k, y / k); }\n\n    double abs() const { return sqrt(x * x + y * y);\
    \ }\n    double dot(const Vec& other) const { return x * other.x + y * other.y;\
    \ }\n    double cross(const Vec& other) const { return x * other.y - y * other.x;\
    \ }\n\n    Vec rot(double ang) const {\n        double c = cos(ang), s = sin(ang);\n\
    \        return Vec(c * x - s * y, s * x + c * y);\n    }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Vec& v) {\n        return os << \"(\" <<\
    \ v.x << \", \" << v.y << \")\";\n    }\n};\n\nstd::vector<Vec> convex_hull(std::vector<Vec>&\
    \ points) {\n    int n = points.size();\n    std::sort(points.begin(), points.end(),\
    \ [](const Vec& v1, const Vec& v2) {\n        return (v1.y != v2.y) ? (v1.y <\
    \ v2.y) : (v1.x < v2.x);\n    });\n    int k = 0; // the number of vertices in\
    \ the convex hull\n    std::vector<Vec> ch(2 * n);\n    // right\n    for (int\
    \ i = 0; i < n; ++i) {\n        while (k > 1 && lt((ch[k-1] - ch[k-2]).cross(points[i]\
    \ - ch[k-1]), 0)) --k;\n        ch[k++] = points[i];\n    }\n    int t = k;\n\
    \    // left\n    for (int i = n - 2; i >= 0; --i) {\n        while (k > t &&\
    \ lt((ch[k-1] - ch[k-2]).cross(points[i] - ch[k-1]), 0)) --k;\n        ch[k++]\
    \ = points[i];\n    }\n    ch.resize(k - 1);\n    return ch;\n}\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int n;\n\
    \    cin >> n;\n    vector<Vec> points(n);\n    for (auto& p : points) cin >>\
    \ p.x >> p.y;\n    auto ans = convex_hull(points);\n    cout << ans.size() <<\
    \ endl;\n    for (auto& p : ans) cout << p.x << \" \" << p.y << \"\\n\";\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/CGL_4_A.test.cpp
  requiredBy: []
  timestamp: '2021-02-06 00:41:04+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/CGL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/CGL_4_A.test.cpp
- /verify/test/aoj/CGL_4_A.test.cpp.html
title: test/aoj/CGL_4_A.test.cpp
---
