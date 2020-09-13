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


# :heavy_check_mark: Fenwick Tree <small>(data-structure/fenwick_tree.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/fenwick_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 04:40:59+09:00




# Fenwick Tree

A Fenwick tree, or a binary indexed tree, is a data structure that stores a sequence $(a_0, a_1, \dots, a_{n-1})$ of a commutative monoid $(T, \cdot, e)$ and offers point update and prefix fold operations.

Space complexity: $O(n)$

## Template parameters

- `M`
    - A commutative monoid $(T, \cdot, e)$. It must have the following publicly accessible members:
        - `T`: the type of the set $T$
        - `T id`: the identity element $e$
        - `T op(T, T)`: an associative and commutative binary operation $\cdot: T \times T \rightarrow T$

## Constructor

- `FenwickTree(int n)`
    - Constructs a Fenwick tree of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$

## Member functions

- `T prefix_fold(int i)`
    - Calculates $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$
    - Time complexity: $O(\lg n)$
- `void update(int i, T x)`
    - Update $a_i$ with $a_i \cdot x$
    - Time complexity: $O(\lg n)$
- `int find_first(const function<bool(T)>& cond)`
    - Returns the first index $i$ such that $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ satisfies the condition `cond`. Returns $n$ if not found.
    - Time complexity: $O(\lg n)$

## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/DSL_2_B.test.cpp.html">test/aoj/DSL_2_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fenwick Tree
 * @docs docs/data-structure/fenwick_tree.md
 */
template <typename M>
struct FenwickTree {
    using T = typename M::T;

    int n;
    vector<T> data;

    FenwickTree(int n) : n(n), data(n+1, M::id) {}

    T prefix_fold(int i) {
        T ret = M::id;
        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);
        return ret;
    }

    void update(int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] = M::op(data[i], x);
    }

    int find_first(const function<bool(T)>& cond) {
        int k = 1;
        while (k * 2 <= n) k <<= 1;
        int i = 0;
        T x = M::id;
        for (; k > 0; k >>= 1) {
            if (i + k <= n && !cond(M::op(x, data[i+k]))) {
                x = M::op(x, data[i+k]);
                i += k;
            }
        }
        return i - 1;
    }
};

// struct Monoid {
//     using T = int;
//     static inline T id = (1u << 31) - 1;
//     static T op(T a, T b) {
//         return min(a, b);
//     }
// };
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/fenwick_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fenwick Tree
 * @docs docs/data-structure/fenwick_tree.md
 */
template <typename M>
struct FenwickTree {
    using T = typename M::T;

    int n;
    vector<T> data;

    FenwickTree(int n) : n(n), data(n+1, M::id) {}

    T prefix_fold(int i) {
        T ret = M::id;
        for (; i > 0; i -= i & -i) ret = M::op(ret, data[i]);
        return ret;
    }

    void update(int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] = M::op(data[i], x);
    }

    int find_first(const function<bool(T)>& cond) {
        int k = 1;
        while (k * 2 <= n) k <<= 1;
        int i = 0;
        T x = M::id;
        for (; k > 0; k >>= 1) {
            if (i + k <= n && !cond(M::op(x, data[i+k]))) {
                x = M::op(x, data[i+k]);
                i += k;
            }
        }
        return i - 1;
    }
};

// struct Monoid {
//     using T = int;
//     static inline T id = (1u << 31) - 1;
//     static T op(T a, T b) {
//         return min(a, b);
//     }
// };

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

