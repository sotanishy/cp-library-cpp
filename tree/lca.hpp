#pragma once
#include <algorithm>
#include <bit>
#include <vector>

class LCA {
   public:
    LCA() = default;
    LCA(const std::vector<std::vector<int>>& G, int root)
        : G(G),
          LOG(std::bit_width(G.size())),
          depth(G.size()),
          table(LOG, std::vector<int>(G.size(), -1)) {
        dfs(root, -1, 0);

        for (int k = 0; k < LOG - 1; ++k) {
            for (int v = 0; v < (int)G.size(); ++v) {
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
    std::vector<int> depth;
    std::vector<std::vector<int>> table;

    void dfs(int v, int p, int d) {
        table[0][v] = p;
        depth[v] = d;
        for (int c : G[v]) {
            if (c != p) dfs(c, v, d + 1);
        }
    }
};