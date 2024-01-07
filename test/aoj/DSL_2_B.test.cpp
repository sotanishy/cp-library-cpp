#define PROBLEM \
    "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"

#include <bits/stdc++.h>

#include "../../data-structure/fenwick_tree.hpp"
using namespace std;

struct Monoid {
    using T = int;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    FenwickTree<Monoid> ft(n);
    for (int i = 0; i < q; i++) {
        int com, x, y;
        cin >> com >> x >> y;
        if (com == 0)
            ft.update(x - 1, y);
        else
            cout << (ft.prefix_fold(y) - ft.prefix_fold(x - 1)) << "\n";
    }
}