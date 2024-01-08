---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: graph/dominator_tree.hpp
    title: Dominator Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/dominatortree
    links:
    - https://judge.yosupo.jp/problem/dominatortree
  bundledCode: "#line 1 \"test/yosupo/dominatortree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/dominatortree\"\n\n#line 2 \"graph/dominator_tree.hpp\"\
    \n#include <algorithm>\n#include <numeric>\n#include <vector>\n\nstd::vector<int>\
    \ dominator_tree(const std::vector<std::vector<int>>& G, int s) {\n    const int\
    \ n = G.size();\n\n    // label nodes with the arrival times of a dfs\n    std::vector<int>\
    \ sdom(n, -1), par(n, -1), vs;\n    vs.reserve(n);\n    int k = 0;\n\n    auto\
    \ dfs = [&](auto& dfs, int v) -> void {\n        sdom[v] = k++;\n        vs.push_back(v);\n\
    \        for (int c : G[v]) {\n            if (sdom[c] == -1) {\n            \
    \    par[c] = v;\n                dfs(dfs, c);\n            }\n        }\n   \
    \ };\n\n    dfs(dfs, s);\n\n    std::vector<std::vector<int>> G_rev(n);\n    for\
    \ (int u = 0; u < n; ++u) {\n        if (sdom[u] == -1) continue;\n        for\
    \ (int v : G[u]) {\n            G_rev[v].push_back(u);\n        }\n    }\n\n \
    \   // union find with path compression\n    std::vector<int> dsu(n), val(n);\n\
    \    std::iota(dsu.begin(), dsu.end(), 0);\n    std::iota(val.begin(), val.end(),\
    \ 0);\n\n    auto unite = [&](int u, int v) {  // make u the parent of v\n   \
    \     dsu[v] = u;\n    };\n\n    auto find = [&](auto& find, int v) -> int {\n\
    \        if (v == dsu[v]) return v;\n        int r = find(find, dsu[v]);\n   \
    \     if (sdom[val[v]] > sdom[val[dsu[v]]]) {\n            val[v] = val[dsu[v]];\n\
    \        }\n        return dsu[v] = r;\n    };\n\n    auto eval = [&](int v) {\
    \  // return the ancestor of v with minimum sdom\n        find(find, v);\n   \
    \     return val[v];\n    };\n\n    // calculate sdom\n    std::vector<int> us(n);\n\
    \    std::vector<std::vector<int>> bucket(n);\n    for (int i = k - 1; i > 0;\
    \ --i) {\n        int w = vs[i];\n        for (int v : G_rev[w]) {\n         \
    \   sdom[w] = std::min(sdom[w], sdom[eval(v)]);\n        }\n        bucket[vs[sdom[w]]].push_back(w);\n\
    \        for (int v : bucket[par[w]]) {\n            us[v] = eval(v);\n      \
    \  }\n        bucket[par[w]].clear();\n        unite(par[w], w);\n    }\n\n  \
    \  // calculate idom\n    std::vector<int> idom(n, -1);\n    idom[s] = sdom[s];\n\
    \    for (int i = 1; i < k; ++i) {\n        int w = vs[i], u = us[w];\n      \
    \  idom[w] = (sdom[w] == sdom[u] ? sdom[w] : idom[u]);\n    }\n    std::ranges::transform(idom,\
    \ idom.begin(), [&](int i) { return vs[i]; });\n    return idom;\n}\n#line 4 \"\
    test/yosupo/dominatortree.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M, S;\n    cin >> N >> M >> S;\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < M; ++i) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        G[a].push_back(b);\n    }\n    auto dom = dominator_tree(G,\
    \ S);\n    for (int i = 0; i < N; ++i) cout << dom[i] << (i < N-1 ? \" \" : \"\
    \\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dominatortree\"\n\n#include\
    \ \"../../graph/dominator_tree.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M, S;\n    cin >> N >> M >> S;\n    vector<vector<int>>\
    \ G(N);\n    for (int i = 0; i < M; ++i) {\n        int a, b;\n        cin >>\
    \ a >> b;\n        G[a].push_back(b);\n    }\n    auto dom = dominator_tree(G,\
    \ S);\n    for (int i = 0; i < N; ++i) cout << dom[i] << (i < N-1 ? \" \" : \"\
    \\n\");\n}"
  dependsOn:
  - graph/dominator_tree.hpp
  isVerificationFile: true
  path: test/yosupo/dominatortree.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/dominatortree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/dominatortree.test.cpp
- /verify/test/yosupo/dominatortree.test.cpp.html
title: test/yosupo/dominatortree.test.cpp
---
