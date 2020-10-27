---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 2 \"misc/mo.cpp\"\n#include <algorithm>\n#include <cmath>\n\
    #include <vector>\n\n/*\n * @brief Mo's Algorithm\n */\nclass Mo {\npublic:\n\
    \    Mo() = default;\n    explicit Mo(int n) : n(n), cnt(0) {}\n\n    void query(int\
    \ l, int r) {\n        queries.emplace_back(cnt++, l, r);\n    }\n\n    template\
    \ <typename T, typename ExL, typename ShL, typename ExR, typename ShR>\n    std::vector<T>\
    \ run(T init, ExL exl, ShL shl, ExR exr, ShR shr) {\n        int s = sqrt(n);\n\
    \        std::sort(queries.begin(), queries.end(), [&](const auto& a, const auto&\
    \ b) {\n            if (a.l / s != b.l / s) return a.l < b.l;\n            return\
    \ a.r < b.r;\n        });\n\n        std::vector<T> ret(cnt);\n        int curL\
    \ = 0, curR = 0;\n        T res = init;\n        for (auto [id, l, r] : queries)\
    \ {\n            while (curL > l) res = exl(res, --curL);\n            while (curL\
    \ < l) res = shl(res, curL++);\n            while (curR < r) res = exr(res, curR++);\n\
    \            while (curR > r) res = shr(res, --curR);\n            ret[id] = res;\n\
    \        }\n        return ret;\n    }\n\nprivate:\n    struct Query {\n     \
    \   int id, l, r;\n        Query(int id, int l, int r) : id(id), l(l), r(r) {}\n\
    \    };\n\n    int n, cnt;\n    std::vector<Query> queries;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cmath>\n#include <vector>\n\
    \n/*\n * @brief Mo's Algorithm\n */\nclass Mo {\npublic:\n    Mo() = default;\n\
    \    explicit Mo(int n) : n(n), cnt(0) {}\n\n    void query(int l, int r) {\n\
    \        queries.emplace_back(cnt++, l, r);\n    }\n\n    template <typename T,\
    \ typename ExL, typename ShL, typename ExR, typename ShR>\n    std::vector<T>\
    \ run(T init, ExL exl, ShL shl, ExR exr, ShR shr) {\n        int s = sqrt(n);\n\
    \        std::sort(queries.begin(), queries.end(), [&](const auto& a, const auto&\
    \ b) {\n            if (a.l / s != b.l / s) return a.l < b.l;\n            return\
    \ a.r < b.r;\n        });\n\n        std::vector<T> ret(cnt);\n        int curL\
    \ = 0, curR = 0;\n        T res = init;\n        for (auto [id, l, r] : queries)\
    \ {\n            while (curL > l) res = exl(res, --curL);\n            while (curL\
    \ < l) res = shl(res, curL++);\n            while (curR < r) res = exr(res, curR++);\n\
    \            while (curR > r) res = shr(res, --curR);\n            ret[id] = res;\n\
    \        }\n        return ret;\n    }\n\nprivate:\n    struct Query {\n     \
    \   int id, l, r;\n        Query(int id, int l, int r) : id(id), l(l), r(r) {}\n\
    \    };\n\n    int n, cnt;\n    std::vector<Query> queries;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/mo.cpp
  requiredBy: []
  timestamp: '2020-10-27 14:13:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: misc/mo.cpp
layout: document
redirect_from:
- /library/misc/mo.cpp
- /library/misc/mo.cpp.html
title: Mo's Algorithm
---
