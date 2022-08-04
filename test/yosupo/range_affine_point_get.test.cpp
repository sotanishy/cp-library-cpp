#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_point_get"

#include "../../data-structure/segtree/dual_segment_tree.cpp"
#include "../../math/modint.cpp"


#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

struct AffineMonoid {
    using T = std::pair<mint, mint>;
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
    vector<mint> a(N);
    for (auto& x : a) cin >> x;
    DualSegmentTree<AffineMonoid> st(N);
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            st.update(l, r, {b, c});
        } else {
            int i;
            cin >> i;
            auto f = st[i];
            cout << (f.first * a[i] + f.second) << "\n";
        }
    }
}