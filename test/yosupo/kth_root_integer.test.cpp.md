---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/kth_root.hpp
    title: math/kth_root.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/kth_root_integer
    links:
    - https://judge.yosupo.jp/problem/kth_root_integer
  bundledCode: "#line 1 \"test/yosupo/kth_root_integer.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n#line 2 \"math/kth_root.hpp\"\
    \n#include <cassert>\n#include <cmath>\n\nunsigned long long kth_root(unsigned\
    \ long long x, int k) {\n    using ull = unsigned long long;\n    assert(k >=\
    \ 1);\n    if (x <= 1 || k == 1) return x;\n    auto check = [&](ull a) {\n  \
    \      ull y = x;\n        int e = k;\n        while (e) {\n            if (e\
    \ & 1) {\n                if (a == 0) return false;\n                y /= a;\n\
    \            }\n            if (a > 0 && a > y / a)\n                a = 0;\n\
    \            else\n                a *= a;\n            e >>= 1;\n        }\n\
    \        return y > 0;\n    };\n    ull res = std::pow(x, std::nextafter(1.0 /\
    \ k, 0.0));\n    while (check(res + 1)) ++res;\n    return res;\n}\n#line 4 \"\
    test/yosupo/kth_root_integer.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int T;\n    cin >> T;\n    while (T--) {\n        unsigned long long A;\n\
    \        int K;\n        cin >> A >> K;\n        cout << kth_root(A, K) << \"\\\
    n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_root_integer\"\n\n\
    #include \"../../math/kth_root.hpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    int T;\n    cin >> T;\n    while (T--) {\n        unsigned long long A;\n\
    \        int K;\n        cin >> A >> K;\n        cout << kth_root(A, K) << \"\\\
    n\";\n    }\n}"
  dependsOn:
  - math/kth_root.hpp
  isVerificationFile: true
  path: test/yosupo/kth_root_integer.test.cpp
  requiredBy: []
  timestamp: '2023-01-18 15:33:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/kth_root_integer.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/kth_root_integer.test.cpp
- /verify/test/yosupo/kth_root_integer.test.cpp.html
title: test/yosupo/kth_root_integer.test.cpp
---
