#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_path_sum"

#include "../../tree/link_cut_tree.cpp"

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct AddMonoid {
    using T = ll;
    static constexpr T id = 0;
    static T op(T a, T b) {
        return a + b;
    }
};

ll flip(ll a) { return a; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    LinkCutTree<AddMonoid, flip> lct(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        lct.set(i, a);
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        lct.link(u, v);
    }
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v, w, x;
            cin >> u >> v >> w >> x;
            lct.evert(u);
            lct.cut(v);
            lct.link(w, x);
        } else if (t == 1) {
            int p, x;
            cin >> p >> x;
            lct.set(p, lct.get(p) + x);
        } else {
            int u, v;
            cin >> u >> v;
            cout << lct.fold(u, v) << "\n";
        }
    }
}