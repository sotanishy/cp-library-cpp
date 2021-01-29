---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: string/manacher.cpp
    title: Manacher's Algorithm
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_palindromes
    links:
    - https://judge.yosupo.jp/problem/enumerate_palindromes
  bundledCode: "#line 1 \"test/yosupo/enumerate_palindromes.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\n\n#line 2 \"string/manacher.cpp\"\
    \n#include <algorithm>\n#include <vector>\n#include <string>\n\nstd::vector<int>\
    \ manacher(const std::string& s) {\n    int n = s.size();\n    std::vector<int>\
    \ vs(2 * n - 1);\n    // odd length\n    for (int i = 0, l = 0, r = -1; i < n;\
    \ ++i) {\n        int k = (i > r) ? 1 : std::min(vs[2 * (l + r - i)], r - i +\
    \ 1);\n        while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) ++k;\n\
    \        vs[2 * i] = k;\n        --k;\n        if (i + k > r) {\n            l\
    \ = i - k;\n            r = i + k;\n        }\n    }\n    // even length\n   \
    \ for (int i = 1, l = 0, r = -1; i < n; ++i) {\n        int k = (i > r) ? 0 :\
    \ std::min(vs[2 * (l + r - i + 1) - 1], r - i + 1);\n        while (0 <= i - k\
    \ - 1 && i + k < n && s[i - k - 1] == s[i + k]) ++k;\n        vs[2 * i - 1] =\
    \ k;\n        --k;\n        if (i + k > r) {\n            l = i - k - 1;\n   \
    \         r = i + k;\n        }\n    }\n    return vs;\n}\n#line 4 \"test/yosupo/enumerate_palindromes.test.cpp\"\
    \n\n#include <bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\n\
    int main() {\n    ios_base::sync_with_stdio(false);\n    cin.tie(nullptr);\n\n\
    \    string S;\n    cin >> S;\n    auto ans = manacher(S);\n    for (int i = 0;\
    \ i < ans.size(); ++i) {\n        if (i % 2 == 0) cout << 2 * ans[i] - 1;\n  \
    \      else cout << 2 * ans[i];\n        if (i < ans.size() - 1) cout << \" \"\
    ;\n        else cout << endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_palindromes\"\
    \n\n#include \"../../string/manacher.cpp\"\n\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\nusing ll = long long;\n\nint main() {\n    ios_base::sync_with_stdio(false);\n\
    \    cin.tie(nullptr);\n\n    string S;\n    cin >> S;\n    auto ans = manacher(S);\n\
    \    for (int i = 0; i < ans.size(); ++i) {\n        if (i % 2 == 0) cout << 2\
    \ * ans[i] - 1;\n        else cout << 2 * ans[i];\n        if (i < ans.size()\
    \ - 1) cout << \" \";\n        else cout << endl;\n    }\n}\n"
  dependsOn:
  - string/manacher.cpp
  isVerificationFile: true
  path: test/yosupo/enumerate_palindromes.test.cpp
  requiredBy: []
  timestamp: '2021-01-29 21:47:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_palindromes.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_palindromes.test.cpp
- /verify/test/yosupo/enumerate_palindromes.test.cpp.html
title: test/yosupo/enumerate_palindromes.test.cpp
---
