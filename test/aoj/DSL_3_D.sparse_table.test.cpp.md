---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/sparse_table.cpp
    title: Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D
  bundledCode: "#line 1 \"test/aoj/DSL_3_D.sparse_table.test.cpp\"\n#define PROBLEM\
    \ \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\n\n#line\
    \ 2 \"data-structure/sparse_table.cpp\"\n#include <algorithm>\n#include <vector>\n\
    \n/*\n * @brief Sparse Table\n * @docs docs/data-structure/sparse_table.md\n */\n\
    template <typename S>\nclass SparseTable {\n    using T = typename S::T;\n\npublic:\n\
    \    SparseTable() = default;\n    explicit SparseTable(const std::vector<T>&\
    \ v) {\n        int n = v.size(), b = 0;\n        while ((1 << b) <= n) ++b;\n\
    \        lookup.resize(b, std::vector<T>(n));\n        std::copy(v.begin(), v.end(),\
    \ lookup[0].begin());\n        for (int i = 1; i < b; ++i) {\n            for\
    \ (int j = 0; j + (1 << i) <= n; ++j) {\n                lookup[i][j] = S::op(lookup[i\
    \ - 1][j], lookup[i - 1][j + (1 << (i - 1))]);\n            }\n        }\n   \
    \ }\n\n    T fold(int l, int r) const {\n        int i = 31 - __builtin_clz(r\
    \ - l);\n        return S::op(lookup[i][l], lookup[i][r - (1 << i)]);\n    }\n\
    \nprivate:\n    std::vector<std::vector<T>> lookup;\n};\n#line 4 \"test/aoj/DSL_3_D.sparse_table.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct S {\n    using T\
    \ = int;\n    static T op(T a, T b) {\n        return min(a, b);\n    }\n};\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int\
    \ N, L;\n    cin >> N >> L;\n    vector<int> a(N);\n    for (int i = 0; i < N;\
    \ i++) cin >> a[i];\n    SparseTable<S> st(a);\n    for (int i = 0; i < N - L\
    \ + 1; i++) {\n        cout << st.fold(i, i + L);\n        if (i < N - L) cout\
    \ << \" \";\n        else cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_3_D\"\
    \n\n#include \"../../data-structure/sparse_table.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nstruct S {\n    using T = int;\n    static T op(T a, T\
    \ b) {\n        return min(a, b);\n    }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, L;\n    cin >> N >> L;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    SparseTable<S> st(a);\n   \
    \ for (int i = 0; i < N - L + 1; i++) {\n        cout << st.fold(i, i + L);\n\
    \        if (i < N - L) cout << \" \";\n        else cout << \"\\n\";\n    }\n\
    }"
  dependsOn:
  - data-structure/sparse_table.cpp
  isVerificationFile: true
  path: test/aoj/DSL_3_D.sparse_table.test.cpp
  requiredBy: []
  timestamp: '2020-10-24 15:56:56+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_3_D.sparse_table.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_3_D.sparse_table.test.cpp
- /verify/test/aoj/DSL_3_D.sparse_table.test.cpp.html
title: test/aoj/DSL_3_D.sparse_table.test.cpp
---
