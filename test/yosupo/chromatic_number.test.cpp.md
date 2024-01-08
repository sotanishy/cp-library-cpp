---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/chromatic_number.hpp
    title: Chromatic Number
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chromatic_number
    links:
    - https://judge.yosupo.jp/problem/chromatic_number
  bundledCode: "#line 1 \"test/yosupo/chromatic_number.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n#line 2 \"graph/chromatic_number.hpp\"\
    \n#include <bit>\n#include <vector>\n\nint chromatic_number(std::vector<std::vector<bool>>&\
    \ G) {\n    const int n = G.size();\n    std::vector<int> neighbor(n);\n    for\
    \ (int i = 0; i < (int)G.size(); ++i) {\n        for (int j = 0; j < (int)G.size();\
    \ ++j) {\n            if (G[i][j]) neighbor[i] |= 1 << j;\n        }\n    }\n\
    \    // number of subsets of S that are independent\n    std::vector<int> ind(1\
    \ << n);\n    ind[0] = 1;\n    for (int S = 1; S < (1 << n); ++S) {\n        int\
    \ v = std::countr_zero((unsigned int)S);\n        // (not containing v) + (containing\
    \ v)\n        ind[S] = ind[S ^ (1 << v)] + ind[(S ^ (1 << v)) & ~neighbor[v]];\n\
    \    }\n    // number of ways to choose k subsets of S that are independent\n\
    \    auto f = ind;\n    for (int k = 1;; ++k) {\n        // numer of ways to choose\
    \ k subsets of S so that they cover S\n        int g = 0;\n        for (int S\
    \ = 0; S < (1 << n); ++S) {\n            g += (std::popcount((unsigned int)S)\
    \ & 1 ? -1 : 1) * f[S];\n        }\n        if (g) return k;\n        for (int\
    \ S = 1; S < (1 << n); ++S) {\n            f[S] *= ind[S];\n        }\n    }\n\
    }\n#line 4 \"test/yosupo/chromatic_number.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<vector<bool>>\
    \ G(N, vector<bool>(N));\n    for (int i = 0; i < M; ++i) {\n        int u, v;\n\
    \        cin >> u >> v;\n        G[u][v] = G[v][u] = true;\n    }\n    cout <<\
    \ chromatic_number(G) << endl;\n}\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/chromatic_number\"\n\n\
    #include \"../../graph/chromatic_number.hpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M;\n    cin >> N >> M;\n    vector<vector<bool>>\
    \ G(N, vector<bool>(N));\n    for (int i = 0; i < M; ++i) {\n        int u, v;\n\
    \        cin >> u >> v;\n        G[u][v] = G[v][u] = true;\n    }\n    cout <<\
    \ chromatic_number(G) << endl;\n}\n\n"
  dependsOn:
  - graph/chromatic_number.hpp
  isVerificationFile: true
  path: test/yosupo/chromatic_number.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/chromatic_number.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/chromatic_number.test.cpp
- /verify/test/yosupo/chromatic_number.test.cpp.html
title: test/yosupo/chromatic_number.test.cpp
---
