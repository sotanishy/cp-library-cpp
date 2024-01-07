#pragma once
#include <algorithm>
#include <bit>
#include <vector>

template <typename M>
class DisjointSparseTable {
    using T = M::T;

   public:
    DisjointSparseTable() = default;
    explicit DisjointSparseTable(const std::vector<T>& v) {
        const int n = v.size();
        const int b = std::bit_width((unsigned int)n);
        lookup.resize(b + 1, std::vector<T>(n));
        std::ranges::copy(v, lookup[0].begin());
        for (int i = 1; i <= b; ++i) {
            int len = 1 << i;
            for (int l = 0; l + len / 2 < n; l += len) {
                int m = l + len / 2;
                lookup[i][m - 1] = v[m - 1];
                for (int j = m - 2; j >= l; --j) {
                    lookup[i][j] = M::op(lookup[i][j + 1], v[j]);
                }
                lookup[i][m] = v[m];
                for (int j = m + 1; j < std::min(l + len, n); ++j) {
                    lookup[i][j] = M::op(lookup[i][j - 1], v[j]);
                }
            }
        }
    }

    T fold(int l, int r) const {
        if (l == r) return M::id();
        if (r - l == 1) return lookup[0][l];
        int i = std::bit_width((unsigned int)(l ^ (r - 1)));
        return M::op(lookup[i][l], lookup[i][r - 1]);
    }

   private:
    std::vector<std::vector<T>> lookup;
};