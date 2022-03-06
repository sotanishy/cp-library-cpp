#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"

#include "../../data-structure/segtree/lazy_segment_tree.cpp"

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct M {
    using T = pair<ll, int>;
    static T id() { return {0, 1}; }
    static T op(T a, T b) {
        return {a.first + b.first, a.second + b.second};
    }
};

struct O {
    using T = ll;
    static T id() { return 0; }
    static T op(T a, T b) {
        return a + b;
    }
};

M::T act(M::T a, O::T b) {
    return {a.first + a.second * b, a.second};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<M, O, act> st(n);
    for (int i = 0; i < q; i++) {
        int type, s, t;
        cin >> type >> s >> t;
        if (type == 0) {
            int x;
            cin >> x;
            st.update(s - 1, t, x);
        } else {
            cout << st.fold(s - 1, t).first << "\n";
        }
    }
}