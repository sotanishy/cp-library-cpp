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
    \nstd::vector<int> prefix_function(const std::string& s) {\n    const int n =\
    \ s.size();\n    std::vector<int> ret(n);\n    int len = 0;\n    for (int i =\
    \ 1; i < n; ++i) {\n        if (s[i] == s[len]) {\n            ++len;\n      \
    \      ret[i] = len;\n        } else {\n            if (len != 0) {\n        \
    \        len = ret[len - 1];\n                --i;\n            } else {\n   \
    \             ret[i] = 0;\n            }\n        }\n    }\n    return ret;\n\
    }\n\nstd::vector<int> kmp(const std::string txt, const std::string pat) {\n  \
    \  int n = txt.size(), m = pat.size();\n    auto lps = prefix_function(pat);\n\
    \    std::vector<int> match;\n    int i = 0, j = 0;\n    while (i < n) {\n   \
    \     if (pat[j] == txt[i]) {\n            ++i;\n            ++j;\n        }\n\
    \        if (j == m) {\n            match.push_back(i - j);\n            j = lps[j\
    \ - 1];\n        } else if (i < n && pat[j] != txt[i]) {\n            if (j !=\
    \ 0) {\n                j = lps[j - 1];\n            } else {\n              \
    \  ++i;\n            }\n        }\n    }\n    return match;\n}\n\ntemplate <int\
    \ AlphabetSize, int Offset>\nstd::vector<std::vector<std::pair<int, bool>>> matching_automaton(const\
    \ std::string& s) {\n    const int n = s.size();\n    auto lps = prefix_function(s);\n\
    \    std::vector<std::vector<std::pair<int, bool>>> aut(n, std::vector<std::pair<int,\
    \ bool>>(AlphabetSize));\n    for (int i = 0; i < n; ++i) {\n        for (int\
    \ c = 0; c < AlphabetSize; ++c) {\n            if (Offset + c == s[i]) {\n   \
    \             if (i == n - 1) aut[i][c] = {lps[i], true};\n                else\
    \ aut[i][c] = {i + 1, false};\n            } else {\n                aut[i][c]\
    \ = {i > 0 ? aut[lps[i - 1]][c].first : 0, 0};\n            }\n        }\n   \
    \ }\n    return aut;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\nstd::vector<int> prefix_function(const\
    \ std::string& s) {\n    const int n = s.size();\n    std::vector<int> ret(n);\n\
    \    int len = 0;\n    for (int i = 1; i < n; ++i) {\n        if (s[i] == s[len])\
    \ {\n            ++len;\n            ret[i] = len;\n        } else {\n       \
    \     if (len != 0) {\n                len = ret[len - 1];\n                --i;\n\
    \            } else {\n                ret[i] = 0;\n            }\n        }\n\
    \    }\n    return ret;\n}\n\nstd::vector<int> kmp(const std::string txt, const\
    \ std::string pat) {\n    int n = txt.size(), m = pat.size();\n    auto lps =\
    \ prefix_function(pat);\n    std::vector<int> match;\n    int i = 0, j = 0;\n\
    \    while (i < n) {\n        if (pat[j] == txt[i]) {\n            ++i;\n    \
    \        ++j;\n        }\n        if (j == m) {\n            match.push_back(i\
    \ - j);\n            j = lps[j - 1];\n        } else if (i < n && pat[j] != txt[i])\
    \ {\n            if (j != 0) {\n                j = lps[j - 1];\n            }\
    \ else {\n                ++i;\n            }\n        }\n    }\n    return match;\n\
    }\n\ntemplate <int AlphabetSize, int Offset>\nstd::vector<std::vector<std::pair<int,\
    \ bool>>> matching_automaton(const std::string& s) {\n    const int n = s.size();\n\
    \    auto lps = prefix_function(s);\n    std::vector<std::vector<std::pair<int,\
    \ bool>>> aut(n, std::vector<std::pair<int, bool>>(AlphabetSize));\n    for (int\
    \ i = 0; i < n; ++i) {\n        for (int c = 0; c < AlphabetSize; ++c) {\n   \
    \         if (Offset + c == s[i]) {\n                if (i == n - 1) aut[i][c]\
    \ = {lps[i], true};\n                else aut[i][c] = {i + 1, false};\n      \
    \      } else {\n                aut[i][c] = {i > 0 ? aut[lps[i - 1]][c].first\
    \ : 0, 0};\n            }\n        }\n    }\n    return aut;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/kmp.cpp
  requiredBy: []
  timestamp: '2022-07-02 23:35:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.kmp.test.cpp
documentation_of: string/kmp.cpp
layout: document
title: Knuth-Morris-Pratt Algorithm
---

## Description

Knuth-Morris-Pratt のアルゴリズムは，文字列中のパターンの出現位置を列挙するアルゴリズムである．

パターンの prefix function (`P[:i]` の接尾辞でもある最長の proper prefix) を各$i$について前計算することで， 文字の比較の回数を減らしている．

## Operations

- `vector<int> prefix_function(string s)`
    - 文字列 `s` の prefix function を計算する
    - 時間計算量: $O(n)$
- `vector<int> kmp(string txt, string pat)`
    - `txt`中の`pat`の出現位置を列挙する
    - 時間計算量: $O(n + m)$
- `vector<vector<pair<int, bool>>> matching_automaton(string s)`
    - `s` のマッチングオートマトンを返す．`ret[i][c]` は，$i$ 文字マッチしているときに文字 `c` が出現したときの遷移先と，全体がマッチしたか否かを返す．
    - 時間計算量: $O(nA)$, $A$ はアルファベットサイズ

## Reference

- [KMP Algorithm for Pattern Searching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)