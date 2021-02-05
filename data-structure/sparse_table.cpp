#pragma once
#include <algorithm>
#include <vector>

template <typename S>
class SparseTable {
    using T = typename S::T;

public:
    SparseTable() = default;
    explicit SparseTable(const std::vector<T>& v) {
        int n = v.size(), b = 0;
        while ((1 << b) <= n) ++b;
        lookup.resize(b, std::vector<T>(n));
        std::copy(v.begin(), v.end(), lookup[0].begin());
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                lookup[i][j] = S::op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T fold(int l, int r) const {
        int i = 31 - __builtin_clz(r - l);
        return S::op(lookup[i][l], lookup[i][r - (1 << i)]);
    }

private:
    std::vector<std::vector<T>> lookup;
};