# Sparse Table

A sparse table is a data structure that can quickly find the minimum value in a range of a static sequence.

Space complexity: $O(n \lg n)$

## Methods

- `SparseTable(const vector<T>& v)`
    - Constructs a sparse table from `v`
    - Time complexity: $O(n \lg n)$
- `T query(int l, int r)`
    - Returns the minimum element in the range $[l, r)$
    - Time complexity: $O(1)$

## Note

A sparse table can handle other associative and idempotent binary operations: max, gcd, bitwise and, bitwise or, etc.