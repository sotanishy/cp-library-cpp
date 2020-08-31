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


# :warning: data-structure/lazy_segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/lazy_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 10:11:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

// this is not abstract
// range sum
struct LazySegmentTree {
    int size;
    vector<int> node, lazy;
    const int I = 0;

    LazySegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size, I);
        lazy.resize(2 * size, I);
    }

    void init(vector<int>& v) {
        for (int k = 0; k < v.size(); k++) {
            node[k + size] = v[k];
        }
        for (int k = size - 1; k > 0; k--) {
            node[k] = node[2 * k] + node[2 * k + 1];
        }
    }

    void eval(int k) {
        if (lazy[k] == I) return;
        if (k < size) { // not a leaf
            lazy[2 * k] = lazy[2 * k + 1] = lazy[k] / 2;
        }
        node[k] += lazy[k];
        lazy[k] = I;
    }

    void update(int a, int b, int x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        eval(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k);
        } else {
            int m = (l + r) / 2;
            update(a, b, x, 2 * k, l, m);
            update(a, b, x, 2 * k + 1, m, r);
            node[k] = node[2 * k] + node[2 * k + 1];
        }
    }

    int query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        eval(k);
        if (r <= a || b <= l) return I;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        int vl = query(a, b, 2 * k, l, m);
        int vr = query(a, b, 2 * k + 1, m, r);
        return vl + vr;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/lazy_segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

// this is not abstract
// range sum
struct LazySegmentTree {
    int size;
    vector<int> node, lazy;
    const int I = 0;

    LazySegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size, I);
        lazy.resize(2 * size, I);
    }

    void init(vector<int>& v) {
        for (int k = 0; k < v.size(); k++) {
            node[k + size] = v[k];
        }
        for (int k = size - 1; k > 0; k--) {
            node[k] = node[2 * k] + node[2 * k + 1];
        }
    }

    void eval(int k) {
        if (lazy[k] == I) return;
        if (k < size) { // not a leaf
            lazy[2 * k] = lazy[2 * k + 1] = lazy[k] / 2;
        }
        node[k] += lazy[k];
        lazy[k] = I;
    }

    void update(int a, int b, int x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        eval(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k);
        } else {
            int m = (l + r) / 2;
            update(a, b, x, 2 * k, l, m);
            update(a, b, x, 2 * k + 1, m, r);
            node[k] = node[2 * k] + node[2 * k + 1];
        }
    }

    int query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        eval(k);
        if (r <= a || b <= l) return I;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        int vl = query(a, b, 2 * k, l, m);
        int vr = query(a, b, 2 * k + 1, m, r);
        return vl + vr;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

