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


# :heavy_check_mark: Segment Tree with Lazy Propagation <small>(data-structure/lazy_segment_tree.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/lazy_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 04:40:59+09:00




# Segment Tree with Lazy Propagation

A segment tree with lazy propagation is a data structure that stores a sequence $(a_0, a_1, \dots, a_{n-1})$ of a monoid $(T, \cdot, e_V)$ and handles actions $*$ of an operator monoid $(E, \circ, e_O)$. It offers range update and range query operations.

The action $*: T \times E \rightarrow T$ satisfies the following conditions:
- $\forall a \in T, a * e_O = a$
- $\forall a, b \in T, f \in E, (a \cdot b) * f = (a * f) \cdot (b * f)$
- $\forall a \in T, f, g \in E, a * (f \circ g) = (a * f) * g$

For point update and range query, use a segment tree.

For range update and point query, use a dual segment tree.

Space complexity: $O(n)$

## Template parameters

- `M`
    - A monoid $(T, \cdot, e_V)$. It must have the following publicly accessible members:
        - `T`: the type of the set $T$
        - `T id`: the identity element $e_V$
        - `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$
- `O`
    - An operator monoid $(E, \circ, e_O)$. It must have the following publicly accessible members:
        - `E`: the type of the set $E$
        - `E id`: the identity element $e_O$
        - `E op(E, E)`: an associative binary operation $\circ: E \times E \rightarrow E$
- `M::T act(M::T, O::E)`
    - An action $*: T \times E \rightarrow T$.

## Constructor

- `LazySegmentTree(int n)`
    - Constructs a segment tree with lazy propagation of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$
- `LazySegmentTree(const vector<T>& v)`
    - Constructs a segment tree with lazy propagation of size `n = v.size()` using the values in `v`.
    - Time complexity: $O(n)$

## Member functions

- `T operator[](int k)`
    - Returns $a_k$.
    - Time complexity: $O(\lg n)$
- `void update(int l, int r, const E& x)`
    - Apply the operator $x$ to $a_l, a_{l+1}, \dots, a_{r-1}$.
    - Time complexity: $O(\lg n)$
- `T fold(int l, int r)`
    - Returns $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}\$.
    - Time complexity: $O(\lg n)$

## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_F.test.cpp.html">test/aoj/DSL_2_F.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_G.lazy_segment_tree.test.cpp.html">test/aoj/DSL_2_G.lazy_segment_tree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/range_affine_range_sum.test.cpp.html">test/yosupo/range_affine_range_sum.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
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

// struct V {
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

// V::T op(V::T a, O::E b) {
//     return a + b;
// }
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
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

// struct V {
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

// V::T op(V::T a, O::E b) {
//     return a + b;
// }

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

