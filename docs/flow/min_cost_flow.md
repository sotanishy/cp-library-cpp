---
title: Minimum Cost Flow
documentation_of: ../../flow/min_cost_flow.cpp
---

## Description

フローネットワークの最小費用流を求める．この実装では，primal-dual 法を用いている．

## Operations

- `MinCostFlow(int V)`
    - グラフを $V$ 頂点で初期化する
    - 時間計算量: $O(V)$
- `void add_edge(int u, int v, Cap cap, Cost cost)`
    - 容量 $cap$，コスト $cost$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `void add_edge(int u, int v, Cap lb, Cap ub, Cost cost)`
    - 最小流量 $lb$, 容量 $ub$，コスト $cost$ の辺 $(u, v)$ を追加する
    - 時間計算量: $O(1)$
- `Cost min_cost_flow(int s, int t, Cap f, bool arbitrary)`
    - 始点 $s$ から終点 $t$ への流量 $f$ の最小費用流を求める．`arbitrary == true` の場合，流量は $f$ 以下の任意の値とする．
    - 時間計算量: $O(fE\log V)$

## Note

このライブラリがそのまま使える場合は，すべての辺のコストが非負である普通の最小費用流のとき．以下，いろいろな状況での使い方を説明する．

- 負辺がある場合
    - ポテンシャルの初期値の計算に，負辺があっても動作する最短路アルゴリズムを用いる必要がある．Bellman-Ford algorithm を用いることができる．また，グラフがDAGである場合は，トポロジカルソートしてDPすることができる．`calculate_initial_potential()`という private メソッドを用意しているのでその中を自分で書き換える．
    - 蟻本に載っているテク（超頂点を作って頑張る）を用いて負辺を除去することもできる．
- 負閉路がある場合
    - Bellman-Ford algorithm で負閉路を見つけてそこに流せるだけ流しておけば良い．