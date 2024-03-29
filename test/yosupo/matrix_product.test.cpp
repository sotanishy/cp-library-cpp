#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"

#include <bits/stdc++.h>

#include "../../math/linalg/matrix.hpp"
#include "../../math/modint.hpp"
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    Matrix<mint> A(N, M), B(M, K);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) cin >> A[i][j];
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < K; ++j) cin >> B[i][j];
    auto C = A * B;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) cout << C[i][j] << (j < K - 1 ? " " : "\n");
    }
}
