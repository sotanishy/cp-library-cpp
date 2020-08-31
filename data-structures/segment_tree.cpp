#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SegmentTree {
    using F = function<T(T, T)>;

    int size;
    vector<T> node;
    const F f;
    const T I;

    SegmentTree(int n, const F f, const T& I) : f(f), I(I) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size, I);
    }

    T operator[](int k) {
        return node[k + size];
    }

    void build(vector<T>& v) {
        for (int k = 0; k < v.size(); k++) node[k + size] = v[k];
        for (int k = size - 1; k > 0; k--) node[k] = f(node[2 * k], node[2 * k + 1]);
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) {
            node[k] = f(node[2 * k], node[2 * k + 1]);
        }
    }

    T query(int a, int b) {
        T L = I, R = I;
        for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
            if (a & 1) L = f(L, node[a++]);
            if (b & 1) R = f(node[--b], R);
        }
        return f(L, R);
    }
};