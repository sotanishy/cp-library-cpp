#define PROBLEM "https://judge.yosupo.jp/problem/system_of_linear_equations"

#include "../../math/linalg/system_of_linear_equations.hpp"

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
    vector<mint> b(N);
    for (int i = 0; i < N; ++i) cin >> b[i];
    auto sol = solve_system(A, b);
    if (sol.empty()) {
        cout << -1 << "\n";
        return 0;
    }
    cout << sol.size() - 1 << "\n";
    for (int i = 0; i < (int)sol.size(); ++i) {
        for (int j = 0; j < M; ++j)
            cout << sol[i][j] << (j < M - 1 ? " " : "\n");
    }
}
