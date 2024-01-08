---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/persistent_segment_tree.hpp
    title: Persistent Segment Tree
  - icon: ':question:'
    path: misc/compress.hpp
    title: Coordinate Compression
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 2 \"data-structure/segtree/persistent_segment_tree.hpp\"\
    \n#include <bit>\n#line 6 \"data-structure/segtree/persistent_segment_tree.hpp\"\
    \n\n/**\n * @brief Persistent Segment Tree\n */\ntemplate <typename M>\nclass\
    \ PersistentSegmentTree {\n    using T = M::T;\n\n   public:\n    PersistentSegmentTree()\
    \ = default;\n    explicit PersistentSegmentTree(int n)\n        : PersistentSegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    explicit PersistentSegmentTree(const std::vector<T>& v)\n\
    \        : root(std::make_shared<Node>()), size(std::bit_ceil(v.size())) {\n \
    \       build(v, root, 0, size);\n    }\n\n    T operator[](int k) const { return\
    \ fold(k, k + 1); }\n\n    PersistentSegmentTree update(int k, const T& x) const\
    \ {\n        return PersistentSegmentTree(update(k, x, root, 0, size), size);\n\
    \    }\n\n    T fold(int l, int r) const { return fold(l, r, root, 0, size); }\n\
    \n   private:\n    struct Node;\n    using node_ptr = std::shared_ptr<Node>;\n\
    \n    struct Node {\n        T val;\n        node_ptr left, right;\n        Node()\
    \ : val(M::id()), left(nullptr), right(nullptr) {}\n        Node(const T& val,\
    \ const node_ptr& left, const node_ptr& right)\n            : val(val), left(left),\
    \ right(right) {}\n    };\n\n    node_ptr root;\n    int size;\n\n    PersistentSegmentTree(const\
    \ node_ptr& root, int size)\n        : root(root), size(size) {}\n\n    void build(const\
    \ std::vector<T>& v, const node_ptr& n, int l, int r) const {\n        if (r -\
    \ l == 1) {\n            n->val = l < (int)v.size() ? v[l] : M::id();\n      \
    \      return;\n        }\n        int m = std::midpoint(l, r);\n        n->left\
    \ = std::make_shared<Node>();\n        build(v, n->left, l, m);\n        n->right\
    \ = std::make_shared<Node>();\n        build(v, n->right, m, r);\n        n->val\
    \ = M::op(n->left->val, n->right->val);\n    }\n\n    node_ptr update(int k, const\
    \ T& x, const node_ptr& n, int l, int r) const {\n        if (r - l == 1) {\n\
    \            return std::make_shared<Node>(x, nullptr, nullptr);\n        }\n\
    \        int m = std::midpoint(l, r);\n        if (k < m) {\n            auto\
    \ left = update(k, x, n->left, l, m);\n            T val = M::op(left->val, n->right->val);\n\
    \            return std::make_shared<Node>(val, left, n->right);\n        } else\
    \ {\n            auto right = update(k, x, n->right, m, r);\n            T val\
    \ = M::op(n->left->val, right->val);\n            return std::make_shared<Node>(val,\
    \ n->left, right);\n        }\n    }\n\n    T fold(int a, int b, const node_ptr&\
    \ n, int l, int r) const {\n        if (r <= a || b <= l) return M::id();\n  \
    \      if (a <= l && r <= b) return n->val;\n        int m = std::midpoint(l,\
    \ r);\n        return M::op(fold(a, b, n->left, l, m), fold(a, b, n->right, m,\
    \ r));\n    }\n};\n#line 4 \"misc/compress.hpp\"\n\n/**\n * @brief Coordinate\
    \ Compression\n */\ntemplate <typename T>\nclass Compress {\n   public:\n    Compress()\
    \ = default;\n    explicit Compress(const std::vector<T>& vs) : xs(vs) {\n   \
    \     std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n    }\n\n    int compress(const T& x) const {\n        return std::ranges::lower_bound(xs,\
    \ x) - xs.begin();\n    }\n\n    std::vector<int> compress(std::vector<T> vs)\
    \ const {\n        std::ranges::transform(vs, vs.begin(),\n                  \
    \             [&](const T& x) { return compress(x); });\n        return vs;\n\
    \    }\n\n    T decompress(int i) const { return xs[i]; }\n\n    int size() const\
    \ { return xs.size(); }\n\n   private:\n    std::vector<T> xs;\n};\n#line 7 \"\
    test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp\"\nusing namespace\
    \ std;\nusing ll = long long;\n\nstruct AddMonoid {\n    using T = ll;\n    static\
    \ T id() { return 0; }\n    static T op(T a, T b) { return a + b; }\n};\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int N, Q;\n    cin >> N >> Q;\n    vector<int> xs, ys;\n    vector<int> x(N),\
    \ y(N), w(N);\n    vector<int> l(Q), d(Q), r(Q), u(Q);\n    for (int i = 0; i\
    \ < N; ++i) {\n        cin >> x[i] >> y[i] >> w[i];\n        xs.push_back(x[i]);\n\
    \        ys.push_back(y[i]);\n    }\n    for (int i = 0; i < Q; ++i) {\n     \
    \   cin >> l[i] >> d[i] >> r[i] >> u[i];\n        xs.push_back(l[i]);\n      \
    \  ys.push_back(d[i]);\n        xs.push_back(r[i]);\n        ys.push_back(u[i]);\n\
    \    }\n    xs.push_back(-1);\n    ys.push_back(-1);\n    Compress<int> cx(xs),\
    \ cy(ys);\n    x = cx.compress(x);\n    y = cy.compress(y);\n    l = cx.compress(l);\n\
    \    d = cy.compress(d);\n    r = cx.compress(r);\n    u = cy.compress(u);\n \
    \   int M = xs.size();\n    vector<vector<pair<int, int>>> points(M);\n    for\
    \ (int i = 0; i < N; ++i) {\n        points[x[i]].emplace_back(y[i], w[i]);\n\
    \    }\n    vector<PersistentSegmentTree<AddMonoid>> st(M);\n    st[0] = PersistentSegmentTree<AddMonoid>(M);\n\
    \    for (int x = 0; x < M; ++x) {\n        if (x > 0) st[x] = st[x - 1];\n  \
    \      auto tmp = st.back();\n        for (auto& p : points[x]) {\n          \
    \  int y, w;\n            tie(y, w) = p;\n            st[x] = st[x].update(y,\
    \ st[x][y] + w);\n        }\n    }\n    for (int i = 0; i < Q; ++i) {\n      \
    \  ll ans = st[r[i] - 1].fold(d[i], u[i]) - st[l[i] - 1].fold(d[i], u[i]);\n \
    \       cout << ans << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../data-structure/segtree/persistent_segment_tree.hpp\"\
    \n#include \"../../misc/compress.hpp\"\nusing namespace std;\nusing ll = long\
    \ long;\n\nstruct AddMonoid {\n    using T = ll;\n    static T id() { return 0;\
    \ }\n    static T op(T a, T b) { return a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> xs,\
    \ ys;\n    vector<int> x(N), y(N), w(N);\n    vector<int> l(Q), d(Q), r(Q), u(Q);\n\
    \    for (int i = 0; i < N; ++i) {\n        cin >> x[i] >> y[i] >> w[i];\n   \
    \     xs.push_back(x[i]);\n        ys.push_back(y[i]);\n    }\n    for (int i\
    \ = 0; i < Q; ++i) {\n        cin >> l[i] >> d[i] >> r[i] >> u[i];\n        xs.push_back(l[i]);\n\
    \        ys.push_back(d[i]);\n        xs.push_back(r[i]);\n        ys.push_back(u[i]);\n\
    \    }\n    xs.push_back(-1);\n    ys.push_back(-1);\n    Compress<int> cx(xs),\
    \ cy(ys);\n    x = cx.compress(x);\n    y = cy.compress(y);\n    l = cx.compress(l);\n\
    \    d = cy.compress(d);\n    r = cx.compress(r);\n    u = cy.compress(u);\n \
    \   int M = xs.size();\n    vector<vector<pair<int, int>>> points(M);\n    for\
    \ (int i = 0; i < N; ++i) {\n        points[x[i]].emplace_back(y[i], w[i]);\n\
    \    }\n    vector<PersistentSegmentTree<AddMonoid>> st(M);\n    st[0] = PersistentSegmentTree<AddMonoid>(M);\n\
    \    for (int x = 0; x < M; ++x) {\n        if (x > 0) st[x] = st[x - 1];\n  \
    \      auto tmp = st.back();\n        for (auto& p : points[x]) {\n          \
    \  int y, w;\n            tie(y, w) = p;\n            st[x] = st[x].update(y,\
    \ st[x][y] + w);\n        }\n    }\n    for (int i = 0; i < Q; ++i) {\n      \
    \  ll ans = st[r[i] - 1].fold(d[i], u[i]) - st[l[i] - 1].fold(d[i], u[i]);\n \
    \       cout << ans << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/segtree/persistent_segment_tree.hpp
  - misc/compress.hpp
  isVerificationFile: true
  path: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
- /verify/test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp.html
title: test/yosupo/rectangle_sum.persistent_segment_tree.test.cpp
---
