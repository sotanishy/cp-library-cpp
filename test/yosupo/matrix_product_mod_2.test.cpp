#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product_mod_2"

#include <bits/stdc++.h>

#include "../../math/linalg/binary_matrix.hpp"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, K;
    cin >> N >> M >> K;
    BinaryMatrix<1 << 12> A(N, M), B(M, K);

    for (int i = 0; i < N; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < M; ++j) {
            if (row[j] == '1') A.set(i, j);
        }
    }
    for (int i = 0; i < M; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < K; ++j) {
            if (row[j] == '1') B.set(i, j);
        }
    }
    auto C = A.matmul(B);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < K; ++j) cout << C.get(i, j);
        cout << "\n";
    }
}
