# Dijkstra's Algorithm

Dijkstra's algorithm is an algorithm for finding the shortest paths from a single source vertex to all other vertices in a weighted graph without negative edges.

- `vector<T> dijkstra(vector<vector<Edge<T>>>& G, int s)`
    - Returns the shortest distance from the source vertex $s$ to all vertices in the graph $G$, given its adjacency list.
    - Time complexity: $O(E \lg V)$