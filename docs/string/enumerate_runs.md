---
title: Enumerate Runs
documentation_of: ../../string/enumerate_runs.hpp
---

## Description

文字列の run (部分文字列の繰り返しであって，長さが極大のもの) を列挙する．この実装では Main-Lorentz アルゴリズムを用いている．

## Operations

- `vector<vector<pair<int, int>> enumerate_runs(string s)`
    - 文字列 $s$ の run を列挙する．`ret[p]` には周期 $p$ の run が含まれている．
    - 時間計算量: $O(n\log n)$

## Reference

- [Runの列挙 (Main-Lorentz algorithm)](https://pazzle1230.hatenablog.com/entry/2019/11/27/234632)
