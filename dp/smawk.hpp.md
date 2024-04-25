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
  bundledCode: "#line 2 \"dp/smawk.hpp\"\n#include <algorithm>\n#include <vector>\n\
    \ntemplate <typename F>\nstd::vector<int> smawk(int n, int m, F f) {\n    auto\
    \ calc = [&](auto& calc, const std::vector<int>& row,\n                    const\
    \ std::vector<int>& col) -> std::vector<int> {\n        const int r = row.size();\n\
    \        if (r == 0) return {};\n\n        // reduce\n        std::vector<int>\
    \ c2;\n        for (int c : col) {\n            while (!c2.empty() && f(row[c2.size()\
    \ - 1], c2.back()) >\n                                      f(row[c2.size() -\
    \ 1], c)) {\n                c2.pop_back();\n            }\n            if ((int)c2.size()\
    \ < r) {\n                c2.push_back(c);\n            }\n        }\n\n     \
    \   // interpolate\n        std::vector<int> r2;\n        for (int i = 1; i <\
    \ r; i += 2) {\n            r2.push_back(row[i]);\n        }\n        auto a2\
    \ = calc(calc, r2, c2);\n        std::vector<int> ans(r);\n        for (int i\
    \ = 0; i < (int)a2.size(); ++i) {\n            ans[2 * i + 1] = a2[i];\n     \
    \   }\n        int j = 0;\n        for (int i = 0; i < r; i += 2) {\n        \
    \    ans[i] = c2[j];\n            int end = (i == r - 1 ? c2.back() : ans[i +\
    \ 1]);\n            while (c2[j] < end) {\n                ++j;\n            \
    \    if (f(row[i], ans[i]) > f(row[i], c2[j])) {\n                    ans[i] =\
    \ c2[j];\n                }\n            }\n        }\n        return ans;\n \
    \   };\n\n    std::vector<int> row(n), col(m);\n    std::iota(row.begin(), row.end(),\
    \ 0);\n    std::iota(col.begin(), col.end(), 0);\n    return calc(calc, row, col);\n\
    }\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n\ntemplate <typename\
    \ F>\nstd::vector<int> smawk(int n, int m, F f) {\n    auto calc = [&](auto& calc,\
    \ const std::vector<int>& row,\n                    const std::vector<int>& col)\
    \ -> std::vector<int> {\n        const int r = row.size();\n        if (r == 0)\
    \ return {};\n\n        // reduce\n        std::vector<int> c2;\n        for (int\
    \ c : col) {\n            while (!c2.empty() && f(row[c2.size() - 1], c2.back())\
    \ >\n                                      f(row[c2.size() - 1], c)) {\n     \
    \           c2.pop_back();\n            }\n            if ((int)c2.size() < r)\
    \ {\n                c2.push_back(c);\n            }\n        }\n\n        //\
    \ interpolate\n        std::vector<int> r2;\n        for (int i = 1; i < r; i\
    \ += 2) {\n            r2.push_back(row[i]);\n        }\n        auto a2 = calc(calc,\
    \ r2, c2);\n        std::vector<int> ans(r);\n        for (int i = 0; i < (int)a2.size();\
    \ ++i) {\n            ans[2 * i + 1] = a2[i];\n        }\n        int j = 0;\n\
    \        for (int i = 0; i < r; i += 2) {\n            ans[i] = c2[j];\n     \
    \       int end = (i == r - 1 ? c2.back() : ans[i + 1]);\n            while (c2[j]\
    \ < end) {\n                ++j;\n                if (f(row[i], ans[i]) > f(row[i],\
    \ c2[j])) {\n                    ans[i] = c2[j];\n                }\n        \
    \    }\n        }\n        return ans;\n    };\n\n    std::vector<int> row(n),\
    \ col(m);\n    std::iota(row.begin(), row.end(), 0);\n    std::iota(col.begin(),\
    \ col.end(), 0);\n    return calc(calc, row, col);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: dp/smawk.hpp
  requiredBy: []
  timestamp: '2024-01-08 01:32:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: dp/smawk.hpp
layout: document
title: SMAWK Algorithm
---

## Description

SMAWK algorithm は，totally monotone 行列の各行の argmin を高速に求めるアルゴリズムである．

単に monotone の場合は monotone minima が使える．

- `vector<int> smawk(int n, int m, F f)`
    - $A_{i,j}=f(i,j)$ である $n \times m$ 行列 $A$ の各行の argmin を求める
    - 時間計算量: $O(n + m)$

## Note

多分壊れてる．monotone minima使って

## Reference

- [Totally Monotone Matrix Searching (SMAWK algorithm)](https://topcoder-g-hatena-ne-jp.jag-icpc.org/spaghetti_source/20120923/)
- [The SMAWK Algorithm](http://web.cs.unlv.edu/larmore/Courses/CSC477/monge.pdf)
- [SMAWK Algorithm](https://noshi91.github.io/Library/algorithm/smawk.cpp.html)