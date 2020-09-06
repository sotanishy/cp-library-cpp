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


# :heavy_check_mark: test/aoj/DSL_2_G.range_fenwick_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_G.range_fenwick_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-07 04:02:57+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/range_fenwick_tree.cpp.html">data-structure/range_fenwick_tree.cpp</a>


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

template <typename T>
struct RangeFenwickTree {
    int n;
    vector<T> data0, data1;

    RangeFenwickTree(int n) : n(n), data0(n+1), data1(n+1) {}

private:
    T _sum(vector<T>& data, int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void _add(vector<T>& data, int i, T x) {
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

