# Partially Persistent Union Find

A partially persistent union find can access some past information about the disjoint sets. It offers the following operations:
- merge two sets
- check if two nodes are in the same set at time $t$
- return the size of the set that a node belongs to at time $t$

Space complexity: $O(n + q)$

## Constructor

- `PartiallyPersistentUnionFind(int n)`
    - Constructs a partially persistent union find of size `n`. The initial time is set to 0.
    - Time complexity: $O(n)$

## Member functions

- `int find(time_type t, int x)`
    - Returns the root of the tree $x$ belongs to at time $t$.
    - Time complexity: $O(\lg n)$
- `void unite(int x, int y)`
    - Increments the time by 1, and unites the set $x$ belongs to and the set $y$ belongs to.
    - Time complexity: $O(\lg n)$
- `bool same(time_type t, int x, int y)`
    - Checks if $x$ and $y$ are in the same set at time $t$.
    - Time complexity: $O(\lg n)$
- `int size(time_type t, int x)`
    - Returns the size of the set $x$ belongs to at time $t$.
    - Time complexity: $O(\lg n)$