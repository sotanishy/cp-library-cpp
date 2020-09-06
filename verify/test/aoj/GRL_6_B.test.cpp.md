---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/GRL_6_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 04:14:56+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/flow/min_cost_flow.cpp.html">flow/min_cost_flow.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#include "../../flow/min_cost_flow.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, F;
    cin >> V >> E >> F;
    MinCostFlow<int, int> mcf(V);
    for (int i = 0; i < E; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        mcf.add_edge(u, v, c, d);
    }
    cout << mcf.min_cost_flow(0, V - 1, F) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_6_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"

#line 1 "flow/min_cost_flow.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename TF, typename TC>
struct MinCostFlow {
    struct Edge {
        int to;
        TF cap;
        TC cost;
        int rev;
        Edge(int to, TF cap, TC cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}
    };

    const TC INF = numeric_limits<TC>::max();

    int V;
    vector<vector<Edge>> G;

    MinCostFlow(int V) : V(V), G(V) {}

    void add_edge(int u, int v, TF cap, TC cost) {
        G[u].emplace_back(v, cap, cost, G[v].size());
        G[v].emplace_back(u, 0, -cost, G[u].size() - 1);
    }

    TC min_cost_flow(int s, int t, TF f) {
        int ret = 0;
        vector<TC> dist(V), h(V);
        vector<int> prevv(V), preve(V);
        using P = pair<TC, int>;
        priority_queue<P, vector<P>, greater<P>> pq;

        while (f > 0) {
            // update h using dijkstra
            fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            pq.emplace(0, s);
            while (!pq.empty()) {
                TC d;
                int v;
                tie(d, v) = pq.top();
                pq.pop();
                if (dist[v] < d) continue;
                for (int i = 0; i < G[v].size(); i++) {
                    Edge& e = G[v][i];
                    TC ndist = dist[v] + e.cost + h[v] - h[e.to];
                    if (e.cap > 0 && dist[e.to] > ndist) {
                        dist[e.to] = ndist;
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.emplace(dist[e.to], e.to);
                    }
                }
            }

            if (dist[t] == INF) return -1;
            for (int v = 0; v < V; v++) h[v] += dist[v];

            TF m = f;
            int v = t;
            for (int v = t; v != s; v = prevv[v]) {
                m = min(m, G[prevv[v]][preve[v]].cap);
            }
            f -= m;
            ret += m * h[t];
            for (int v = t; v != s; v = prevv[v]) {
                Edge& e = G[prevv[v]][preve[v]];
                e.cap -= m;
                G[v][e.rev].cap += m;
            }
        }
        return ret;
    }
};
#line 4 "test/aoj/GRL_6_B.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, F;
    cin >> V >> E >> F;
    MinCostFlow<int, int> mcf(V);
    for (int i = 0; i < E; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        mcf.add_edge(u, v, c, d);
    }
    cout << mcf.min_cost_flow(0, V - 1, F) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

