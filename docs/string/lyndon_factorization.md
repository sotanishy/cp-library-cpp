---
title: Lyndon Factorization
documentation_of: ../../string/lyndon_factorization.hpp
---

## Description

Lyndon word とは，その任意の proper suffix よりも辞書順で真に小さいような文字列である．

任意の文字列は，単調非増加な Lyndon word の結合として一意的に分解される．この分解を Lyndon factorization という．

## Operations

- `vector<int> lyndon_factorization(string s)`
    - 文字列 $s$ を Lyndon factorization したときの，各 Lyndon word の最初の index を返す
    - 時間計算量: $O(n)$

## Reference

- [Lyndon factorization - Algorithms for Competitive Programming](https://cp-algorithms.com/string/lyndon_factorization.html)