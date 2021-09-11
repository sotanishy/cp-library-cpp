---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: data-structure/leftist_heap.cpp
    title: Leftist Heap
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/union_find.cpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/directedmst.test.cpp
    title: test/yosupo/directedmst.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Minimum Spanning Arborescence
    links: []
  bundledCode: "#line 2 \"graph/minimum_spanning_arborescence.cpp\"\n#include <algorithm>\n\
    #include <limits>\n#include <memory>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n#line 2 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge {\n    int from, to;\n    T weight;\n    Edge() = default;\n    Edge(int\
    \ to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int from, int\
    \ to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 4 \"data-structure/unionfind/union_find.cpp\"\
    \n\nclass UnionFind {\npublic:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) {\n        return\
    \ find(x) == find(y);\n    }\n\n    int size(int x) {\n        return -data[find(x)];\n\
    \    }\n\nprivate:\n    std::vector<int> data;\n};\n#line 5 \"data-structure/leftist_heap.cpp\"\
    \n\ntemplate <typename T>\nclass LeftistHeap {\npublic:\n    LeftistHeap() = default;\n\
    \n    static LeftistHeap meld(LeftistHeap a, LeftistHeap b) {\n        return\
    \ LeftistHeap(meld(std::move(a.root), std::move(b.root)));\n    }\n\n    std::pair<int,\
    \ T> top() const {\n        push(root);\n        return {root->id, root->val};\n\
    \    }\n\n    void pop() {\n        push(root);\n        root = meld(std::move(root->left),\
    \ std::move(root->right));\n    }\n\n    void push(int id, T x) {\n        root\
    \ = meld(std::move(root), std::make_unique<Node>(id, x));\n    }\n\n    bool empty()\
    \ const { return root == nullptr; }\n\n    void add(T x) { root->lazy += x; }\n\
    \nprivate:\n    struct Node;\n    using node_ptr = std::unique_ptr<Node>;\n\n\
    \    struct Node {\n        node_ptr left, right;\n        int s;\n        int\
    \ id;\n        T val, lazy;\n        Node(int id, T x) : id(id), val(x), lazy(0)\
    \ {}\n    };\n\n    node_ptr root = nullptr;\n\n    explicit LeftistHeap(node_ptr\
    \ root) : root(std::move(root)) {}\n\n    static node_ptr meld(node_ptr a, node_ptr\
    \ b) {\n        if (!a) return b;\n        if (!b) return a;\n        push(a);\n\
    \        push(b);\n        if (a->val > b->val) std::swap(a, b);\n        a->right\
    \ = meld(std::move(a->right), std::move(b));\n        if (!a->left || a->left->s\
    \ < a->right->s) std::swap(a->left, a->right);\n        a->s = (a->right ? a->right->s\
    \ : 0) + 1;\n        return a;\n    }\n\n    static void push(const node_ptr&\
    \ t) {\n        if (t->left) t->left->lazy += t->lazy;\n        if (t->right)\
    \ t->right->lazy += t->lazy;\n        t->val += t->lazy;\n        t->lazy = 0;\n\
    \    }\n};\n#line 11 \"graph/minimum_spanning_arborescence.cpp\"\n\n/*\n * @brief\
    \ Minimum Spanning Arborescence\n */\ntemplate <typename T>\nstd::pair<T, std::vector<int>>\
    \ minimum_spanning_arborescence(std::vector<Edge<T>> G, int V, int root) {\n \
    \   std::vector<LeftistHeap<T>> incoming(V);\n    for (int i = 0; i < (int) G.size();\
    \ ++i) {\n        auto& e = G[i];\n        incoming[e.to].push(i, e.weight);\n\
    \    }\n    T weight = 0;\n    UnionFind uf(V);\n    std::vector<int> from(V),\
    \ stem(V, -1), prev_edge(G.size()), ord;\n    std::vector<T> from_cost(V);\n \
    \   std::vector<int> status(V); // 0: not checked, 1: cheking, 2: checked\n  \
    \  status[root] = 2;\n\n    for (int s = 0; s < V; ++s) {\n        if (status[s]\
    \ != 0) continue;\n        int cur = s, cyc = 0;\n        std::vector<int> seen,\
    \ processing;\n        while (status[cur] != 2) {\n            status[cur] = 1;\n\
    \            processing.push_back(cur);\n            if (incoming[cur].empty())\
    \ { // no msa\n                return {std::numeric_limits<T>::max(), std::vector<int>()};\n\
    \            }\n\n            auto [i, c] = incoming[cur].top();\n           \
    \ int v = uf.find(G[i].from);\n            incoming[cur].pop();\n            if\
    \ (cur == v) continue;\n            from[cur] = v;\n            from_cost[cur]\
    \ = c;\n            weight += c;\n            ord.push_back(i);\n            if\
    \ (stem[cur] == -1) stem[cur] = i;\n            while (cyc) {\n              \
    \  prev_edge[seen.back()] = i;\n                seen.pop_back();\n           \
    \     --cyc;\n            }\n            seen.push_back(i);\n\n            if\
    \ (status[v] == 1) {\n                int p = cur;\n                do {\n   \
    \                 if (!incoming[p].empty()) incoming[p].add(-from_cost[p]);\n\
    \                    if (p != cur) {\n                        uf.unite(p, cur);\n\
    \                        auto newheap = LeftistHeap<T>::meld(std::move(incoming[cur]),\
    \ std::move(incoming[p]));\n                        incoming[cur = uf.find(cur)]\
    \ = std::move(newheap);\n                    }\n                    p = uf.find(from[p]);\n\
    \                    ++cyc;\n                } while (p != cur);\n           \
    \ } else {\n                cur = v;\n            }\n        }\n        for (int\
    \ v : processing) status[v] = 2;\n    }\n    std::reverse(ord.begin(), ord.end());\n\
    \    std::vector<bool> used_edge(G.size());\n    std::vector<int> par(V);\n  \
    \  std::iota(par.begin(), par.end(), 0);\n    for (int i : ord) {\n        if\
    \ (used_edge[i]) continue;\n        auto& e = G[i];\n        par[e.to] = e.from;\n\
    \        int x = stem[e.to];\n        while (x != i) {\n            used_edge[x]\
    \ = true;\n            x = prev_edge[x];\n        }\n    }\n    return {weight,\
    \ par};\n}\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <memory>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\n#include \"edge.cpp\"\
    \n#include \"../data-structure/unionfind/union_find.cpp\"\n#include \"../data-structure/leftist_heap.cpp\"\
    \n\n/*\n * @brief Minimum Spanning Arborescence\n */\ntemplate <typename T>\n\
    std::pair<T, std::vector<int>> minimum_spanning_arborescence(std::vector<Edge<T>>\
    \ G, int V, int root) {\n    std::vector<LeftistHeap<T>> incoming(V);\n    for\
    \ (int i = 0; i < (int) G.size(); ++i) {\n        auto& e = G[i];\n        incoming[e.to].push(i,\
    \ e.weight);\n    }\n    T weight = 0;\n    UnionFind uf(V);\n    std::vector<int>\
    \ from(V), stem(V, -1), prev_edge(G.size()), ord;\n    std::vector<T> from_cost(V);\n\
    \    std::vector<int> status(V); // 0: not checked, 1: cheking, 2: checked\n \
    \   status[root] = 2;\n\n    for (int s = 0; s < V; ++s) {\n        if (status[s]\
    \ != 0) continue;\n        int cur = s, cyc = 0;\n        std::vector<int> seen,\
    \ processing;\n        while (status[cur] != 2) {\n            status[cur] = 1;\n\
    \            processing.push_back(cur);\n            if (incoming[cur].empty())\
    \ { // no msa\n                return {std::numeric_limits<T>::max(), std::vector<int>()};\n\
    \            }\n\n            auto [i, c] = incoming[cur].top();\n           \
    \ int v = uf.find(G[i].from);\n            incoming[cur].pop();\n            if\
    \ (cur == v) continue;\n            from[cur] = v;\n            from_cost[cur]\
    \ = c;\n            weight += c;\n            ord.push_back(i);\n            if\
    \ (stem[cur] == -1) stem[cur] = i;\n            while (cyc) {\n              \
    \  prev_edge[seen.back()] = i;\n                seen.pop_back();\n           \
    \     --cyc;\n            }\n            seen.push_back(i);\n\n            if\
    \ (status[v] == 1) {\n                int p = cur;\n                do {\n   \
    \                 if (!incoming[p].empty()) incoming[p].add(-from_cost[p]);\n\
    \                    if (p != cur) {\n                        uf.unite(p, cur);\n\
    \                        auto newheap = LeftistHeap<T>::meld(std::move(incoming[cur]),\
    \ std::move(incoming[p]));\n                        incoming[cur = uf.find(cur)]\
    \ = std::move(newheap);\n                    }\n                    p = uf.find(from[p]);\n\
    \                    ++cyc;\n                } while (p != cur);\n           \
    \ } else {\n                cur = v;\n            }\n        }\n        for (int\
    \ v : processing) status[v] = 2;\n    }\n    std::reverse(ord.begin(), ord.end());\n\
    \    std::vector<bool> used_edge(G.size());\n    std::vector<int> par(V);\n  \
    \  std::iota(par.begin(), par.end(), 0);\n    for (int i : ord) {\n        if\
    \ (used_edge[i]) continue;\n        auto& e = G[i];\n        par[e.to] = e.from;\n\
    \        int x = stem[e.to];\n        while (x != i) {\n            used_edge[x]\
    \ = true;\n            x = prev_edge[x];\n        }\n    }\n    return {weight,\
    \ par};\n}\n"
  dependsOn:
  - graph/edge.cpp
  - data-structure/unionfind/union_find.cpp
  - data-structure/leftist_heap.cpp
  isVerificationFile: false
  path: graph/minimum_spanning_arborescence.cpp
  requiredBy: []
  timestamp: '2021-09-11 15:28:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/directedmst.test.cpp
documentation_of: graph/minimum_spanning_arborescence.cpp
layout: document
redirect_from:
- /library/graph/minimum_spanning_arborescence.cpp
- /library/graph/minimum_spanning_arborescence.cpp.html
title: Minimum Spanning Arborescence
---
