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


# :heavy_check_mark: data-structure/range_fenwick_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/range_fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 10:36:41+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_G.range_fenwick_tree.test.cpp.html">test/aoj/DSL_2_G.range_fenwick_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct RangeFenwickTree {
public:
    RangeFenwickTree(int n) : n(n), data0(n+1), data1(n+1) {}

    T sum(int i) {
        return sum(data0, i) * i + sum(data1, i);
    }

    void add(int l, int r, T x) {
        add(data0, l, x);
        add(data0, r + 1, -x);
        add(data1, l, -x * (l - 1));
        add(data1, r + 1, x * r);
    }

private:
    int n;
    vector<T> data0, data1;

    T sum(vector<T>& data, int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void add(vector<T>& data, int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/range_fenwick_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct RangeFenwickTree {
public:
    RangeFenwickTree(int n) : n(n), data0(n+1), data1(n+1) {}

    T sum(int i) {
        return sum(data0, i) * i + sum(data1, i);
    }

    void add(int l, int r, T x) {
        add(data0, l, x);
        add(data0, r + 1, -x);
        add(data1, l, -x * (l - 1));
        add(data1, r + 1, x * r);
    }

private:
    int n;
    vector<T> data0, data1;

    T sum(vector<T>& data, int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void add(vector<T>& data, int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

