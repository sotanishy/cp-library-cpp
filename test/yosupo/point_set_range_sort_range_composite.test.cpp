#define PROBLEM \
    "https://judge.yosupo.jp/problem/point_set_range_sort_range_composite"

#include <bits/stdc++.h>

#include "../../data-structure/segtree/segment_tree.hpp"
#include "../../data-structure/segtree/sortable_segment_tree.hpp"
#include "../../math/modint.hpp"
using namespace std;

using mint = Modint<998244353>;

struct AffineMonoid {
    using T = pair<mint, mint>;
    static T id() { return {1, 0}; }
    static T op(T a, T b) {
        return {a.first * b.first, a.second * b.first + b.second};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<long long, pair<mint, mint>>> kv(N);
    for (int i = 0; i < N; ++i) {
        int p, a, b;
        cin >> p >> a >> b;
        kv[i] = {p, {a, b}};
    }
    SortableSegmentTree<AffineMonoid> st(1e9 + 1, kv);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int i, p, a, b;
            cin >> i >> p >> a >> b;
            st.update(i, p, {a, b});
        } else if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            auto [a, b] = st.fold(l, r);
            cout << (a * x + b) << "\n";
        } else if (t == 2) {
            int l, r;
            cin >> l >> r;
            st.sort(l, r);
        } else {
            int l, r;
            cin >> l >> r;
            st.sort(l, r, true);
        }
    }
}