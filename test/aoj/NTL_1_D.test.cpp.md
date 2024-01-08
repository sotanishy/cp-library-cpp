---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: math/number-theory/euler_totient.hpp
    title: Euler's Totient Function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D
  bundledCode: "#line 1 \"test/aoj/NTL_1_D.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#line 2 \"math/number-theory/euler_totient.hpp\"\n#include <numeric>\n#include\
    \ <vector>\n\nlong long euler_totient(long long n) {\n    long long ret = n;\n\
    \    if (n % 2 == 0) {\n        ret -= ret / 2;\n        while (n % 2 == 0) n\
    \ /= 2;\n    }\n    for (long long i = 3; i * i <= n; i += 2) {\n        if (n\
    \ % i == 0) {\n            ret -= ret / i;\n            while (n % i == 0) n /=\
    \ i;\n        }\n    }\n    if (n != 1) ret -= ret / n;\n    return ret;\n}\n\n\
    std::vector<int> euler_totient_table(int n) {\n    std::vector<int> ret(n + 1);\n\
    \    std::iota(ret.begin(), ret.end(), 0);\n    for (int i = 2; i <= n; ++i) {\n\
    \        if (ret[i] == i) {\n            for (int j = i; j <= n; j += i) {\n \
    \               ret[j] = ret[j] / i * (i - 1);\n            }\n        }\n   \
    \ }\n    return ret;\n}\n\ntemplate <typename mint>\nstd::pair<std::vector<mint>,\
    \ std::vector<mint>> totient_summatory_table(\n    long long n) {\n    if (n ==\
    \ 0) return {{0}, {0}};\n    const int b = std::min(n, (long long)1e4);\n    std::vector<mint>\
    \ small(n / b + 1), large(b + 1);\n\n    std::vector<int> totient(n / b + 1);\n\
    \    std::iota(totient.begin(), totient.end(), 0);\n    for (int i = 2; i <= n\
    \ / b; ++i) {\n        if (totient[i] != i) continue;\n        for (int j = i;\
    \ j <= n / b; j += i) {\n            totient[j] = totient[j] / i * (i - 1);\n\
    \        }\n    }\n    for (int i = 0; i < n / b; ++i) small[i + 1] = small[i]\
    \ + totient[i + 1];\n\n    for (int i = 1; i <= b; ++i) {\n        mint k = n\
    \ / i;\n        large[i] = k * (k + 1) / 2;\n    }\n    for (long long i = b;\
    \ i >= 1; --i) {\n        for (long long l = 2; l <= n / i;) {\n            long\
    \ long q = n / (i * l), r = n / (i * q) + 1;\n            large[i] -=\n      \
    \          (i * l <= b ? large[i * l] : small[n / (i * l)]) * (r - l);\n     \
    \       l = r;\n        }\n    }\n    return {small, large};\n}\n#line 4 \"test/aoj/NTL_1_D.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    cout << euler_totient(n) <<\
    \ endl;\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_D\"\
    \n\n#include \"../../math/number-theory/euler_totient.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    int n;\n    cin >> n;\n    cout << euler_totient(n) <<\
    \ endl;\n}"
  dependsOn:
  - math/number-theory/euler_totient.hpp
  isVerificationFile: true
  path: test/aoj/NTL_1_D.test.cpp
  requiredBy: []
  timestamp: '2024-01-08 17:31:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/NTL_1_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/NTL_1_D.test.cpp
- /verify/test/aoj/NTL_1_D.test.cpp.html
title: test/aoj/NTL_1_D.test.cpp
---
