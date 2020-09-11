#include <bits/stdc++.h>
using namespace std;

/*
 * @brief Fenwick Tree with Range Update
 * @docs docs/data-structure/range_fenwick_tree.md
 */
template <typename T>
struct RangeFenwickTree {
public:
    RangeFenwickTree(int n) : n(n), data0(n+1), data1(n+1) {}

    T sum(int i) {
        return sum(data0, i) * i + sum(data1, i);
    }

    void add(int l, int r, T x) {
        add(data0, l, x);
        add(data0, r + 1, -x);
        add(data1, l, -x * (l - 1));
        add(data1, r + 1, x * r);
    }

private:
    int n;
    vector<T> data0, data1;

    T sum(vector<T>& data, int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void add(vector<T>& data, int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }
};