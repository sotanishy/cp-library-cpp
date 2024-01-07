---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: geometry/bisector.hpp
    title: geometry/bisector.hpp
  - icon: ':question:'
    path: geometry/dist.hpp
    title: geometry/dist.hpp
  - icon: ':question:'
    path: geometry/geometry.hpp
    title: Geometry
  - icon: ':question:'
    path: geometry/intersect.hpp
    title: geometry/intersect.hpp
  - icon: ':question:'
    path: geometry/intersection.hpp
    title: geometry/intersection.hpp
  - icon: ':heavy_check_mark:'
    path: geometry/triangle.hpp
    title: geometry/triangle.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"geometry/delaunay_diagram.hpp\"\n#include <queue>\n#include\
    \ <set>\n#include <utility>\n#include <vector>\n\n#line 2 \"geometry/geometry.hpp\"\
    \n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <complex>\n\
    #include <iostream>\n#include <numbers>\n#include <numeric>\n#line 10 \"geometry/geometry.hpp\"\
    \n\n// note that if T is of an integer type, std::abs does not work\nusing T =\
    \ double;\nusing Vec = std::complex<T>;\n\nstd::istream& operator>>(std::istream&\
    \ is, Vec& p) {\n    T x, y;\n    is >> x >> y;\n    p = {x, y};\n    return is;\n\
    }\n\nT dot(const Vec& a, const Vec& b) { return (std::conj(a) * b).real(); }\n\
    \nT cross(const Vec& a, const Vec& b) { return (std::conj(a) * b).imag(); }\n\n\
    constexpr T PI = std::numbers::pi_v<T>;\nconstexpr T eps = 1e-10;\ninline bool\
    \ eq(T a, T b) { return std::abs(a - b) <= eps; }\ninline bool eq(Vec a, Vec b)\
    \ { return std::abs(a - b) <= eps; }\ninline bool lt(T a, T b) { return a < b\
    \ - eps; }\ninline bool leq(T a, T b) { return a <= b + eps; }\n\nstruct Line\
    \ {\n    Vec p1, p2;\n    Line() = default;\n    Line(const Vec& p1, const Vec&\
    \ p2) : p1(p1), p2(p2) {}\n    Vec dir() const { return p2 - p1; }\n};\n\nstruct\
    \ Segment : Line {\n    using Line::Line;\n};\n\nstruct Circle {\n    Vec c;\n\
    \    T r;\n    Circle() = default;\n    Circle(const Vec& c, T r) : c(c), r(r)\
    \ {}\n};\n\nusing Polygon = std::vector<Vec>;\n\nVec rot(const Vec& a, T ang)\
    \ { return a * Vec(std::cos(ang), std::sin(ang)); }\n\nVec perp(const Vec& a)\
    \ { return Vec(-a.imag(), a.real()); }\n\nVec projection(const Line& l, const\
    \ Vec& p) {\n    return l.p1 + dot(p - l.p1, l.dir()) * l.dir() / std::norm(l.dir());\n\
    }\n\nVec reflection(const Line& l, const Vec& p) {\n    return T(2) * projection(l,\
    \ p) - p;\n}\n\n// 0: collinear\n// 1: counter-clockwise\n// -1: clockwise\nint\
    \ ccw(const Vec& a, const Vec& b, const Vec& c) {\n    if (eq(cross(b - a, c -\
    \ a), 0)) return 0;\n    if (lt(cross(b - a, c - a), 0)) return -1;\n    return\
    \ 1;\n}\n\nvoid sort_by_arg(std::vector<Vec>& pts) {\n    std::ranges::sort(pts,\
    \ [&](auto& p, auto& q) {\n        if ((p.imag() < 0) != (q.imag() < 0)) return\
    \ (p.imag() < 0);\n        if (cross(p, q) == 0) {\n            if (p == Vec(0,\
    \ 0))\n                return !(q.imag() < 0 || (q.imag() == 0 && q.real() > 0));\n\
    \            if (q == Vec(0, 0))\n                return (p.imag() < 0 || (p.imag()\
    \ == 0 && p.real() > 0));\n            return (p.real() > q.real());\n       \
    \ }\n        return (cross(p, q) > 0);\n    });\n}\n#line 3 \"geometry/intersect.hpp\"\
    \n\nbool intersect(const Segment& s, const Vec& p) {\n    Vec u = s.p1 - p, v\
    \ = s.p2 - p;\n    return eq(cross(u, v), 0) && leq(dot(u, v), 0);\n}\n\n// 0:\
    \ outside\n// 1: on the border\n// 2: inside\nint intersect(const Polygon& poly,\
    \ const Vec& p) {\n    const int n = poly.size();\n    bool in = 0;\n    for (int\
    \ i = 0; i < n; ++i) {\n        auto a = poly[i] - p, b = poly[(i + 1) % n] -\
    \ p;\n        if (eq(cross(a, b), 0) && (lt(dot(a, b), 0) || eq(dot(a, b), 0)))\n\
    \            return 1;\n        if (a.imag() > b.imag()) std::swap(a, b);\n  \
    \      if (leq(a.imag(), 0) && lt(0, b.imag()) && lt(cross(a, b), 0)) in ^= 1;\n\
    \    }\n    return in ? 2 : 0;\n}\n\nint intersect(const Segment& s, const Segment&\
    \ t) {\n    auto a = s.p1, b = s.p2;\n    auto c = t.p1, d = t.p2;\n    if (ccw(a,\
    \ b, c) != ccw(a, b, d) && ccw(c, d, a) != ccw(c, d, b)) return 2;\n    if (intersect(s,\
    \ c) || intersect(s, d) || intersect(t, a) ||\n        intersect(t, b))\n    \
    \    return 1;\n    return 0;\n}\n\n// true if they have positive area in common\
    \ or touch on the border\nbool intersect(const Polygon& poly1, const Polygon&\
    \ poly2) {\n    const int n = poly1.size();\n    const int m = poly2.size();\n\
    \    for (int i = 0; i < n; ++i) {\n        for (int j = 0; j < m; ++j) {\n  \
    \          if (intersect(Segment(poly1[i], poly1[(i + 1) % n]),\n            \
    \              Segment(poly2[j], poly2[(j + 1) % m]))) {\n                return\
    \ true;\n            }\n        }\n    }\n    return intersect(poly1, poly2[0])\
    \ || intersect(poly2, poly1[0]);\n}\n\n// 0: inside\n// 1: inscribe\n// 2: intersect\n\
    // 3: circumscribe\n// 4: outside\nint intersect(const Circle& c1, const Circle&\
    \ c2) {\n    T d = std::abs(c1.c - c2.c);\n    if (lt(d, std::abs(c2.r - c1.r)))\
    \ return 0;\n    if (eq(d, std::abs(c2.r - c1.r))) return 1;\n    if (eq(c1.r\
    \ + c2.r, d)) return 3;\n    if (lt(c1.r + c2.r, d)) return 4;\n    return 2;\n\
    }\n#line 4 \"geometry/dist.hpp\"\n\nT dist(const Line& l, const Vec& p) {\n  \
    \  return std::abs(cross(p - l.p1, l.dir())) / std::abs(l.dir());\n}\n\nT dist(const\
    \ Segment& s, const Vec& p) {\n    if (lt(dot(p - s.p1, s.dir()), 0)) return std::abs(p\
    \ - s.p1);\n    if (lt(dot(p - s.p2, -s.dir()), 0)) return std::abs(p - s.p2);\n\
    \    return std::abs(cross(p - s.p1, s.dir())) / std::abs(s.dir());\n}\n\nT dist(const\
    \ Segment& s, const Segment& t) {\n    if (intersect(s, t)) return T(0);\n   \
    \ return std::min(\n        {dist(s, t.p1), dist(s, t.p2), dist(t, s.p1), dist(t,\
    \ s.p2)});\n}\n#line 4 \"geometry/intersection.hpp\"\n\nVec intersection(const\
    \ Line& l, const Line& m) {\n    assert(!eq(cross(l.dir(), m.dir()), 0));  //\
    \ not parallel\n    Vec r = m.p1 - l.p1;\n    return l.p1 + cross(m.dir(), r)\
    \ / cross(m.dir(), l.dir()) * l.dir();\n}\n\nstd::vector<Vec> intersection(const\
    \ Circle& c, const Line& l) {\n    T d = dist(l, c.c);\n    if (lt(c.r, d)) return\
    \ {};  // no intersection\n    Vec e1 = l.dir() / std::abs(l.dir());\n    Vec\
    \ e2 = perp(e1);\n    if (ccw(c.c, l.p1, l.p2) == 1) e2 *= -1;\n    if (eq(c.r,\
    \ d)) return {c.c + d * e2};  // tangent\n    T t = std::sqrt(c.r * c.r - d *\
    \ d);\n    return {c.c + d * e2 + t * e1, c.c + d * e2 - t * e1};\n}\n\nstd::vector<Vec>\
    \ intersection(const Circle& c1, const Circle& c2) {\n    T d = std::abs(c1.c\
    \ - c2.c);\n    if (lt(c1.r + c2.r, d)) return {};  // outside\n    Vec e1 = (c2.c\
    \ - c1.c) / std::abs(c2.c - c1.c);\n    Vec e2 = perp(e1);\n    if (lt(d, std::abs(c2.r\
    \ - c1.r))) return {};                  // contain\n    if (eq(d, std::abs(c2.r\
    \ - c1.r))) return {c1.c + c1.r * e1};  // tangent\n    T x = (c1.r * c1.r - c2.r\
    \ * c2.r + d * d) / (2 * d);\n    T y = std::sqrt(c1.r * c1.r - x * x);\n    return\
    \ {c1.c + x * e1 + y * e2, c1.c + x * e1 - y * e2};\n}\n\nT area_intersection(const\
    \ Circle& c1, const Circle& c2) {\n    T d = std::abs(c2.c - c1.c);\n    if (leq(c1.r\
    \ + c2.r, d)) return 0;    // outside\n    if (leq(d, std::abs(c2.r - c1.r)))\
    \ {  // inside\n        T r = std::min(c1.r, c2.r);\n        return PI * r * r;\n\
    \    }\n    T ans = 0;\n    T a;\n    a = std::acos((c1.r * c1.r + d * d - c2.r\
    \ * c2.r) / (2 * c1.r * d));\n    ans += c1.r * c1.r * (a - std::sin(a) * std::cos(a));\n\
    \    a = std::acos((c2.r * c2.r + d * d - c1.r * c1.r) / (2 * c2.r * d));\n  \
    \  ans += c2.r * c2.r * (a - std::sin(a) * std::cos(a));\n    return ans;\n}\n\
    #line 4 \"geometry/bisector.hpp\"\n\nLine bisector(const Segment& s) {\n    auto\
    \ m = (s.p1 + s.p2) / T(2);\n    return Line(m, m + Vec(-s.dir().imag(), s.dir().real()));\n\
    }\n\nstd::pair<Line, Line> bisector(const Line& l, const Line& m) {\n    // parallel\n\
    \    if (eq(cross(l.dir(), m.dir()), 0)) {\n        auto n = Line(l.p1, l.p1 +\
    \ perp(l.dir()));\n        auto p = intersection(n, m);\n        auto m = (l.p1\
    \ + p) / T(2);\n        return {Line(m, m + l.dir()), Line()};\n    }\n    auto\
    \ p = intersection(l, m);\n    T ang = (std::arg(l.dir()) + std::arg(m.dir()))\
    \ / T(2);\n    auto b1 = Line(p, p + std::polar(T(1), ang));\n    auto b2 = Line(p,\
    \ p + std::polar(T(1), ang + PI / T(2)));\n    return {b1, b2};\n}\n#line 5 \"\
    geometry/triangle.hpp\"\n\nVec centroid(const Vec& A, const Vec& B, const Vec&\
    \ C) {\n    assert(ccw(A, B, C) != 0);\n    return (A + B + C) / T(3);\n}\n\n\
    Vec incenter(const Vec& A, const Vec& B, const Vec& C) {\n    assert(ccw(A, B,\
    \ C) != 0);\n    T a = std::abs(B - C);\n    T b = std::abs(C - A);\n    T c =\
    \ std::abs(A - B);\n    return (a * A + b * B + c * C) / (a + b + c);\n}\n\nVec\
    \ circumcenter(const Vec& A, const Vec& B, const Vec& C) {\n    assert(ccw(A,\
    \ B, C) != 0);\n    return intersection(bisector(Segment(A, B)), bisector(Segment(A,\
    \ C)));\n}\n\n// large error but beautiful\n// Vec circumcenter(const Vec& A,\
    \ const Vec& B, const Vec& C) {\n//     assert(ccw(A, B, C) != 0);\n//     Vec\
    \ p = C - B, q = A - C, r = B - A;\n//     T a = std::norm(p) * dot(q, r);\n//\
    \     T b = std::norm(q) * dot(r, p);\n//     T c = std::norm(r) * dot(p, q);\n\
    //     return (a*A + b*B + c*C) / (a + b + c);\n// }\n#line 9 \"geometry/delaunay_diagram.hpp\"\
    \n\nstd::vector<std::pair<int, int>> delaunay_diagram(std::vector<Vec> pts) {\n\
    \    const int n = pts.size();\n    constexpr T INF = 1e20;\n    // stores delaunay\
    \ edges\n    std::vector<std::pair<int, int>> edges;\n    // the sweep line moves\
    \ from left to right\n    // x coordinate of the sweepline\n    static T sweepx;\n\
    \n    // check if all points are collinear\n    bool ok = false;\n    for (int\
    \ i = 2; i < n; ++i) {\n        if (ccw(pts[0], pts[1], pts[i]) != 0) {\n    \
    \        ok = true;\n            break;\n        }\n    }\n    // handle degenerate\
    \ cases\n    if (!ok) {\n        // connect all points by a path\n        std::vector<std::pair<Vec,\
    \ int>> pi(n);\n        for (int i = 0; i < n; ++i) pi[i] = {pts[i], i};\n   \
    \     std::ranges::sort(pi, {}, [&](auto& p) {\n            return std::make_pair(p.first.real(),\
    \ p.first.imag());\n        });\n        for (int k = 0; k < n - 1; ++k) {\n \
    \           edges.emplace_back(pi[k].second, pi[k + 1].second);\n        }\n \
    \       return edges;\n    }\n\n    // represents a parabola given by the focus\
    \ p\n    // and the focus q of the next parabola\n    struct Parabola {\n    \
    \    Vec p;\n        mutable Vec q;\n        int i;\n        mutable int id =\
    \ 0;\n        Parabola(const Vec& p, const Vec& q, int i) : p(p), q(q), i(i) {}\n\
    \n        T gety(T x) const {\n            if (q.imag() == INF) return INF;\n\
    \            x += eps;\n            Vec m = (p + q) / T(2);\n            Vec dir\
    \ = rot(p - m, PI / 2);\n            T D = (x - p.real()) * (x - q.real());\n\
    \            return m.imag() + ((m.real() - x) * dir.real() +\n              \
    \                 std::sqrt(D) * std::abs(dir)) /\n                          \
    \        dir.imag();\n        }\n        bool operator<(T y) const { return gety(sweepx)\
    \ < y; }\n        bool operator<(const Parabola& o) const {\n            return\
    \ gety(sweepx) < o.gety(sweepx);\n        }\n    };\n\n    // maintains a list\
    \ of parabola\n    std::multiset<Parabola, std::less<>> beach;\n    using iterator\
    \ = decltype(beach)::iterator;\n\n    // represents an event\n    // id >= 0:\
    \ point event\n    // id < 0: vertex event\n    struct Event {\n        T x;\n\
    \        int id;\n        iterator it;\n        Event(T x, int id, iterator it)\
    \ : x(x), id(id), it(it) {}\n        bool operator>(const Event& e) const { return\
    \ x > e.x; }\n    };\n\n    // maintains a list of events\n    std::priority_queue<Event,\
    \ std::vector<Event>, std::greater<>> pq;\n    // true if the i-th vertex event\
    \ is still valid\n    std::vector<bool> valid(1);\n\n    int k = 1;  // next id\n\
    \n    // create vertex events\n    auto update = [&](const iterator& it) {\n \
    \       if (it->i <= -1 || it == beach.begin()) return;  // sentinels\n      \
    \  valid[it->id] = false;\n        auto a = std::prev(it);\n        // handle\
    \ a vertex event that occurs\n        // when 3 parabolas at (a->p, it->p, it->q)\
    \ coincide\n        if (eq(ccw(a->p, it->p, it->q), 0))\n            return; \
    \ // never coincide when collinear\n        // create a new event\n        it->id\
    \ = k++;\n        valid.push_back(true);\n        Vec c = circumcenter(a->p, it->p,\
    \ it->q);\n        // coordinate of the vertex event\n        T x = c.real() +\
    \ std::abs(c - it->p);\n        if (leq(sweepx, x) && leq(it->gety(x), a->gety(x)))\
    \ {\n            pq.emplace(x, -it->id, it);\n        }\n    };\n\n    auto add_edge\
    \ = [&](int i, int j) {\n        if (i != -1 && j != -1) edges.emplace_back(i,\
    \ j);\n    };\n\n    // rotate all points by a radian\n    // so that x coordinates\
    \ are distinct\n    for (auto& p : pts) p = rot(p, 1);\n\n    // sentinel\n  \
    \  beach.emplace(Vec(-INF, INF), Vec(-INF * 2, INF), -1);\n\n    // add all point\
    \ events\n    for (int i = 0; i < n; ++i) {\n        pq.emplace(pts[i].real(),\
    \ i, beach.end());\n    }\n\n    while (!pq.empty()) {\n        auto e = pq.top();\n\
    \        pq.pop();\n        sweepx = e.x;\n        if (e.id >= 0) {\n        \
    \    // point event\n            int i = e.id;\n            auto p = pts[i];\n\
    \            // (c) -> (c, p, c)\n            auto c = beach.lower_bound(p.imag());\n\
    \            auto b = beach.insert(c, Parabola(p, c->p, i));\n            auto\
    \ a = beach.insert(b, Parabola(c->p, p, c->i));\n            add_edge(i, c->i);\n\
    \            update(a);\n            update(b);\n            update(c);\n    \
    \    } else if (valid[-e.id]) {\n            // vertex event\n            // (a,\
    \ e, b) -> (a, b)\n            auto a = std::prev(e.it);\n            auto b =\
    \ std::next(e.it);\n            beach.erase(e.it);\n            a->q = b->p;\n\
    \            add_edge(a->i, b->i);\n            update(a);\n            update(b);\n\
    \        }\n    }\n\n    return edges;\n}\n"
  code: "#pragma once\n#include <queue>\n#include <set>\n#include <utility>\n#include\
    \ <vector>\n\n#include \"geometry.hpp\"\n#include \"triangle.hpp\"\n\nstd::vector<std::pair<int,\
    \ int>> delaunay_diagram(std::vector<Vec> pts) {\n    const int n = pts.size();\n\
    \    constexpr T INF = 1e20;\n    // stores delaunay edges\n    std::vector<std::pair<int,\
    \ int>> edges;\n    // the sweep line moves from left to right\n    // x coordinate\
    \ of the sweepline\n    static T sweepx;\n\n    // check if all points are collinear\n\
    \    bool ok = false;\n    for (int i = 2; i < n; ++i) {\n        if (ccw(pts[0],\
    \ pts[1], pts[i]) != 0) {\n            ok = true;\n            break;\n      \
    \  }\n    }\n    // handle degenerate cases\n    if (!ok) {\n        // connect\
    \ all points by a path\n        std::vector<std::pair<Vec, int>> pi(n);\n    \
    \    for (int i = 0; i < n; ++i) pi[i] = {pts[i], i};\n        std::ranges::sort(pi,\
    \ {}, [&](auto& p) {\n            return std::make_pair(p.first.real(), p.first.imag());\n\
    \        });\n        for (int k = 0; k < n - 1; ++k) {\n            edges.emplace_back(pi[k].second,\
    \ pi[k + 1].second);\n        }\n        return edges;\n    }\n\n    // represents\
    \ a parabola given by the focus p\n    // and the focus q of the next parabola\n\
    \    struct Parabola {\n        Vec p;\n        mutable Vec q;\n        int i;\n\
    \        mutable int id = 0;\n        Parabola(const Vec& p, const Vec& q, int\
    \ i) : p(p), q(q), i(i) {}\n\n        T gety(T x) const {\n            if (q.imag()\
    \ == INF) return INF;\n            x += eps;\n            Vec m = (p + q) / T(2);\n\
    \            Vec dir = rot(p - m, PI / 2);\n            T D = (x - p.real()) *\
    \ (x - q.real());\n            return m.imag() + ((m.real() - x) * dir.real()\
    \ +\n                               std::sqrt(D) * std::abs(dir)) /\n        \
    \                          dir.imag();\n        }\n        bool operator<(T y)\
    \ const { return gety(sweepx) < y; }\n        bool operator<(const Parabola& o)\
    \ const {\n            return gety(sweepx) < o.gety(sweepx);\n        }\n    };\n\
    \n    // maintains a list of parabola\n    std::multiset<Parabola, std::less<>>\
    \ beach;\n    using iterator = decltype(beach)::iterator;\n\n    // represents\
    \ an event\n    // id >= 0: point event\n    // id < 0: vertex event\n    struct\
    \ Event {\n        T x;\n        int id;\n        iterator it;\n        Event(T\
    \ x, int id, iterator it) : x(x), id(id), it(it) {}\n        bool operator>(const\
    \ Event& e) const { return x > e.x; }\n    };\n\n    // maintains a list of events\n\
    \    std::priority_queue<Event, std::vector<Event>, std::greater<>> pq;\n    //\
    \ true if the i-th vertex event is still valid\n    std::vector<bool> valid(1);\n\
    \n    int k = 1;  // next id\n\n    // create vertex events\n    auto update =\
    \ [&](const iterator& it) {\n        if (it->i <= -1 || it == beach.begin()) return;\
    \  // sentinels\n        valid[it->id] = false;\n        auto a = std::prev(it);\n\
    \        // handle a vertex event that occurs\n        // when 3 parabolas at\
    \ (a->p, it->p, it->q) coincide\n        if (eq(ccw(a->p, it->p, it->q), 0))\n\
    \            return;  // never coincide when collinear\n        // create a new\
    \ event\n        it->id = k++;\n        valid.push_back(true);\n        Vec c\
    \ = circumcenter(a->p, it->p, it->q);\n        // coordinate of the vertex event\n\
    \        T x = c.real() + std::abs(c - it->p);\n        if (leq(sweepx, x) &&\
    \ leq(it->gety(x), a->gety(x))) {\n            pq.emplace(x, -it->id, it);\n \
    \       }\n    };\n\n    auto add_edge = [&](int i, int j) {\n        if (i !=\
    \ -1 && j != -1) edges.emplace_back(i, j);\n    };\n\n    // rotate all points\
    \ by a radian\n    // so that x coordinates are distinct\n    for (auto& p : pts)\
    \ p = rot(p, 1);\n\n    // sentinel\n    beach.emplace(Vec(-INF, INF), Vec(-INF\
    \ * 2, INF), -1);\n\n    // add all point events\n    for (int i = 0; i < n; ++i)\
    \ {\n        pq.emplace(pts[i].real(), i, beach.end());\n    }\n\n    while (!pq.empty())\
    \ {\n        auto e = pq.top();\n        pq.pop();\n        sweepx = e.x;\n  \
    \      if (e.id >= 0) {\n            // point event\n            int i = e.id;\n\
    \            auto p = pts[i];\n            // (c) -> (c, p, c)\n            auto\
    \ c = beach.lower_bound(p.imag());\n            auto b = beach.insert(c, Parabola(p,\
    \ c->p, i));\n            auto a = beach.insert(b, Parabola(c->p, p, c->i));\n\
    \            add_edge(i, c->i);\n            update(a);\n            update(b);\n\
    \            update(c);\n        } else if (valid[-e.id]) {\n            // vertex\
    \ event\n            // (a, e, b) -> (a, b)\n            auto a = std::prev(e.it);\n\
    \            auto b = std::next(e.it);\n            beach.erase(e.it);\n     \
    \       a->q = b->p;\n            add_edge(a->i, b->i);\n            update(a);\n\
    \            update(b);\n        }\n    }\n\n    return edges;\n}\n"
  dependsOn:
  - geometry/geometry.hpp
  - geometry/triangle.hpp
  - geometry/bisector.hpp
  - geometry/intersection.hpp
  - geometry/dist.hpp
  - geometry/intersect.hpp
  isVerificationFile: false
  path: geometry/delaunay_diagram.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:08:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/delaunay_diagram.hpp
layout: document
title: Delaunay Diagram
---

## Description

与えられた点の Delaunay 図は，Voronoi 図の双対であり，Voronoi 領域の隣接関係を表す．

Voronoi 図とは，平面に配置された母点に対して，平面の各点がどの母点に最も近いかによって領域分けされた図である．

Delaunay 辺の本数は Euler の多面体定理より $O(n)$ 本である．また，Euclidean MST は Delaunay 図の部分グラフである．

Delaunay 図は平面走査アルゴリズムである Fortune のアルゴリズムで求めることができる．

## Operations

- `vector<pair<int, int>> delaunay_diagram(vector<Vec> pts)`
    - `pts` から定まる Delaunay 図の辺を返す
    - 時間計算量: $O(n\log n)$

## Reference

- [[Tutorial] Voronoi Diagram and Delaunay Triangulation in O(n log n) with Fortune's Algorithm - Codeforces](https://codeforces.com/blog/entry/85638?f0a28=1)
- [ユークリッド最小全域木 - SlideShare](https://www.slideshare.net/maroonrk/ss-65378126)
- verify: [https://atcoder.jp/contests/abc181/submissions/31463286](https://atcoder.jp/contests/abc181/submissions/31463286)
