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


# :heavy_check_mark: Dijkstra's Algorithm <small>(graph/dijkstra.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dijkstra.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 22:35:33+09:00




# Dijkstra's Algorithm

Dijkstra's algorithm is an algorithm for finding the shortest paths from a single source vertex to all other vertices in a weighted graph without negative edges.

- `vector<T> dijkstra(vector<vector<Edge<T>>>& G, int s)`
    - Returns the shortest distance from the source vertex $s$ to all vertices in the graph $G$, given its adjacency list.
    - Time complexity: $O(E \lg V)$

## Depends on

* :question: <a href="edge.cpp.html">graph/edge.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include "edge.cpp"
using namespace std;

/*
 * @brief Dijkstra's Algorithm
 * @docs docs/graph/dijkstra.md
 */
template <typename T>
vector<T> dijkstra(vector<vector<Edge<T>>>& G, int s) {
    const T INF = numeric_limits<T>::max();
    vector<T> dist(G.size(), INF);
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
#line 2 "graph/edge.cpp"
using namespace std;

template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};
#line 3 "graph/dijkstra.cpp"
using namespace std;

/*
 * @brief Dijkstra's Algorithm
 * @docs docs/graph/dijkstra.md
 */
template <typename T>
vector<T> dijkstra(vector<vector<Edge<T>>>& G, int s) {
    const T INF = numeric_limits<T>::max();
    vector<T> dist(G.size(), INF);
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

