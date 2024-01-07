---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/unionfind/union_find.cpp
    title: Union Find
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_decomposition_width_2.test.cpp
    title: test/yosupo/tree_decomposition_width_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/junction_tree.hpp\"\n#include <set>\n#include <stack>\n\
    #include <vector>\n\n#line 2 \"data-structure/unionfind/union_find.cpp\"\n#include\
    \ <algorithm>\n#line 4 \"data-structure/unionfind/union_find.cpp\"\n\nclass UnionFind\
    \ {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int n) : data(n,\
    \ -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return x;\n      \
    \  return data[x] = find(data[x]);\n    }\n\n    void unite(int x, int y) {\n\
    \        x = find(x);\n        y = find(y);\n        if (x == y) return;\n   \
    \     if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n \
    \       data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return find(x)\
    \ == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};\n#line 7 \"graph/junction_tree.hpp\"\
    \n\nclass JunctionTreeWidth2 {\n   public:\n    struct Node {\n        std::vector<int>\
    \ bag;\n        std::vector<int> ch;\n    };\n\n    explicit JunctionTreeWidth2(const\
    \ std::vector<std::vector<int>>& G)\n        : nodes(1) {\n        const int n\
    \ = G.size();\n\n        UnionFind uf(n);\n        std::vector<int> deg(n);\n\
    \        std::vector<std::set<int>> G_st(n);\n        for (int v = 0; v < n; ++v)\
    \ {\n            for (int u : G[v]) {\n                uf.unite(u, v);\n     \
    \           G_st[v].insert(u);\n            }\n            deg[v] = G_st[v].size();\n\
    \        }\n\n        // add dummy edges to make G connected\n        std::vector<int>\
    \ leaders;\n        for (int v = 0; v < n; ++v) {\n            if (uf.find(v)\
    \ == v) {\n                leaders.push_back(v);\n            }\n        }\n \
    \       for (int i = 0; i < (int)leaders.size() - 1; ++i) {\n            int u\
    \ = leaders[i];\n            int v = leaders[i + 1];\n            G_st[u].insert(v);\n\
    \            G_st[v].insert(u);\n            ++deg[u], ++deg[v];\n        }\n\n\
    \        // construct a tree decomposition of width 2\n\n        // -2: removed\
    \ and added to the tree\n        // -1: not removed\n        // >= 0: removed\
    \ and not yet added to the tree\n        std::vector<int> state(n, -1);\n    \
    \    std::stack<int> st;\n        for (int v = 0; v < n; ++v) {\n            if\
    \ (deg[v] <= 2) {\n                st.push(v);\n            }\n        }\n   \
    \     while (!st.empty()) {\n            int v = st.top();\n            st.pop();\n\
    \            if (state[v] != -1) continue;\n            Node node;\n         \
    \   node.bag.push_back(v);\n            int x = -1, y = -1;\n            for (int\
    \ u : G_st[v]) {\n                if (state[u] == -1) {\n                    (x\
    \ == -1 ? x : y) = u;\n                    node.bag.push_back(u);\n          \
    \      } else if (state[u] > 0) {\n                    node.ch.push_back(state[u]);\n\
    \                    state[u] = -2;\n                }\n            }\n\n    \
    \        if (x == -1) {\n                // last vertex\n            } else if\
    \ (y == -1) {\n                --deg[x];\n            } else {\n             \
    \   // add new edge\n                if (!G_st[x].count(y)) {\n              \
    \      G_st[x].insert(y);\n                    G_st[y].insert(x);\n          \
    \      } else {\n                    --deg[x], --deg[y];\n                }\n\
    \            }\n            for (int u : G_st[v]) {\n                if (state[u]\
    \ == -1 && deg[u] <= 2) {\n                    st.push(u);\n                }\n\
    \            }\n\n            deg[v] = 0;\n            state[v] = nodes.size();\n\
    \            nodes.push_back(node);\n        }\n\n        if (*std::max_element(deg.begin(),\
    \ deg.end()) > 0) {\n            treewidth_is_2 = false;\n            return;\n\
    \        }\n\n        treewidth_is_2 = true;\n        nodes[0].ch.push_back(nodes.size()\
    \ - 1);\n    }\n\n    bool is_treewidth_2() const { return treewidth_is_2; }\n\
    \n    int size() const { return nodes.size(); }\n\n    std::vector<Node> get_nodes()\
    \ const { return nodes; }\n\n   private:\n    bool treewidth_is_2;\n    std::vector<Node>\
    \ nodes;\n};\n"
  code: "#pragma once\n#include <set>\n#include <stack>\n#include <vector>\n\n#include\
    \ \"../data-structure/unionfind/union_find.cpp\"\n\nclass JunctionTreeWidth2 {\n\
    \   public:\n    struct Node {\n        std::vector<int> bag;\n        std::vector<int>\
    \ ch;\n    };\n\n    explicit JunctionTreeWidth2(const std::vector<std::vector<int>>&\
    \ G)\n        : nodes(1) {\n        const int n = G.size();\n\n        UnionFind\
    \ uf(n);\n        std::vector<int> deg(n);\n        std::vector<std::set<int>>\
    \ G_st(n);\n        for (int v = 0; v < n; ++v) {\n            for (int u : G[v])\
    \ {\n                uf.unite(u, v);\n                G_st[v].insert(u);\n   \
    \         }\n            deg[v] = G_st[v].size();\n        }\n\n        // add\
    \ dummy edges to make G connected\n        std::vector<int> leaders;\n       \
    \ for (int v = 0; v < n; ++v) {\n            if (uf.find(v) == v) {\n        \
    \        leaders.push_back(v);\n            }\n        }\n        for (int i =\
    \ 0; i < (int)leaders.size() - 1; ++i) {\n            int u = leaders[i];\n  \
    \          int v = leaders[i + 1];\n            G_st[u].insert(v);\n         \
    \   G_st[v].insert(u);\n            ++deg[u], ++deg[v];\n        }\n\n       \
    \ // construct a tree decomposition of width 2\n\n        // -2: removed and added\
    \ to the tree\n        // -1: not removed\n        // >= 0: removed and not yet\
    \ added to the tree\n        std::vector<int> state(n, -1);\n        std::stack<int>\
    \ st;\n        for (int v = 0; v < n; ++v) {\n            if (deg[v] <= 2) {\n\
    \                st.push(v);\n            }\n        }\n        while (!st.empty())\
    \ {\n            int v = st.top();\n            st.pop();\n            if (state[v]\
    \ != -1) continue;\n            Node node;\n            node.bag.push_back(v);\n\
    \            int x = -1, y = -1;\n            for (int u : G_st[v]) {\n      \
    \          if (state[u] == -1) {\n                    (x == -1 ? x : y) = u;\n\
    \                    node.bag.push_back(u);\n                } else if (state[u]\
    \ > 0) {\n                    node.ch.push_back(state[u]);\n                 \
    \   state[u] = -2;\n                }\n            }\n\n            if (x == -1)\
    \ {\n                // last vertex\n            } else if (y == -1) {\n     \
    \           --deg[x];\n            } else {\n                // add new edge\n\
    \                if (!G_st[x].count(y)) {\n                    G_st[x].insert(y);\n\
    \                    G_st[y].insert(x);\n                } else {\n          \
    \          --deg[x], --deg[y];\n                }\n            }\n           \
    \ for (int u : G_st[v]) {\n                if (state[u] == -1 && deg[u] <= 2)\
    \ {\n                    st.push(u);\n                }\n            }\n\n   \
    \         deg[v] = 0;\n            state[v] = nodes.size();\n            nodes.push_back(node);\n\
    \        }\n\n        if (*std::max_element(deg.begin(), deg.end()) > 0) {\n \
    \           treewidth_is_2 = false;\n            return;\n        }\n\n      \
    \  treewidth_is_2 = true;\n        nodes[0].ch.push_back(nodes.size() - 1);\n\
    \    }\n\n    bool is_treewidth_2() const { return treewidth_is_2; }\n\n    int\
    \ size() const { return nodes.size(); }\n\n    std::vector<Node> get_nodes() const\
    \ { return nodes; }\n\n   private:\n    bool treewidth_is_2;\n    std::vector<Node>\
    \ nodes;\n};\n"
  dependsOn:
  - data-structure/unionfind/union_find.cpp
  isVerificationFile: false
  path: graph/junction_tree.hpp
  requiredBy: []
  timestamp: '2023-05-07 15:56:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/tree_decomposition_width_2.test.cpp
documentation_of: graph/junction_tree.hpp
layout: document
title: Junction Tree (Width 2)
---

## Description

与えられた木の木幅が $2$ 以下か判定し，そうならば木幅 $2$ の木分解を構築する．

空間計算量: $O(V + E)$

## Operations

- `JunctionTreeWidth2(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ の木幅 $2$ の木分解を求める．
    - 時間計算量: $O(E\log V)$
- `bool is_treewidth_2()`
    - 木幅が $2$ 以下か判定する
- `vector<Node> get_nodes()`
    - $G$ の junction tree のノードを返す．`Node` は `bag` メンバと `ch` メンバを持つ． `bag` はそのノードに含まれる $G$ の頂点， `ch` は junction tree におけるそのノードの子である．

## Reference

- [木幅が2以下のグラフの木分解と動的計画法 - ei1333の日記](https://ei1333.hateblo.jp/entry/2020/02/12/150319)
- [離散最適化基礎論 (2016年度後学期) グラフの木分解](http://dopal.cs.uec.ac.jp/okamotoy/lect/2016/treewidth/)