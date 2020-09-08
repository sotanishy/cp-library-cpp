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


# :heavy_check_mark: graph/scc_decomposition.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/scc_decomposition.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 19:33:24+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_3_C.test.cpp.html">test/aoj/GRL_3_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct SCC {
public:
    SCC(vector<vector<int>>& G) : G(G), comp(G.size(), -1), visited(G.size()), G_rev(G.size()) {
        for (int u = 0; u < G.size(); u++) {
            for (int v : G[u]) G_rev[v].push_back(u);
        }

        for (int v = 0; v < G.size(); v++) dfs(v);
        reverse(order.begin(), order.end());
        int c = 0;
        for (int v : order) if (comp[v] == -1) rdfs(v, c++);
    }

    int operator[](int k) const {
        return comp[k];
    }

private:
    vector<vector<int>> G, G_rev;
    vector<int> comp, order;
    vector<bool> visited;

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
#line 1 "graph/scc_decomposition.cpp"
#include <bits/stdc++.h>
using namespace std;

struct SCC {
public:
    SCC(vector<vector<int>>& G) : G(G), comp(G.size(), -1), visited(G.size()), G_rev(G.size()) {
        for (int u = 0; u < G.size(); u++) {
            for (int v : G[u]) G_rev[v].push_back(u);
        }

        for (int v = 0; v < G.size(); v++) dfs(v);
        reverse(order.begin(), order.end());
        int c = 0;
        for (int v : order) if (comp[v] == -1) rdfs(v, c++);
    }

    int operator[](int k) const {
        return comp[k];
    }

private:
    vector<vector<int>> G, G_rev;
    vector<int> comp, order;
    vector<bool> visited;

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

