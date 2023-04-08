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
  bundledCode: "#line 2 \"misc/discrete_log_monoid_action.hpp\"\n#include <unordered_set>\n\
    \ntemplate <typename M, typename S, S (*act)(typename M::T, S)>\nint discrete_log_monoid_action(typename\
    \ M::T x, S s, S t, long long N) {\n    using T = typename M::T;\n\n    // baby-step\n\
    \    const int m = sqrt(N) + 1;\n    std::unordered_set<S> babies;\n    S baby\
    \ = t;\n    for (int i = 1; i <= m; ++i) {\n        baby = act(x, baby);\n   \
    \     babies.insert(baby);\n    }\n\n    // giant-step\n    T xm = M::id(), y\
    \ = x;\n    int m_ = m;\n    while (m_) {\n        if (m_ & 1) xm = M::op(xm,\
    \ y);\n        y = M::op(y, y);\n        m_ >>= 1;\n    }\n\n    S giant = s;\n\
    \    bool first = true;\n    for (int i = 0; i <= N / m; ++i) {\n        if (babies.count(act(xm,\
    \ giant))) {\n            S u = giant;\n            for (int j = 0; j < m; ++j)\
    \ {\n                if (u == t) {\n                    return m * i + j;\n  \
    \              }\n                u = act(x, u);\n            }\n            if\
    \ (!first) return -1;\n            first = false;\n        }\n        giant =\
    \ act(xm, giant);\n    }\n    return -1;\n}\n"
  code: "#pragma once\n#include <unordered_set>\n\ntemplate <typename M, typename\
    \ S, S (*act)(typename M::T, S)>\nint discrete_log_monoid_action(typename M::T\
    \ x, S s, S t, long long N) {\n    using T = typename M::T;\n\n    // baby-step\n\
    \    const int m = sqrt(N) + 1;\n    std::unordered_set<S> babies;\n    S baby\
    \ = t;\n    for (int i = 1; i <= m; ++i) {\n        baby = act(x, baby);\n   \
    \     babies.insert(baby);\n    }\n\n    // giant-step\n    T xm = M::id(), y\
    \ = x;\n    int m_ = m;\n    while (m_) {\n        if (m_ & 1) xm = M::op(xm,\
    \ y);\n        y = M::op(y, y);\n        m_ >>= 1;\n    }\n\n    S giant = s;\n\
    \    bool first = true;\n    for (int i = 0; i <= N / m; ++i) {\n        if (babies.count(act(xm,\
    \ giant))) {\n            S u = giant;\n            for (int j = 0; j < m; ++j)\
    \ {\n                if (u == t) {\n                    return m * i + j;\n  \
    \              }\n                u = act(x, u);\n            }\n            if\
    \ (!first) return -1;\n            first = false;\n        }\n        giant =\
    \ act(xm, giant);\n    }\n    return -1;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/discrete_log_monoid_action.hpp
  requiredBy: []
  timestamp: '2023-04-08 13:57:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/discrete_log_monoid_action.hpp
layout: document
redirect_from:
- /library/misc/discrete_log_monoid_action.hpp
- /library/misc/discrete_log_monoid_action.hpp.html
title: misc/discrete_log_monoid_action.hpp
---
