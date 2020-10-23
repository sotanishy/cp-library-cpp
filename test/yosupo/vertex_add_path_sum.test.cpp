#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

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
    HLD<AddMonoid> hld(G, a);
    for (int i = 0; i < Q; ++i) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            hld.update(p, hld[p] + x);
        } else {
            int u, v;
            cin >> u >> v;
            cout << hld.fold(u, v) << endl;
        }
    }
}