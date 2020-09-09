#include <bits/stdc++.h>
using namespace std;

template <typename M>
struct DualSegmentTree {
    using T = typename M::T;

    DualSegmentTree(int n) {
        size = 1;
        height = 1;
        while (size < n) size <<= 1, height++;
        lazy.resize(2 * size, M::id);
    }

    T operator[](int k) {
        return query(k);
    }

    void update(int l, int r, const T& x) {
        propagate(l);
        propagate(r - 1);
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = M::op(lazy[l], x), l++;
            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);
        }
    }

    T query(int k) {
        propagate(k);
        return lazy[k + size];
    }

private:
    int size, height;
    vector<T> lazy;

    void push(int k) {
        if (lazy[k] == M::id) return;
        lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);
        lazy[2 * k + 1] = M::op(lazy[2 * k + 1], lazy[k]);
        lazy[k] = M::id;
    }

    void propagate(int k) {
        k += size;
        for (int i = height; i > 0; i--) push(k >> i);
    }
};

// struct M {
//     using T = int;
//     inline static const T id = 0;
//     static T op(T a, T b) {
//         return a + b;
//     }
// };