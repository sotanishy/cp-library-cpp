---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/unionfind/union_find.hpp
    title: Union Find
  - icon: ':heavy_check_mark:'
    path: graph/junction_tree.hpp
    title: Junction Tree (Width 2)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_decomposition_width_2
    links:
    - https://judge.yosupo.jp/problem/tree_decomposition_width_2
  bundledCode: "#line 1 \"test/yosupo/tree_decomposition_width_2.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/tree_decomposition_width_2\"\n\n#include\
    \ <bits/stdc++.h>\n\n#line 5 \"graph/junction_tree.hpp\"\n\n#line 4 \"data-structure/unionfind/union_find.hpp\"\
    \n\nclass UnionFind {\n   public:\n    UnionFind() = default;\n    explicit UnionFind(int\
    \ n) : data(n, -1) {}\n\n    int find(int x) {\n        if (data[x] < 0) return\
    \ x;\n        return data[x] = find(data[x]);\n    }\n\n    void unite(int x,\
    \ int y) {\n        x = find(x);\n        y = find(y);\n        if (x == y) return;\n\
    \        if (data[x] > data[y]) std::swap(x, y);\n        data[x] += data[y];\n\
    \        data[y] = x;\n    }\n\n    bool same(int x, int y) { return find(x) ==\
    \ find(y); }\n\n    int size(int x) { return -data[find(x)]; }\n\n   private:\n\
    \    std::vector<int> data;\n};\n#line 7 \"graph/junction_tree.hpp\"\n\nclass\
    \ JunctionTreeWidth2 {\n   public:\n    struct Node {\n        std::vector<int>\
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
    \   // add new edge\n                if (!G_st[x].contains(y)) {\n           \
    \         G_st[x].insert(y);\n                    G_st[y].insert(x);\n       \
    \         } else {\n                    --deg[x], --deg[y];\n                }\n\
    \            }\n            for (int u : G_st[v]) {\n                if (state[u]\
    \ == -1 && deg[u] <= 2) {\n                    st.push(u);\n                }\n\
    \            }\n\n            deg[v] = 0;\n            state[v] = nodes.size();\n\
    \            nodes.push_back(node);\n        }\n\n        if (*std::ranges::max_element(deg)\
    \ > 0) {\n            treewidth_is_2 = false;\n            return;\n        }\n\
    \n        treewidth_is_2 = true;\n        nodes[0].ch.push_back(nodes.size() -\
    \ 1);\n    }\n\n    bool is_treewidth_2() const { return treewidth_is_2; }\n\n\
    \    int size() const { return nodes.size(); }\n\n    std::vector<Node> get_nodes()\
    \ const { return nodes; }\n\n   private:\n    bool treewidth_is_2;\n    std::vector<Node>\
    \ nodes;\n};\n#line 6 \"test/yosupo/tree_decomposition_width_2.test.cpp\"\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    string _s;\n    cin >> _s >> _s;\n    int N, M;\n\
    \    cin >> N >> M;\n    vector<vector<int>> G(N);\n    for (int i = 0; i < M;\
    \ ++i) {\n        int u, v;\n        cin >> u >> v;\n        --u, --v;\n     \
    \   G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    JunctionTreeWidth2\
    \ jt(G);\n    if (!jt.is_treewidth_2()) {\n        cout << -1 << \"\\n\";\n  \
    \      return 0;\n    }\n    auto nodes = jt.get_nodes();\n    int K = jt.size();\n\
    \    cout << \"s td \" << K << \" 2 \" << N << \"\\n\";\n    for (int i = 0; i\
    \ < K; ++i) {\n        cout << \"b \" << i + 1;\n        for (int v : nodes[i].bag)\
    \ {\n            cout << \" \" << v + 1;\n        }\n        cout << \"\\n\";\n\
    \    }\n    for (int i = 0; i < K; ++i) {\n        for (int c : nodes[i].ch) {\n\
    \            cout << i + 1 << \" \" << c + 1 << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_decomposition_width_2\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../graph/junction_tree.hpp\"\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    string _s;\n    cin >> _s >> _s;\n    int N, M;\n\
    \    cin >> N >> M;\n    vector<vector<int>> G(N);\n    for (int i = 0; i < M;\
    \ ++i) {\n        int u, v;\n        cin >> u >> v;\n        --u, --v;\n     \
    \   G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n    JunctionTreeWidth2\
    \ jt(G);\n    if (!jt.is_treewidth_2()) {\n        cout << -1 << \"\\n\";\n  \
    \      return 0;\n    }\n    auto nodes = jt.get_nodes();\n    int K = jt.size();\n\
    \    cout << \"s td \" << K << \" 2 \" << N << \"\\n\";\n    for (int i = 0; i\
    \ < K; ++i) {\n        cout << \"b \" << i + 1;\n        for (int v : nodes[i].bag)\
    \ {\n            cout << \" \" << v + 1;\n        }\n        cout << \"\\n\";\n\
    \    }\n    for (int i = 0; i < K; ++i) {\n        for (int c : nodes[i].ch) {\n\
    \            cout << i + 1 << \" \" << c + 1 << \"\\n\";\n        }\n    }\n}\n"
  dependsOn:
  - graph/junction_tree.hpp
  - data-structure/unionfind/union_find.hpp
  isVerificationFile: true
  path: test/yosupo/tree_decomposition_width_2.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree_decomposition_width_2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_decomposition_width_2.test.cpp
- /verify/test/yosupo/tree_decomposition_width_2.test.cpp.html
title: test/yosupo/tree_decomposition_width_2.test.cpp
---
