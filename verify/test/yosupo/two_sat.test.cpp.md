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


# :heavy_check_mark: test/yosupo/two_sat.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/two_sat.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 01:37:18+09:00


* see: <a href="https://judge.yosupo.jp/problem/two_sat">https://judge.yosupo.jp/problem/two_sat</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/graph/scc.cpp.html">graph/scc.cpp</a>
* :heavy_check_mark: <a href="../../../library/graph/twosat.cpp.html">graph/twosat.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../graph/twosat.cpp"

using ll = long long;

int main() {
    string _p, _cnf;
    int N, M;
    cin >> _p >> _cnf >> N >> M;
    TwoSat sat(N);
    for (int i = 0; i < M; i++) {
        int a, b, _c;
        cin >> a >> b >> _c;
        sat.add_clause(abs(a) - 1, (a > 0), abs(b) - 1, (b > 0));
    }
    sat.solve();
    if (sat.satisfiable) {
        cout << "s SATISFIABLE\nv";
        for (int i = 0; i < N; i++) {
            cout << " " << (sat[i] ? 1 : -1) * (i + 1);
        }
        cout << " 0\n";
    } else {
        cout << "s UNSATISFIABLE\n";
    }
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/two_sat.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#line 1 "graph/twosat.cpp"
#include <bits/stdc++.h>
#line 2 "graph/scc.cpp"
using namespace std;

struct SCC {
public:
    int num;

    SCC(int n) : G(n), G_rev(n), comp(n, -1), visited(n) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G_rev[v].push_back(u);
    }

    void build() {
        for (int v = 0; v < G.size(); v++) dfs(v);
        reverse(order.begin(), order.end());
        num = 0;
        for (int v : order) if (comp[v] == -1) rdfs(v, num++);
    }

    int operator[](int i) const {
        return comp[i];
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
#line 3 "graph/twosat.cpp"
using namespace std;

struct TwoSat {
    bool satisfiable = true;

    TwoSat(int n) : n(n), scc(2 * n), val(n) {}

    void add_clause(int u, bool a, int v, bool b) {
        scc.add_edge(n * a + u, n * (!b) + v);
        scc.add_edge(n * b + v, n * (!a) + u);
    }

    void solve() {
        scc.build();
        for (int i = 0; i < n; i++) {
            if (scc[i] == scc[n + i]) {
                satisfiable = false;
                break;
            }
            val[i] = scc[i] > scc[n + i];
        }
    }

    bool operator[](int i) const {
        return val[i];
    }

private:
    int n;
    SCC scc;
    vector<bool> val;
};
#line 4 "test/yosupo/two_sat.test.cpp"

using ll = long long;

int main() {
    string _p, _cnf;
    int N, M;
    cin >> _p >> _cnf >> N >> M;
    TwoSat sat(N);
    for (int i = 0; i < M; i++) {
        int a, b, _c;
        cin >> a >> b >> _c;
        sat.add_clause(abs(a) - 1, (a > 0), abs(b) - 1, (b > 0));
    }
    sat.solve();
    if (sat.satisfiable) {
        cout << "s SATISFIABLE\nv";
        for (int i = 0; i < N; i++) {
            cout << " " << (sat[i] ? 1 : -1) * (i + 1);
        }
        cout << " 0\n";
    } else {
        cout << "s UNSATISFIABLE\n";
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

