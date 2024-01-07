---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Sum of Top K Values
    links: []
  bundledCode: "#line 2 \"misc/sum_top_k.hpp\"\n#include <set>\n#include <vector>\n\
    \n/**\n * @brief Sum of Top K Values\n */\n\ntemplate <typename T>\nclass SumTopK\
    \ {\n   public:\n    SumTopK() = default;\n    explicit SumTopK(int k) : k(k)\
    \ {}\n\n    void insert(T x) {\n        small.insert(x);\n        sumsmall +=\
    \ x;\n        fix();\n    }\n\n    void erase(T x) {\n        if (small.contains(x))\
    \ {\n            small.erase(small.find(x));\n            sumsmall -= x;\n   \
    \     } else {\n            assert(big.contains(x));\n            big.erase(big.find(x));\n\
    \            sumbig -= x;\n        }\n        fix();\n    }\n\n    T sum_big()\
    \ const { return sumbig; }\n\n    T sum_small() const { return sumsmall; }\n\n\
    \   private:\n    std::multiset<T> small, big;\n    T sumsmall = 0, sumbig = 0;\n\
    \    int k;\n\n    void fix() {\n        while (!small.empty() && !big.empty()\
    \ &&\n               *small.rbegin() > *big.begin()) {\n            auto st =\
    \ --small.end();\n            auto bt = big.begin();\n            auto sv = *st,\
    \ bv = *bt;\n            sumsmall -= sv, sumsmall += bv;\n            sumbig -=\
    \ bv, sumbig += sv;\n            small.erase(st), small.insert(bv);\n        \
    \    big.erase(bt), big.insert(sv);\n        }\n        while (!small.empty()\
    \ && big.size() < k) {\n            auto st = --small.end();\n            auto\
    \ sv = *st;\n            sumsmall -= sv;\n            sumbig += sv;\n        \
    \    small.erase(st);\n            big.insert(sv);\n        }\n        while (big.size()\
    \ > k) {\n            auto bt = big.begin();\n            auto bv = *bt;\n   \
    \         sumsmall += bv;\n            sumbig -= bv;\n            big.erase(bt);\n\
    \            small.insert(bv);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <set>\n#include <vector>\n\n/**\n * @brief Sum of\
    \ Top K Values\n */\n\ntemplate <typename T>\nclass SumTopK {\n   public:\n  \
    \  SumTopK() = default;\n    explicit SumTopK(int k) : k(k) {}\n\n    void insert(T\
    \ x) {\n        small.insert(x);\n        sumsmall += x;\n        fix();\n   \
    \ }\n\n    void erase(T x) {\n        if (small.contains(x)) {\n            small.erase(small.find(x));\n\
    \            sumsmall -= x;\n        } else {\n            assert(big.contains(x));\n\
    \            big.erase(big.find(x));\n            sumbig -= x;\n        }\n  \
    \      fix();\n    }\n\n    T sum_big() const { return sumbig; }\n\n    T sum_small()\
    \ const { return sumsmall; }\n\n   private:\n    std::multiset<T> small, big;\n\
    \    T sumsmall = 0, sumbig = 0;\n    int k;\n\n    void fix() {\n        while\
    \ (!small.empty() && !big.empty() &&\n               *small.rbegin() > *big.begin())\
    \ {\n            auto st = --small.end();\n            auto bt = big.begin();\n\
    \            auto sv = *st, bv = *bt;\n            sumsmall -= sv, sumsmall +=\
    \ bv;\n            sumbig -= bv, sumbig += sv;\n            small.erase(st), small.insert(bv);\n\
    \            big.erase(bt), big.insert(sv);\n        }\n        while (!small.empty()\
    \ && big.size() < k) {\n            auto st = --small.end();\n            auto\
    \ sv = *st;\n            sumsmall -= sv;\n            sumbig += sv;\n        \
    \    small.erase(st);\n            big.insert(sv);\n        }\n        while (big.size()\
    \ > k) {\n            auto bt = big.begin();\n            auto bv = *bt;\n   \
    \         sumsmall += bv;\n            sumbig -= bv;\n            big.erase(bt);\n\
    \            small.insert(bv);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/sum_top_k.hpp
  requiredBy: []
  timestamp: '2024-01-08 00:27:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/sum_top_k.hpp
layout: document
redirect_from:
- /library/misc/sum_top_k.hpp
- /library/misc/sum_top_k.hpp.html
title: Sum of Top K Values
---
