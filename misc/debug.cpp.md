---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"misc/debug.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <typename T, typename U>\nstring to_string(const pair<T, U>&\
    \ p) {\n    return \"(\" + to_string(p.first) + \", \" + to_string(p.second) +\
    \ \")\";\n}\n\ntemplate <typename T>\nstring to_string(const T& v) {\n    bool\
    \ first = true;\n    string res = \"{\";\n    for (const auto& x : v) {\n    \
    \    if (!first) res += \", \";\n        first = false;\n        res += to_string(x);\n\
    \    }\n    res += \"}\";\n    return res;\n}\n\nvoid debug_out() {\n    cerr\
    \ << endl;\n}\n\ntemplate <typename Head, typename... Tail>\nvoid debug_out(Head\
    \ H, Tail... T) {\n    cerr << \" \" << to_string(H);\n    debug_out(T...);\n\
    }\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T, typename\
    \ U>\nstring to_string(const pair<T, U>& p) {\n    return \"(\" + to_string(p.first)\
    \ + \", \" + to_string(p.second) + \")\";\n}\n\ntemplate <typename T>\nstring\
    \ to_string(const T& v) {\n    bool first = true;\n    string res = \"{\";\n \
    \   for (const auto& x : v) {\n        if (!first) res += \", \";\n        first\
    \ = false;\n        res += to_string(x);\n    }\n    res += \"}\";\n    return\
    \ res;\n}\n\nvoid debug_out() {\n    cerr << endl;\n}\n\ntemplate <typename Head,\
    \ typename... Tail>\nvoid debug_out(Head H, Tail... T) {\n    cerr << \" \" <<\
    \ to_string(H);\n    debug_out(T...);\n}"
  dependsOn: []
  isVerificationFile: false
  path: misc/debug.cpp
  requiredBy: []
  timestamp: '2020-09-22 15:17:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/debug.cpp
layout: document
redirect_from:
- /library/misc/debug.cpp
- /library/misc/debug.cpp.html
title: misc/debug.cpp
---
