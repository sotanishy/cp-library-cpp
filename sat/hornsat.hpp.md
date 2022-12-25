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
  bundledCode: "#line 2 \"sat/hornsat.hpp\"\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\nstd::vector<bool> horn_sat(int n_literals, const std::vector<std::pair<int,\
    \ std::vector<int>>>& clauses) {\n    const int n_clauses = clauses.size();\n\
    \    std::vector<bool> val(n_literals, false);\n    std::vector<std::vector<int>>\
    \ neg(n_clauses), idx(n_literals);\n    std::vector<int> pos(n_clauses), n_neg(n_clauses);\n\
    \n    int k = 0;\n    for (auto& [p, n] : clauses) {\n        pos[k] = p;\n  \
    \      neg[k] = n;\n        n_neg[k] = n.size();\n        for (int i : n) idx[i].push_back(k);\n\
    \        ++k;\n    }\n\n    // if there is a clause with no negative literals\
    \ and a positive literal,\n    // make it positive and remove it from other clauses.\n\
    \    // if there is no such clause, make all remaining literals negative.\n  \
    \  std::stack<int> st;\n    for (int i = 0; i < n_clauses; ++i) {\n        if\
    \ (n_neg[i] == 0 && pos[i] != -1) {\n            st.push(i);\n        }\n    }\n\
    \    while (!st.empty()) {\n        int i = st.top();\n        st.pop();\n   \
    \     if (val[pos[i]]) continue;\n        val[pos[i]] = true;\n        for (int\
    \ j : idx[pos[i]]) {\n            --n_neg[j];\n            if (n_neg[j] == 0 &&\
    \ pos[j] != -1) {\n                st.push(j);\n            }\n        }\n   \
    \ }\n    // check\n    for (int i = 0; i < n_clauses; ++i) {\n        bool v =\
    \ false;\n        if (pos[i] != -1) v |= val[pos[i]];\n        for (int j : neg[i])\
    \ v |= !val[j];\n        if (!v) {\n            // not satisfiable\n         \
    \   return {};\n        }\n    }\n    return val;\n}\n"
  code: "#pragma once\n#include <stack>\n#include <utility>\n#include <vector>\n\n\
    std::vector<bool> horn_sat(int n_literals, const std::vector<std::pair<int, std::vector<int>>>&\
    \ clauses) {\n    const int n_clauses = clauses.size();\n    std::vector<bool>\
    \ val(n_literals, false);\n    std::vector<std::vector<int>> neg(n_clauses), idx(n_literals);\n\
    \    std::vector<int> pos(n_clauses), n_neg(n_clauses);\n\n    int k = 0;\n  \
    \  for (auto& [p, n] : clauses) {\n        pos[k] = p;\n        neg[k] = n;\n\
    \        n_neg[k] = n.size();\n        for (int i : n) idx[i].push_back(k);\n\
    \        ++k;\n    }\n\n    // if there is a clause with no negative literals\
    \ and a positive literal,\n    // make it positive and remove it from other clauses.\n\
    \    // if there is no such clause, make all remaining literals negative.\n  \
    \  std::stack<int> st;\n    for (int i = 0; i < n_clauses; ++i) {\n        if\
    \ (n_neg[i] == 0 && pos[i] != -1) {\n            st.push(i);\n        }\n    }\n\
    \    while (!st.empty()) {\n        int i = st.top();\n        st.pop();\n   \
    \     if (val[pos[i]]) continue;\n        val[pos[i]] = true;\n        for (int\
    \ j : idx[pos[i]]) {\n            --n_neg[j];\n            if (n_neg[j] == 0 &&\
    \ pos[j] != -1) {\n                st.push(j);\n            }\n        }\n   \
    \ }\n    // check\n    for (int i = 0; i < n_clauses; ++i) {\n        bool v =\
    \ false;\n        if (pos[i] != -1) v |= val[pos[i]];\n        for (int j : neg[i])\
    \ v |= !val[j];\n        if (!v) {\n            // not satisfiable\n         \
    \   return {};\n        }\n    }\n    return val;\n}"
  dependsOn: []
  isVerificationFile: false
  path: sat/hornsat.hpp
  requiredBy: []
  timestamp: '2022-04-14 13:03:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: sat/hornsat.hpp
layout: document
title: Horn-SAT
---

## Description

Horn-SAT は，節内の肯定リテラル数が高々1つであるような乗法標準形の論理式に対する充足可能性問題 (SAT) である．

$(a_1 \land a_2 \land \dots \land a_n \rightarrow b)$ や $(a_1 \land a_2 \land \dots \land a_n \rightarrow \lnot b)$ といった論理式は，高々1つの肯定リテラルからなる節 (Horn 節) に変換できる．

この問題は unit-propagation によって解ける．肯定リテラルのみからなる節がない場合はすべてのリテラルを `false` にし，そのような節があればそのリテラルの値を `true` に確定し残りのリテラルについて同じ問題を解けば良い．

## Operations

- `vector<bool> horn_sat(int n_literals, vector<pair<int, vector<int>>> clauses)`
    - $n_{literals}$ リテラルを含む Horn 節のリストが与えられたとき，すべての節を充足するリテラルの真偽値の組み合わせを一つ返す．節は `{p, {n}}` の形で与え，$(p \lor \lnot n_1 \lor \dots \lor \lnot n_k)$ を追加する．肯定リテラルがない場合は `pos = -1` とする．問題が充足可能でない場合，空リストを返す．
    - 時間計算量: $O(n_{literals})$

## Reference

- [Horn-satisfiability - Wikipedia](https://en.wikipedia.org/wiki/Horn-satisfiability)
- [Horn SATのメモ - むげんのぶろぐ](https://mugen1337.hatenablog.com/entry/2021/08/22/230456)
- verify: [https://codeforces.com/gym/103202/submission/153602970](https://codeforces.com/gym/103202/submission/153602970)