---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/scc.hpp
    title: Strongly Connected Components
  - icon: ':x:'
    path: sat/twosat.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 2 \"sat/twosat.hpp\"\n#include <vector>\n\n#line 2 \"graph/scc.hpp\"\
    \n#include <algorithm>\n#include <ranges>\n#line 5 \"graph/scc.hpp\"\n\nstd::vector<int>\
    \ scc(const std::vector<std::vector<int>>& G) {\n    const int n = G.size();\n\
    \    std::vector<std::vector<int>> G_rev(n);\n    for (int u = 0; u < n; ++u)\
    \ {\n        for (int v : G[u]) G_rev[v].push_back(u);\n    }\n    std::vector<int>\
    \ comp(n, -1), order(n);\n    std::vector<bool> visited(n);\n\n    auto dfs =\
    \ [&](const auto& dfs, int u) -> void {\n        if (visited[u]) return;\n   \
    \     visited[u] = true;\n        for (int v : G[u]) dfs(dfs, v);\n        order.push_back(u);\n\
    \    };\n\n    for (int v = 0; v < n; ++v) dfs(dfs, v);\n    int c = 0;\n\n  \
    \  auto rdfs = [&](const auto& rdfs, int u, int c) -> void {\n        if (comp[u]\
    \ != -1) return;\n        comp[u] = c;\n        for (int v : G_rev[u]) rdfs(rdfs,\
    \ v, c);\n    };\n\n    for (int v : order | std::views::reverse) {\n        if\
    \ (comp[v] == -1) rdfs(rdfs, v, c++);\n    }\n    return comp;\n}\n\nstd::vector<std::vector<int>>\
    \ contract(const std::vector<std::vector<int>>& G,\n                         \
    \              const std::vector<int>& comp) {\n    const int n = *std::ranges::max_element(comp)\
    \ + 1;\n    std::vector<std::vector<int>> G2(n);\n    for (int i = 0; i < (int)G.size();\
    \ ++i) {\n        for (int j : G[i]) {\n            if (comp[i] != comp[j]) {\n\
    \                G2[comp[i]].push_back(comp[j]);\n            }\n        }\n \
    \   }\n    for (int i = 0; i < n; ++i) {\n        std::ranges::sort(G2[i]);\n\
    \        G2[i].erase(std::ranges::unique(G2[i]).begin(), G2[i].end());\n    }\n\
    \    return G2;\n}\n#line 5 \"sat/twosat.hpp\"\n\nstd::vector<bool> two_sat(\n\
    \    int n, const std::vector<std::tuple<int, bool, int, bool>>& clauses) {\n\
    \    std::vector<std::vector<int>> G(2 * n);\n    std::vector<bool> val(n);\n\n\
    \    for (auto& [i, f, j, g] : clauses) {\n        G[n * f + i].push_back(n *\
    \ (!g) + j);\n        G[n * g + j].push_back(n * (!f) + i);\n    }\n\n    auto\
    \ comp = scc(G);\n    for (int i = 0; i < n; ++i) {\n        if (comp[i] == comp[n\
    \ + i]) {\n            // not satisfiable\n            return {};\n        }\n\
    \        val[i] = comp[i] > comp[n + i];\n    }\n    return val;\n}\n#line 4 \"\
    test/yosupo/two_sat.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    using ll = long long;\n\nint main() {\n    string _p, _cnf;\n    int N, M;\n \
    \   cin >> _p >> _cnf >> N >> M;\n    vector<tuple<int, bool, int, bool>> clauses;\n\
    \    for (int i = 0; i < M; i++) {\n        int a, b, _c;\n        cin >> a >>\
    \ b >> _c;\n        clauses.push_back({abs(a) - 1, (a > 0), abs(b) - 1, (b > 0)});\n\
    \    }\n    auto ans = two_sat(N, clauses);\n    if (!ans.empty()) {\n       \
    \ cout << \"s SATISFIABLE\\nv\";\n        for (int i = 0; i < N; i++) {\n    \
    \        cout << \" \" << (ans[i] ? 1 : -1) * (i + 1);\n        }\n        cout\
    \ << \" 0\\n\";\n    } else {\n        cout << \"s UNSATISFIABLE\\n\";\n    }\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../../sat/twosat.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\nusing\
    \ ll = long long;\n\nint main() {\n    string _p, _cnf;\n    int N, M;\n    cin\
    \ >> _p >> _cnf >> N >> M;\n    vector<tuple<int, bool, int, bool>> clauses;\n\
    \    for (int i = 0; i < M; i++) {\n        int a, b, _c;\n        cin >> a >>\
    \ b >> _c;\n        clauses.push_back({abs(a) - 1, (a > 0), abs(b) - 1, (b > 0)});\n\
    \    }\n    auto ans = two_sat(N, clauses);\n    if (!ans.empty()) {\n       \
    \ cout << \"s SATISFIABLE\\nv\";\n        for (int i = 0; i < N; i++) {\n    \
    \        cout << \" \" << (ans[i] ? 1 : -1) * (i + 1);\n        }\n        cout\
    \ << \" 0\\n\";\n    } else {\n        cout << \"s UNSATISFIABLE\\n\";\n    }\n\
    }\n"
  dependsOn:
  - sat/twosat.hpp
  - graph/scc.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
