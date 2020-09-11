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


# :heavy_check_mark: Prim's Algorithm <small>(graph/prim.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/prim.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 22:35:33+09:00




# Prim's Algorithm

Prim's algorithm is an algorithm for finding the minimum spanning tree of an undirected weighted graph.

- `T prim(vector<vector<Edge<T>>>& G)`
    - Returns the weight of the minimum spanning tree of the undirected weighted graph $G$, given its adjancency list.
    - Time complexity: $O(E\lg V)$

## Depends on

* :heavy_check_mark: <a href="edge.cpp.html">graph/edge.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.prim.test.cpp.html">test/aoj/GRL_2_A.prim.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include "edge.cpp"
using namespace std;

/*
 * @brief Prim's Algorithm
 * @docs docs/graph/prim.md
 */
template <typename T>
T prim(vector<vector<Edge<T>>>& G) {
    vector<bool> used(G.size());
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, 0);
    T ret = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (used[v]) continue;
        used[v] = true;
        ret += p.first;
        for (auto& e : G[v]) {
            pq.emplace(e.cost, e.to);
        }
    }
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/prim.cpp"
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
#line 3 "graph/prim.cpp"
using namespace std;

/*
 * @brief Prim's Algorithm
 * @docs docs/graph/prim.md
 */
template <typename T>
T prim(vector<vector<Edge<T>>>& G) {
    vector<bool> used(G.size());
    using P = pair<T, int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.emplace(0, 0);
    T ret = 0;
    while (!pq.empty()) {
        auto p = pq.top();
        pq.pop();
        int v = p.second;
        if (used[v]) continue;
        used[v] = true;
        ret += p.first;
        for (auto& e : G[v]) {
            pq.emplace(e.cost, e.to);
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

