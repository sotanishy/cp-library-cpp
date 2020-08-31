#include <bits/stdc++.h>
#include "fenwick_tree.cpp"
using namespace std;

template <typename T>
struct RangeFenwickTree {
    FenwickTree<T> bit0, bit1;

    RangeFenwickTree(int n) : bit0(n), bit1(n) {}

    T sum(int i) {
        return bit0.sum(i) * i + bit1.sum(i);
    }

    void add(int l, int r, T x) {
        bit0.add(l, x);
        bit0.add(r + 1, -x);
        bit1.add(l, -x * (l - 1));
        bit1.add(r + 1, x * r);
    }
};