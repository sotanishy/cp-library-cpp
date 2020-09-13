# Segment Tree

A segment tree is a data structure that stores a sequence $(a_0, a_1, \dots, a_{n-1})$ of a monoid $(T, \cdot, e)$ and offers point update and range query operations.

For range update and point query, use a dual segment tree.

For range update and range query, use a segment tree with lazy propagation.

Space complexity: $O(n)$

## Template parameters

- `M`
    - A monoid $(T, \cdot, e)$. It must have the following publicly accessible members:
        - `T`: the type of the set $T$
        - `T id`: the identity element $e$
        - `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$

## Constructor

- `SegmentTree(int n)`
    - Constructs a segment tree of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$
- `SegmentTree(const vector<T>& v)`
    - Constructs a segment tree of size `n = v.size()` using the values in `v`.
    - Time complexity: $O(n)$

## Member functions

- `T operator[](int k)`
    - Returns $a_k$.
    - Time complexity: $O(1)$
- `void update(int k, const T& x)`
    - Sets $a_k$ to $x$.
    - Time complexity: $O(\lg n)$
- `T fold(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$. Returns $e$ if $l = r$.
    - Time complexity: $O(\lg n)$
- `int find_first(int l, const function<bool(T)>& cond)`
    - Returns the first index $r$ after $l$ such that $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ satisfies the condition `cond`, assuming that the sequence is monotonic. Returns `-1` if not found.
    - Time complexity: $O(\lg n)$
- `int find_last(int r, const function<bool(T)>& cond)`
    - Returns the last index $l$ before $r$ such that $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$ satisfies the condition `cond`, assuming that the sequence is monotonic. Returns `-1` if not found.
    - Time complexity: $O(\lg n)$