#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"

#include "../../math/modint.cpp"
#include "../../math/matrix/square_matrix.cpp"

#include <bits/stdc++.h>
using namespace std;

using mint = Modint<998244353>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    SquareMatrix<mint> a(N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) cin >> a[i][j];
    }
    cout << a.det() << endl;
}
