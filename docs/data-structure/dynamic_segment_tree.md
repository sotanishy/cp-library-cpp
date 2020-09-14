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