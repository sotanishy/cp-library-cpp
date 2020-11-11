#pragma once
#include <vector>
#include "../data-structure/segtree/segment_tree.cpp"

/*
 * @brief Euler Tour
 */
template <typename M>
class EulerTour {
    using T = typename M::T;

public:
    EulerTour() = default;
    EulerTour(const std::vector<std::vector<int>>& G, int root) : n(G.size()), root(root), G(G), in(n), out(n), st(2 * n) {
        dfs(root, -1);
    }

    T get(int v) {
        return st[in[v]];
    }

    void update(int v, const T& x) {
        st.update(in[v], x);
    }

    T subtree_fold(int v) {
        return st.fold(in[v], out[v]);
    }

private:
    int n, root;
    std::vector<std::vector<int>> G;
    std::vector<int> in, out;
    int k = 0;
    SegmentTree<M> st;

    void dfs(int v, int p) {
        in[v] = k++;
        for (int c : G[v]) if (c != p) dfs(c, v);
        out[v] = k;
    }
};