#define PROBLEM "https://judge.yosupo.jp/problem/dynamic_graph_vertex_add_component_sum"

#include "../../graph/offline_dynamic_connectivity.cpp"

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
    for (auto& x : a) cin >> x;
    OfflineDynamicConnectivity<AddMonoid> dc(a);
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int u, v;
            cin >> u >> v;
            dc.link(u, v);
        }
        if (t == 1) {
            int u, v;
            cin >> u >> v;
            dc.cut(u, v);
        }
        if (t == 2) {
            int v, x;
            cin >> v >> x;
            dc.update(v, x);
        }
        if (t == 3) {
            int v;
            cin >> v;
            dc.component_fold(v);
        }
    }
    auto ans = dc.run();
    for (auto x : ans) cout << x << "\n";
}