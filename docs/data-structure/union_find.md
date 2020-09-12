# Union Find

A union find, or a disjoint set union, is a data structure that stores a collection of disjoint sets.

This version uses path compression and union by size.

Space complexity: $O(n)$

## Constructor

- `UnionFind(int n)`
    - Constructs a union find of size `n`.
    - Time complexity: $O(n)$

## Member functions

- `int find(int x)`
    - Returns the root of the tree $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(int x, int y)`
    - Unites the set $x$ belongs to and the set $y$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(int x, int y)`
    - Checks if $x$ and $y$ are in the same set.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `int size(int x)`
    - Returns the size of the set $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ is the inverse Ackermann function.