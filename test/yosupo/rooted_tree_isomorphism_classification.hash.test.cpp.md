---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/edge.cpp
    title: graph/edge.cpp
  - icon: ':question:'
    path: misc/compress.cpp
    title: Coordinate Compression
  - icon: ':heavy_check_mark:'
    path: tree/tree_diameter.cpp
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
  bundledCode: "#line 1 \"test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#line 2 \"misc/compress.cpp\"\n#include <algorithm>\n#include <vector>\n\n\
    /*\n * @brief Coordinate Compression\n */\ntemplate <typename T>\nclass Compress\
    \ {\npublic:\n    Compress() = default;\n    explicit Compress(const std::vector<T>&\
    \ vs) : xs(vs) {\n        std::sort(xs.begin(), xs.end());\n        xs.erase(std::unique(xs.begin(),\
    \ xs.end()), xs.end());\n    }\n\n    int compress(const T& x) const {\n     \
    \   return std::lower_bound(xs.begin(), xs.end(), x) - xs.begin();\n    }\n\n\
    \    std::vector<int> compress(const std::vector<T>& vs) const {\n        std::vector<int>\
    \ ret;\n        std::transform(vs.begin(), vs.end(), std::back_inserter(ret),\
    \ [&](const T& x) {\n            return compress(x);\n        });\n        return\
    \ ret;\n    }\n\n    T decompress(int i) const {\n        return xs[i];\n    }\n\
    \n    int size() const {\n        return xs.size();\n    }\n\nprivate:\n    std::vector<T>\
    \ xs;\n};\n#line 3 \"tree/tree_isomorphism.hpp\"\n#include <map>\n#include <random>\n\
    #include <utility>\n#line 2 \"graph/edge.cpp\"\n\ntemplate <typename T>\nstruct\
    \ Edge {\n    int from, to;\n    T weight;\n    Edge() = default;\n    Edge(int\
    \ to, T weight) : from(-1), to(to), weight(weight) {}\n    Edge(int from, int\
    \ to, T weight) : from(from), to(to), weight(weight) {}\n};\n#line 6 \"tree/tree_diameter.cpp\"\
    \n\nstd::pair<int, std::vector<int>> tree_diameter(const std::vector<std::vector<int>>&\
    \ G) {\n    std::vector<int> to(G.size());\n\n    auto dfs = [&](const auto& dfs,\
    \ int v, int p) -> std::pair<int, int> {\n        std::pair<int, int> ret(0, v);\n\
    \        for (int c : G[v]) {\n            if (c == p) continue;\n           \
    \ auto weight = dfs(dfs, c, v);\n            ++weight.first;\n            if (ret\
    \ < weight) {\n                ret = weight;\n                to[v] = c;\n   \
    \         }\n        }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0,\
    \ -1);\n    auto q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n   \
    \ int v = p.second;\n    while (v != q.second) {\n        path.push_back(v);\n\
    \        v = to[v];\n    }\n    path.push_back(v);\n    return {q.first, path};\n\
    }\n\ntemplate <typename T>\nstd::pair<T, std::vector<int>> tree_diameter(const\
    \ std::vector<std::vector<Edge<T>>>& G) {\n    std::vector<int> to(G.size());\n\
    \n    auto dfs = [&](const auto& dfs, int v, int p) -> std::pair<T, int> {\n \
    \       std::pair<T, int> ret(0, v);\n        for (auto& e : G[v]) {\n       \
    \     if (e.to == p) continue;\n            auto weight = dfs(dfs, e.to, v);\n\
    \            weight.first += e.weight;\n            if (ret < weight) {\n    \
    \            ret = weight;\n                to[v] = e.to;\n            }\n   \
    \     }\n        return ret;\n    };\n\n    auto p = dfs(dfs, 0, -1);\n    auto\
    \ q = dfs(dfs, p.second, -1);\n    std::vector<int> path;\n    int v = p.second;\n\
    \    while (v != q.second) {\n        path.push_back(v);\n        v = to[v];\n\
    \    }\n    path.push_back(v);\n    return {q.first, path};\n}\n#line 8 \"tree/tree_isomorphism.hpp\"\
    \n\nclass TreeHasher {\npublic:\n    TreeHasher() : rng(rd()), rand(1, mod-1)\
    \ {}\n\n    long long hash_all(const std::vector<std::vector<int>>& G, int root\
    \ = -1) {\n        long long res;\n        if (root == -1) {\n            auto\
    \ [d, path] = tree_diameter(G);\n            res = dfs_all(G, path[d / 2], -1).first;\n\
    \            if (d % 2 == 1) {\n                res = std::min(res, dfs_all(G,\
    \ path[d / 2 + 1], -1).first);\n            }\n        } else {\n            res\
    \ = dfs_all(G, root, -1).first;\n        }\n        return res;\n    }\n\n   \
    \ std::vector<long long> hash_subtrees(const std::vector<std::vector<int>>& G,\
    \ int root) {\n        std::vector<long long> hash(G.size());\n        dfs_subtrees(G,\
    \ hash, root, -1);\n        return hash;\n    }\n\nprivate:\n    static constexpr\
    \ long long mod = (1LL << 61) - 1;\n\n    static inline long long add(long long\
    \ a, long long b) {\n        if ((a += b) >= mod) a -= mod;\n        return a;\n\
    \    }\n\n    static inline long long mul(long long a, long long b) {\n      \
    \  __int128_t c = (__int128_t) a * b;\n        return add(c >> 61, c & mod);\n\
    \    }\n\n    std::random_device rd;\n    std::mt19937_64 rng;\n    std::uniform_int_distribution<long\
    \ long> rand;\n    std::vector<long long> R;\n\n    std::pair<long long, int>\
    \ dfs_all(const std::vector<std::vector<int>>& G, int v, int p) {\n        int\
    \ maxd = 0;\n        std::vector<long long> hash;\n        for (int c : G[v])\
    \ {\n            if (c != p) {\n                auto [h, d] = dfs_all(G, c, v);\n\
    \                maxd = std::max(maxd, d + 1);\n                hash.push_back(h);\n\
    \            }\n        }\n        if ((int) R.size() == maxd) {\n           \
    \ R.push_back(rand(rng));\n        }\n        long long res = 1;\n        for\
    \ (auto h : hash) {\n            res = mul(res, add(R[maxd], h));\n        }\n\
    \        return {res, maxd};\n    }\n\n    int dfs_subtrees(const std::vector<std::vector<int>>&\
    \ G, std::vector<long long>& hash, int v, int p) {\n        int maxd = 0;\n  \
    \      for (int c : G[v]) {\n            if (c != p) {\n                maxd =\
    \ std::max(maxd, dfs_subtrees(G, hash, c, v) + 1);\n            }\n        }\n\
    \        if ((int) R.size() == maxd) {\n            R.push_back(rand(rng));\n\
    \        }\n        long long res = 1;\n        for (int c : G[v]) {\n       \
    \     if (c != p) {\n                res = mul(res, add(R[maxd], hash[c]));\n\
    \            }\n        }\n        hash[v] = res;\n        return maxd;\n    }\n\
    };\n\n\nclass TreeEncoder {\npublic:\n    TreeEncoder() {\n        mp[{}] = 0;\n\
    \    }\n\n    std::vector<int> encode(const std::vector<std::vector<int>>& G,\
    \ int root) {\n        std::vector<int> val(G.size());\n        dfs(G, val, root,\
    \ -1);\n        return val;\n    }\n\nprivate:\n    std::map<std::vector<int>,\
    \ int> mp;\n    std::vector<long long> R;\n\n    void dfs(const std::vector<std::vector<int>>&\
    \ G, std::vector<int>& val, int v, int p) {\n        std::vector<int> ch;\n  \
    \      for (int c : G[v]) {\n            if (c != p) {\n                dfs(G,\
    \ val, c, v);\n                ch.push_back(val[c]);\n            }\n        }\n\
    \        std::sort(ch.begin(), ch.end());\n        if (!mp.count(ch)) {\n    \
    \        mp[ch] = mp.size();\n        }\n        val[v] = mp[ch];\n    }\n};\n\
    #line 5 \"test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp\"\n\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N);\n\
    \    for (int i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n      \
    \  G[p].push_back(i);\n    }\n    TreeHasher hash;\n    auto val = hash.hash_subtrees(G,\
    \ 0);\n    Compress<long long> comp(val);\n    auto val2 = comp.compress(val);\n\
    \    cout << comp.size() << endl;\n    for (int i = 0; i < N; ++i) cout << val2[i]\
    \ << (i < N - 1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n\n#include \"../../misc/compress.cpp\"\n#include \"../../tree/tree_isomorphism.hpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N;\n    cin >> N;\n    vector<vector<int>> G(N);\n\
    \    for (int i = 1; i < N; ++i) {\n        int p;\n        cin >> p;\n      \
    \  G[p].push_back(i);\n    }\n    TreeHasher hash;\n    auto val = hash.hash_subtrees(G,\
    \ 0);\n    Compress<long long> comp(val);\n    auto val2 = comp.compress(val);\n\
    \    cout << comp.size() << endl;\n    for (int i = 0; i < N; ++i) cout << val2[i]\
    \ << (i < N - 1 ? \" \" : \"\\n\");\n}"
  dependsOn:
  - misc/compress.cpp
  - tree/tree_isomorphism.hpp
  - tree/tree_diameter.cpp
  - graph/edge.cpp
  isVerificationFile: true
  path: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
  requiredBy: []
  timestamp: '2022-10-20 22:01:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
- /verify/test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp.html
title: test/yosupo/rooted_tree_isomorphism_classification.hash.test.cpp
---
