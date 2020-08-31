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


# :warning: graph/topological_sort.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/topological_sort.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

// returns an empty list if G is not a DAG
vector<int> topological_sort(vector<vector<int>>& G) {
    int V = G.size();
    vector<int> par_count(0, V);
    for (int u = 0; u < V; u++) {
        for (int v : G[u]) par_count[v]++;
    }
    stack<int> start;
    for (int v = 0; v < V; v++) {
        if (par_count[v] == 0) start.push(v);
    }

    vector<int> ret;
    while (!start.empty()) {
        int u = start.top();
        start.pop();
        ret.push_back(u);
        for (int v : G[u]) {
            par_count[v]--;
            if (par_count[v] == 0) start.push(v);
        }
    }

    for (int c : par_count) {
        if (c > 0) return vector<int>();
    }
    return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/topological_sort.cpp"
#include <bits/stdc++.h>
using namespace std;

// returns an empty list if G is not a DAG
vector<int> topological_sort(vector<vector<int>>& G) {
    int V = G.size();
    vector<int> par_count(0, V);
    for (int u = 0; u < V; u++) {
        for (int v : G[u]) par_count[v]++;
    }
    stack<int> start;
    for (int v = 0; v < V; v++) {
        if (par_count[v] == 0) start.push(v);
    }

    vector<int> ret;
    while (!start.empty()) {
        int u = start.top();
        start.pop();
        ret.push_back(u);
        for (int v : G[u]) {
            par_count[v]--;
            if (par_count[v] == 0) start.push(v);
        }
    }

    for (int c : par_count) {
        if (c > 0) return vector<int>();
    }
    return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

