# Bellman-Ford Algorithm

The Bellman-Ford algorithm is an algorithm for finding the shortest paths from a single source vertex to all other vertices in a weighted graph. It can also be used for negative cycle detection.

- `vector<T> bellman_ford(vector<Edge<T>>& G, int V, int s)`
    - Returns the shortest distance from the source vertex $s$ to all vertices in the graph $G$ with $V$ vertices, given the list of its edges. Returns an empty list if $G$ contains a negative cycle.
    - Time complexity: $O(VE)$