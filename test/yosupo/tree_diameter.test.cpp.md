---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.hpp
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
    https://judge.yosupo.jp/problem/tree_diameter\"\n\n#line 2 \"tree/tree_diameter.hpp\"\
    \n#include <algorithm>\n#include <utility>\n#include <vector>\n\nstd::pair<int,\
    \ std::vector<int>> tree_diameter(\n    const std::vector<std::vector<int>>& G)\
    \ {\n    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs,\
    \ int v, int p) -> std::pair<int, int> {\n        std::pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto weight = dfs(dfs, c, v);\n            ++weight.first;\n            if (ret\
    \ < weight) {\n                ret = weight;\n                to[v] = c;\n   \
    \         }\n        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0,\
    \ -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n   \
    \ int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>> tree_diameter(\n  \
    \  const std::vector<std::vector<std::pair<int, T>>>& G) {\n    std::vector<int>\
    \ to(G.size());\n\n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T,\
    \ int> {\n        std::pair<T, int> ret(0, v);\n        for (auto& [u, w] : G[v])\
    \ {\n            if (u == p) continue;\n            auto weight = dfs(dfs, u,\
    \ v);\n            weight.first += w;\n            if (ret < weight) {\n     \
    \           ret = weight;\n                to[v] = u;\n            }\n       \
    \ }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto q\
    \ = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n#line 4 \"test/yosupo/tree_diameter.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    template <typename T>\nostream& operator<<(ostream& os, const vector<T>& v) {\n\
    \    for (int i = 0; i < (int)v.size(); ++i) cout << v[i] << \" \";\n    return\
    \ os;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N;\n    cin >> N;\n    vector<vector<pair<int, ll>>> G(N);\n    for\
    \ (int i = 0; i < N - 1; ++i) {\n        int a, b, c;\n        cin >> a >> b >>\
    \ c;\n        G[a].push_back({b, c});\n        G[b].push_back({a, c});\n    }\n\
    \    auto ans = tree_diameter(G);\n    cout << ans.first << \" \" << ans.second.size()\
    \ << endl;\n    cout << ans.second << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ \"../../tree/tree_diameter.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\ntemplate <typename T>\nostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); ++i) cout\
    \ << v[i] << \" \";\n    return os;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N;\n    cin >> N;\n    vector<vector<pair<int,\
    \ ll>>> G(N);\n    for (int i = 0; i < N - 1; ++i) {\n        int a, b, c;\n \
    \       cin >> a >> b >> c;\n        G[a].push_back({b, c});\n        G[b].push_back({a,\
    \ c});\n    }\n    auto ans = tree_diameter(G);\n    cout << ans.first << \" \"\
    \ << ans.second.size() << endl;\n    cout << ans.second << endl;\n}"
  dependsOn:
  - tree/tree_diameter.hpp
  isVerificationFile: true
  path: test/yosupo/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_diameter.test.cpp
- /verify/test/yosupo/tree_diameter.test.cpp.html
title: test/yosupo/tree_diameter.test.cpp
---
