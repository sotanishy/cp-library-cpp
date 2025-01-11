---
title: Convex Hull
documentation_of: ../../geometry/convex_hull.hpp
---

## Description

与えられた点の凸包を求める．この実装では Graham scan アルゴリズムを用いている．

## Operations

- `vector<Vec> convex_hull(vector<Vec> pts, bool strict = true)`
    - `pts` の凸包の境界の頂点を返す． `strict = true` ならば，凸包の頂点のみ返す．
    - 時間計算量: $O(n\log n)$