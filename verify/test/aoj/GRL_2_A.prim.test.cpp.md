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


# :heavy_check_mark: test/aoj/GRL_2_A.prim.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_2_A.prim.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 15:01:14+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/edge.cpp.html">graph/edge.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/prim.cpp.html">graph/prim.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

#include "../../graph/prim.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<Edge<int>>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    cout << prim(G) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_2_A.prim.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"

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
#line 4 "test/aoj/GRL_2_A.prim.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<Edge<int>>> G(V);
    for (int i = 0; i < E; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        G[s].push_back({t, w});
        G[t].push_back({s, w});
    }
    cout << prim(G) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

