#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Disjoint Sparse Table
 * @docs docs/data-structure/disjoint_sparse_table.md
 */
template <typename T, T (*op)(T, T)>
struct DisjointSparseTable {
    vector<vector<T>> lookup;

    DisjointSparseTable(const vector<T>& v) {
        size_t n = v.size(), b = 0;
        while ((1 << b) < n) b++;
        lookup.resize(b + 1, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (size_t i = 1; i <= b; i++) {
            size_t len = 1 << i;
            for (size_t l = 0; l + len / 2 < n; l += len) {
                size_t m = l + len / 2;
                lookup[i][m - 1] = v[m - 1];
                for (size_t j = 1; j < len / 2; j++) {
                    lookup[i][m - 1 - j] = op(v[j], lookup[i][m - j]);
                }
                lookup[i][m] = v[m];
                for (size_t j = 1; m + j < min(l + len, n); j++) {
                    lookup[i][m + j] = op(lookup[i][m + j - 1], v[j]);
                }
            }
        }
    }

    T fold(size_t l, size_t r) {
        if (r - l == 1) return lookup[0][l];
        size_t i = 32 - __builtin_clz(l ^ (r - 1));
        return op(lookup[i][l], lookup[i][r - 1]);
    }
};