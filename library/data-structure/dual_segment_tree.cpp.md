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


# :heavy_check_mark: Dual Segment Tree <small>(data-structure/dual_segment_tree.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/dual_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 16:31:52+09:00




# Dual Segment Tree

A dual segment tree is a data structure that stores a sequence $(a_0, a_1, \dots, a_{n-1})$ of a monoid $(T, \cdot, e)$ and offers range update and point query operations.

For point update and range query, use a segment tree.

For range update and range query, use a segment tree with lazy propagation.

Space complexity: $O(n)$

## Template parameters

- `M`
    - A monoid $(T, \cdot, e)$ with the following members defined:
        - `T`: the type of the set $T$
        - `T id`: the identity element $e$
        - `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$

## Constructor

- `DualSegmentTree(int n)`
    - Constructs a dual segment tree of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$

## Methods

- `T operator[](int k)`
    - Returns $a_k$.
    - Time complexity: $O(\lg n)$
- `void update(int l, int r, const T& x)`
    - Apply the operator $x$ to $a_l, a_{l+1}, \dots, a_{r-1}$.
    - Time complexity: $O(\lg n)$

## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_D.test.cpp.html">test/aoj/DSL_2_D.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_E.test.cpp.html">test/aoj/DSL_2_E.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Dual Segment Tree
 * @docs docs/data-structure/dual_segment_tree.md
 */
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
        k += size;
        propagate(k);
        return lazy[k];
    }

    void update(int l, int r, const T& x) {
        l += size;
        r += size;
        propagate(l);
        propagate(r - 1);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = M::op(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);
        }
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
        for (int i = height; i > 0; i--) push(k >> i);
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/dual_segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Dual Segment Tree
 * @docs docs/data-structure/dual_segment_tree.md
 */
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
        k += size;
        propagate(k);
        return lazy[k];
    }

    void update(int l, int r, const T& x) {
        l += size;
        r += size;
        propagate(l);
        propagate(r - 1);
        for (; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = M::op(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);
        }
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
        for (int i = height; i > 0; i--) push(k >> i);
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

