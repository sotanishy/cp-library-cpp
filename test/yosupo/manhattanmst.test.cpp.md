---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/segment_tree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/manhattan_mst.hpp
    title: Manhattan Minimum Spanning Tree
  - icon: ':heavy_check_mark:'
    path: graph/mst.hpp
    title: Minimum Spanning Tree Algorithms
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/manhattanmst
    links:
    - https://judge.yosupo.jp/problem/manhattanmst
  bundledCode: "#line 1 \"test/yosupo/manhattanmst.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include <bits/stdc++.h>\n\n\
    #line 5 \"graph/manhattan_mst.hpp\"\n\n#line 3 \"data-structure/segtree/segment_tree.hpp\"\
    \n#include <bit>\n#line 5 \"data-structure/segtree/segment_tree.hpp\"\n\ntemplate\
    \ <typename M>\nclass SegmentTree {\n    using T = M::T;\n\n   public:\n    SegmentTree()\
    \ = default;\n    explicit SegmentTree(int n) : SegmentTree(std::vector<T>(n,\
    \ M::id())) {}\n    explicit SegmentTree(const std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\
    \ node(2 * size, M::id()) {\n        std::ranges::copy(v, node.begin() + size);\n\
    \        for (int i = size - 1; i > 0; --i) {\n            node[i] = M::op(node[2\
    \ * i], node[2 * i + 1]);\n        }\n    }\n\n    T operator[](int k) const {\
    \ return node[k + size]; }\n\n    void update(int k, const T& x) {\n        k\
    \ += size;\n        node[k] = x;\n        while (k >>= 1) node[k] = M::op(node[2\
    \ * k], node[2 * k + 1]);\n    }\n\n    T fold(int l, int r) const {\n       \
    \ T vl = M::id(), vr = M::id();\n        for (l += size, r += size; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) vl = M::op(vl, node[l++]);\n         \
    \   if (r & 1) vr = M::op(node[--r], vr);\n        }\n        return M::op(vl,\
    \ vr);\n    }\n\n    template <typename F>\n    int find_first(int l, F cond)\
    \ const {\n        T v = M::id();\n        for (l += size; l > 0; l >>= 1) {\n\
    \            if (l & 1) {\n                T nv = M::op(v, node[l]);\n       \
    \         if (cond(nv)) {\n                    while (l < size) {\n          \
    \              nv = M::op(v, node[2 * l]);\n                        if (cond(nv))\
    \ {\n                            l = 2 * l;\n                        } else {\n\
    \                            v = nv, l = 2 * l + 1;\n                        }\n\
    \                    }\n                    return l + 1 - size;\n           \
    \     }\n                v = nv;\n                ++l;\n            }\n      \
    \  }\n        return -1;\n    }\n\n    template <typename F>\n    int find_last(int\
    \ r, F cond) const {\n        T v = M::id();\n        for (r += size; r > 0; r\
    \ >>= 1) {\n            if (r & 1) {\n                --r;\n                T\
    \ nv = M::op(node[r], v);\n                if (cond(nv)) {\n                 \
    \   while (r < size) {\n                        nv = M::op(node[2 * r + 1], v);\n\
    \                        if (cond(nv)) {\n                            r = 2 *\
    \ r + 1;\n                        } else {\n                            v = nv,\
    \ r = 2 * r;\n                        }\n                    }\n             \
    \       return r - size;\n                }\n                v = nv;\n       \
    \     }\n        }\n        return -1;\n    }\n\n   private:\n    int size;\n\
    \    std::vector<T> node;\n};\n#line 6 \"graph/mst.hpp\"\n\n#line 4 \"data-structure/unionfind/union_find.hpp\"\
    \n\nclass UnionFind {\n   public:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) { return find(x) ==\
    \ find(y); }\n\n    int size(int x) { return -data[find(x)]; }\n\n   private:\n\
    \    std::vector<int> data;\n};\n#line 8 \"graph/mst.hpp\"\n\ntemplate <typename\
    \ T>\nusing Edge = std::tuple<int, int, T>;\n\n/*\n * Kruskal's Algorithm\n */\n\
    template <typename T>\nstd::pair<T, std::vector<Edge<T>>> kruskal(std::vector<Edge<T>>\
    \ G, int V) {\n    std::ranges::sort(G, {}, [](auto& e) { return std::get<2>(e);\
    \ });\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>> edges;\n\
    \    for (auto& [u, v, w] : G) {\n        if (!uf.same(u, v)) {\n            uf.unite(u,\
    \ v);\n            weight += w;\n            edges.push_back({u, v, w});\n   \
    \     }\n    }\n    return {weight, edges};\n}\n\n/*\n * Prim's Algorithm\n */\n\
    template <typename T>\nstd::pair<T, std::vector<Edge<T>>> prim(\n    const std::vector<std::vector<std::pair<int,\
    \ T>>>& G) {\n    std::vector<bool> used(G.size());\n    auto cmp = [](const auto&\
    \ e1, const auto& e2) {\n        return std::get<2>(e1) > std::get<2>(e2);\n \
    \   };\n    std::priority_queue<Edge<T>, std::vector<Edge<T>>, decltype(cmp)>\
    \ pq(cmp);\n    pq.emplace(0, 0, 0);\n    T weight = 0;\n    std::vector<Edge<T>>\
    \ edges;\n    while (!pq.empty()) {\n        auto [p, v, w] = pq.top();\n    \
    \    pq.pop();\n        if (used[v]) continue;\n        used[v] = true;\n    \
    \    weight += w;\n        if (v != 0) edges.push_back({p, v, w});\n        for\
    \ (auto& [u, w2] : G[v]) {\n            pq.emplace(v, u, w2);\n        }\n   \
    \ }\n    return {weight, edges};\n}\n\n/*\n * Boruvka's Algorithm\n */\ntemplate\
    \ <typename T>\nstd::pair<T, std::vector<Edge<T>>> boruvka(std::vector<Edge<T>>\
    \ G, int V) {\n    UnionFind uf(V);\n    T weight = 0;\n    std::vector<Edge<T>>\
    \ edges;\n    while (uf.size(0) < V) {\n        std::vector<Edge<T>> cheapest(V,\n\
    \                                      {-1, -1, std::numeric_limits<T>::max()});\n\
    \        for (auto [u, v, w] : G) {\n            if (!uf.same(u, v)) {\n     \
    \           u = uf.find(u);\n                v = uf.find(v);\n               \
    \ if (w < std::get<2>(cheapest[u])) cheapest[u] = {u, v, w};\n               \
    \ if (w < std::get<2>(cheapest[v])) cheapest[v] = {u, v, w};\n            }\n\
    \        }\n        for (auto [u, v, w] : cheapest) {\n            if (u != -1\
    \ && !uf.same(u, v)) {\n                uf.unite(u, v);\n                weight\
    \ += w;\n                edges.push_back({u, v, w});\n            }\n        }\n\
    \    }\n    return {weight, edges};\n}\n#line 8 \"graph/manhattan_mst.hpp\"\n\n\
    template <typename U>\nstruct MinMonoid {\n    using T = std::pair<U, int>;\n\
    \    static T id() { return {std::numeric_limits<U>::max(), -1}; }\n    static\
    \ T op(T a, T b) { return std::min(a, b); }\n};\n\ntemplate <typename T>\nstd::pair<T,\
    \ std::vector<std::pair<int, int>>> manhattan_mst(\n    std::vector<std::pair<T,\
    \ T>> pts) {\n    std::vector<int> idx(pts.size());\n    std::iota(idx.begin(),\
    \ idx.end(), 0);\n\n    std::vector<std::tuple<int, int, T>> edges;\n\n    for\
    \ (int i = 0; i < 2; ++i) {\n        for (int j = 0; j < 2; ++j) {\n         \
    \   for (int k = 0; k < 2; ++k) {\n                // sort by y-x asc then by\
    \ y desc\n                std::ranges::sort(idx, {}, [&](int i) {\n          \
    \          auto [x, y] = pts[i];\n                    return std::make_tuple(y\
    \ - x, -y, i);\n                });\n\n                // compress y\n       \
    \         std::vector<T> cs;\n                cs.reserve(pts.size());\n      \
    \          for (auto [x, y] : pts) cs.push_back(y);\n                std::ranges::sort(cs);\n\
    \                cs.erase(std::ranges::unique(cs).begin(), cs.end());\n\n    \
    \            // sweep\n                SegmentTree<MinMonoid<T>> st(cs.size());\n\
    \n                for (int i : idx) {\n                    auto [x, y] = pts[i];\n\
    \                    int k = std::ranges::lower_bound(cs, y) - cs.begin();\n \
    \                   auto [d, j] = st.fold(k, cs.size());\n                   \
    \ if (j != -1) {\n                        edges.push_back({i, j, d - (x + y)});\n\
    \                    }\n                    st.update(k, {x + y, i});\n      \
    \          }\n\n                for (auto& p : pts) std::swap(p.first, p.second);\n\
    \            }\n            for (auto& p : pts) p.first *= -1;\n        }\n  \
    \      for (auto& p : pts) p.second *= -1;\n    }\n\n    auto [weight, mst_edges]\
    \ = kruskal(edges, pts.size());\n    std::vector<std::pair<int, int>> ret(mst_edges.size());\n\
    \    std::ranges::transform(mst_edges, ret.begin(), [&](const auto& e) {\n   \
    \     return std::make_pair(std::get<0>(e), std::get<1>(e));\n    });\n    return\
    \ {weight, ret};\n}\n#line 6 \"test/yosupo/manhattanmst.test.cpp\"\n\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    int N;\n    cin >> N;\n   \
    \ vector<pair<long long, long long>> pts(N);\n    for (auto& x : pts) cin >> x.first\
    \ >> x.second;\n    auto [weight, edges] = manhattan_mst(pts);\n    cout << weight\
    \ << endl;\n    for (auto [u, v] : edges) {\n        cout << u << \" \" << v <<\
    \ \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/manhattanmst\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../graph/manhattan_mst.hpp\"\n\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    int N;\n    cin >> N;\n   \
    \ vector<pair<long long, long long>> pts(N);\n    for (auto& x : pts) cin >> x.first\
    \ >> x.second;\n    auto [weight, edges] = manhattan_mst(pts);\n    cout << weight\
    \ << endl;\n    for (auto [u, v] : edges) {\n        cout << u << \" \" << v <<\
    \ \"\\n\";\n    }\n}"
  dependsOn:
  - graph/manhattan_mst.hpp
  - data-structure/segtree/segment_tree.hpp
  - graph/mst.hpp
  - data-structure/unionfind/union_find.hpp
  isVerificationFile: true
  path: test/yosupo/manhattanmst.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 15:51:32+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/manhattanmst.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/manhattanmst.test.cpp
- /verify/test/yosupo/manhattanmst.test.cpp.html
title: test/yosupo/manhattanmst.test.cpp
---
