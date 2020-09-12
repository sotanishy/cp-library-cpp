#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Strongly Connected Components
 * @docs docs/graph/scc.md
 */
struct SCC {
public:
    SCC(int n) : G(n), G_rev(n), comp(n, -1), visited(n) {}

    void add_edge(int u, int v) {
        G[u].push_back(v);
        G_rev[v].push_back(u);
    }

    void build() {
        for (int v = 0; v < G.size(); v++) dfs(v);
        reverse(order.begin(), order.end());
        cnt = 0;
        for (int v : order) if (comp[v] == -1) rdfs(v, cnt++);
    }

    int operator[](int i) const {
        return comp[i];
    }

    int count() {
        return cnt;
    }

private:
    vector<vector<int>> G, G_rev;
    vector<int> comp, order;
    vector<bool> visited;
    int cnt;

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