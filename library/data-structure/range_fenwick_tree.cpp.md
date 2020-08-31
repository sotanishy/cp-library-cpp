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


# :warning: data-structure/range_fenwick_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/range_fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 10:11:59+09:00




## Depends on

* :warning: <a href="fenwick_tree.cpp.html">data-structure/fenwick_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
#include "fenwick_tree.cpp"
using namespace std;

template <typename T>
struct RangeFenwickTree {
    FenwickTree<T> bit0, bit1;

    RangeFenwickTree(int n) : bit0(n), bit1(n) {}

    T sum(int i) {
        return bit0.sum(i) * i + bit1.sum(i);
    }

    void add(int l, int r, T x) {
        bit0.add(l, x);
        bit0.add(r + 1, -x);
        bit1.add(l, -x * (l - 1));
        bit1.add(r + 1, x * r);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/range_fenwick_tree.cpp"
#include <bits/stdc++.h>
#line 2 "data-structure/fenwick_tree.cpp"
using namespace std;

template <typename T>
struct FenwickTree {
    int n;
    vector<T> data;

    FenwickTree(int n) : n(n), data(n+1) {}

    T sum(int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void add(int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }

    int lower_bound(T x) {
        if (x <= 0) return 0;
        int k = 1;
        while (k * 2 <= n) k *= 2;
        int j = 0;
        for (; k > 0; k /= 2) {
            if (j + k <= n && data[j+k] < x) {
                x -= data[j+k];
                j += k;
            }
        }
        return j;
    }
};
#line 3 "data-structure/range_fenwick_tree.cpp"
using namespace std;

template <typename T>
struct RangeFenwickTree {
    FenwickTree<T> bit0, bit1;

    RangeFenwickTree(int n) : bit0(n), bit1(n) {}

    T sum(int i) {
        return bit0.sum(i) * i + bit1.sum(i);
    }

    void add(int l, int r, T x) {
        bit0.add(l, x);
        bit0.add(r + 1, -x);
        bit1.add(l, -x * (l - 1));
        bit1.add(r + 1, x * r);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

