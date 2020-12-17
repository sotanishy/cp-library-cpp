---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/quadtree.cpp
    title: Quadtree
  - icon: ':question:'
    path: misc/compress.cpp
    title: Coordinate Compression
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/point_add_rectangle_sum.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\n\n#line\
    \ 2 \"data-structure/quadtree.cpp\"\n#include <memory>\n#include <vector>\n\n\
    /*\n * @brief Quadtree\n * @docs docs/data-structure/quadtree.md\n */\ntemplate\
    \ <typename M>\nclass Quadtree {\n    using T = typename M::T;\n\npublic:\n  \
    \  Quadtree() = default;\n    Quadtree(int n) : root(std::make_unique<Node>())\
    \ {\n        size = 1;\n        while (size < n) size <<= 1;\n    }\n\n    T get(int\
    \ x, int y) const { return fold(x, x + 1, y, y + 1); }\n\n    void update(int\
    \ x, int y, const T& val) const { update(x, y, val, root, 0, 0, size); }\n\n \
    \   T fold(int l, int r, int b, int t) const { return fold(l, r, b, t, root, 0,\
    \ 0, size); }\n\nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr ch[4];\n        Node() :\
    \ val(M::id) {}\n    };\n\n    const node_ptr root;\n    int size;\n\n    void\
    \ update(int x, int y, const T& val, const node_ptr& n, int p, int q, int len)\
    \ const {\n        if (len == 1) {\n            n->val = val;\n            return;\n\
    \        }\n        len /= 2;\n        for (int i = 3; i >= 0; --i) {\n      \
    \      if (x >= p + len * (i >> 1) && y >= q + len * (i & 1)) {\n            \
    \    if (!n->ch[i]) n->ch[i] = std::make_unique<Node>();\n                update(x,\
    \ y, val, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len);\n           \
    \     break;\n            }\n        }\n        n->val = M::id;\n        for (int\
    \ i = 0; i < 4; ++i) {\n            if (n->ch[i]) n->val = M::op(n->val, n->ch[i]->val);\n\
    \        }\n    }\n\n    T fold(int l, int r, int b, int t, const node_ptr& n,\
    \ int p, int q, int len) const {\n        if (!n) return M::id;\n        if (p\
    \ + len <= l || r <= p || q + len <= b || t <= q) {\n            return M::id;\n\
    \        }\n        if (l <= p && p + len <= r && b <= q && q + len <= t) {\n\
    \            return n->val;\n        }\n        len /= 2;\n        T val = M::id;\n\
    \        for (int i = 0; i < 4; ++i) {\n            if (n->ch[i]) val = M::op(val,\
    \ fold(l, r, b, t, n->ch[i], p + len * (i >> 1), q + len * (i & 1), len));\n \
    \       }\n        return val;\n    }\n};\n#line 2 \"misc/compress.cpp\"\n#include\
    \ <algorithm>\n#line 4 \"misc/compress.cpp\"\n\n/*\n * @brief Coordinate Compression\n\
    \ */\ntemplate <typename T>\nclass Compress {\npublic:\n    Compress() = default;\n\
    \    explicit Compress(const std::vector<T>& vs) : xs(vs) {\n        std::sort(xs.begin(),\
    \ xs.end());\n        xs.erase(std::unique(xs.begin(), xs.end()), xs.end());\n\
    \    }\n\n    int compress(const T& x) const {\n        return std::lower_bound(xs.begin(),\
    \ xs.end(), x) - xs.begin();\n    }\n\n    std::vector<int> compress(const std::vector<T>&\
    \ vs) const {\n        std::vector<int> ret;\n        std::transform(vs.begin(),\
    \ vs.end(), std::back_inserter(ret), [&](const T& x) {\n            return compress(x);\n\
    \        });\n        return ret;\n    }\n\n    T decompress(int i) const {\n\
    \        return xs[i];\n    }\n\nprivate:\n    std::vector<T> xs;\n};\n#line 5\
    \ \"test/yosupo/point_add_rectangle_sum.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nstruct AddMonoid {\n    using T\
    \ = ll;\n    static constexpr T id = 0;\n    static T op(T a, T b) { return a\
    \ + b; }\n};\n\nstruct Query {\n    int t, x, y, w, l, d, r, u;\n    Query(int\
    \ t, int x, int y, int w) : t(t), x(x), y(y), w(w) {}\n    Query(int t, int l,\
    \ int d, int r, int u) : t(t), l(l), d(d), r(r), u(u) {}\n};\n\nint main() {\n\
    \    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n    int N, Q;\n\
    \    cin >> N >> Q;\n    vector<int> xs, ys;\n    vector<int> x(N), y(N), w(N);\n\
    \    for (int i = 0; i < N; ++i) {\n        cin >> x[i] >> y[i] >> w[i];\n   \
    \ }\n    xs.insert(xs.end(), x.begin(), x.end());\n    ys.insert(ys.end(), y.begin(),\
    \ y.end());\n    vector<Query> queries;\n    for (int i = 0; i < Q; ++i) {\n \
    \       int t;\n        cin >> t;\n        if (t == 0) {\n            int x, y,\
    \ w;\n            cin >> x >> y >> w;\n            queries.emplace_back(t, x,\
    \ y, w);\n            xs.push_back(x);\n            ys.push_back(y);\n       \
    \ } else {\n            int l, d, r, u;\n            cin >> l >> d >> r >> u;\n\
    \            queries.emplace_back(t, l, d, r, u);\n            xs.push_back(l);\n\
    \            ys.push_back(d);\n            xs.push_back(r);\n            ys.push_back(u);\n\
    \        }\n    }\n    Compress<int> cx(xs), cy(ys);\n    x = cx.compress(x);\n\
    \    y = cy.compress(y);\n    Quadtree<AddMonoid> qt(xs.size());\n    for (int\
    \ i = 0; i < N; ++i) {\n        qt.update(x[i], y[i], qt.get(x[i], y[i]) + w[i]);\n\
    \    }\n\n    for (auto& q : queries) {\n        if (q.t == 0) {\n           \
    \ int a = cx.compress(q.x), b = cy.compress(q.y);\n            qt.update(a, b,\
    \ qt.get(a, b) + q.w);\n        } else {\n            int l = cx.compress(q.l),\
    \ r = cx.compress(q.r);\n            int d = cy.compress(q.d), u = cy.compress(q.u);\n\
    \            cout << qt.fold(l, r, d, u) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include \"../../data-structure/quadtree.cpp\"\n#include \"../../misc/compress.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    struct AddMonoid {\n    using T = ll;\n    static constexpr T id = 0;\n    static\
    \ T op(T a, T b) { return a + b; }\n};\n\nstruct Query {\n    int t, x, y, w,\
    \ l, d, r, u;\n    Query(int t, int x, int y, int w) : t(t), x(x), y(y), w(w)\
    \ {}\n    Query(int t, int l, int d, int r, int u) : t(t), l(l), d(d), r(r), u(u)\
    \ {}\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<int> xs, ys;\n    vector<int>\
    \ x(N), y(N), w(N);\n    for (int i = 0; i < N; ++i) {\n        cin >> x[i] >>\
    \ y[i] >> w[i];\n    }\n    xs.insert(xs.end(), x.begin(), x.end());\n    ys.insert(ys.end(),\
    \ y.begin(), y.end());\n    vector<Query> queries;\n    for (int i = 0; i < Q;\
    \ ++i) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n         \
    \   int x, y, w;\n            cin >> x >> y >> w;\n            queries.emplace_back(t,\
    \ x, y, w);\n            xs.push_back(x);\n            ys.push_back(y);\n    \
    \    } else {\n            int l, d, r, u;\n            cin >> l >> d >> r >>\
    \ u;\n            queries.emplace_back(t, l, d, r, u);\n            xs.push_back(l);\n\
    \            ys.push_back(d);\n            xs.push_back(r);\n            ys.push_back(u);\n\
    \        }\n    }\n    Compress<int> cx(xs), cy(ys);\n    x = cx.compress(x);\n\
    \    y = cy.compress(y);\n    Quadtree<AddMonoid> qt(xs.size());\n    for (int\
    \ i = 0; i < N; ++i) {\n        qt.update(x[i], y[i], qt.get(x[i], y[i]) + w[i]);\n\
    \    }\n\n    for (auto& q : queries) {\n        if (q.t == 0) {\n           \
    \ int a = cx.compress(q.x), b = cy.compress(q.y);\n            qt.update(a, b,\
    \ qt.get(a, b) + q.w);\n        } else {\n            int l = cx.compress(q.l),\
    \ r = cx.compress(q.r);\n            int d = cy.compress(q.d), u = cy.compress(q.u);\n\
    \            cout << qt.fold(l, r, d, u) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/quadtree.cpp
  - misc/compress.cpp
  isVerificationFile: true
  path: test/yosupo/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-27 21:47:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp.html
title: test/yosupo/point_add_rectangle_sum.test.cpp
---
