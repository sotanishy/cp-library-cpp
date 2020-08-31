#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SparseTable {
    vector<vector<T>> lookup;
    vector<int> len;

    SparseTable(vector<int>& v) {
        int n = 1;
        int b = 0;
        while (n <= v.size()) {
            n <<= 1;
            b++;
        }
        lookup.resize(v.size(), vector<int>(b));
        for (int i = 0; i < v.size(); i++) lookup[i][0] = v[i];
        for (int j = 1; j < b; j++) {
            for (int i = 0; i + (1 << j) <= v.size(); i++) {
                lookup[i][j] = min(lookup[i][j-1], lookup[i + (1 << (j-1))][j-1]);
            }
        }
        len.resize(v.size() + 1);
        for (int i = 2; i <= v.size(); i++) {
            len[i] = len[i / 2] + 1;
        }
    }

    T query(int l, int r) {
        int b = len[r - l];
        return min(lookup[l][b], lookup[r - (1 << b)][b]);
    }
};