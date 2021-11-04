#pragma once
#include <vector>

template <typename T>
std::vector<T> berlekamp_massey(const std::vector<T>& a) {
    int n = a.size();
    std::vector<T> B = {1}, C = {1};
    T b = 1;
    int L = 0, m = 1;
    for (int i = 0; i < n; ++i) {
        T d = a[i];
        for (int j = 1; j < (int) C.size(); ++j) {
            d += a[i-j] * C[j];
        }
        if (d == 0) {
            ++m;
        } else {
            auto tmp =  C;
            if (C.size() < m + B.size()) {
                C.resize(m + B.size());
            }
            T f = d / b;
            for (int j = 0; j < (int) B.size(); ++j) {
                C[m + j] -= f * B[j];
            }
            if (2 * L <= i) {
                L = i + 1 - L;
                b = d;
                B = tmp;
                m = 1;
            } else {
                ++m;
            }
        }
    }
    std::vector<T> ret(L);
    for (int i = 1; i <= L; ++i) {
        ret[i-1] = -C[i];
    }
    return ret;
}
