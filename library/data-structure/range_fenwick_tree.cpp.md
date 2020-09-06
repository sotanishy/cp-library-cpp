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


# :x: data-structure/range_fenwick_tree.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/range_fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 03:18:51+09:00




## Verified with

* :x: <a href="../../verify/test/aoj/DSL_2_G.range_fenwick_tree.test.cpp.html">test/aoj/DSL_2_G.range_fenwick_tree.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct RangeFenwickTree {
    int n;
    vector<T> data0, data1;

    RangeFenwickTree(int n) : n(n), data0(n+1), data1(n+1) {}

private:
    T _sum(vector<int>& data, int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void _add(vector<int>& data, int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }

public:
    T sum(int i) {
        return _sum(data0, i) * i + _sum(data1, i);
    }

    void add(int l, int r, T x) {
        _add(data0, l, x);
        _add(data0, r + 1, -x);
        _add(data1, l, -x * (l - 1));
        _add(data1, r + 1, x * r);
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
    int n;
    vector<T> data0, data1;

    RangeFenwickTree(int n) : n(n), data0(n+1), data1(n+1) {}

private:
    T _sum(vector<int>& data, int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void _add(vector<int>& data, int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }

public:
    T sum(int i) {
        return _sum(data0, i) * i + _sum(data1, i);
    }

    void add(int l, int r, T x) {
        _add(data0, l, x);
        _add(data0, r + 1, -x);
        _add(data1, l, -x * (l - 1));
        _add(data1, r + 1, x * r);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

