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


# :heavy_check_mark: data-structure/weighted_union_find.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/weighted_union_find.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 10:11:59+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_1_B.test.cpp.html">test/aoj/DSL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct WeightedUnionFind {
    vector<int> par;
    vector<T> ws;

    WeightedUnionFind(int n) : par(n, -1), ws(n) {}

    int find(int x) {
        if (par[x] < 0) return x;
        int r = find(par[x]);
        ws[x] += ws[par[x]];
        return par[x] = r;
    }

    T weight(int x) {
        find(x);
        return ws[x];
    }

    bool unite(int x, int y, T w) {
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

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }

    int size(int x) {
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

template <typename T>
struct WeightedUnionFind {
    vector<int> par;
    vector<T> ws;

    WeightedUnionFind(int n) : par(n, -1), ws(n) {}

    int find(int x) {
        if (par[x] < 0) return x;
        int r = find(par[x]);
        ws[x] += ws[par[x]];
        return par[x] = r;
    }

    T weight(int x) {
        find(x);
        return ws[x];
    }

    bool unite(int x, int y, T w) {
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

    bool same(int x, int y) {
        return find(x) == find(y);
    }

    T diff(int x, int y) {
        return weight(y) - weight(x);
    }

    int size(int x) {
        return -par[find(x)];
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

