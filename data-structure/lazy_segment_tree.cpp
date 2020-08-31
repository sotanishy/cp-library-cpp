#include <bits/stdc++.h>
using namespace std;

// this is not abstract
// range sum
struct LazySegmentTree {
    int size;
    vector<int> node, lazy;
    const int I = 0;

    LazySegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size, I);
        lazy.resize(2 * size, I);
    }

    void init(vector<int>& v) {
        for (int k = 0; k < v.size(); k++) {
            node[k + size] = v[k];
        }
        for (int k = size - 1; k > 0; k--) {
            node[k] = node[2 * k] + node[2 * k + 1];
        }
    }

    void eval(int k) {
        if (lazy[k] == I) return;
        if (k < size) { // not a leaf
            lazy[2 * k] = lazy[2 * k + 1] = lazy[k] / 2;
        }
        node[k] += lazy[k];
        lazy[k] = I;
    }

    void update(int a, int b, int x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        eval(k);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] += (r - l) * x;
            eval(k);
        } else {
            int m = (l + r) / 2;
            update(a, b, x, 2 * k, l, m);
            update(a, b, x, 2 * k + 1, m, r);
            node[k] = node[2 * k] + node[2 * k + 1];
        }
    }

    int query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        eval(k);
        if (r <= a || b <= l) return I;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        int vl = query(a, b, 2 * k, l, m);
        int vr = query(a, b, 2 * k + 1, m, r);
        return vl + vr;
    }
};