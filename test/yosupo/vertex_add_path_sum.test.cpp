#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../data-structure/segtree/segment_tree.cpp"
#include "../../tree/hld.cpp"

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    HLD<AddMonoid> hld(G, false);
    SegmentTree<AddMonoid> st(N);
    auto update = [&](int k, ll x) {
        st.update(k, st[k] + x);
    };
    auto fold = [&](int l, int r) {
        return st.fold(l, r);
    };
    for (int i = 0; i < N; ++i) hld.update(i, a[i], update);
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            hld.update(p, x, update);
        } else {
            int u, v;
            cin >> u >> v;
            cout << hld.path_fold(u, v, fold) << "\n";
        }
    }
}