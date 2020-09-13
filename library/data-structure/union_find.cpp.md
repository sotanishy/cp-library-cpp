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


# :heavy_check_mark: Union Find <small>(data-structure/union_find.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00




# Union Find

A union find, or a disjoint set union, is a data structure that stores a collection of disjoint sets.

This version uses path compression and union by size.

Space complexity: $O(n)$

## Constructor

- `UnionFind(int n)`
    - Constructs a union find of size `n`.
    - Time complexity: $O(n)$

## Member functions

- `int find(int x)`
    - Returns the root of the tree $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(int x, int y)`
    - Unites the set $x$ belongs to and the set $y$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(int x, int y)`
    - Checks if $x$ and $y$ are in the same set.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `int size(int x)`
    - Returns the size of the set $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ is the inverse Ackermann function.

## Required by

* :heavy_check_mark: <a href="../graph/kruskal.cpp.html">Kruskal's Algorithm <small>(graph/kruskal.cpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_1_A.test.cpp.html">test/aoj/DSL_1_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_2_A.kruskal.test.cpp.html">test/aoj/GRL_2_A.kruskal.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/unionfind.test.cpp.html">test/yosupo/unionfind.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Union Find
 * @docs docs/data-structure/union_find.md
 */
struct UnionFind {
    vector<int> par;

    UnionFind(size_t n) : par(n, -1) {}

    size_t find(size_t x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    void unite(size_t x, size_t y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }

    size_t size(size_t x) {
        return -par[find(x)];
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/union_find.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Union Find
 * @docs docs/data-structure/union_find.md
 */
struct UnionFind {
    vector<int> par;

    UnionFind(size_t n) : par(n, -1) {}

    size_t find(size_t x) {
        if (par[x] < 0) return x;
        return par[x] = find(par[x]);
    }

    void unite(size_t x, size_t y) {
        x = find(x);
        y = find(y);
        if (x == y) return;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }

    size_t size(size_t x) {
        return -par[find(x)];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

