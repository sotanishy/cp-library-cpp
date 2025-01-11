---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/convex_hull.hpp
    title: Convex Hull
  - icon: ':heavy_check_mark:'
    path: geometry/geometry.hpp
    title: Geometry
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_convex_hull
    links:
    - https://judge.yosupo.jp/problem/static_convex_hull
  bundledCode: "#line 1 \"test/yosupo/static_convex_hull.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/static_convex_hull\"\n\n#include <bits/stdc++.h>\n\
    \n#line 3 \"geometry/convex_hull.hpp\"\n\n#line 7 \"geometry/geometry.hpp\"\n\
    #include <numbers>\n#line 10 \"geometry/geometry.hpp\"\n\n// note that if T is\
    \ of an integer type, std::abs does not work\nusing T = double;\nusing Vec = std::complex<T>;\n\
    \nstd::istream& operator>>(std::istream& is, Vec& p) {\n    T x, y;\n    is >>\
    \ x >> y;\n    p = {x, y};\n    return is;\n}\n\nT dot(const Vec& a, const Vec&\
    \ b) { return (std::conj(a) * b).real(); }\n\nT cross(const Vec& a, const Vec&\
    \ b) { return (std::conj(a) * b).imag(); }\n\nconstexpr T PI = std::numbers::pi_v<T>;\n\
    constexpr T eps = 1e-10;\ninline bool eq(T a, T b) { return std::abs(a - b) <=\
    \ eps; }\ninline bool eq(Vec a, Vec b) { return std::abs(a - b) <= eps; }\ninline\
    \ bool lt(T a, T b) { return a < b - eps; }\ninline bool leq(T a, T b) { return\
    \ a <= b + eps; }\n\nstruct Line {\n    Vec p1, p2;\n    Line() = default;\n \
    \   Line(const Vec& p1, const Vec& p2) : p1(p1), p2(p2) {}\n    Vec dir() const\
    \ { return p2 - p1; }\n};\n\nstruct Segment : Line {\n    using Line::Line;\n\
    };\n\nstruct Circle {\n    Vec c;\n    T r;\n    Circle() = default;\n    Circle(const\
    \ Vec& c, T r) : c(c), r(r) {}\n};\n\nusing Polygon = std::vector<Vec>;\n\nVec\
    \ rot(const Vec& a, T ang) { return a * Vec(std::cos(ang), std::sin(ang)); }\n\
    \nVec perp(const Vec& a) { return Vec(-a.imag(), a.real()); }\n\nVec projection(const\
    \ Line& l, const Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir()) * l.dir()\
    \ / std::norm(l.dir());\n}\n\nVec reflection(const Line& l, const Vec& p) {\n\
    \    return T(2) * projection(l, p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n\
    // -1: clockwise\nint ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if\
    \ (eq(cross(b - a, c - a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0))\
    \ return -1;\n    return 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n\
    \    std::ranges::sort(pts, [&](auto& p, auto& q) {\n        if ((p.imag() < 0)\
    \ != (q.imag() < 0)) return (p.imag() < 0);\n        if (cross(p, q) == 0) {\n\
    \            if (p == Vec(0, 0))\n                return !(q.imag() < 0 || (q.imag()\
    \ == 0 && q.real() > 0));\n            if (q == Vec(0, 0))\n                return\
    \ (p.imag() < 0 || (p.imag() == 0 && p.real() > 0));\n            return (p.real()\
    \ > q.real());\n        }\n        return (cross(p, q) > 0);\n    });\n}\n#line\
    \ 5 \"geometry/convex_hull.hpp\"\n\nstd::vector<Vec> convex_hull(std::vector<Vec>\
    \ pts, bool strict = true) {\n    std::ranges::sort(pts, {}, [](const Vec& v)\
    \ {\n        return std::make_pair(v.imag(), v.real());\n    });\n    if (strict)\
    \ {\n        pts.erase(std::ranges::unique(pts).begin(), pts.end());\n    }\n\
    \    const int n = pts.size();\n    if (n <= 1) return pts;\n    int k = 0;  //\
    \ the number of vertices in the convex hull\n    std::vector<Vec> ch(2 * n);\n\
    \    // right\n    for (int i = 0; i < n; ++i) {\n        if (strict) {\n    \
    \        while (k > 1 &&\n                   leq(cross(ch[k - 1] - ch[k - 2],\
    \ pts[i] - ch[k - 1]), 0))\n                --k;\n        } else {\n         \
    \   while (k > 1 &&\n                   lt(cross(ch[k - 1] - ch[k - 2], pts[i]\
    \ - ch[k - 1]), 0))\n                --k;\n        }\n        ch[k++] = pts[i];\n\
    \    }\n    int t = k;\n    // left\n    for (int i = n - 2; i >= 0; --i) {\n\
    \        if (strict) {\n            while (k > t &&\n                   leq(cross(ch[k\
    \ - 1] - ch[k - 2], pts[i] - ch[k - 1]), 0))\n                --k;\n        }\
    \ else {\n            while (k > t &&\n                   lt(cross(ch[k - 1] -\
    \ ch[k - 2], pts[i] - ch[k - 1]), 0))\n                --k;\n        }\n     \
    \   ch[k++] = pts[i];\n    }\n    ch.resize(k - 1);\n    return ch;\n}\n#line\
    \ 7 \"test/yosupo/static_convex_hull.test.cpp\"\nusing namespace std;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int T;\n  \
    \  cin >> T;\n    while (T--) {\n        int N;\n        cin >> N;\n        vector<Vec>\
    \ pts(N);\n        for (auto& p : pts) cin >> p;\n        auto conv = convex_hull(pts);\n\
    \        cout << conv.size() << \"\\n\";\n        for (auto& p : conv)\n     \
    \       cout << (int)p.real() << \" \" << (int)p.imag() << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_convex_hull\"\n\n\
    #include <bits/stdc++.h>\n\n#include \"../../geometry/convex_hull.hpp\"\n#include\
    \ \"../../geometry/geometry.hpp\"\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int T;\n    cin >> T;\n    while (T--) {\n        int\
    \ N;\n        cin >> N;\n        vector<Vec> pts(N);\n        for (auto& p : pts)\
    \ cin >> p;\n        auto conv = convex_hull(pts);\n        cout << conv.size()\
    \ << \"\\n\";\n        for (auto& p : conv)\n            cout << (int)p.real()\
    \ << \" \" << (int)p.imag() << \"\\n\";\n    }\n}"
  dependsOn:
  - geometry/convex_hull.hpp
  - geometry/geometry.hpp
  isVerificationFile: true
  path: test/yosupo/static_convex_hull.test.cpp
  requiredBy: []
  timestamp: '2025-01-11 18:51:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/static_convex_hull.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/static_convex_hull.test.cpp
- /verify/test/yosupo/static_convex_hull.test.cpp.html
title: test/yosupo/static_convex_hull.test.cpp
---
