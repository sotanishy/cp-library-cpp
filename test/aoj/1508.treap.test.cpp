#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1508"

#include <bits/stdc++.h>

#include "../../data-structure/bst/treap.hpp"
using namespace std;

struct MinMonoid {
    using T = int;
    static T id() { return (1u << 31) - 1; }
    static T op(T a, T b) { return min(a, b); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    using ST = Treap<MinMonoid>;
    ST st;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        st.push_back(a);
    }
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        if (x == 0) {
            st.reverse(y, z + 1);
            st.reverse(y + 1, z + 1);
        } else if (x == 1) {
            cout << st.fold(y, z + 1) << "\n";
        } else {
            st.update(y, z);
        }
    }
}