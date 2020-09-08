#include <bits/stdc++.h>
using namespace std;

struct SCC {
public:
    SCC(vector<vector<int>>& G) : G(G), comp(G.size(), -1), visited(G.size()), G_rev(G.size()) {
        for (int u = 0; u < G.size(); u++) {
            for (int v : G[u]) G_rev[v].push_back(u);
        }

        for (int v = 0; v < G.size(); v++) dfs(v);
        reverse(order.begin(), order.end());
        int c = 0;
        for (int v : order) if (comp[v] == -1) rdfs(v, c++);
    }

    int operator[](int k) const {
        return comp[k];
    }

private:
    vector<vector<int>> G, G_rev;
    vector<int> comp, order;
    vector<bool> visited;

    void dfs(int u) {
        if (visited[u]) return;
        visited[u] = true;
        for (int v : G[u]) dfs(v);
        order.push_back(u);
    }

    void rdfs(int u, int c) {
        if (comp[u] != -1) return;
        comp[u] = c;
        for (int v : G_rev[u]) rdfs(v, c);
    }
};