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


# :heavy_check_mark: test/aoj/GRL_1_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 22:35:33+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/floyd_warshall.cpp.html">Floyd-Warshall Algorithm <small>(graph/floyd_warshall.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#include "../../graph/floyd_warshall.cpp"

using ll = long long;

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<ll>> dist(V, vector<ll>(V, INF));
    for (int i = 0; i < V; i++) dist[i][i] = 0;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    floyd_warshall(dist);
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] < 1e10) cout << dist[i][j];
            else cout << "INF";
            if (j < V - 1) cout << " ";
            else cout << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_1_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"

#line 1 "graph/floyd_warshall.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Floyd-Warshall Algorithm
 * @docs docs/graph/floyd_warshall.md
 */
template <typename T>
void floyd_warshall(vector<vector<T>>& dist) {
    int V = dist.size();
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
#line 4 "test/aoj/GRL_1_C.test.cpp"

using ll = long long;

const ll INF = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    vector<vector<ll>> dist(V, vector<ll>(V, INF));
    for (int i = 0; i < V; i++) dist[i][i] = 0;
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        dist[s][t] = d;
    }
    floyd_warshall(dist);
    for (int i = 0; i < V; i++) {
        if (dist[i][i] < 0) {
            cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    }
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            if (dist[i][j] < 1e10) cout << dist[i][j];
            else cout << "INF";
            if (j < V - 1) cout << " ";
            else cout << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

