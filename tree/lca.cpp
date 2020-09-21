#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Lowerst Common Ancestor
 * @docs docs/tree/lca.md
 */
class LCA {
public:
    LCA(vector<vector<int>>& G, int root) : G(G), LOG(32 - __builtin_clz(G.size())), depth(G.size()) {
        int V = G.size();
        table.assign(LOG, vector<int>(V, -1));

        dfs(root, -1, 0);

        for (int k = 0; k < LOG - 1; k++) {
            for (int v = 0; v < V; v++) {
                if (table[k][v] >= 0) {
                    table[k+1][v] = table[k][table[k][v]];
                }
            }
        }
    }

    int query(int u, int v) const {
        if (depth[u] > depth[v]) swap(u, v);

        // go up to the same depth
        for (int k = 0; k < LOG; k++) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = table[k][v];
            }
        }
        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (table[k][u] != table[k][v]) {
                u = table[k][u];
                v = table[k][v];
            }
        }
        return table[0][u];
    }

    int dist(int u, int v) const {
        return depth[u] + depth[v] - 2 * depth[query(u, v)];
    }

private:
    const vector<vector<int>>& G;
    const int LOG;
    vector<vector<int>> table;
    vector<int> depth;

    void dfs(int v, int p, int d) {
        table[0][v] = p;
        depth[v] = d;
        for (int c : G[v]) {
            if (c != p) dfs(c, v, d + 1);
        }
    }
};