---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/scc.cpp
    title: Strongly Connected Components
  - icon: ':heavy_check_mark:'
    path: graph/twosat.cpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "#line 1 \"test/yosupo/two_sat.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\
    \n\n#line 1 \"graph/twosat.cpp\"\n#include <bits/stdc++.h>\n#line 2 \"graph/scc.cpp\"\
    \n\n/*\n * @brief Strongly Connected Components\n * @docs docs/graph/scc.md\n\
    \ */\nclass SCC {\npublic:\n    SCC() = default;\n    explicit SCC(int n) : G(n),\
    \ G_rev(n), comp(n, -1), visited(n) {}\n\n    void add_edge(int u, int v) {\n\
    \        G[u].push_back(v);\n        G_rev[v].push_back(u);\n    }\n\n    void\
    \ build() {\n        for (int v = 0; v < (int) G.size(); ++v) dfs(v);\n      \
    \  std::reverse(order.begin(), order.end());\n        cnt = 0;\n        for (int\
    \ v : order) if (comp[v] == -1) rdfs(v, cnt++);\n    }\n\n    int operator[](int\
    \ i) const {\n        return comp[i];\n    }\n\n    int count() const noexcept\
    \ {\n        return cnt;\n    }\n\nprivate:\n    std::vector<std::vector<int>>\
    \ G, G_rev;\n    std::vector<int> comp, order;\n    std::vector<bool> visited;\n\
    \    int cnt;\n\n    void dfs(int u) {\n        if (visited[u]) return;\n    \
    \    visited[u] = true;\n        for (int v : G[u]) dfs(v);\n        order.push_back(u);\n\
    \    }\n\n    void rdfs(int u, int c) {\n        if (comp[u] != -1) return;\n\
    \        comp[u] = c;\n        for (int v : G_rev[u]) rdfs(v, c);\n    }\n};\n\
    #line 3 \"graph/twosat.cpp\"\n\n/*\n * @brief 2-SAT\n * @docs docs/graph/twosat.md\n\
    \ */\nclass TwoSat {\npublic:\n    TwoSat() = default;\n    explicit TwoSat(int\
    \ n) : n(n), scc(2 * n), val(n) {}\n\n    void add_clause(int u, bool a, int v,\
    \ bool b) {\n        scc.add_edge(n * a + u, n * (!b) + v);\n        scc.add_edge(n\
    \ * b + v, n * (!a) + u);\n    }\n\n    void solve() {\n        scc.build();\n\
    \        for (int i = 0; i < n; ++i) {\n            if (scc[i] == scc[n + i])\
    \ {\n                satisfiable = false;\n                break;\n          \
    \  }\n            val[i] = scc[i] > scc[n + i];\n        }\n    }\n\n    bool\
    \ is_satisfiable() const noexcept {\n        return satisfiable;\n    }\n\n  \
    \  bool operator[](int i) const {\n        return val[i];\n    }\n\nprivate:\n\
    \    int n;\n    SCC scc;\n    std::vector<bool> val;\n    bool satisfiable =\
    \ true;\n};\n#line 4 \"test/yosupo/two_sat.test.cpp\"\n\nusing namespace std;\n\
    using ll = long long;\n\nint main() {\n    string _p, _cnf;\n    int N, M;\n \
    \   cin >> _p >> _cnf >> N >> M;\n    TwoSat sat(N);\n    for (int i = 0; i <\
    \ M; i++) {\n        int a, b, _c;\n        cin >> a >> b >> _c;\n        sat.add_clause(abs(a)\
    \ - 1, (a > 0), abs(b) - 1, (b > 0));\n    }\n    sat.solve();\n    if (sat.is_satisfiable())\
    \ {\n        cout << \"s SATISFIABLE\\nv\";\n        for (int i = 0; i < N; i++)\
    \ {\n            cout << \" \" << (sat[i] ? 1 : -1) * (i + 1);\n        }\n  \
    \      cout << \" 0\\n\";\n    } else {\n        cout << \"s UNSATISFIABLE\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../../graph/twosat.cpp\"\n\nusing namespace std;\nusing ll = long long;\n\nint\
    \ main() {\n    string _p, _cnf;\n    int N, M;\n    cin >> _p >> _cnf >> N >>\
    \ M;\n    TwoSat sat(N);\n    for (int i = 0; i < M; i++) {\n        int a, b,\
    \ _c;\n        cin >> a >> b >> _c;\n        sat.add_clause(abs(a) - 1, (a > 0),\
    \ abs(b) - 1, (b > 0));\n    }\n    sat.solve();\n    if (sat.is_satisfiable())\
    \ {\n        cout << \"s SATISFIABLE\\nv\";\n        for (int i = 0; i < N; i++)\
    \ {\n            cout << \" \" << (sat[i] ? 1 : -1) * (i + 1);\n        }\n  \
    \      cout << \" 0\\n\";\n    } else {\n        cout << \"s UNSATISFIABLE\\n\"\
    ;\n    }\n}\n"
  dependsOn:
  - graph/twosat.cpp
  - graph/scc.cpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 00:47:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
