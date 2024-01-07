---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/cht/convex_hull_trick_binsearchtree.hpp
    title: Convex Hull Trick (Binary Search Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"test/yosupo/line_add_get_min.cht.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n#line 2 \"data-structure/cht/convex_hull_trick_binsearchtree.hpp\"\
    \n#include <cassert>\n#include <limits>\n#include <set>\n#include <utility>\n\n\
    template <typename T>\nclass ConvexHullTrick {\n   public:\n    void add(T a,\
    \ T b) {\n        a = -a, b = -b;\n        auto m = lines.insert({a, b, 0});\n\
    \        auto l = m, r = m;\n        ++r;\n        while (update(m, r)) {\n  \
    \          r = lines.erase(r);\n        }\n        if (l != lines.begin() && update(--l,\
    \ m)) {\n            m = lines.erase(m);\n            update(l, m);\n        }\n\
    \        m = l;\n        while (l != lines.begin() && (--l)->p >= m->p) {\n  \
    \          update(l, lines.erase(m));\n            m = l;\n        }\n    }\n\n\
    \    T get(T x) const {\n        assert(!lines.empty());\n        auto it = *lines.lower_bound(x);\n\
    \        return -(it.a * x + it.b);\n    }\n\n   private:\n    struct Line {\n\
    \        mutable T a, b;    // ax + b\n        mutable double p;  // intersection\
    \ point with the next line\n        bool operator<(const Line& o) const { return\
    \ a < o.a; }\n        bool operator<(T x) const { return p < x; }\n    };\n\n\
    \    using iterator = typename std::multiset<Line, std::less<>>::iterator;\n \
    \   static constexpr double INF = std::numeric_limits<double>::max() / 2;\n\n\
    \    std::multiset<Line, std::less<>> lines;\n\n    bool update(iterator x, iterator\
    \ y) const {\n        if (y == lines.end()) {\n            x->p = INF;\n     \
    \       return false;\n        }\n        if (x->a == y->a) {\n            x->p\
    \ = (x->b > y->b ? INF : -INF);\n        } else {\n            x->p = 1.0 * (y->b\
    \ - x->b) / (x->a - y->a);\n        }\n        return x->p >= y->p;\n    }\n};\n\
    #line 4 \"test/yosupo/line_add_get_min.cht.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    ConvexHullTrick<ll>\
    \ cht;\n    for (int i = 0; i < N; ++i) {\n        ll a, b;\n        cin >> a\
    \ >> b;\n        cht.add(a, b);\n    }\n    while (Q--) {\n        int t;\n  \
    \      cin >> t;\n        if (t == 0) {\n            ll a, b;\n            cin\
    \ >> a >> b;\n            cht.add(a, b);\n        } else {\n            int p;\n\
    \            cin >> p;\n            cout << cht.get(p) << \"\\n\";\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n\n\
    #include \"../../data-structure/cht/convex_hull_trick_binsearchtree.hpp\"\n\n\
    #include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int N, Q;\n    cin >> N >> Q;\n    ConvexHullTrick<ll> cht;\n    for (int\
    \ i = 0; i < N; ++i) {\n        ll a, b;\n        cin >> a >> b;\n        cht.add(a,\
    \ b);\n    }\n    while (Q--) {\n        int t;\n        cin >> t;\n        if\
    \ (t == 0) {\n            ll a, b;\n            cin >> a >> b;\n            cht.add(a,\
    \ b);\n        } else {\n            int p;\n            cin >> p;\n         \
    \   cout << cht.get(p) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/cht/convex_hull_trick_binsearchtree.hpp
  isVerificationFile: true
  path: test/yosupo/line_add_get_min.cht.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/line_add_get_min.cht.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/line_add_get_min.cht.test.cpp
- /verify/test/yosupo/line_add_get_min.cht.test.cpp.html
title: test/yosupo/line_add_get_min.cht.test.cpp
---
