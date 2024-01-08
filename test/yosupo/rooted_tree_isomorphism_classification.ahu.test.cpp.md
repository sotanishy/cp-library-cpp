---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: tree/tree_diameter.hpp
    title: Diameter of a Tree
  - icon: ':heavy_check_mark:'
    path: tree/tree_isomorphism.hpp
    title: Tree Isomorphism
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 2 \"tree/tree_isomorphism.hpp\"\n#include <algorithm>\n#include <map>\n\
    #include <random>\n#include <utility>\n#include <vector>\n\n#line 5 \"tree/tree_diameter.hpp\"\
    \n\nstd::pair<int, std::vector<int>> tree_diameter(\n    const std::vector<std::vector<int>>&\
    \ G) {\n    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs,\
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
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n#line 9 \"tree/tree_isomorphism.hpp\"\
    \n\nclass TreeHasher {\n   public:\n    TreeHasher() : rng(rd()), rand(1, mod\
    \ - 1) {}\n\n    long long hash_all(const std::vector<std::vector<int>>& G, int\
    \ root = -1) {\n        long long res;\n        if (root == -1) {\n          \
    \  auto [d, path] = tree_diameter(G);\n            res = dfs_all(G, path[d / 2],\
    \ -1).first;\n            if (d % 2 == 1) {\n                res = std::min(res,\
    \ dfs_all(G, path[d / 2 + 1], -1).first);\n            }\n        } else {\n \
    \           res = dfs_all(G, root, -1).first;\n        }\n        return res;\n\
    \    }\n\n    std::vector<long long> hash_subtrees(const std::vector<std::vector<int>>&\
    \ G,\n                                         int root) {\n        std::vector<long\
    \ long> hash(G.size());\n        dfs_subtrees(G, hash, root, -1);\n        return\
    \ hash;\n    }\n\n   private:\n    static constexpr long long mod = (1LL << 61)\
    \ - 1;\n\n    static inline long long add(long long a, long long b) {\n      \
    \  if ((a += b) >= mod) a -= mod;\n        return a;\n    }\n\n    static inline\
    \ long long mul(long long a, long long b) {\n        __int128_t c = (__int128_t)a\
    \ * b;\n        return add(c >> 61, c & mod);\n    }\n\n    std::random_device\
    \ rd;\n    std::mt19937_64 rng;\n    std::uniform_int_distribution<long long>\
    \ rand;\n    std::vector<long long> R;\n\n    std::pair<long long, int> dfs_all(const\
    \ std::vector<std::vector<int>>& G,\n                                      int\
    \ v, int p) {\n        int maxd = 0;\n        std::vector<long long> hash;\n \
    \       for (int c : G[v]) {\n            if (c != p) {\n                auto\
    \ [h, d] = dfs_all(G, c, v);\n                maxd = std::max(maxd, d + 1);\n\
    \                hash.push_back(h);\n            }\n        }\n        if ((int)R.size()\
    \ == maxd) {\n            R.push_back(rand(rng));\n        }\n        long long\
    \ res = 1;\n        for (auto h : hash) {\n            res = mul(res, add(R[maxd],\
    \ h));\n        }\n        return {res, maxd};\n    }\n\n    int dfs_subtrees(const\
    \ std::vector<std::vector<int>>& G,\n                     std::vector<long long>&\
    \ hash, int v, int p) {\n        int maxd = 0;\n        for (int c : G[v]) {\n\
    \            if (c != p) {\n                maxd = std::max(maxd, dfs_subtrees(G,\
    \ hash, c, v) + 1);\n            }\n        }\n        if ((int)R.size() == maxd)\
    \ {\n            R.push_back(rand(rng));\n        }\n        long long res = 1;\n\
    \        for (int c : G[v]) {\n            if (c != p) {\n                res\
    \ = mul(res, add(R[maxd], hash[c]));\n            }\n        }\n        hash[v]\
    \ = res;\n        return maxd;\n    }\n};\n\nclass TreeEncoder {\n   public:\n\
    \    TreeEncoder() { mp[{}] = 0; }\n\n    std::vector<int> encode(const std::vector<std::vector<int>>&\
    \ G, int root) {\n        std::vector<int> val(G.size());\n        dfs(G, val,\
    \ root, -1);\n        return val;\n    }\n\n   private:\n    std::map<std::vector<int>,\
    \ int> mp;\n    std::vector<long long> R;\n\n    void dfs(const std::vector<std::vector<int>>&\
    \ G, std::vector<int>& val,\n             int v, int p) {\n        std::vector<int>\
    \ ch;\n        for (int c : G[v]) {\n            if (c != p) {\n             \
    \   dfs(G, val, c, v);\n                ch.push_back(val[c]);\n            }\n\
    \        }\n        std::ranges::sort(ch);\n        if (!mp.contains(ch)) {\n\
    \            mp[ch] = mp.size();\n        }\n        val[v] = mp[ch];\n    }\n\
    };\n#line 4 \"test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N);\n\
    \    for (int i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n      \
    \  G[p].push_back(i);\n    }\n    TreeEncoder enc;\n    auto val = enc.encode(G,\
    \ 0);\n    cout << *max_element(val.begin(), val.end()) + 1 << endl;\n    for\
    \ (int i = 0; i < N; ++i) cout << val[i] << (i < N - 1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../tree/tree_isomorphism.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N);\n\
    \    for (int i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n      \
    \  G[p].push_back(i);\n    }\n    TreeEncoder enc;\n    auto val = enc.encode(G,\
    \ 0);\n    cout << *max_element(val.begin(), val.end()) + 1 << endl;\n    for\
    \ (int i = 0; i < N; ++i) cout << val[i] << (i < N - 1 ? \" \" : \"\\n\");\n}"
  dependsOn:
  - tree/tree_isomorphism.hpp
  - tree/tree_diameter.hpp
  isVerificationFile: true
  path: test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 23:25:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
- /verify/test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp.html
title: test/yosupo/rooted_tree_isomorphism_classification.ahu.test.cpp
---
