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

- `FenwickTree(size_t n)`
    - Constructs a Fenwick tree of size `n` with all elements set to the identity $e$.
    - Time complexity: $O(n)$

## Member functions

- `T prefix_fold(size_t i)`
    - Calculates $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$
    - Time complexity: $O(\lg n)$
- `void update(size_t i, T x)`
    - Update $a_i$ with $a_i \cdot x$
    - Time complexity: $O(\lg n)$
- `size_t find_first(const function<bool(T)>& cond)`
    - Returns the first index $i$ such that $a_0 \cdot a_1 \cdot \cdots \cdot a_{i-1}$ satisfies the condition `cond`. Returns $n$ if not found.
    - Time complexity: $O(\lg n)$