#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../../data-structure/fenwick_tree.cpp"
#include "../../misc/compress.cpp"
#include "../../misc/mo.cpp"

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct AddMonoid {
    using T = int;
    static constexpr T id = 0;
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
    auto exl = [&](ll res, int i) {
        res += fw.prefix_fold(A[i]);
        fw.update(A[i], 1);
        return res;
    };
    auto shl = [&](ll res, int i) {
        res -= fw.prefix_fold(A[i]);
        fw.update(A[i], -1);
        return res;
    };
    auto exr = [&](ll res, int i) {
        res += fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);
        fw.update(A[i], 1);
        return res;
    };
    auto shr = [&](ll res, int i) {
        res -= fw.prefix_fold(N) - fw.prefix_fold(A[i] + 1);
        fw.update(A[i], -1);
        return res;
    };
    auto ans = mo.run(0LL, exl, shl, exr, shr);
    for (auto& x : ans) cout << x << "\n";
}