---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: string/lcp_array.cpp
    title: Longest Common Prefix Array
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/string/suffix_array.md
    document_title: Suffix Array
    links: []
  bundledCode: "#line 1 \"string/suffix_array.cpp\"\n#include <bits/stdc++.h>\n\n\
    /*\n * @brief Suffix Array\n * @docs docs/string/suffix_array.md\n */\nclass SuffixArray\
    \ {\npublic:\n    SuffixArray() = default;\n    explicit SuffixArray(const std::string&\
    \ str) : s(str) {\n        int n = s.size();\n        sa.resize(n);\n        std::iota(sa.begin(),\
    \ sa.end(), 0);\n        std::sort(sa.begin(), sa.end(), [&](int i, int j) {\n\
    \            return s[i] == s[j] ? i > j : s[i] < s[j];\n        });\n       \
    \ int cl = 0;\n        std::vector<int> rank(n);\n        for (int i = 1; i <\
    \ n; ++i) {\n            if (s[sa[i - 1]] != s[sa[i]]) ++cl;\n            rank[sa[i]]\
    \ = cl;\n        }\n        std::vector<int> tmp(n), nrank(n), cnt(n);\n     \
    \   for (int k = 1; k < n; k <<= 1) {\n            // sort by second half\n  \
    \          int cnt1 = 0, cnt2 = k;\n            for (int i = 0; i < n; ++i) {\n\
    \                int j = sa[i] - k;\n                if (j >= 0) tmp[cnt2++] =\
    \ j;\n                else tmp[cnt1++] = j + n;\n            }\n\n           \
    \ // sort by first half\n            std::fill(cnt.begin(), cnt.end(), 0);\n \
    \           for (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n            for\
    \ (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];\n            for (int i = n -\
    \ 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]] = tmp[i];\n\n            // assign new\
    \ rank\n            nrank[sa[0]] = 0;\n            cl = 0;\n            for (int\
    \ i = 1; i < n; ++i) {\n                if (rank[sa[i - 1]] != rank[sa[i]]\n \
    \                   || (sa[i - 1] + k < n ? rank[sa[i - 1] + k] : -1) != (sa[i]\
    \ + k < n ? rank[sa[i] + k] : -1)) {\n                    ++cl;\n            \
    \    }\n                nrank[sa[i]] = cl;\n            }\n            std::swap(rank,\
    \ nrank);\n        }\n    }\n\n    int operator[](int k) const {\n        return\
    \ sa[k];\n    }\n\n    int lower_bound(const std::string& t) const {\n       \
    \ int lb = -1, ub = sa.size();\n        while (ub - lb > 1) {\n            int\
    \ m = (lb + ub) / 2;\n            if (lt_substr(t, sa[m])) lb = m;\n         \
    \   else ub = m;\n        }\n        return ub;\n    }\n\n    int upper_bound(const\
    \ std::string& t) const {\n        return lower_bound(t + std::numeric_limits<char>::max());\n\
    \    }\n\nprivate:\n    std::vector<int> sa;\n    const std::string s;\n\n   \
    \ bool lt_substr(const std::string& t, int si) const {\n        int sn = s.size(),\
    \ tn = t.size();\n        int ti = 0;\n        for (; si < sn && ti < tn; ++si,\
    \ ++ti) {\n            if (s[si] < t[ti]) return true;\n            if (s[si]\
    \ > t[ti]) return false;\n        }\n        return si >= sn && ti < tn;\n   \
    \ }\n};\n"
  code: "#include <bits/stdc++.h>\n\n/*\n * @brief Suffix Array\n * @docs docs/string/suffix_array.md\n\
    \ */\nclass SuffixArray {\npublic:\n    SuffixArray() = default;\n    explicit\
    \ SuffixArray(const std::string& str) : s(str) {\n        int n = s.size();\n\
    \        sa.resize(n);\n        std::iota(sa.begin(), sa.end(), 0);\n        std::sort(sa.begin(),\
    \ sa.end(), [&](int i, int j) {\n            return s[i] == s[j] ? i > j : s[i]\
    \ < s[j];\n        });\n        int cl = 0;\n        std::vector<int> rank(n);\n\
    \        for (int i = 1; i < n; ++i) {\n            if (s[sa[i - 1]] != s[sa[i]])\
    \ ++cl;\n            rank[sa[i]] = cl;\n        }\n        std::vector<int> tmp(n),\
    \ nrank(n), cnt(n);\n        for (int k = 1; k < n; k <<= 1) {\n            //\
    \ sort by second half\n            int cnt1 = 0, cnt2 = k;\n            for (int\
    \ i = 0; i < n; ++i) {\n                int j = sa[i] - k;\n                if\
    \ (j >= 0) tmp[cnt2++] = j;\n                else tmp[cnt1++] = j + n;\n     \
    \       }\n\n            // sort by first half\n            std::fill(cnt.begin(),\
    \ cnt.end(), 0);\n            for (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n\
    \            for (int i = 1; i < n; ++i) cnt[i] += cnt[i - 1];\n            for\
    \ (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]] = tmp[i];\n\n         \
    \   // assign new rank\n            nrank[sa[0]] = 0;\n            cl = 0;\n \
    \           for (int i = 1; i < n; ++i) {\n                if (rank[sa[i - 1]]\
    \ != rank[sa[i]]\n                    || (sa[i - 1] + k < n ? rank[sa[i - 1] +\
    \ k] : -1) != (sa[i] + k < n ? rank[sa[i] + k] : -1)) {\n                    ++cl;\n\
    \                }\n                nrank[sa[i]] = cl;\n            }\n      \
    \      std::swap(rank, nrank);\n        }\n    }\n\n    int operator[](int k)\
    \ const {\n        return sa[k];\n    }\n\n    int lower_bound(const std::string&\
    \ t) const {\n        int lb = -1, ub = sa.size();\n        while (ub - lb > 1)\
    \ {\n            int m = (lb + ub) / 2;\n            if (lt_substr(t, sa[m]))\
    \ lb = m;\n            else ub = m;\n        }\n        return ub;\n    }\n\n\
    \    int upper_bound(const std::string& t) const {\n        return lower_bound(t\
    \ + std::numeric_limits<char>::max());\n    }\n\nprivate:\n    std::vector<int>\
    \ sa;\n    const std::string s;\n\n    bool lt_substr(const std::string& t, int\
    \ si) const {\n        int sn = s.size(), tn = t.size();\n        int ti = 0;\n\
    \        for (; si < sn && ti < tn; ++si, ++ti) {\n            if (s[si] < t[ti])\
    \ return true;\n            if (s[si] > t[ti]) return false;\n        }\n    \
    \    return si >= sn && ti < tn;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: string/suffix_array.cpp
  requiredBy:
  - string/lcp_array.cpp
  timestamp: '2020-09-24 01:50:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_B.test.cpp
documentation_of: string/suffix_array.cpp
layout: document
redirect_from:
- /library/string/suffix_array.cpp
- /library/string/suffix_array.cpp.html
title: Suffix Array
---
# Suffix Array

接尾辞配列は，文字列のインデックスを接尾辞の辞書順に並べたものである．文字列検索が効率的に行える．

この実装では Manber-Myers のアルゴリズムを用いている．ソートに基数ソートを用いることで時間計算量を $O(n\lg^2 n)$ から $O(n\lg n)$ に改善している．

線形時間で構築を行う SA-IS というより高速なアルゴリズムもある．

## Constructor

- `SuffixArray(string str)`
    - `str` から接尾辞配列を構築する
    - 時間計算量: $O(n\lg n)$

## Member functions

- `int operator[](int k)`
    - 接尾辞配列の $k$ 番目の要素を返す
    - 時間計算量: $O(1)$
- `int lower_bound(string t)`
    - $k$ 番目の接尾辞が `t` より辞書順で等しいか大きくなるような最小の $k$ を返す
    - 時間計算量: $O(m\lg n)$
- `int upper_bound(string t)`
    - $k$ 番目の接尾辞が `t` より辞書順で大きくなるような最小の $k$ を返す
    - 時間計算量: $O(m\lg n)$