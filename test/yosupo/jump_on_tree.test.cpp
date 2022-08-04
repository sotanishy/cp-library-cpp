#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"

// #include "../../tree/lca.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class LCA {
public:
    LCA() = default;
    LCA(const std::vector<std::vector<int>>& G, int root) : G(G), LOG(32 - __builtin_clz(G.size())), depth(G.size()) {
        int V = G.size();
        table.assign(LOG, std::vector<int>(V, -1));

        dfs(root, -1, 0);

        for (int k = 0; k < LOG - 1; ++k) {
            for (int v = 0; v < V; ++v) {
                if (table[k][v] >= 0) {
                    table[k + 1][v] = table[k][table[k][v]];
                }
            }
        }
    }

    int query(int u, int v) const {
        if (depth[u] > depth[v]) std::swap(u, v);

        // go up to the same depth
        for (int k = 0; k < LOG; ++k) {
            if ((depth[v] - depth[u]) >> k & 1) {
                v = table[k][v];
            }
        }
        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; --k) {
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

    int parent(int v, int k) const {
        for (int i = LOG - 1; i >= 0; --i) {
            if (k >= (1 << i)) {
                v = table[i][v];
                k -= 1 << i;
            }
        }
        return v;
    }

    int jump(int u, int v, int k) const {
        int l = query(u, v);
        int du = depth[u] - depth[l];
        int dv = depth[v] - depth[l];
        if (du + dv < k) return -1;
        if (k < du) return parent(u, k);
        return parent(v, du + dv - k);
    }

protected:
    const std::vector<std::vector<int>>& G;
    const int LOG;
    std::vector<std::vector<int>> table;
    std::vector<int> depth;

    void dfs(int v, int p, int d) {
        table[0][v] = p;
        depth[v] = d;
        for (int c : G[v]) {
            if (c != p) dfs(c, v, d + 1);
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> G(N);
    for (int i = 1; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    LCA lca(G, 0);
    for (int q = 0; q < Q; ++q) {
        int s, t, i;
        cin >> s >> t >> i;
        cout << lca.jump(s, t, i) << "\n";
    }
}
