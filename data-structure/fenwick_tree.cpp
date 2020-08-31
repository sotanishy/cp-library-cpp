#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct FenwickTree {
    int n;
    vector<T> data;

    FenwickTree(int n) : n(n), data(n+1) {}

    T sum(int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void add(int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }

    int lower_bound(T x) {
        if (x <= 0) return 0;
        int k = 1;
        while (k * 2 <= n) k *= 2;
        int j = 0;
        for (; k > 0; k /= 2) {
            if (j + k <= n && data[j+k] < x) {
                x -= data[j+k];
                j += k;
            }
        }
        return j;
    }
};