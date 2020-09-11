# Diameter of a Tree

This struct calculates the diameter of the given tree using DFS.


## Methods

- `static int diameter(vector<vector<int>>& G)`
    - Calculates the diameter of the tree $G$ where the  weights of all edges are 1.
    - Time complexity: $O(n)$
- `static T diameter(vector<vector<Edge<T>>>& G)`
    - Calculates the diameter of the tree $G$.
    - Time complexity: $O(n)$