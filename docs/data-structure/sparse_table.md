# Sparse Table

A sparse table is a data structure that can quickly answer range queries on a static sequence of a semigroup $(T, \cdot)$.

The binary operation $\cdot: T \times T \rightarrow T$ must be idempotent i.e. $\forall a \in T, a \cdot a = a$

Idempotent binary operations include: max, min, gcd, bitwise and, and bitwise or.

Space complexity: $O(n \lg n)$

## Template parameters

- `T`
    - The type of the elements.

- `T op(T, T)`
    - An associative and idempotent binary operation $\cdot: T \times T \rightarrow T$.

## Constructor

- `SparseTable(const vector<T>& v)`
    - Constructs a sparse table from `v`
    - Time complexity: $O(n \lg n)$

## Member functions

- `T query(int l, int r)`
    - Calculates $a_l \cdot a_{l+1} \cdot \cdots \cdot a_{r-1}$.
    - Time complexity: $O(1)$