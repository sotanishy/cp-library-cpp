---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/segtree/lazy_segment_tree.hpp
    title: Segment Tree with Lazy Propagation
  - icon: ':heavy_check_mark:'
    path: tree/permutation_tree.hpp
    title: Permutation Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/common_interval_decomposition_tree
    links:
    - https://judge.yosupo.jp/problem/common_interval_decomposition_tree
  bundledCode: "#line 1 \"test/yosupo/common_interval_decomposition_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/common_interval_decomposition_tree\"\
    \n\n#line 2 \"tree/permutation_tree.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \n#line 3 \"data-structure/segtree/lazy_segment_tree.hpp\"\n#include <bit>\n#include\
    \ <numeric>\n#line 6 \"data-structure/segtree/lazy_segment_tree.hpp\"\n\ntemplate\
    \ <typename M, typename O,\n          typename M::T (*act)(typename M::T, typename\
    \ O::T)>\nclass LazySegmentTree {\n    using T = M::T;\n    using E = O::T;\n\n\
    \   public:\n    LazySegmentTree() = default;\n    explicit LazySegmentTree(int\
    \ n)\n        : LazySegmentTree(std::vector<T>(n, M::id())) {}\n    explicit LazySegmentTree(const\
    \ std::vector<T>& v)\n        : size(std::bit_ceil(v.size())),\n          node(2\
    \ * size, M::id()),\n          lazy(2 * size, O::id()) {\n        std::ranges::copy(v,\
    \ node.begin() + size);\n        for (int i = size - 1; i > 0; --i) {\n      \
    \      node[i] = M::op(node[2 * i], node[2 * i + 1]);\n        }\n    }\n\n  \
    \  T operator[](int k) { return fold(k, k + 1); }\n\n    void update(int l, int\
    \ r, const E& x) { update(l, r, x, 1, 0, size); }\n\n    T fold(int l, int r)\
    \ { return fold(l, r, 1, 0, size); }\n\n    template <typename F>\n    int find_first(int\
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
    \ 2 * k, l, m, v, cond);\n    }\n};\n#line 6 \"tree/permutation_tree.hpp\"\n\n\
    struct MinMonoid {\n    using T = int;\n    static T id() { return (1u << 31)\
    \ - 1; }\n    static T op(T a, T b) { return std::min(a, b); }\n};\n\nstruct AddMonoid\
    \ {\n    using T = int;\n    static T id() { return 0; }\n    static T op(T a,\
    \ T b) { return a + b; }\n};\n\nint act(int a, int b) { return a + b; }\n\nclass\
    \ PermutationTree {\n   public:\n    enum NodeType { JoinAsc, JoinDesc, Cut, Leaf,\
    \ None };\n    struct Node {\n        NodeType tp;\n        int l, r;    // i\
    \ in [l, r)\n        int lb, ub;  // p[i] in [lb, ub)\n        std::vector<int>\
    \ ch;\n    };\n\n    std::vector<Node> nodes;\n\n    PermutationTree() = default;\n\
    \    explicit PermutationTree(const std::vector<int>& p) {\n        LazySegmentTree<MinMonoid,\
    \ AddMonoid, act> seg(\n            std::vector<int>(p.size()));\n        // seg.fold(l,\
    \ r) ==\n        // min_{l <= j < r} { max(p[j:i]) - min(p[j:i]) - (i - j) }\n\
    \        std::vector<int> st_max = {-1}, st_min = {-1}, st;\n\n        for (int\
    \ i = 0; i < (int)p.size(); ++i) {\n            while (st_max.back() >= 0 && p[st_max.back()]\
    \ < p[i]) {\n                seg.update(st_max[st_max.size() - 2] + 1, st_max.back()\
    \ + 1,\n                           p[i] - p[st_max.back()]);\n               \
    \ st_max.pop_back();\n            }\n            st_max.push_back(i);\n\n    \
    \        while (st_min.back() >= 0 && p[st_min.back()] > p[i]) {\n           \
    \     seg.update(st_min[st_min.size() - 2] + 1, st_min.back() + 1,\n         \
    \                  -(p[i] - p[st_min.back()]));\n                st_min.pop_back();\n\
    \            }\n            st_min.push_back(i);\n\n            nodes.push_back(\n\
    \                {Leaf, i, i + 1, p[i], p[i] + 1, std::vector<int>{}});\n    \
    \        int v = nodes.size() - 1;  // index of the current node\n\n         \
    \   while (true) {\n                NodeType join_tp = None;\n               \
    \ if (!st.empty() && nodes[st.back()].ub == nodes[v].lb)\n                   \
    \ join_tp = JoinAsc;\n                if (!st.empty() && nodes[st.back()].lb ==\
    \ nodes[v].ub)\n                    join_tp = JoinDesc;\n\n                if\
    \ (!st.empty() && join_tp != None) {\n                    // join\n          \
    \          if (join_tp == nodes[st.back()].tp) {\n                        // same\
    \ type, append to the existing join node\n                        add_child(st.back(),\
    \ v);\n                        v = st.back();\n                        st.pop_back();\n\
    \                    } else {\n                        // different type, create\
    \ a new join node\n                        int u = st.back();\n              \
    \          nodes.push_back({join_tp,\n                                       \
    \  nodes[u].l,\n                                         nodes[u].r,\n       \
    \                                  nodes[u].lb,\n                            \
    \             nodes[u].ub,\n                                         {u}});\n\
    \                        st.pop_back();\n                        add_child(nodes.size()\
    \ - 1, v);\n                        v = nodes.size() - 1;\n                  \
    \  }\n                } else if (seg.fold(0, i + 1 - (nodes[v].r - nodes[v].l))\
    \ ==\n                           0) {\n                    // cut\n          \
    \          int l = nodes[v].l, r = nodes[v].r, lb = nodes[v].lb,\n           \
    \             ub = nodes[v].ub;\n                    nodes.push_back({Cut, l,\
    \ r, lb, ub, {v}});\n                    v = nodes.size() - 1;\n             \
    \       do {\n                        add_child(v, st.back());\n             \
    \           st.pop_back();\n                    } while (nodes[v].ub - nodes[v].lb\
    \ !=\n                             nodes[v].r - nodes[v].l);\n               \
    \     std::ranges::reverse(nodes[v].ch);\n                } else {\n         \
    \           break;\n                }\n            }\n            st.push_back(v);\n\
    \            seg.update(0, i + 1, -1);\n        }\n    }\n\n   private:\n    void\
    \ add_child(int par, int ch) {\n        nodes[par].ch.push_back(ch);\n       \
    \ nodes[par].l = std::min(nodes[par].l, nodes[ch].l);\n        nodes[par].r =\
    \ std::max(nodes[par].r, nodes[ch].r);\n        nodes[par].lb = std::min(nodes[par].lb,\
    \ nodes[ch].lb);\n        nodes[par].ub = std::max(nodes[par].ub, nodes[ch].ub);\n\
    \    }\n};\n#line 4 \"test/yosupo/common_interval_decomposition_tree.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int N;\n    cin >> N;\n    vector<int> p(N);\n    for (auto& x : p) cin >>\
    \ x;\n    PermutationTree pt(p);\n    vector<int> par(pt.nodes.size(), -1);\n\
    \    for (int i = 0; i < (int) pt.nodes.size(); ++i) {\n        for (int j : pt.nodes[i].ch)\
    \ {\n            par[j] = i;\n        }\n    }\n    cout << pt.nodes.size() <<\
    \ endl;\n    for (int i = 0; i < (int) pt.nodes.size(); ++i) {\n        cout <<\
    \ par[i] << \" \" << pt.nodes[i].l << \" \" << pt.nodes[i].r-1 << \" \" << (pt.nodes[i].tp\
    \ == PermutationTree::Cut ? \"prime\" : \"linear\") << \"\\n\";\n    }\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/common_interval_decomposition_tree\"\
    \n\n#include \"../../tree/permutation_tree.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N;\n    cin >> N;\n    vector<int> p(N);\n \
    \   for (auto& x : p) cin >> x;\n    PermutationTree pt(p);\n    vector<int> par(pt.nodes.size(),\
    \ -1);\n    for (int i = 0; i < (int) pt.nodes.size(); ++i) {\n        for (int\
    \ j : pt.nodes[i].ch) {\n            par[j] = i;\n        }\n    }\n    cout <<\
    \ pt.nodes.size() << endl;\n    for (int i = 0; i < (int) pt.nodes.size(); ++i)\
    \ {\n        cout << par[i] << \" \" << pt.nodes[i].l << \" \" << pt.nodes[i].r-1\
    \ << \" \" << (pt.nodes[i].tp == PermutationTree::Cut ? \"prime\" : \"linear\"\
    ) << \"\\n\";\n    }\n}\n\n"
  dependsOn:
  - tree/permutation_tree.hpp
  - data-structure/segtree/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/yosupo/common_interval_decomposition_tree.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 01:08:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/common_interval_decomposition_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/common_interval_decomposition_tree.test.cpp
- /verify/test/yosupo/common_interval_decomposition_tree.test.cpp.html
title: test/yosupo/common_interval_decomposition_tree.test.cpp
---
