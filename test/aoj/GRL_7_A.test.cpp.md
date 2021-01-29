---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: flow/bipartite_matching.cpp
    title: Bipartite Matching
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A
  bundledCode: "#line 1 \"test/aoj/GRL_7_A.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#line 2 \"flow/bipartite_matching.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \nclass BipartiteMatching {\npublic:\n    BipartiteMatching() = default;\n   \
    \ explicit BipartiteMatching(int n) : G(n), used(n), match(n) {}\n\n    void add_edge(int\
    \ u, int v) {\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\
    \n    int bipartite_matching() {\n        int res = 0;\n        std::fill(match.begin(),\
    \ match.end(), -1);\n        for (int v = 0; v < (int) G.size(); ++v) {\n    \
    \        if (match[v] == -1) {\n                std::fill(used.begin(), used.end(),\
    \ false);\n                if (dfs(v)) ++res;\n            }\n        }\n    \
    \    return res;\n    }\n\n    std::vector<std::pair<int, int>> get_edges() {\n\
    \        std::vector<std::pair<int, int>> ret;\n        for (int i = 0; i < (int)\
    \ G.size(); ++i) {\n            if (i < match[i]) ret.emplace_back(i, match[i]);\n\
    \        }\n        return ret;\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<bool> used;\n    std::vector<int> match;\n\n    bool dfs(int\
    \ u) {\n        used[u] = true;\n        for (int v : G[u]) {\n            int\
    \ w = match[v];\n            if (w == -1 || (!used[w] && dfs(w))) {\n        \
    \        match[u] = v;\n                match[v] = u;\n                return\
    \ true;\n            }\n        }\n        return false;\n    }\n};\n#line 4 \"\
    test/aoj/GRL_7_A.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int X, Y, E;\n    cin >> X >> Y >> E;\n    BipartiteMatching bm(X + Y);\n  \
    \  for (int i = 0; i < E; i++) {\n        int x, y;\n        cin >> x >> y;\n\
    \        bm.add_edge(x, X + y);\n    }\n    cout << bm.bipartite_matching() <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A\"\
    \n\n#include \"../../flow/bipartite_matching.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int X, Y, E;\n    cin >> X >> Y >> E;\n    BipartiteMatching\
    \ bm(X + Y);\n    for (int i = 0; i < E; i++) {\n        int x, y;\n        cin\
    \ >> x >> y;\n        bm.add_edge(x, X + y);\n    }\n    cout << bm.bipartite_matching()\
    \ << endl;\n}"
  dependsOn:
  - flow/bipartite_matching.cpp
  isVerificationFile: true
  path: test/aoj/GRL_7_A.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_7_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_7_A.test.cpp
- /verify/test/aoj/GRL_7_A.test.cpp.html
title: test/aoj/GRL_7_A.test.cpp
---
