---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.kmp.test.cpp
    title: test/aoj/ALDS1_14_B.kmp.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/kmp.cpp\"\n#include <string>\n#include <vector>\n\
    \nstd::vector<int> kmp(const std::string txt, const std::string pat) {\n    int\
    \ n = txt.size(), m = pat.size();\n\n    std::vector<int> lps(m);\n    int len\
    \ = 0;\n    for (int i = 1; i < m; ++i) {\n        if (pat[i] == pat[len]) {\n\
    \            ++len;\n            lps[i] = len;\n        } else {\n           \
    \ if (len != 0) {\n                len = lps[len - 1];\n                --i;\n\
    \            } else {\n                lps[i] = 0;\n            }\n        }\n\
    \    }\n\n    std::vector<int> match;\n    int i = 0, j = 0;\n    while (i < n)\
    \ {\n        if (pat[j] == txt[i]) {\n            ++i;\n            ++j;\n   \
    \     }\n        if (j == m) {\n            match.push_back(i - j);\n        \
    \    j = lps[j - 1];\n        } else if (i < n && pat[j] != txt[i]) {\n      \
    \      if (j != 0) {\n                j = lps[j - 1];\n            } else {\n\
    \                ++i;\n            }\n        }\n    }\n    return match;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\nstd::vector<int> kmp(const\
    \ std::string txt, const std::string pat) {\n    int n = txt.size(), m = pat.size();\n\
    \n    std::vector<int> lps(m);\n    int len = 0;\n    for (int i = 1; i < m; ++i)\
    \ {\n        if (pat[i] == pat[len]) {\n            ++len;\n            lps[i]\
    \ = len;\n        } else {\n            if (len != 0) {\n                len =\
    \ lps[len - 1];\n                --i;\n            } else {\n                lps[i]\
    \ = 0;\n            }\n        }\n    }\n\n    std::vector<int> match;\n    int\
    \ i = 0, j = 0;\n    while (i < n) {\n        if (pat[j] == txt[i]) {\n      \
    \      ++i;\n            ++j;\n        }\n        if (j == m) {\n            match.push_back(i\
    \ - j);\n            j = lps[j - 1];\n        } else if (i < n && pat[j] != txt[i])\
    \ {\n            if (j != 0) {\n                j = lps[j - 1];\n            }\
    \ else {\n                ++i;\n            }\n        }\n    }\n    return match;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: string/kmp.cpp
  requiredBy: []
  timestamp: '2021-02-05 21:57:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.kmp.test.cpp
documentation_of: string/kmp.cpp
layout: document
title: Knuth-Morris-Pratt Algorithm
---

## Description

Knuth-Morris-Pratt のアルゴリズムは，文字列中のパターンの出現位置を列挙するアルゴリズムである．

`P[:i]` の接尾辞でもある最長の proper prefix を各$i$について前計算することで， 文字の比較の回数を減らしている．

- `vector<int> kmp(string txt, string pat)`
    - `txt`中の`pat`の出現位置を列挙する
    - 時間計算量: $O(n + m)$

## Reference

- [KMP Algorithm for Pattern Searching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)