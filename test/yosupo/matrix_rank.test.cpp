#define PROBLEM "https://judge.yosupo.jp/problem/matrix_rank"

#include <bits/stdc++.h>

#include "../../math/linalg/matrix.hpp"
#include "../../math/modint.hpp"
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    Matrix<mint> A(N, M);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j) cin >> A[i][j];
    cout << A.rank() << endl;
}
