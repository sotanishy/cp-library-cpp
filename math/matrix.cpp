#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Matrix
 * @docs docs/math/matrix.md
 */
template <typename T, typename = typename enable_if<is_arithmetic<T>::value, T>::type>
struct Matrix {
    vector<vector<T>> A;
    int m, n;

    const double EPS = 1e-8;

    Matrix(int m, int n) : A(m, vector<T>(n)), m(m), n(n) {}

    Matrix(initializer_list<initializer_list<T>> list) {
        for (auto& l : list) {
            A.push_back(vector<T>(l.begin(), l.end()));
        }
        m = A.size();
        n = A[0].size();
    }

    static Matrix I(int n) {
        Matrix ret(n, n);
        for (int i = 0; i < n; i++) ret[i][i] = 1;
        return ret;
    }

    static Matrix concatenate(const Matrix& A, const Matrix& B) {
        assert(A.m == B.m);
        Matrix C(A.m, A.n + B.n);
        for (int i = 0; i < A.m; i++) {
            for (int j = 0; j < A.n; j++) {
                C[i][j] = A[i][j];
            }
            for (int j = 0; j < B.n; j++) {
                C[i][A.n + j] = B[i][j];
            }
        }
        return C;
    }

    const vector<T>& operator[](int i) const {
        return A[i];
    }

    vector<T>& operator[](int i) {
        return A[i];
    }

    Matrix& operator+=(const Matrix& B) {
        assert(m == B.m && n == B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& B) {
        assert(m == B.m && n == B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    Matrix operator+(const Matrix& B) const {
        return Matrix(*this) += B;
    }

    Matrix operator-(const Matrix& B) const {
        return Matrix(*this) -= B;
    }

    Matrix transpose() const {
        Matrix ret(n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ret[i][j] = A[j][i];
            }
        }
        return ret;
    }

    Matrix matmul(const Matrix& B) {
        assert(n == B.m);
        Matrix C(m, B.n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < B.n; j++) {
                for (int k = 0; k < n; k++) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
    }

    Matrix pow(long long k) {
        assert(m == n);
        Matrix ret = Matrix::I(n);
        Matrix B(*this);
        while (k > 0) {
            if (k & 1) ret = ret.matmul(B);
            B = B.matmul(B);
            k >>= 1;
        }
        return ret;
    }

    Matrix rref() const {
        Matrix B(*this);
        int pivot = 0;
        for (int col = 0; col < n; col++) {
            int row = pivot;
            for (; row < m && abs(B[row][col]) < EPS; row++);

            if (row == m) continue;

            if (row != pivot) swap(B[row], B[pivot]);

            T p = B[pivot][col];
            for (int c = col; c < n; c++) {
                B[pivot][c] /= p;
            }

            for (int r = 0; r < m; r++) {
                if (r == pivot) continue;

                T v = B[r][col];
                for (int c = col; c < n; c++) {
                    B[r][c] -= B[pivot][c] * v;
                }
            }

            pivot++;
        }
        return B;
    }

    T det() const {
        assert(m == n);
        Matrix B(*this);
        T ret = 1;
        for (int j = 0; j < n; j++) {
            int i = j;
            for (; i < m && abs(B[i][j]) < EPS; i++);

            if (i == m) return 0;

            if (i != j) {
                swap(B[i], B[j]);
                ret = -ret;
            }

            T p = B[i][j];
            ret *= p;
            for (int l = j; l < n; l++) {
                B[i][l] /= p;
            }

            for (int k = i + 1; k < m; k++) {
                T v = B[k][j];
                for (int l = j; l < n; l++) {
                    B[k][l] -= B[i][l] * v;
                }
            }
        }
        return ret;
    }

    int rank() const {
        auto B = rref();
        for (int i = 0; i < m; i++) {
            bool nonzero = false;
            for (int j = 0; j < n; j++) {
                if (abs(B[i][j]) > EPS) {
                    nonzero = true;
                    break;
                }
            }
            if (!nonzero) return i;
        }
        return m;
    }

    Matrix inverse() const {
        assert(abs(det(A)) > EPS);
        Matrix AI = concatenate(*this, I(n));
        Matrix Ib = rref(AI);
        Matrix B(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                B[i][j] = IB[i][n + j];
            }
        }
        return B;
    }
};