---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/number-theory/quotients.hpp
    title: Intervals with Equal Quotients
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_quotients
    links:
    - https://judge.yosupo.jp/problem/enumerate_quotients
  bundledCode: "#line 1 \"test/yosupo/enumerate_quotients.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\n#include <bits/stdc++.h>\n\
    \n#line 3 \"math/number-theory/quotients.hpp\"\n\n/**\n * @brief Intervals with\
    \ Equal Quotients\n */\ntemplate <typename T>\nstd::vector<std::pair<T, T>> quotient_ranges(T\
    \ n) {\n    std::vector<std::pair<T, T>> ret;\n    T i = 1;\n    while (i <= n)\
    \ {\n        T q = n / i;\n        T j = n / q + 1;\n        ret.emplace_back(i,\
    \ j);\n        i = j;\n    }\n    return ret;\n}\n#line 6 \"test/yosupo/enumerate_quotients.test.cpp\"\
    \nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    long long N;\n    cin >> N;\n    auto qr = quotient_ranges(N);\n\
    \    vector<long long> ans;\n    for (auto [l, r] : qr) ans.push_back(N / l);\n\
    \    reverse(ans.begin(), ans.end());\n    int k = ans.size();\n    cout << k\
    \ << endl;\n    for (int i = 0; i < k; ++i) {\n        cout << ans[i] << (i <\
    \ k - 1 ? \" \" : \"\\n\");\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_quotients\"\n\
    \n#include <bits/stdc++.h>\n\n#include \"../../math/number-theory/quotients.hpp\"\
    \nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    long long N;\n    cin >> N;\n    auto qr = quotient_ranges(N);\n\
    \    vector<long long> ans;\n    for (auto [l, r] : qr) ans.push_back(N / l);\n\
    \    reverse(ans.begin(), ans.end());\n    int k = ans.size();\n    cout << k\
    \ << endl;\n    for (int i = 0; i < k; ++i) {\n        cout << ans[i] << (i <\
    \ k - 1 ? \" \" : \"\\n\");\n    }\n}"
  dependsOn:
  - math/number-theory/quotients.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_quotients.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_quotients.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_quotients.test.cpp
- /verify/test/yosupo/enumerate_quotients.test.cpp.html
title: test/yosupo/enumerate_quotients.test.cpp
---
