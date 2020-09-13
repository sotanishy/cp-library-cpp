#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../data-structure/segment_tree.cpp"

using ll = long long;

struct Monoid {
    using T = ll;
    static inline T id = 0;
    static T op(T a, T b) {
        return a + b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    SegmentTree<Monoid> st(a);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, x;
            cin >> p >> x;
            st.update(p, st[p] + x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.fold(l, r) << "\n";
        }
    }
}