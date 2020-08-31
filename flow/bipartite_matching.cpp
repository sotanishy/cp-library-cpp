#include <bits/stdc++.h>
using namespace std;

struct BipartiteMatching {
    vector<vector<int>> G;
    vector<bool> used;
    vector<int> match;

    BipartiteMatching(int V) : G(V), used(V), match(V) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }

    bool dfs(int u) {
        used[u] = true;
        for (int v : G[u]) {
            int w = match[v];
            if (w < 0 || (!used[w] && dfs(w))) {
                match[u] = v;
                match[v] = u;
                return true;
            }
        }
        return false;
    }

    int bipartite_matching() {
        int res = 0;
        fill(match.begin(), match.end(), -1);
        for (int v = 0; v < G.size(); v++) {
            if (match[v] == -1) {
                fill(used.begin(), used.end(), false);
                if (dfs(v)) res++;
            }
        }
        return res;
    }
};