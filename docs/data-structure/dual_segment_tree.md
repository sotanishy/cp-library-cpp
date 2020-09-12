# Dual Segment Tree

A dual segment tree is a data structure that stores a sequence $(a_0, a_1, \dots, a_{n-1})$ of a monoid $(T, \cdot, e)$ and offers range update and point query operations.

For point update and range query, use [a segment tree](segment_tree.md)
For range update and range query, use [a segment tree with lazy propagation](lazy_segment_tree.md)

Space complexity: $O(n)$

## Template parameters

- `M`
    - A monoid $(T, \cdot, e)$. It must have the following publicly accessible members:
        - `T`: the type of the set $T$
        - `T id`: the identity element $e$
        - `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$

## Constructor

- `DualSegmentTree(int n)`
    - Constructs a dual segment tree of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$

## Methods

- `T operator[](int k)`
    - Returns $a_k$ (same as `T query(int k)`).
    - Time complexity: $O(\lg n)$
- `void update(int l, int r, const T& x)`
    - Apply the operator $x$ to $a_l, a_{l+1}, \dots, a_{r-1}$.
    - Time complexity: $O(\lg n)$
- `T query(int k)`
    - Returns $a_k$ (same as `T operator[](int k)`).
    - Time complexity: $O(\lg n)$