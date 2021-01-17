---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/hld.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename M>\nclass HLD {\n    using T = typename M::T;\n\npublic:\n\
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
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ M>\nclass HLD {\n    using T = typename M::T;\n\npublic:\n    HLD() = default;\n\
    \    HLD(const std::vector<std::vector<int>>& G, bool edge)\n        : G(G), size(G.size()),\
    \ depth(G.size()), par(G.size(), -1),\n          in(G.size()), out(G.size()),\
    \ head(G.size()), heavy(G.size(), -1), edge(edge) {\n        dfs(0);\n       \
    \ decompose(0, 0);\n    }\n\n    template <typename F>\n    void update(int v,\
    \ const T& x, const F& f) const {\n        f(in[v], x);\n    }\n\n    template\
    \ <typename E, typename F>\n    void update(int u, int v, const E& x, const F&\
    \ f) const {\n        while (head[u] != head[v]) {\n            if (in[head[u]]\
    \ > in[head[v]]) std::swap(u, v);\n            f(in[head[v]], in[v] + 1, x);\n\
    \            v = par[head[v]];\n        }\n        if (in[u] > in[v]) std::swap(u,\
    \ v);\n        f(in[u] + edge, in[v] + 1, x);\n    }\n\n    template <typename\
    \ F>\n    T path_fold(int u, int v, const F& f) const {\n        T res = M::id;\n\
    \        while (head[u] != head[v]) {\n            if (in[head[u]] > in[head[v]])\
    \ std::swap(u, v);\n            T val = f(in[head[v]], in[v] + 1);\n         \
    \   res = M::op(val, res);\n            v = par[head[v]];\n        }\n       \
    \ if (in[u] > in[v]) std::swap(u, v);\n        T val = f(in[u] + edge, in[v] +\
    \ 1);\n        return M::op(val, res);\n    }\n\n    template <typename F>\n \
    \   T subtree_fold(int v, const F& f) const {\n        return f(in[v] + edge,\
    \ out[v]);\n    }\n\n    int lca(int u, int v) const {\n        while (true) {\n\
    \            if (in[u] > in[v]) std::swap(u, v);\n            if (head[u] == head[v])\
    \ return u;\n            v = par[head[v]];\n        }\n    }\n\n    int dist(int\
    \ u, int v) const {\n        return depth[u] + depth[v] - 2 * depth[lca(u, v)];\n\
    \    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<int>\
    \ size, depth, par, in, out, head, heavy;\n    bool edge;\n    int cur_pos = 0;\n\
    \n    void dfs(int v) {\n        size[v] = 1;\n        int max_size = 0;\n   \
    \     for (int c : G[v]) {\n            if (c == par[v]) continue;\n         \
    \   par[c] = v;\n            depth[c] = depth[v] + 1;\n            dfs(c);\n \
    \           size[v] += size[c];\n            if (size[c] > max_size) {\n     \
    \           max_size = size[c];\n                heavy[v] = c;\n            }\n\
    \        }\n    }\n\n    void decompose(int v, int h) {\n        head[v] = h;\n\
    \        in[v] = cur_pos++;\n        if (heavy[v] != -1) decompose(heavy[v], h);\n\
    \        for (int c : G[v]) {\n            if (c != par[v] && c != heavy[v]) decompose(c,\
    \ c);\n        }\n        out[v] = cur_pos;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/hld.cpp
  requiredBy: []
  timestamp: '2021-01-17 17:56:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/vertex_add_subtree_sum.hld.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
documentation_of: tree/hld.cpp
layout: document
title: Heavy-Light Decomposition
---

## Description

HL 分解 (重軽分解) は，木をいくつかのパスに分解する手法である．分解されたパスからなる木は高さが高々 $O(\lg n)$ になる．これにより，木上のクエリを高速に処理することができる．

木に乗せられる代数的構造は可換モノイド $(T, \cdot, e)$ である．非可換モノイドも乗せられないことはないが，めんどくさい (後述)．

空間計算量: $O(n)$

## Operations

- `HLD(vector<vector<int>> G, bool edge)`
    - 木 `G` を HL 分解する．`edge == true` ならクエリは辺に対して実行される．
    - 時間計算量: $O(n)$
- `void update(int v, T x, F update)`
    - 頂点 $v$ に対して $update(x)$ を実行する
    - 時間計算量: $O(f(n) \lg n)$
- `void update(int u, int v, T x, F update)`
    - $uv$ パス上の頂点/辺に対して $update(x)$ を実行する．
    - 時間計算量: $O(f(n) \lg n)$
- `T path_fold(int u, int v, F fold)`
    - $uv$ パス上の頂点/辺に対して $fold()$ を実行する．
    - 時間計算量: $O(f(n) \lg n)$
- `T subtree_fold(int v, F fold)`
    - 頂点 $v$ を根とする部分木の頂点/辺に対して $fold()$ を実行する．
    - 時間計算量: $O(f(n))$
- `int lca(int u, int v)`
    - 頂点 $u$ と頂点 $v$ の最小共通祖先を返す
    - 時間計算量: $O(\lg n)$
- `int dist(int u, int v)`
    - $uv$ 間の距離を計算する
    - 時間計算量: $O(\lg n)$

## Note

`update` および `fold` の時間計算量を $f(n)$ としている．

非可換モノイドを載せたいときは，例えば以下のような方法が使える．
- $uv$ パス上で fold したいとする．上から下に下る分には非可換で fold できるので，$u$ と $v$ の LCA $p$ を求めて，$pu$ パスと $pv$ パスを fold する．
- $pu$ パスの結果を反転する．これは，モノイドに2方向から fold した結果を持たせておけばよい．
- $a_{up} \cdot a_p^{-1} \cdot a_{pv}$ を計算する．

以上の方法は逆元の存在を仮定している．非可換モノイドを扱うためだけに関数を書き換えれば逆元なしでできるが，めんどくさい．

## Reference

- [Heavy-Light Decomposition](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [Heavy-light decomposition](https://cp-algorithms.com/graph/hld.html)
- [Easiest HLD with subtree queries](https://codeforces.com/blog/entry/53170)

## TODO

- 非可換 fold ましなやり方