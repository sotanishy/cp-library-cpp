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


# :heavy_check_mark: test/aoj/GRL_1_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 22:35:33+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/bellman_ford.cpp.html">Bellman-Ford Algorithm <small>(graph/bellman_ford.cpp)</small></a>
* :question: <a href="../../../library/graph/edge.cpp.html">graph/edge.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#include "../../graph/bellman_ford.cpp"

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, r;
    cin >> V >> E >> r;
    vector<Edge<int>> G;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G.push_back({s, t, d});
    }
    auto dist = bellman_ford(G, V, r);
    if (dist.size() == 0) cout << "NEGATIVE CYCLE\n";
    else {
        for (int i = 0; i < V; i++) {
            if (dist[i] < INF) cout << dist[i] << "\n";
            else cout << "INF\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"

#line 1 "graph/bellman_ford.cpp"
#include <bits/stdc++.h>
#line 2 "graph/edge.cpp"
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};
#line 3 "graph/bellman_ford.cpp"
using namespace std;

/*
 * @brief Bellman-Ford Algorithm
 * @docs docs/graph/bellman_ford.md
 */
template <typename T>
vector<T> bellman_ford(vector<Edge<T>>& G, int V, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<int> dist(V, INF);
    dist[s] = 0;
    for (int i = 0; i < V; i++) {
        for (auto& e : G) {
            if (dist[e.from] != INF && dist[e.to] > dist[e.from] + e.cost) {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == V - 1) return vector<T>();
            }
        }
    }
    return dist;
}
#line 4 "test/aoj/GRL_1_B.test.cpp"

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E, r;
    cin >> V >> E >> r;
    vector<Edge<int>> G;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        G.push_back({s, t, d});
    }
    auto dist = bellman_ford(G, V, r);
    if (dist.size() == 0) cout << "NEGATIVE CYCLE\n";
    else {
        for (int i = 0; i < V; i++) {
            if (dist[i] < INF) cout << dist[i] << "\n";
            else cout << "INF\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

