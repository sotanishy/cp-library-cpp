#define PROBLEM "https://judge.yosupo.jp/problem/range_reverse_range_sum"

#include <bits/stdc++.h>

#include "../../data-structure/bst/treap.hpp"
using namespace std;

struct AddMonoid {
    using T = long long;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    Treap<AddMonoid> st;
    for (int i = 0; i < N; ++i) {
        long long x;
        cin >> x;
        st.push_back(x);
    }
    for (int i = 0; i < Q; i++) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 0) {
            st.reverse(l, r);
        } else {
            cout << st.fold(l, r) << "\n";
        }
    }
}