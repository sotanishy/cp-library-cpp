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


# :warning: Dynamic Segment Tree <small>(data-structure/dynamic_segment_tree.cpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/dynamic_segment_tree.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-14 16:31:52+09:00




# Dynamic Segment Tree

A dynamic segment tree is a data structure that stores a sequence $(a_0, a_1, \dots, a_{n-1})$ of a monoid $(T, \cdot, e)$ and offers point update and range query operations.

If $n$ is small enough (less than around $10^6$), use a regular segment tree.

For range update and point query, use a dual segment tree.

For range update and range query, use a segment tree with lazy propagation.

Space complexity: $O(m\lg n)$, where $m$ is the number of elements added.

## Template parameters

- `M`
    - A monoid $(T, \cdot, e)$ with the following members defined:
        - `T`: the type of the set $T$
        - `T id`: the identity element $e$
        - `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$

## Constructor

- `DynamicSegmentTree(int n)`
    - Constructs a segment tree of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(\lg n)$

## Member functions

- `T operator[](int k)`
    - Returns $a_k$.
    - Time complexity: $O(\lg n)$
- `void update(int k, const T& x)`
    - Sets $a_k$ to $x$.
    - Time complexity: $O(\lg n)$
- `T fold(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$. Returns $e$ if $l = r$.
    - Time complexity: $O(\lg n)$

## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Dynamic Segment Tree
 * @docs docs/data-structure/dynamic_segment_tree.md
 */
template <typename M>
struct DynamicSegmentTree {
    using T = typename M::T;

    DynamicSegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        root = new Node();
    }

    T operator[](int k) const {
        return fold(k, k + 1);
    }

    void update(int k, const T& x) { update(k, x, root, 0, size); }

    T fold(int l, int r) { return fold(l, r, root, 0, size); }

private:
    struct Node {
        Node* left;
        Node* right;
        T val;
        Node() : left(nullptr), right(nullptr), val(M::id) {}
    };

    Node* root;
    int size;

    void update(int k, const T& x, Node* n, int l, int r) {
        if (r - l == 1) {
            n->val = x;
            return;
        }
        int m = (l + r) / 2;
        if (k < m) {
            if (!n->left) n->left = new Node();
            update(k, x, n->left, l, m);
            n->val = M::op(n->left->val, n->right ? n->right->val : M::id);
        } else {
            if (!n->right) n->right = new Node();
            update(k, x, n->right, m, r);
            n->val = M::op(n->left ? n->left->val : M::id, n->right->val);
        }
    }

    T fold(int a, int b, Node* n, int l, int r) {
        if (a <= l && r <= b) return n->val;
        if (r <= a || b <= l) return M::id;
        int m = (l + r) / 2;
        T vl = n->left ? fold(a, b, n->left, l, m) : M::id;
        T vr = n->right ? fold(a, b, n->right, m, r) : M::id;
        return vr + vr;
    }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "data-structure/dynamic_segment_tree.cpp"
#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Dynamic Segment Tree
 * @docs docs/data-structure/dynamic_segment_tree.md
 */
template <typename M>
struct DynamicSegmentTree {
    using T = typename M::T;

    DynamicSegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        root = new Node();
    }

    T operator[](int k) const {
        return fold(k, k + 1);
    }

    void update(int k, const T& x) { update(k, x, root, 0, size); }

    T fold(int l, int r) { return fold(l, r, root, 0, size); }

private:
    struct Node {
        Node* left;
        Node* right;
        T val;
        Node() : left(nullptr), right(nullptr), val(M::id) {}
    };

    Node* root;
    int size;

    void update(int k, const T& x, Node* n, int l, int r) {
        if (r - l == 1) {
            n->val = x;
            return;
        }
        int m = (l + r) / 2;
        if (k < m) {
            if (!n->left) n->left = new Node();
            update(k, x, n->left, l, m);
            n->val = M::op(n->left->val, n->right ? n->right->val : M::id);
        } else {
            if (!n->right) n->right = new Node();
            update(k, x, n->right, m, r);
            n->val = M::op(n->left ? n->left->val : M::id, n->right->val);
        }
    }

    T fold(int a, int b, Node* n, int l, int r) {
        if (a <= l && r <= b) return n->val;
        if (r <= a || b <= l) return M::id;
        int m = (l + r) / 2;
        T vl = n->left ? fold(a, b, n->left, l, m) : M::id;
        T vr = n->right ? fold(a, b, n->right, m, r) : M::id;
        return vr + vr;
    }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

