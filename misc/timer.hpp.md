---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/timer.hpp\"\n#include <chrono>\n\nclass Timer {\n \
    \  public:\n    void start() { start_time = std::chrono::steady_clock::now();\
    \ }\n\n    long long get_time() const {\n        auto cur_time = std::chrono::steady_clock::now();\n\
    \        return std::chrono::duration_cast<std::chrono::milliseconds>(cur_time\
    \ -\n                                                                     start_time)\n\
    \            .count();\n    }\n\n   private:\n    std::chrono::steady_clock::time_point\
    \ start_time;\n};\n"
  code: "#pragma once\n#include <chrono>\n\nclass Timer {\n   public:\n    void start()\
    \ { start_time = std::chrono::steady_clock::now(); }\n\n    long long get_time()\
    \ const {\n        auto cur_time = std::chrono::steady_clock::now();\n       \
    \ return std::chrono::duration_cast<std::chrono::milliseconds>(cur_time -\n  \
    \                                                                   start_time)\n\
    \            .count();\n    }\n\n   private:\n    std::chrono::steady_clock::time_point\
    \ start_time;\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
