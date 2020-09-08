#include <bits/stdc++.h>
using namespace std;

template <typename T, T (*op)(T, T), T id>
struct SegmentTree {
    int size;
    vector<T> node;

    SegmentTree(int n) {
        size = 1;
        while (size < n) size <<= 1;
        node.resize(2 * size, id);
    }

    void set(int k, const T& x) {
        node[k + size] = x;
    }

    T operator[](int k) const {
        return node[k + size];
    }

    void build() {
        for (int k = size - 1; k > 0; k--) node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) node[k] = op(node[2 * k], node[2 * k + 1]);
    }

    T query(int l, int r) {
        T L = id, R = id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = op(L, node[l++]);
            if (r & 1) R = op(node[--r], R);
        }
        return op(L, R);
    }

    int find_first(int l, const function<bool(T)>& cond) {
        T L = id;
        int r = 2 * size;
        for (l += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                T nxt = op(L, node[l]);
                if (cond(nxt)) {
                    while (l < size) {
                        nxt = op(L, node[2 * l]);
                        if (cond(nxt)) l = 2 * l;
                        else L = nxt, l = 2 * l + 1;
                    }
                    return l - size;
                }
                L = nxt;
                l++;
            }
        }
        return -1;
    }

    int find_last(int r, const function<bool(T)>& cond) {
        T R = id;
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                r--;
                T nxt = op(node[r], R);
                if (cond(nxt)) {
                    while (r < size) {
                        nxt = op(node[2 * r + 1], R);
                        if (cond(nxt)) r = 2 * r + 1;
                        else R = nxt, r = 2 * r;
                    }
                    return r - size;
                }
                R = nxt;
            }
        }
        return -1;
    }
};