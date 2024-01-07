#pragma once
#include <algorithm>
#include <bit>
#include <vector>

template <typename M>
class SparseTable {
    using T = M::T;

   public:
    SparseTable() = default;
    explicit SparseTable(const std::vector<T>& v) {
        const int n = v.size();
        const int b = std::bit_width((unsigned int)n);
        lookup.resize(b, std::vector<T>(n));
        std::ranges::copy(v, lookup[0].begin());
        for (int i = 1; i < b; ++i) {
            for (int j = 0; j + (1 << i) <= n; ++j) {
                lookup[i][j] =
                    M::op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T fold(int l, int r) const {
        if (l == r) return M::id();
        int i = std::bit_width((unsigned int)(r - l)) - 1;
        return M::op(lookup[i][l], lookup[i][r - (1 << i)]);
    }

   private:
    std::vector<std::vector<T>> lookup;
};