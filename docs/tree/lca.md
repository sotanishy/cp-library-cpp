# Lowest Common Ancestor

This struct calculates the lowest common ancestor between pairs of vertices in a tree.

## Methods

- `LCA(vector<vector<int>>& G, int root)`
    - Builds a lookup table.
    - Time complexity: O(n\lg n)
- `int query(int u, int v)`
    - Returns the lowest common ancestor of $u$ and $v$.
    - Time complexity: O(\lg n)
- `int dist(int u, int v)`
    - Calculates the distance between $u$ and $v$.
    - Time complexity: O(\lg n)