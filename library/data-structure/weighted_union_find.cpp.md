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


# :heavy_check_mark: Weighted Union Find <small>(data-structure/weighted_union_find.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/weighted_union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00




# Weighted Union Find

In addition to operations that a union find provides, a weighted union find stores the weights of each node relative to other nodes in the same set.

This version uses path compression and union by size.

Space complexity: $O(n)$

## Template parameters

- `T`
    - The type of the weights

## Constructor

- `WeightedUnionFind(size_t n)`
    - Constructs a weighted union find of size `n`.
    - Time complexity: $O(n)$

## Member functions

- `size_t find(size_t x)`
    - Returns the root of the tree $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `T weight(size_t x)`
    - Returns the weight of $x$ relative to the root of the set.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(size_t x, size_t y, T w)`
    - Unites the set $x$ belongs to and the set $y$ belongs to, so that $weight(y) - weight(x) = w$.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(size_t x, size_t y)`
    - Checks if $x$ and $y$ are in the same set.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `T diff(size_t x, size_t y)`
    - Returns the weight of $y$ relative to $x$, i.e. $weight(y) - weight(x)$.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `size_t size(size_t x)`
    - Returns the size of the set $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ is the inverse Ackermann function.

## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_1_B.test.cpp.html">test/aoj/DSL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Weighted Union Find
 * @docs docs/data-structure/weighted_union_find.md
 */
template <typename T>
struct WeightedUnionFind {
    vector<int> par;
    vector<T> ws;

    WeightedUnionFind(size_t n) : par(n, -1), ws(n) {}

    size_t find(size_t x) {
        if (par[x] < 0) return x;
        size_t r = find(par[x]);
        ws[x] += ws[par[x]];
        return par[x] = r;
    }

    T weight(size_t x) {
        find(x);
        return ws[x];
    }

    bool unite(size_t x, size_t y, T w) {
        w += weight(x);
        w -= weight(y);
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) {
            swap(x, y);
            w = -w;
        }
        par[x] += par[y];
        par[y] = x;
        ws[y] = w;
        return true;
    }

    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }

    T diff(size_t x, size_t y) {
        return weight(y) - weight(x);
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
#line 1 "data-structure/weighted_union_find.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Weighted Union Find
 * @docs docs/data-structure/weighted_union_find.md
 */
template <typename T>
struct WeightedUnionFind {
    vector<int> par;
    vector<T> ws;

    WeightedUnionFind(size_t n) : par(n, -1), ws(n) {}

    size_t find(size_t x) {
        if (par[x] < 0) return x;
        size_t r = find(par[x]);
        ws[x] += ws[par[x]];
        return par[x] = r;
    }

    T weight(size_t x) {
        find(x);
        return ws[x];
    }

    bool unite(size_t x, size_t y, T w) {
        w += weight(x);
        w -= weight(y);
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (par[x] > par[y]) {
            swap(x, y);
            w = -w;
        }
        par[x] += par[y];
        par[y] = x;
        ws[y] = w;
        return true;
    }

    bool same(size_t x, size_t y) {
        return find(x) == find(y);
    }

    T diff(size_t x, size_t y) {
        return weight(y) - weight(x);
    }

    size_t size(size_t x) {
        return -par[find(x)];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

