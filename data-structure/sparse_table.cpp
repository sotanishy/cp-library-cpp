#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Sparse Table
 * @docs docs/data-structure/sparse_table.md
 */
template <typename S>
struct SparseTable {
    using T = S::T;

    vector<vector<T>> lookup;

    SparseTable(const vector<T>& v) {
        int n = v.size(), b = 0;
        while ((1 << b) <= n) b++;
        lookup.resize(b, vector<T>(n));
        copy(v.begin(), v.end(), lookup[0].begin());
        for (int i = 1; i < b; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                lookup[i][j] = S::op(lookup[i - 1][j], lookup[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    T fold(int l, int r) {
        int i = 31 - __builtin_clz(r - l);
        return S::op(lookup[i][l], lookup[i][r - (1 << i)]);
    }
};

// struct S {
//     using T = int;
//     static T op(T a, T b) {
//         return min(a, b);
//     }
// };