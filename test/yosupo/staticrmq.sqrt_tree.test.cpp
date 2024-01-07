#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>

#include "../../data-structure/sqrt_tree.hpp"
using namespace std;

struct MinSemigroup {
    using T = int;
    static T op(T a, T b) { return min(a, b); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (auto& x : a) cin >> x;
    SqrtTree<MinSemigroup> st(a);
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << st.fold(l, r) << "\n";
    }
}