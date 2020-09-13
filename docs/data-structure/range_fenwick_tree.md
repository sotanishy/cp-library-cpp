# Fenwick Tree with Range Update

A Fenwick tree with range update uses two internal Fenwick trees to efficiently handle range updates.

The interface is 0-indexed.

Space complexity: $O(n)$

## Template parameters

- `RangeFenwickTree(size_t n)`
    - Constructs a Fenwick tree with range update of size `n` with all elements initialized to $0$.
    - Time complexity: $O(n)$

## Member functions

- `T sum(size_t i)`
    - Calculates the prefix sum, i.e. calculates the sum $a_0, a_1, \dots, a_i$
    - Time complexity: $O(\lg n)$
- `void add(size_t l, size_t r, T x)`
    - Adds $x$ to $a_l, \dots, a_r$
    - Time complexity: $O(\lg n)$