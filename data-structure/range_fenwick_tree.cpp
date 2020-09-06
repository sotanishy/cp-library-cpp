#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct RangeFenwickTree {
    int n;
    vector<T> data0, data1;

    RangeFenwickTree(int n) : n(n), data0(n+1), data1(n+1) {}

private:
    T _sum(vector<int>& data, int i) {
        T ret = 0;
        for (i++; i > 0; i -= i & -i) ret += data[i];
        return ret;
    }

    void _add(vector<int>& data, int i, T x) {
        for (i++; i <= n; i += i & -i) data[i] += x;
    }

public:
    T sum(int i) {
        return _sum(data0, i) * i + _sum(data1, i);
    }

    void add(int l, int r, T x) {
        _add(data0, l, x);
        _add(data0, r + 1, -x);
        _add(data1, l, -x * (l - 1));
        _add(data1, r + 1, x * r);
    }
};