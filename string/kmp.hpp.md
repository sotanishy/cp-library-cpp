---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/pattern_search_2d.hpp
    title: 2D Pattern Search (Baker-Bird Algorithm)
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.kmp.test.cpp
    title: test/aoj/ALDS1_14_B.kmp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_C.test.cpp
    title: test/aoj/ALDS1_14_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/kmp.hpp\"\n#include <string>\n#include <vector>\n\
    \ntemplate <typename T>\nstd::vector<int> prefix_function(const std::vector<T>&\
    \ s) {\n    const int n = s.size();\n    std::vector<int> ret(n);\n    for (int\
    \ len = 0, i = 1; i < n; ++i) {\n        if (s[i] == s[len]) {\n            ++len;\n\
    \            ret[i] = len;\n        } else {\n            if (len != 0) {\n  \
    \              len = ret[len - 1];\n                --i;\n            } else {\n\
    \                ret[i] = 0;\n            }\n        }\n    }\n    return ret;\n\
    }\n\ntemplate <typename T>\nstd::vector<int> kmp(const std::vector<T>& txt, const\
    \ std::vector<T>& pat,\n                     const std::vector<int>& pf) {\n \
    \   const int n = txt.size(), m = pat.size();\n    std::vector<int> match;\n \
    \   for (int i = 0, j = 0; i < n;) {\n        if (pat[j] == txt[i]) {\n      \
    \      ++i;\n            ++j;\n        }\n        if (j == m) {\n            match.push_back(i\
    \ - j);\n            j = pf[j - 1];\n        } else if (i < n && pat[j] != txt[i])\
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
    \ aut;\n}\n"
  code: "#pragma once\n#include <string>\n#include <vector>\n\ntemplate <typename\
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
    \ aut;\n}"
  dependsOn: []
  isVerificationFile: false
  path: string/kmp.hpp
  requiredBy:
  - string/pattern_search_2d.hpp
  timestamp: '2024-01-07 22:05:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.kmp.test.cpp
  - test/aoj/ALDS1_14_C.test.cpp
documentation_of: string/kmp.hpp
layout: document
title: Knuth-Morris-Pratt Algorithm
---

## Description

Knuth-Morris-Pratt のアルゴリズムは，文字列中のパターンの出現位置を列挙するアルゴリズムである．

パターンの prefix function (`P[:i+1]` の接尾辞でもある最長の proper prefix) を各$i$について前計算することで， 文字の比較の回数を減らしている．

## Operations

- `vector<int> prefix_function(vector<T> s)`
- `vector<int> prefix_function(string s)`
    - 数列 `s` の prefix function を計算する
    - 時間計算量: $O(n)$
- `vector<int> kmp(vector<T> txt, vector<T> pat, vector<int> pf)`
- `vector<int> kmp(string txt, string pat, vector<int> pf)`
    - `txt`中の`pat`の出現位置を列挙する
    - 時間計算量: $O(n + m)$
- `vector<vector<pair<int, bool>>> matching_automaton(string s)`
    - `s` のマッチングオートマトンを返す．`ret[i][c]` は，$i$ 文字マッチしているときに文字 `c` が出現したときの遷移先と，全体がマッチしたか否かを返す．
    - 時間計算量: $O(nA)$, $A$ はアルファベットサイズ

## Reference

- [KMP Algorithm for Pattern Searching](https://www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/)