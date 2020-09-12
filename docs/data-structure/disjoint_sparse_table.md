# Disjoint Sparse Table

A disjoint sparse table is a data structure that can quickly answer range queries on a static sequence of a semigroup $(T, \cdot)$.

The binary operation $\cdot$ is not required to be idempotent; for idempotent operations, [a sparse table](sparse_table.md) might be faster by a constant factor.

Space complexity: $O(n \lg n)$

## Template parameters

- `T`
    - The type of the elements.

- `T op(T, T)`
    - An associative binary operation $\cdot: T \times T \rightarrow T$.

## Constructor

- `DisjointSparseTable(const vector<T>& v)`
    - Constructs a disjoint sparse table from `v`
    - Time complexity: $O(n \lg n)$

## Member functions

- `T query(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(1)$