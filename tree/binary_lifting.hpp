#pragma once
#include <vector>

#include "lca.hpp"

/**
 * @brief Binary Lifting
 */
template <typename M>
class BinaryLifting : public LCA {
    using T = M::T;

   public:
    BinaryLifting() = default;
    BinaryLifting(const std::vector<std::vector<int>>& G,
                  const std::vector<T> vs, int root)
        : LCA(G, root) {
        int V = G.size();
        val.assign(LOG, std::vector<int>(V, M::id()));
        val[0] = vs;

        for (int k = 0; k < LOG - 1; ++k) {
            for (int v = 0; v < V; ++v) {
                if (table[k][v] >= 0) {
                    val[k + 1][v] = M::op(val[k][v], val[k][table[k][v]]);
                }
            }
        }
    }

    T fold(int u, int v) const {
        bool flipped = false;
        if (depth[u] > depth[v]) {
            std::swap(u, v);
            flipped = true;
        }
        T resu = M::id(), resv = M::id();

        // go up to the same depth
        for (int k = 0; k < LOG; ++k) {
            if ((depth[v] - depth[u]) >> k & 1) {
                resv = M::op(resv, val[k][v]);
                v = table[k][v];
            }
        }
        if (u == v) {
            resu = M::op(val[0][u], M::flip(resv));
            if (flipped) resu = M::flip(resu);
            return resu;
        }

        for (int k = LOG - 1; k >= 0; --k) {
            if (table[k][u] != table[k][v]) {
                resu = M::op(resu, val[k][u]);
                resv = M::op(resv, val[k][v]);
                u = table[k][u];
                v = table[k][v];
            }
        }
        resu = M::op(M::op(resu, val[0][table[0][u]]), M::flip(resv));
        if (flipped) resu = M::flip(resu);
        return resu;
    }

   private:
    std::vector<std::vector<T>> val;
};