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


# :x: test/aoj/GRL_2_A.kruskal.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_2_A.kruskal.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :question: <a href="../../../library/data-structure/union_find.cpp.html">Union Find <small>(data-structure/union_find.cpp)</small></a>
* :question: <a href="../../../library/graph/edge.cpp.html">graph/edge.cpp</a>
* :x: <a href="../../../library/graph/kruskal.cpp.html">Kruskal's Algorithm <small>(graph/kruskal.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../graph/kruskal.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<Edge<int>> edges;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edges.emplace_back(s, t, w);
    }
    cout << kruskal(edges, V) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_2_A.kruskal.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

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

/*
 * @brief Union Find
 * @docs docs/data-structure/union_find.md
 */
struct UnionFind {
    vector<int> par;

    UnionFind(size_t n) : par(n, -1) {}

    size_t find(size_t x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    void unite(size_t x, size_t y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }

    size_t size(size_t x) {
        return -par[find(x)];
    }
};
#line 4 "graph/kruskal.cpp"
using namespace std;

/*
 * @brief Kruskal's Algorithm
 * @docs docs/graph/kruskal.md
 */
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
#line 4 "test/aoj/GRL_2_A.kruskal.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<Edge<int>> edges;
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        edges.emplace_back(s, t, w);
    }
    cout << kruskal(edges, V) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

