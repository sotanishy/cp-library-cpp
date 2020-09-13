# Segment Tree with Lazy Propagation

A segment tree with lazy propagation is a data structure that stores a sequence $(a_0, a_1, \dots, a_{n-1})$ of a monoid $(T, \cdot, e_M)$ and handles actions $*$ of an operator monoid $(E, \circ, e_O)$. It offers range update and range query operations.

The action $*: T \times E \rightarrow T$ satisfies the following conditions:
- $\forall a \in T, a * e_O = a$
- $\forall a, b \in T, f \in E, (a \cdot b) * f = (a * f) \cdot (b * f)$
- $\forall a \in T, f, g \in E, a * (f \circ g) = (a * f) * g$

For point update and range query, use a segment tree.

For range update and point query, use a dual segment tree.

Space complexity: $O(n)$

## Template parameters

- `M`
    - A monoid $(T, \cdot, e_M)$ with the following members defined:
        - `T`: the type of the set $T$
        - `T id`: the identity element $e_M$
        - `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$
- `O`
    - An operator monoid $(E, \circ, e_O)$. It must have the following members defined:
        - `E`: the type of the set $E$
        - `E id`: the identity element $e_O$
        - `E op(E, E)`: an associative binary operation $\circ: E \times E \rightarrow E$
- `T act(T, E)`
    - An action $*: T \times E \rightarrow T$.

## Constructor

- `LazySegmentTree(int n)`
    - Constructs a segment tree with lazy propagation of size `n` with all elements set to the identity $e_M$.
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