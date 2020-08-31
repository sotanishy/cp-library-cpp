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


# :warning: flow/dinic.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/dinic.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 09:52:54+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to, cap, rev;
    };

    const int INF = numeric_limits<int>::max();

    vector<vector<Edge>> G;
    vector<int> level, iter;

    Dinic(int V) : G(V), level(V), iter(V) {}

    void add_edge(int u, int v, int cap) {
        G[u].emplace_back((Edge) {v, cap, (int) G[v].size()});
        G[v].emplace_back((Edge) {u, 0, (int) G[u].size() - 1});
    }

    // calculate the shortest distance from s
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty() && level[t] == -1) {
            int v = q.front();
            q.pop();
            for (auto& e : G[v]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    // find a path
    // v: current node, t: sink node, f: current flow
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < G[v].size(); i++) {
            Edge& e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    // find the max flow from s to t
    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(iter.begin(), iter.end(), 0);
            int f = 0;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "flow/dinic.cpp"
#include <bits/stdc++.h>
using namespace std;

struct Dinic {
    struct Edge {
        int to, cap, rev;
    };

    const int INF = numeric_limits<int>::max();

    vector<vector<Edge>> G;
    vector<int> level, iter;

    Dinic(int V) : G(V), level(V), iter(V) {}

    void add_edge(int u, int v, int cap) {
        G[u].emplace_back((Edge) {v, cap, (int) G[v].size()});
        G[v].emplace_back((Edge) {u, 0, (int) G[u].size() - 1});
    }

    // calculate the shortest distance from s
    bool bfs(int s, int t) {
        fill(level.begin(), level.end(), -1);
        level[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty() && level[t] == -1) {
            int v = q.front();
            q.pop();
            for (auto& e : G[v]) {
                if (e.cap > 0 && level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[t] != -1;
    }

    // find a path
    // v: current node, t: sink node, f: current flow
    int dfs(int v, int t, int f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < G[v].size(); i++) {
            Edge& e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                int d = dfs(e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    // find the max flow from s to t
    int max_flow(int s, int t) {
        int flow = 0;
        while (bfs(s, t)) {
            fill(iter.begin(), iter.end(), 0);
            int f = 0;
            while ((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

