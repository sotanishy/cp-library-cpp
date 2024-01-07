#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include <bits/stdc++.h>

#include "../../data-structure/segtree/dynamic_lazy_segment_tree.hpp"
using namespace std;

struct M {
    using T = int;
    static T id() { return (1u << 31) - 1; }
    static T op(T a, T b) { return min(a, b); }
};

struct O {
    using T = int;
    static T id() { return (1u << 31) - 1; }
    static T op(T a, T b) { return b; }
};

M::T act(M::T a, O::T b) { return b; }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    DynamicLazySegmentTree<M, O, act> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s, t + 1, x);
        } else {
            cout << st.fold(s, t + 1) << "\n";
        }
    }
}