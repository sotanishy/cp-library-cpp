# Strongly Connected Components

This struct decomposes the given graph $G$ into strongly connected components (SCCs) i.e. subgraphs of $G$ that are strongly connected and maximal, using Kosaraju's algorithm.

If each SCC is contracted into a single vertex, the resulting graph will be a directed acyclic graph (DAG).

The labels of SCCs are in the topological order.

Space complexity: $O(V + E)$

## Constructor

- `SCC(int n)`
    - Creates a graph with $n$ vertices and no edges.

## Member functions

- `void add_edge(int u, int v)`
    - Adds an edge $(u, v)$
    - Time complexity: $O(1)$
- `void build()`
    - Decomposes the graph into strongly connected components.
    - Time complexity: $O(V + E)$
- `int operator[](int i)`
    - Returns the label of the strongly connected component the vertex $i$ belongs to.
    - Time complexity: $O(1)$
- `int count()`
    - Returns the number of strongly connected components.
    - Time complexity: $O(1)$