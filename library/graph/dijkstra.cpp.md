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
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: graph/dijkstra.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;

    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}

    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template <typename T>
vector<T> dijkstra(vector<vector<Edge<T>>>& G, int V, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(V, INF);
    dist[s] = 0;
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        T cost;
        int v;
        tie(cost, v) = pq.top();
        pq.pop();
        if (dist[v] < cost) continue;
        for (auto& e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }

    return dist;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/dijkstra.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;

    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}

    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template <typename T>
vector<T> dijkstra(vector<vector<Edge<T>>>& G, int V, int s) {
    const auto INF = numeric_limits<T>::max();
    vector<T> dist(V, INF);
    dist[s] = 0;
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, s);

    while (!pq.empty()) {
        T cost;
        int v;
        tie(cost, v) = pq.top();
        pq.pop();
        if (dist[v] < cost) continue;
        for (auto& e : G[v]) {
            if (dist[e.to] > dist[v] + e.cost) {
                dist[e.to] = dist[v] + e.cost;
                pq.emplace(dist[e.to], e.to);
            }
        }
    }

    return dist;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

