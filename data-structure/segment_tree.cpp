#include <bits/stdc++.h>
using namespace std;

template <typename M>
struct SegmentTree {
    using T = typename M::T;

    int size;
    vector<T> node;

    SegmentTree(int n) : SegmentTree(vector<T>(n, M::id)) {}
    SegmentTree(const vector<T>& v) {
        size = 1;
        while (size < v.size()) size <<= 1;
        node.resize(2 * size, M::id);
        for (int i = 0; i < v.size(); i++) node[i + size] = v[i];
        for (int i = size - 1; i > 0; i--) node[i] = M::op(node[2 * i], node[2 * i + 1]);
    }

    T operator[](int k) const {
        return node[k + size];
    }

    void update(int k, const T& x) {
        k += size;
        node[k] = x;
        while (k >>= 1) node[k] = M::op(node[2 * k], node[2 * k + 1]);
    }

    T query(int l, int r) {
        T vl = M::id, vr = M::id;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = M::op(vl, node[l++]);
            if (r & 1) vr = M::op(node[--r], vr);
        }
        return M::op(vl, vr);
    }

    int find_first(int l, const function<bool(T)>& cond) {
        T vl = M::id;
        int r = 2 * size;
        for (l += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                T nxt = M::op(vl, node[l]);
                if (cond(nxt)) {
                    while (l < size) {
                        nxt = M::op(vl, node[2 * l]);
                        if (cond(nxt)) l = 2 * l;
                        else vl = nxt, l = 2 * l + 1;
                    }
                    return l - size;
                }
                vl = nxt;
                l++;
            }
        }
        return -1;
    }

    int find_last(int r, const function<bool(T)>& cond) {
        T vr = M::id;
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                r--;
                T nxt = M::op(node[r], vr);
                if (cond(nxt)) {
                    while (r < size) {
                        nxt = M::op(node[2 * r + 1], vr);
                        if (cond(nxt)) r = 2 * r + 1;
                        else vr = nxt, r = 2 * r;
                    }
                    return r - size;
                }
                vr = nxt;
            }
        }
        return -1;
    }
};

// struct Monoid {
//     using T = int;
//     static inline T id = (1u << 31) - 1;
//     static T op(T a, T b) {
//         return min(a, b);
//     }
// };