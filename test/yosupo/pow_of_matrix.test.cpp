#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_matrix"

#include <bits/stdc++.h>

#include "../../math/linalg/matrix.hpp"
#include "../../math/modint.hpp"
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long K;
    cin >> N >> K;
    Matrix<mint> a(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> a[i][j];
    }
    a = a.pow(K);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cout << a[i][j] << (j < N - 1 ? " " : "\n");
    }
}
