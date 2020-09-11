# Topological Sort

A topological sort of a directed acyclic graph (DAG) is a linear ordering of its vertices such that for every edge $(u, v)$, $u$ comes before $v$.

- `vector<int> topological_sort(vector<vector<int>>& G)`
    - Returns a topological sort of the graph $G$. If $G$ is not a DAG, returns an empty list.
    - Time complexity: $O(V + E)$