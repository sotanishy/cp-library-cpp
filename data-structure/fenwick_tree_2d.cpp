#include <bits/stdc++.h>
using namespace std;

/*
 * @brief 2D Fenwick Tree
 */
template <typename T>
struct FenwickTree2D {
    size_t H, W;
    vector<vector<T>> data;

    FenwickTree2D(size_t H, size_t W) : H(H), W(W), data(H+1, vector<T>(W+1)) {}

    void add(size_t a, size_t b, T x) {
        a++;
        b++;
        for (size_t i = a; i <= H; i += i & -i) {
            for (size_t j = b; j <= W; j += j & -j) {
                data[i][j] += x;
            }
        }
    }

    T sum(size_t a, size_t b) {
        a++;
        b++;
        T ret = 0;
        for (size_t i = a; i > 0; i -= i & -i) {
            for (size_t j = b; j > 0; j -= j & -j) {
                ret += bit[i][j];
            }
        }
        return ret;
    }
};