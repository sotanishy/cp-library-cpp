#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <bits/stdc++.h>

#include "../../data-structure/segtree/segment_tree.hpp"
#include "../../tree/euler_tour.hpp"
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
    auto [in, out] = euler_tour(G, 0);
    SegmentTree<AddMonoid> st(N);
    for (int i = 0; i < N; ++i) st.update(in[i], a[i]);
    for (int i = 0; i < Q; ++i) {
        int t, u;
        cin >> t >> u;
        if (t == 0) {
            int x;
            cin >> x;
            st.update(in[u], st[in[u]] + x);
        } else {
            cout << st.fold(in[u], out[u]) << "\n";
        }
    }
}