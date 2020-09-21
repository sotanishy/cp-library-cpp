#include <bits/stdc++.h>
using namespace std;

/*
 * @brief 2D Fenwick Tree
 */
template <typename T>
class FenwickTree2D {
public:
    FenwickTree2D(int H, int W) : H(H), W(W), data(H+1, vector<T>(W+1)) {}

    void add(int a, int b, T x) {
        a++;
        b++;
        for (int i = a; i <= H; i += i & -i) {
            for (int j = b; j <= W; j += j & -j) {
                data[i][j] += x;
            }
        }
    }

    T sum(int a, int b) const {
        a++;
        b++;
        T ret = 0;
        for (int i = a; i > 0; i -= i & -i) {
            for (int j = b; j > 0; j -= j & -j) {
                ret += data[i][j];
            }
        }
        return ret;
    }

private:
    int H, W;
    vector<vector<T>> data;
};