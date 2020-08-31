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


# :warning: data-structure/segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 10:11:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    int size;
    vector<T> node;
    const F f;
    const T I;

    SegmentTree(int n, const F f, const T& I) : f(f), I(I) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size, I);
    }

    T operator[](int k) {
        return node[k + size];
    }

    void build(vector<T>& v) {
        for (int k = 0; k < v.size(); k++) node[k + size] = v[k];
        for (int k = size - 1; k > 0; k--) node[k] = f(node[2 * k], node[2 * k + 1]);
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) {
            node[k] = f(node[2 * k], node[2 * k + 1]);
        }
    }

    T query(int a, int b) {
        T L = I, R = I;
        for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, node[a++]);
            if (b & 1) R = f(node[--b], R);
        }
        return f(L, R);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    int size;
    vector<T> node;
    const F f;
    const T I;

    SegmentTree(int n, const F f, const T& I) : f(f), I(I) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size, I);
    }

    T operator[](int k) {
        return node[k + size];
    }

    void build(vector<T>& v) {
        for (int k = 0; k < v.size(); k++) node[k + size] = v[k];
        for (int k = size - 1; k > 0; k--) node[k] = f(node[2 * k], node[2 * k + 1]);
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) {
            node[k] = f(node[2 * k], node[2 * k + 1]);
        }
    }

    T query(int a, int b) {
        T L = I, R = I;
        for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, node[a++]);
            if (b & 1) R = f(node[--b], R);
        }
        return f(L, R);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

