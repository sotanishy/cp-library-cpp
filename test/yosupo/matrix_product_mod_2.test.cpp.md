---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/linalg/binary_matrix.hpp
    title: Binary Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product_mod_2
    links:
    - https://judge.yosupo.jp/problem/matrix_product_mod_2
  bundledCode: "#line 1 \"test/yosupo/matrix_product_mod_2.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/matrix_product_mod_2\"\n\n#include <bits/stdc++.h>\n\
    \n#line 5 \"math/linalg/binary_matrix.hpp\"\n\n/**\n * @brief Binary Matrix\n\
    \ */\ntemplate <int SZ>\nclass BinaryMatrix {\n    using Mat = BinaryMatrix;\n\
    \    using Vec = std::bitset<SZ>;\n\n   public:\n    BinaryMatrix() = default;\n\
    \    BinaryMatrix(int m, int n) : mat(m), m(m), n(n) {}\n\n    void set(int i,\
    \ int j) { mat[i].set(j); }\n\n    bool get(int i, int j) { return mat[i].test(j);\
    \ }\n\n    Mat matmul(const Mat& B) const {\n        Mat res(m, B.n);\n      \
    \  for (int i = 0; i < m; ++i) {\n            for (int k = 0; k < n; ++k) {\n\
    \                if (mat[i][k]) res.mat[i] ^= B.mat[k];\n            }\n     \
    \   }\n        return res;\n    }\n\n    Mat pow(long long k) const {\n      \
    \  assert(m == n);\n        Mat ret(n, n), A(*this);\n        for (int i = 0;\
    \ i < n; ++i) {\n            ret.mat[i].set(i);\n            ret.matt[i].set(i);\n\
    \        }\n        while (k > 0) {\n            if (k & 1) ret = ret.matmul(A);\n\
    \            A = A.matmul(A);\n            k >>= 1;\n        }\n        return\
    \ ret;\n    }\n\n   protected:\n    std::vector<Vec> mat;\n    int m, n;\n};\n\
    #line 6 \"test/yosupo/matrix_product_mod_2.test.cpp\"\nusing namespace std;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    int N, M, K;\n    cin >> N >> M >> K;\n    BinaryMatrix<1 << 12> A(N, M),\
    \ B(M, K);\n\n    for (int i = 0; i < N; ++i) {\n        string row;\n       \
    \ cin >> row;\n        for (int j = 0; j < M; ++j) {\n            if (row[j] ==\
    \ '1') A.set(i, j);\n        }\n    }\n    for (int i = 0; i < M; ++i) {\n   \
    \     string row;\n        cin >> row;\n        for (int j = 0; j < K; ++j) {\n\
    \            if (row[j] == '1') B.set(i, j);\n        }\n    }\n    auto C = A.matmul(B);\n\
    \    for (int i = 0; i < N; ++i) {\n        for (int j = 0; j < K; ++j) cout <<\
    \ C.get(i, j);\n        cout << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product_mod_2\"\n\
    \n#include <bits/stdc++.h>\n\n#include \"../../math/linalg/binary_matrix.hpp\"\
    \nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    int N, M, K;\n    cin >> N >> M >> K;\n    BinaryMatrix<1\
    \ << 12> A(N, M), B(M, K);\n\n    for (int i = 0; i < N; ++i) {\n        string\
    \ row;\n        cin >> row;\n        for (int j = 0; j < M; ++j) {\n         \
    \   if (row[j] == '1') A.set(i, j);\n        }\n    }\n    for (int i = 0; i <\
    \ M; ++i) {\n        string row;\n        cin >> row;\n        for (int j = 0;\
    \ j < K; ++j) {\n            if (row[j] == '1') B.set(i, j);\n        }\n    }\n\
    \    auto C = A.matmul(B);\n    for (int i = 0; i < N; ++i) {\n        for (int\
    \ j = 0; j < K; ++j) cout << C.get(i, j);\n        cout << \"\\n\";\n    }\n}\n"
  dependsOn:
  - math/linalg/binary_matrix.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_product_mod_2.test.cpp
  requiredBy: []
  timestamp: '2024-03-02 18:46:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_product_mod_2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_product_mod_2.test.cpp
- /verify/test/yosupo/matrix_product_mod_2.test.cpp.html
title: test/yosupo/matrix_product_mod_2.test.cpp
---
