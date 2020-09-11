# Floyd-Warshall Algorithm

The Floyd-Warshall algorithm is an algorithm for finding the shortest paths between all pairs of vertices in a weighted graph $G$ without negative cycles. If $dist(i, i) < 0$ for any $i \in V$, $G$ contains a negative cycle.

- `void floyd_warshall(vector<vector<T>>& dist)`
    - Calculates the shortest distance between all pairs of vertices in the graph $G$, given its adjacency matrix.
    - Time complexity: $O(V^3)$