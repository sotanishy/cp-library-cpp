---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/kmp.cpp
    title: Knuth-Morris-Pratt Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
    links:
    - http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.kmp.test.cpp\"\n#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#line 2 \"string/kmp.cpp\"\n#include <string>\n#include <vector>\n\nstd::vector<int>\
    \ kmp(const std::string txt, const std::string pat) {\n    int n = txt.size(),\
    \ m = pat.size();\n\n    std::vector<int> lps(m);\n    int len = 0;\n    for (int\
    \ i = 1; i < m; ++i) {\n        if (pat[i] == pat[len]) {\n            ++len;\n\
    \            lps[i] = len;\n        } else {\n            if (len != 0) {\n  \
    \              len = lps[len - 1];\n                --i;\n            } else {\n\
    \                lps[i] = 0;\n            }\n        }\n    }\n\n    std::vector<int>\
    \ match;\n    int i = 0, j = 0;\n    while (i < n) {\n        if (pat[j] == txt[i])\
    \ {\n            ++i;\n            ++j;\n        }\n        if (j == m) {\n  \
    \          match.push_back(i - j);\n            j = lps[j - 1];\n        } else\
    \ if (i < n && pat[j] != txt[i]) {\n            if (j != 0) {\n              \
    \  j = lps[j - 1];\n            } else {\n                ++i;\n            }\n\
    \        }\n    }\n    return match;\n}\n#line 4 \"test/aoj/ALDS1_14_B.kmp.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(0);\n\n    string T;\n    cin >> T;\n    string P;\n    cin >> P;\n\
    \    auto ans = kmp(T, P);\n    for (int i : ans) cout << i << \"\\n\";\n}\n"
  code: "#define PROBLEM \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include \"../../string/kmp.cpp\"\n\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    string T;\n    cin >> T;\n    string P;\n    cin >> P;\n    auto ans = kmp(T,\
    \ P);\n    for (int i : ans) cout << i << \"\\n\";\n}\n"
  dependsOn:
  - string/kmp.cpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.kmp.test.cpp
  requiredBy: []
  timestamp: '2021-02-05 21:57:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.kmp.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.kmp.test.cpp
- /verify/test/aoj/ALDS1_14_B.kmp.test.cpp.html
title: test/aoj/ALDS1_14_B.kmp.test.cpp
---
