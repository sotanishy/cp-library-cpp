---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: string/z_array.cpp
    title: Z Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/zalgorithm
    links:
    - https://judge.yosupo.jp/problem/zalgorithm
  bundledCode: "#line 1 \"test/yosupo/zalgorithm.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\
    \n\n#line 2 \"string/z_array.cpp\"\n#include <string>\n#include <vector>\n\nstd::vector<int>\
    \ z_array(const std::string& s) {\n    int n = s.size();\n    std::vector<int>\
    \ z(n);\n    z[0] = n;\n    int l = 0, r = 0;\n    for (int i = 1; i < n; ++i)\
    \ {\n        int k = i - l;\n        if (i <= r && z[k] < r - i + 1) {\n     \
    \       z[i] = z[k];\n        } else {\n            l = i;\n            if (i\
    \ > r) r = i;\n            while (r < n && s[r - l] == s[r]) ++r;\n          \
    \  --r;\n            z[i] = r - l + 1;\n        }\n    }\n    return z;\n}\n#line\
    \ 4 \"test/yosupo/zalgorithm.test.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    string S;\n    cin >> S;\n    vector<int> z = z_array(S);\n    for (int\
    \ i = 0; i < S.size(); ++i) cout << z[i] << (i < S.size() - 1 ? \" \" : \"\\n\"\
    );\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../../string/z_array.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace std;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ string S;\n    cin >> S;\n    vector<int> z = z_array(S);\n    for (int i =\
    \ 0; i < S.size(); ++i) cout << z[i] << (i < S.size() - 1 ? \" \" : \"\\n\");\n\
    }"
  dependsOn:
  - string/z_array.cpp
  isVerificationFile: true
  path: test/yosupo/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '2021-01-17 18:23:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/zalgorithm.test.cpp
- /verify/test/yosupo/zalgorithm.test.cpp.html
title: test/yosupo/zalgorithm.test.cpp
---
