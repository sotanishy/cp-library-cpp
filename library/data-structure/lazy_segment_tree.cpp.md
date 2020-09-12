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
    - Last commit date: 2020-09-11 18:56:12+09:00




# Lazy Segment Tree

A segment tree with lazy propagation is a data structure that stores a sequence $(a_0, a_1, \dots, a_{n-1})$ of a monoid $(T, \cdot, e_V)$ and handles actions $*$ of an operator monoid $(E, \circ, e_O)$. It offers range update and range query operations.

The action $*: T \times E \rightarrow T$ satisfies the following conditions:
- $\forall a \in T, a * e_O = a$
- $\forall f, g \in E, a \in T, a * (f \circ g) = (a * f) * g$

For point update and range query, use [a segment tree](segment_tree.md)
For range update and point query, use [a dual segment tree](dual_segment_tree.md)

Space complexity: $O(n)$

## Template parameters

- `S`
    - It has two member types and two member functions.
        - `V`: a monoid $(T, \cdot, e_V)$. It must have the following publicly accessible members:
            - `T`: the type of the set $T$
            - `T id`: the identity element $e_V$
            - `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$
        - `O`: an operator monoid $(E, \circ, e_O)$. It must have the following publicly accessible members:
            - `E`: the type of the set $E$
            - `E id`: the identity element $e_O$
            - `E op(E, E)`: an associative binary operation $\circ: E \times E \rightarrow E$
        - `T op(T, E)`: an action $*: T \times E \rightarrow T$.
        - `E mul(E, int)`: a function $p: E \times \mathbb{N} \rightarrow E$ such that for $a \in T, x \in E, k \in \mathbb{N}$, $(a_i * x) \cdot \cdots \cdot (a_{i+k-1} * x) = (a_i \cdot \cdots \cdot a_{i+k-1}) * p(x, k)$

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
- `T query(int a, int b)`
    - Returns $a_a \cdot a_{a+1} \cdot \cdots \cdot a_{b-1}\$.
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
        node[k] = S::op(node[k], S::mul(lazy[k], len));
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
//     };

//     static V::T op(V::T a, O::E b) {
//         return a + b;
//     }

//     static O::E mul(O::E a, int b) {
//         return a * b;
//     }
// };
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
        node[k] = S::op(node[k], S::mul(lazy[k], len));
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
//     };

//     static V::T op(V::T a, O::E b) {
//         return a + b;
//     }

//     static O::E mul(O::E a, int b) {
//         return a * b;
//     }
// };

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

