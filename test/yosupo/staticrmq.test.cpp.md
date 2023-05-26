---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/disjoint_sparse_table.cpp
    title: Disjoint Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#include <bits/stdc++.h>\n\n#line 4 \"data-structure/disjoint_sparse_table.cpp\"\
    \n\ntemplate <typename M>\nclass DisjointSparseTable {\n    using T = typename\
    \ M::T;\n\n   public:\n    DisjointSparseTable() = default;\n    explicit DisjointSparseTable(const\
    \ std::vector<T>& v) {\n        int n = v.size(), b = 0;\n        while ((1 <<\
    \ b) < n) ++b;\n        lookup.resize(b + 1, std::vector<T>(n));\n        std::copy(v.begin(),\
    \ v.end(), lookup[0].begin());\n        for (int i = 1; i <= b; ++i) {\n     \
    \       int len = 1 << i;\n            for (int l = 0; l + len / 2 < n; l += len)\
    \ {\n                int m = l + len / 2;\n                lookup[i][m - 1] =\
    \ v[m - 1];\n                for (int j = m - 2; j >= l; --j) {\n            \
    \        lookup[i][j] = M::op(lookup[i][j + 1], v[j]);\n                }\n  \
    \              lookup[i][m] = v[m];\n                for (int j = m + 1; j < std::min(l\
    \ + len, n); ++j) {\n                    lookup[i][j] = M::op(lookup[i][j - 1],\
    \ v[j]);\n                }\n            }\n        }\n    }\n\n    T fold(int\
    \ l, int r) const {\n        if (l == r) return M::id();\n        if (r - l ==\
    \ 1) return lookup[0][l];\n        int i = 32 - __builtin_clz(l ^ (r - 1));\n\
    \        return M::op(lookup[i][l], lookup[i][r - 1]);\n    }\n\n   private:\n\
    \    std::vector<std::vector<T>> lookup;\n};\n#line 6 \"test/yosupo/staticrmq.test.cpp\"\
    \nusing namespace std;\n\nstruct MinMonoid {\n    using T = int;\n    static T\
    \ id() { return (1u << 31) - 1; }\n    static T op(T a, T b) { return min(a, b);\
    \ }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> a[i];\n    DisjointSparseTable<MinMonoid> st(a);\n    for\
    \ (int i = 0; i < Q; i++) {\n        int l, r;\n        cin >> l >> r;\n     \
    \   cout << st.fold(l, r) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../data-structure/disjoint_sparse_table.cpp\"\
    \nusing namespace std;\n\nstruct MinMonoid {\n    using T = int;\n    static T\
    \ id() { return (1u << 31) - 1; }\n    static T op(T a, T b) { return min(a, b);\
    \ }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> a[i];\n    DisjointSparseTable<MinMonoid> st(a);\n    for\
    \ (int i = 0; i < Q; i++) {\n        int l, r;\n        cin >> l >> r;\n     \
    \   cout << st.fold(l, r) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/disjoint_sparse_table.cpp
  isVerificationFile: true
  path: test/yosupo/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2023-05-27 03:55:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/staticrmq.test.cpp
- /verify/test/yosupo/staticrmq.test.cpp.html
title: test/yosupo/staticrmq.test.cpp
---
