# Ford-Fulkerson Algorithm

The Ford-Fulkerson algorithm is an algorithm for findng the maximum flow. It continuously finds an augmenting path in the residual graph using DFS and sends flow along the path.

# Methods

- `FordFulkerson(int n)`
    - Initializes the graph with $n$ vertices.
    - Time complexity: $O(n)$
- `void add_edge(int u, int v, T cap)`
    - Adds an edge $(u, v)$ with a capacity $cap$.
    - Time complexity: $O(1)$
- `T max_flow(int s, int t)`
    - Calculates the maximum flow from the source $s$ to the sink $t$.
    - Time complexity: $O(Ef)$