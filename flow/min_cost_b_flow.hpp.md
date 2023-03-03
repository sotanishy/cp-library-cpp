---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/min_cost_b_flow.test.cpp
    title: test/yosupo/min_cost_b_flow.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"flow/min_cost_b_flow.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <limits>\n#include <utility>\n#include\
    \ <vector>\n\ntemplate <typename Flow, typename Cost>\nclass MinCostFlow {\n \
    \  public:\n    MinCostFlow() = default;\n    explicit MinCostFlow(int V) : V(V),\
    \ G(V), b(V), potential(V) {}\n\n    void add_supply(int v, Flow amount) { b[v]\
    \ += amount; }\n    void add_demand(int v, Flow amount) { b[v] -= amount; }\n\n\
    \    void add_edge(int u, int v, Flow lb, Flow ub, Cost cost) {\n        assert(lb\
    \ <= ub);\n        int e = G[u].size(), re = u == v ? e + 1 : G[v].size();\n \
    \       G[u].push_back({v, re, ub, 0, cost});\n        G[v].push_back({u, e, -lb,\
    \ 0, -cost});\n        edge_idx.push_back({u, e});\n    }\n\n    std::pair<bool,\
    \ Cost> min_cost_flow() {\n        // handle min flow constraints\n        for\
    \ (int v = 0; v < V; ++v) {\n            for (auto& e : G[v]) {\n            \
    \    Flow f = e.residual_cap();\n                if (f < 0) {\n              \
    \      b[v] -= f;\n                    b[e.to] += f;\n                    e.flow\
    \ += f;\n                    G[e.to][e.rev].flow -= f;\n                }\n  \
    \          }\n        }\n\n        // get max delta\n        Flow max_cap = 1;\n\
    \        for (int v = 0; v < V; ++v) {\n            for (auto& e : G[v]) max_cap\
    \ = std::max(max_cap, e.residual_cap());\n        }\n        Flow delta = 1;\n\
    \        while (delta <= max_cap) delta <<= 1;\n\n        std::vector<Cost> dist(V);\n\
    \        std::vector<int> prevv(V), preve(V);\n        using P = std::pair<Cost,\
    \ int>;\n        std::priority_queue<P, std::vector<P>, std::greater<P>> pq;\n\
    \n        for (delta >>= 1; delta > 0; delta >>= 1) {\n            // handle negative\
    \ edges\n            for (int v = 0; v < V; ++v) {\n                for (auto&\
    \ e : G[v]) {\n                    Flow f = e.residual_cap();\n              \
    \      if (f >= delta && residual_cost(v, e) < 0) {\n                        b[v]\
    \ -= f;\n                        b[e.to] += f;\n                        e.flow\
    \ += f;\n                        G[e.to][e.rev].flow -= f;\n                 \
    \   }\n                }\n            }\n\n            while (true) {\n      \
    \          // dual\n                dist.assign(V, INF);\n                prevv.assign(V,\
    \ -1);\n                preve.assign(V, -1);\n                for (int s = 0;\
    \ s < V; ++s) {\n                    if (b[s] >= delta) {\n                  \
    \      dist[s] = 0;\n                        pq.emplace(0, s);\n             \
    \       }\n                }\n                bool augment = false;\n        \
    \        Cost farthest = 0;\n                while (!pq.empty()) {\n         \
    \           auto [d, v] = pq.top();\n                    pq.pop();\n         \
    \           if (dist[v] < d) continue;\n                    farthest = d;\n  \
    \                  if (b[v] <= -delta) augment = true;\n                    for\
    \ (int i = 0; i < (int)G[v].size(); ++i) {\n                        Edge& e =\
    \ G[v][i];\n                        Cost ndist = dist[v] + residual_cost(v, e);\n\
    \                        if (e.residual_cap() >= delta && dist[e.to] > ndist)\
    \ {\n                            dist[e.to] = ndist;\n                       \
    \     prevv[e.to] = v;\n                            preve[e.to] = i;\n       \
    \                     pq.emplace(dist[e.to], e.to);\n                        }\n\
    \                    }\n                }\n\n                for (int v = 0; v\
    \ < V; ++v)\n                    potential[v] += std::min(dist[v], farthest);\n\
    \n                if (!augment) break;\n\n                // primal\n        \
    \        for (int t = 0; t < V; ++t) {\n                    if (b[t] >= 0 || dist[t]\
    \ > farthest) continue;\n\n                    Flow f = -b[t];\n             \
    \       int v;\n                    for (v = t; prevv[v] != -1 && f >= delta;\
    \ v = prevv[v]) {\n                        f = std::min(f, G[prevv[v]][preve[v]].residual_cap());\n\
    \                    }\n                    f = std::min(f, b[v]);\n\n       \
    \             if (f < delta) continue;\n                    for (v = t; prevv[v]\
    \ != -1; v = prevv[v]) {\n                        Edge& e = G[prevv[v]][preve[v]];\n\
    \                        e.flow += f;\n                        G[v][e.rev].flow\
    \ -= f;\n                    }\n\n                    b[t] += f;\n           \
    \         b[v] -= f;\n                }\n            }\n        }\n\n        Cost\
    \ res = 0;\n        for (int v = 0; v < V; ++v) {\n            for (auto& e :\
    \ G[v]) {\n                res += e.flow * e.cost;\n            }\n        }\n\
    \        res /= 2;\n\n        bool feasible = true;\n        for (int v = 0; v\
    \ < V; ++v) {\n            if (b[v] != 0) {\n                feasible = false;\n\
    \                break;\n            }\n        }\n\n        return {feasible,\
    \ res};\n    }\n\n    std::vector<Flow> get_flow() const {\n        std::vector<Flow>\
    \ ret(edge_idx.size());\n        for (int j = 0; j < (int)edge_idx.size(); ++j)\
    \ {\n            auto [v, i] = edge_idx[j];\n            ret[j] = G[v][i].flow;\n\
    \        }\n        return ret;\n    }\n\n    std::vector<Cost> get_potential()\
    \ const { return potential; }\n\n   private:\n    struct Edge {\n        int to,\
    \ rev;\n        Flow cap, flow;\n        Cost cost;\n\n        Flow residual_cap()\
    \ const { return cap - flow; }\n    };\n\n    static constexpr Cost INF = std::numeric_limits<Cost>::max()\
    \ / 2;\n\n    int V;\n    std::vector<std::vector<Edge>> G;\n    std::vector<Flow>\
    \ b;\n    std::vector<Cost> potential;\n    std::vector<std::pair<int, int>> edge_idx;\n\
    \n    Cost residual_cost(int v, const Edge& e) const {\n        return e.cost\
    \ + potential[v] - potential[e.to];\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <limits>\n#include <utility>\n#include <vector>\n\ntemplate <typename\
    \ Flow, typename Cost>\nclass MinCostFlow {\n   public:\n    MinCostFlow() = default;\n\
    \    explicit MinCostFlow(int V) : V(V), G(V), b(V), potential(V) {}\n\n    void\
    \ add_supply(int v, Flow amount) { b[v] += amount; }\n    void add_demand(int\
    \ v, Flow amount) { b[v] -= amount; }\n\n    void add_edge(int u, int v, Flow\
    \ lb, Flow ub, Cost cost) {\n        assert(lb <= ub);\n        int e = G[u].size(),\
    \ re = u == v ? e + 1 : G[v].size();\n        G[u].push_back({v, re, ub, 0, cost});\n\
    \        G[v].push_back({u, e, -lb, 0, -cost});\n        edge_idx.push_back({u,\
    \ e});\n    }\n\n    std::pair<bool, Cost> min_cost_flow() {\n        // handle\
    \ min flow constraints\n        for (int v = 0; v < V; ++v) {\n            for\
    \ (auto& e : G[v]) {\n                Flow f = e.residual_cap();\n           \
    \     if (f < 0) {\n                    b[v] -= f;\n                    b[e.to]\
    \ += f;\n                    e.flow += f;\n                    G[e.to][e.rev].flow\
    \ -= f;\n                }\n            }\n        }\n\n        // get max delta\n\
    \        Flow max_cap = 1;\n        for (int v = 0; v < V; ++v) {\n          \
    \  for (auto& e : G[v]) max_cap = std::max(max_cap, e.residual_cap());\n     \
    \   }\n        Flow delta = 1;\n        while (delta <= max_cap) delta <<= 1;\n\
    \n        std::vector<Cost> dist(V);\n        std::vector<int> prevv(V), preve(V);\n\
    \        using P = std::pair<Cost, int>;\n        std::priority_queue<P, std::vector<P>,\
    \ std::greater<P>> pq;\n\n        for (delta >>= 1; delta > 0; delta >>= 1) {\n\
    \            // handle negative edges\n            for (int v = 0; v < V; ++v)\
    \ {\n                for (auto& e : G[v]) {\n                    Flow f = e.residual_cap();\n\
    \                    if (f >= delta && residual_cost(v, e) < 0) {\n          \
    \              b[v] -= f;\n                        b[e.to] += f;\n           \
    \             e.flow += f;\n                        G[e.to][e.rev].flow -= f;\n\
    \                    }\n                }\n            }\n\n            while\
    \ (true) {\n                // dual\n                dist.assign(V, INF);\n  \
    \              prevv.assign(V, -1);\n                preve.assign(V, -1);\n  \
    \              for (int s = 0; s < V; ++s) {\n                    if (b[s] >=\
    \ delta) {\n                        dist[s] = 0;\n                        pq.emplace(0,\
    \ s);\n                    }\n                }\n                bool augment\
    \ = false;\n                Cost farthest = 0;\n                while (!pq.empty())\
    \ {\n                    auto [d, v] = pq.top();\n                    pq.pop();\n\
    \                    if (dist[v] < d) continue;\n                    farthest\
    \ = d;\n                    if (b[v] <= -delta) augment = true;\n            \
    \        for (int i = 0; i < (int)G[v].size(); ++i) {\n                      \
    \  Edge& e = G[v][i];\n                        Cost ndist = dist[v] + residual_cost(v,\
    \ e);\n                        if (e.residual_cap() >= delta && dist[e.to] > ndist)\
    \ {\n                            dist[e.to] = ndist;\n                       \
    \     prevv[e.to] = v;\n                            preve[e.to] = i;\n       \
    \                     pq.emplace(dist[e.to], e.to);\n                        }\n\
    \                    }\n                }\n\n                for (int v = 0; v\
    \ < V; ++v)\n                    potential[v] += std::min(dist[v], farthest);\n\
    \n                if (!augment) break;\n\n                // primal\n        \
    \        for (int t = 0; t < V; ++t) {\n                    if (b[t] >= 0 || dist[t]\
    \ > farthest) continue;\n\n                    Flow f = -b[t];\n             \
    \       int v;\n                    for (v = t; prevv[v] != -1 && f >= delta;\
    \ v = prevv[v]) {\n                        f = std::min(f, G[prevv[v]][preve[v]].residual_cap());\n\
    \                    }\n                    f = std::min(f, b[v]);\n\n       \
    \             if (f < delta) continue;\n                    for (v = t; prevv[v]\
    \ != -1; v = prevv[v]) {\n                        Edge& e = G[prevv[v]][preve[v]];\n\
    \                        e.flow += f;\n                        G[v][e.rev].flow\
    \ -= f;\n                    }\n\n                    b[t] += f;\n           \
    \         b[v] -= f;\n                }\n            }\n        }\n\n        Cost\
    \ res = 0;\n        for (int v = 0; v < V; ++v) {\n            for (auto& e :\
    \ G[v]) {\n                res += e.flow * e.cost;\n            }\n        }\n\
    \        res /= 2;\n\n        bool feasible = true;\n        for (int v = 0; v\
    \ < V; ++v) {\n            if (b[v] != 0) {\n                feasible = false;\n\
    \                break;\n            }\n        }\n\n        return {feasible,\
    \ res};\n    }\n\n    std::vector<Flow> get_flow() const {\n        std::vector<Flow>\
    \ ret(edge_idx.size());\n        for (int j = 0; j < (int)edge_idx.size(); ++j)\
    \ {\n            auto [v, i] = edge_idx[j];\n            ret[j] = G[v][i].flow;\n\
    \        }\n        return ret;\n    }\n\n    std::vector<Cost> get_potential()\
    \ const { return potential; }\n\n   private:\n    struct Edge {\n        int to,\
    \ rev;\n        Flow cap, flow;\n        Cost cost;\n\n        Flow residual_cap()\
    \ const { return cap - flow; }\n    };\n\n    static constexpr Cost INF = std::numeric_limits<Cost>::max()\
    \ / 2;\n\n    int V;\n    std::vector<std::vector<Edge>> G;\n    std::vector<Flow>\
    \ b;\n    std::vector<Cost> potential;\n    std::vector<std::pair<int, int>> edge_idx;\n\
    \n    Cost residual_cost(int v, const Edge& e) const {\n        return e.cost\
    \ + potential[v] - potential[e.to];\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/min_cost_b_flow.hpp
  requiredBy: []
  timestamp: '2023-01-01 16:25:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/min_cost_b_flow.test.cpp
documentation_of: flow/min_cost_b_flow.hpp
layout: document
title: Minimum Cost b-flow
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