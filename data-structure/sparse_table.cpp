#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Sparse Table
 * @docs docs/data-structure/sparse_table.md
 */
template <typename T, T (*op)(T, T)>
struct SparseTable {
    vector<vector<T>> lookup;

    SparseTable(const vector<T>& v) {
        size_t n = v.size(), b = 0;
        while ((1 << b) <= n) b++;
        lookup.resize(b, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (size_t i = 1; i < b; i++) {
            for (size_t j = 0; j + (1 << i) <= n; j++) {
                lookup[i][j] = op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T fold(size_t l, size_t r) {
        size_t i = 31 - __builtin_clz(r - l);
        return op(lookup[i][l], lookup[i][r - (1 << i)]);
    }
};