#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../../data-structure/segtree/segment_tree_beats.cpp"

using namespace std;

using ll = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    SegmentTreeBeats<ll> st(a);
    for (int i = 0; i < Q; i++) {
        int t, l, r;
        ll b;
        cin >> t >> l >> r;
        if (t != 3) cin >> b;
        if (t == 0) {
            st.chmin(l, r, b);
        } else if (t == 1) {
            st.chmax(l, r, b);
        } else if (t == 2) {
            st.add(l, r, b);
        } else {
            cout << st.fold_sum(l, r) << "\n";
        }
    }
}