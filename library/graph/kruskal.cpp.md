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


# :heavy_check_mark: graph/kruskal.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/kruskal.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 15:01:14+09:00




## Depends on

* :heavy_check_mark: <a href="../data-structure/union_find.cpp.html">data-structure/union_find.cpp</a>
* :heavy_check_mark: <a href="edge.cpp.html">graph/edge.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.kruskal.test.cpp.html">test/aoj/GRL_2_A.kruskal.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include "edge.cpp"
#include "../data-structure/union_find.cpp"
using namespace std;

template <typename T>
T kruskal(vector<Edge<T>>& G, int V) {
    sort(G.begin(), G.end(), [](const auto& e1, const auto& e2) {
        return e1.cost < e2.cost;
    });
    UnionFind uf(V);
    T ret = 0;
    for (auto& e : G) {
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            ret += e.cost;
        }
    }
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/kruskal.cpp"
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
#line 2 "data-structure/union_find.cpp"
using namespace std;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) : par(n, -1) {}

    int find(int x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return -par[find(x)];
    }
};
#line 4 "graph/kruskal.cpp"
using namespace std;

template <typename T>
T kruskal(vector<Edge<T>>& G, int V) {
    sort(G.begin(), G.end(), [](const auto& e1, const auto& e2) {
        return e1.cost < e2.cost;
    });
    UnionFind uf(V);
    T ret = 0;
    for (auto& e : G) {
        if (!uf.same(e.from, e.to)) {
            uf.unite(e.from, e.to);
            ret += e.cost;
        }
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>
