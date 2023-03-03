---
title: Minimum Cost b-flow
documentation_of: ../../flow/min_cost_b_flow.hpp
---

## Description

フローネットワークの最小費用 b-フローを求める．この実装では，容量スケーリング法を用いている．

最小費用 s-t フローは頂点 $s$ から頂点 $t$ に流すというイメージだが，最小費用 b-フローは各頂点に湧き出し量と吸い込み量が定まっており，頂点間でフローをやり取りして過不足をなくすというイメージがある．

より形式的には，最小費用 b-フローは以下の線形計画問題として定式化される．

$$
\begin{align*}
\text{minimize } & \sum_e c_e f_e \\
\text{subject to } & l_e \leq f_e \leq u_e & \forall e \\
& \sum_{e\in \delta^+(v)} f_e - \sum_{e\in \delta^-(v)} f_e = b_v & \forall v
\end{align*}
$$

## Operations

- `MinCostFlow(int V)`
    - グラフを $V$ 頂点で初期化する
    - 時間計算量: $O(V)$
- `void add_edge(int u, int v, Flow lb, Flow ub, Cost cost)`
    - 最小流量 $lb$, 容量 $ub$，コスト $cost$ の辺 $(u, v)$ を追加する
- `void add_supply(int v, Flow amount)`
    - 頂点 $v$ に湧き出しを追加する
- `void add_demand(int v, Flow amount)`
    - 頂点 $v$ に吸い込みを追加する
- `pair<bool, Flow> min_cost_flow()`
    - 最小費用 b-フローを求める．問題が infeasible ならペアの第一要素は `false` となる．
    - 時間計算量: $O(fE\log V)$
- `vector<Flow> get_flow()`
    - 各辺の流量を返す
- `vector<Cost> get_potential()`
    - 各頂点のポテンシャルを返す

## Note

[最小費用 s-t フロー](min_cost_flow.md) とできることがあまり変わらないが，b-フローによる定式化のほうが
- 負辺，負閉路，最小流量制約の扱いが楽
- フローの復元が楽

という利点がある．

- 流量が任意の場合
    - $t$ から $s$ に容量 $\infty$，コスト $0$ の辺を貼れば良い．
- 最小費用最大流を求める場合
    - 参考文献を参照

## Reference

- [ぼくの考えたさいきょうのフローライブラリ - みさわめも](https://misawa.github.io/others/flow/library_design.html)
- [容量スケーリング法のすゝめ - みさわめも](https://misawa.github.io/others/flow/lets_use_capacity_scaling.html)