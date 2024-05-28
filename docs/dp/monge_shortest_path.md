---
title: Monge Shortest Path
documentation_of: ../../dp/monge_shortest_path.hpp
---

## Description

Monge な辺重みを持つ完全 DAG 上の最短距離を求める．この問題は LARSCH algorithm によって $O(N)$ 時間で解けるが，この実装ではより実装が簡単で定数倍高速な $O(N \log N)$ 時間の簡易版 LARSCH algorithm を用いている．

- `vector<T> monge_shortest_path(int n, F cost)`
    - 辺 $(i,j)$ の重みが $\mathrm{cost}(i,j)$ で与えられる $n$ 頂点完全 DAG の頂点 $0$ から各頂点への最短距離を返す
    - 時間計算量: $O(n \log n)$

## Reference

- [簡易版 LARSCH Algorithm - noshi91のメモ](https://noshi91.hatenablog.com/entry/2023/02/18/005856)
- verify: [https://atcoder.jp/contests/abc355/submissions/53788299](https://atcoder.jp/contests/abc355/submissions/53788299)