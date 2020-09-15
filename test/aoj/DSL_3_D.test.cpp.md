---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.cpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#line 1 \"data-structure/sparse_table.cpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n/*\n * @brief Sparse Table\n * @docs docs/data-structure/sparse_table.md\n\
    \ */\ntemplate <typename S>\nstruct SparseTable {\n    using T = typename S::T;\n\
    \n    vector<vector<T>> lookup;\n\n    SparseTable(const vector<T>& v) {\n   \
    \     int n = v.size(), b = 0;\n        while ((1 << b) <= n) b++;\n        lookup.resize(b,\
    \ vector<T>(n));\n        copy(v.begin(), v.end(), lookup[0].begin());\n     \
    \   for (int i = 1; i < b; i++) {\n            for (int j = 0; j + (1 << i) <=\
    \ n; j++) {\n                lookup[i][j] = S::op(lookup[i - 1][j], lookup[i -\
    \ 1][j + (1 << (i - 1))]);\n            }\n        }\n    }\n\n    T fold(int\
    \ l, int r) {\n        int i = 31 - __builtin_clz(r - l);\n        return S::op(lookup[i][l],\
    \ lookup[i][r - (1 << i)]);\n    }\n};\n#line 4 \"test/aoj/DSL_3_D.test.cpp\"\n\
    \nstruct S {\n    using T = int;\n    static T op(T a, T b) {\n        return\
    \ min(a, b);\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, L;\n    cin >> N >> L;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    SparseTable<S> st(a);\n   \
    \ for (int i = 0; i < N - L + 1; i++) {\n        cout << st.fold(i, i + L);\n\
    \        if (i < N - L) cout << \" \";\n        else cout << \"\\n\";\n    }\n\
    }\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include \"../../data-structure/sparse_table.cpp\"\n\nstruct S {\n    using\
    \ T = int;\n    static T op(T a, T b) {\n        return min(a, b);\n    }\n};\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ int N, L;\n    cin >> N >> L;\n    vector<int> a(N);\n    for (int i = 0; i\
    \ < N; i++) cin >> a[i];\n    SparseTable<S> st(a);\n    for (int i = 0; i < N\
    \ - L + 1; i++) {\n        cout << st.fold(i, i + L);\n        if (i < N - L)\
    \ cout << \" \";\n        else cout << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/sparse_table.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.test.cpp
  requiredBy: []
  timestamp: '2020-09-14 16:31:52+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.test.cpp
- /verify/test/aoj/DSL_3_D.test.cpp.html
title: test/aoj/DSL_3_D.test.cpp
---
