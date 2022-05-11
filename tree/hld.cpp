#pragma once
#include <algorithm>
#include <vector>

template <typename M>
class HLD {
    using T = typename M::T;

public:
    HLD() = default;
    HLD(const std::vector<std::vector<int>>& G, bool edge)
        : G(G), size(G.size()), depth(G.size()), par(G.size(), -1),
          in(G.size()), out(G.size()), head(G.size()), heavy(G.size(), -1), edge(edge) {
        dfs(0);
        decompose(0, 0);
    }

    template <typename F>
    void update(int v, const T& x, const F& f) const {
        f(in[v], x);
    }

    template <typename F>
    void update_edge(int u, int v, const T& x, const F& f) const {
        if (in[u] > in[v]) std::swap(u, v);
        f(in[v], x);
    }

    template <typename E, typename F>
    void update(int u, int v, const E& x, const F& f) const {
        while (head[u] != head[v]) {
            if (in[head[u]] > in[head[v]]) std::swap(u, v);
            f(in[head[v]], in[v] + 1, x);
            v = par[head[v]];
        }
        if (in[u] > in[v]) std::swap(u, v);
        f(in[u] + edge, in[v] + 1, x);
    }

    template <typename F, typename Flip>
    T path_fold(int u, int v, const F& f, const Flip& flip) const {
        bool flipped = false;
        T resu = M::id(), resv = M::id();
        while (head[u] != head[v]) {
            if (in[head[u]] > in[head[v]]) {
                std::swap(u, v);
                std::swap(resu, resv);
                flipped ^= true;
            }
            T val = f(in[head[v]], in[v] + 1);
            resv = M::op(val, resv);
            v = par[head[v]];
        }
        if (in[u] > in[v]) {
            std::swap(u, v);
            std::swap(resu, resv);
            flipped ^= true;
        }
        T val = f(in[u] + edge, in[v] + 1);
        resv = M::op(val, resv);
        resv = M::op(flip(resu), resv);
        if (flipped) {
            resv = flip(resv);
        }
        return resv;
    }

    template <typename F>
    T path_fold(int u, int v, const F& f) const {
        path_fold(u, v, f, [&](auto& v) { return v; });
    }

    template <typename F>
    T subtree_fold(int v, const F& f) const {
        return f(in[v] + edge, out[v]);
    }

    int lca(int u, int v) const {
        while (true) {
            if (in[u] > in[v]) std::swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }

    int dist(int u, int v) const {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }

private:
    std::vector<std::vector<int>> G;
    std::vector<int> size, depth, par, in, out, head, heavy;
    bool edge;
    int cur_pos = 0;

    void dfs(int v) {
        size[v] = 1;
        int max_size = 0;
        for (int c : G[v]) {
            if (c == par[v]) continue;
            par[c] = v;
            depth[c] = depth[v] + 1;
            dfs(c);
            size[v] += size[c];
            if (size[c] > max_size) {
                max_size = size[c];
                heavy[v] = c;
            }
        }
    }

    void decompose(int v, int h) {
        head[v] = h;
        in[v] = cur_pos++;
        if (heavy[v] != -1) decompose(heavy[v], h);
        for (int c : G[v]) {
            if (c != par[v] && c != heavy[v]) decompose(c, c);
        }
        out[v] = cur_pos;
    }
};
