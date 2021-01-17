---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/unionfind/partially_persistent_union_find.cpp\"\
    \n#include <algorithm>\n#include <limits>\n#include <utility>\n#include <vector>\n\
    \nclass PartiallyPersistentUnionFind {\npublic:\n    PartiallyPersistentUnionFind()\
    \ = default;\n    explicit PartiallyPersistentUnionFind(int n) : data(n, -1),\
    \ time(n, INF), sz(n, {{0, 1}}) {}\n\n    int find(int t, int x) const {\n   \
    \     if (t < time[x]) return x;\n        return find(t, data[x]);\n    }\n\n\
    \    void unite(int x, int y) {\n        ++now;\n        x = find(now, x);\n \
    \       y = find(now, y);\n        if (x == y) return;\n        if (data[x] >\
    \ data[y]) std::swap(x, y);\n        data[x] += data[y];\n        sz[x].emplace_back(now,\
    \ -data[x]);\n        data[y] = x;\n        time[y] = now;\n    }\n\n    bool\
    \ same(int t, int x, int y) const {\n        return find(t, x) == find(t, y);\n\
    \    }\n\n    int size(int t, int x) const {\n        x = find(t, x);\n      \
    \  return (--std::lower_bound(sz[x].begin(), sz[x].end(), std::make_pair(t, INF)))->second;\n\
    \    }\n\nprivate:\n    static constexpr int INF = std::numeric_limits<int>::max();\n\
    \n    std::vector<int> data;\n    std::vector<int> time;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> sz;\n    int now = 0;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <utility>\n\
    #include <vector>\n\nclass PartiallyPersistentUnionFind {\npublic:\n    PartiallyPersistentUnionFind()\
    \ = default;\n    explicit PartiallyPersistentUnionFind(int n) : data(n, -1),\
    \ time(n, INF), sz(n, {{0, 1}}) {}\n\n    int find(int t, int x) const {\n   \
    \     if (t < time[x]) return x;\n        return find(t, data[x]);\n    }\n\n\
    \    void unite(int x, int y) {\n        ++now;\n        x = find(now, x);\n \
    \       y = find(now, y);\n        if (x == y) return;\n        if (data[x] >\
    \ data[y]) std::swap(x, y);\n        data[x] += data[y];\n        sz[x].emplace_back(now,\
    \ -data[x]);\n        data[y] = x;\n        time[y] = now;\n    }\n\n    bool\
    \ same(int t, int x, int y) const {\n        return find(t, x) == find(t, y);\n\
    \    }\n\n    int size(int t, int x) const {\n        x = find(t, x);\n      \
    \  return (--std::lower_bound(sz[x].begin(), sz[x].end(), std::make_pair(t, INF)))->second;\n\
    \    }\n\nprivate:\n    static constexpr int INF = std::numeric_limits<int>::max();\n\
    \n    std::vector<int> data;\n    std::vector<int> time;\n    std::vector<std::vector<std::pair<int,\
    \ int>>> sz;\n    int now = 0;\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/unionfind/partially_persistent_union_find.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:47:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure/unionfind/partially_persistent_union_find.cpp
layout: document
redirect_from:
- /library/data-structure/unionfind/partially_persistent_union_find.cpp
- /library/data-structure/unionfind/partially_persistent_union_find.cpp.html
title: data-structure/unionfind/partially_persistent_union_find.cpp
---
