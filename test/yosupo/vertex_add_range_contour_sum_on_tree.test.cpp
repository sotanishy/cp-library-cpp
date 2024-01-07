#define PROBLEM \
    "https://judge.yosupo.jp/problem/vertex_add_range_contour_sum_on_tree"

#include <bits/stdc++.h>

#include "../../data-structure/fenwick_tree.hpp"
#include "../../tree/centroid_decomposition.hpp"
#include "../../tree/range_contour_aggregation.hpp"
using namespace std;
using ll = long long;

struct AddGroup {
    using T = ll;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
    static T inv(T a) { return -a; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    std::vector<ll> a(N);
    for (auto& x : a) cin >> x;
    vector<vector<int>> G(N);
    for (int i = 0; i < N - 1; ++i) {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    RangeContourAggregation<AddGroup> agg(G);
    for (int i = 0; i < N; ++i) {
        agg.update(i, a[i]);
    }
    for (int i = 0; i < Q; ++i) {
        int t, p;
        cin >> t >> p;
        if (t == 0) {
            ll x;
            cin >> x;
            agg.update(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            ll ans = agg.fold(p, r) - agg.fold(p, l);
            cout << ans << "\n";
        }
    }
}
