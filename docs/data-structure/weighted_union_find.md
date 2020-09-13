# Weighted Union Find

In addition to operations that a union find provides, a weighted union find stores the weights of each node relative to other nodes in the same set.

This version uses path compression and union by size.

Space complexity: $O(n)$

## Template parameters

- `T`
    - The type of the weights

## Constructor

- `WeightedUnionFind(size_t n)`
    - Constructs a weighted union find of size `n`.
    - Time complexity: $O(n)$

## Member functions

- `size_t find(size_t x)`
    - Returns the root of the tree $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `T weight(size_t x)`
    - Returns the weight of $x$ relative to the root of the set.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(size_t x, size_t y, T w)`
    - Unites the set $x$ belongs to and the set $y$ belongs to, so that $weight(y) - weight(x) = w$.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(size_t x, size_t y)`
    - Checks if $x$ and $y$ are in the same set.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `T diff(size_t x, size_t y)`
    - Returns the weight of $y$ relative to $x$, i.e. $weight(y) - weight(x)$.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `size_t size(size_t x)`
    - Returns the size of the set $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ is the inverse Ackermann function.