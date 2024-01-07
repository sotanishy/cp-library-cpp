#define PROBLEM \
    "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include <bits/stdc++.h>

#include "../../data-structure/segtree/segment_tree_beats.hpp"
using namespace std;
using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    vector<S> init(N);
    for (int i = 0; i < N; ++i) init[i] = S(a[i], 1);
    SegmentTreeBeats<MinMaxSumMonoid, ChminChmaxAddMonoid, act> st(init);
    for (int i = 0; i < Q; i++) {
        int t, l, r;
        ll b;
        cin >> t >> l >> r;
        if (t != 3) cin >> b;
        if (t == 0) {
            st.update(l, r, F::chmin(b));
        } else if (t == 1) {
            st.update(l, r, F::chmax(b));
        } else if (t == 2) {
            st.update(l, r, F::add(b));
        } else {
            cout << st.fold(l, r).sum << "\n";
        }
    }
}