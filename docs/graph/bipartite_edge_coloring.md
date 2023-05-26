---
title: Bipartite Edge Coloring
documentation_of: ../../graph/bipartite_edge_coloring.hpp
---

## Description

二部グラフの辺彩色を求める．

Kőnig's Line Coloring Theorem によると，二部グラフ $G$ の頂点の最大次数を $D$ とすると，$G$ は必ず $D$ 色で辺彩色可能である．

## Operations

- `vector<int> bipartite_edge_coloring(vector<pair<int, int>> G, int n, int m)`
    - 頂点数が $(n, m)$ の二部グラフ $G$ の最小辺彩色における各辺の色を返す
    - 時間計算量: $O(E\sqrt{V} + E\log D)$

## Note

計算量解析あってるかわからん．

正則二部グラフの完全マッチングを $O(E\log V)$ 時間で求めるアルゴリズムを用いれば，時間計算量を $O(E\log E)$ に改善できる．ただし，実測では普通に Hopcroft-Karp をやったほうが速かった．アルゴリズムについては，参考文献 (Twitter) を参照．

## Reference

- [辺彩色 - slideshare](https://www.slideshare.net/catupper/ss-25736611)
- [二部グラフの辺彩色 - ei1333の日記](https://ei1333.hateblo.jp/entry/2020/08/25/015955)
- [https://twitter.com/snuke_/status/1246630370415538176](https://twitter.com/snuke_/status/1246630370415538176)
- [Noga Alon の二部グラフの辺彩色 - 37zigenのHP](https://37zigen.com/noga-alon-edge-coloring-bipartite/)