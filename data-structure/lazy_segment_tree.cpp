#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*op)(T, T), T tid, typename E, T (*apply)(T, E), E (*comp)(E, E), E (*prod)(E, int), E eid>
struct LazySegmentTree {
    int size;
    vector<T> node;
    vector<E> lazy;

    LazySegmentTree(int n) : LazySegmentTree(vector<T>(n, tid)) {}
    LazySegmentTree(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        node.resize(2 * size, tid);
        lazy.resize(2 * size, eid);
        for (int i = 0; i < v.size(); i++) node[i + size] = v[i];
        for (int i = size - 1; i > 0; i--) node[i] = op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) {
        return query(k, k + 1);
    }

    void push(int k, int len) {
        if (lazy[k] == eid) return;
        if (k < size) {
            lazy[2 * k] = comp(lazy[2 * k], lazy[k]);
            lazy[2 * k + 1] = comp(lazy[2 * k + 1], lazy[k]);
        }
        node[k] = apply(node[k], prod(lazy[k], len));
        lazy[k] = eid;
    }

    void update(int a, int b, const T& x, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        push(k, r - l);
        if (r <= a || b <= l) return;
        if (a <= l && r <= b) {
            lazy[k] = comp(lazy[k], x);
            push(k, r - l);
            return;
        }
        int m = (l + r) / 2;
        update(a, b, x, 2 * k, l, m);
        update(a, b, x, 2 * k + 1, m, r);
        node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    T query(int a, int b, int k = 1, int l = 0, int r = -1) {
        if (r == -1) r = size;

        push(k, r - l);
        if (r <= a || b <= l) return tid;
        if (a <= l && r <= b) return node[k];
        int m = (l + r) / 2;
        int vl = query(a, b, 2 * k, l, m);
        int vr = query(a, b, 2 * k + 1, m, r);
        return op(vl, vr);
    }
};