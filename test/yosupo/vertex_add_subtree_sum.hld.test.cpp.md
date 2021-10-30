---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/fenwick_tree.cpp
    title: Fenwick Tree
  - icon: ':heavy_check_mark:'
    path: tree/hld.cpp
    title: Heavy-Light Decomposition
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
  bundledCode: "#line 1 \"test/yosupo/vertex_add_subtree_sum.hld.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line\
    \ 2 \"data-structure/fenwick_tree.cpp\"\n#include <functional>\n#include <vector>\n\
    \ntemplate <typename M>\nclass FenwickTree {\n    using T = typename M::T;\n\n\
    public:\n    FenwickTree() = default;\n    explicit FenwickTree(int n) : n(n),\
    \ data(n + 1, M::id) {}\n\n    T prefix_fold(int i) const {\n        T ret = M::id;\n\
    \        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);\n        return\
    \ ret;\n    }\n\n    void update(int i, const T& x) {\n        for (++i; i <=\
    \ n; i += i & -i) data[i] = M::op(data[i], x);\n    }\n\n    int lower_bound(const\
    \ T& x) const {\n        return lower_bound(x, std::less<>());\n    }\n\n    template\
    \ <typename Compare>\n    int lower_bound(const T& x, Compare cmp) const {\n \
    \       int k = 1;\n        while (k * 2 <= n) k <<= 1;\n        int i = 0;\n\
    \        T v = M::id;\n        for (; k > 0; k >>= 1) {\n            if (i + k\
    \ <= n) continue;\n            T nv = M::op(v, data[i + k]);\n            if (cmp(nv,\
    \ x)) {\n                v = nv;\n                i += k;\n            }\n   \
    \     }\n        return i + 1;\n    }\n\nprivate:\n    int n;\n    std::vector<T>\
    \ data;\n};\n#line 2 \"tree/hld.cpp\"\n#include <algorithm>\n#line 4 \"tree/hld.cpp\"\
    \n\ntemplate <typename M>\nclass HLD {\n    using T = typename M::T;\n\npublic:\n\
    \    HLD() = default;\n    HLD(const std::vector<std::vector<int>>& G, bool edge)\n\
    \        : G(G), size(G.size()), depth(G.size()), par(G.size(), -1),\n       \
    \   in(G.size()), out(G.size()), head(G.size()), heavy(G.size(), -1), edge(edge)\
    \ {\n        dfs(0);\n        decompose(0, 0);\n    }\n\n    template <typename\
    \ F>\n    void update(int v, const T& x, const F& f) const {\n        f(in[v],\
    \ x);\n    }\n\n    template <typename E, typename F>\n    void update(int u,\
    \ int v, const E& x, const F& f) const {\n        while (head[u] != head[v]) {\n\
    \            if (in[head[u]] > in[head[v]]) std::swap(u, v);\n            f(in[head[v]],\
    \ in[v] + 1, x);\n            v = par[head[v]];\n        }\n        if (in[u]\
    \ > in[v]) std::swap(u, v);\n        f(in[u] + edge, in[v] + 1, x);\n    }\n\n\
    \    template <typename F>\n    T path_fold(int u, int v, const F& f) const {\n\
    \        T res = M::id;\n        while (head[u] != head[v]) {\n            if\
    \ (in[head[u]] > in[head[v]]) std::swap(u, v);\n            T val = f(in[head[v]],\
    \ in[v] + 1);\n            res = M::op(val, res);\n            v = par[head[v]];\n\
    \        }\n        if (in[u] > in[v]) std::swap(u, v);\n        T val = f(in[u]\
    \ + edge, in[v] + 1);\n        return M::op(val, res);\n    }\n\n    template\
    \ <typename F>\n    T subtree_fold(int v, const F& f) const {\n        return\
    \ f(in[v] + edge, out[v]);\n    }\n\n    int lca(int u, int v) const {\n     \
    \   while (true) {\n            if (in[u] > in[v]) std::swap(u, v);\n        \
    \    if (head[u] == head[v]) return u;\n            v = par[head[v]];\n      \
    \  }\n    }\n\n    int dist(int u, int v) const {\n        return depth[u] + depth[v]\
    \ - 2 * depth[lca(u, v)];\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> size, depth, par, in, out, head, heavy;\n    bool edge;\n\
    \    int cur_pos = 0;\n\n    void dfs(int v) {\n        size[v] = 1;\n       \
    \ int max_size = 0;\n        for (int c : G[v]) {\n            if (c == par[v])\
    \ continue;\n            par[c] = v;\n            depth[c] = depth[v] + 1;\n \
    \           dfs(c);\n            size[v] += size[c];\n            if (size[c]\
    \ > max_size) {\n                max_size = size[c];\n                heavy[v]\
    \ = c;\n            }\n        }\n    }\n\n    void decompose(int v, int h) {\n\
    \        head[v] = h;\n        in[v] = cur_pos++;\n        if (heavy[v] != -1)\
    \ decompose(heavy[v], h);\n        for (int c : G[v]) {\n            if (c !=\
    \ par[v] && c != heavy[v]) decompose(c, c);\n        }\n        out[v] = cur_pos;\n\
    \    }\n};\n#line 5 \"test/yosupo/vertex_add_subtree_sum.hld.test.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\nstruct AddMonoid\
    \ {\n    using T = ll;\n    static constexpr T id = 0;\n    static T op(T a, T\
    \ b) { return a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    vector<vector<int>> G(N);\n\
    \    for (int i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n      \
    \  G[p].push_back(i);\n    }\n    HLD<AddMonoid> hld(G, false);\n    FenwickTree<AddMonoid>\
    \ fw(N);\n    auto update = [&](int k, ll x) {\n        fw.update(k, x);\n   \
    \ };\n    auto fold = [&](int l, int r) {\n        return fw.prefix_fold(r) -\
    \ fw.prefix_fold(l);\n    };\n    for (int i = 0; i < N; ++i) hld.update(i, a[i],\
    \ update);\n    for (int i = 0; i < Q; ++i) {\n        int t, u;\n        cin\
    \ >> t >> u;\n        if (t == 0) {\n            int x;\n            cin >> x;\n\
    \            hld.update(u, x, update);\n        } else {\n            cout <<\
    \ hld.subtree_fold(u, fold) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../data-structure/fenwick_tree.cpp\"\n#include \"../../tree/hld.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    struct AddMonoid {\n    using T = ll;\n    static constexpr T id = 0;\n    static\
    \ T op(T a, T b) { return a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    vector<vector<int>> G(N);\n\
    \    for (int i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n      \
    \  G[p].push_back(i);\n    }\n    HLD<AddMonoid> hld(G, false);\n    FenwickTree<AddMonoid>\
    \ fw(N);\n    auto update = [&](int k, ll x) {\n        fw.update(k, x);\n   \
    \ };\n    auto fold = [&](int l, int r) {\n        return fw.prefix_fold(r) -\
    \ fw.prefix_fold(l);\n    };\n    for (int i = 0; i < N; ++i) hld.update(i, a[i],\
    \ update);\n    for (int i = 0; i < Q; ++i) {\n        int t, u;\n        cin\
    \ >> t >> u;\n        if (t == 0) {\n            int x;\n            cin >> x;\n\
    \            hld.update(u, x, update);\n        } else {\n            cout <<\
    \ hld.subtree_fold(u, fold) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - data-structure/fenwick_tree.cpp
  - tree/hld.cpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  requiredBy: []
  timestamp: '2021-10-30 12:57:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.hld.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.hld.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
---
