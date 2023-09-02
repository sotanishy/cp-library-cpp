---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segtree/segment_tree.cpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: tree/euler_tour.cpp
    title: Euler Tour
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\
    \n#line 2 \"tree/euler_tour.cpp\"\n#include <vector>\n\n/*\n * @brief Euler Tour\n\
    \ */\nstd::pair<std::vector<int>, std::vector<int>> euler_tour(const std::vector<std::vector<int>>&\
    \ G, int root) {\n    std::vector<int> in(G.size()), out(G.size());\n    int k\
    \ = 0;\n\n    auto dfs = [&](auto& dfs, int v, int p) -> void {\n        in[v]\
    \ = k++;\n        for (int c : G[v]) if (c != p) dfs(dfs, c, v);\n        out[v]\
    \ = k;\n    };\n\n    dfs(dfs, root, -1);\n    return {in, out};\n}\n#line 2 \"\
    data-structure/segtree/segment_tree.cpp\"\n#include <algorithm>\n#line 4 \"data-structure/segtree/segment_tree.cpp\"\
    \n\ntemplate <typename M>\nclass SegmentTree {\n    using T = typename M::T;\n\
    \n   public:\n    SegmentTree() = default;\n    explicit SegmentTree(int n) :\
    \ SegmentTree(std::vector<T>(n, M::id())) {}\n    explicit SegmentTree(const std::vector<T>&\
    \ v) {\n        size = 1;\n        while (size < (int)v.size()) size <<= 1;\n\
    \        node.resize(2 * size, M::id());\n        std::copy(v.begin(), v.end(),\
    \ node.begin() + size);\n        for (int i = size - 1; i > 0; --i)\n        \
    \    node[i] = M::op(node[2 * i], node[2 * i + 1]);\n    }\n\n    T operator[](int\
    \ k) const { return node[k + size]; }\n\n    void update(int k, const T& x) {\n\
    \        k += size;\n        node[k] = x;\n        while (k >>= 1) node[k] = M::op(node[2\
    \ * k], node[2 * k + 1]);\n    }\n\n    T fold(int l, int r) const {\n       \
    \ T vl = M::id(), vr = M::id();\n        for (l += size, r += size; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) vl = M::op(vl, node[l++]);\n         \
    \   if (r & 1) vr = M::op(node[--r], vr);\n        }\n        return M::op(vl,\
    \ vr);\n    }\n\n    template <typename F>\n    int find_first(int l, F cond)\
    \ const {\n        T v = M::id();\n        for (l += size; l > 0; l >>= 1) {\n\
    \            if (l & 1) {\n                T nv = M::op(v, node[l]);\n       \
    \         if (cond(nv)) {\n                    while (l < size) {\n          \
    \              nv = M::op(v, node[2 * l]);\n                        if (cond(nv))\n\
    \                            l = 2 * l;\n                        else\n      \
    \                      v = nv, l = 2 * l + 1;\n                    }\n       \
    \             return l + 1 - size;\n                }\n                v = nv;\n\
    \                ++l;\n            }\n        }\n        return -1;\n    }\n\n\
    \    template <typename F>\n    int find_last(int r, F cond) const {\n       \
    \ T v = M::id();\n        for (r += size; r > 0; r >>= 1) {\n            if (r\
    \ & 1) {\n                --r;\n                T nv = M::op(node[r], v);\n  \
    \              if (cond(nv)) {\n                    while (r < size) {\n     \
    \                   nv = M::op(node[2 * r + 1], v);\n                        if\
    \ (cond(nv))\n                            r = 2 * r + 1;\n                   \
    \     else\n                            v = nv, r = 2 * r;\n                 \
    \   }\n                    return r - size;\n                }\n             \
    \   v = nv;\n            }\n        }\n        return -1;\n    }\n\n   private:\n\
    \    int size;\n    std::vector<T> node;\n};\n#line 5 \"test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    struct AddMonoid {\n    using T = ll;\n    static T id() { return 0; }\n    static\
    \ T op(T a, T b) { return a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    vector<vector<int>> G(N);\n\
    \    for (int i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n      \
    \  G[p].push_back(i);\n    }\n    auto [in, out] = euler_tour(G, 0);\n    SegmentTree<AddMonoid>\
    \ st(N);\n    for (int i = 0; i < N; ++i) st.update(in[i], a[i]);\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t, u;\n        cin >> t >> u;\n        if\
    \ (t == 0) {\n            int x;\n            cin >> x;\n            st.update(in[u],\
    \ st[in[u]] + x);\n        } else {\n            cout << st.fold(in[u], out[u])\
    \ << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../tree/euler_tour.cpp\"\n#include \"../../data-structure/segtree/segment_tree.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    struct AddMonoid {\n    using T = ll;\n    static T id() { return 0; }\n    static\
    \ T op(T a, T b) { return a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    vector<vector<int>> G(N);\n\
    \    for (int i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n      \
    \  G[p].push_back(i);\n    }\n    auto [in, out] = euler_tour(G, 0);\n    SegmentTree<AddMonoid>\
    \ st(N);\n    for (int i = 0; i < N; ++i) st.update(in[i], a[i]);\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t, u;\n        cin >> t >> u;\n        if\
    \ (t == 0) {\n            int x;\n            cin >> x;\n            st.update(in[u],\
    \ st[in[u]] + x);\n        } else {\n            cout << st.fold(in[u], out[u])\
    \ << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - tree/euler_tour.cpp
  - data-structure/segtree/segment_tree.cpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
  requiredBy: []
  timestamp: '2023-06-13 22:58:26+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.euler_tour.test.cpp
---
