---
title: Minimum Bounding Circle
documentation_of: ../../geometry/minimum_bounding_circle.hpp
---

## Description

与えられた点群の最小包含円を求める．Welzl のアルゴリズムを用いている．

## Operations

- `Circle minimum_bounding_circle(vector<Vec> pts)`
    - `pts` の最小包含円を返す
    - 時間計算量: $\mathrm{expected}\ O(n)$

## Reference

- [Smallest circle problem - Wikipedia](https://en.wikipedia.org/wiki/Smallest-circle_problem)
- verify: [https://atcoder.jp/contests/abc151/submissions/31596027](https://atcoder.jp/contests/abc151/submissions/31596027)

