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


# :heavy_check_mark: 2-SAT <small>(graph/twosat.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/twosat.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 22:11:54+09:00




# 2-SAT

This struct solves the 2-satisfiability (2-SAT) problem in conjunctive normal form (CNF).

A 2-SAT can be solved with SCC decomposition, using the fact that a clause $(u \lor v)$ is logically equivalent to $(\lnot u \implies v) \land (\lnot v \implies u)$.

Space complexity: $O(n + m)$, where $n$ is the number of variables and $m$ is the number of clauses.

## Constructor

- `TwoSat(int n)`
    - Initializes the struct with $n$ variables.
    - Time complexity: $O(n)$

## Member functions

- `void add_clause(int u, bool a, int v, bool b)`
    - Adds a clause $(u \lor v)$. If `a == false`, replace $u$ with $\lnot u$. Similarly, if `b == false`, replace $v$ with $\lnot v$.
    - Time complexity: $O(1)$
- `void solve()`
    - Solves the given problem.
    - Time complexity: $O(n + m)$
- `bool is_satisfiable()`
    - Returns if the problem is satisfiable.
    - Time complexity: $O(1)$
- `bool operator[](int i)`
    - Returns the truth value of the $i$th variable if `satisfiable == true`
    - Time complexity: $O(1)$

## Depends on

* :heavy_check_mark: <a href="scc.cpp.html">Strongly Connected Components <small>(graph/scc.cpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/two_sat.test.cpp.html">test/yosupo/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include "scc.cpp"
using namespace std;

/*
 * @brief 2-SAT
 * @docs docs/graph/twosat.md
 */
struct TwoSat {
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

    bool is_satisfiable() const {
        return satisfiable;
    }

    bool operator[](int i) const {
        return val[i];
    }

private:
    int n;
    SCC scc;
    vector<bool> val;
    bool satisfiable = true;
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "graph/twosat.cpp"
#include <bits/stdc++.h>
#line 2 "graph/scc.cpp"
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
#line 3 "graph/twosat.cpp"
using namespace std;

/*
 * @brief 2-SAT
 * @docs docs/graph/twosat.md
 */
struct TwoSat {
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

    bool is_satisfiable() const {
        return satisfiable;
    }

    bool operator[](int i) const {
        return val[i];
    }

private:
    int n;
    SCC scc;
    vector<bool> val;
    bool satisfiable = true;
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

