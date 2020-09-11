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


# :heavy_check_mark: test/aoj/GRL_6_A.ford_fulkerson.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_6_A.ford_fulkerson.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 00:51:47+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/flow/ford_fulkerson.cpp.html">Ford-Fulkerson Algorithm <small>(flow/ford_fulkerson.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#include "../../flow/ford_fulkerson.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    FordFulkerson<int> flow(V);
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }
    cout << flow.max_flow(0, V - 1) << endl;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/GRL_6_A.ford_fulkerson.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"

#line 1 "flow/ford_fulkerson.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Ford-Fulkerson Algorithm
 * @docs docs/flow/ford_fulkerson.md
 */
template <typename T>
struct FordFulkerson {
public:
    FordFulkerson(int n) : G(n), used(n) {}

    void add_edge(int u, int v, T cap) {
        G[u].emplace_back(v, cap, (int) G[v].size());
        G[v].emplace_back(u, 0, (int) G[u].size() - 1);
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while (true) {
            fill(used.begin(), used.end(), false);
            T f = dfs(s, t, INF);
            if (f == 0) return flow;
            flow += f;
        }
    }

private:
    struct Edge {
        int to;
        T cap;
        int rev;
        Edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    const T INF = numeric_limits<T>::max() / 2;

    vector<vector<Edge>> G;
    vector<bool> used;

    T dfs(int v, int t, T f) {
        if (v == t) return f;
        used[v] = true;
        for (auto& e : G[v]) {
            if (!used[e.to] && e.cap > 0) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
};
#line 4 "test/aoj/GRL_6_A.ford_fulkerson.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int V, E;
    cin >> V >> E;
    FordFulkerson<int> flow(V);
    for (int i = 0; i < E; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        flow.add_edge(u, v, c);
    }
    cout << flow.max_flow(0, V - 1) << endl;
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

