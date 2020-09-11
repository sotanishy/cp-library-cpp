# Fenwick Tree

A Fenwick tree, or a binary indexed tree, is a data structure that can update elements and calculate prefix sums.

The interface is 0-indexed.

Space complexity: $O(n)$

## Methods

- `FenwickTree(int n)`
    - Constructs a Fenwick tree of size `n` with all elements set to $0$.
    - Time complexity: $O(n)$
- `T sum(int i)`
    - Calculates the prefix sum, i.e. calculates the sum $a_0, a_1, \dots, a_i$
    - Time complexity: $O(\lg n)$
- `void add(int i, T x)`
    - Adds $x$ to $a_i$.
    - Time complexity: $O(\lg n)$
- `int lower_bound(T x)`
    - Returns the first index $i$ such that the prefix sum at $i$ is greater than or equal to $x$
    - Time complexity: $O(\lg n)$

## Note

A Fenwick tree can be generalized to treat any sequence of a commutative monoid.