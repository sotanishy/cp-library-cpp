#include <bits/stdc++.h>

/*
 * @brief 2D Fenwick Tree
 */
template <typename T>
class FenwickTree2D {
public:
    FenwickTree2D(int H, int W) : H(H), W(W), data(H+1, std::vector<T>(W+1)) {}

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
    std::vector<std::vector<T>> data;
};