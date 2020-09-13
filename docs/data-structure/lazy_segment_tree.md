# Segment Tree with Lazy Propagation

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
        - `E mul(E, size_t)`: a function $p: E \times \mathbb{N} \rightarrow E$ such that for $a \in T, x \in E, k \in \mathbb{N}$, $(a_i * x) \cdot \cdots \cdot (a_{i+k-1} * x) = (a_i \cdot \cdots \cdot a_{i+k-1}) * p(x, k)$

## Constructor

- `LazySegmentTree(size_t n)`
    - Constructs a segment tree with lazy propagation of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$
- `LazySegmentTree(const vector<T>& v)`
    - Constructs a segment tree with lazy propagation of size `n = v.size()` using the values in `v`.
    - Time complexity: $O(n)$

## Member functions

- `T operator[](size_t k)`
    - Returns $a_k$.
    - Time complexity: $O(\lg n)$
- `void update(size_t l, size_t r, const E& x)`
    - Apply the operator $x$ to $a_l, a_{l+1}, \dots, a_{r-1}$.
    - Time complexity: $O(\lg n)$
- `T fold(size_t l, size_t r)`
    - Returns $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}\$.
    - Time complexity: $O(\lg n)$