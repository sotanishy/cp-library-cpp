# Prim's Algorithm

Prim's algorithm is an algorithm for finding the minimum spanning tree of an undirected weighted graph.

- `T prim(vector<vector<Edge<T>>>& G)`
    - Returns the weight of the minimum spanning tree of the undirected weighted graph $G$, given its adjancency list.
    - Time complexity: O(E\lg V)