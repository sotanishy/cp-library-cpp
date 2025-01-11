---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/biconnected_components.hpp
    title: Biconnected Components
  - icon: ':question:'
    path: graph/lowlink.hpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/yosupo/biconnected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n#line 2 \"graph/biconnected_components.hpp\"\
    \n#include <stack>\n#include <utility>\n#include <vector>\n\n#line 2 \"graph/lowlink.hpp\"\
    \n#include <algorithm>\n#line 5 \"graph/lowlink.hpp\"\n\nclass Lowlink {\n   public:\n\
    \    std::vector<int> ord, low;\n    std::vector<std::pair<int, int>> bridge;\n\
    \    std::vector<int> articulation;\n\n    Lowlink() = default;\n    explicit\
    \ Lowlink(const std::vector<std::vector<int>>& G)\n        : ord(G.size(), -1),\
    \ low(G.size()), G(G) {\n        for (int i = 0; i < (int)G.size(); ++i) {\n \
    \           if (ord[i] == -1) dfs(i, -1);\n        }\n    }\n\n    bool is_bridge(int\
    \ u, int v) const {\n        if (ord[u] > ord[v]) std::swap(u, v);\n        return\
    \ ord[u] < low[v];\n    }\n\n   private:\n    std::vector<std::vector<int>> G;\n\
    \    int k = 0;\n\n    void dfs(int v, int p) {\n        ord[v] = k++;\n     \
    \   low[v] = ord[v];\n        bool is_articulation = false, checked = false;\n\
    \        int cnt = 0;\n        for (int c : G[v]) {\n            if (c == p &&\
    \ !checked) {\n                checked = true;\n                continue;\n  \
    \          }\n            if (ord[c] == -1) {\n                ++cnt;\n      \
    \          dfs(c, v);\n                low[v] = std::min(low[v], low[c]);\n  \
    \              if (p != -1 && ord[v] <= low[c]) is_articulation = true;\n    \
    \            if (ord[v] < low[c]) bridge.push_back(std::minmax(v, c));\n     \
    \       } else {\n                low[v] = std::min(low[v], ord[c]);\n       \
    \     }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 7 \"\
    graph/biconnected_components.hpp\"\n\nstd::vector<std::vector<int>> biconnected_components(\n\
    \    const std::vector<std::vector<int>>& G, const Lowlink& low) {\n    std::vector<bool>\
    \ used(G.size());\n    std::stack<std::pair<int, int>> st;\n    std::vector<std::vector<int>>\
    \ blocks;\n    std::vector<int> isolated;\n\n    auto dfs = [&](auto& dfs, int\
    \ v, int p) -> void {\n        used[v] = true;\n        for (int c : G[v]) {\n\
    \            if (c == p) continue;\n            if (!used[c] || low.ord[c] < low.ord[v])\
    \ {\n                st.emplace(v, c);\n            }\n            if (!used[c])\
    \ {\n                dfs(dfs, c, v);\n                if (low.ord[v] <= low.low[c])\
    \ {  // v is an articulation point\n                    blocks.emplace_back();\n\
    \                    auto& block = blocks.back();\n                    while (true)\
    \ {\n                        auto e = st.top();\n                        st.pop();\n\
    \                        block.push_back(e.first);\n                        block.push_back(e.second);\n\
    \                        if (e.first == v) {\n                            break;\n\
    \                        }\n                    }\n                    std::sort(block.begin(),\
    \ block.end());\n                    block.erase(std::unique(block.begin(), block.end()),\n\
    \                                block.end());\n                }\n          \
    \  }\n        }\n    };\n\n    for (int v = 0; v < (int)G.size(); ++v) {\n   \
    \     if (!used[v]) dfs(dfs, v, -1);\n        if (G[v].empty()) {\n          \
    \  blocks.push_back({v});\n        }\n    }\n\n    return blocks;\n}\n\n// B:\
    \ number of blocks, C: number of cut vertices\n// 0 through B - 1: block\n// B\
    \ through B + C - 1: cut\nstd::vector<std::vector<int>> block_cut_tree(\n    const\
    \ std::vector<std::vector<int>>& blocks, const std::vector<int>& cuts) {\n   \
    \ const int B = blocks.size();\n    std::vector<std::vector<int>> bct(B + (int)cuts.size());\n\
    \    std::unordered_map<int, int> cut_idx;\n    for (int i = 0; i < (int)cuts.size();\
    \ ++i) cut_idx[cuts[i]] = i;\n\n    for (int i = 0; i < (int)blocks.size(); ++i)\
    \ {\n        auto& block = blocks[i];\n        for (int v : block) {\n       \
    \     if (cut_idx.contains(v)) {\n                int j = B + cut_idx[v];\n  \
    \              bct[i].push_back(j);\n                bct[j].push_back(i);\n  \
    \          }\n        }\n    }\n\n    return bct;\n}\n#line 4 \"test/yosupo/biconnected_components.test.cpp\"\
    \n\n#include <bits/stdc++.h>\n\n#line 8 \"test/yosupo/biconnected_components.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < M; ++i) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n    }\n   \
    \ Lowlink low(G);\n    auto blocks = biconnected_components(G, low);\n    cout\
    \ << blocks.size() << endl;\n    for (auto& block : blocks) {\n        cout <<\
    \ block.size();\n        for (int i : block) cout << \" \" << i;\n        cout\
    \ << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"../../graph/biconnected_components.hpp\"\n\n#include <bits/stdc++.h>\n\
    \n#include \"../../graph/lowlink.hpp\"\nusing namespace std;\nusing ll = long\
    \ long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> G(N);\n    for (int\
    \ i = 0; i < M; ++i) {\n        int a, b;\n        cin >> a >> b;\n        G[a].push_back(b);\n\
    \        G[b].push_back(a);\n    }\n    Lowlink low(G);\n    auto blocks = biconnected_components(G,\
    \ low);\n    cout << blocks.size() << endl;\n    for (auto& block : blocks) {\n\
    \        cout << block.size();\n        for (int i : block) cout << \" \" << i;\n\
    \        cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - graph/biconnected_components.hpp
  - graph/lowlink.hpp
  isVerificationFile: true
  path: test/yosupo/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2025-01-11 14:37:08+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/biconnected_components.test.cpp
- /verify/test/yosupo/biconnected_components.test.cpp.html
title: test/yosupo/biconnected_components.test.cpp
---
