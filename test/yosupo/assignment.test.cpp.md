---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "#line 1 \"test/yosupo/assignment.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    template <typename T>\nstd::pair<T, std::vector<int>> hungarian(const std::vector<std::vector<T>>&\
    \ A) {\n    const T INF = std::numeric_limits<T>::max();\n    const int n = A.size();\n\
    \    std::vector<int> P(n), way(n);\n    std::vector<T> U(n), V(n), minV;  //\
    \ value substracted from row, col\n    std::vector<bool> used;\n\n    for (int\
    \ i = 1; i < n; ++i) {\n        P[0] = i;\n        minV.assign(n, INF);\n    \
    \    used.assign(n, false);\n        int j0 = 0;\n        while (P[j0] != 0) {\n\
    \            int i0 = P[j0], j1 = 0;  // col with the minimum value\n        \
    \    used[j0] = true;\n            T delta = INF;\n            for (int j = 1;\
    \ j < n; ++j) {\n                if (used[j]) continue;\n                T curr\
    \ = A[i0][j] - U[i0] - V[j];\n                if (curr < minV[j]) {\n        \
    \            minV[j] = curr;\n                    way[j] = j0;\n             \
    \   }\n                if (minV[j] < delta) {\n                    delta = minV[j];\n\
    \                    j1 = j;\n                }\n            }\n            for\
    \ (int j = 0; j < n; ++j) {\n                if (used[j]) {\n                \
    \    U[P[j]] += delta;\n                    V[j] -= delta;\n                }\
    \ else {\n                    minV[j] -= delta;\n                }\n         \
    \   }\n            j0 = j1;\n        }\n        do {\n            P[j0] = P[way[j0]];\n\
    \            j0 = way[j0];\n        } while (j0 != 0);\n    }\n    return -V[0];\n\
    }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N;\n    cin >> N;\n    vector<vector<ll>> a(N, vector<ll>(N));\n   \
    \ for (auto& row : a) for (auto& x : row) cin >> x;\n    ll X;\n    vector<int>\
    \ p;\n    tie(X, p) = hungarian(a);\n    cout << X << endl;\n    for (int i =\
    \ 0; i < N; ++i) cout << p[i] < (i < N-1 ? \" \" : \"\\n\");\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\ntemplate <typename\
    \ T>\nstd::pair<T, std::vector<int>> hungarian(const std::vector<std::vector<T>>&\
    \ A) {\n    const T INF = std::numeric_limits<T>::max();\n    const int n = A.size();\n\
    \    std::vector<int> P(n), way(n);\n    std::vector<T> U(n), V(n), minV;  //\
    \ value substracted from row, col\n    std::vector<bool> used;\n\n    for (int\
    \ i = 1; i < n; ++i) {\n        P[0] = i;\n        minV.assign(n, INF);\n    \
    \    used.assign(n, false);\n        int j0 = 0;\n        while (P[j0] != 0) {\n\
    \            int i0 = P[j0], j1 = 0;  // col with the minimum value\n        \
    \    used[j0] = true;\n            T delta = INF;\n            for (int j = 1;\
    \ j < n; ++j) {\n                if (used[j]) continue;\n                T curr\
    \ = A[i0][j] - U[i0] - V[j];\n                if (curr < minV[j]) {\n        \
    \            minV[j] = curr;\n                    way[j] = j0;\n             \
    \   }\n                if (minV[j] < delta) {\n                    delta = minV[j];\n\
    \                    j1 = j;\n                }\n            }\n            for\
    \ (int j = 0; j < n; ++j) {\n                if (used[j]) {\n                \
    \    U[P[j]] += delta;\n                    V[j] -= delta;\n                }\
    \ else {\n                    minV[j] -= delta;\n                }\n         \
    \   }\n            j0 = j1;\n        }\n        do {\n            P[j0] = P[way[j0]];\n\
    \            j0 = way[j0];\n        } while (j0 != 0);\n    }\n    return -V[0];\n\
    }\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\
    \n    int N;\n    cin >> N;\n    vector<vector<ll>> a(N, vector<ll>(N));\n   \
    \ for (auto& row : a) for (auto& x : row) cin >> x;\n    ll X;\n    vector<int>\
    \ p;\n    tie(X, p) = hungarian(a);\n    cout << X << endl;\n    for (int i =\
    \ 0; i < N; ++i) cout << p[i] < (i < N-1 ? \" \" : \"\\n\");\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/assignment.test.cpp
  requiredBy: []
  timestamp: '2022-05-06 13:22:10+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/assignment.test.cpp
- /verify/test/yosupo/assignment.test.cpp.html
title: test/yosupo/assignment.test.cpp
---
