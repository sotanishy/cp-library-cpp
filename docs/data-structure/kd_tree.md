# k-d Tree

A k-d tree is a data structure that stores points in a $k$-dimensional space, which allows for efficient range searches.

This k-d tree supports axis-aligned rectangular range searches in a 2-dimensional space.

Space complexity: $O(n)$

## Methods

- `void add_point(int id, T x, T y)`
    - Adds the point $(x, y)$ labeled `id`.
    - Time complexity: $O(1)$
- `void build()`
    - Builds a k-d tree.
    - Time complexity: $O(n\lg^2 n)$
- `vector<int> search(T sx, T tx, T sy, T ty)`
    - Returns the labels of points in the rectangular range from $(sx, sy)$ to $(tx, ty)$.
    - Time complexity: $O(\sqrt{N} + m)$, where $m$ is the number of reported points