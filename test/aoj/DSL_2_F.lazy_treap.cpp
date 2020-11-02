#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"

#include "../../data-structure/bst/lazy_treap.cpp"

#include <bits/stdc++.h>
using namespace std;

struct M {
    using T = int;
    static constexpr T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return min(a, b);
    }
};

struct O {
    using T = int;
    static constexpr T id = (1u << 31) - 1;
    static T op(T a, T b) {
        return b;
    }
};

M::T act(M::T a, O::T b) {
    return b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;
    LazyTreap<M, O, act> st;
    for (int i = 0; i < n; ++i) st.push_back(M::id);
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