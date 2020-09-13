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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :x: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_G.range_fenwick_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G</a>


## Depends on

* :x: <a href="../../../library/data-structure/range_fenwick_tree.cpp.html">Fenwick Tree with Range Update <small>(data-structure/range_fenwick_tree.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../data-structure/range_fenwick_tree.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    RangeFenwickTree<long long> ft(n+1);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            ft.add(s - 1, t - 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << ft.sum(t - 1) - ft.sum(s - 2) << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_G.range_fenwick_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#line 1 "data-structure/range_fenwick_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fenwick Tree with Range Update
 * @docs docs/data-structure/range_fenwick_tree.md
 */
template <typename T>
struct RangeFenwickTree {
public:
    RangeFenwickTree(size_t n) : n(n), data0(n+1), data1(n+1) {}

    T sum(size_t i) {
        return sum(data0, i) * i + sum(data1, i);
    }

    void add(size_t l, size_t r, T x) {
        add(data0, l, x);
        add(data0, r + 1, -x);
        add(data1, l, -x * (l - 1));
        add(data1, r + 1, x * r);
    }

private:
    size_t n;
    vector<T> data0, data1;

    T sum(vector<T>& data, size_t i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void add(vector<T>& data, size_t i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }
};
#line 4 "test/aoj/DSL_2_G.range_fenwick_tree.test.cpp"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    RangeFenwickTree<long long> ft(n+1);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            ft.add(s - 1, t - 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << ft.sum(t - 1) - ft.sum(s - 2) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

