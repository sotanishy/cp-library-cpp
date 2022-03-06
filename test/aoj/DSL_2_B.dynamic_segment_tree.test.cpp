#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include "../../data-structure/segtree/dynamic_segment_tree.cpp"

#include <bits/stdc++.h>
using namespace std;

struct Monoid {
    using T = int;
    static T id() { return 0; }
    static T op(T a, T b) {
        return a + b;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    DynamicSegmentTree<Monoid> st(n);
    for (int i = 0; i < q; ++i) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0) st.update(x - 1, st[x - 1] + y);
        else cout << st.fold(x - 1, y) << "\n";
    }
}