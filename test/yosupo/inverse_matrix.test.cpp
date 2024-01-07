#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"

#include "../../math/modint.hpp"
#include "../../math/matrix/square_matrix.cpp"


#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    SquareMatrix<mint> A(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> A[i][j];
    }
    if (A.det() == 0) {
        cout << -1 << endl;
        return 0;
    }
    auto B = A.inv();
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cout << B[i][j] << (j < N - 1 ? " " : "\n");
    }
}
