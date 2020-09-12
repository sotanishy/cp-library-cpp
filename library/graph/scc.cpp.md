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


# :heavy_check_mark: Strongly Connected Components <small>(graph/scc.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/scc.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 22:11:54+09:00




# Strongly Connected Components

This struct decomposes the given graph $G$ into strongly connected components (SCCs) i.e. subgraphs of $G$ that are strongly connected and maximal, using Kosaraju's algorithm.

If each SCC is contracted into a single vertex, the resulting graph will be a directed acyclic graph (DAG).

The labels of SCCs are in the topological order.

Space complexity: $O(V + E)$

## Constructor

- `SCC(int n)`
    - Creates a graph with $n$ vertices and no edges.

## Member functions

- `void add_edge(int u, int v)`
    - Adds an edge $(u, v)$
    - Time complexity: $O(1)$
- `void build()`
    - Decomposes the graph into strongly connected components.
    - Time complexity: $O(V + E)$
- `int operator[](int i)`
    - Returns the label of the strongly connected component the vertex $i$ belongs to.
    - Time complexity: $O(1)$
- `int count()`
    - Returns the number of strongly connected components.
    - Time complexity: $O(1)$

## Required by

* :heavy_check_mark: <a href="twosat.cpp.html">2-SAT <small>(graph/twosat.cpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_3_C.test.cpp.html">test/aoj/GRL_3_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/two_sat.test.cpp.html">test/yosupo/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Strongly Connected Components
 * @docs docs/graph/scc.md
 */
struct SCC {
public:
    SCC(int n) : G(n), G_rev(n), comp(n, -1), visited(n) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G_rev[v].push_back(u);
    }

    void build() {
        for (int v = 0; v < G.size(); v++) dfs(v);
        reverse(order.begin(), order.end());
        cnt = 0;
        for (int v : order) if (comp[v] == -1) rdfs(v, cnt++);
    }

    int operator[](int i) const {
        return comp[i];
    }

    int count() {
        return cnt;
    }

private:
    vector<vector<int>> G, G_rev;
    vector<int> comp, order;
    vector<bool> visited;
    int cnt;

    void dfs(int u) {
        if (visited[u]) return;
        visited[u] = true;
        for (int v : G[u]) dfs(v);
        order.push_back(u);
    }

    void rdfs(int u, int c) {
        if (comp[u] != -1) return;
        comp[u] = c;
        for (int v : G_rev[u]) rdfs(v, c);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/scc.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Strongly Connected Components
 * @docs docs/graph/scc.md
 */
struct SCC {
public:
    SCC(int n) : G(n), G_rev(n), comp(n, -1), visited(n) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G_rev[v].push_back(u);
    }

    void build() {
        for (int v = 0; v < G.size(); v++) dfs(v);
        reverse(order.begin(), order.end());
        cnt = 0;
        for (int v : order) if (comp[v] == -1) rdfs(v, cnt++);
    }

    int operator[](int i) const {
        return comp[i];
    }

    int count() {
        return cnt;
    }

private:
    vector<vector<int>> G, G_rev;
    vector<int> comp, order;
    vector<bool> visited;
    int cnt;

    void dfs(int u) {
        if (visited[u]) return;
        visited[u] = true;
        for (int v : G[u]) dfs(v);
        order.push_back(u);
    }

    void rdfs(int u, int c) {
        if (comp[u] != -1) return;
        comp[u] = c;
        for (int v : G_rev[u]) rdfs(v, c);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

