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


# :heavy_check_mark: test/yosupo/range_affine_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 05:19:47+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/lazy_segment_tree.cpp.html">Segment Tree with Lazy Propagation <small>(data-structure/lazy_segment_tree.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../data-structure/lazy_segment_tree.cpp"

using ll = long long;

const ll mod = 998244353;

struct M {
    using T = pair<ll, int>;
    inline static const T id = {0, 0};
    static T op(T a, T b) {
        return {(a.first + b.first) % mod, a.second + b.second};
    }
};

struct O {
    using E = pair<ll, ll>;
    inline static const E id = {1, 0};
    static E op(E a, E b) {
        return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
    }
};

M::T act(M::T a, O::E b) {
    return {(a.first * b.first + a.second * b.second) % mod, a.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, int>> a(N, {0, 1});
    for (int i = 0; i < N; i++) cin >> a[i].first;
    LazySegmentTree<M, O, act> st(a);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            st.update(l, r, {b, c});
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.fold(l, r).first << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/range_affine_range_sum.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#line 1 "data-structure/lazy_segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Segment Tree with Lazy Propagation
 * @docs docs/data-structure/lazy_segment_tree.md
 */
template <typename M, typename O, typename M::T (*act)(typename M::T, typename O::E)>
struct LazySegmentTree {
    using T = typename M::T;
    using E = typename O::E;

    LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, M::id)) {}
    LazySegmentTree(const vector<T>& v) {
        size = 1;
        height = 0;
        while (size < v.size()) size <<= 1, height++;
        node.resize(2 * size, M::id);
        lazy.resize(2 * size, O::id);
        copy(v.begin(), v.end(), node.begin() + size);
        for (int i = size - 1; i > 0; i--) node[i] = M::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) {
        return fold(k, k + 1);
    }

    void update(int l, int r, const E& x) { update(l, r, x, 1, 0, size); }

    T fold(int l, int r) { return fold(l, r, 1, 0, size); }

private:
    int size, height;
    vector<T> node;
    vector<E> lazy;

    void push(int k) {
        if (lazy[k] == O::id) return;
        if (k < size) {
            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = act(node[k], lazy[k]);
        lazy[k] = O::id;
    }

    void update(int a, int b, const E& x, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = O::op(lazy[k], x);
            push(k);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = M::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(int a, int b, int k, int l, int r) {
        push(k);
        if (r <= a || b <= l) return M::id;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        return M::op(fold(a, b, 2 * k, l, m),
                     fold(a, b, 2 * k + 1, m, r));
    }
};

// struct M {
//     using T = ll;
//     inline static const T id = 0;
//     static T op(T a, T b) {
//         return a + b;
//     }
// };

// struct O {
//     using E = ll;
//     inline static const E id = 0;
//     static E op(E a, E b) {
//         return a + b;
//     }
// };

// M::T op(M::T a, O::E b) {
//     return a + b;
// }
#line 4 "test/yosupo/range_affine_range_sum.test.cpp"

using ll = long long;

const ll mod = 998244353;

struct M {
    using T = pair<ll, int>;
    inline static const T id = {0, 0};
    static T op(T a, T b) {
        return {(a.first + b.first) % mod, a.second + b.second};
    }
};

struct O {
    using E = pair<ll, ll>;
    inline static const E id = {1, 0};
    static E op(E a, E b) {
        return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
    }
};

M::T act(M::T a, O::E b) {
    return {(a.first * b.first + a.second * b.second) % mod, a.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, int>> a(N, {0, 1});
    for (int i = 0; i < N; i++) cin >> a[i].first;
    LazySegmentTree<M, O, act> st(a);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            st.update(l, r, {b, c});
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.fold(l, r).first << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

