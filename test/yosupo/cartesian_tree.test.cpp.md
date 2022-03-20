---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/cartesian_tree.cpp
    title: Cartesian Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cartesian_tree
    links:
    - https://judge.yosupo.jp/problem/cartesian_tree
  bundledCode: "#line 1 \"test/yosupo/cartesian_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#line 2 \"tree/cartesian_tree.cpp\"\
    \n#include <stack>\n#include <vector>\n\ntemplate <typename T>\nstd::vector<int>\
    \ cartesian_tree(const std::vector<T>& a) {\n    int n = a.size();\n    std::vector<int>\
    \ par(n, -1);\n    std::stack<int> st;\n    for (int i = 0; i < n; ++i) {\n  \
    \      int j = -1;\n        while (!st.empty() && a[st.top()] >= a[i]) {\n   \
    \         j = st.top();\n            st.pop();\n        }\n        if (!st.empty())\
    \ {\n            par[i] = st.top();\n        }\n        if (j != -1) {\n     \
    \       par[j] = i;\n        }\n        st.push(i);\n    }\n    return par;\n\
    }\n#line 4 \"test/yosupo/cartesian_tree.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N;\n    cin >> N;\n    vector<int> a(N);\n \
    \   for (auto& x : a) cin >> x;\n    auto p = cartesian_tree(a);\n    for (int\
    \ i = 0; i < N; ++i) cout << (p[i] == -1 ? i : p[i]) << (i < N-1 ? \" \" : \"\\\
    n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cartesian_tree\"\n\n#include\
    \ \"../../tree/cartesian_tree.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N;\n    cin >> N;\n    vector<int> a(N);\n \
    \   for (auto& x : a) cin >> x;\n    auto p = cartesian_tree(a);\n    for (int\
    \ i = 0; i < N; ++i) cout << (p[i] == -1 ? i : p[i]) << (i < N-1 ? \" \" : \"\\\
    n\");\n}\n"
  dependsOn:
  - tree/cartesian_tree.cpp
  isVerificationFile: true
  path: test/yosupo/cartesian_tree.test.cpp
  requiredBy: []
  timestamp: '2022-03-20 19:41:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/cartesian_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/cartesian_tree.test.cpp
- /verify/test/yosupo/cartesian_tree.test.cpp.html
title: test/yosupo/cartesian_tree.test.cpp
---
