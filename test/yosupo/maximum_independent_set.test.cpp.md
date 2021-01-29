---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/maximum_independent_set.cpp
    title: Maximum Independent Set
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/maximum_independent_set
    links:
    - https://judge.yosupo.jp/problem/maximum_independent_set
  bundledCode: "#line 1 \"test/yosupo/maximum_independent_set.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\n\n#line\
    \ 2 \"graph/maximum_independent_set.cpp\"\n#include <vector>\n\nstd::vector<int>\
    \ maximum_independent_set(const std::vector<std::vector<int>>& G) {\n    int n\
    \ = G.size();\n    std::vector<bool> used(n), ans(n);\n    std::vector<int> deg(n),\
    \ dead(n);\n    for (int i = 0; i < n; ++i) deg[i] = G[i].size();\n    int res\
    \ = 0, cnt = 0, alive = n;\n\n    auto dfs = [&](const auto& self) {\n       \
    \ if (cnt + alive <= res) return;\n\n        int v = -1;\n        for (int i =\
    \ 0; i < n; ++i) {\n            if (used[i] || dead[i]) continue;\n          \
    \  if (deg[i] <= 1) {\n                v = i;\n                break;\n      \
    \      }\n            if (v < 0 || deg[v] < deg[i]) v = i;\n        }\n      \
    \  if (v < 0) return;\n\n        // not use\n        if (deg[v] != 1) {\n    \
    \        dead[v] = true;\n            --alive;\n            for (int u : G[v])\
    \ --deg[u];\n\n            self(self);\n\n            dead[v] = false;\n     \
    \       ++alive;\n            for (int u : G[v]) ++deg[u];\n        }\n\n    \
    \    // use\n        used[v] = true;\n        --alive;\n        for (int u : G[v])\
    \ {\n            if (!dead[u]) --alive;\n            ++dead[u];\n        }\n \
    \       ++cnt;\n        if (res < cnt) {\n            ans = used;\n          \
    \  res = cnt;\n        }\n\n        self(self);\n\n        used[v] = false;\n\
    \        ++alive;\n        for (int u : G[v]) {\n            --dead[u];\n    \
    \        if (!dead[u]) ++alive;\n        }\n        --cnt;\n    };\n\n    dfs(dfs);\n\
    \n    std::vector<int> ret;\n    for (int i = 0; i < n; ++i) {\n        if (ans[i])\
    \ ret.push_back(i);\n    }\n    return ret;\n}\n#line 4 \"test/yosupo/maximum_independent_set.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < M; ++i) {\n        int u, v;\n        cin >>\
    \ u >> v;\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n   \
    \ auto ans = maximum_independent_set(G);\n    cout << ans.size() << endl;\n  \
    \  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << (i < ans.size() - 1\
    \ ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/maximum_independent_set\"\
    \n\n#include \"../../graph/maximum_independent_set.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < M; ++i) {\n        int u, v;\n        cin >>\
    \ u >> v;\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n   \
    \ auto ans = maximum_independent_set(G);\n    cout << ans.size() << endl;\n  \
    \  for (int i = 0; i < ans.size(); ++i) cout << ans[i] << (i < ans.size() - 1\
    \ ? \" \" : \"\\n\");\n}\n"
  dependsOn:
  - graph/maximum_independent_set.cpp
  isVerificationFile: true
  path: test/yosupo/maximum_independent_set.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 23:34:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/maximum_independent_set.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/maximum_independent_set.test.cpp
- /verify/test/yosupo/maximum_independent_set.test.cpp.html
title: test/yosupo/maximum_independent_set.test.cpp
---
