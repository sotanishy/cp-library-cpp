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


# :heavy_check_mark: test/aoj/DSL_2_D.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_D.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 11:54:04+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/dual_segment_tree.cpp.html">data-structure/dual_segment_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#include "../../data-structure/dual_segment_tree.cpp"

struct Monoid {
    using T = int;
    inline static const T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    DualSegmentTree<Monoid> st(n);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            st.update(s, t + 1, x);
        } else {
            int i;
            cin >> i;
            cout << st.query(i) << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_D.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"

#line 1 "data-structure/dual_segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename M>
struct DualSegmentTree {
    using T = typename M::T;

    DualSegmentTree(int n) {
        size = 1;
        height = 1;
        while (size < n) size <<= 1, height++;
        lazy.resize(2 * size, M::id);
    }

    T operator[](int k) {
        return query(k);
    }

    void update(int l, int r, const T& x) {
        propagate(l);
        propagate(r - 1);
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = M::op(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);
        }
    }

    T query(int k) {
        propagate(k);
        return lazy[k + size];
    }

private:
    int size, height;
    vector<T> lazy;

    void push(int k) {
        if (lazy[k] == M::id) return;
        lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);
        lazy[2 * k + 1] = M::op(lazy[2 * k + 1], lazy[k]);
        lazy[k] = M::id;
    }

    void propagate(int k) {
        k += size;
        for (int i = height; i > 0; i--) push(k >> i);
    }
};

// struct M {
//     using T = int;
//     inline static const T id = 0;
//     static T op(T a, T b) {
//         return a + b;
//     }
// };
#line 4 "test/aoj/DSL_2_D.test.cpp"

struct Monoid {
    using T = int;
    inline static const T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    DualSegmentTree<Monoid> st(n);
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            st.update(s, t + 1, x);
        } else {
            int i;
            cin >> i;
            cout << st.query(i) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

