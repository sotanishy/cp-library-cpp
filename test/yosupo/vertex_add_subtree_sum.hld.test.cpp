#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <bits/stdc++.h>

#include "../../data-structure/fenwick_tree.hpp"
#include "../../tree/hld.hpp"
using namespace std;
using ll = long long;

struct AddMonoid {
    using T = ll;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    vector<vector<int>> G(N);
    for (int i = 1; i < N; ++i) {
        int p;
        cin >> p;
        G[p].push_back(i);
    }
    HLD<AddMonoid> hld(G, false);
    FenwickTree<AddMonoid> fw(N);
    auto update = [&](int k, ll x) { fw.update(k, x); };
    auto fold = [&](int l, int r) {
        return fw.prefix_fold(r) - fw.prefix_fold(l);
    };
    for (int i = 0; i < N; ++i) hld.update(i, a[i], update);
    for (int i = 0; i < Q; ++i) {
        int t, u;
        cin >> t >> u;
        if (t == 0) {
            int x;
            cin >> x;
            hld.update(u, x, update);
        } else {
            cout << hld.subtree_fold(u, fold) << "\n";
        }
    }
}