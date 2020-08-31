#include <bits/stdc++.h>
using namespace std;

struct Matrix {
    vector<vector<long long>> A;
    int m, n;

    Matrix(int m, int n) : A(m, vector<long long>(m)), m(m), n(n) {};

    Matrix(int n) : A(n, vector<long long>(n)), m(n), n(n) {};

    static Matrix I(int n) {
        Matrix ret(n);
        for (int i = 0; i < n; i++) ret[i][i] = 1;
        return ret;
    }

    vector<long long> operator[](int i) const {
        return A[i];
    }

    Matrix operator+=(const Matrix& B) {
        assert(m == B.m && n == B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    Matrix operator-=(const Matrix& B) {
        assert(m == B.m && n == B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& B) {
        return Matrix(*this) += B;
    }

    Matrix operator-(const Matrix& B) {
        return Matrix(*this) -= B;
    }

    Matrix matmul(const Matrix& B, long long mod) {
        assert(n == B.m);
        Matrix C(m, B.n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < B.n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
        return C;
    }

    Matrix pow(long long k, long long mod) {
        assert(m == n);
        Matrix ret = Matrix::I(n);
        Matrix B(*this);
        while (k > 0) {
            if (k & 1) ret = ret.matmul(B, mod);
            B = B.matmul(B, mod);
            k >>= 1LL;
        }
        return ret;
    }
};