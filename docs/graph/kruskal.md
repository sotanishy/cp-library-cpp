# Kruskal's Algorithm

Kruskal's algorithm is an algorithm for finding the minimum spanning tree of an undirected weighted graph.

- `T kruskal(vector<Edge<T>>& G, int V)`
    - Returns the weight of the minimum spanning tree of the undirected weighted graph $G$ with $V$ vertices, given the list of its edges.
    - Time complexity: $O(E\lg E)$