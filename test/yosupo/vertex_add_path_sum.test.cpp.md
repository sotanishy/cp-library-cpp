---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree.cpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: tree/hld.cpp
    title: Heavy-Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 1 \"tree/hld.cpp\"\
    \n#include <bits/stdc++.h>\n#line 2 \"data-structure/segtree/segment_tree.cpp\"\
    \n\n/*\n * @brief Segment Tree\n * @docs docs/data-structure/segtree/segment_tree.md\n\
    \ */\ntemplate <typename M>\nclass SegmentTree {\n    using T = typename M::T;\n\
    \npublic:\n    SegmentTree() = default;\n    explicit SegmentTree(int n): SegmentTree(std::vector<T>(n,\
    \ M::id)) {}\n    explicit SegmentTree(const std::vector<T>& v) {\n        size\
    \ = 1;\n        while (size < (int) v.size()) size <<= 1;\n        node.resize(2\
    \ * size, M::id);\n        std::copy(v.begin(), v.end(), node.begin() + size);\n\
    \        for (int i = size - 1; i > 0; --i) node[i] = M::op(node[2 * i], node[2\
    \ * i + 1]);\n    }\n\n    T operator[](int k) const {\n        return node[k\
    \ + size];\n    }\n\n    void update(int k, const T& x) {\n        k += size;\n\
    \        node[k] = x;\n        while (k >>= 1) node[k] = M::op(node[2 * k], node[2\
    \ * k + 1]);\n    }\n\n    T fold(int l, int r) const {\n        T vl = M::id,\
    \ vr = M::id;\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n\
    \            if (l & 1) vl = M::op(vl, node[l++]);\n            if (r & 1) vr\
    \ = M::op(node[--r], vr);\n        }\n        return M::op(vl, vr);\n    }\n\n\
    \    template <typename F>\n    int find_first(int l, F cond) const {\n      \
    \  T vl = M::id;\n        int r = size;\n        for (l += size, r += size; l\
    \ < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n                T nxt =\
    \ M::op(vl, node[l]);\n                if (cond(nxt)) {\n                    while\
    \ (l < size) {\n                        nxt = M::op(vl, node[2 * l]);\n      \
    \                  if (cond(nxt)) l = 2 * l;\n                        else vl\
    \ = nxt, l = 2 * l + 1;\n                    }\n                    return l -\
    \ size;\n                }\n                vl = nxt;\n                ++l;\n\
    \            }\n        }\n        return -1;\n    }\n\n    template <typename\
    \ F>\n    int find_last(int r, F cond) const {\n        T vr = M::id;\n      \
    \  int l = 0;\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n\
    \            if (r & 1) {\n                --r;\n                T nxt = M::op(node[r],\
    \ vr);\n                if (cond(nxt)) {\n                    while (r < size)\
    \ {\n                        nxt = M::op(node[2 * r + 1], vr);\n             \
    \           if (cond(nxt)) r = 2 * r + 1;\n                        else vr = nxt,\
    \ r = 2 * r;\n                    }\n                    return r - size;\n  \
    \              }\n                vr = nxt;\n            }\n        }\n      \
    \  return -1;\n    }\n\nprivate:\n    int size;\n    std::vector<T> node;\n};\n\
    #line 3 \"tree/hld.cpp\"\n\n/*\n * @brief Heavy-Light Decomposition\n * @docs\
    \ docs/tree/hld.md\n */\ntemplate <typename M>\nclass HLD {\n    using T = typename\
    \ M::T;\n\npublic:\n    HLD() = default;\n    explicit HLD(const std::vector<std::vector<int>>&\
    \ G) : HLD(G, std::vector<T>(G.size(), M::id)) {}\n    HLD(const std::vector<std::vector<int>>&\
    \ G, const std::vector<T>& val)\n        : G(G), size(G.size()), depth(G.size()),\
    \ par(G.size(), -1), pos(G.size()), head(G.size()), heavy(G.size(), -1) {\n  \
    \      dfs(0);\n        decompose(0, 0);\n        std::vector<T> val_ordered(val.size());\n\
    \        for (int i = 0; i < (int) val.size(); ++i) val_ordered[pos[i]] = val[i];\n\
    \        st = SegmentTree<M>(val_ordered);\n    }\n\n    T operator[](int v) const\
    \ {\n        return st[pos[v]];\n    }\n\n    void update(int v, const T& x) {\n\
    \        st.update(pos[v], x);\n    }\n\n    T fold(int u, int v) const {\n  \
    \      T res = M::id;\n        for (; head[u] != head[v]; v = par[head[v]]) {\n\
    \            if (depth[head[u]] > depth[head[v]]) std::swap(u, v);\n         \
    \   T val = st.fold(pos[head[v]], pos[v] + 1);\n            res = M::op(res, val);\n\
    \        }\n        if (depth[u] > depth[v]) std::swap(u, v);\n        T val =\
    \ st.fold(pos[u], pos[v] + 1);\n        return M::op(res, val);\n    }\n\n   \
    \ int lca(int u, int v) const {\n        for (;; v = par[head[v]]) {\n       \
    \     if (depth[u] > depth[v]) std::swap(u, v);\n            if (head[u] == head[v])\
    \ return u;\n        }\n    }\n\n    int dist(int u, int v) const {\n        return\
    \ depth[u] + depth[v] - 2 * depth[lca(u, v)];\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> size, depth, par, pos, head, heavy;\n    int cur_pos\
    \ = 0;\n    SegmentTree<M> st;\n\n    void dfs(int v) {\n        size[v] = 1;\n\
    \        int max_size = 0;\n        for (int c : G[v]) {\n            if (c ==\
    \ par[v]) continue;\n            par[c] = v;\n            depth[c] = depth[v]\
    \ + 1;\n            dfs(c);\n            size[v] += size[c];\n            if (size[c]\
    \ > max_size) {\n                max_size = size[c];\n                heavy[v]\
    \ = c;\n            }\n        }\n    }\n\n    void decompose(int v, int h) {\n\
    \        head[v] = h;\n        pos[v] = cur_pos++;\n        if (heavy[v] != -1)\
    \ decompose(heavy[v], h);\n        for (int c : G[v]) {\n            if (c !=\
    \ par[v] && c != heavy[v]) decompose(c, c);\n        }\n    }\n};\n#line 4 \"\
    test/yosupo/vertex_add_path_sum.test.cpp\"\n\nusing namespace std;\nusing ll =\
    \ long long;\n\nstruct AddMonoid {\n    using T = ll;\n    static constexpr T\
    \ id = 0;\n    static T op(T a, T b) {\n        return a + b;\n    }\n};\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n    for (int i = 0; i\
    \ < N; ++i) cin >> a[i];\n    vector<vector<int>> G(N);\n    for (int i = 0; i\
    \ < N - 1; ++i) {\n        int u, v;\n        cin >> u >> v;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n    HLD<AddMonoid> hld(G, a);\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            int p, x;\n            cin >> p >> x;\n            hld.update(p,\
    \ hld[p] + x);\n        } else {\n            int u, v;\n            cin >> u\
    \ >> v;\n            cout << hld.fold(u, v) << endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../tree/hld.cpp\"\n\nusing namespace std;\nusing ll = long long;\n\
    \nstruct AddMonoid {\n    using T = ll;\n    static constexpr T id = 0;\n    static\
    \ T op(T a, T b) {\n        return a + b;\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n\
    \    for (int i = 0; i < N; ++i) cin >> a[i];\n    vector<vector<int>> G(N);\n\
    \    for (int i = 0; i < N - 1; ++i) {\n        int u, v;\n        cin >> u >>\
    \ v;\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n    HLD<AddMonoid>\
    \ hld(G, a);\n    for (int i = 0; i < Q; ++i) {\n        int t;\n        cin >>\
    \ t;\n        if (t == 0) {\n            int p, x;\n            cin >> p >> x;\n\
    \            hld.update(p, hld[p] + x);\n        } else {\n            int u,\
    \ v;\n            cin >> u >> v;\n            cout << hld.fold(u, v) << endl;\n\
    \        }\n    }\n}"
  dependsOn:
  - tree/hld.cpp
  - data-structure/segtree/segment_tree.cpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2020-10-12 02:39:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_path_sum.test.cpp
- /verify/test/yosupo/vertex_add_path_sum.test.cpp.html
title: test/yosupo/vertex_add_path_sum.test.cpp
---
