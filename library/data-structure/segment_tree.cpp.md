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


# :x: data-structure/segment_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 19:54:37+09:00




## Verified with

* :x: <a href="../../verify/test/aoj/DSL_2_A.test.cpp.html">test/aoj/DSL_2_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*op)(T, T), T id>
struct SegmentTree {
    int size;
    vector<T> node;

    SegmentTree(int n) : SegmentTree(vector<T>(n, id)) {}
    SegmentTree(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        node.resize(2 * size, id);
        for (int i = 0; i < size; i++) node[i + size] = v[i];
        for (int i = size - 1; i > 0; i--) node[i] = op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) const {
        return node[k + size];
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    T query(int l, int r) {
        T vl = id, vr = id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = op(vl, node[l++]);
            if (r & 1) vr = op(node[--r], vr);
        }
        return op(vl, vr);
    }

    int find_first(int l, const function<bool(T)>& cond) {
        T vl = id;
        int r = 2 * size;
        for (l += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                T nxt = op(vl, node[l]);
                if (cond(nxt)) {
                    while (l < size) {
                        nxt = op(vl, node[2 * l]);
                        if (cond(nxt)) l = 2 * l;
                        else vl = nxt, l = 2 * l + 1;
                    }
                    return l - size;
                }
                vl = nxt;
                l++;
            }
        }
        return -1;
    }

    int find_last(int r, const function<bool(T)>& cond) {
        T vr = id;
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                r--;
                T nxt = op(node[r], vr);
                if (cond(nxt)) {
                    while (r < size) {
                        nxt = op(node[2 * r + 1], vr);
                        if (cond(nxt)) r = 2 * r + 1;
                        else vr = nxt, r = 2 * r;
                    }
                    return r - size;
                }
                vr = nxt;
            }
        }
        return -1;
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

template <typename T, T (*op)(T, T), T id>
struct SegmentTree {
    int size;
    vector<T> node;

    SegmentTree(int n) : SegmentTree(vector<T>(n, id)) {}
    SegmentTree(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        node.resize(2 * size, id);
        for (int i = 0; i < size; i++) node[i + size] = v[i];
        for (int i = size - 1; i > 0; i--) node[i] = op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) const {
        return node[k + size];
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    T query(int l, int r) {
        T vl = id, vr = id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = op(vl, node[l++]);
            if (r & 1) vr = op(node[--r], vr);
        }
        return op(vl, vr);
    }

    int find_first(int l, const function<bool(T)>& cond) {
        T vl = id;
        int r = 2 * size;
        for (l += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                T nxt = op(vl, node[l]);
                if (cond(nxt)) {
                    while (l < size) {
                        nxt = op(vl, node[2 * l]);
                        if (cond(nxt)) l = 2 * l;
                        else vl = nxt, l = 2 * l + 1;
                    }
                    return l - size;
                }
                vl = nxt;
                l++;
            }
        }
        return -1;
    }

    int find_last(int r, const function<bool(T)>& cond) {
        T vr = id;
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                r--;
                T nxt = op(node[r], vr);
                if (cond(nxt)) {
                    while (r < size) {
                        nxt = op(node[2 * r + 1], vr);
                        if (cond(nxt)) r = 2 * r + 1;
                        else vr = nxt, r = 2 * r;
                    }
                    return r - size;
                }
                vr = nxt;
            }
        }
        return -1;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

