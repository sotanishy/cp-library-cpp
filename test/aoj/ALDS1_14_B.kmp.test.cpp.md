---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/kmp.hpp
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
  bundledCode: "#line 1 \"test/aoj/ALDS1_14_B.kmp.test.cpp\"\n#define PROBLEM \\\n\
    \    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\n\
    \n#include <bits/stdc++.h>\n\n#line 4 \"string/kmp.hpp\"\n\ntemplate <typename\
    \ T>\nstd::vector<int> prefix_function(const std::vector<T>& s) {\n    const int\
    \ n = s.size();\n    std::vector<int> ret(n);\n    for (int len = 0, i = 1; i\
    \ < n; ++i) {\n        if (s[i] == s[len]) {\n            ++len;\n           \
    \ ret[i] = len;\n        } else {\n            if (len != 0) {\n             \
    \   len = ret[len - 1];\n                --i;\n            } else {\n        \
    \        ret[i] = 0;\n            }\n        }\n    }\n    return ret;\n}\n\n\
    template <typename T>\nstd::vector<int> kmp(const std::vector<T>& txt, const std::vector<T>&\
    \ pat,\n                     const std::vector<int>& pf) {\n    const int n =\
    \ txt.size(), m = pat.size();\n    std::vector<int> match;\n    for (int i = 0,\
    \ j = 0; i < n;) {\n        if (pat[j] == txt[i]) {\n            ++i;\n      \
    \      ++j;\n        }\n        if (j == m) {\n            match.push_back(i -\
    \ j);\n            j = pf[j - 1];\n        } else if (i < n && pat[j] != txt[i])\
    \ {\n            if (j != 0) {\n                j = pf[j - 1];\n            }\
    \ else {\n                ++i;\n            }\n        }\n    }\n    return match;\n\
    }\n\nstd::vector<int> prefix_function(const std::string& s) {\n    return prefix_function(std::vector<char>(s.begin(),\
    \ s.end()));\n}\n\nstd::vector<int> kmp(const std::string& txt, const std::string&\
    \ pat,\n                     const std::vector<int>& pf) {\n    return kmp(std::vector<char>(txt.begin(),\
    \ txt.end()),\n               std::vector<char>(pat.begin(), pat.end()), pf);\n\
    }\n\ntemplate <int AlphabetSize, int Offset>\nstd::vector<std::vector<std::pair<int,\
    \ bool>>> matching_automaton(\n    const std::string& s) {\n    const int n =\
    \ s.size();\n    auto lps = prefix_function(s);\n    std::vector aut(n, std::vector<std::pair<int,\
    \ bool>>(AlphabetSize));\n    for (int i = 0; i < n; ++i) {\n        for (int\
    \ c = 0; c < AlphabetSize; ++c) {\n            if (Offset + c == s[i]) {\n   \
    \             if (i == n - 1) {\n                    aut[i][c] = {lps[i], true};\n\
    \                } else {\n                    aut[i][c] = {i + 1, false};\n \
    \               }\n            } else {\n                aut[i][c] = {i > 0 ?\
    \ aut[lps[i - 1]][c].first : 0, 0};\n            }\n        }\n    }\n    return\
    \ aut;\n}\n#line 7 \"test/aoj/ALDS1_14_B.kmp.test.cpp\"\nusing namespace std;\n\
    \nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\n   \
    \ string T;\n    cin >> T;\n    string P;\n    cin >> P;\n    auto ans = kmp(T,\
    \ P, prefix_function(P));\n    for (int i : ans) cout << i << \"\\n\";\n}\n"
  code: "#define PROBLEM \\\n    \"http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B\"\
    \n\n#include <bits/stdc++.h>\n\n#include \"../../string/kmp.hpp\"\nusing namespace\
    \ std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(0);\n\
    \n    string T;\n    cin >> T;\n    string P;\n    cin >> P;\n    auto ans = kmp(T,\
    \ P, prefix_function(P));\n    for (int i : ans) cout << i << \"\\n\";\n}\n"
  dependsOn:
  - string/kmp.hpp
  isVerificationFile: true
  path: test/aoj/ALDS1_14_B.kmp.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 22:05:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ALDS1_14_B.kmp.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ALDS1_14_B.kmp.test.cpp
- /verify/test/aoj/ALDS1_14_B.kmp.test.cpp.html
title: test/aoj/ALDS1_14_B.kmp.test.cpp
---
