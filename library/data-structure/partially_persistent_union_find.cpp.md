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


# :warning: Partially Persistent Union Find <small>(data-structure/partially_persistent_union_find.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/partially_persistent_union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:56:12+09:00




# Partially Persistent Union Find

A partially persistent union find can access some past information about the disjoint sets. It offers the following operations:
* merge two sets
* check if two nodes are in the same set at time $t$
* return the size of the set that a node belongs to at time $t$

Space complexity: $O(n + q)$

## Methods

- `PartiallyPersistentUnionFind(int n)`
    - Constructs a partially persistent union find of size `n`. The initial time is set to 0.
    - Time complexity: $O(n)$
- `int find(int t, int x)`
    - Returns the root of the tree $x$ belongs to at time $t$.
    - Time complexity: $O(\lg n)$
- `void unite(int x, int y)`
    - Increments the time by 1, and unites the set $x$ belongs to and the set $y$ belongs to.
    - Time complexity: $O(\lg n)$
- `bool same(int t, int x, int y)`
    - Checks if $x$ and $y$ are in the same set at time $t$.
    - Time complexity: $O(\lg n)$
- `int size(int t, int x)`
    - Returns the size of the set $x$ belongs to at time $t$.
    - Time complexity: $O(\lg n)$

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Partially Persistent Union Find
 * @docs docs/data-structure/partially_persistent_union_find.md
 */
struct PartiallyPersistentUnionFind {
    vector<int> par, time;
    vector<vector<pair<int, int>>> sz;
    int now = 0;
    const int INF = 1e9;

    PartiallyPersistentUnionFind(int n) : par(n, -1), time(n, INF), sz(n, {{0, 1}}) {}

    int find(int t, int x) {
        if (t < time[x]) return x;
        return find(t, par[x]);
    }

    void unite(int x, int y) {
        now++;
        x = find(now, x);
        y = find(now, y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        sz[x].emplace_back(now, -par[x]);
        par[y] = x;
        time[y] = now;
    }

    bool same(int t, int x, int y) {
        return find(t, x) == find(t, y);
    }

    int size(int t, int x) {
        x = find(t, x);
        return (--lower_bound(sz[x].begin(), sz[x].end(), make_pair(t, INF)))->second;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/partially_persistent_union_find.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Partially Persistent Union Find
 * @docs docs/data-structure/partially_persistent_union_find.md
 */
struct PartiallyPersistentUnionFind {
    vector<int> par, time;
    vector<vector<pair<int, int>>> sz;
    int now = 0;
    const int INF = 1e9;

    PartiallyPersistentUnionFind(int n) : par(n, -1), time(n, INF), sz(n, {{0, 1}}) {}

    int find(int t, int x) {
        if (t < time[x]) return x;
        return find(t, par[x]);
    }

    void unite(int x, int y) {
        now++;
        x = find(now, x);
        y = find(now, y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        sz[x].emplace_back(now, -par[x]);
        par[y] = x;
        time[y] = now;
    }

    bool same(int t, int x, int y) {
        return find(t, x) == find(t, y);
    }

    int size(int t, int x) {
        x = find(t, x);
        return (--lower_bound(sz[x].begin(), sz[x].end(), make_pair(t, INF)))->second;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

