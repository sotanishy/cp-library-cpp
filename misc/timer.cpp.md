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
  bundledCode: "#line 1 \"misc/timer.cpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct Timer {\n    chrono::steady_clock::time_point start_time;\n\n\
    \    void start() {\n        start_time = chrono::steady_clock::now();\n    }\n\
    \n    long long get_time() {\n        auto cur_time = chrono::steady_clock::now();\n\
    \        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();\n\
    \    }\n};\n"
  code: "#include <bits/stdc++.h>\nusing namespace std;\n\nstruct Timer {\n    chrono::steady_clock::time_point\
    \ start_time;\n\n    void start() {\n        start_time = chrono::steady_clock::now();\n\
    \    }\n\n    long long get_time() {\n        auto cur_time = chrono::steady_clock::now();\n\
    \        return chrono::duration_cast<chrono::milliseconds>(cur_time - start_time).count();\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.cpp
  requiredBy: []
  timestamp: '2020-08-31 09:52:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.cpp
layout: document
redirect_from:
- /library/misc/timer.cpp
- /library/misc/timer.cpp.html
title: misc/timer.cpp
---
