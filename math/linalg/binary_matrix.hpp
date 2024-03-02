#pragma once
#include <bitset>
#include <cassert>
#include <vector>

/**
 * @brief Binary Matrix
 */
template <int SZ>
class BinaryMatrix {
    using Mat = BinaryMatrix;
    using Vec = std::bitset<SZ>;

   public:
    BinaryMatrix() = default;
    BinaryMatrix(int m, int n) : mat(m), m(m), n(n) {}

    void set(int i, int j) { mat[i].set(j); }

    bool get(int i, int j) { return mat[i].test(j); }

    Mat matmul(const Mat& B) const {
        Mat res(m, B.n);
        for (int i = 0; i < m; ++i) {
            for (int k = 0; k < n; ++k) {
                if (mat[i][k]) res.mat[i] ^= B.mat[k];
            }
        }
        return res;
    }

    Mat pow(long long k) const {
        assert(m == n);
        Mat ret(n, n), A(*this);
        for (int i = 0; i < n; ++i) {
            ret.mat[i].set(i);
            ret.matt[i].set(i);
        }
        while (k > 0) {
            if (k & 1) ret = ret.matmul(A);
            A = A.matmul(A);
            k >>= 1;
        }
        return ret;
    }

   protected:
    std::vector<Vec> mat;
    int m, n;
};