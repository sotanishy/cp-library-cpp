---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Median Set
    links: []
  bundledCode: "#line 2 \"misc/median_set.cpp\"\n#include <set>\n\n/**\n * @brief\
    \ Median Set\n */\ntemplate <typename T>\nclass MedianSet {\npublic:\n    void\
    \ insert(T x) {\n        if (x < *right.begin()) {\n            left.insert(x);\n\
    \        } else {\n            right.insert(x);\n        }\n        balance();\n\
    \    }\n\n    void erase(T x) {\n        if (x < *right.begin()) {\n         \
    \   left.erase(x);\n        } else {\n            right.erase(x);\n        }\n\
    \        balance();\n    }\n\n    T median() const {\n        if (left.size()\
    \ > right.size()) {\n            return *left.rbegin();\n        } else {\n  \
    \          return (*left.rbegin() + *right.begin()) / 2;\n        }\n    }\n\n\
    private:\n    std::set<T> left, right;\n\n    void balance() {\n        while\
    \ (left.size() < right.size()) {\n            left.insert(*right.begin());\n \
    \           right.erase(right.begin());\n        }\n        while (left.size()\
    \ > right.size() + 1) {\n            right.insert(*left.rbegin());\n         \
    \   left.erase(left.rbegin());\n        }\n    }\n};\n"
  code: "#pragma once\n#include <set>\n\n/**\n * @brief Median Set\n */\ntemplate\
    \ <typename T>\nclass MedianSet {\npublic:\n    void insert(T x) {\n        if\
    \ (x < *right.begin()) {\n            left.insert(x);\n        } else {\n    \
    \        right.insert(x);\n        }\n        balance();\n    }\n\n    void erase(T\
    \ x) {\n        if (x < *right.begin()) {\n            left.erase(x);\n      \
    \  } else {\n            right.erase(x);\n        }\n        balance();\n    }\n\
    \n    T median() const {\n        if (left.size() > right.size()) {\n        \
    \    return *left.rbegin();\n        } else {\n            return (*left.rbegin()\
    \ + *right.begin()) / 2;\n        }\n    }\n\nprivate:\n    std::set<T> left,\
    \ right;\n\n    void balance() {\n        while (left.size() < right.size()) {\n\
    \            left.insert(*right.begin());\n            right.erase(right.begin());\n\
    \        }\n        while (left.size() > right.size() + 1) {\n            right.insert(*left.rbegin());\n\
    \            left.erase(left.rbegin());\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/median_set.cpp
  requiredBy: []
  timestamp: '2022-03-07 20:52:41+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/median_set.cpp
layout: document
redirect_from:
- /library/misc/median_set.cpp
- /library/misc/median_set.cpp.html
title: Median Set
---
