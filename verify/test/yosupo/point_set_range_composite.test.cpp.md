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


# :x: test/yosupo/point_set_range_composite.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0b58406058f6619a0f31a172defc0230">test/yosupo</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/yosupo/point_set_range_composite.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-13 10:49:49+09:00


* see: <a href="https://judge.yosupo.jp/problem/point_set_range_composite">https://judge.yosupo.jp/problem/point_set_range_composite</a>


## Depends on

* :question: <a href="../../../library/data-structure/segment_tree.cpp.html">Segment Tree <small>(data-structure/segment_tree.cpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../data-structure/segment_tree.cpp"

using ll = long long;

const ll mod = 998244353;

struct Monoid {
    using T = pair<ll, ll>;
    static inline T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, ll>> ab(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        ab[i] = {a, b};
    }
    SegmentTree<Monoid> st(ab);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            st.update(p, {c, d});
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            auto f = st.fold(l, r);
            cout << (f.first * x + f.second) % mod << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/yosupo/point_set_range_composite.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#line 1 "data-structure/segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Segment Tree
 * @docs docs/data-structure/segment_tree.md
 */
template <typename M>
struct SegmentTree {
    using T = typename M::T;

    size_t size;
    vector<T> node;

    SegmentTree(size_t n) : SegmentTree(vector<T>(n, M::id)) {}
    SegmentTree(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        node.resize(2 * size, M::id);
        copy(v.begin(), v.end(), node.begin() + size);
        for (size_t i = size - 1; i > 0; i--) node[i] = M::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](size_t k) const {
        return node[k + size];
    }

    void update(size_t k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);
    }

    T fold(size_t l, size_t r) {
        T vl = M::id, vr = M::id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = M::op(vl, node[l++]);
            if (r & 1) vr = M::op(node[--r], vr);
        }
        return M::op(vl, vr);
    }

    int find_first(size_t l, const function<bool(T)>& cond) {
        T vl = M::id;
        size_t r = 2 * size;
        for (l += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                T nxt = M::op(vl, node[l]);
                if (cond(nxt)) {
                    while (l < size) {
                        nxt = M::op(vl, node[2 * l]);
                        if (cond(nxt)) l = 2 * l;
                        else vl = nxt, l = 2 * l + 1;
                    }
                    return l - size;
                }
                vl = nxt;
                l++;
            }
        }
        return -1;
    }

    int find_last(size_t r, const function<bool(T)>& cond) {
        T vr = M::id;
        size_t l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                r--;
                T nxt = M::op(node[r], vr);
                if (cond(nxt)) {
                    while (r < size) {
                        nxt = M::op(node[2 * r + 1], vr);
                        if (cond(nxt)) r = 2 * r + 1;
                        else vr = nxt, r = 2 * r;
                    }
                    return r - size;
                }
                vr = nxt;
            }
        }
        return -1;
    }
};

// struct Monoid {
//     using T = int;
//     static inline T id = (1u << 31) - 1;
//     static T op(T a, T b) {
//         return min(a, b);
//     }
// };
#line 4 "test/yosupo/point_set_range_composite.test.cpp"

using ll = long long;

const ll mod = 998244353;

struct Monoid {
    using T = pair<ll, ll>;
    static inline T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first % mod, (a.second * b.first + b.second) % mod};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<ll, ll>> ab(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        ab[i] = {a, b};
    }
    SegmentTree<Monoid> st(ab);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            st.update(p, {c, d});
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            auto f = st.fold(l, r);
            cout << (f.first * x + f.second) % mod << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

