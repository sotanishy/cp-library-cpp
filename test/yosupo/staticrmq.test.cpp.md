---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: data-structure/disjoint_sparse_table.hpp
    title: Disjoint Sparse Table
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/staticrmq
    links:
    - https://judge.yosupo.jp/problem/staticrmq
  bundledCode: "#line 1 \"test/yosupo/staticrmq.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\
    \n\n#include <bits/stdc++.h>\n\n#line 3 \"data-structure/disjoint_sparse_table.hpp\"\
    \n#include <bit>\n#line 5 \"data-structure/disjoint_sparse_table.hpp\"\n\ntemplate\
    \ <typename M>\nclass DisjointSparseTable {\n    using T = M::T;\n\n   public:\n\
    \    DisjointSparseTable() = default;\n    explicit DisjointSparseTable(const\
    \ std::vector<T>& v) {\n        const int n = v.size();\n        const int b =\
    \ std::bit_width((unsigned int)n);\n        lookup.resize(b + 1, std::vector<T>(n));\n\
    \        std::ranges::copy(v, lookup[0].begin());\n        for (int i = 1; i <=\
    \ b; ++i) {\n            int len = 1 << i;\n            for (int l = 0; l + len\
    \ / 2 < n; l += len) {\n                int m = l + len / 2;\n               \
    \ lookup[i][m - 1] = v[m - 1];\n                for (int j = m - 2; j >= l; --j)\
    \ {\n                    lookup[i][j] = M::op(lookup[i][j + 1], v[j]);\n     \
    \           }\n                lookup[i][m] = v[m];\n                for (int\
    \ j = m + 1; j < std::min(l + len, n); ++j) {\n                    lookup[i][j]\
    \ = M::op(lookup[i][j - 1], v[j]);\n                }\n            }\n       \
    \ }\n    }\n\n    T fold(int l, int r) const {\n        if (l == r) return M::id();\n\
    \        if (r - l == 1) return lookup[0][l];\n        int i = std::bit_width((unsigned\
    \ int)(l ^ (r - 1)));\n        return M::op(lookup[i][l], lookup[i][r - 1]);\n\
    \    }\n\n   private:\n    std::vector<std::vector<T>> lookup;\n};\n#line 6 \"\
    test/yosupo/staticrmq.test.cpp\"\nusing namespace std;\n\nstruct MinMonoid {\n\
    \    using T = int;\n    static T id() { return (1u << 31) - 1; }\n    static\
    \ T op(T a, T b) { return min(a, b); }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    DisjointSparseTable<MinMonoid>\
    \ st(a);\n    for (int i = 0; i < Q; i++) {\n        int l, r;\n        cin >>\
    \ l >> r;\n        cout << st.fold(l, r) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/staticrmq\"\n\n#include\
    \ <bits/stdc++.h>\n\n#include \"../../data-structure/disjoint_sparse_table.hpp\"\
    \nusing namespace std;\n\nstruct MinMonoid {\n    using T = int;\n    static T\
    \ id() { return (1u << 31) - 1; }\n    static T op(T a, T b) { return min(a, b);\
    \ }\n};\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N);\n    for (int i = 0;\
    \ i < N; i++) cin >> a[i];\n    DisjointSparseTable<MinMonoid> st(a);\n    for\
    \ (int i = 0; i < Q; i++) {\n        int l, r;\n        cin >> l >> r;\n     \
    \   cout << st.fold(l, r) << \"\\n\";\n    }\n}"
  dependsOn:
  - data-structure/disjoint_sparse_table.hpp
  isVerificationFile: true
  path: test/yosupo/staticrmq.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 02:22:28+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/staticrmq.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/staticrmq.test.cpp
- /verify/test/yosupo/staticrmq.test.cpp.html
title: test/yosupo/staticrmq.test.cpp
---
