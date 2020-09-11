# Bipartite Matching

This struct calculates the maximum matching of a bipartite graph using the Ford-Fulkerson algorithm.

# Methods

- `BipartiteMatching(int n)`
    - Initializes the bipartite graph with $n$ vertices.
    - Time complexity: $O(n)$
- `void add_edge(int u, int v)`
    - Adds an edge $(u, v)$.
    - Time complexity: $O(1)$
- `int bipartite_matching()`
    - Calculates the maximum matching of the bipartite graph.
    - Time complexity: $O(VE)$