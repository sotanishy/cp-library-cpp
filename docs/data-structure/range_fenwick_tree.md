# Fenwick Tree with Range Update

A Fenwick tree with range update uses two internal Fenwick trees to efficiently handle range updates.

The interface is 0-indexed.

Space complexity: $O(n)$

## Template parameters

- `RangeFenwickTree(int n)`
    - Constructs a Fenwick tree with range update of size `n` with all elements initialized to $0$.
    - Time complexity: $O(n)$

## Member functions

- `T sum(int i)`
    - Calculates the prefix sum, i.e. calculates the sum $a_0, a_1, \dots, a_i$
    - Time complexity: $O(\lg n)$
- `void add(int l, int r, T x)`
    - Adds $x$ to $a_l, \dots, a_r$
    - Time complexity: $O(\lg n)$