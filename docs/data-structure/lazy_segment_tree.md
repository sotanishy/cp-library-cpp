# Lazy Segment Tree

A lazy segment tree stores a sequence $(a_0, a_1, \dots, a_n)$ of a monoid $V$ and operations from an operator monoid $O$.

See the note for the description of a monoid and an operator monoid.

A segment tree with lazy propagation supports range update and range query both in $O(\lg n)$ time.

For point update and range query, use [a segment tree](segment_tree.md)

For range update and point query, use [a dual segment tree](dual_segment_tree.md)

Space complexity: $O(n)$

## Methods

- `LazySegmentTree(int n)`
    - Constructs a segment tree with lazy propagation of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$
- `LazySegmentTree(const vector<T>& v)`
    - Constructs a segment tree with lazy propagation of size `v.size()` using the given sequence.
    - Time complexity: $O(n)$
- `T operator[](int k)`
    - Returns $a_k$.
    - Time complexity: $O(\lg n)$
- `void update(int l, int r, const E& x)`
    - Apply the operator $x$ to $a_l, a_{l+1}, \dots, a_{r-1}$.
    - Time complexity: $O(\lg n)$
- `T query(int a, int b)`
    - Returns $a_a \cdot a_{a+1} \cdot \cdots \cdot a_{b-1}\$.
    - Time complexity: $O(\lg n)$

## Note

The template argument `S` is a class/struct with following members defined:
* `V`: a class/struct representing a monoid $V$, and has the following members defined
    * `T`: the type of the elements in $V$
    * `T id`: the identity element $e$
    * `T op(T, T)`: an associative binary operation $\cdot$
* `O`: a class/struct representing an operator monoid $O$, and has the following members defined
    * `E`: the type of the elements in $O$
    * `E id`: the identity element
    * `E op(E, E)`: an associative binary operation $\circ$
* `T op(T, E)`: the mapping $f: T \times E \rightarrow T$
* `E mul(E, int)`: a function $p(x, k)$ such that for $a \in T, x \in E, k \in \mathbb{N}$, $\left(f(a, x)\right)^k = f(a^k, p(x, b))$

See the verify files for examples of implementation.