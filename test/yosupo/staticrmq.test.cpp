#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <bits/stdc++.h>

#include "../../data-structure/disjoint_sparse_table.cpp"
using namespace std;

struct MinMonoid {
    using T = int;
    static T id() { return (1u << 31) - 1; }
    static T op(T a, T b) { return min(a, b); }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    DisjointSparseTable<MinMonoid> st(a);
    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;
        cout << st.fold(l, r) << "\n";
    }
}