---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: graph/two_edge_connected_components.cpp
    title: 2-Edge-Connected Components
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  - icon: ':x:'
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/graph/lowlink.md
    document_title: Lowlink
    links: []
  bundledCode: "#line 1 \"graph/lowlink.cpp\"\n#include <bits/stdc++.h>\n\n/*\n *\
    \ @brief Lowlink\n * @docs docs/graph/lowlink.md\n */\nclass Lowlink {\npublic:\n\
    \    Lowlink() = default;\n    explicit Lowlink(const std::vector<std::vector<int>>\
    \ G) : G(G), ord(G.size(), -1), low(G.size()) {\n        for (int i = 0; i < (int)\
    \ G.size(); ++i) {\n            if (ord[i] == -1) dfs(i, -1);\n        }\n   \
    \ }\n\n    std::vector<std::pair<int, int>> get_bridges() const {\n        return\
    \ bridge;\n    }\n\n    std::vector<int> get_articulation_points() const {\n \
    \       return articulation;\n    }\n\n    bool is_bridge(int u, int v) {\n  \
    \      if (ord[u] > ord[v]) std::swap(u, v);\n        return ord[u] < low[v];\n\
    \    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<int>\
    \ ord, low;\n    std::vector<std::pair<int, int>> bridge;\n    std::vector<int>\
    \ articulation;\n    int k = 0;\n\n    void dfs(int v, int p) {\n        ord[v]\
    \ = k++;\n        low[v] = ord[v];\n        bool is_articulation = false, checked\
    \ = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n            if\
    \ (c == p && !checked) {\n                checked = true;\n                continue;\n\
    \            }\n            if (ord[c] == -1) {\n                ++cnt;\n    \
    \            dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n\
    \                if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n  \
    \              if (ord[v] < low[c]) bridge.emplace_back(std::min(v, c), std::max(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Lowlink\n * @docs docs/graph/lowlink.md\n\
    \ */\nclass Lowlink {\npublic:\n    Lowlink() = default;\n    explicit Lowlink(const\
    \ std::vector<std::vector<int>> G) : G(G), ord(G.size(), -1), low(G.size()) {\n\
    \        for (int i = 0; i < (int) G.size(); ++i) {\n            if (ord[i] ==\
    \ -1) dfs(i, -1);\n        }\n    }\n\n    std::vector<std::pair<int, int>> get_bridges()\
    \ const {\n        return bridge;\n    }\n\n    std::vector<int> get_articulation_points()\
    \ const {\n        return articulation;\n    }\n\n    bool is_bridge(int u, int\
    \ v) {\n        if (ord[u] > ord[v]) std::swap(u, v);\n        return ord[u] <\
    \ low[v];\n    }\n\nprivate:\n    std::vector<std::vector<int>> G;\n    std::vector<int>\
    \ ord, low;\n    std::vector<std::pair<int, int>> bridge;\n    std::vector<int>\
    \ articulation;\n    int k = 0;\n\n    void dfs(int v, int p) {\n        ord[v]\
    \ = k++;\n        low[v] = ord[v];\n        bool is_articulation = false, checked\
    \ = false;\n        int cnt = 0;\n        for (int c : G[v]) {\n            if\
    \ (c == p && !checked) {\n                checked = true;\n                continue;\n\
    \            }\n            if (ord[c] == -1) {\n                ++cnt;\n    \
    \            dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n\
    \                if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n  \
    \              if (ord[v] < low[c]) bridge.emplace_back(std::min(v, c), std::max(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: graph/lowlink.cpp
  requiredBy:
  - graph/two_edge_connected_components.cpp
  timestamp: '2020-10-24 00:03:03+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/GRL_3_B.test.cpp
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: graph/lowlink.cpp
layout: document
redirect_from:
- /library/graph/lowlink.cpp
- /library/graph/lowlink.cpp.html
title: Lowlink
---
# Lowlink

Lowlink はグラフの橋や間接点などを求める際に有効な概念である．グラフの DFS tree において，頂点 $v$ の訪問時刻を `ord[v]` としたとき，$v$ から後退辺 (DFS tree に含まれない辺) を高々1回用いて到達することができる頂点の `ord` の最小値 `low[v]` を lowlink という．

辺 $(u, v)$ が橋であるとき，`ord[u] < low[v]` が成り立つ．

頂点 $v$ が間接点であるとき，$v$ が DFS tree の根なら $v$ は2つ以上の子を持ち，そうでないなら $v$ ある子 $c$ について `ord[v] <= low[v]` が成り立つ．

空間計算量: $O(V + E)$

## Constructor

- `Lowlink(vector<vector<int>> G)`
    - グラフ $G$ の隣接リストが与えられたとき，$G$ の橋と間接点を求める
    - 時間計算量: $O(V + E)$

## Member functions

- `vector<pair<int, int>> get_bridges()`
    - $G$ の橋を返す
- `vector<int> get_articulation_points()`
    - $G$ の間接点を返す
- `bool is_bridge(int u, int v)`
    - 辺 $uv$ が橋かどうか判定する
    - 時間計算量: $O(1)$

## Reference

- [橋と関節点, lowlink](https://kagamiz.hatenablog.com/entry/2013/10/05/005213)