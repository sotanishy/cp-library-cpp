---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/lazy_segment_tree.hpp
    title: Segment Tree with Lazy Propagation
  - icon: ':heavy_check_mark:'
    path: misc/rectangle_union.hpp
    title: Area of Union of Rectangles
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/area_of_union_of_rectangles
    links:
    - https://judge.yosupo.jp/problem/area_of_union_of_rectangles
  bundledCode: "#line 1 \"test/yosupo/area_of_union_of_rectangles.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\n\n\
    #include <bits/stdc++.h>\n\n#line 4 \"misc/rectangle_union.hpp\"\n\n#line 3 \"\
    data-structure/segtree/lazy_segment_tree.hpp\"\n#include <bit>\n#line 6 \"data-structure/segtree/lazy_segment_tree.hpp\"\
    \n\ntemplate <typename M, typename O,\n          typename M::T (*act)(typename\
    \ M::T, typename O::T)>\nclass LazySegmentTree {\n    using T = M::T;\n    using\
    \ E = O::T;\n\n   public:\n    LazySegmentTree() = default;\n    explicit LazySegmentTree(int\
    \ n)\n        : LazySegmentTree(std::vector<T>(n, M::id())) {}\n    explicit LazySegmentTree(const\
    \ std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\n          node(2\
    \ * size, M::id()),\n          lazy(2 * size, O::id()) {\n        std::ranges::copy(v,\
    \ node.begin() + size);\n        for (int i = size - 1; i > 0; --i) {\n      \
    \      node[i] = M::op(node[2 * i], node[2 * i + 1]);\n        }\n    }\n\n  \
    \  T operator[](int k) { return fold(k, k + 1); }\n\n    void update(int l, int\
    \ r, const E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int l, int r)\
    \ { return fold(l, r, 1, 0, size); }\n\n    T fold_all() {\n        push(1);\n\
    \        return node[1];\n    }\n\n    template <typename F>\n    int find_first(int\
    \ l, F cond) {\n        T v = M::id();\n        return find_first(l, size, 1,\
    \ 0, size, v, cond);\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) {\n        T v = M::id();\n        return find_last(0, r, 1, 0, size,\
    \ v, cond);\n    }\n\n   private:\n    int size;\n    std::vector<T> node;\n \
    \   std::vector<E> lazy;\n\n    void push(int k) {\n        if (lazy[k] == O::id())\
    \ return;\n        if (k < size) {\n            lazy[2 * k] = O::op(lazy[2 * k],\
    \ lazy[k]);\n            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);\n\
    \        }\n        node[k] = act(node[k], lazy[k]);\n        lazy[k] = O::id();\n\
    \    }\n\n    void update(int a, int b, const E& x, int k, int l, int r) {\n \
    \       push(k);\n        if (r <= a || b <= l) return;\n        if (a <= l &&\
    \ r <= b) {\n            lazy[k] = O::op(lazy[k], x);\n            push(k);\n\
    \            return;\n        }\n        int m = std::midpoint(l, r);\n      \
    \  update(a, b, x, 2 * k, l, m);\n        update(a, b, x, 2 * k + 1, m, r);\n\
    \        node[k] = M::op(node[2 * k], node[2 * k + 1]);\n    }\n\n    T fold(int\
    \ a, int b, int k, int l, int r) {\n        push(k);\n        if (r <= a || b\
    \ <= l) return M::id();\n        if (a <= l && r <= b) return node[k];\n     \
    \   int m = std::midpoint(l, r);\n        return M::op(fold(a, b, 2 * k, l, m),\
    \ fold(a, b, 2 * k + 1, m, r));\n    }\n\n    template <typename F>\n    int find_first(int\
    \ a, int b, int k, int l, int r, T& v, F cond) {\n        push(k);\n        if\
    \ (r <= a) return -1;\n        if (b <= l) return l;\n        if (a <= l && r\
    \ <= b && !cond(M::op(v, node[k]))) {\n            v = M::op(v, node[k]);\n  \
    \          return -1;\n        }\n        if (r - l == 1) return r;\n        int\
    \ m = std::midpoint(l, r);\n        int res = find_first(a, b, 2 * k, l, m, v,\
    \ cond);\n        if (res != -1) return res;\n        return find_first(a, b,\
    \ 2 * k + 1, m, r, v, cond);\n    }\n\n    template <typename F>\n    int find_last(int\
    \ a, int b, int k, int l, int r, T& v, F cond) {\n        push(k);\n        if\
    \ (b <= l) return -1;\n        if (r <= a) return r;\n        if (a <= l && r\
    \ <= b && !cond(M::op(node[k], v))) {\n            v = M::op(node[k], v);\n  \
    \          return -1;\n        }\n        if (r - l == 1) return l;\n        int\
    \ m = std::midpoint(l, r);\n        int res = find_last(a, b, 2 * k + 1, m, r,\
    \ v, cond);\n        if (res != -1) return res;\n        return find_last(a, b,\
    \ 2 * k, l, m, v, cond);\n    }\n};\n#line 6 \"misc/rectangle_union.hpp\"\n\n\
    /**\n * @brief Area of Union of Rectangles\n */\nstruct CountMinMonoid {\n   \
    \ using T = std::pair<int, int>;  // min, count\n    static T id() { return {(1u\
    \ << 31) - 1, 0}; }\n    static T op(T a, T b) {\n        if (a.first < b.first)\
    \ return a;\n        if (a.first > b.first) return b;\n        return {a.first,\
    \ a.second + b.second};\n    }\n};\n\nstruct AddMonoid {\n    using T = int;\n\
    \    static T id() { return 0; }\n    static T op(T a, T b) { return a + b; }\n\
    };\n\nCountMinMonoid::T act(CountMinMonoid::T a, AddMonoid::T b) {\n    return\
    \ {a.first + b, a.second};\n}\n\n// rectangles are given in the form (l, d, r,\
    \ u)\nlong long area_of_union_of_rectangles(\n    const std::vector<std::tuple<long\
    \ long, long long, long long, long long>>&\n        rects) {\n    std::vector<long\
    \ long> xs, ys;\n    for (auto [l, d, r, u] : rects) {\n        xs.push_back(l);\n\
    \        xs.push_back(r);\n        ys.push_back(d);\n        ys.push_back(u);\n\
    \    }\n    std::ranges::sort(xs);\n    xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n    std::ranges::sort(ys);\n    ys.erase(std::ranges::unique(ys).begin(),\
    \ ys.end());\n\n    std::vector<std::vector<std::tuple<long long, long long, int>>>\
    \ update(\n        ys.size());\n    for (auto [l, d, r, u] : rects) {\n      \
    \  int cl = std::ranges::lower_bound(xs, l) - xs.begin();\n        int cd = std::ranges::lower_bound(ys,\
    \ d) - ys.begin();\n        int cr = std::ranges::lower_bound(xs, r) - xs.begin();\n\
    \        int cu = std::ranges::lower_bound(ys, u) - ys.begin();\n        update[cd].push_back({cl,\
    \ cr, 1});\n        update[cu].push_back({cl, cr, -1});\n    }\n\n    std::vector<std::pair<int,\
    \ int>> init(xs.size() - 1);\n    for (int x = 0; x < (int)xs.size() - 1; ++x)\
    \ {\n        init[x] = {0, xs[x + 1] - xs[x]};\n    }\n\n    LazySegmentTree<CountMinMonoid,\
    \ AddMonoid, act> st(init);\n    long long ans = 0;\n    long long xlen = xs.back()\
    \ - xs[0];\n    for (int y = 0; y < (int)ys.size() - 1; ++y) {\n        for (auto\
    \ [l, r, diff] : update[y]) {\n            st.update(l, r, diff);\n        }\n\
    \        auto [minval, len0] = st.fold_all();\n        if (minval > 0) len0 =\
    \ 0;\n        ans += (xlen - len0) * (ys[y + 1] - ys[y]);\n    }\n    return ans;\n\
    }\n#line 6 \"test/yosupo/area_of_union_of_rectangles.test.cpp\"\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N;\n    cin >> N;\n    vector<tuple<ll, ll,\
    \ ll, ll>> rects(N);\n    for (int i = 0; i < N; ++i) {\n        int l, d, r,\
    \ u;\n        cin >> l >> d >> r >> u;\n        rects[i] = {l, d, r, u};\n   \
    \ }\n    cout << area_of_union_of_rectangles(rects) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/area_of_union_of_rectangles\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../misc/rectangle_union.hpp\"\n\
    using namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N;\n    cin >> N;\n    vector<tuple<ll, ll,\
    \ ll, ll>> rects(N);\n    for (int i = 0; i < N; ++i) {\n        int l, d, r,\
    \ u;\n        cin >> l >> d >> r >> u;\n        rects[i] = {l, d, r, u};\n   \
    \ }\n    cout << area_of_union_of_rectangles(rects) << endl;\n}"
  dependsOn:
  - misc/rectangle_union.hpp
  - data-structure/segtree/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/yosupo/area_of_union_of_rectangles.test.cpp
  requiredBy: []
  timestamp: '2024-05-08 10:29:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/area_of_union_of_rectangles.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/area_of_union_of_rectangles.test.cpp
- /verify/test/yosupo/area_of_union_of_rectangles.test.cpp.html
title: test/yosupo/area_of_union_of_rectangles.test.cpp
---
