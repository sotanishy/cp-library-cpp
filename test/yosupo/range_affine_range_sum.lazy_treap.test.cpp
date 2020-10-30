#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../data-structure/bst/lazy_treap.cpp"
#include "../../math/modint.cpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

struct M {
    using T = pair<mint, mint>;
    static constexpr T id = {0, 0};
    static T op(T a, T b) {
        return {a.first + b.first, a.second + b.second};
    }
};

struct O {
    using T = pair<mint, mint>;
    static constexpr T id = {1, 0};
    static T op(T a, T b) {
        return {a.first * b.first, a.second * b.first + b.second};
    }
};

M::T act(M::T a, O::T b) {
    return {a.first * b.first + a.second * b.second, a.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<pair<mint, mint>> a(N, {0, 1});
    for (int i = 0; i < N; i++) cin >> a[i].first;
    LazyTreap<M, O, act> st;
    for (int i = 0; i < N; ++i) {
        st.push_back(a[i]);
    }
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 0) {
            int l, r, b, c;
            cin >> l >> r >> b >> c;
            st.update(l, r, {b, c});
        } else {
            int l, r;
            cin >> l >> r;
            cout << st.fold(l, r).first << "\n";
        }
    }
}