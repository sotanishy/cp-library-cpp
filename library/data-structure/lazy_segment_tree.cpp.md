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


# :question: data-structure/lazy_segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/lazy_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 20:07:17+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>
* :x: <a href="../../verify/test/aoj/DSL_2_G.lazy_segment_tree.test.cpp.html">test/aoj/DSL_2_G.lazy_segment_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*op)(T, T), T tid, typename E, T (*apply)(T, E), E (*comp)(E, E), E (*prod)(E, int), E eid>
struct LazySegmentTree {
    int size;
    vector<T> node;
    vector<E> lazy;

    LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, tid)) {}
    LazySegmentTree(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        node.resize(2 * size, tid);
        lazy.resize(2 * size, eid);
        for (int i = 0; i < v.size(); i++) node[i + size] = v[i];
        for (int i = size - 1; i > 0; i--) node[i] = op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) {
        return query(k, k + 1);
    }

    void push(int k, int len) {
        if (lazy[k] == eid) return;
        if (k < size) {
            lazy[2 * k] = comp(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = comp(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = apply(node[k], prod(lazy[k], len));
        lazy[k] = eid;
    }

    void update(int a, int b, const T& x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        push(k, r - l);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = comp(lazy[k], x);
            push(k, r - l);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    T query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        push(k, r - l);
        if (r <= a || b <= l) return tid;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        int vl = query(a, b, 2 * k, l, m);
        int vr = query(a, b, 2 * k + 1, m, r);
        return op(vl, vr);
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

template <typename T, T (*op)(T, T), T tid, typename E, T (*apply)(T, E), E (*comp)(E, E), E (*prod)(E, int), E eid>
struct LazySegmentTree {
    int size;
    vector<T> node;
    vector<E> lazy;

    LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, tid)) {}
    LazySegmentTree(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        node.resize(2 * size, tid);
        lazy.resize(2 * size, eid);
        for (int i = 0; i < v.size(); i++) node[i + size] = v[i];
        for (int i = size - 1; i > 0; i--) node[i] = op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) {
        return query(k, k + 1);
    }

    void push(int k, int len) {
        if (lazy[k] == eid) return;
        if (k < size) {
            lazy[2 * k] = comp(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = comp(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = apply(node[k], prod(lazy[k], len));
        lazy[k] = eid;
    }

    void update(int a, int b, const T& x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        push(k, r - l);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = comp(lazy[k], x);
            push(k, r - l);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    T query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        push(k, r - l);
        if (r <= a || b <= l) return tid;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        int vl = query(a, b, 2 * k, l, m);
        int vr = query(a, b, 2 * k + 1, m, r);
        return op(vl, vr);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

