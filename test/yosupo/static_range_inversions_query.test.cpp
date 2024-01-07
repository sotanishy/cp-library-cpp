#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include <bits/stdc++.h>

#include "../../data-structure/fenwick_tree.hpp"
#include "../../misc/compress.hpp"
#include "../../misc/mo.hpp"
using namespace std;
using ll = long long;

struct AddMonoid {
    using T = int;
    static T id() { return 0; }
    static T op(T a, T b) { return a + b; }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    A = Compress<int>(A).compress(A);
    Mo mo(N);
    for (int i = 0; i < Q; ++i) {
        int l, r;
        cin >> l >> r;
        mo.query(l, r);
    }

    FenwickTree<AddMonoid> fw(N);
    ll res = 0;
    vector<ll> ans(Q);
    auto exl = [&](int i) {
        res += fw.prefix_fold(A[i]);
        fw.update(A[i], 1);
    };
    auto shl = [&](int i) {
        res -= fw.prefix_fold(A[i]);
        fw.update(A[i], -1);
    };
    auto exr = [&](int i) {
        res += fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);
        fw.update(A[i], 1);
    };
    auto shr = [&](int i) {
        res -= fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);
        fw.update(A[i], -1);
    };
    auto out = [&](int i) { ans[i] = res; };
    mo.run(exl, shl, exr, shr, out);
    for (auto& x : ans) cout << x << "\n";
}