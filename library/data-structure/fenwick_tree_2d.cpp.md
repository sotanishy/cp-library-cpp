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


# :warning: data-structure/fenwick_tree_2d.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/fenwick_tree_2d.cpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 10:11:59+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct FenwickTree2D {
    int H, W;
    vector<vector<T>> data;

    FenwickTree2D(int H, int W) : H(H), W(W), data(H+1, vector<T>(W+1)) {}

    void add(int a, int b, T x) {
        a++;
        b++;
        for (int i = a; i <= H; i += i & -i) {
            for (int j = b; j <= W; j += j & -j) {
                data[i][j] += x;
            }
        }
    }

    T sum(int a, int b) {
        a++;
        b++;
        T ret = 0;
        for (int i = a; i > 0; i -= i & -i) {
            for (int j = b; j > 0; j -= j & -j) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/fenwick_tree_2d.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct FenwickTree2D {
    int H, W;
    vector<vector<T>> data;

    FenwickTree2D(int H, int W) : H(H), W(W), data(H+1, vector<T>(W+1)) {}

    void add(int a, int b, T x) {
        a++;
        b++;
        for (int i = a; i <= H; i += i & -i) {
            for (int j = b; j <= W; j += j & -j) {
                data[i][j] += x;
            }
        }
    }

    T sum(int a, int b) {
        a++;
        b++;
        T ret = 0;
        for (int i = a; i > 0; i -= i & -i) {
            for (int j = b; j > 0; j -= j & -j) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

