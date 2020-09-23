---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/floor_sum.cpp
    title: Floor Sum
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_floor_of_linear
    links:
    - https://judge.yosupo.jp/problem/sum_of_floor_of_linear
  bundledCode: "#line 1 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\n\n#line 1 \"math/floor_sum.cpp\"\
    \n#include <bits/stdc++.h>\n\n/*\n * @brief Floor Sum\n * @docs docs/math/floor_sum.md\n\
    \ */\nstd::int64_t floor_sum(std::int64_t n, std::int64_t m, std::int64_t a, std::int64_t\
    \ b) {\n    std::int64_t sum = 0;\n    if (a >= m) {\n        sum += (a / m) *\
    \ n * (n - 1) / 2;\n        a %= m;\n    }\n    if (b >= m) {\n        sum +=\
    \ (b / m) * n;\n        b %= m;\n    }\n    std::int64_t y = (a * n + b) / m;\n\
    \    if (y == 0) return sum;\n    std::int64_t x = (m * y - b + a - 1) / a;\n\
    \    sum += (n - x) * y + floor_sum(y, a, m, a * x - m * y + b);\n    return sum;\n\
    }\n#line 4 \"test/yosupo/sum_of_floor_of_linear.test.cpp\"\n\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int T;\n    cin >> T;\n    while (T--) {\n        int N, M, A, B;\n    \
    \    cin >> N >> M >> A >> B;\n        cout << floor_sum(N, M, A, B) << \"\\n\"\
    ;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_floor_of_linear\"\
    \n\n#include \"../../math/floor_sum.cpp\"\n\nusing namespace std;\n\nint main()\
    \ {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n    int T;\n  \
    \  cin >> T;\n    while (T--) {\n        int N, M, A, B;\n        cin >> N >>\
    \ M >> A >> B;\n        cout << floor_sum(N, M, A, B) << \"\\n\";\n    }\n}"
  dependsOn:
  - math/floor_sum.cpp
  isVerificationFile: true
  path: test/yosupo/sum_of_floor_of_linear.test.cpp
  requiredBy: []
  timestamp: '2020-09-23 11:09:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_floor_of_linear.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp
- /verify/test/yosupo/sum_of_floor_of_linear.test.cpp.html
title: test/yosupo/sum_of_floor_of_linear.test.cpp
---
