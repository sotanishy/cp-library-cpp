#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"

#include <bits/stdc++.h>

#include "../../data-structure/wavelet_matrix.cpp"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) cin >> a[i];
    WaveletMatrix<int, 30> wm(a);
    for (int i = 0; i < Q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << wm.quantile(l, r, k) << "\n";
    }
}