---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/range_tree.hpp
    title: Range Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "#line 1 \"test/yosupo/rectangle_sum.range_tree.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include <bits/stdc++.h>\n\
    \n#line 3 \"data-structure/range_tree.hpp\"\n#include <bit>\n#line 6 \"data-structure/range_tree.hpp\"\
    \n\ntemplate <typename X, typename Y, typename T>\nclass RangeTree {\n   public:\n\
    \    RangeTree() = default;\n    explicit RangeTree(const std::vector<std::tuple<X,\
    \ Y, T>>& pts) {\n        for (auto& [x, y, v] : pts) xs.push_back(x);\n     \
    \   std::ranges::sort(xs);\n        xs.erase(std::ranges::unique(xs).begin(),\
    \ xs.end());\n\n        const int n = xs.size();\n        size = std::bit_ceil((unsigned\
    \ int)n);\n\n        node.resize(2 * size);\n        sum.resize(2 * size);\n\n\
    \        for (auto& [x, y, v] : pts) {\n            int i = std::ranges::lower_bound(xs,\
    \ x) - xs.begin();\n            node[size + i].emplace_back(y, v);\n        }\n\
    \n        for (int i = 0; i < n; ++i) {\n            std::ranges::sort(node[size\
    \ + i]);\n        }\n        for (int i = size - 1; i > 0; --i) {\n          \
    \  std::ranges::merge(node[2 * i], node[2 * i + 1],\n                        \
    \       std::back_inserter(node[i]));\n        }\n        for (int i = 0; i <\
    \ size + n; ++i) {\n            sum[i].resize(node[i].size() + 1);\n         \
    \   for (int j = 0; j < (int)node[i].size(); ++j) {\n                sum[i][j\
    \ + 1] = sum[i][j] + node[i][j].second;\n            }\n        }\n    }\n\n \
    \   T fold(X sx, X tx, Y sy, Y ty) const {\n        int l = std::ranges::lower_bound(xs,\
    \ sx) - xs.begin();\n        int r = std::ranges::lower_bound(xs, tx) - xs.begin();\n\
    \        T ret = 0;\n        auto proj = [&](const auto& p) { return p.first;\
    \ };\n        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {\n        \
    \    if (l & 1) {\n                int hi = std::ranges::lower_bound(node[l],\
    \ ty, {}, proj) -\n                         node[l].begin();\n               \
    \ int lo = std::ranges::lower_bound(node[l], sy, {}, proj) -\n               \
    \          node[l].begin();\n                ret += sum[l][hi] - sum[l][lo];\n\
    \                ++l;\n            }\n            if (r & 1) {\n             \
    \   --r;\n                int hi = std::ranges::lower_bound(node[r], ty, {}, proj)\
    \ -\n                         node[r].begin();\n                int lo = std::ranges::lower_bound(node[r],\
    \ sy, {}, proj) -\n                         node[r].begin();\n               \
    \ ret += sum[r][hi] - sum[r][lo];\n            }\n        }\n        return ret;\n\
    \    }\n\n   private:\n    int size;\n    std::vector<X> xs;\n    std::vector<std::vector<std::pair<Y,\
    \ T>>> node;\n    std::vector<std::vector<T>> sum;\n};\n#line 6 \"test/yosupo/rectangle_sum.range_tree.test.cpp\"\
    \nusing namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<tuple<int,\
    \ int, ll>> pts;\n    for (int i = 0; i < N; ++i) {\n        int x, y, w;\n  \
    \      cin >> x >> y >> w;\n        pts.push_back({x, y, w});\n    }\n    RangeTree<int,\
    \ int, ll> rt(pts);\n    for (int i = 0; i < Q; ++i) {\n        int l, d, r, u;\n\
    \        cin >> l >> d >> r >> u;\n        cout << rt.fold(l, r, d, u) << \"\\\
    n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../data-structure/range_tree.hpp\"\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<tuple<int,\
    \ int, ll>> pts;\n    for (int i = 0; i < N; ++i) {\n        int x, y, w;\n  \
    \      cin >> x >> y >> w;\n        pts.push_back({x, y, w});\n    }\n    RangeTree<int,\
    \ int, ll> rt(pts);\n    for (int i = 0; i < Q; ++i) {\n        int l, d, r, u;\n\
    \        cin >> l >> d >> r >> u;\n        cout << rt.fold(l, r, d, u) << \"\\\
    n\";\n    }\n}"
  dependsOn:
  - data-structure/range_tree.hpp
  isVerificationFile: true
  path: test/yosupo/rectangle_sum.range_tree.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 16:18:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/rectangle_sum.range_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/rectangle_sum.range_tree.test.cpp
- /verify/test/yosupo/rectangle_sum.range_tree.test.cpp.html
title: test/yosupo/rectangle_sum.range_tree.test.cpp
---
