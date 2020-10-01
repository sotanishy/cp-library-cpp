---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/segment_tree.cpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/hld.md
    document_title: Heavy-Light Decomposition
    links: []
  bundledCode: "#line 1 \"tree/hld.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"data-structure/segment_tree.cpp\"\
    \n\n/*\n * @brief Segment Tree\n * @docs docs/data-structure/segment_tree.md\n\
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
    \    template <typename F>\n    int find_first(int l, const F& cond) const {\n\
    \        T vl = M::id;\n        int r = size;\n        for (l += size, r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n                T nxt\
    \ = M::op(vl, node[l]);\n                if (cond(nxt)) {\n                  \
    \  while (l < size) {\n                        nxt = M::op(vl, node[2 * l]);\n\
    \                        if (cond(nxt)) l = 2 * l;\n                        else\
    \ vl = nxt, l = 2 * l + 1;\n                    }\n                    return\
    \ l - size;\n                }\n                vl = nxt;\n                ++l;\n\
    \            }\n        }\n        return -1;\n    }\n\n    template <typename\
    \ F>\n    int find_last(int r, const F& cond) const {\n        T vr = M::id;\n\
    \        int l = 0;\n        for (l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (r & 1) {\n                --r;\n                T nxt\
    \ = M::op(node[r], vr);\n                if (cond(nxt)) {\n                  \
    \  while (r < size) {\n                        nxt = M::op(node[2 * r + 1], vr);\n\
    \                        if (cond(nxt)) r = 2 * r + 1;\n                     \
    \   else vr = nxt, r = 2 * r;\n                    }\n                    return\
    \ r - size;\n                }\n                vr = nxt;\n            }\n   \
    \     }\n        return -1;\n    }\n\nprivate:\n    int size;\n    std::vector<T>\
    \ node;\n};\n#line 3 \"tree/hld.cpp\"\n\n/*\n * @brief Heavy-Light Decomposition\n\
    \ * @docs docs/tree/hld.md\n */\ntemplate <typename M>\nclass HLD {\n    using\
    \ T = typename M::T;\n\npublic:\n    HLD() = default;\n    explicit HLD(const\
    \ std::vector<std::vector<int>>& G) : HLD(G, std::vector<T>(G.size(), M::id))\
    \ {}\n    HLD(const std::vector<std::vector<int>>& G, const std::vector<T>& val)\n\
    \        : G(G), size(G.size()), depth(G.size()), par(G.size(), -1), pos(G.size()),\
    \ head(G.size()), heavy(G.size(), -1) {\n        dfs(0);\n        decompose(0,\
    \ 0);\n        std::vector<T> val_ordered(val.size());\n        for (int i = 0;\
    \ i < (int) val.size(); ++i) val_ordered[pos[i]] = val[i];\n        st = SegmentTree<M>(val_ordered);\n\
    \    }\n\n    T operator[](int v) const {\n        return st[pos[v]];\n    }\n\
    \n    void update(int v, const T& x) {\n        st.update(pos[v], x);\n    }\n\
    \n    T fold(int u, int v) const {\n        T res = M::id;\n        for (; head[u]\
    \ != head[v]; v = par[head[v]]) {\n            if (depth[head[u]] > depth[head[v]])\
    \ std::swap(u, v);\n            T val = st.fold(pos[head[v]], pos[v] + 1);\n \
    \           res = M::op(res, val);\n        }\n        if (depth[u] > depth[v])\
    \ std::swap(u, v);\n        T val = st.fold(pos[u], pos[v] + 1);\n        return\
    \ M::op(res, val);\n    }\n\n    int lca(int u, int v) const {\n        for (;;\
    \ v = par[head[v]]) {\n            if (depth[u] > depth[v]) std::swap(u, v);\n\
    \            if (head[u] == head[v]) return u;\n        }\n    }\n\n    int dist(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<int>\
    \ size, depth, par, pos, head, heavy;\n    int cur_pos = 0;\n    SegmentTree<M>\
    \ st;\n\n    void dfs(int v) {\n        size[v] = 1;\n        int max_size = 0;\n\
    \        for (int c : G[v]) {\n            if (c == par[v]) continue;\n      \
    \      par[c] = v;\n            depth[c] = depth[v] + 1;\n            dfs(c);\n\
    \            size[v] += size[c];\n            if (size[c] > max_size) {\n    \
    \            max_size = size[c];\n                heavy[v] = c;\n            }\n\
    \        }\n    }\n\n    void decompose(int v, int h) {\n        head[v] = h;\n\
    \        pos[v] = cur_pos++;\n        if (heavy[v] != -1) decompose(heavy[v],\
    \ h);\n        for (int c : G[v]) {\n            if (c != par[v] && c != heavy[v])\
    \ decompose(c, c);\n        }\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n#include \"../data-structure/segment_tree.cpp\"\
    \n\n/*\n * @brief Heavy-Light Decomposition\n * @docs docs/tree/hld.md\n */\n\
    template <typename M>\nclass HLD {\n    using T = typename M::T;\n\npublic:\n\
    \    HLD() = default;\n    explicit HLD(const std::vector<std::vector<int>>& G)\
    \ : HLD(G, std::vector<T>(G.size(), M::id)) {}\n    HLD(const std::vector<std::vector<int>>&\
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
    \ par[v] && c != heavy[v]) decompose(c, c);\n        }\n    }\n};\n"
  dependsOn:
  - data-structure/segment_tree.cpp
  isVerificationFile: false
  path: tree/hld.cpp
  requiredBy: []
  timestamp: '2020-10-01 22:49:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertex_add_path_sum.test.cpp
documentation_of: tree/hld.cpp
layout: document
redirect_from:
- /library/tree/hld.cpp
- /library/tree/hld.cpp.html
title: Heavy-Light Decomposition
---
# Heavy-Light Decomposition

HL 分解は，木をいくつかのパスに分解する手法である．分解されたパスからなる木は高さが高々 $O(\lg n)$ になる．これにより，木上のクエリを高速に処理することができる．

この実装ではクエリの処理にセグメント木を用いている．よって，一点更新と区間クエリが可能である．遅延伝搬セグメント木を使えば区間更新も可能だが面倒なので後でやる．

木に乗せられる代数的構造は可換モノイド $(T, \cdot, e)$ である．非可換にすることもできると思うが面倒なので後でやる．

空間計算量: $O(n)$

## Template parameters

- `M`
    - 可換モノイド $(T, \cdot, e)$．以下のメンバーが定義されている:
        - `T`: 集合 $T$ の型
        - `T id`: 単位元 $e$
        - `T op(T, T)`: 結合的かつ可換な二項演算 $\cdot: T \times T \rightarrow T$

## Constructor

- `HLD(vector<vector<int>> G)`
    - 木 `G` を HL 分解する．頂点の値は $e$ で初期化される．
    - 時間計算量: $O(n)$
- `HLD(vector<vector<int>> G, vector<T> val)`
    - 木 `G` を HL 分解する．頂点の値は `val` の値で初期化される．
    - 時間計算量: $O(n)$

## Member functions

- `T operator[](int v)`
    - 頂点 $v$ の値を返す
    - 時間計算量: $O(1)$
- `void update(int v, T x)`
    - 頂点 $v$ の値を $x$ に更新する
    - 時間計算量: $O(\lg n)$
- `T fold(int u, int v)`
    - $uv$ パス上の頂点の値を $\cdot$ で fold する．
    - 時間計算量: $O(\lg^2 n)$
- `int lca(int u, int v)`
    - $u$ と $v$ の最小共通祖先を返す
    - 時間計算量: $O(\lg n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\lg n)$


## Reference

- [Heavy-light decomposition](https://cp-algorithms.com/graph/hld.html)