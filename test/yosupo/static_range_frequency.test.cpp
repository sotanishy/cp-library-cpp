#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"

#include <bits/stdc++.h>

#include "../../data-structure/wavelet_matrix.cpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, Q;
    cin >> N >> Q;
    if (N == 0) {
        while (Q--) cout << 0 << "\n";
        return 0;
    }
    vector<int> a(N);
    for (auto& x : a) cin >> x;
    WaveletMatrix<int, 30> wm(a);
    while (Q--) {
        int l, r, x;
        cin >> l >> r >> x;
        cout << wm.rank(r, x) - wm.rank(l, x) << "\n";
    }
}