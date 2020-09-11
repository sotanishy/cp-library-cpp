# Weighted Union Find

In addition to operations that a union find provides, a weighted union find stores the weights of each node relative to other nodes in the same set.

This version uses path compression and union by size.

Space complexity: $O(n)$

## Methods

- `WeightedUnionFind(int n)`
    - Constructs a weighted union find of size `n`.
    - Time complexity: $O(n)$
- `int find(int x)`
    - Returns the root of the tree $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `T weight(int x)`
    - Returns the weight of $x$ relative to the root of the set.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `void unite(int x, int y, T w)`
    - Unites the set $x$ belongs to and the set $y$ belongs to, so that $weight(y) - weight(x) = w$.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `bool same(int x, int y)`
    - Checks if $x$ and $y$ are in the same set.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `T diff(int x, int y)`
    - Returns the weight of $y$ relative to $x$, i.e. $weight(y) - weight(x)$.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$
- `int size(int x)`
    - Returns the size of the set $x$ belongs to.
    - Time complexity: $\mathrm{amortized}\ O(\alpha(n))$

## Note

$\alpha(x)$ is the inverse Ackermann function.