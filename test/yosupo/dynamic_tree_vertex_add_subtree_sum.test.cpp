#define PROBLEM \
    "https://judge.yosupo.jp/problem/dynamic_tree_vertex_add_subtree_sum"

#include <bits/stdc++.h>

#include "../../tree/euler_tour_tree.hpp"
using namespace std;
using ll = long long;

struct AddMonoid {
    using T = ll;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

ll act(ll a, ll b) { return a + b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    EulerTourTree<AddMonoid, AddMonoid, act> ett(N);
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ett.update(i, a);
    }
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        ett.link(u, v);
    }
    while (Q--) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v, w, x;
            cin >> u >> v >> w >> x;
            ett.cut(u, v);
            ett.link(w, x);
        } else if (t == 1) {
            int p, x;
            cin >> p >> x;
            ett.update(p, ett.get(p) + x);
        } else {
            int v, p;
            cin >> v >> p;
            cout << ett.fold(v, p) << "\n";
        }
    }
}