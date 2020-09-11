# Minimum Cost Flow

This struct calculates the minimum cost flow of a directed graph.

# Methods

- `MinCostFlow(int V)`
    - Initializes the graph with $V$ vertices.
    - Time complexity: $O(V)$
- `void add_edge(int u, int v, Cap cap, Cost cost)`
    - Adds an edge $(u, v)$ with a capacity $cap$ and a cost $cost$.
    - Time complexity: $O(1)$
- `Cost min_cost_flow(int s, int t, Cap f)`
    - Calculates the minimum cost flow from the source $s$ to the sink $t$ with flow $f$.
    - Time complexity: $O(fE\lg V)$