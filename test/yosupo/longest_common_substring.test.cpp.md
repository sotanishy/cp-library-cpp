---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/lcp_array.hpp
    title: Longest Common Prefix Array
  - icon: ':heavy_check_mark:'
    path: string/longest_common_substring.hpp
    title: Longest Common Substring
  - icon: ':heavy_check_mark:'
    path: string/suffix_array.hpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/longest_common_substring
    links:
    - https://judge.yosupo.jp/problem/longest_common_substring
  bundledCode: "#line 1 \"test/yosupo/longest_common_substring.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/longest_common_substring\"\n\n#line\
    \ 2 \"string/longest_common_substring.hpp\"\n#include <algorithm>\n#include <string>\n\
    \n#line 3 \"string/lcp_array.hpp\"\n#include <vector>\n\ntemplate <typename T>\n\
    std::vector<int> lcp_array(const std::vector<T>& s,\n                        \
    \   const std::vector<int>& sa) {\n    const int n = s.size();\n    std::vector<int>\
    \ rank(n);\n    for (int i = 0; i < n; ++i) rank[sa[i]] = i;\n    int h = 0;\n\
    \    std::vector<int> lcp(n - 1);\n    for (int i = 0; i < n; ++i) {\n       \
    \ if (h > 0) --h;\n        if (rank[i] == 0) continue;\n        int j = sa[rank[i]\
    \ - 1];\n        while (j + h < n && i + h < n && s[j + h] == s[i + h]) ++h;\n\
    \        lcp[rank[i] - 1] = h;\n    }\n    return lcp;\n}\n\nstd::vector<int>\
    \ lcp_array(const std::string& s, const std::vector<int>& sa) {\n    return lcp_array(std::vector<char>(s.begin(),\
    \ s.end()), sa);\n}\n#line 3 \"string/suffix_array.hpp\"\n#include <numeric>\n\
    #line 6 \"string/suffix_array.hpp\"\n\ntemplate <typename T>\nstd::vector<int>\
    \ suffix_array(const std::vector<T>& s) {\n    const int n = s.size();\n    std::vector<int>\
    \ sa(n);\n    std::iota(sa.begin(), sa.end(), 0);\n    std::ranges::sort(sa, {},\
    \ [&](int i) { return s[i]; });\n    int cl = 0;\n    std::vector<int> rank(n);\n\
    \    for (int i = 1; i < n; ++i) {\n        if (s[sa[i - 1]] != s[sa[i]]) ++cl;\n\
    \        rank[sa[i]] = cl;\n    }\n    std::vector<int> tmp(n), nrank(n), cnt(n);\n\
    \    for (int k = 1; k < n; k <<= 1) {\n        // sort by second half\n     \
    \   int cnt1 = 0, cnt2 = k;\n        for (int i = 0; i < n; ++i) {\n         \
    \   int j = sa[i] - k;\n            if (j >= 0)\n                tmp[cnt2++] =\
    \ j;\n            else\n                tmp[cnt1++] = j + n;\n        }\n\n  \
    \      // sort by first half\n        std::ranges::fill(cnt, 0);\n        for\
    \ (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n;\
    \ ++i) cnt[i] += cnt[i - 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n\n        // assign new rank\n        nrank[sa[0]] = 0;\n       \
    \ cl = 0;\n        for (int i = 1; i < n; ++i) {\n            if (rank[sa[i -\
    \ 1]] != rank[sa[i]] ||\n                (sa[i - 1] + k < n ? rank[sa[i - 1] +\
    \ k] : -1) !=\n                    (sa[i] + k < n ? rank[sa[i] + k] : -1)) {\n\
    \                ++cl;\n            }\n            nrank[sa[i]] = cl;\n      \
    \  }\n        rank.swap(nrank);\n    }\n    return sa;\n}\n\nstd::vector<int>\
    \ suffix_array(const std::string& s) {\n    return suffix_array(std::vector<char>(s.begin(),\
    \ s.end()));\n}\n\ntemplate <typename T>\nstd::vector<int> cyclic_suffix_array(const\
    \ std::vector<T>& s) {\n    const int n = s.size();\n    std::vector<int> sa(n);\n\
    \    std::iota(sa.begin(), sa.end(), 0);\n    std::ranges::sort(sa, {}, [&](int\
    \ i) { return s[i]; });\n    int cl = 0;\n    std::vector<int> rank(n);\n    for\
    \ (int i = 1; i < n; ++i) {\n        if (s[sa[i - 1]] != s[sa[i]]) ++cl;\n   \
    \     rank[sa[i]] = cl;\n    }\n    std::vector<int> tmp(n), nrank(n), cnt(n);\n\
    \    for (int k = 1; k < n; k <<= 1) {\n        // sort by second half\n     \
    \   int cnt1 = 0, cnt2 = k;\n        for (int i = 0; i < n; ++i) {\n         \
    \   int j = sa[i] - k;\n            if (j >= 0)\n                tmp[cnt2++] =\
    \ j;\n            else\n                tmp[cnt1++] = j + n;\n        }\n\n  \
    \      // sort by first half\n        std::ranges::fill(cnt, 0);\n        for\
    \ (int i = 0; i < n; ++i) ++cnt[rank[tmp[i]]];\n        for (int i = 1; i < n;\
    \ ++i) cnt[i] += cnt[i - 1];\n        for (int i = n - 1; i >= 0; --i) sa[--cnt[rank[tmp[i]]]]\
    \ = tmp[i];\n\n        // assign new rank\n        nrank[sa[0]] = 0;\n       \
    \ cl = 0;\n        for (int i = 1; i < n; ++i) {\n            if (rank[sa[i -\
    \ 1]] != rank[sa[i]] ||\n                rank[(sa[i - 1] + k) % n] != rank[(sa[i]\
    \ + k) % n]) {\n                ++cl;\n            }\n            nrank[sa[i]]\
    \ = cl;\n        }\n        rank.swap(nrank);\n    }\n    return sa;\n}\n\nstd::vector<int>\
    \ cyclic_suffix_array(const std::string& s) {\n    return cyclic_suffix_array(std::vector<char>(s.begin(),\
    \ s.end()));\n}\n\n/*\n// comparator for substrings\n// used for string matching\
    \ with the suffix array\n\nauto cmp = [&](int si, const string& t) {\n    int\
    \ sn = S.size(), tn = t.size();\n    int ti = 0;\n    for (; si < sn && ti < tn;\
    \ ++si, ++ti) {\n        if (T[si] < t[ti]) return true;\n        if (T[si] >\
    \ t[ti]) return false;\n    }\n    return si == sn && ti < tn;\n};\n*/\n#line\
    \ 7 \"string/longest_common_substring.hpp\"\n\n/**\n * @brief Longest Common Substring\n\
    \ */\nstd::tuple<int, int, int, int> longest_common_substring(const std::string&\
    \ s,\n                                                        const std::string&\
    \ t) {\n    const int n = s.size();\n    auto st = s + \"$\" + t;\n    auto sa\
    \ = suffix_array(st);\n    auto lcp = lcp_array(st, sa);\n    std::pair<int, std::tuple<int,\
    \ int, int, int>> ans(0, {0, 0, 0, 0});\n    for (int i = 0; i < (int)st.size()\
    \ - 1; ++i) {\n        int len = lcp[i];\n        if (len == 0) continue;\n  \
    \      if (sa[i] < n && sa[i + 1] >= n + 1) {\n            int a = sa[i], c =\
    \ sa[i + 1] - n - 1;\n            ans = std::max(ans, {len, {a, a + len, c, c\
    \ + len}});\n        } else if (sa[i] >= n + 1 && sa[i + 1] < n) {\n         \
    \   int a = sa[i + 1], c = sa[i] - n - 1;\n            ans = std::max(ans, {len,\
    \ {a, a + len, c, c + len}});\n        }\n    }\n    return ans.second;\n}\n#line\
    \ 4 \"test/yosupo/longest_common_substring.test.cpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    string S, T;\n    cin >> S >> T;\n    auto [a, b,\
    \ c, d] = longest_common_substring(S, T);\n    cout << a << \" \" << b << \" \"\
    \ << c << \" \" << d << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/longest_common_substring\"\
    \n\n#include \"../../string/longest_common_substring.hpp\"\n\n#include <bits/stdc++.h>\n\
    using namespace std;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    string S, T;\n    cin >> S >> T;\n    auto [a, b,\
    \ c, d] = longest_common_substring(S, T);\n    cout << a << \" \" << b << \" \"\
    \ << c << \" \" << d << endl;\n}\n"
  dependsOn:
  - string/longest_common_substring.hpp
  - string/lcp_array.hpp
  - string/suffix_array.hpp
  isVerificationFile: true
  path: test/yosupo/longest_common_substring.test.cpp
  requiredBy: []
  timestamp: '2024-01-07 22:37:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/longest_common_substring.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/longest_common_substring.test.cpp
- /verify/test/yosupo/longest_common_substring.test.cpp.html
title: test/yosupo/longest_common_substring.test.cpp
---
