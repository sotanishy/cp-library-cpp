#pragma once
#include <array>
#include <bitset>

/**
 * @brief Boolean Square Matrix
 */
template <int N>
class BooleanSquareMatrix {
    using BSMatrix = BooleanSquareMatrix;
    using Matrix = std::array<std::bitset<N>, N>;

   public:
    void set(int r, int c) {
        rmat[r].set(c);
        cmat[c].set(r);
    }

    bool get(int r, int c) { return rmat[r][c]; }

    BSMatrix matmul(const BSMatrix& B) const {
        BSMatrix res;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                res.rmat[i][j] = res.cmat[j][i] = (rmat[i] & B.cmat[j]).any();
            }
        }
        return res;
    }

    BSMatrix pow(long long k) const {
        BSMatrix ret, A(*this);
        for (int i = 0; i < N; ++i) {
            ret.rmat[i].set(i);
            ret.cmat[i].set(i);
        }
        while (k > 0) {
            if (k & 1) ret = ret.matmul(A);
            A = A.matmul(A);
            k >>= 1;
        }
        return ret;
    }

   private:
    Matrix rmat, cmat;
};
