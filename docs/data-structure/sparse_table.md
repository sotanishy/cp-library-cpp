# Sparse Table

A sparse table is a data structure that can quickly answer range queries on a static sequence of an idempotent semigroup $(T, \cdot)$.

An idempotent binary operation is a mapping $\cdot: T \times T \rightarrow T$ such that $\forall a \in T, a \cdot a = a$.Idempotent binary operations include: max, min, gcd, bitwise and, and bitwise or.

Space complexity: $O(n \lg n)$

## Template parameters

- `S`
    - The idempotent semigroup $(T, \cdot)$ with the following members defined:
        - `T`: the type of the set $T$
        - `T op(T, T)`: an associative and idempotent binary operation $\cdot: T \times T \rightarrow T$

## Constructor

- `SparseTable(const vector<T>& v)`
    - Constructs a sparse table from `v`
    - Time complexity: $O(n \lg n)$

## Member functions

- `T fold(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(1)$