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


# :heavy_check_mark: test/aoj/DSL_2_G.lazy_segment_tree.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_G.lazy_segment_tree.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 20:12:18+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/lazy_segment_tree.cpp.html">data-structure/lazy_segment_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../data-structure/lazy_segment_tree.cpp"

using ll = long long;

ll op(ll a, ll b) { return a + b; }
ll apply(ll a, ll b) { return a + b; }
ll comp(ll a, ll b) { return a + b; }
ll prod(ll a, int b) { return a * b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<ll, op, 0, ll, apply, comp, prod, 0> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s - 1, t, x);
        } else {
            cout << st.query(s - 1, t) << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_G.lazy_segment_tree.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

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
        return op(query(a, b, 2 * k, l, m),
                  query(a, b, 2 * k + 1, m, r));
    }
};
#line 4 "test/aoj/DSL_2_G.lazy_segment_tree.test.cpp"

using ll = long long;

ll op(ll a, ll b) { return a + b; }
ll apply(ll a, ll b) { return a + b; }
ll comp(ll a, ll b) { return a + b; }
ll prod(ll a, int b) { return a * b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<ll, op, 0, ll, apply, comp, prod, 0> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s - 1, t, x);
        } else {
            cout << st.query(s - 1, t) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

