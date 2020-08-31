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


# :warning: data-structure/rmq.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/rmq.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 10:11:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct RMQ {
    int n;
    vector<T> node;
    const int INF = 1e9;

    RMQ(int size) {
        n = 1;
        while (n < size) n << 1;
        node.resize(2 * n - 1, INF);
    }

    void update(int i, T x) {
        i += n - 1;
        node[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            node[i] = min(node[i * 2 + 1], node[i* 2 + 2]);
        }
    }

    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = n;

        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        T vl = query(a, b, k * 2 + 1, l, m);
        T vr = query(a, b, k * 2 + 2, m, r);
        return min(vl, vr);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/rmq.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct RMQ {
    int n;
    vector<T> node;
    const int INF = 1e9;

    RMQ(int size) {
        n = 1;
        while (n < size) n << 1;
        node.resize(2 * n - 1, INF);
    }

    void update(int i, T x) {
        i += n - 1;
        node[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            node[i] = min(node[i * 2 + 1], node[i* 2 + 2]);
        }
    }

    T query(int a, int b, int k = 0, int l = 0, int r = -1) {
        if (r == -1) r = n;

        if (r <= a || b <= l) return INF;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        T vl = query(a, b, k * 2 + 1, l, m);
        T vr = query(a, b, k * 2 + 2, m, r);
        return min(vl, vr);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

