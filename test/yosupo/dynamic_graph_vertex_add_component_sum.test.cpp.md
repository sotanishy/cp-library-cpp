---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/undoable_union_find.hpp
    title: Undoable Union Find
  - icon: ':heavy_check_mark:'
    path: graph/offline_dynamic_connectivity.cpp
    title: Offline Dynamic Connectivity
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum
  bundledCode: "#line 1 \"test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \n#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#line 8 \"graph/offline_dynamic_connectivity.cpp\"\
    \n\n#line 7 \"data-structure/unionfind/undoable_union_find.hpp\"\n\ntemplate <typename\
    \ M>\nclass UndoableUnionFind {\n    using T = M::T;\n\n   public:\n    UndoableUnionFind()\
    \ = default;\n    explicit UndoableUnionFind(int n)\n        : UndoableUnionFind(std::vector<T>(n,\
    \ M::id())) {}\n    explicit UndoableUnionFind(const std::vector<T>& v)\n    \
    \    : data(v.size(), -1), val(v.begin(), v.end()) {}\n\n    int find(int x) const\
    \ {\n        if (data[x] < 0) return x;\n        return find(data[x]);\n    }\n\
    \n    void unite(int x, int y) {\n        x = find(x);\n        y = find(y);\n\
    \        history.emplace(-1, 0, M::id());\n        history.emplace(x, data[x],\
    \ val[x]);\n        history.emplace(y, data[y], val[y]);\n        if (x == y)\
    \ return;\n        if (data[x] > data[y]) std::swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        val[x] = M::op(val[x], val[y]);\n  \
    \  }\n\n    void undo() {\n        assert(!history.empty());\n        while (true)\
    \ {\n            auto [x, dx, vx] = history.top();\n            history.pop();\n\
    \            if (x == -1) break;\n            data[x] = dx;\n            val[x]\
    \ = vx;\n        }\n    }\n\n    bool same(int x, int y) const { return find(x)\
    \ == find(y); }\n\n    int size(int x) const { return -data[find(x)]; }\n\n  \
    \  T component_fold(int x) const { return val[find(x)]; }\n\n    void update(int\
    \ x, const T& v) {\n        x = find(x);\n        history.emplace(-1, 0, M::id());\n\
    \        history.emplace(x, data[x], val[x]);\n        val[x] = M::op(val[x],\
    \ v);\n    }\n\n   private:\n    std::vector<int> data;\n    std::vector<T> val;\n\
    \    std::stack<std::tuple<int, int, T>> history;\n};\n#line 10 \"graph/offline_dynamic_connectivity.cpp\"\
    \n\ntemplate <typename M>\nclass OfflineDynamicConnectivity {\n    using T = typename\
    \ M::T;\n\n   public:\n    OfflineDynamicConnectivity() = default;\n    explicit\
    \ OfflineDynamicConnectivity(int n)\n        : OfflineDynamicConnectivity(std::vector<T>(n,\
    \ M::id())) {}\n    explicit OfflineDynamicConnectivity(const std::vector<T>&\
    \ v) : val(v) {}\n\n    void link(int u, int v) {\n        ++now;\n        auto\
    \ edge = std::minmax(u, v);\n        open.emplace(edge, now);\n    }\n\n    void\
    \ cut(int u, int v) {\n        ++now;\n        auto edge = std::minmax(u, v);\n\
    \        auto it = open.find(edge);\n        assert(it != open.end());\n     \
    \   closed.emplace_back(edge.first, edge.second, it->second, now);\n        open.erase(it);\n\
    \    }\n\n    void update(int v, const T& x) {\n        ++now;\n        query_update.emplace_back(now,\
    \ v, x);\n    }\n\n    void same(int u, int v) {\n        ++now;\n        query_same[now]\
    \ = {u, v};\n    }\n\n    void component_fold(int v) {\n        ++now;\n     \
    \   query_fold[now] = v;\n    }\n\n    std::vector<std::pair<bool, T>> run() {\n\
    \        ++now;\n\n        // cut edges\n        for (auto [edge, s] : open) {\n\
    \            closed.emplace_back(edge.first, edge.second, s, now);\n        }\n\
    \n        // build a segment tree\n        int size = 1;\n        while (size\
    \ < now) size <<= 1;\n        std::vector<std::vector<std::pair<int, int>>> edges(2\
    \ * size);\n        std::vector<std::vector<std::pair<int, T>>> updates(2 * size);\n\
    \n        for (auto [u, v, s, t] : closed) {\n            for (s += size, t +=\
    \ size; s < t; s >>= 1, t >>= 1) {\n                if (s & 1) edges[s++].emplace_back(u,\
    \ v);\n                if (t & 1) edges[--t].emplace_back(u, v);\n           \
    \ }\n        }\n\n        for (auto [s, v, x] : query_update) {\n            int\
    \ t = size;\n            for (s += size, t += size; s < t; s >>= 1, t >>= 1) {\n\
    \                if (s & 1) updates[s++].emplace_back(v, x);\n               \
    \ if (t & 1) updates[--t].emplace_back(v, x);\n            }\n        }\n\n  \
    \      // handle queries\n        UndoableUnionFind<M> uf(val);\n        std::vector<std::pair<bool,\
    \ T>> ret;\n\n        auto dfs = [&](const auto& self, int k) -> void {\n    \
    \        for (auto [u, v] : edges[k]) {\n                uf.unite(u, v);\n   \
    \         }\n            for (auto [v, x] : updates[k]) {\n                uf.update(v,\
    \ x);\n            }\n            if (k < size) {\n                self(self,\
    \ 2 * k);\n                self(self, 2 * k + 1);\n            } else if (k <\
    \ size + now) {\n                if (query_same.count(k - size)) {\n         \
    \           auto [u, v] = query_same[k - size];\n                    ret.emplace_back(uf.same(u,\
    \ v), M::id());\n                }\n                if (query_fold.count(k - size))\
    \ {\n                    ret.emplace_back(false,\n                           \
    \          uf.component_fold(query_fold[k - size]));\n                }\n    \
    \        }\n            for (int i = 0; i < (int)(edges[k].size() + updates[k].size());\n\
    \                 ++i) {\n                uf.undo();\n            }\n        };\n\
    \n        dfs(dfs, 1);\n        return ret;\n    }\n\n   private:\n    int now\
    \ = 0;\n    std::multimap<std::pair<int, int>, int> open;\n    std::vector<std::tuple<int,\
    \ int, int, int>> closed;\n    std::vector<std::tuple<int, int, T>> query_update;\n\
    \    std::map<int, std::pair<int, int>> query_same;\n    std::map<int, int> query_fold;\n\
    \    std::vector<T> val;\n};\n#line 7 \"test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp\"\
    \nusing namespace std;\n\nusing ll = long long;\n\nstruct AddMonoid {\n    using\
    \ T = ll;\n    static T id() { return 0; }\n    static T op(T a, T b) { return\
    \ a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n    for (auto& x :\
    \ a) cin >> x;\n    OfflineDynamicConnectivity<AddMonoid> dc(a);\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            int u, v;\n            cin >> u >> v;\n            dc.link(u,\
    \ v);\n        }\n        if (t == 1) {\n            int u, v;\n            cin\
    \ >> u >> v;\n            dc.cut(u, v);\n        }\n        if (t == 2) {\n  \
    \          int v, x;\n            cin >> v >> x;\n            dc.update(v, x);\n\
    \        }\n        if (t == 3) {\n            int v;\n            cin >> v;\n\
    \            dc.component_fold(v);\n        }\n    }\n    auto ans = dc.run();\n\
    \    for (auto x : ans) cout << x.second << \"\\n\";\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../graph/offline_dynamic_connectivity.cpp\"\
    \nusing namespace std;\n\nusing ll = long long;\n\nstruct AddMonoid {\n    using\
    \ T = ll;\n    static T id() { return 0; }\n    static T op(T a, T b) { return\
    \ a + b; }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<ll> a(N);\n    for (auto& x :\
    \ a) cin >> x;\n    OfflineDynamicConnectivity<AddMonoid> dc(a);\n    for (int\
    \ i = 0; i < Q; ++i) {\n        int t;\n        cin >> t;\n        if (t == 0)\
    \ {\n            int u, v;\n            cin >> u >> v;\n            dc.link(u,\
    \ v);\n        }\n        if (t == 1) {\n            int u, v;\n            cin\
    \ >> u >> v;\n            dc.cut(u, v);\n        }\n        if (t == 2) {\n  \
    \          int v, x;\n            cin >> v >> x;\n            dc.update(v, x);\n\
    \        }\n        if (t == 3) {\n            int v;\n            cin >> v;\n\
    \            dc.component_fold(v);\n        }\n    }\n    auto ans = dc.run();\n\
    \    for (auto x : ans) cout << x.second << \"\\n\";\n}"
  dependsOn:
  - graph/offline_dynamic_connectivity.cpp
  - data-structure/unionfind/undoable_union_find.hpp
  isVerificationFile: true
  path: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 20:49:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
- /verify/test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp.html
title: test/yosupo/dynamic_graph_vertex_add_component_sum.test.cpp
---
