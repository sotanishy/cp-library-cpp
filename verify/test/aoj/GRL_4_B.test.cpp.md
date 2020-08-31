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


# :x: test/aoj/GRL_4_B.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_4_B.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 15:48:39+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B</a>


## Depends on

* :x: <a href="../../../library/graph/topological_sort.cpp.html">graph/topological_sort.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#include "../../graph/topological_sort.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    auto order = topological_sort(G);
    for (int i = 0; i < V; i++) cout << order[i] << "\n";
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_4_B.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_4_B"

#line 1 "graph/topological_sort.cpp"
#include <bits/stdc++.h>
using namespace std;

// returns an empty list if G is not a DAG
vector<int> topological_sort(vector<vector<int>>& G) {
    int V = G.size();
    vector<int> par_count(V);
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
#line 4 "test/aoj/GRL_4_B.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<int>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        G[s].push_back(t);
    }
    auto order = topological_sort(G);
    for (int i = 0; i < V; i++) cout << order[i] << "\n";
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

