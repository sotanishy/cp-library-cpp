#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_set_path_composite"

#include "../../math/modint.cpp"
#include "../../tree/link_cut_tree.cpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

struct AffineMonoid {
    using T = pair<pair<mint, mint>, pair<mint, mint>>;
    static constexpr T id = {{1, 0}, {1, 0}};
    static T op(T a, T b) {
        return {
            {a.first.first * b.first.first, a.first.second * b.first.first + b.first.second},
            {b.second.first * a.second.first, b.second.second * a.second.first + a.second.second},
        };
    }
};

AffineMonoid::T flip(AffineMonoid::T a) { swap(a.first, a.second); return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    LinkCutTree<AffineMonoid, flip> lct;
    vector<decltype(lct)::node_ptr> nodes;
    for (int i = 0; i < N; ++i) {
        int a, b;
        cin >> a >> b;
        nodes.emplace_back(lct.make_node({{a, b}, {a, b}}));
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        lct.link(nodes[u], nodes[v]);
    }
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v, w, x;
            cin >> u >> v >> w >> x;
            lct.evert(nodes[u]);
            lct.cut(nodes[v]);
            lct.link(nodes[w], nodes[x]);
        } else if (t == 1) {
            int p, c, d;
            cin >> p >> c >> d;
            lct.update(nodes[p], {{c, d}, {c, d}});
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            auto f = lct.fold(nodes[u], nodes[v]);
            cout << f.first.first * x + f.first.second << "\n";
        }
    }
}