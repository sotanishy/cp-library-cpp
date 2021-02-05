---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
    title: Diameter of a Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "#line 1 \"test/yosupo/tree_diameter.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 2 \"graph/edge.cpp\"\n\
    \ntemplate <typename T>\nstruct Edge {\n    int from, to;\n    T weight;\n   \
    \ Edge(int to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int from,\
    \ int to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 2 \"tree/tree_diameter.cpp\"\
    \n#include <algorithm>\n#include <utility>\n#include <vector>\n#line 6 \"tree/tree_diameter.cpp\"\
    \n\nstd::pair<int, std::vector<int>> tree_diameter(const std::vector<std::vector<int>>&\
    \ G) {\n    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs,\
    \ int v, int p) -> std::pair<int, int> {\n        std::pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto weight = dfs(dfs, c, v);\n            ++weight.first;\n            if (ret\
    \ < weight) {\n                ret = weight;\n                to[v] = c;\n   \
    \         }\n        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0,\
    \ -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n   \
    \ int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>> tree_diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<int> to(G.size());\n\
    \n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T, int> {\n \
    \       std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n       \
    \     if (e.to == p) continue;\n            auto weight = dfs(dfs, e.to, v);\n\
    \            weight.first += e.weight;\n            if (ret < weight) {\n    \
    \            ret = weight;\n                to[v] = e.to;\n            }\n   \
    \     }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto\
    \ q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n#line 5 \"test/yosupo/tree_diameter.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    template <typename T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n\
    \    for (int i = 0; i < (int) v.size(); ++i) cout << v[i] << \" \";\n    return\
    \ os;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N;\n    cin >> N;\n    vector<vector<Edge<ll>>> G(N);\n    for (int\
    \ i = 0; i < N - 1; ++i) {\n        int a, b, c;\n        cin >> a >> b >> c;\n\
    \        G[a].push_back({b, c});\n        G[b].push_back({a, c});\n    }\n   \
    \ auto ans = tree_diameter(G);\n    cout << ans.first << \" \" << ans.second.size()\
    \ << endl;\n    cout << ans.second << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../graph/edge.cpp\"\n#include \"../../tree/tree_diameter.cpp\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\ntemplate <typename\
    \ T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i =\
    \ 0; i < (int) v.size(); ++i) cout << v[i] << \" \";\n    return os;\n}\n\nint\
    \ main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n \
    \   int N;\n    cin >> N;\n    vector<vector<Edge<ll>>> G(N);\n    for (int i\
    \ = 0; i < N - 1; ++i) {\n        int a, b, c;\n        cin >> a >> b >> c;\n\
    \        G[a].push_back({b, c});\n        G[b].push_back({a, c});\n    }\n   \
    \ auto ans = tree_diameter(G);\n    cout << ans.first << \" \" << ans.second.size()\
    \ << endl;\n    cout << ans.second << endl;\n}"
  dependsOn:
  - graph/edge.cpp
  - tree/tree_diameter.cpp
  isVerificationFile: true
  path: test/yosupo/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2021-02-05 23:21:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_diameter.test.cpp
- /verify/test/yosupo/tree_diameter.test.cpp.html
title: test/yosupo/tree_diameter.test.cpp
---
