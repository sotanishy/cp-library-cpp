#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"


#include "../../math/modint.hpp"
#include "../../data-structure/segtree/segment_tree.hpp"
#include "../../tree/hld.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using mint = Modint<998244353>;

struct AffineMonoid {
    using T = pair<pair<mint, mint>, pair<mint, mint>>;
    static T id() { return {{1, 0}, {1, 0}}; }
    static T op(T a, T b) {
        return {
            {a.first.first * b.first.first, a.first.second * b.first.first + b.first.second},
            {b.second.first * a.second.first, b.second.second * a.second.first + a.second.second},
        };
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<pair<pair<mint, mint>, pair<mint, mint>>> ab(N);
    for (int i = 0; i < N; ++i) {
        mint a, b;
        cin >> a >> b;
        ab[i] = {{a, b}, {a, b}};
    }
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    HLD<AffineMonoid> hld(G, false);
    SegmentTree<AffineMonoid> st(N);
    auto update = [&](int k, const AffineMonoid::T& p) {
        st.update(k, p);
    };
    auto fold = [&](int l, int r) {
        return st.fold(l, r);
    };
    auto flip = [&](AffineMonoid::T& a) { return make_pair(a.second, a.first); };
    for (int i = 0; i < N; ++i) hld.update(i, ab[i], update);
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            hld.update(p, {{c, d}, {c, d}}, update);
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            auto a = hld.path_fold(u, v, fold, flip).first;
            cout << a.first * x + a.second << "\n";
        }
    }
}
