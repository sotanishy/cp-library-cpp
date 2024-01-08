---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/partition_refinement.hpp
    title: Partition Refinement
  - icon: ':heavy_check_mark:'
    path: graph/chordal_graph_recognition.hpp
    title: Chordal Graph Recognition
  - icon: ':heavy_check_mark:'
    path: graph/lex_bfs.hpp
    title: Lexicographic BFS
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/chordal_graph_recognition.test.cpp
    links:
    - https://judge.yosupo.jp/problem/chordal_graph_recognition.test.cpp
  bundledCode: "#line 1 \"test/yosupo/chordal_graph_recognition.test.cpp\"\n#define\
    \ PROBLEM \\\n    \"https://judge.yosupo.jp/problem/chordal_graph_recognition.test.cpp\"\
    \n\n#line 2 \"graph/chordal_graph_recognition.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <set>\n#include <utility>\n#include <vector>\n\
    \n#line 4 \"graph/lex_bfs.hpp\"\n\n#line 4 \"data-structure/partition_refinement.hpp\"\
    \n#include <map>\n#line 7 \"data-structure/partition_refinement.hpp\"\n\nclass\
    \ PartitionRefinement {\n   public:\n    PartitionRefinement() = default;\n  \
    \  explicit PartitionRefinement(int n) : sets(1), cls(n, 0) {\n        for (int\
    \ i = 0; i < n; ++i) sets[0].insert(i);\n    }\n\n    int find(int x) const {\
    \ return cls[x]; }\n\n    bool same(int x, int y) const {\n        int cx = find(x),\
    \ cy = find(y);\n        return cx != -1 && cy != -1 && cx == cy;\n    }\n\n \
    \   bool contains(int x) const { return cls[x] != -1; }\n\n    void erase(int\
    \ x) {\n        if (contains(x)) {\n            sets[cls[x]].erase(x);\n     \
    \       cls[x] = -1;\n        }\n    }\n\n    int size(int i) const { return sets[i].size();\
    \ }\n\n    int member(int i) const {\n        assert(0 <= i && i < (int)sets.size());\n\
    \        return *sets[i].begin();\n    }\n\n    std::vector<int> members(int i)\
    \ const {\n        assert(0 <= i && i < (int)sets.size());\n        return std::vector<int>(sets[i].begin(),\
    \ sets[i].end());\n    }\n\n    std::vector<std::pair<int, int>> refine(const\
    \ std::vector<int>& pivot) {\n        std::map<int, std::vector<int>> split;\n\
    \        for (auto x : pivot) {\n            if (!contains(x)) continue;\n   \
    \         int i = cls[x];\n            split[i].push_back(x);\n            sets[i].erase(x);\n\
    \        }\n        std::vector<std::pair<int, int>> updated;\n        for (auto&\
    \ [i, s] : split) {\n            int ni = sets.size();\n            sets.emplace_back(s.begin(),\
    \ s.end());\n            if (sets[i].size() < sets[ni].size()) {\n           \
    \     std::swap(sets[i], sets[ni]);\n            }\n            if (sets[ni].empty())\
    \ {\n                sets.pop_back();\n                continue;\n           \
    \ }\n            for (auto x : sets[ni]) {\n                cls[x] = ni;\n   \
    \         }\n            updated.push_back({i, ni});\n        }\n        return\
    \ updated;\n    }\n\n   private:\n    std::vector<std::set<int>> sets;\n    std::vector<int>\
    \ cls;\n};\n#line 6 \"graph/lex_bfs.hpp\"\n\nstd::vector<int> lex_bfs(const std::vector<std::vector<int>>&\
    \ G) {\n    const int n = G.size();\n    PartitionRefinement pr(n);\n    std::vector<int>\
    \ prv(1, -1), nxt(1, -1);\n    std::vector<int> ord;\n    int k = 0;\n    for\
    \ (int i = 0; i < n; ++i) {\n        while (pr.size(k) == 0) {\n            k\
    \ = nxt[k];\n        }\n        int x = pr.member(k);\n        ord.push_back(x);\n\
    \        pr.erase(x);\n        std::vector<int> pivot;\n        std::set<int>\
    \ neighbor;\n        for (int y : G[x]) {\n            if (pr.contains(y)) {\n\
    \                pivot.push_back(y);\n                neighbor.insert(y);\n  \
    \          }\n        }\n        for (auto [s, t] : pr.refine(pivot)) {\n    \
    \        if ((int)prv.size() <= t) {\n                prv.resize(t + 1, -1);\n\
    \                nxt.resize(t + 1, -1);\n            }\n            if (neighbor.contains(pr.member(s)))\
    \ {\n                if (nxt[s] >= 0) prv[nxt[s]] = t;\n                nxt[t]\
    \ = nxt[s];\n                prv[t] = s;\n                nxt[s] = t;\n      \
    \      } else {\n                if (prv[s] >= 0) nxt[prv[s]] = t;\n         \
    \       prv[t] = prv[s];\n                prv[s] = t;\n                nxt[t]\
    \ = s;\n            }\n        }\n        if (prv[k] != -1) k = prv[k];\n    }\n\
    \    return ord;\n}\n#line 10 \"graph/chordal_graph_recognition.hpp\"\n\n// if\
    \ G is chordal, return a perfect elimination ordering\n// otherwise return an\
    \ induced cycle of length >= 4\nstd::pair<bool, std::vector<int>> recognize_chordal_graph(\n\
    \    const std::vector<std::vector<int>>& G) {\n    const int n = G.size();\n\
    \    std::vector<std::set<int>> st(n);\n    for (int x = 0; x < n; ++x) {\n  \
    \      for (int y : G[x]) st[x].insert(y);\n    }\n\n    auto ord = lex_bfs(G);\n\
    \    std::ranges::reverse(ord);\n    std::vector<int> idx(n, -1);\n    for (int\
    \ x = 0; x < n; ++x) idx[ord[x]] = x;\n\n    // check if ord is a perfect elimination\
    \ ordering\n    for (int i = n - 1; i >= 0; --i) {\n        int x = ord[i];\n\n\
    \        // find the first neighbor z of x that appears after x\n        std::pair<int,\
    \ int> neighbor(n, -1);\n        for (int y : G[x]) {\n            if (idx[y]\
    \ > i) {\n                neighbor = std::min(neighbor, {idx[y], y});\n      \
    \      }\n        }\n        auto [j, z] = neighbor;\n        if (j == n) continue;\n\
    \n        // check if N(x) - z is a subset of N(z)\n        for (int y : G[x])\
    \ {\n            if (idx[y] > i && y != z && !st[y].count(z)) {\n            \
    \    // not chordal\n                // bfs from y to z using vertices after x\
    \ and not in N(x)\n\n                std::queue<int> que;\n                que.push(y);\n\
    \                std::vector<int> prv(n, -1);\n                prv[y] = y;\n \
    \               prv[z] = -1;\n                for (int v : G[x]) {\n         \
    \           if (v != y && v != z) {\n                        prv[v] = -2;\n  \
    \                  }\n                }\n                while (!que.empty())\
    \ {\n                    int v = que.front();\n                    que.pop();\n\
    \                    for (int u : G[v]) {\n                        if (idx[u]\
    \ > i && prv[u] == -1) {\n                            prv[u] = v;\n          \
    \                  que.push(u);\n                        }\n                 \
    \   }\n                }\n\n                assert(prv[z] != -1);\n\n        \
    \        std::vector<int> cycle;\n                int v = z;\n               \
    \ while (prv[v] != v) {\n                    cycle.push_back(v);\n           \
    \         v = prv[v];\n                }\n                cycle.push_back(y);\n\
    \                cycle.push_back(x);\n\n                return {false, cycle};\n\
    \            }\n        }\n    }\n\n    return {true, ord};\n}\n#line 5 \"test/yosupo/chordal_graph_recognition.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n#define\
    \ rep(i, s, t) for (int i = (int)(s); i < (int)(t); ++i)\n#define revrep(i, t,\
    \ s) for (int i = (int)(t)-1; i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\n\
    template <typename T>\nbool chmax(T& a, const T& b) {\n    return a < b ? (a =\
    \ b, 1) : 0;\n}\ntemplate <typename T>\nbool chmin(T& a, const T& b) {\n    return\
    \ a > b ? (a = b, 1) : 0;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n\n    int N, M;\n\
    \    cin >> N >> M;\n    vector<vector<int>> G(N);\n    rep(i, 0, M) {\n     \
    \   int a, b;\n        cin >> a >> b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n\
    \    }\n\n    auto [ans, vec] = recognize_chordal_graph(G);\n    cout << (ans\
    \ ? \"YES\" : \"NO\") << \"\\n\";\n    if (!ans) cout << vec.size() << \"\\n\"\
    ;\n    for (int i = 0; i < (int)vec.size(); ++i) {\n        cout << vec[i] <<\
    \ (i < (int)vec.size() - 1 ? \" \" : \"\\n\");\n    }\n}\n"
  code: "#define PROBLEM \\\n    \"https://judge.yosupo.jp/problem/chordal_graph_recognition.test.cpp\"\
    \n\n#include \"../../graph/chordal_graph_recognition.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n#define rep(i, s, t) for (int i =\
    \ (int)(s); i < (int)(t); ++i)\n#define revrep(i, t, s) for (int i = (int)(t)-1;\
    \ i >= (int)(s); --i)\n#define all(x) begin(x), end(x)\ntemplate <typename T>\n\
    bool chmax(T& a, const T& b) {\n    return a < b ? (a = b, 1) : 0;\n}\ntemplate\
    \ <typename T>\nbool chmin(T& a, const T& b) {\n    return a > b ? (a = b, 1)\
    \ : 0;\n}\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \    cout << fixed << setprecision(15);\n\n    int N, M;\n    cin >> N >> M;\n\
    \    vector<vector<int>> G(N);\n    rep(i, 0, M) {\n        int a, b;\n      \
    \  cin >> a >> b;\n        G[a].push_back(b);\n        G[b].push_back(a);\n  \
    \  }\n\n    auto [ans, vec] = recognize_chordal_graph(G);\n    cout << (ans ?\
    \ \"YES\" : \"NO\") << \"\\n\";\n    if (!ans) cout << vec.size() << \"\\n\";\n\
    \    for (int i = 0; i < (int)vec.size(); ++i) {\n        cout << vec[i] << (i\
    \ < (int)vec.size() - 1 ? \" \" : \"\\n\");\n    }\n}"
  dependsOn:
  - graph/chordal_graph_recognition.hpp
  - graph/lex_bfs.hpp
  - data-structure/partition_refinement.hpp
  isVerificationFile: true
  path: test/yosupo/chordal_graph_recognition.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 13:32:33+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/chordal_graph_recognition.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/chordal_graph_recognition.test.cpp
- /verify/test/yosupo/chordal_graph_recognition.test.cpp.html
title: test/yosupo/chordal_graph_recognition.test.cpp
---
