# Dual Segment Tree

A dual segment tree stores a sequence $(a_0, a_1, \dots, a_n)$ of an operator monoid $M$.

See the note for how to use the template argument.

A dual segment tree supports range update and point query both in $O(\lg n)$ time.
For point update and range query, use [a segment tree](segment_tree.md)
For range update and range query, use [a segment tree with lazy propagation](lazy_segment_tree.md)

Space complexity: $O(n)$

## Methods

- `DualSegmentTree(int n)`
    - Constructs a dual segment tree of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$
- `T operator[](int k)`
    - Returns $a_k$ (same as `T query(int k)`).
    - Time complexity: $O(\lg n)$
- `void update(int l, int r, const T& x)`
    - Apply the operator $x$ to $a_l, a_{l+1}, \dots, a_{r-1}$.
    - Time complexity: $O(\lg n)$
- `T query(int k)`
    - Returns $a_k$ (same as `T operator[](int k)`).
    - Time complexity: $O(\lg n)$

## Note

The template argument `M` represents a monoid $(T, \cdot, e)$ and is a class/struct with the following members defined:
* `T`: the type of the set $T$
* `T id`: the identity element $e$
* `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$

See the verify files for examples of implementation.