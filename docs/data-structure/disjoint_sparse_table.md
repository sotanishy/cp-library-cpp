# Disjoint Sparse Table

A disjoint sparse table is a data structure that can quickly answer range queries on a static sequence of a semigroup $(T, \cdot)$.

If the binary operation $\cdot$ is idempotent, a sparse table might be faster by a constant factor.

Space complexity: $O(n \lg n)$

## Template parameters

- `S`
    - The idempotent semigroup $(T, \cdot)$ with the following members defined:
        - `T`: the type of the set $T$
        - `T op(T, T)`: an associative binary operation $\cdot: T \times T \rightarrow T$

## Constructor

- `DisjointSparseTable(const vector<T>& v)`
    - Constructs a disjoint sparse table from `v`
    - Time complexity: $O(n \lg n)$

## Member functions

- `T fold(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(1)$