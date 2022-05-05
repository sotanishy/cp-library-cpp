---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: tree/rerooting.cpp
    title: Rerooting
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B
  bundledCode: "#line 1 \"test/aoj/GRL_5_B.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#line 2 \"tree/rerooting.cpp\"\n#include <utility>\n#include <vector>\n\n\
    template <typename M,\n          typename Cost,\n          typename M::T (*leaf)(),\n\
    \          typename M::T (*apply)(typename M::T, int, int, Cost)>\nclass Rerooting\
    \ {\n    using T = typename M::T;\n\npublic:\n    explicit Rerooting(int n) :\
    \ G(n) {}\n\n    void add_edge(int u, int v, Cost c) {\n        G[u].emplace_back(v,\
    \ c);\n        G[v].emplace_back(u, c);\n    }\n\n    std::vector<T> run() {\n\
    \        dp_sub.resize(G.size(), M::id());\n        dp_all.resize(G.size());\n\
    \        dfs_sub(0, -1);\n        dfs_all(0, -1, M::id());\n        return dp_all;\n\
    \    }\n\nprivate:\n    std::vector<std::vector<std::pair<int, Cost>>> G;\n  \
    \  std::vector<T> dp_sub, dp_all;\n\n    void dfs_sub(int v, int p) {\n      \
    \  bool is_leaf = true;\n        for (auto [c, cost] : G[v]) {\n            if\
    \ (c == p) continue;\n            is_leaf = false;\n            dfs_sub(c, v);\n\
    \            dp_sub[v] = M::op(dp_sub[v], apply(dp_sub[c], v, c, cost));\n   \
    \     }\n        if (is_leaf) dp_sub[v] = leaf();\n    }\n\n    void dfs_all(int\
    \ v, int p, const T& val) {\n        std::vector<T> ds = {val};\n        for (auto\
    \ [c, cost] : G[v]) {\n            if (c == p) continue;\n            ds.push_back(apply(dp_sub[c],\
    \ v, c, cost));\n        }\n        int n = ds.size();\n        std::vector<T>\
    \ head(n + 1, M::id()), tail(n + 1, M::id());\n        for (int i = 0; i < n;\
    \ ++i) head[i+1] = M::op(head[i], ds[i]);\n        for (int i = n - 1; i >= 0;\
    \ --i) tail[i] = M::op(ds[i], tail[i+1]);\n        dp_all[v] = head[n];\n    \
    \    int k = 1;\n        for (auto [c, cost] : G[v]) {\n            if (c == p)\
    \ continue;\n            dfs_all(c, v, apply(M::op(head[k], tail[k+1]), c, v,\
    \ cost));\n            ++k;\n        }\n    }\n};\n#line 4 \"test/aoj/GRL_5_B.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct MaxMonoid {\n   \
    \ using T = int;\n    static T id() { return 0; }\n    static T op(T a, T b) {\n\
    \        return max(a, b);\n    }\n};\nint leaf() { return 0; }\nint apply(int\
    \ x, int, int, int c) { return x + c; }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    Rerooting<MaxMonoid, int, leaf,\
    \ apply> G(n);\n    for (int i = 0; i < n-1; i++) {\n        int s, t, w;\n  \
    \      cin >> s >> t >> w;\n        G.add_edge(s, t, w);\n    }\n    auto ans\
    \ = G.run();\n    for (int i = 0; i < n; ++i) cout << ans[i] << \"\\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B\"\
    \n\n#include \"../../tree/rerooting.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct MaxMonoid {\n    using T = int;\n    static T id() { return 0;\
    \ }\n    static T op(T a, T b) {\n        return max(a, b);\n    }\n};\nint leaf()\
    \ { return 0; }\nint apply(int x, int, int, int c) { return x + c; }\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int n;\n  \
    \  cin >> n;\n    Rerooting<MaxMonoid, int, leaf, apply> G(n);\n    for (int i\
    \ = 0; i < n-1; i++) {\n        int s, t, w;\n        cin >> s >> t >> w;\n  \
    \      G.add_edge(s, t, w);\n    }\n    auto ans = G.run();\n    for (int i =\
    \ 0; i < n; ++i) cout << ans[i] << \"\\n\";\n}\n"
  dependsOn:
  - tree/rerooting.cpp
  isVerificationFile: true
  path: test/aoj/GRL_5_B.test.cpp
  requiredBy: []
  timestamp: '2022-05-05 22:04:46+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_B.test.cpp
- /verify/test/aoj/GRL_5_B.test.cpp.html
title: test/aoj/GRL_5_B.test.cpp
---
