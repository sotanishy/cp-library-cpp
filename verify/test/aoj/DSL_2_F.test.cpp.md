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


# :heavy_check_mark: test/aoj/DSL_2_F.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/DSL_2_F.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 11:54:04+09:00


* see: <a href="http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F">http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/data-structure/lazy_segment_tree.cpp.html">data-structure/lazy_segment_tree.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../../data-structure/lazy_segment_tree.cpp"

 struct S {
    struct V {
        using T = int;
        inline static const T id = (1u << 31) - 1;
        static T op(T a, T b) {
            return min(a, b);
        }
    };

    struct O {
        using E = int;
        inline static const E id = (1u << 31) - 1;
        static E op(E a, E b) {
            return b;
        }
        static E prod(E a, int b) {
            return a;
        }
    };

    static V::T op(V::T a, O::E b) {
        return b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<S> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s, t + 1, x);
        } else {
            cout << st.query(s, t + 1) << "\n";
        }
    }
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "test/aoj/DSL_2_F.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#line 1 "data-structure/lazy_segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

template <typename S>
struct LazySegmentTree {
    using V = typename S::V;
    using T = typename V::T;
    using O = typename S::O;
    using E = typename O::E;

    LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, V::id)) {}
    LazySegmentTree(const vector<T>& v) {
        size = 1;
        height = 0;
        while (size < v.size()) size <<= 1, height++;
        node.resize(2 * size, V::id);
        lazy.resize(2 * size, O::id);
        copy(v.begin(), v.end(), node.begin() + size);
        for (int i = size - 1; i > 0; i--) node[i] = V::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) {
        return query(k, k + 1);
    }

    void update(int a, int b, const E& x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        push(k, r - l);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = O::op(lazy[k], x);
            push(k, r - l);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = V::op(node[2 * k], node[2 * k + 1]);
    }

    T query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        push(k, r - l);
        if (r <= a || b <= l) return V::id;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        return V::op(query(a, b, 2 * k, l, m),
                     query(a, b, 2 * k + 1, m, r));
    }

private:
    int size, height;
    vector<T> node;
    vector<E> lazy;

    void push(int k, int len) {
        if (lazy[k] == O::id) return;
        if (k < size) {
            lazy[2 * k] = O::op(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = O::op(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = S::op(node[k], O::prod(lazy[k], len));
        lazy[k] = O::id;
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
//         static E prod(E a, int b) {
//             return a * b;
//         }
//     };

//     static V::T op(V::T a, O::E b) {
//         return a + b;
//     }
// };
#line 4 "test/aoj/DSL_2_F.test.cpp"

 struct S {
    struct V {
        using T = int;
        inline static const T id = (1u << 31) - 1;
        static T op(T a, T b) {
            return min(a, b);
        }
    };

    struct O {
        using E = int;
        inline static const E id = (1u << 31) - 1;
        static E op(E a, E b) {
            return b;
        }
        static E prod(E a, int b) {
            return a;
        }
    };

    static V::T op(V::T a, O::E b) {
        return b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<S> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s, t + 1, x);
        } else {
            cout << st.query(s, t + 1) << "\n";
        }
    }
}

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>

