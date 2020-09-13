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


# :x: test/yosupo/range_affine_range_sum.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/range_affine_range_sum.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/range_affine_range_sum">https://judge.yosupo.jp/problem/range_affine_range_sum</a>


## Depends on

* :x: <a href="../../../library/data-structure/lazy_segment_tree.cpp.html">Segment Tree with Lazy Propagation <small>(data-structure/lazy_segment_tree.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../data-structure/lazy_segment_tree.cpp"

using ll = long long;

const ll mod = 998244353;

struct S {
    struct V {
        using T = ll;
        inline static const T id = 0;
        static T op(T a, T b) {
            return (a + b) % mod;
        }
    };

    struct O {
        using E = pair<ll, ll>;
        inline static const E id = {1, 0};
        static E op(E a, E b) {
            return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
        }
    };

    static V::T op(V::T a, O::E b) {
        return (a * b.first + b.second) % mod;
    }

    static O::E mul(O::E a, size_t b) {
        return {a.first, a.second * b % mod};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    LazySegmentTree<S> st(a);
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
            cout << st.fold(l, r) << "\n";
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
template <typename S>
struct LazySegmentTree {
    using V = typename S::V;
    using T = typename V::T;
    using O = typename S::O;
    using E = typename O::E;

    LazySegmentTree(size_t n) : LazySegmentTree(vector<T>(n, V::id)) {}
    LazySegmentTree(const vector<T>& v) {
        size = 1;
        height = 0;
        while (size < v.size()) size <<= 1, height++;
        node.resize(2 * size, V::id);
        lazy.resize(2 * size, O::id);
        copy(v.begin(), v.end(), node.begin() + size);
        for (size_t i = size - 1; i > 0; i--) node[i] = V::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](size_t k) {
        return fold(k, k + 1);
    }

    void update(size_t l, size_t r, const E& x) { update(l, r, x, 1, 0, size); }

    T fold(size_t l, size_t r) { return fold(l, r, 1, 0, size); }

private:
    size_t size, height;
    vector<T> node;
    vector<E> lazy;

    void push(size_t k, size_t len) {
        if (lazy[k] == O::id) return;
        if (k < size) {
            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = S::op(node[k], S::mul(lazy[k], len));
        lazy[k] = O::id;
    }

    void update(size_t a, size_t b, const E& x, size_t k, size_t l, size_t r) {
        push(k, r - l);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = O::op(lazy[k], x);
            push(k, r - l);
            return;
        }
        size_t m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = V::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(size_t a, size_t b, size_t k, int l, int r) {
        push(k, r - l);
        if (r <= a || b <= l) return V::id;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        return V::op(fold(a, b, 2 * k, l, m),
                     fold(a, b, 2 * k + 1, m, r));
    }
};

// struct S {
//     struct V {
//         using T = ll;
//         inline static const T id = 0;
//         static T op(T a, T b) {
//             return a + b;
//         }
//     };

//     struct O {
//         using E = ll;
//         inline static const E id = 0;
//         static E op(E a, E b) {
//             return a + b;
//         }
//     };

//     static V::T op(V::T a, O::E b) {
//         return a + b;
//     }

//     static O::E mul(O::E a, size_t b) {
//         return a * b;
//     }
// };
#line 4 "test/yosupo/range_affine_range_sum.test.cpp"

using ll = long long;

const ll mod = 998244353;

struct S {
    struct V {
        using T = ll;
        inline static const T id = 0;
        static T op(T a, T b) {
            return (a + b) % mod;
        }
    };

    struct O {
        using E = pair<ll, ll>;
        inline static const E id = {1, 0};
        static E op(E a, E b) {
            return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
        }
    };

    static V::T op(V::T a, O::E b) {
        return (a * b.first + b.second) % mod;
    }

    static O::E mul(O::E a, size_t b) {
        return {a.first, a.second * b % mod};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    LazySegmentTree<S> st(a);
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
            cout << st.fold(l, r) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

