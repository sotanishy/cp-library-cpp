---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/biconnected_components.cpp
    title: Biconnected Components
  - icon: ':question:'
    path: graph/lowlink.cpp
    title: Lowlink
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/biconnected_components
    links:
    - https://judge.yosupo.jp/problem/biconnected_components
  bundledCode: "#line 1 \"test/yosupo/biconnected_components.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/biconnected_components\"\n\n#line 2 \"graph/biconnected_components.cpp\"\
    \n#include <stack>\n#include <utility>\n#include <vector>\n#line 2 \"graph/lowlink.cpp\"\
    \n#include <algorithm>\n#line 5 \"graph/lowlink.cpp\"\n\nclass Lowlink {\npublic:\n\
    \    Lowlink() = default;\n    explicit Lowlink(const std::vector<std::vector<int>>&\
    \ G) : G(G), ord(G.size(), -1), low(G.size()) {\n        for (int i = 0; i < (int)\
    \ G.size(); ++i) {\n            if (ord[i] == -1) dfs(i, -1);\n        }\n   \
    \ }\n\n    std::vector<std::pair<int, int>> get_bridges() const {\n        return\
    \ bridge;\n    }\n\n    std::vector<int> get_articulation_points() const {\n \
    \       return articulation;\n    }\n\n    bool is_bridge(int u, int v) const\
    \ {\n        if (ord[u] > ord[v]) std::swap(u, v);\n        return ord[u] < low[v];\n\
    \    }\n\nprotected:\n    std::vector<std::vector<int>> G;\n    std::vector<int>\
    \ ord, low;\n    std::vector<std::pair<int, int>> bridge;\n    std::vector<int>\
    \ articulation;\n\nprivate:\n    int k = 0;\n\n    void dfs(int v, int p) {\n\
    \        ord[v] = k++;\n        low[v] = ord[v];\n        bool is_articulation\
    \ = false, checked = false;\n        int cnt = 0;\n        for (int c : G[v])\
    \ {\n            if (c == p && !checked) {\n                checked = true;\n\
    \                continue;\n            }\n            if (ord[c] == -1) {\n \
    \               ++cnt;\n                dfs(c, v);\n                low[v] = std::min(low[v],\
    \ low[c]);\n                if (p != -1 && ord[v] <= low[c]) is_articulation =\
    \ true;\n                if (ord[v] < low[c]) bridge.push_back(std::minmax(v,\
    \ c));\n            } else {\n                low[v] = std::min(low[v], ord[c]);\n\
    \            }\n        }\n        if (p == -1 && cnt > 1) is_articulation = true;\n\
    \        if (is_articulation) articulation.push_back(v);\n    }\n};\n#line 6 \"\
    graph/biconnected_components.cpp\"\n\nclass BiconnectedComponents : Lowlink {\n\
    public:\n    BiconnectedComponents() = default;\n    explicit BiconnectedComponents(const\
    \ std::vector<std::vector<int>>& G) : Lowlink(G), G(G), used(G.size()) {\n   \
    \     for (int v = 0; v < (int) G.size(); ++v) {\n            if (!used[v]) dfs(v,\
    \ -1);\n        }\n    }\n\n    std::vector<std::vector<std::pair<int, int>>>\
    \ get_biconnected_components() const {\n        return bc;\n    }\n\nprivate:\n\
    \    std::vector<std::vector<int>> G;\n    std::vector<bool> used;\n    std::stack<std::pair<int,\
    \ int>> st;\n    std::vector<std::vector<std::pair<int, int>>> bc;\n\n    void\
    \ dfs(int v, int p) {\n        used[v] = true;\n        for (int c : G[v]) {\n\
    \            if (c == p) continue;\n            if (!used[c] || ord[c] < ord[v])\
    \ {\n                st.emplace(v, c);\n            }\n            if (!used[c])\
    \ {\n                dfs(c, v);\n                if (ord[v] <= low[c]) {  // v\
    \ is an articulation point\n                    bc.emplace_back();\n         \
    \           while (true) {\n                        auto e = st.top();\n     \
    \                   st.pop();\n                        bc.back().push_back(e);\n\
    \                        if (e.first == v) {\n                            break;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n        }\n    }\n};\n#line 4 \"test/yosupo/biconnected_components.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<vector<int>> G(N);\n    map<pair<int,\
    \ int>, vector<int>> id;\n    for (int i = 0; i < M; ++i) {\n        int a, b;\n\
    \        cin >> a >> b;\n        if (!id.count(minmax(a, b))) {\n            G[a].push_back(b);\n\
    \            G[b].push_back(a);\n        }\n        id[minmax(a, b)].push_back(i);\n\
    \    }\n    BiconnectedComponents bc(G);\n    auto comps = bc.get_biconnected_components();\n\
    \    cout << comps.size() << endl;\n    for (auto& comp : comps) {\n        vector<int>\
    \ c;\n        for (auto [u, v] : comp) {\n            for (int i : id[minmax(u,\
    \ v)]) c.push_back(i);\n        }\n        cout << c.size();\n        for (int\
    \ i : c) cout << \" \" << i;\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/biconnected_components\"\
    \n\n#include \"../../graph/biconnected_components.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>>\
    \ G(N);\n    map<pair<int, int>, vector<int>> id;\n    for (int i = 0; i < M;\
    \ ++i) {\n        int a, b;\n        cin >> a >> b;\n        if (!id.count(minmax(a,\
    \ b))) {\n            G[a].push_back(b);\n            G[b].push_back(a);\n   \
    \     }\n        id[minmax(a, b)].push_back(i);\n    }\n    BiconnectedComponents\
    \ bc(G);\n    auto comps = bc.get_biconnected_components();\n    cout << comps.size()\
    \ << endl;\n    for (auto& comp : comps) {\n        vector<int> c;\n        for\
    \ (auto [u, v] : comp) {\n            for (int i : id[minmax(u, v)]) c.push_back(i);\n\
    \        }\n        cout << c.size();\n        for (int i : c) cout << \" \" <<\
    \ i;\n        cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - graph/biconnected_components.cpp
  - graph/lowlink.cpp
  isVerificationFile: true
  path: test/yosupo/biconnected_components.test.cpp
  requiredBy: []
  timestamp: '2022-03-06 21:25:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/biconnected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/biconnected_components.test.cpp
- /verify/test/yosupo/biconnected_components.test.cpp.html
title: test/yosupo/biconnected_components.test.cpp
---
