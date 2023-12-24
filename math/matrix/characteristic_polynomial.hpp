#include <algorithm>
#include <vector>

#include "../polynomial.cpp"
#include "square_matrix.cpp"

template <typename mint>
Polynomial<mint> characteristic_polynomial(SquareMatrix<mint> mat) {
    const int n = mat.size();
    if (n == 0) return {1};
    // stage 1: reduce mat to upper Hessenberg form
    for (int j = 0; j < n; ++j) {
        int i = j + 1;
        while (i < n && mat[i][j] == 0) ++i;
        if (i == n) continue;

        if (i != j + 1) {
            // swap mat[i], mat[j+1]
            mat[i].swap(mat[j + 1]);
            // swap mat[:,i], mat[:,j+1]
            for (int k = 0; k < n; ++k) {
                std::swap(mat[k][i], mat[k][j + 1]);
            }
        }

        mint inv = mint(1) / mat[j + 1][j];
        for (int k = j + 2; k < n; ++k) {
            mint v = mat[k][j] * inv;
            // mat[k] -= mat[j+1] * v
            for (int l = j; l < n; ++l) {
                mat[k][l] -= mat[j + 1][l] * v;
            }
            // mat[:,j+1] += mat[:,k] * v
            for (int l = 0; l < n; ++l) {
                mat[l][j + 1] += mat[l][k] * v;
            }
        }
    }
    // stage 2: recursively compute char polys of leading principal submatrices
    std::vector<Polynomial<mint>> p(n + 1);
    p[0] = {1};
    for (int i = 0; i < n; ++i) {
        p[i + 1].resize(i + 1 + 1);
        // (x - mat[i,i]) * p[i]
        for (int j = 0; j <= i; ++j) {
            p[i + 1][j] -= mat[i][i] * p[i][j];
            p[i + 1][j + 1] += p[i][j];
        }

        mint beta = 1;
        for (int k = i - 1; k >= 0; --k) {
            beta *= mat[k + 1][k];
            p[i + 1] -= p[k] * mat[k][i] * beta;
        }
    }
    return p[n];
}
