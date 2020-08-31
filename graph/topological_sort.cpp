#include <bits/stdc++.h>
using namespace std;

// returns an empty list if G is not a DAG
vector<int> topological_sort(vector<vector<int>>& G) {
    int V = G.size();
    vector<int> par_count(V);
    for (int u = 0; u < V; u++) {
        for (int v : G[u]) par_count[v]++;
    }
    stack<int> start;
    for (int v = 0; v < V; v++) {
        if (par_count[v] == 0) start.push(v);
    }

    vector<int> ret;
    while (!start.empty()) {
        int u = start.top();
        start.pop();
        ret.push_back(u);
        for (int v : G[u]) {
            par_count[v]--;
            if (par_count[v] == 0) start.push(v);
        }
    }

    for (int c : par_count) {
        if (c > 0) return vector<int>();
    }
    return ret;
}